/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-09 19:14:56
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-09 19:26:51
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\42_将有序数组转换为二叉搜索树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//11.09
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode* travesal(vector<int> nums, int left, int right){
    if(left > right) return nullptr;

    // 也可以用 left + (right - left) / 2  防止数字过大溢出
    int mid = (right + left) / 2;

    TreeNode* root = new TreeNode(nums[mid]);

    root->left = travesal(nums, left, mid - 1);
    root->right = travesal(nums, mid + 1, right);

    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums){
    if(nums.size() != 0) return travesal(nums, 0, nums.size() - 1);
    else return nullptr;
}