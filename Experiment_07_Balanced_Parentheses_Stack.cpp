#include <iostream> 
#include <stack> 
#include <string> 
using namespace std; 
 
// Check whether two brackets match 
bool isMatching(char opening, char closing) { 
    return (opening == '(' && closing == ')') || 
           (opening == '[' && closing == ']') || 
           (opening == '{' && closing == '}'); 
} 
 
// Check balanced parentheses 
bool isBalanced(string expression) { 
    stack<char> s; 
 
    for (char ch : expression) { 
        // Push opening brackets 
        if (ch == '(' || ch == '[' || ch == '{') { 
            s.push(ch); 
        } 
        // Process closing brackets 
        else if (ch == ')' || ch == ']' || ch == '}') { 
            if (s.empty()) { 
                return false; 
            } 
 
            if (!isMatching(s.top(), ch)) { 
                return false; 
            } 
 
            s.pop(); 
        } 
    } 
 
    return s.empty(); 
} 
 
int main() { 
    string expression; 
 
    cout << "Enter an expression: "; 
    getline(cin, expression); 
 
    if (isBalanced(expression)) { 
        cout << "The expression has balanced parentheses." 
             << endl; 
    } else { 
        cout << "The expression has unbalanced parentheses." 
             << endl; 
    } 
 
    return 0; 
}
