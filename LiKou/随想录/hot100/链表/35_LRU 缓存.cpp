#include <iostream>
#include <unordered_map>
using namespace std;

//链表结构
class ListNode_{
    public:
        ListNode_(int x, int y) {
            this->key = x;
            this->val = y;
            this->prev = nullptr;
            this->next = nullptr;
        }
    public:
        int key, val;
        ListNode_* next, *prev;  
};

//双链表
class DoubleList{
    private:
        //头尾节点
        ListNode_* head, *tail;
         //长度
        int size;

    public:
        DoubleList(){
            this->head = new ListNode_(0,0);
            this->tail = new ListNode_(0,0);
            this->head->next = this->tail;
            this->tail->prev = this->head;
            this->size = 0;
        }

        //在链表头部添加节点x
        void addLast(ListNode_* node){
            node->prev = this->head;
            node->next = this->head->next;

            this->head->next->prev = node;
            this->head->next = node;

            this->size++;
        }

        //删除链表中的节点 (该节点一定存在)
        void remove(ListNode_* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
            this->size--;
        }

        //删除链表最后一个节点
        ListNode_* removeBack(){
            if(this->tail->prev == head)
                return nullptr;

            ListNode_* node = this->tail->prev;
            remove(node);

            return node;
        }

        int getSize(){
            return this->size;
        }

};




class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->cache = new DoubleList();
    }
    
    int get(int key) {
        if(this->map[key] == nullptr)
        return -1;

        makeRecently(key);
        ListNode_* node = this->map[key];

        return node->val;
    }
    
    void put(int key, int value) {
        //如果此前元素存在  则先删除 再添加
        if(this->map[key] != nullptr){
            //删除旧数据
            deletKey(key);
            //添加一个元素
            addRecently(key, value);

            return;
        }

        //添加一个元素
        addRecently(key, value);

        //如果超过cap 则删除最后一个
        if(this->cache->getSize() > this->cap)
        deletBack();
    }

    private:
        //将某个元素提升到最近使用
        void makeRecently(int key){
            //从map中得到node
            ListNode_* node = this->map[key];
            //移除node
            this->cache->remove(node);
            //添加到最前面
            this->cache->addLast(node);
        }

        //添加一个使用的元素
        void addRecently(int key, int val){
            ListNode_* node = new ListNode_(key, val);
            //添加到链表头部
            this->cache->addLast(node);
            //将key node 添加到 map
            this->map[key] = node;
        }

        //删除某个key
        void deletKey(int key){
            ListNode_* node = this->map[key];
            //删除链表
            this->cache->remove(node);
            //删除map
            this->map.erase(key);
        }

        //删除最后一个元素
        void deletBack(){
            //删除链表
            ListNode_* node = this->cache->removeBack();
            //删除node
            this->map.erase(node->key);
        }


    private:
        unordered_map<int, ListNode_*> map;
        DoubleList* cache;
        int cap;
};