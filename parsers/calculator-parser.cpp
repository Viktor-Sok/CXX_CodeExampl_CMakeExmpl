#include <iostream> 
#include <string> 
#include <cctype> 
 
int expression(); 
 
char token() {  
    std::cout << "token-call" << std::endl; 
    char ch; 
    std::cin >> ch; 
    return ch; 
} 
 
int factor() {  
    std::cout << "factor-call" << std::endl; 
    int val = 0; 
    char ch = token(); 
    if (ch == '(') { 
        std::cout << "factor-call-brackets" << std::endl; 
        val = expression(); 
        ch = token(); 
        if (ch != ')') { 
            std::string error = std::string("Expected ')', got: ") + ch; 
            throw std::runtime_error(error.c_str()); 
        } 
    } 
    else if (isdigit(ch)) { 
        std::cout << "factor-call-unget" << std::endl; 
        std::cin.unget(); 
        std::cin >> val; 
    } 
    else throw std::runtime_error("Unexpected character"); 
    return val; 
} 
 
int term() {  
    std::cout << "term-call" << std::endl;
    int ch; 
    int val = factor(); 
    ch = token(); 
    if (ch == '*' || ch == '/') { 
        std::cout << "term-call-mult-div" << std::endl;
        int b = term(); 
        if (ch == '*') 
            val *= b; 
        else 
            val /= b; 
    } 
    else { 
        std::cin.unget(); 
        std::cout << "term-call-unget" << std::endl;
    }
    return val; 
} 
 
int expression() { 
    std::cout << "expr-call" << std::endl;
    int val = term(); 
    char ch = token(); 
    if (ch == '-' || ch=='+') { 
        std::cout << "expr-call-sub-sum" << std::endl;
        int b = expression(); 
        if (ch == '+') 
            val += b; 
        else 
            val -= b; 
    } 
    else { 
        std::cin.unget(); 
        std::cout << "expr-call-unget" << std::endl;
    }
        
    return val; 
} 
 
int main(int argc, char **argv) { 
    try { 
        std::cout << expression(); 
    } 
    catch(std::exception &e) { 
        std::cout << e.what(); 
    } 
    return 0; 
} 