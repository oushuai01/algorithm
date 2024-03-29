#include <iostream>
using namespace std;

// 未完
class Node{
    public:
        Node(int key_, int value_){
            key = key_;
            value = value_;
            next = nullptr;
            pre = nullptr;
        }
    public:
        int key;
        int value;
        Node* next;
        Node* pre;
};


class ListNode{
    public:
        ListNode(int size_){
            head = new Node(-1, -1);
            back = new Node(-1, -1);
            head->next = back;
            back->pre = head;
            size = size_;
        }
        // 移除尾部
        void removeBack(){
            // 有元素则移除
            if(back->pre != head){
                Node* temp = back->pre;
                back->pre = back->pre->pre;
                back->pre->pre->next = back;

                delete temp;
            }
        }

        // 添加到头部
        void add(int key_, int value_){
            // 元素未满
            if(size > 0){
                Node* cur = new Node(key_, value_);
                Node* temp = head->next->next;
                head->next = cur;
                cur->pre = head;
                cur->next = temp;
                size--;
            }
            else{

            }

        }

    public:
        Node* head;
        Node* back;
        int size;

};


class LRUCache {
public:
    LRUCache(int capacity) {
        listnode = new ListNode(capacity);
    }
    
    int get(int key) {

    }
    
    void put(int key, int value) {

    }
public:
    ListNode* listnode;
};