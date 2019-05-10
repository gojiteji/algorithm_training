#include <iostream>
using namespace std;

class QUEUE
{
    int a;
};

class STACK
{
private:
    unsigned int size;
    float *data;
    int top;

public:
    STACK(unsigned int s);
    float pop();
    void push(float a);
    bool isEmpty();
    bool isFull();
};

STACK::STACK(unsigned int s)
{
    this->size = s;
    this->data = new float[size+1];//先頭はis empty専用()is emptyは先頭の一致のみを見るためなにも容れない)
    this->top = 0; //先頭アドレス
}

void STACK::push(float a)
{
    this->data[++top] = a;
}
float STACK::pop()
{
    return this->data[top--];
}

bool STACK::isEmpty()
{
    return (this->top == 0 )? true:false;
}
bool STACK::isFull()
{
   return (this->top == this->size) ? true:false;
}

int main()
{
    STACK a(10);
    QUEUE b;
    for (int i=0;i<10;i++)
        a.push(i);
    cout<<"empty:"<<a.isEmpty()<<endl;
    cout<<"full:"<<a.isFull()<<endl;
    for (int i=0;i<10;i++)
        cout<<a.pop()<<endl;
    cout<<"empty:"<<a.isEmpty()<<endl;
    cout<<"full:"<<a.isFull()<<endl;

    return 0;
}
