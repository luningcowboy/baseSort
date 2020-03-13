#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
typedef struct Table{
    int * head;
    int length;
    int size;
}table;

table initTable(){
    table t;
    t.head = (int *)malloc(SIZE*sizeof(int));
    if (!t.head){
        printf("initTable failed");
        exit(0);
    }
    t.length = 0;
    t.size = SIZE;
    return t;
}
table addTable(table t, int elem, int add){
    if(add > t.length + 1 || add < 1){
        printf("addTable error 1");
        return t;
    }
    if(t.length >= t.size){
        t.head = (int *)realloc(t.head, (t.size + 1)*sizeof(int));
        if(!t.head){
            printf("addTable error 2");
        }
        t.size += 1;
    }
    for(int i = t.length - 1; i >= add - 1; i--){
        t.head[i + 1] = t.head[i];
    }
    t.head[add-1] = elem;
    t.length++;
    return t;
}
table delTable(table t, int add){
    if (add > t.length || add < 1){
        printf("delTable: 被删除的元素位置有误");
        exit(0);
    }
    for(int i = add; i < t.length; i++){
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
table amendTable(table t, int elem, int newElem){
    int add = selectTable(t, elem);
    if(add != -1){
        t.head[add - 1] = newElem;
    }
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
    for(int i = 1; i < SIZE; i++){
        t.head[i - 1] = i;
        t.length++;
    }
    displayTable(t);

    t = delTable(t, 1);
    displayTable(t);

    t = addTable(t, 5, 2);
    displayTable(t);

    int add = selectTable(t, 3);
    printf("%d", add);

    t = amendTable(t, 3, 6);
    displayTable(t);
    return 0;
}
