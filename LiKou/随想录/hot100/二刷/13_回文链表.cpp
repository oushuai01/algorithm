/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-12 10:07:01
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-12 10:31:11
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\13_回文链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


bool isPalindrome(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* cur = nullptr;


    // 反转前半部分
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;

        ListNode* temp = slow->next;
        slow->next = cur;
        cur = slow;
        slow = temp;
    }

    // 此时 cur 作为前半链表的头节点
    // slow 作为后半链表的头节点
    // 如果 fast != nullptr 说明链表长度为奇数  多出来的单独节点不需要比较
    if(fast != nullptr){
        slow = slow->next;
    }

    while(slow != nullptr){
        if(slow->val != cur->val)
        return false;

        slow = slow->next;
        cur = cur->next;
    }

    return true;

}

