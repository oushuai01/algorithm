#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL) return head;
    // 删除头节点
    while(head != NULL && head->val == val){
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
    ListNode* cur = head;
    // 删除非头节点
    while(cur != NULL && cur->next != NULL){
        if(cur->next->val == val){
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else{
            cur = cur->next;
        }
    }
    return head;

}
int main(){


    return 0;
}