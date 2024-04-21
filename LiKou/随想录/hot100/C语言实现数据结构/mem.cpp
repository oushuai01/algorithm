#include <iostream>
#include <unistd.h>
#include <cstring>
#define MEM_ONE_MB  (int)(1024 * 1024 * 1024)
#define MAX_SIZE 3


int main(){
    int* arr[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++){
        arr[i] = (int*)malloc(MEM_ONE_MB);
        std::cout << (i + 1) << "GB" << std::endl;
        //memset(arr[i], 0, MEM_ONE_MB);
        sleep(1);
    }

    for(int i = 0; i < MAX_SIZE; i++){
        free(arr[i]);
        std::cout << (i + 1) << "GB" << std::endl;
        //sleep(5000);
    }




}