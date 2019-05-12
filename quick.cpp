#include <iostream>
#include <algorithm>
using namespace std;
void quick(int array[10],int head,int tail){
    int center=(head+tail)/2;
    int i=head;
    int j=tail;
    while(true){
        while(array[i]<array[center])//pivotは大きさの境界であって、位置の境界ではない!
            i++;//array[i]=>array[center]が分岐条件
        while(array[j]>array[center])
            j--;
        if(i<=j){
        swap(array[i],array[j]);            
        i++;//これないと等号で無限ループが発生。
        j--;
        }else{//重なることはない(i>j)
            //cout<<"array["<<i<<"]="<<array[i]<<","<<"array["<<j<<"]="<<array[j]<<endl;
            break;
        }
    }
    if(j-head>0){//2個以上の要素(自然数の差が存在)
    quick(array,head,j);
    }
    if(tail-i>0){
    quick(array,i,tail);
    }

}
//image:区間をどんどん分割していく
//注意：区切りは交差した配列間であり、pivotではない。



int main(){
    int array[7];
    for(int i=0;i<7;i++)
    cin>>array[i];
    quick(array,0,6);
 
    for(int i=0;i<7;i++)
    cout<<array[i]<<" ";

    return 0;
}