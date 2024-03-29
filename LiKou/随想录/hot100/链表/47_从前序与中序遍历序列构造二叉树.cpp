/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-17 22:12:28
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-17 22:32:14
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\47_从前序与中序遍历序列构造二叉树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-17 22:12:28
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-17 22:31:26
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\47_从前序与中序遍历序列构造二叉树.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//11.17
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode* frontTrack(vector<int>& preorder, vector<int>& inorder){
    if(preorder.size() == 0 || inorder.size() == 0) return nullptr;
    
    // 根节点
    int root_val = preorder[0];
    TreeNode* root = new TreeNode(root_val);

    // 判断是否是叶子节点
    if(preorder.size() == 1) return root;

    // 根节点的下标
    int index = 0;
    for(auto node : inorder){
        if(node == root_val)
        break;
        index++;
    }
    // 切割中序
    vector<int> inorderLeft(inorder.begin(), inorder.begin() + index);
    vector<int> inorderRight(inorder.begin() + index + 1, inorder.end());
    

    // 切割前序
    vector<int> perrorLeft(preorder.begin() + 1, preorder.begin() + 1 + inorderLeft.size());
    vector<int> perrorRight(preorder.begin() + 1 + + inorderLeft.size(), preorder.end());

    root->left = frontTrack(perrorLeft, inorderLeft);
    root->right = frontTrack(perrorRight, inorderRight);

    return root;

}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    return frontTrack(preorder, inorder);
}