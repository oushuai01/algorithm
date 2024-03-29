/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2024-03-19 17:33:04
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2024-03-19 20:55:22
 * @FilePath: \algorithm\LiKou\随想录\hot100\二刷\20_随机链表的复制.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

 Node* copyRandomList(Node* head) {
    if(head == nullptr) return nullptr;

    unordered_map<Node*, Node*> umap;
    Node* cur = head;
    //复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
    while(cur != nullptr){
        umap[cur] = new Node(cur->val);
        cur = cur->next;
    }

    cur = head;
    //构建新链表的next 和 random指向
    while(cur != nullptr){
        umap[cur]->next = umap[cur->next];
        umap[cur]->random = umap[cur->random];
        cur = cur->next;
    }

    return umap[head];
 }


