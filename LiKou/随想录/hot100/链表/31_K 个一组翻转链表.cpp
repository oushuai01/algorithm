/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-27 10:18:47
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-27 11:25:25
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\31_K 个一组翻转链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <vector>
#include <iostream>
//10.27
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//反转链表
ListNode* reverse(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;

    while(cur != nullptr){
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    return pre;
}

//题解
//https://leetcode.cn/problems/reverse-nodes-in-k-group/solutions/10416/tu-jie-kge-yi-zu-fan-zhuan-lian-biao-by-user7208t/
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* result = new ListNode(0);
    result->next = head;
    ListNode* pre = result;
    ListNode* end = result;
    while(end->next != nullptr){
        for(int i = 0; i < k && end != nullptr; i++){
            end = end->next;
        }
        if(end == nullptr)
        break;

        //记录开始反转的头节点 和下一次开始反转的头节点
        ListNode* start = pre->next;
        ListNode* next = end->next;
        //将end 指向 null
        end->next = nullptr;
        //反转
        pre->next = reverse(start);
        //将反转的末尾与这段开头连接  start 此时已经到末尾了
        //如果后面的链表长度小于k 就是原顺序
        start->next = next;

        //更新下一次反转的开头
        pre = start;
        end = start;
    } 

    return result->next;  
}

//用栈也能实现   最后不满足k的不用入栈


