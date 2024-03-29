/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-23 15:28:15
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-23 15:41:52
 * @FilePath: \algorithm\LiKou\随想录\二叉树\23_二叉搜索树中的插入操作.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
using namespace std;
//10.23
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

//插入操作不需要改变二叉树的顺序
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == nullptr){
        TreeNode* node = new TreeNode(val);
        return node;
    }

    if(val < root->val)
    root->left = insertIntoBST(root->left, val);
    if(val > root->val)
    root->right = insertIntoBST(root->right, val);

    return root;
}

//这个题用迭代法也可以
TreeNode* insertIntoBST_(TreeNode* root, int val) {
    if(root == nullptr){
        TreeNode* node = new TreeNode(val);
        return node;
    }

    TreeNode* cur = root;
    TreeNode* parent = root;
    while(cur != nullptr){
        parent = cur;
        if(val > cur->val) cur = cur->right;
        else cur = cur->left;
    }

    TreeNode* node = new TreeNode(val);
    if(val > parent->val){
        parent->right = node;
    }else{
        parent->left = node;
    }

    return root;
}