#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
// fast指针一次走两步  slow指针一次走一步  他们会在环内相遇
// 相遇后   再设置 相遇点 和 head 一起走   相遇点就是环的入口
ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){   //环内相遇
            ListNode* index1 = slow;
            ListNode* index2 = head;
            while(index1 != index2){  //找到环入口
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;

        }

    }
    return NULL;
}
int main(){


    return 0;
}


