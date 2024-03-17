#include<iostream>
#include<stack>
using namespace std;

 void paracheck(string c)
{
    stack<char> st;
    int i,n;
    n = c.length();
    for(i=0; i<n ;i++)
    {
        if(c[i]=='(')
        {
            st.push('(');
        }
        else if(c[i]==')')
        {
            if(st.empty())
            {
                cout<<"unmatched paranthesis"<<endl;
            }
            st.pop();
        }
    }

}

int main()
{
    string exp;
    exp="(a+b)";
}