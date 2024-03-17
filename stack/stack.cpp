#include<iostream>
using namespace std;

class stack
{
public:
    int size;
    int top;
    int* arr;

    void initstack()
    {
        cout<<"Enter size of stack:";
        cin>>this->size;
        this->arr=new int[this->size];
        this->top=-1;
    }

    bool isempty()
    {
        return (this->top==-1);
    }

    bool isfull()
    {
        return(this->top==(this->size-1));
    }

    void push(int value)
    {
        if(this->isfull())
        {
            cout<<"Stack-overflow"<<endl;
            exit(0);
        }   
        this->arr[++this->top]=value;
    }

    int pop()
    {
        if(this->isempty())
        {
            cout<<"Stack-underflow";
            exit(0);
        }
        return this->arr[this->top--];
    }

    int showtop()
    {
        return this->arr[this->top];
    }
};

int main()
{
    stack st;
    st.initstack();
    st.push(69);
    st.push(911);
    st.push(420);

    cout<<"Top element:"<<st.showtop()<<endl;
    cout<<"Popped element:"<<st.pop()<<endl;
    cout<<"Popped element:"<<st.pop()<<endl;
    cout<<"Top element:"<<st.showtop()<<endl;
    
    return 0;
}