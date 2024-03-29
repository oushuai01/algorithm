#include <vector>
#include <iostream>
//10.26
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* result = new ListNode(0);
    result->next = head;

    ListNode* fast = head;
    ListNode* slow = head;

    while(n--){ //先让 fast 走 n 步
        fast = fast->next;
    }

    if(fast == nullptr){   //如果fast == nullptr 说明到了最后节点  那么要删除头节点
        result->next = head->next;
        delete head;
        return result->next;
    }

    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }

    //删除slow后面的节点
    slow->next = slow->next->next;
    return result->next;
}