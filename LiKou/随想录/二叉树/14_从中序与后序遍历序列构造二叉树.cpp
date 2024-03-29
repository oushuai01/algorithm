/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-14 15:46:48
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-15 15:11:08
 * @FilePath: \algorithm\LiKou\随想录\二叉树\14_从中序与后序遍历序列构造二叉树.cpp
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


TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
    //第一步
    if(postorder.size() == 0) return nullptr;

    //第二步: 后序遍历的最后一个元素，就是当前的中间节点
    int rootValue = postorder[postorder.size() - 1];
    TreeNode* root = new TreeNode(rootValue);

    //叶子节点
    if(postorder.size() == 1) return root;


    //第三步：找切割点
    int index_;
    for(index_ = 0; index_ < inorder.size(); index_++){
        if(inorder[index_] == rootValue) break;
    }

    //第四步切割中序
    vector<int> inorderLeft(inorder.begin(), inorder.begin() + index_);
    vector<int> inorderRight(inorder.begin() + index_ + 1, inorder.end());

    //第五步切割后序
    postorder.resize(postorder.size() - 1);
    vector<int> postorderLeft(postorder.begin(), postorder.begin() + inorderLeft.size());
    vector<int> postorderRight(postorder.begin() + inorderLeft.size(), postorder.end());
    
    //debug
    cout << "----------" << endl;
    for(int num : inorderLeft) cout << num << " ";
    cout << endl;
    for(int num : inorderRight) cout << num << " ";
    cout << endl;
    for(int num : postorderLeft) cout << num << " ";
    cout << endl;
    for(int num : postorderRight) cout << num << " ";
    cout << endl;


    root->left = traversal(inorderLeft, postorderLeft);
    root->right = traversal(inorderRight, postorderRight);

    return root;
}


 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
    return traversal(inorder, postorder);
 }

 int main(){
    vector<int> inorder = {9,3,15,20,7}, postorder = {9,15,7,20,3};
    buildTree(inorder, postorder);
 }

//***********
//优化的话  就对于递归函数里面的 vector进行优化   不让他创建空间  而是用下标索引  来表示左范围 右范围