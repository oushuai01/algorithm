/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-14 13:52:25
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-14 14:25:35
 * @FilePath: \algorithm\LiKou\随想录\二叉树\13_路径总和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//10.14

#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

//会全部遍历
bool flag = false;
void traversal(TreeNode* root, int curSum, int targetSum){
    curSum += root->val;
    if(root->left == nullptr && root->right == nullptr && curSum == targetSum){
        flag = true;
        return;
    }
    if(root->left)
    traversal(root->left, curSum, targetSum);
    if(root->right)
    traversal(root->right, curSum, targetSum);
    
    return;
}
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root != nullptr)
    traversal(root, 0, targetSum);
    return flag;
}




//此题由于不需要全部遍历
//找到立刻返回
bool traversal_(TreeNode* cur, int count){
    if(!cur->left && !cur->right && count == 0) return true;
    if(!cur->left && !cur->right) return false;

    if(cur->left){
        if(traversal_(cur->left, count - cur->left->val)) return true;
    }

    if(cur->right){
        if(traversal_(cur->right, count - cur->right->val)) return true;
    }

    return false;
}

bool hasPathSum_(TreeNode* root, int targetSum) {
    if(root != nullptr)
    return traversal_(root, targetSum - root->val);
    else return false;
}
