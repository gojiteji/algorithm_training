#include <iostream>
#include <algorithm>
using namespace std;
void quick(int array[10], int head, int tail)
{
    int center = array[(head + tail) / 2];
    int i = head;
    int j = tail;
    while (true)
    {
        while (array[i] < center) //pivotは大きさの境界であって、位置の境界ではない!
            i++;                  //array[i]=>array[center]が分岐条件
        while (array[j] > center)
            j--;

        if(i>=j)
            break;
        swap(array[i], array[j]);
        i++; //これないと等号で無限ループが発生。
        j--;
    }
    /*
    whileでi=jとなった時の動作
    - i→i+1=jと移動する
        つまりa[i+1]はpivより大きい
        a[j]はpivより大きいので、次のfor分で確実に過ぎ去る

        重なる→iの止まってる場所にjが来る→a[i]はpivより大きい→jは過ぎ去る
        i-1はiが過ぎたはずなので、jは確実に止まる
        よって確実に一個差で終了する。(要素>2)
    */
    if (i-1 - head > 0) //2個以上の要素(自然数の差が存在)
        quick(array, head, i-1);
    if (tail - (j+1) > 0)
        quick(array, j+1, tail);
}
//image:区間をどんどん分割していく
//注意：区切りは交差した配列間であり、pivotではない。

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
        cin >> array[i];
    quick(array, 0, 9);

    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";

    return 0;
}
