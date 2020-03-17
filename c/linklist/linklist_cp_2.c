/*************************************************************************
 @Author: luning
 @Created Time : 二  3/17 19:22:26 2020
 @File Name: linklist_cp_2.c
 @Description:
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct Link{
    int elem;
    struct Link * next;
}link;

link * initLink(){
    link * p = (link *)malloc(sizeof(link));
    link * t = p;
    for(int i = 0; i < 5; i++){
        link * a = (link *)malloc(sizeof(link));
        a->elem = i + 1;
        a->next = NULL;
        t->next = a;
        t = a;
    }
    return p;
}
link * insertLink(link * p, int elem, int pos){
    link * t = p;
    t = t->next;
    int i = 1;
    for(int i = 1; i < pos - 1; i++){
        if(!t){
            printf("没有找到指定位置\n");
            return p;
        }
        t = t->next;
    }
    link * a = (link*)malloc(sizeof(link));
    a->elem = elem;
    a->next = t->next;
    t->next = a;
    return p;
}
link * delLink(link * p, int pos){
    link * t = p;
    for(int i = 1; i < pos; i++){
        t = t->next;
        if(t->next == NULL){
            printf("没有找到指定位置\n");
        }
    }
    link * del = t->next;
    t->next = del->next;
    free(del);
    return p;
}

int selectLink(link * p, int elem){
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
link * refreshLink(link * p, int elem, int newElem){
    link * t = p;
    while(t->next){
        t = t->next;
        if(t->elem == elem){
            t->elem = newElem;
            break;
        }
    }
    return p;
}

link * refreshLink2(link * p, int pos, int newElem){
    link * t = p;
    for(int i = 1; i <= pos; i++){
        t = t->next;
        if(t == NULL){
            printf("没有找到指定元素\n");
        }
    }
    if(t) t->elem = newElem;
    return p;
}

void displayLink(link * p){
    link * t = p->next;
    while(t){
        printf("%d ", t->elem);
        t = t->next;
    }
    printf("\n");

}

int main(){
    link * p = initLink();
    displayLink(p);

    p = insertLink(p, 13, 3);
    displayLink(p);

    p = delLink(p, 3);
    displayLink(p);

    int addr = selectLink(p, 2);
    printf("2:%d \n", addr);
    
    p = refreshLink(p,2, 20);
    displayLink(p);

    p = refreshLink2(p, 3, 21);
    displayLink(p);

}
