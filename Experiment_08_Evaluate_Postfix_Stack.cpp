#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string expression) {
    stack<int> s;

    for (char ch : expression) {

        if (isspace(static_cast<unsigned char>(ch))) {
            continue;
        }

        if (isdigit(static_cast<unsigned char>(ch))) {
            s.push(ch - '0');
        }

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
