/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-12 11:08:05
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-12 11:14:23
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\16_合并两个有序链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr && list2 == nullptr) return nullptr;
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;


    ListNode* head = new ListNode(0);
    ListNode* cur = head;

    while(list1 != nullptr && list2 != nullptr){
        if(list1->val <= list2->val){
            cur->next = list1;
            list1 = list1->next;
        }
        else{
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }

    cur->next = list1 != nullptr ? list1 : list2;


    return head->next;

    
}
