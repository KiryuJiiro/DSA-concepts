#include<iostream>
#include<stack>
using namespace std;

bool checkparan(string exp)
{
    int len=exp.length();
    stack<char> list;
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
            list.push(exp[i]);
        }
        else if(exp[i]==')')
        {
            if(list.empty())
            {
                return false;
            }
            else
            {
                list.pop();
            }
        }
    }
    return list.empty();
}

int main()
{
    string expression;
    cout<<"Enter an expression:";
    cin>>expression;
    if(checkparan(expression))
    {
        cout<<"Paranthesis balanced";
    }
    else 
    {
        cout<<"Paranthesis not balanced";
    }
    return 0;
}