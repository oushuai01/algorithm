/*
 * @Author: oushuai 1768621963@qq.com
 * @Date: 2023-10-30 16:24:38
 * @LastEditors: oushuai 1768621963@qq.com
 * @LastEditTime: 2023-10-30 16:49:08
 * @FilePath: \algorithm\LiKou\随想录\hot100\链表\32_随机链表的复制.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <vector>
#include <iostream>
#include <unordered_map>
//10.30
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
//题解：https://leetcode.cn/problems/copy-list-with-random-pointer/solutions/2361362/138-fu-zhi-dai-sui-ji-zhi-zhen-de-lian-b-6jeo/

Node* copyRandomList(Node* head) {
    if(head == nullptr) return nullptr;
    Node* cur = head;
    unordered_map<Node*, Node*> umap;

    while(cur != nullptr){
        //复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
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
    //返回链表头节点
    return umap[head];
}