#include <iostream>
using namespace std;
/* マージソート 
1.前半再帰
    要素一まで下る→return
    要素2で
        左半分workに突っ込む
        右半分w逆順でworkに突っ込む 
        arrayがいっぱいになるまでworkの右と左小さい方を先に詰める
2. 後半再帰
    要素１まで...
    
3. arrayは前半も後半も再帰済み




*/

void mergesort(int arr[], int head, int tail)
{
    cout << "arr[" << tail - head + 1 << "]" << endl;

    for (int i = head; i <= tail; i++)
    {
        cout << arr[i] << " ";
    }

    int mid;
    int work[tail - head + 1];
    if (head < tail)
    {
        mid = (head + tail) / 2;
        cout << "front merge(" << head << "to" << mid << ")" << endl;

        mergesort(arr, head, mid);
        cout << "backword merge(" << mid + 1 << "to" << tail << ")" << endl;

        mergesort(arr, mid + 1, tail);
        cout << "sort" << head << "to" << tail << endl;
        cout << "array[] is: ";
        for (int i = head; i <= tail; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        for (int i = head; i <= mid; i++) //順列
        {
            work[i] = arr[i];
        }
        cout << "mid:" << mid << " head:" << head;
        cout << "順列work[] is: ";
        for (int i = head; i <= tail; i++)
        {
            cout << work[i] << " ";
        }
        cout << endl;

        for (int i = mid + 1; i <= tail; i++) //逆順列
        {
            work[i] = arr[tail + mid + 1 - i];
        }
        cout << "逆順列work[] is: ";
        for (int i = head; i <= tail; i++)
        {
            cout << work[i] << " ";
        }
        cout << endl;

        cout << "work[] is: ";
        for (int i = head; i <= tail; i++)
        {
            cout << work[i] << " ";
        }
        cout << endl;
        cout << "begining marging by comnparig " << head << "and" << tail << endl;
        int i = head;
        int j = tail;
        for (int k = head; k <=tail; k++)
        {
            if (work[i] <= work[j])
            {
                cout << work[i] << "<=" << work[j] << endl;
                arr[k] = work[i];
                i++;
            }
            else
            {
                cout << work[i] << ">" << work[j] << endl;
                arr[k] = work[j];
                j--;
            }
        }
        cout << "finished merge:";
        for (int i = head; i <= tail; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << endl;
    }
    else
    {
        cout << "this is min size" << endl
             << endl;
    }
}
int main(void)
{
    int array[10];
    int k = 0;
    while (k < 10)
        cin >> array[k++];
    int i;
    cout << "starting merge sort" << endl;
    while (k < 10)
        cout << array[k++] << " ";

    mergesort(array, 0, 9);

    cout << "finished merge sort" << endl;
    k = 0;
    while (k < 10)
        cout << array[k++] << " ";
    cout << endl;
    return 0;
}