#include <stdio.h>
#include <stdlib.h>

#define Size 5
typedef struct Item {
    int data;
    struct Item* next;
    struct Item* entry;
} item;

item* initStack()
{
    item* p = (item*)malloc(sizeof(item));
    item* t = p;
    for (int i = 0; i < Size; i++) {
        item* a = (item*)malloc(sizeof(item));
        t->next = a;
        a->next = NULL;
        a->data = i + 1;
        a->entry = NULL;
        t = a;
    }
    p->entry = t;
    return p;
}
item* push(item* p, int data)
{
    item* t = p;
    item* entry = p->entry;
    item* a = (item*)malloc(sizeof(item));
    a->next = NULL;
    a->entry = NULL;
    a->data = data;
    entry->next = a;
    p->entry = a;
    return p;
}
item* pop(item* p)
{
    item* t = p;
    item* before = NULL;
    while (t->next) {
        before = t;
        t = t->next;
    }
    if (before) {
        before->next = NULL;
        free(t);
        p->entry = before;
    }
    else{
        printf("这是个空表\n");
    }
    return p;
}
void display(item* p)
{
    item* t = p;
    t = p->next;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    item* p = initStack();
    display(p);

    p = push(p, 10);
    display(p);

    p = pop(p);
    display(p);
    return 0;
}
