/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-18 09:18:38
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-18 10:13:50
 * @FilePath: \algorithm\LiKou\随想录\二叉树\20_二叉搜索树中的众数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
using namespace std;
//10.18
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


//由于是二叉搜索树,中序遍历就是有序的
vector<int> vec;
void traversal(TreeNode* root){
    if(root == nullptr) return;
    traversal(root->left);
    vec.push_back(root->val);
    traversal(root->right);

    return;
}

vector<int> findMode(TreeNode* root) {
    if(root != nullptr)
    traversal(root);
    int left = 0;
    int right = 0;
    int count = 0;
    int max_count = 1;
    vector<int> result;
    //有序数组进行找众数
    while(right < vec.size()){
        int num = vec[right];
        if(num == vec[left]){
            count++;
        }
        else{
            count = 1;
            left = right;
        }

        if(count == max_count){
            result.push_back(vec[left]);
        }

        if(count > max_count){
            result.clear();
            result.push_back(vec[left]);
            max_count = max(max_count, count);
        }
        right++;
    }
    return result;
}


//也可以用map记录最多的数字，
//然后转化为vector 按照value进行排序  得到结果