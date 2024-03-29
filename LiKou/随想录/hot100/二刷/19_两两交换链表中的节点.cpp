/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-14 21:08:44
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-14 21:25:13
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\19_两两交换链表中的节点.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* result = new ListNode(0);
    result->next = head;

    ListNode* cur = result;

    while(cur->next != nullptr && cur->next->next != nullptr){
        // 保留 第一个和 第三个节点
        ListNode* temp1 = cur->next;
        ListNode* temp2 = cur->next->next->next;

        cur->next = cur->next->next;
        cur->next->next = temp1;
        temp1->next = temp2;

        cur = cur->next->next;
    }

    return result->next;
}