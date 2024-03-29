/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-25 10:14:09
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-25 10:31:58
 * @FilePath: \algorithm\LiKou\随想录\二叉树\27_把二叉搜索树转换为累加树.cpp
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

int pre = 0;
void traversal(TreeNode* cur) {    // 右中左遍历
    if(cur == nullptr) return;

    traversal(cur->right);
    //进行累加
    cur->val += pre;
    pre = cur->val;
    traversal(cur->left);

    return;
}

TreeNode* convertBST(TreeNode* root) {
    if(root == nullptr) return root;
    traversal(root);

    return root;
}
