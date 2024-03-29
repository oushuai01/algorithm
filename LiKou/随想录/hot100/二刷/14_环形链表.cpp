#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


// 快指针一次走两步  慢指针一次走一步
// 如果有环他们必定相遇
// 相遇的节点不一定是相交节点
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