#include <iostream>
using namespace std;

void heap(int arr[], int e)
{

    /*
p, c ∈ Ｎ
c(p)-head=2(p-head),+2(p-head)+1 #先頭からの番号
p=c^-1=head+(c-head)/2 (int(1/2)=0)
*/
    for (int head = 0; head < e; head++)
    { //上から末端の方向へ大小関係を揃える
        int p = 0;
        int c=e;
        while (p < c)
        {
            p = head + (c-head) / 2;
            if (arr[p] > arr[c])
                swap(arr[p], arr[c]);
            c--; //枝を狭めていく
        }
    }
}

int main()
{
    int arr[11] = {0, 8, 54, 6, 4, 2, 67, 8, 4, 2, 1};
    int i = 1;
    while (i < 11)
        cout << arr[i++] << " ";
    cout << endl;

    heap(arr, 10);
    i = 1;
    while (i < 11)
        cout << arr[i++] << " ";

    return 0;
}