/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-24 10:43:31
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-24 10:58:12
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\23_反转链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <vector>
#include <iostream>
//10.24
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//双指针
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



//使用这种写法 一定要判断head 是否为nullptr
//否则 ListNode* back_ = head->next; 会报错
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    if(head == nullptr) return nullptr;
    ListNode* pre = head;
    ListNode* back_ = head->next;
    head->next = nullptr;

    while(back_){
        ListNode* temp = back_->next;
        back_->next = pre;
        pre = back_;
        back_ = temp;
    }

    return pre;
    }
};