#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    int elem;
    struct Link *next;
}link;
link * initLink(){
    // 创建一个头节点，初始值为0
    link * p = (link*)malloc(sizeof(link));
    link * t = p;
    // 在创建4个节点, 分别为1,2,3,4
    for(int i = 1; i < 5; i++){
        link * a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        t->next = a;
        printf("initLink:%d\n", i);

        t = a;
    }
    return p;
}
link * insertElem(link * p, int elem, int pos){
    link * t = p;
    // 找到目标位置的元素
    for(int i = 1; i < pos; i++){
        t = t->next;
        printf("insertElem: %d\n", t->elem);
        if(t == NULL){
            printf("insertElem failed\n");
            return p;
        }
    }
    // 插入操作
    link * a = (link*)malloc(sizeof(link));
    a->elem = elem;
    a->next = t->next;
    t->next = a;
    return p;
}
link * delElem(link * p, int pos){
    link * t = p;
    for(int i = 1; i < pos; i++){
        t = t->next;
        if(t->next == NULL){
            printf("delElem: failed");
            return p;
        }
    }
    link * del = t->next;
    t->next = del->next;
    free(del);
    return p;
}
int selectElem(link *p, int elem){
    link * t = p;
    int i = 1;
    while(t->next){
        t = t->next;
        if(t->elem == elem){
            return i;
        }
        i++;
    }
    return -1;
}
link * refreshElem(link * p, int newElem, int pos){
    link * t = p;
    t = t->next;
    for(int i = 1; i < pos; i++){
        t = t->next;
        if(t == NULL){
            printf("没有找到指定元素\n");
            return p;
        }
    }
    t->elem = newElem;
    return p;
}
void display(link * p){
    printf("display:\n");
    link * t = p->next;
    while(t){
        printf("%d ", t->elem);
        t = t->next;
    }
    printf("\n");
}
int main(){
    link * p = initLink();
    display(p);

    printf("在第三个位置插入10:\n");
    p = insertElem(p, 10, 3);
    display(p);

    printf("删除第2哥位置第元素:\n");
    p = delElem(p, 2);
    display(p);

    printf("查找3的位置:\n");
    int add = selectElem(p, 3);
    printf("%d\n", add);

    printf("设置第一个元素为8:\n");
    p = refreshElem(p, 8, 1);
    display(p);
    return 0;
}
