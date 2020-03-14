/*************************************************************************
 @Author: luning
 @Created Time : 六  3/14 17:59:42 2020
 @File Name: linklist_cp_1.c
 @Description:
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct Link {
    int elem;
    struct Link* next;
} link;

link* initLink();
link* insertLink(link* p, int elem, int pos);
link* delLink(link* p, int pos);
int selectElem(link* p, int elem);
link* refreshLink(link* p, int elem, int pos);
void displayLink(link * p);

int main()
{
    printf("初始化链表:\n");
    link * p = initLink();
    displayLink(p);

    printf("在第四个位置插入5:\n");
    p = insertLink(p, 5, 4);
    displayLink(p);

    printf("删除第三个位置的元素:\n");
    p = delLink(p, 3);
    displayLink(p);

    printf("查找元素为2的位置:\n");
    int add = selectElem(p, 2);
    printf("add=%d\n", add);

    printf("修改第三个位置上的元素为7:\n");
    p = refreshLink(p, 7, 3);
    displayLink(p);



    return 0;
}

link* initLink()
{
    // 生成头节点,这里的头节点并不包含链表数据
    link* p = (link*)malloc(sizeof(link));
    link* t = p;
    // 生成链表
    for (int i = 1; i < 5; i++) {
        link* a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        t->next = a;
        t = a;
    }
    return p;
}

link* insertLink(link* p, int elem, int pos)
{
    link* t = p;
    for (int i = 1; i < pos; i++) {
        t = t->next;
        if (t == NULL) {
            printf("没有找到指定位置\n");
            return p;
        }
    }
    link * a = (link*)malloc(sizeof(link));
    a->elem = elem;
    a->next = t->next;
    t->next = a;
    return p;
}
link* delLink(link* p, int pos){
    link * t = p;
    for(int i = 1; i < pos; i++){
        t = t->next;
        if(t->next == NULL){
            printf("没有找到指定元素\n");
            return p;
        }
    }
    link * del = t->next;
    t->next = del->next;
    free(del);
    return p;
}

int selectElem(link* p, int elem){
    link * t = p;
    t = t->next;
    int pos = 1;
    while(t){
        if(t->elem == elem){
            return pos;
        }
        t = t->next;
        pos++;
    }
    return -1;
}
link* refreshLink(link* p, int elem, int pos){
    link * t = p;
    t = t->next;
    for(int i = 1; i < pos; i++){
        t = t->next;
    }
    if(t){
        t->elem = elem;
    }
    else{
        printf("refreshLink 没有找到指定元素\n");
    }
    return p;
}
void displayLink(link * p){
    link * t = p;
    t = t->next;
    while(t){
        printf("%d ", t->elem);
        t = t->next;
    }
    printf("\n");
}
