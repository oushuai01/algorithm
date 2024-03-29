#include <iostream>
#include <vector>
using namespace std;
void quick_sort(vector<int> &vc, int l, int r){
    if(l >= r) return;
    int x = vc[l + r >> 1], i = l - 1, j = r + 1;
    while(i < j){
        do i++; while(vc[i] < x);
        do j--; while(vc[j] > x);
        if(i < j) swap(vc[i],vc[j]);
    }
    quick_sort(vc,l,j);
    quick_sort(vc,j + 1,r);
}

int main(){
    int n;
    scanf("%d",&n);
    vector<int> vec(n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&vec[i]);
    }
    quick_sort(vec,0,n-1);
    for(int i = 0; i < n; ++i){
        printf("%d",vec[i]);
    }
    return 0;


}




