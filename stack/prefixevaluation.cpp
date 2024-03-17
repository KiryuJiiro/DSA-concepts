#include <iostream>
#include <stack>
#include <cctype>

using namespace std;
string revstring(string str)
{
    string reverse;
    int n = str.length();
    for(int i=n-1;i>=0;i--)
    {
        reverse+=str[i];
    }
    return reverse;
}

int evaluatePostfix(const string& expression) {
    stack<int> operands;
    
    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0');
        } else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            
            switch (c) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                // Feel free to add more operators here if you ever feel adventurous
                default:
                    throw invalid_argument("Invalid operator encountered: " + string(1, c));
            }
        }
    }
    
    return operands.top();
}

int main() {
    string expression;
    cout << "Enter a prefix expression:";
    cin >> expression;
    expression = revstring(expression);
    
    try {
        int result = evaluatePostfix(expression);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    
    return 0;
}
