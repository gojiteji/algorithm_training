#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void quicksort(int b[10], int head, int tail)
{
    int middle = b[(head + tail) / 2];
    int i = head;
    int j = tail;
    while (1)
    {
        //まず左から攻める
        while (b[i] < middle)
            i++;
        //hitしたらつずいて右から攻める
        while (b[j] > middle)
            j--;
        if (i >= j)//移動後ピボットが交差したら
            break;
        //hit同士を交換
        swap(b[i], b[j]);
        //交換ごちゃんと次に進む
        i++;
        j++;

    }

    //再帰
    //右に比較できる要素があれば
    if (i - head >1)
        quicksort(b, head, i - 1); //前半。ピボット交差breakでi>jとなああっているので引く。
    //左に比較できる要素があれば
    if (tail - j >1)
        quicksort(b, j + 1, tail); //後半。ピボット交差breakでi>jとなああっているので足す。
}

int main()
{
    int a[10];

    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    cout << "before:";
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    quicksort(a, 0, 9);

    cout << "after:";
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}