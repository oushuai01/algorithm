/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-13 09:31:23
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-13 09:46:39
 * @FilePath: \algorithm\LiKou\随想录\二叉树\11_左叶子之和.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//10.13
#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};
//左右中遍历顺序
int sumOfLeftLeaves(TreeNode* root) {
    if(root ==  nullptr) return 0;

    int leftvalue = sumOfLeftLeaves(root->left);
    if(root->left && !root->left->left && !root->left->right)
    leftvalue = root->left->val;

    int rightvalue = sumOfLeftLeaves(root->right);

    int sum = leftvalue + rightvalue;
    return sum;
}
