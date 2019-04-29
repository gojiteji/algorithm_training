#include<iostream>
using namespace std;

int a[100]={};

int fib(int n){
    if(n<=1){
        return 1;
    }else{
        a[n]=fib(n-1)+fib(n-2);
        return a[n];
    }
    

}

int main(){
cout<<"fibonach below"<<endl;
for(int i=0;i<100;i++)
cout<<fib(i)<<endl;
    return 0;
}

/*
漸化式
a_n=an-1+an-2
a_1=1,a_2=1
*/