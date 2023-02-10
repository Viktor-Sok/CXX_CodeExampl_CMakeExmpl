#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>

using namespace std;

/* This parser only works for only one level deep into the xml tree*/
namespace Xml {
// namespace can be used for organisation of the project, related function and classes can be 
pair<string_view, string_view> Split(string_view line, char by) {
    /*Splits line by the symbol into two lines and return them in pair*/
    size_t pos = line.find(by);
    string_view left = line.substr(0, pos);

    if (pos < line.size() && pos + 1 < line.size()) {
        return {left, line.substr(pos + 1)};
    } else {
        return {left, string_view()};
    }
}

string_view Lstrip(string_view line) {
    /*strip oof spaces from the left*/
    while(!line.empty() && isspace(line[0])) {
        line.remove_prefix(1);
    }
    return  line;
}

string_view Unquote(string_view value) {
    /*removes quotes*/
    if (!value.empty() && value.front() == '"') {
        value.remove_prefix(1);
    }
    if (!value.empty() && value.back() == '"') {
        value.remove_suffix(1);
    }
    return value;
}




class Node {
    /*Node of the XML tree with its Node children  stored in vector*/
private:
    string name;
    vector<Node> children;
    unordered_map<string, string> attrs;
public:
    Node(string name, unordered_map<string, string> attrs) : name(name), attrs(move(attrs)) {}

    const vector<Node>& Children() const {return children;}
    void AddChild(Node node) {
        children.push_back(move(node));
    }
    string_view Name() const {return name;}

    template <typename T>
    T AttributeValue(const string& name) const;

    unordered_map<string, string> getAttrs() {
        return attrs;
    }
};

class Document {
public:
    /* Loads XML document, onlu one level deep*/
    explicit Document(Node root) : root(move(root)) {}

    const Node& GetRoot() const {
        return root;
    }

private:
    Node root;
};

Node LoadNode(istream& input) {
    /*Parsing root and its children, extracting aqttributes and their values*/
    string root_name;
    getline(input, root_name);

    Node root(root_name.substr(0, root_name.size() - 2), {});
    //cout << root.getAttrs().first << root.getAttrs().second << endl;
    for (string line; getline(input, line) && Lstrip(line)[1] != '/';) {
        auto [node_name, attrs] = Split(Lstrip(line), ' ');
        //--------------------------------Attribute parsing-----------------------------------
        attrs = Split(attrs, '>').first;  // for attribute parsing
        unordered_map<string, string> node_attrs;
        while (!attrs.empty()) {
            // Loop parses attributes 
            auto [head, tail] = Split(attrs, ' ');
            auto [name, value] = Split(head, '=');
            if (!name.empty() && !value.empty()) {
                node_attrs[string(Unquote(name))] = string(Unquote(value));
            }
            attrs = tail; // assining attrs to the remaining line
        }
        //---------------------------------------------------------------------------
        root.AddChild(Node(string(node_name.substr(1)), move(node_attrs)));
    }
    return root;
}

Document Load(istream& input) {
    return Document{LoadNode(input)};
}

template <typename T>
//method template for class node
inline T Node::AttributeValue(const string& name) const {
    istringstream attr_input(attrs.at(name));
    T res;
    attr_input >> res;
    return res;
}
} //closesvXml namespace


struct Spending {
    string category;
    int amount;
    friend ostream& operator<< (ostream& os, const Spending& s) {
            return os << '(' << s.category << ": " << s.amount << ')';
    }
};

vector<Spending> LoadFromXml (istream& input) {
    /* Loads data from XML document containing spendings */
    Xml::Document doc = Xml::Load(input);
    vector<Spending> res;
    for (const Xml::Node& node : doc.GetRoot().Children()) {
        res.push_back({
            node.AttributeValue<string>("category"), node.AttributeValue<int>("amount")});
    }
    return res;
}

int main() {
    ifstream xml_input("data.xml");
    const vector<Spending> spendings= LoadFromXml(xml_input);
    for (auto& e : spendings) {
        cout << e << "; ";
    }

    return 0;
}