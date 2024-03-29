/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-24 10:21:53
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-24 10:38:19
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\22_相交链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <vector>
#include <iostream>
using namespace std;
//10.24
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* tempA = headA;
    ListNode* tempB = headB;
    int countA = 0;
    int countB = 0;
    //找到最长的链表
    while(tempA != nullptr){
        countA ++;
        tempA = tempA->next;
    }
    while(tempB != nullptr){
        countB ++;
        tempB = tempB->next;
    }
    
    int size_ = abs(countA - countB);
    //保证 headA 是最长的
    if(countB > countA) swap(headA, headB);
    //最长的链表先走size步
    while(size_--){
        headA = headA->next;
    }

    while(headA != nullptr){
        if(headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return nullptr;

}


//更聪明的做法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        while (A != B) {
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }
        return A;
    }
};
//如果有交点   一定会相遇在交点
//如果没有交点  会相遇在最后
// A 链表 到交点的距离为 a - c
// B 链表 到交点的距离为 b - c

// A 链表 遍历完再遍历 B 链表  一共走的步数 a - c + b
// B 链表 遍历完再遍历 A 链表  一共走的步数 b - c + a
// 他们一定会相遇  相遇的就是交点  没有交点就是null