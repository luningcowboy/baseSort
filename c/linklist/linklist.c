#include <stdio.h>
#include <stdlib.h>
// 声明节点
typedef struct Link {
    int elem;          // 存储整型元素
    struct Link* next; // 指向直接后继元素的指针
} link;

link* initLink();
void display(link* p);
link* insertElem(link* p, int elem, int pos);
link* delElem(link* p, int pos);
int selectElem(link* p, int elem);
link* amendElem(link* p, int pos, int newElem);

int main()
{
    printf("初始化链表:\n");
    link* p = initLink();
    display(p);

    printf("在第四个位置插入元素5:\n");
    p = insertElem(p, 5, 4);
    display(p);

    printf("删除元素3:\n");
    p = delElem(p, 3);
    display(p);

    printf("查找元素2的位置为:\n");
    int address = selectElem(p, 2);
    if(address == -1){
        printf("没有找到元素2\n");
    }
    else{
        printf("元素2的位置为:%d\n", address);
    }

    printf("修改元素3位置上的数据为7:\n");
    p = amendElem(p, 3, 7);
    display(p);
    return 0;
}

link* initLink()
{
    link* p = (link*)malloc(sizeof(link));
    link* tmp = p;
    for (int i = 1; i < 5; i++) {
        link *a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        tmp->next = a;
        tmp = tmp->next;
    }
    return p;
}
link* insertElem(link* p, int elem, int pos)
{
    link* tmp = p;
    for (int i = 1; i < pos; i++) {
        tmp = tmp->next;
        if (tmp == NULL) {
            printf("insertElem Err: 插入位置无效\n");
            return p;
        }
    }
    link* c = (link*)malloc(sizeof(link));
    c->elem = elem;
    c->next = tmp->next;
    tmp->next = c;
    return p;
}
link* delElem(link* p, int pos)
{
    link* tmp = p;
    for (int i = 1; i < pos; i++) {
        tmp = tmp->next;
        if (tmp->next == NULL) {
            printf("delElem Err: 删除位置无效\n");
            return p;
        }
    }
    link* del = tmp->next;
    tmp->next = del->next;
    free(del);
    return p;
}
int selectElem(link* p, int elem)
{
    link* t = p;
    int i = 1;
    while (t->next) {
        t = t->next;
        if (t->elem == elem) {
            return i;
        }
        i++;
    }
    return -1;
}
link* amendElem(link* p, int pos, int newElem)
{
    link* t = p;
    t = t->next;
    for(int i = 1; i < pos; i++){
        t = t->next;
    }
    t->elem = newElem;
    return p;
}
void display(link* p)
{
    link* temp = p;
    while (temp) {
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}
