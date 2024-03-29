#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        value = x;
        left = NULL;
        right = NULL;
    }
};

// 前序遍历
void traversal(TreeNode *cur,vector<int> &vec){
    if(cur == NULL){
        return;
    }
    vec.push_back(cur->value);
    traversal(cur->left,vec);
    traversal(cur->right,vec);
}
// 中序遍历
void travermid(TreeNode *cur,vector<int> &vec){
    if(cur == NULL){
        return;
    }
    travermid(cur->left,vec);
    vec.push_back(cur->value);
    travermid(cur->right,vec);
}

// 后序遍历
void traverback(TreeNode *cur,vector<int> &vec){
    if(cur == NULL){
        return;
    }
    traverback(cur->left,vec);
    traverback(cur->right,vec);
    vec.push_back(cur->value);
}

// 栈的前序实现
vector<int> preorderTraversal(TreeNode *root){
    if(root == NULL) return;
    vector<int> res;
    stack<TreeNode *> st;
    st.push(root);
    while(st.size()){
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node->value);
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);

    }
    return res;
}

int main(){
    
    return 0;
}
