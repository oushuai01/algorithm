#include <iostream>
using namespace std;
class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int val_):val(val_),next(nullptr){}
    };

    MyLinkedList() {
        FakeHead = new ListNode(0);
        size_ = 0;
    }
    
    int get(int index) {
        if(index > (size_ - 1) || index < 0){
            return -1;
        }
        ListNode* cur = FakeHead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* preHead = FakeHead->next;
        ListNode* addHead = new ListNode(val);
        FakeHead->next = addHead;
        addHead->next = preHead;
        size_++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = FakeHead;
        ListNode* addTail = new ListNode(val);
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = addTail;
        size_++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size_)return;
        if(index <= 0) {
            addAtHead(val);
            return;
        }
        if(index == size_) {
            addAtTail(val);
            return;
        }
        ListNode* addIndex = new ListNode(val);
        ListNode* cur = FakeHead;
        while(index--){
            cur = cur->next;
        }
        addIndex->next = cur->next;
        cur->next = addIndex;
        size_++;


    }
    
    void deleteAtIndex(int index) {
        // index 不能等于 size_
        if(index < 0 || index >= size_ || size_ == 0) return;
        ListNode* pre = FakeHead;
        ListNode* cur = FakeHead->next;
        while(index--){
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
        cur = nullptr;
        size_--;
    }
private:
    ListNode* FakeHead;
    int size_;
};

int main(){


    return 0;
}