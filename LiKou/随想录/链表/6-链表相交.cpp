#include <iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// 求差值  再遍历看地址是否一样
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* curA = headA;
    ListNode* curB = headB;
    int lenA = 0;
    int lenB = 0;
    while(curA != NULL){  //求链表A的长度
        lenA++;
        curA = curA->next;
    }
    while(curB != NULL){  //求链表B的长度
        lenB++;
        curB = curB->next;
    }
    curA = headA;
    curB = headB;
    if(lenA < lenB){      //使得A是长的链表
        swap(lenA,lenB);
        swap(curA,curB);
    }
    int gap = lenA - lenB;   //求长度差值
    while(gap--){
        curA = curA->next;   //移动长链表到和短链表开头相同位置
    }

    while(curA != NULL){    // 一个一个对比
        if(curA == curB)
        return curA;
        curA = curA->next;
        curB = curB->next;
    }

    return NULL;
}


int main(){


    


return 0;
}