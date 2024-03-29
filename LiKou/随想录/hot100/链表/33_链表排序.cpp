#include <vector>
#include <iostream>
#include <algorithm>
//10.31
//用一下排序   这个空间消耗太大   有时间看一下排序


using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

bool cmp(pair<int, ListNode*>& a, pair<int, ListNode*>& b){
    return a.first < b.first;
}

vector<pair<int, ListNode*>> vec;

//用一下排序   这个空间消耗太大

ListNode* sortList(ListNode* head) {
    if(head == nullptr) return nullptr;

    ListNode* cur = head;
    while(cur){
        // pair<int,ListNode*> temp = make_pair(cur->val, cur->next);
        pair<int, ListNode*> temp(cur->val, cur);
        vec.push_back(temp);
        cur = cur->next;
    }

    sort(vec.begin(), vec.end(), cmp);

    ListNode* result = vec[0].second;
    cur = result;
    for(int i = 1; i < vec.size(); i++){
        cur->next = vec[i].second;
        cur = cur->next;
    }
    //最后一个值的next指针指向nullptr
    cur->next = nullptr;

    return result;
}