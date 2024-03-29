/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-17 10:02:24
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-17 10:21:31
 * @FilePath: \algorithm\LiKou\随想录\二叉树\19_二叉搜索树的最小绝对差.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
using namespace std;
//10.17
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

//中序遍历完  就是一个有序数组
vector<int> vec;
void traversal(TreeNode* root){
    if(root == nullptr) return;
    traversal(root->left);
    vec.push_back(root->val);
    traversal(root->right);
    return;
}

int getMinimumDifference(TreeNode* root) {
    traversal(root);
    int result = INT_MAX;
    for(int i = 0; i < vec.size() - 1; i++){
        int temp = vec[i + 1] - vec[i];
        result = min(result, temp);
    }
    return result;
}

