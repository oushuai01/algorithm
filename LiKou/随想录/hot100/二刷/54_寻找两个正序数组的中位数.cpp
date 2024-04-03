#include <iostream>
#include <vector>
using namespace std;

// 2024-04-03

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int nums1_size = nums1.size();
    int nums2_size = nums2.size();
    int nums_size = nums1_size + nums2_size;
    int nums1_index = 0, nums2_index = 0;
    vector<int> nums(nums_size, 0);
    int index = 0;
    // 合并两个有序数组
    while(nums1_index != nums1_size && nums2_index != nums2_size){
        if(nums1[nums1_index] <= nums2[nums2_index]) nums[index++] = nums1[nums1_index++];
        else if(nums1[nums1_index] > nums2[nums2_index]) nums[index++]= nums2[nums2_index++]; 
    }

    // 判断哪个数组还有数值
    if(nums1_index == nums1_size){
        for(int i = nums2_index; i < nums2_size; i++)
        nums[index++] = nums2[i];
    }
    else if(nums2_index == nums2_size){
        for(int i = nums1_index; i < nums1_size; i++)
        nums[index++] = nums1[i];
    }

    double result;
    if(nums_size % 2 == 0){
        result = nums[nums_size / 2] + nums[(nums_size / 2) - 1];
        result = result / 2.0;
    }else{
        result = (double)nums[nums_size / 2];
    }


    return result;

}

int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    cout << findMedianSortedArrays(nums1, nums2);
}