/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-24 09:13:37
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-24 09:39:01
 * @FilePath: \algorithm\LiKou\随想录\二叉树\24_删除二叉搜索树中的节点.cpp
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

//左右孩子节点都不为空，则将删除节点的左子树头结点（左孩子）
//放到删除节点的 右子树 的最左面节点的 左孩子 上，返回删除节点右孩子为新的根节点。

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == nullptr) return root;

    if(root->val == key){
        //第一种情况   左右孩子都为空
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }

        //第二种情况   左孩子不为空
        else if(root->left != nullptr && root->right == nullptr){
            return root->left;
        }

        //第三种情况   右孩子不为空
        else if(root->right != nullptr && root->left == nullptr){
            return root->right;
        }

        //第四张情况   左右孩子都不为空
        else{
            //找到右节点的最左边的节点
            //将root->left 的节点放到 root->right最左边的节点
            TreeNode* cur = root->right;
            while(cur->left != nullptr){
                cur = cur->left;
            }
            cur->left = root->left;
            
            //返回右节点
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

    }

    if(key > root->val) root->right = deleteNode(root->right, key);
    if(key < root->val) root->left = deleteNode(root->left, key);

    return root;
}