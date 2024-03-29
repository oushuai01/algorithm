/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-15 21:20:57
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-15 21:30:56
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\44_二叉搜索树中第K小的元素.CPP
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//11.15
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int index = 0;
int res = 0;
void backTrack(TreeNode* root){
    if(root == nullptr) return;
    backTrack(root->left);
    if(index == 0) return;
    if(--index ==  0) res = root->val;
    backTrack(root->right);
}
int kthSmallest(TreeNode* root, int k) {
    if(root == nullptr) return 0;

    index = k;
    backTrack(root);
    return res;
    

}

