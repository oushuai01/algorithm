/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-23 15:14:47
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-25 10:31:02
 * @FilePath: \algorithm\LiKou\随想录\二叉树\22_二叉搜索树的最近公共祖先.cpp
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

//找到最近的一个在区间 [p,q] 里面  就是他的公共祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) return nullptr;

    if(root->val > p->val && root->val > q->val){
        TreeNode* left = lowestCommonAncestor(root->left, p , q);
        if(left != nullptr) return left;
    }


    if(root->val < p->val && root->val < q->val){
        TreeNode* right = lowestCommonAncestor(root->right, p , q);
        if(right != nullptr) return right;
    }

    return root;
}