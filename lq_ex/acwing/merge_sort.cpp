#include <iostream>
using namespace std;
const int N = 1000010;
int n;
int q[N],temp[N];
void merge_sort(int q_[], int l, int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    merge_sort(q_,l,mid);
    merge_sort(q_,mid,r);

    int k = 0, i = l, j = r;
    while(i <= mid && j <= r){
        if(q_[i] < q_[j]) temp[k++] = q_[i++];
        else temp[k++] = q_[j++];
    }
    while(i <= mid) temp[k++] = q_[i++];
    while(j <= r) temp[k++] = q_[j++];

    for(i = l, j = 0; i <= r;i ++,j ++)
    q_[i] = temp[j];

}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) scanf("%d",q[i]);

    merge_sort(q, 0 , n-1);
    for (int i = 0; i < n; i++) printf("%d",q[i]);
    
}