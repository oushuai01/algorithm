/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-11-02 15:04:47
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-11-02 15:48:48
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\34_合并 K 个升序链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
//10.02

using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    // 优先队列能解决问题
    // greater 排序后数组是从大到小  用的是小顶堆才能实现此排序  所以优先队列每次弹出的都是最小的 也就是升序
    // less 则相反
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> test;
    for(auto list : lists){
        if(list != nullptr)
        test.push(make_pair(list->val, list));
    }
    ListNode* result = new ListNode(0);
    ListNode* cur = result;

    while(!test.empty()){
        //拿到最小值的节点
        ListNode* temp = test.top().second;
        //出队
        test.pop();
        //指向最小节点
        cur->next = temp;

        //将该节点 下一个节点入队
        if(temp->next != nullptr){
            pair<int, ListNode*> newPair = make_pair(temp->next->val, temp->next);
            test.push(newPair);
        }

        cur = cur->next;
    }

    return result->next;

}