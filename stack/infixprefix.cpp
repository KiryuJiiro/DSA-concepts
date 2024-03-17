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

bool operandornot(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    else
        return false;
}


bool openingornot(char c)
{
    if(c == '(')
        return true;
    else
        return false;
}

bool closeornot(char c)
{
    if(c == ')')
        return true;
    else
        return false;
}

int checkprecedence(char c)
{
    if(c == '^')
        return 4;
    else if((c == '/') || (c == '*'))
        return 3;
    else if((c == '+') || (c == '-'))
        return 2;
    else 
        return -1;
}

string checkassociativity(char c)
{
    if(c == '^')
        return "RTL";
    else 
        return "LTR";
}

int main()
{
    string exp;
    stack<char> list;
    string prefix;
    cout<<"Enter an expression:";
    cin>>exp;
    cout<<exp<<endl;
    exp=revstring(exp);
    // exp = "(B+A)";
    exp=changebrackets(exp);
    cout<<exp<<endl;
    for(int i=0;i<exp.length();i++)
    {
        if(operandornot(exp[i]))
        {
            prefix+=exp[i];
        }

        else if(openingornot(exp[i]))
        {
            list.push('(');
        }

         else if (closeornot(exp[i]))
       {
            while (list.top() != '(')
            {
                prefix += list.top();
                list.pop();
            }
                list.pop();
        }

        else
        {
            while((!list.empty()) && (checkprecedence(exp[i]) > checkprecedence(list.top())))
            {
                prefix+=list.top();
                list.pop();
            }
            // while((!list.empty()))
                list.push(exp[i]);
        }
    }
     while(!list.empty())
            {
                prefix+=list.top();
                list.pop();
            }
    prefix = revstring(prefix);
    cout<<"Prefix expression:"<<prefix<<endl;
    return 0;
}