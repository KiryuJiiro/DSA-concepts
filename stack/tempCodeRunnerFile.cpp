#include<iostream>
#include<stack>
using namespace std;

bool operandornot(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

bool openingornt(char c) {
    return (c == '(');
}

bool closingornot(char c) {
    return (c == ')');
}

int precedencelevel(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string asscociativitylevel(char c) {
    if (c == '^')
        return "RTL";
    return "LTR";
}

int main() {
    string exp = "A+B*C/(E-F)";
    string postfix;
    stack<char> st;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (operandornot(exp[i])) {
            postfix += exp[i];
        } else if (openingornt(exp[i])) {
            st.push(exp[i]);
        } else if (closingornot(exp[i])) {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) // Remove the '('
                st.pop();
        } else {
            while (!st.empty() && (precedencelevel(exp[i]) < precedencelevel(st.top()) ||
                (precedencelevel(exp[i]) == precedencelevel(st.top()) && asscociativitylevel(exp[i]) == "LTR"))) {
                postfix += st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << "Infix to postfix: " << postfix << endl;
    return 0;
}
