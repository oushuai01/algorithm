#include <iostream>
#include <vector>
using namespace std;
//暴力做法
// int removeElement(vector<int>& nums, int val){
//     int size_ = nums.size() - 1;
//     for(int i = 0; i <= size_; i++){
//         if(nums[i] == val){
//         for(int j = i; j <= size_; j++){
//             nums[j] = nums[j+1];
//         }
//         size_ -= 1;
//         i -= 1;
//         }
//     }
//     for(int i = 0; i <= size_; i ++ ){
//         cout << nums[i] << " ";
//     }
//     cout << endl;
//     return size_ + 1;

// }
//双指针
int removeElement(vector<int>& nums, int val){

    int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (leftIndex <= rightIndex) {
            // 找左边等于val的元素
            while (leftIndex <= rightIndex && nums[leftIndex] != val){
                ++leftIndex;
            }
            // 找右边不等于val的元素
            while (leftIndex <= rightIndex && nums[rightIndex] == val) {
                -- rightIndex;
            }
            // 将右边不等于val的元素覆盖左边等于val的元素
            if (leftIndex < rightIndex) {
                nums[leftIndex++] = nums[rightIndex--];
            }
        }
        return leftIndex;   // leftIndex一定指向了最终数组末尾的下一个元素
}
int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int  val = 2;
    cout << removeElement(nums,val);
    return 0;
}