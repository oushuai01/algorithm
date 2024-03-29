#include <vector>
#include <iostream>
//10.26
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
    while(l1 != nullptr && l2 != nullptr){
        //判断是否超过 10
        int num = l1->val + l2->val + pre;
        if(num / 10 != 0){
            pre = 1;
            num %= 10;
        }else{
            pre = 0;
        }
        ListNode* temp = new ListNode(num);
        cur->next = temp;
        cur = cur->next;
        l1 = l1->next;
        l2 = l2->next;
    }


    //当l1 链表为空
    if(l1 == nullptr){
        //cur 指向 l2
        cur->next = l2;
        while(l2 != nullptr){
            //更新之前留下来的pre  进位  没有进位直接break;
            if(pre == 0)
            break;

            //更新进位
            int sum = l2->val + pre;
            if(sum / 10 != 0){
                pre = 1;
                sum %= 10;
                l2->val = sum;

            }else{
                pre = 0;
                l2->val = sum;
            }
            cur = l2;
            l2 = l2->next;
        }
        if(pre == 1){
            cur->next = new ListNode(1);
        }
    }
    //当l2 链表为空
     if(l2 == nullptr){
        cur->next = l1;
        while(l1 != nullptr){
            //更新之前留下来的pre  进位  没有进位直接break;
            if(pre == 0)
            break;

            //更新进位
            int sum = l1->val + pre;
            if(sum / 10 != 0){
                pre = 1;
                sum %= 10;
                l1->val = sum;

            }else{
                pre = 0;
                l1->val = sum;
            }

            cur = l1;
            l1 = l1->next;
        }
        if(pre == 1){
            ListNode* temp = new ListNode(1);
            cur->next = temp;
        }
    }


    return res->next;
}


//简洁写法
ListNode* addTwoNumbers_(ListNode* l1, ListNode* l2){
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
    if(pre == 1){
        cur->next = new ListNode(pre);
    }

    return res->next;
}