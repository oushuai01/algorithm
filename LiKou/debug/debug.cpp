#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        // if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}


void quick_sort_(int q[], int l, int r){

    if(l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];

    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) {
            int temp = q[i];
            q[i] = q[j];
            q[j] = temp;
            // swap(q[i], q[j]);
        }
    }

    quick_sort_(q, l, j);
    quick_sort_(q, j + 1, r);

}



void shift_func(int *array, int len, int k)
{
 int i = 0, j = 0;
 int temp = 0;
 if (array == NULL)
  return;
 k %= len;
 for (i = 0; i < k; i++)
 {
  temp = array[len - 1];
  for (j = len - 1; j > 0; j--) // 1
  {
   array[j] = array[j - 1];
  }
  array[0] = temp;
 }
}


int main()
{
    int arr[10] = {1, 5, 8, 9, 45, 15, 36, 56, 20, 3};

    int lenght = sizeof(arr) / sizeof(int);

    quick_sort_(arr, 0, lenght - 1);

    for(int i = 0; i < lenght; i++){
        printf("%d ", arr[i]);
    }

}