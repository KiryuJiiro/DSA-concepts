#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int value)
    {
        data = value;
        next = nullptr;
    }
};


class stackusinglist
{
node* top;

public:

    stackusinglist()
    {
        top = nullptr;
    }

    void push(int value)
    {
        node* newnode = new node(value);

        newnode->next = top;
        top = newnode;
    }   

    void pop()
    {
        int topvalue = top->data;
        node* temp = top;
        top = top->next;
        delete(temp);
        cout<<"Top value is:"<<topvalue<<endl;
    }

    bool isempty()
    {
        return(top == nullptr);
    }
};


int main()
{
    stackusinglist stack;

    stack.push(6);
    stack.push(9);
    stack.push(11);

    while(!stack.isempty())
    {
        stack.pop();
    }
}