/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-12 09:31:49
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-12 18:27:31
 * @FilePath: \algorithm\LiKou\随想录\二叉树\10_ 二叉树的所有路径.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

//10.12
#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

void traversal(TreeNode* cur, string path, vector<string>& result) {
    path += to_string(cur->val);
    if(cur->left == nullptr && cur->right == nullptr) result.push_back(path);

    if(cur->left){
        path += "->";
        traversal(cur->left, path, result);
        //回溯
        path.pop_back();
        path.pop_back();

        //traversal(cur->left, path + "->", result);   这样写就不用写pop 带了回溯的思想
    }

    if(cur->right){
        path += "->";
        traversal(cur->right, path, result);
    }


}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    string path;
    if(root == nullptr) return res;
    traversal(root, path, res);

    return res;
}