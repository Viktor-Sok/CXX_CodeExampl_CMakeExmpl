#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

class StringData {
public:
    string hrml = "";
    explicit StringData(string filename) {
        ifstream f(filename);
        string temp;
        while(getline(f, temp)) {
            hrml += temp;
        }
    }
};

vector<string> parseQuery(string query) {
    vector<string> res;
    size_t start = 0;
    size_t end = query.find_first_of(".~");  
    while (end != string::npos) {
        res.push_back(query.substr(start, end - start));
        start = end + 1;
        end = query.find_first_of(".~", end + 1);
    }
    res.push_back(query.substr(start));
    return res; 
}

int countSubstrings(size_t start, size_t end, const string& data, const string& substring)  {
    string s = data.substr(start, end - start);
    int occurrences = 0;
    size_t pos = 0;
    while ((pos = s.find(substring, pos)) != string::npos) {
            ++ occurrences;
            pos += substring.size();
    }
    return occurrences;
} 

string findTag(string data, vector<string> tags) {
    size_t nested = 0;
    size_t tag = 0, found = 0;
    size_t tag_begin = 0, tag_end = 0; //point to <  and the next charachter after > of the tag 
    while (tag < tags.size() - 1) {
        found = data.find(tags[tag], tag_end);
        // Calculating depth of nesting of the tag
        //nested = countSubstrings(tag_begin, found, data, "<") - 1 - 2*countSubstrings(tag_begin, found, data, "/");
        nested = countSubstrings(0, found, data, "<") - 1 - 2*countSubstrings(0, found, data, "/");
        cout << "nested_level: " << nested << endl;
        // Find the begging and the end of the found tag
        tag_begin = found - 1;
        tag_end = data.find_first_of('>', found) + 1;
        if (nested != tag) {
            // nesting level should correspond to the nested tag in the query  
            continue;
        }
        ++tag;
    }
    return data.substr(tag_begin, tag_end - tag_begin);
}

string getAttrValue(const string& tag, const string& attr) {
    auto found = tag.find(attr + " =");
    if (found == string::npos) {
        return "Not Found!";
    } else {
        auto left_quote = tag.find_first_of('"');
        auto right_quote = tag.find_first_of('"', left_quote + 1);
        return tag.substr(left_quote, right_quote - left_quote + 1); 
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT    
    string s = "abcLmsKbcfjjbc";
    auto indx = s.find("bc");
    cout << indx << endl;
    auto indx2 = s.find("bc", ++indx);
    cout << indx2 << endl;
    */
    string query = "tag4~x";
    auto qv = parseQuery(query);
    
    for (const auto& e : qv)
        cout << e << " ";
    cout << endl;
    
    StringData data("data.txt");
    cout << data.hrml << endl;
    string tag = findTag(data.hrml, qv);
    cout << "tag: " << tag << endl; 
    string att_val = getAttrValue(tag, qv.back());
    cout << qv.back() << ": " << att_val << endl;                                                 
    
    return 0;
}
