/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-22 15:04:38
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-22 15:18:53
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\23_二叉树的中序遍历.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void travermid(TreeNode* cur, vector<int>& vec){
    if(cur == nullptr) return;

    travermid(cur->left, vec);
    vec.push_back(cur->val);
    travermid(cur->right, vec);
}

vector<int> inorderTraversal(TreeNode* root){
    vector<int> vec;
    travermid(root, vec);

    return vec;
}