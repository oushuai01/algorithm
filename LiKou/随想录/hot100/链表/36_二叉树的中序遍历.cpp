/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-06 15:45:16
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-06 15:45:58
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\36_二叉树的中序遍历.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};


void travermid(TreeNode* cur, vector<int>& vec){
    if(cur == NULL)
    return;

    travermid(cur->left, vec);
    vec.push_back(cur->val);
    travermid(cur->right, vec);

}
    vector<int> inorderTraversal(TreeNode* root) {
                vector<int> vec;
        travermid(root, vec);
        return vec;
    }
