#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* my_str(char* str1, char* str2){

    if(strlen(str1) < strlen(str2)){
        printf("0\n");
        return NULL;
    }


    char* temp = str2;
    int count = 0;
    char* prestr1 = NULL;
    

    while(*str1){
        if(*str1 != *str2){
            str2 = temp;
        }
        else{
            //printf("%c ", *str1);
            str2++;
            str1++;
        }

        if(*str2 == '\0'){
            count++;
            prestr1 = (str1 - 3);
            //rintf("\n%c %d\n", *prestr1, count);
            str2 = temp;
        }
    }

    printf("\n%d", count);

    return prestr1;

}

int main(){

    char* str1 = "abcabca";
    char* str2 = "abc";

    printf("\n%c", *my_str(str1, str2));
}