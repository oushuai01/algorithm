/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-14 16:17:49
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-16 20:32:44
 * @FilePath: \algorithm\LiKou\随想录\二叉树\14_从前序与中序遍历序列构造二叉树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
using namespace std;

//10.14
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
    //第一步 可要可不要  不要就在调用函数之前判断一下   要就直接用这个函数 不需要buildTree
    //if(preorder.size() == 0 || inorder.size() == 0) return nullptr;

    //第二步：获取根节点
    int rootValue = preorder[0];
    TreeNode* root = new TreeNode(rootValue);

    //判断是否是叶子节点
    if(preorder.size() == 1) return root;

    //第三步：获取根节点的位置
    int index_;
    for(index_ = 0; index_ < inorder.size(); index_++){
        if(inorder[index_] == rootValue) break;
    }

    //第四步：切割中序
    vector<int> inorderLeft(inorder.begin(), inorder.begin() + index_);
    vector<int> inorderRight(inorder.begin() + index_ + 1, inorder.end());

    //第五步: 切割前序
    vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + 1 + inorderLeft.size());
    vector<int> preorderRight(preorder.begin() + 1 + inorderLeft.size(), preorder.end());
    
    root->left = traversal(preorderLeft, inorderLeft);
    root->right = traversal(preorderRight, inorderRight);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return traversal(preorder, inorder);
}

//***********
//优化的话  就对于递归函数里面的 vector进行优化   不让他创建空间  而是用下标索引  来表示左范围 右范围