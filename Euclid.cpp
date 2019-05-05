#include <iostream>
using namespace std;


int EU(int a, int b)
{
    while(true){
        a=a%b;
        if(a==0)
        break;
        swap(a,b);
    }
    return b;
    
}

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    if(b>a){
        swap(a,b);
    }
    cout << EU(a, b) << endl;

    return 0;
}
/*
Calculate the Great common divsor
commondivisor<=a,b

*/
