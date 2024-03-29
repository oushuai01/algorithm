/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-26 11:25:19
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-26 11:35:05
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\30_两两交换链表中的节点.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <vector>
#include <iostream>
//10.26
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
        //保留 下1个节点  和  第3个节点
        ListNode* temp1 = cur->next;
        ListNode* temp2 = cur->next->next->next;

        cur->next = cur->next->next;    //1
        cur->next->next = temp1;        //2
        temp1->next = temp2;            //3

        cur = cur->next->next;
    }

    return result->next;
}
