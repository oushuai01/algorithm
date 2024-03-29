/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-07-04 21:07:24
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-04 16:57:20
 * @FilePath: \algorithm\LiKou\随想录\哈希表\2-两个数组的交集.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> res_;
    unordered_set<int> set_1(nums1.begin(),nums1.end());
    for(int num:nums2){
        if(set_1.find(num) != set_1.end()){
            res_.insert(num);
        }
    }
    return vector<int>(res_.begin(),res_.end());


}
int main(){



    return 0;
}