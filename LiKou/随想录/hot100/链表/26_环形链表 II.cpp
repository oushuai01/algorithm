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
//相遇之后 头节点 到环入口的距离和 slow节点 到环入口的距离相等
ListNode *detectCycle(ListNode *head) {
    if(head == nullptr) return nullptr;

    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
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