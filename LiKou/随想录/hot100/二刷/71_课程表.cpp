#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// 2024-04-08
// bfs
// 拓扑排序
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
int n = prerequisites.size();
    if(n == 0) return true;

    vector<int> indegree(numCourses, 0);        // 入度
    vector<vector<int>> adjacency(numCourses);  // 邻接矩阵 先修课程-->(后续课程集合)
    queue<int> que;                             // 辅助队列

    // 统计所有节点的入度  构建邻接矩阵
    for(int i = 0; i < n; i++){
        indegree[prerequisites[i][0]]++;
        adjacency[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    // 将所有入度为0的加入队列，入度为0说明没有先修节点
    for(int i = 0; i < indegree.size(); i++){
        if(indegree[i] == 0) que.push(i);
    }
    int count = 0;  // 已学课程
    while(!que.empty()){
        int visited = que.front();
        count++;
        que.pop();
        // 将学完课程的所有后续课程入度减1
        for(int i = 0; i < adjacency[visited].size(); i++){
            indegree[adjacency[visited][i]]--;
            // 如果有后续课程的入度减为零了，则其变为了自由课程，加入队列
            if(indegree[adjacency[visited][i]] == 0)
            que.push(adjacency[visited][i]);
        }

    }
    // 如果学完的课程数=课程总数则返回true，否则返回false
    return count == numCourses;
}