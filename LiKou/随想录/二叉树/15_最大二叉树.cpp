/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-15 15:11:51
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-16 15:09:18
 * @FilePath: \algorithm\LiKou\随想录\二叉树\15_最大二叉树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
using namespace std;

//10.15
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    //终止
    if(nums.size() == 0) return nullptr;
    if(nums.size() == 1) {
        TreeNode* root  = new TreeNode(nums[0]);
        return root;
    }

    //找到最大值索引
    int index_max = 0;
    int max_num = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > max_num){
            max_num = nums[i];
            index_max= i;
        }
    }

    //构建中间节点
    TreeNode* root = new TreeNode(max_num);


    //切割左边
    vector<int> rootLeft(nums.begin(), nums.begin() + index_max);
    //切割右边
    vector<int> rootRight(nums.begin() + index_max + 1, nums.end());

    root->left = constructMaximumBinaryTree(rootLeft);
    root->right = constructMaximumBinaryTree(rootRight);


    return root;
}

//***********
//优化的话  就对于递归函数里面的 vector进行优化   不让他创建空间  而是用下标索引  来表示左范围 右范围
//优化版本
TreeNode* travel_(vector<int>& nums, int node_left, int node_right){
    //判断
    if(node_left == node_right) return nullptr;

    if(node_right - node_left == 1) {
        TreeNode* root = new TreeNode(nums[node_left]);
        return root;
    }

    //找到最大值索引
    int max_num = INT_MIN;
    int index_max = 0;
    for(int i = node_left; i < node_right; i++){
        if(nums[i] > max_num){
            max_num = nums[i];
            index_max = i;
        }
    }

    //建立根节点
    TreeNode* root = new TreeNode(max_num);

    //分割左边
    int leftLeft = node_left;
    int leftRight = index_max;

    //分割右边
    int rightLeft = index_max + 1;
    int rightRight = node_right;

    root->left = travel_(nums, leftLeft, leftRight);
    root->right = travel_(nums, rightLeft, rightRight);
    return root;
}

TreeNode* constructMaximumBinaryTree_(vector<int>& nums){
    if(nums.size() != 0)
    return travel_(nums, 0 , nums.size());
    else return nullptr;
}

