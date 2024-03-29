/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-21 14:29:05
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-22 14:09:28
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\21_排序链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

static bool cmp(pair<int, ListNode*>& a, pair<int, ListNode>& b){
    return a.first < b.first;
}

ListNode* sortList(ListNode* head){
    if(head == nullptr) return nullptr;
    vector<pair<int, ListNode*>> vec;

    ListNode* cur = head;

    // 将数据插入到 vector
    while(cur){
        pair<int, ListNode*> temp(cur->val, cur);
        vec.push_back(temp);
        cur = cur->next;
    }

    sort(vec.begin(), vec.end(), cmp);

    // 将 vector 数据拿出来
    ListNode* result = new ListNode(-1);
    cur = result;
    for(int i = 0; i < vec.size(); i++){
        cur->next = vec[i].second;
        cur = cur->next;
    }

    cur->next = nullptr;
    return result->next;
}