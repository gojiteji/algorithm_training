#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int array[10];
    for(int i=0;i<10;i++)
    cin>>array[i];
    
    for (int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(array[i]>array[j])//自分より右側に自分より小さいのがいたら左側に追いやる(じゅぶんと入れ替え)
            swap(array[i],array[j]);
        }
    }
    for(int i=0;i<10;i++)
    cout<<array[i]<<" ";

    return 0;
}