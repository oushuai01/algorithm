#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int index = nums1.size() - 1;
    m--;
    n--;

    while(m >= 0 && n >= 0){
        nums1[index--] =  nums1[m] >= nums2[n] ? nums1[m--] : nums2[n--];
    }
    while(m >= 0){
        nums1[index--] = nums1[m--];
    }
    while(n >= 0){
        nums1[index--] = nums2[n--];
    }
}


int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    merge(nums1, 3, nums2, 3);

    for(auto num : nums1) cout << num;
}