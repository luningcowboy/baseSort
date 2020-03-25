/*************************************************************************
 @Author: luning
 @Created Time : 三  3/25 14:39:57 2020
 @File Name: arr_cp_3.c
 @Description:
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct Table{
    int * head;
    int size;
    int length;
}table;
#define Size 5

table initTable(){
    table t;
    t.head = (int*)malloc(sizeof(int));
    if(!t.head){
        printf("initTable failed\n");
        exit(0);
    }
    t.size = Size;
    t.length = 0;
    return t;
}
table insertTable(table t, int elem, int pos){
    // 1. 检查插入位置是否有问题
    // 2. 检查是否需要重新分配内存，如果需要，重新分配内存
    // 3. 平移内存中的值，空出pos上的值
    // 4. 给pos上的元素赋值
    // 5. length增加
    if(pos < 1 || pos > t.length + 1){
        printf("插入位置有问题\n");
        return t;
    }
    if(t.length >= t.size){
        t.head = (int*)realloc(t.head, (t.size + 1) * sizeof(int));
        t.head = (int *)realloc(t.head, (t.size + 1)*sizeof(int));
        if(!t.head){
            printf("分配内存失败\n");
            return t;
        }
        t.size += 1;
    }
    for(int i = t.length - 1; i >= pos - 1; i--){
        t.head[i + 1] = t.head[i];
    }
    t.head[pos - 1] = elem;
    t.length += 1;
    return t;
}
table delTable(table t, int pos){
    // 1. 进行位置判断
    // 2. 找到制定位置，直接平移数组
    // 3. 修改数组长度
    if(pos < 1 || pos > t.length){
        printf("位置错误\n");
        return t;
    }
    for(int i = pos-1; i < t.length; i++){
        t.head[i] = t.head[i + 1];
    }
    t.length--;

    return t;
}
int selectTable(table t, int elem){
    int idx = -1;
    for(int i = 0; i < t.length; i++){
        if(t.head[i] == elem){
            idx = i + 1;
            break;
        }
    }
    return idx;
}
table rereshTable(table t, int elem, int newElem){
    int add = selectTable(t, elem);
    if(add == -1){
        printf("没找到指定元素\n");
    }
    else{
        t.head[add - 1] = newElem;
    }
    return t;
}
void display(table t){
    for(int i = 0; i < t.length; i++){
        printf("%d ", t.head[i]);
    }
    printf("\n");
}
int main(){
    table t = initTable();
    for(int i = 1; i <= 5; i++){
        t.head[i - 1] = i;
        t.length++;
    }
    display(t);
    t = insertTable(t, 6,2);
    display(t);
    t = delTable(t, 6);
    display(t);
    t = rereshTable(t, 3, 30);
    display(t);
    return 0;
}
