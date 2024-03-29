/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-24 10:08:31
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-24 10:20:31
 * @FilePath: \algorithm\LiKou\随想录\二叉树\25_修剪二叉搜索树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
using namespace std;
//10.24
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

//修剪在区间内的二叉树
TreeNode* trimBST(TreeNode* root, int low, int high) {
    if(root == nullptr) return nullptr;

    //判断符合条件的节点
    if(root->val < low){
        TreeNode* right = trimBST(root->right, low, high);
        return right;
    }
    //判断符合条件的节点
    else if(root->val > high){
        TreeNode* left = trimBST(root->left, low, high);
        return left;
    }
    //用来接住符合条件的节点
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
}
