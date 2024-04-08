#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2024-04-07

vector<vector<int>> result;
vector<int> path;

// 请你找出所有从节点 0 到节点 n-1 的路径并输出
void backTrack(vector<vector<int>>& graph, int start){
    // 找出到 n- 1的路径
    if(start == graph.size()  - 1)
    {
        result.push_back(path);
        return;
    }
    for(int i = 0; i < graph[start].size(); i++){
        path.push_back(graph[start][i]);
        backTrack(graph, graph[start][i]);
        path.pop_back();
    }
}


vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    path.push_back(0);
    backTrack(graph, 0);
    return result;
}