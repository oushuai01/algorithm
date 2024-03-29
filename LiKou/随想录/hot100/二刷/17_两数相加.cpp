/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-14 20:34:42
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-14 20:48:04
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\17_两数相加.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode(0);
    ListNode* cur = res;
    int pre = 0;

    while(l1 != nullptr || l2 != nullptr){
        int x = l1 == nullptr ? 0 : l1->val;
        int y = l2 == nullptr ? 0 : l2->val;

        int sum = x + y + pre;

        pre = sum / 10;
        sum = sum % 10;

        ListNode* temp = new ListNode(sum);
        cur->next = temp;
        cur = cur->next;

        if(l1 != nullptr){
            l1 = l1->next;
        }

        if(l2 != nullptr){
            l2 = l2->next;
        }

    }

    if(pre != 0){
        ListNode* temp = new ListNode(pre);
        cur->next = temp;
    }

    return res->next;
}