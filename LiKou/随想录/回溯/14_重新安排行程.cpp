#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

// 11.22

// 第二个数据结构用 map 是因为 要排序
unordered_map<string, map<string, int>> fly_map;
bool tarck(int num, vector<string>& result){
    // 当 result 的长度 == 路径的条数 + 1  说明找到了
    if(result.size() == num + 1){
        return true;
    }

    // 必须加引用  需要对里面的内容进行更改
    for(auto& pair_map : fly_map[result.back()]){
        if(pair_map.second > 0){     // 记录此路径是否飞过
            result.push_back(pair_map.first);
            pair_map.second--;
            if(tarck(num, result)) return true;
            result.pop_back();
            pair_map.second++;
        }
    }

    return false;
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    // 建立映射关系
    for(vector<string> vec : tickets){
        fly_map[vec[0]][vec[1]]++;
    }
    vector<string> result;
    // 加入开始机场
    result.push_back("JFK");

    tarck(tickets.size(), result);

    return result;
}