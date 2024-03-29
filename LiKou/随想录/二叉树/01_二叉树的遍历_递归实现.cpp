/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-08 09:44:01
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-08 10:11:49
 * @FilePath: \algorithm\LiKou\随想录\二叉树\01_二叉树的递归遍历.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * 递归实现
*/



struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

//前
void traversal(TreeNode* cur, vector<int>& vec){
    if(cur == NULL)
    return;

    vec.push_back(cur->val);
    traversal(cur->left, vec);
    traversal(cur->right, vec);
}
//中
void travermid(TreeNode* cur, vector<int>& vec){
    if(cur == NULL)
    return;

    travermid(cur->left, vec);
    vec.push_back(cur->val);
    travermid(cur->right, vec);

}
//后
void traverback(TreeNode* cur, vector<int>& vec){
    if(cur == NULL)
    return;

    traverback(cur->left, vec);
    traverback(cur->right, vec);
    vec.push_back(cur->val);

}






