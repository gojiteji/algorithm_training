#include<stdio.h>
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
void merge_sort (int array[], int left, int right) {
  int i, j, k, mid;
  int work[10];  // 作業用配列
  if (left < right) {
    mid = (left + right)/2; // 真ん中
            cout << "front merge(" << left << "to" << mid << ")" << endl;
    merge_sort(array, left, mid);  // 左を整列
            cout << "back merge(" << mid+1 << "to" << right << ")" << endl;
    merge_sort(array, mid+1, right);  // 右を整列
    for (i = mid; i >= left; i--) { work[i] = array[i]; } // 左半分
    for (j = mid+1; j <= right; j++) {
      work[right-(j-(mid+1))] = array[j]; // 右半分を逆順
    }
    i = left; j = right;
    for (k = left; k <= right; k++) {
      if (work[i] < work[j]) { array[k] = work[i++]; }
      else                   { array[k] = work[j--]; }
    }
  }
}

int main (void) {
  int array[10] = { 2, 1, 8, 5, 4, 7, 9, 0, 6, 3 };
  int i;

  printf("Before sort: ");
  for (i = 0; i < 10; i++) { printf("%d ", array[i]); }
  printf("\n");

  merge_sort(array, 0, 9);

  printf("After sort: ");
  for (i = 0; i < 10; i++) { printf("%d ", array[i]); }
  printf("\n");

  return 0;
}