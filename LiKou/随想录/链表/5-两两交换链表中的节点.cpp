#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// 画图解决
ListNode* swapPairs(ListNode* head) {
    ListNode* FakeHead = new ListNode(0);
    FakeHead->next = head;
    ListNode* cur = FakeHead;
    while(cur->next != nullptr && cur->next->next != nullptr){
        ListNode* tmp = cur->next;
        ListNode* tmp1 = cur->next->next->next;

        cur->next = cur->next->next;  //1
        cur->next->next = tmp;        //2
        cur->next->next->next = tmp1; //3

        cur = cur->next->next;
    }

    return FakeHead->next;
}
int main(){


    return 0;
}