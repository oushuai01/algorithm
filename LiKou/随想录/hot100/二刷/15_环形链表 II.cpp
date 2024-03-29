/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-12 10:43:48
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-12 11:01:23
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\15_环形链表 II.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ListNode *detectCycle(ListNode *head) {
    if(head == nullptr) return nullptr;

    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            ListNode* index1 = slow;
            ListNode* index2 = head;

            while(index1 != index2){
                index1 = index1->next;
                index2 = index2->next;
            }

            return index1;
        }
    }

    return nullptr;


}
