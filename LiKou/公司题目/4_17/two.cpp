#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode{
    char name;
    int one_problem;
    int very_problem;
    vector<TreeNode*> chair;
    TreeNode(char x): name(x), one_problem(0), very_problem(0){}
};


unordered_map<char, TreeNode*> root_umap;
vector<TreeNode*> root_list;
unordered_map<char, TreeNode*> umap;
long long n,m;

void dfs(TreeNode* root, long long& very_problem_, long long& one_problem_){
    very_problem_ += root->very_problem;
    one_problem_ += root->one_problem;
    
    if(root->chair.size() == 0) return;

    for(auto chain : root->chair){
        dfs(chain, very_problem_, one_problem_);
    }
}



int main(){
    cin >> n >> m;
    while(m--){
        string str(3, '0');
        for(int i = 0; i < 3; i++){
            cin >> str[i];
        }
        int str_int;
        cin >> str_int;

        // cout << str << endl;
        if(str[1] == '*'){
            if(root_umap[str[0]] == nullptr){
                TreeNode* root = new TreeNode(str[0]);
                if(str[2] == '0') root->very_problem += str_int;
                else if(str[2] == '1') root->one_problem += str_int;
                root_list.push_back(root);
                // cout << str[0] << endl;
                root_umap[str[0]] = root;
                umap[str[0]] = root;
            }
            else{
                if(str[2] == '0') root_umap[str[0]]->very_problem += str_int;
                else if(str[2] == '1') root_umap[str[0]]->one_problem += str_int;
            }
        }

        else{
            if(umap[str[1]] != nullptr){
                if(umap[str[0]] == nullptr){
                    TreeNode* root = new TreeNode(str[0]);
                    if(str[2] == '0') root->very_problem = str_int;
                    else if(str[2] == '1') root->one_problem = str_int;
                    umap[str[1]]->chair.push_back(root);
                    umap[str[0]] = root;
                }
                else{
                    if(str[2] == '0') umap[str[0]]->very_problem += str_int;
                    else if(str[2] == '1') umap[str[0]]->one_problem += str_int;
                }
            }
        }
    }
    int count = 0;
    
    for(auto root : root_list){
        long long very_problem_ = 0;
        long long one_problem_ = 0;
        long long res = 0;
        dfs(root, very_problem_, one_problem_);
        // cout << very_problem_ << " " << one_problem_ << endl;
        // cout << very_problem_ << "  " << one_problem_ << endl;
        res = 5 * very_problem_ + 2 * one_problem_;
        // cout << root->name << " " << res << endl;
        if(res > n) count++;
    }

    cout << count << endl;
    
}