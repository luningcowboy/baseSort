/*************************************************************************
 @Author: luning
 @Created Time : 一  3/16 12:49:29 2020
 @File Name: cp_0.c
 @Description:
 ************************************************************************/

#include <stdio.h>
#define maxSize 6
typedef struct Comopnent{
    int data;
    int cur;
}cmp;

void reserveArr(cmp * arr);
int initArr(cmp * arr);
void displayArr(cmp * arr, int body);
int mallocArr(cmp * arr);

int main(){
    cmp arr[maxSize];
    int body = initArr(arr);
    displayArr(arr, body);
    return 0;
}

// 创建备用链表
void reserveArr(cmp * arr){
    for(int i = 0; i < maxSize; i++){
        arr[i].cur = i + 1;
        arr[i].data = -1;
    }
    arr[maxSize-1].cur = 0;
}
// 提取分配空间
int mallocArr(cmp * arr){
    int i = arr[0].cur;
    if(arr[0].cur){
        arr[0].cur = arr[i].cur;
    }
    return i;
}
int initArr(cmp * arr){
    reserveArr(arr);
    int body = mallocArr(arr);
    int tmpbody = body;
    for(int i = 1; i < 4; i++){
        int j = mallocArr(arr);
        arr[tmpbody].cur = j;
        arr[j].data = i;
        tmpbody = j;
    }
    arr[tmpbody].cur = 0;
    return body;
}
void displayArr(cmp * arr, int body){
    int tmp = body;
    while(arr[tmp].cur){
        printf("%d, %d ", arr[tmp].data, arr[tmp].cur);
        tmp = arr[tmp].cur;
    }
    printf("%d, %d \n", arr[tmp].data, arr[tmp].cur);
}
