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



vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if(root != NULL)
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        vector<int> vec;
        for(int i = 0; i < size; i++){
            TreeNode* node = que.front();
            que.pop();

            vec.push_back(node->val);
            if(node->left != NULL)
            que.push(node->left); 

            if(node->right != NULL)
            que.push(node->right);
        }
        res.push_back(vec);
    }

    return res;
}



// 递归法
class Solution {
public:
    void order(TreeNode* cur, vector<vector<int>>& result, int depth)
    {
        //depth 用的好
        if (cur == nullptr) return;
        if (result.size() == depth) result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        order(root, result, depth);
        return result;
    }
};




//10.09
//107  二叉树的层序遍历 II
//https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if(root != NULL)
    que.push(root);

    while(!que.empty()){
        int size = que.size();
        vector<int> vec;
        for(int i = 0; i < size; i++){
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if(node->left != NULL) que.push(node->left);
            if(node->right != NULL) que.push(node->right);
        }

        res.push_back(vec);
    }

    reverse(res.begin(), res.end());

    return res;
}

//10.09
//199 二叉树的右视图
//https://leetcode.cn/problems/binary-tree-right-side-view/

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> que;
    if(root != NULL)
    que.push(root);

    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i < size; i++){
            TreeNode* node = que.front();
            que.pop();
            if(node->left != NULL) que.push(node->left);
            if(node->right != NULL) que.push(node->right);

            if(i == (size - 1))
            res.push_back(node->val);
        }
    }

    return res;
}


//10.09
//637. 二叉树的层平均值
//https://leetcode.cn/problems/average-of-levels-in-binary-tree/

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    queue<TreeNode*> que;
    if(root != nullptr)
    que.push(root);

    while(!que.empty()){
        int size = que.size();
        double num = 0;
        for(int i = 0; i < size; i++){
            TreeNode* node = que.front();
            que.pop();
            num += node->val;
            if(node->left != NULL) que.push(node->left);
            if(node->right != NULL) que.push(node->right);
        }
        res.push_back(num / size);
    }
    return res;
}


//10.09
//429. N 叉树的层序遍历
//https://leetcode.cn/problems/n-ary-tree-level-order-traversal/

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    queue<Node*> que;
    if(root != nullptr) que.push(root);

    while(!que.empty()){
        int size = que.size();
        vector<int> vec;
        for(int i = 0; i < size; i++){
            Node* node = que.front();
            que.pop();
            vec.push_back(node->val);
            for(Node* node_ : node->children){
                if(node_ != nullptr)
                que.push(node_);
            }
        }
        res.push_back(vec);
    }

    return res;
}


//10.09
//515. 在每个树行中找最大值
//https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> que;
    if(root != NULL)
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        int MAX = INT32_MIN;
        for(int i = 0; i < size; i++){
            TreeNode* node = que.front();
            que.pop();
            MAX = node->val > MAX ? node->val : MAX;
            if(node->left != NULL)
            que.push(node->left); 

            if(node->right != NULL)
            que.push(node->right);
        }
        res.push_back(MAX);
    }

    return res;
}


//10.09
//116. 填充每个节点的下一个右侧节点指针
//117. 填充每个节点的下一个右侧节点指针II
//https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    queue<Node*> que;
    if(root != nullptr) que.push(root);

    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i < size; i++){
            Node* node = que.front();
            que.pop();
            if(i < (size - 1)) node->next = que.front();
            else node->next = nullptr;

            if(node->left != nullptr) que.push(node->left);
            if(node->right != nullptr) que.push(node->right);
        }
    }
    return root;
}


//104. 二叉树的最大深度
//https://leetcode.cn/problems/maximum-depth-of-binary-tree/
int maxDepth(TreeNode* root) {
    int res = 0;
    queue<TreeNode*> que;
    if(root != NULL) que.push(root);
    while(!que.empty()){
        int size = que.size();
        vector<int> vec;
        for(int i = 0; i < size; i++){
            TreeNode* node = que.front();
            que.pop();
            if(node->left != NULL) que.push(node->left); 
            if(node->right != NULL) que.push(node->right);
        }
        res += 1;
    }

    return res;
}

//111. 二叉树的最小深度
//https://leetcode.cn/problems/minimum-depth-of-binary-tree/
int minDepth(TreeNode* root) {
    int res = 0;
    queue<TreeNode*> que;
    if(root != nullptr) que.push(root);
    while(!que.empty()){
        int size = que.size();
        vector<int> vec;
        for(int i = 0; i < size; i++){
            TreeNode* node = que.front();
            que.pop();
            if(node->left == nullptr && node->right == nullptr) return res + 1;
            if(node->left != nullptr) que.push(node->left); 
            if(node->right != nullptr) que.push(node->right);
        }
        res += 1;
    }
    return res;
}