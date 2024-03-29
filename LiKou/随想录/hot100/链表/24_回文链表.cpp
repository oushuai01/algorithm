#include <vector>
#include <iostream>
//10.24
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//将链表放到数组进行比较   这个耗费时间较长O(n)   且要开辟一个数组
bool isPalindrome(ListNode* head) {
    if(head == nullptr) return false;
    vector<int> vec;
    while(head != nullptr){
        vec.push_back(head->val);
        head = head->next;
    }

    for(int i = 0, j = vec.size() - 1; i < j; i++, j--){
        if(vec[i] != vec[j])
        return false;
    }

    return true;
}

/*
找到前半部分链表的尾节点。
反转前半部分链表。
判断是否回文。
返回结果。
*/

//快慢指针
bool isPalindrome_(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* cur = nullptr;

    //翻转前半部分链表
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        ListNode* temp = slow->next;
        slow->next = cur;
        cur = slow;
        slow = temp;
    }
    //此时 cur   作为前半链表的头节点
    //     slow  作为后半链表的头节点
    //如果fast != nullptr 说明链表长度为奇数  多出来的单独节点不需要比较
    if(fast != nullptr){
        slow = slow->next;
    }

    while(slow != nullptr){
        if(slow->val != cur->val)
        return false;
        slow = slow->next;
        cur = cur->next;
    }

    return true;




}