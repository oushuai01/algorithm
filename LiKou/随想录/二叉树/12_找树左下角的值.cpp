/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-13 09:51:43
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-13 10:05:37
 * @FilePath: \algorithm\LiKou\随想录\二叉树\12_找树左下角的值.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
//10.13
#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

int maxDepth = INT_MIN;
int result;


//前序遍历   最先访问的就是左边节点
void traversal(TreeNode* root, int depth){
    if(root->left == nullptr && root->right == nullptr){
        if(depth > maxDepth){
            //更新信息
            maxDepth = depth;
            result = root->val;
        }
        return;
    }
    if(root->left)
    traversal(root->left, depth + 1);
    if(root->right)
    traversal(root->right, depth + 1);

    return;
}

int findBottomLeftValue(TreeNode* root) {
    if(root != nullptr)
    traversal(root, 1);

    return result;
}
