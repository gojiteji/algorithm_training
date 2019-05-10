#include <iostream>
using namespace std;

class QUEUE
{
   private:
    float* data;
    int head,tail;
    int size;
   public:
   QUEUE(unsigned int s);
   void enqueue(float datumn);
   float dequeue();
   bool isEmpty();
   bool isFull();
};

   QUEUE::QUEUE(unsigned int s){
    data=new float[s];
    this->size=s;
    this->head=0;//最初のheadはつかう
    this->tail=0;
   }

   void QUEUE::enqueue(float datumn){
       if(tail==size)//maxの時に処理が来たら
        tail=0;
       this->data[tail++]=datumn;
   }
   float QUEUE::dequeue(){
       if(head==size)//maxの時に処理が来たら
              head=0;       
       return this->data[head++];
   }


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
 
    QUEUE b(10);
   for (int i=0;i<6;i++)
        b.enqueue(i);
    cout<<"empty:"<<b.isEmpty()<<endl;
    cout<<"full:"<<b.isFull()<<endl;
    for (int i=0;i<3;i++)
        cout<<b.dequeue()<<endl;
    cout<<"empty:"<<b.isEmpty()<<endl;
    cout<<"full:"<<b.isFull()<<endl;
   for (int i=0;i<7;i++)
        b.enqueue(i);
    cout<<"empty:"<<b.isEmpty()<<endl;
    cout<<"full:"<<b.isFull()<<endl;
    for (int i=0;i<8;i++)
        cout<<b.dequeue()<<endl;
    cout<<"empty:"<<b.isEmpty()<<endl;
    cout<<"full:"<<b.isFull()<<endl;
    for (int i=0;i<2;i++)
        cout<<b.dequeue()<<endl;
    cout<<"empty:"<<b.isEmpty()<<endl;
    cout<<"full:"<<b.isFull()<<endl;


/*
    STACK a(10);
    for (int i=0;i<10;i++)
        a.push(i);
    cout<<"empty:"<<a.isEmpty()<<endl;
    cout<<"full:"<<a.isFull()<<endl;
    for (int i=0;i<10;i++)
        cout<<a.pop()<<endl;
    cout<<"empty:"<<a.isEmpty()<<endl;
    cout<<"full:"<<a.isFull()<<endl;
*/
    return 0;
}
