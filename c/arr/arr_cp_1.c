/*************************************************************************
 @Author: luning
 @Created Time : 六  3/14 17:33:43 2020
 @File Name: arr_cp_1.c
 @Description:
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define Size 5
typedef struct Table{
    int * head;
    int length;
    int size;
}table;

table initTable();
table insertTable(table t, int elem, int pos);
table delTable(table t, int pos);
int selectTable(table t, int elem);
table refreshTable(table t, int elem, int newElem);
void displayTable(table t);

int main(){
    table t = initTable();
    for(int i = 1; i < Size; i++){
        t.head[i - 1] = i;
        t.length++;
    }

    printf("原顺序表:\n");
    displayTable(t);

    printf("删除第一个元素:\n");
    t = delTable(t, 1);
    displayTable(t);

    printf("在第二个位置插入5:\n");
    t = insertTable(t, 5, 2);
    displayTable(t);

    printf("查找元素3的位置:\n");
    int pos = selectTable(t, 3);
    printf("3:%d\n", pos);

    printf("将元素3修改为6:\n");
    t = refreshTable(t, 3, 6);
    displayTable(t);

    return 0;
}

table initTable(){
    table t;
    t.head = (int *)malloc(Size * sizeof(int));
    if(!t.head){
        printf("initTable failed.\n");
        exit(0);
    }
    t.length = 0;
    t.size = Size;
    return t;
}
table insertTable(table t, int elem, int pos){
    // 检测是否能插入
    if(pos > t.length + 1 || pos < 1){
        printf("插入的位置有问题\n");
        return t;
    }
    // 重新分配内存
    if(t.length >= t.size){
        t.head = (int *)realloc(t.head, (t.size + 1)*sizeof(int));
        if(!t.head){
            printf("内存分配失败\n");
            return t;
        }
        t.size += 1;
    }
    // 内存搬移
    for(int i = t.length - 1; i >= pos-1; i--){
        t.head[i + 1] = t.head[i];
    }
    // 变量赋值
    t.head[pos - 1] = elem;
    t.length++;
    return t;
}

table delTable(table t, int pos){
    if(pos > t.length || pos < 1){
        printf("删除的位置有问题");
        return t;
    }
    for(int i = pos; i < t.length; i++){
        t.head[i - 1] = t.head[i];
    }
    t.length--;
    return t;
}

int selectTable(table t, int elem){
    for(int i = 0; i < t.length; i++){
        if(t.head[i] == elem){
            return i + 1;
        }
    }
    return -1;
}


table refreshTable(table t, int elem, int newElem){
    int pos = selectTable(t, elem);
    if(pos == -1){
        printf("没有找到指定元素\n");
        return t;
    }
    t.head[pos-1] = newElem;
    return t;
}

void displayTable(table t){
    for(int i = 0; i < t.length; i++){
        printf("%d ", t.head[i]);
    }
    printf("\n");
}
