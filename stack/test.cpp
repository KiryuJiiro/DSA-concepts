#include<iostream>
#include<stack>
#include<string>
using namespace std;

string changebrackets(string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
            str[i]=')';
        else if(str[i]==')')
            str[i]='(';
    }
    return str;
}

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
    postfix = revstring(postfix);
    postfix = changebrackets(postfix);

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

    postfix = revstring(postfix);

    cout << "Infix to postfix: " << postfix << endl;
    return 0;
}
