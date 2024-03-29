/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-25 09:32:43
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-25 10:04:18
 * @FilePath: \algorithm\LiKou\随想录\二叉树\26_将有序数组转换为二叉搜索树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
using namespace std;
//10.25
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


TreeNode* traversal(vector<int>& nums, int left, int right){
    if(left > right) return nullptr;
    
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    //左闭右闭区间
    root->left = traversal(nums, left, mid - 1);
    root->right = traversal(nums, mid + 1, right);

    return root;
}


TreeNode* sortedArrayToBST(vector<int>& nums) {
    return traversal(nums, 0, nums.size() - 1);
}