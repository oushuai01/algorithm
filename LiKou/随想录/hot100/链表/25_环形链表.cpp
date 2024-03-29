/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-25 10:36:10
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-25 10:45:38
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\25_环形链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <vector>
#include <iostream>
//10.25
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
//双指针判断有无环  有环一定会相遇
bool hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }

    return false;
}

