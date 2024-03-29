/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-17 09:38:19
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-17 09:54:30
 * @FilePath: \algorithm\LiKou\随想录\二叉树\18_验证二叉搜索树.cpp
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

bool isValidBST(TreeNode* root) {
    if(root == nullptr) return false;
    traversal(root);
    for(int i = 0; i < vec.size() - 1; i++){
        if(vec[i] >= vec[i + 1]) return false;
    }
    return true;
}
