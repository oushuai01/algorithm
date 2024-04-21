#include <iostream>
#include <cstring>

typedef struct queue {
    int* arr;
    int head;
    int tail;
    int lenght;
    int maxsize;
}queue;

// 创建一个环形队列 传入 size
// 是否满
// 是否为空
// 插入
// 删除

/**
 * @brief 创建一个环形链表
 * @param size 最大容量
 * @return 成功：返回queue地址  失败：nullptr
 * @author os
 */
queue* CreatQueue(int size){
    if(size <= 0) return nullptr;

    queue* result = (queue*)malloc(sizeof(queue));
    if(result == nullptr) return nullptr;
    result->head = 0;
    result->tail = 0;
    result->lenght = 0;
    result->maxsize = size;
    result->arr = (int*)malloc(sizeof(int) * size);

    if(result->arr == nullptr) return nullptr;
    return result;
}

/**
 * @brief 环形链表判断是否为空
 * @param queue_ 环形链表地址
 * @return 空：true  不空：false
 * @author os
 */
bool empty(queue* queue_){
    if(queue_->lenght == 0) return true;

    return false;
}

/**
 * @brief 环形链表判断是否满
 * @param queue_ 环形链表地址
 * @return 满：true  不满：false
 * @author os
 */
bool full(queue* queue_){
    if(queue_->lenght == queue_->maxsize) return true;

    return false;
}

/**
 * @brief 环形链表插入函数
 * @param queue_ 环形链表地址 num 插入的值
 * @return 成功：0  失败：-1
 * @author os
 */
int push(queue* queue_, int num){
    if(full(queue_)) {  // 满了自动扩容
        // 将原来的数据存储下来 并记录之前的head
        int* temp = queue_->arr;
        int  pre_head = queue_->head;
        int  pre_maxsize = queue_->maxsize;

        // 申请两倍大小的内存
        queue_->arr = (int*)malloc(sizeof(int) * queue_->maxsize * 2);
        if(queue_->arr == nullptr) return -1;

        // 将数组全部置0
        memset(queue_->arr, 0, sizeof(int) * queue_->maxsize * 2);

        // 将最大大小设置为 maxsize * 2
        // 同时对 head 和 tail 进行复位操作
        queue_->maxsize *= 2;
        queue_->head = 0;
        queue_->tail = 0;

        // 将原来有用的数据复制进来  通过 head 和 lenght 来复制存储
        for(int i = 0; i < queue_->lenght; i++){
            queue_->arr[queue_->tail] = temp[(pre_head + i) % pre_maxsize];
            queue_->tail = (queue_->tail + 1) % queue_->maxsize;
        }

        // 释放掉原数组内存
        free(temp);

        // 将需要插入的数据进行插入
        queue_->arr[queue_->tail] = num;
        queue_->tail = (queue_->tail + 1) % queue_->maxsize;
        queue_->lenght++;

        return 0;
    }

    queue_->arr[queue_->tail] = num;
    queue_->tail = (queue_->tail + 1) % queue_->maxsize;
    queue_->lenght++;

    return 0;
}

/**
 * @brief 环形链表删除函数
 * @param queue_ 环形链表地址
 * @return 成功：0  失败：-1
 * @author os
 */
int pop(queue* queue_){
    if(empty(queue_)) return -1;

    queue_->head = (queue_->head + 1) % queue_->maxsize;
    queue_->lenght--;

    return 0;
}


/**
 * @brief 打印环形队列
 * @param queue_ 环形链表地址
 * @author os
 */
void print_queue(queue* queue_){
    std::cout << "maxsize: " << queue_->maxsize << "   lenght: " << queue_->lenght << std::endl;
    for(int i = 0; i < queue_->lenght; i++){
        std::cout << queue_->arr[(queue_->head + i) % queue_->maxsize];
    }

    std::cout << std::endl;
}


int main(){
    int maxsize = 3;
    queue* que = CreatQueue(maxsize);
    push(que, 1);
    push(que, 2);
    push(que, 3);
    print_queue(que);
    push(que, 4);
    pop(que);
    pop(que);
    print_queue(que);
    push(que, 5);
    push(que, 6);
    push(que, 7);
    push(que, 8);
    push(que, 9);
    print_queue(que);

    free(que->arr);
    free(que);
}