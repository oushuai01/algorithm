/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-11 20:08:03
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-11 20:12:59
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\12_反转链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseList(ListNode* head) {
    if(head == nullptr) return nullptr;

    ListNode* pre = nullptr;
    ListNode* cur = head;

    while(cur != nullptr){
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    return pre;
}
