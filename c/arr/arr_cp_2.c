/*************************************************************************
 @Author: luning
 @Created Time : 二  3/17 18:47:16 2020
 @File Name: arr_cp_2.c
 @Description:
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
typedef struct Table{
    int * head;
    int size;
    int length;
}table;

table initTable(){
    // 1. 初始化table, 分配内存空间
    // 2. 检查内存分配是否成功
    // 3. 设置table length和size
    // 4. 返回table
    table t ;
    t.head = (int *)malloc(SIZE * sizeof(int));
    if(!t.head){
        printf("分配内存空间失败\n");
        exit(0);
    }
    t.size = SIZE;
    t.length = 0;
    return t;
}
table insertTable(table t, int elem, int pos){
    // 1. 检查插入位置是否有问题
    // 2. 检查是否需要重新分配内存，如果需要，重新分配内存
    // 3. 平移内存中的值，空出pos上的值
    // 4. 给pos上的元素赋值
    // 5. length增加
    //
    if(pos < 1 || pos > t.length + 1){
        printf("插入位置错误\n");
        return t;
    }
    if(t.length >= t.size){
        t.head = (int *)realloc(t.head, (t.size + 1)*sizeof(int));
        if(!t.head){
            printf("内存空间分配失败");
            return t;
        }
        t.size++;
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
        printf("删除位置错误\n");
        return t;
    }
    for(int i = pos - 1; i < t.length; i++){
        t.head[i] = t.head[i + 1];
    }
    t.length--;
    return t;
}
int selectTable(table t, int elem){
    for(int i = 0; i < t.length; i++){
        if(t.head[i] == elem) return i + 1;
    }
    return -1;
}
table refreshTable(table t, int elem, int newElem){
    int add = selectTable(t, elem);
    if(add == -1){
        printf("没有找到指定元素:%d \n", elem);
        return t;
    }
    t.head[add - 1] = newElem;
    return t;
}
void displayTable(table t){
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
    displayTable(t);

    t = insertTable(t, 6, 6);
    displayTable(t);

    t = delTable(t, 3);
    displayTable(t);

    int add = selectTable(t, 4);
    printf("address:%d \n", add);

    t = refreshTable(t, 5, 15);
    displayTable(t);
    return 0;
}
