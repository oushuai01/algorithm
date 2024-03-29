#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// ListNode* removeNthFromEnd(ListNode* head, int n) {
//     if(head == nullptr) return head;
//     int num = 0;
//     ListNode* tmp = head;
//     while(tmp != nullptr){
//         num++;
//         tmp = tmp->next;
//     }
//     int index_ = num - n;
//     ListNode* FakeNode = new ListNode(0);
//     ListNode* pre = FakeNode;
//     ListNode* cur = head;
//     pre->next = head;
//     while(index_--){
//         pre = pre->next;
//         cur = cur->next;
//     }
//     pre->next = cur->next;
//     delete cur;


//     return FakeNode->next;

    
// }

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == nullptr) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* slow = dummy;
    ListNode* fast = dummy;
    while(n--){
        fast = fast->next;
    }
    // fast 移动 n + 1 步
    fast = fast->next;
    while(fast != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* tmp = slow->next;
    slow->next = slow->next->next;
    ListNode* newHead = dummy->next;
    delete dummy;
    delete tmp;
    
    return newHead;
}
int main(){



    return 0;
}