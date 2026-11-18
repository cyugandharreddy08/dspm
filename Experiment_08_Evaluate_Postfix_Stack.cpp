/*
 * ============================================================================
 * Experiment No. 8
 * Aim: To evaluate a valid single-digit postfix expression using the Stack 
 *      data structure.
 * Course: Data Structures and Programming Methodology Laboratory (PCL03DSPM)
 * ============================================================================
 */

#include <iostream> 
#include <stack> 
#include <string> 
#include <cctype> 
using namespace std; 
 
// Evaluate a postfix expression 
int evaluatePostfix(string expression) { 
    stack<int> s; 
 
    for (char ch : expression) { 
        // Ignore spaces 
        if (isspace(static_cast<unsigned char>(ch))) { 
            continue; 
        } 
 
        // If the character is a digit, push it 
        if (isdigit(static_cast<unsigned char>(ch))) { 
            s.push(ch - '0'); 
        } 
        // Otherwise, perform the operation 
        else { 
            if (s.empty()) {
                throw string("Invalid postfix expression: insufficient operands!");
            }
            int right = s.top(); 
            s.pop(); 
 
            if (s.empty()) {
                throw string("Invalid postfix expression: insufficient operands!");
            }
            int left = s.top(); 
            s.pop(); 
 
            int result; 
 
            switch (ch) { 
                case '+': 
                    result = left + right; 
                    break; 
 
                case '-': 
                    result = left - right; 
                    break; 
 
                case '*': 
                    result = left * right; 
                    break; 
 
                case '/': 
                    if (right == 0) { 
                        throw string("Division by zero!"); 
                    } 
                    result = left / right; 
                    break; 
 
                default: 
                    throw string("Invalid operator!"); 
            } 
 
            s.push(result); 
        } 
    } 
 
    if (s.size() != 1) {
        throw string("Invalid postfix expression: excess operands remaining!");
    }

    return s.top(); 
} 
 
int main() { 
    string expression; 
 
    cout << "Enter a postfix expression: "; 
    getline(cin, expression); 
 
    try { 
        int result = evaluatePostfix(expression); 
        cout << "Result = " << result << endl; 
    } 
    catch (const string& error) { 
        cout << error << endl; 
    } 
 
    return 0; 
}
