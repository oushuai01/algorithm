/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-08 10:11:53
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-08 10:50:54
 * @FilePath: \algorithm\LiKou\随想录\二叉树\02_二叉树的递归遍历_迭代实现.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};


//前序
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> STA;
    vector<int> vec;
    if(root == NULL) return vec;
    STA.push(root);
    while(!STA.empty()){
        TreeNode* node = STA.top();
        STA.pop();

        vec.push_back(node->val);  //中
        
        if(node->right != NULL)   //右
        STA.push(node->right);

        if(node->left != NULL)    //左
        STA.push(node->left);

        //先右后左  是为了出栈的时候是 根左右
    }
    return vec;
}

//中序
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vec;
    stack<TreeNode*> STA;
    TreeNode* cur = root;
    while(cur != NULL || !STA.empty()){
        if(cur != NULL){     // 指针来访问节点，访问到最底层
            STA.push(cur);   // 将访问的节点放进栈
            cur = cur->left;  // 左
        }else{
            cur = STA.top();  // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
            STA.pop();
            vec.push_back(cur->val);    // 中
            cur = cur->right;           // 右
        }
    }
    return vec;
}

//后序  在前序上稍作修改
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> STA;
    vector<int> vec;
    if(root == NULL) return vec;
    STA.push(root);
    while(!STA.empty()){
        TreeNode* node = STA.top();
        STA.pop();

        // 中右左的遍历顺序
        vec.push_back(node->val);  //中
        
        if(node->left != NULL)   // 修改 //左
        STA.push(node->left);

        if(node->right != NULL)    // 修改 //右
        STA.push(node->right);
        
    }

    //再反转数组  左右中
    reverse(vec.begin(), vec.end());

    return vec;
}