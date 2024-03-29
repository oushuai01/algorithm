#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int headA_size = 0;
    int headB_size = 0;


    ListNode* temp_A = headA;
    while(temp_A){
        headA_size++;
        temp_A = temp_A->next;
    }


    ListNode* temp_B = headB;
    while(temp_B){
        headB_size++;
        temp_B = temp_B->next;
    }


    if(headA_size < headB_size)
    swap(headA, headB);


    int count = abs(headA_size - headB_size);

    while(count){
        headA = headA->next;
        count--;
    }

    while(headA){
        if(headA == headB)
        return headA;

        headA = headA->next;
        headB = headB->next;
    }

    return nullptr;
}