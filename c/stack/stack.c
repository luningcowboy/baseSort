#include <stdio.h>
#include <stdlib.h>

#define Size 5
typedef struct Item{
    int data;
    struct Item * next;
}item;

item * initStack(){
    item * p = (item*)malloc(sizeof(item));
    item * t = p;
    for(int i = 0; i < Size; i++){
        item * a = (item*)malloc(sizeof(item));
        t->next = a;
        a->next = NULL;
        a->data = i + 1;
        t = a;
    }
    return p;
}
item * push(item * p, int data){
    item * t = p;
    while(t){
        if(t->next == NULL){
            item * last = t;
            item * a = (item*)malloc(sizeof(item));
            last->next = a;
            a->data = data;
            a->next = NULL;
            break;
        }
        t = t->next;
    }
    return p;
}
item * pop(item * p){
    item * t = p;
    while(t){
        if(t->next->next == NULL){
            item * del = t->next->next;
            free(del);
            t->next = NULL;
            break;
        }
        t = t->next;
    }
    return p;
}
void display(item *p){
    item * t = p;
    t = p->next;
    while(t){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main(){
    item * p = initStack();
    display(p);

    p = push(p, 10);
    display(p);

    p = pop(p);
    display(p);
    return 0;
}
