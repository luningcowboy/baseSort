/*************************************************************************
 @Author: luning
 @Created Time : 五  3/20 21:56:19 2020
 @File Name: arr_p_3.c
 @Description:
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Table{
    int *head;
    int length;
    int size;
}table;
#define Size 5

table initTable(){
    // 1. 初始化table, 分配内存空间
    // 2. 检查内存分配是否成功
    // 3. 设置table length和size
    // 4. 返回table
    table t;
    t.head = (int *)malloc(Size * sizeof(int));
    if(!t.head){
        printf("分配内存失败\n");
        exit(0);
    }
    for(int i = 0; i < Size; i++){
        t.head[i] = i + 1;
        t.length++;
    }
    t.size = Size;
    return t;
}
table insertTable(table t, int elem, int pos){
    // 1. 检查插入位置是否有问题
    // 2. 检查是否需要重新分配内存，如果需要，重新分配内存
    // 3. 平移内存中的值，空出pos上的值
    // 4. 给pos上的元素赋值
    // 5. length增加

 
    return t;
}

table delTable(table t, int pos){
    // 1. 进行位置判断
    // 2. 找到制定位置，直接平移数组
    // 3. 修改数组长度
    return t;
}
int selectTable(table t, int elem){
    return -1;
}
table refreshTable(table t, int elem, int newElem){
    return t;
}
void displayTable(table t){
}
int main(){
    return 0;
}
