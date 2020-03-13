#include <stdio.h>
#include <stdlib.h>
typedef struct Table{
    int * head;
    int length;
    int size;
}table;
#define Size 5

table initArray(){
    table arr;
    arr.head = (int *)malloc(Size * sizeof(int));
    if(!arr.head){
        printf("initArray failed.");
        exit(0);
    }
    arr.length = 0;
    arr.size = Size;
    return arr;
}
void displayArray(table arr){
    for(int i = 0; i < arr.length; ++i){
        printf("%d ", arr.head[i]);
    }
    printf("\n");
}
int main(){
    table arr = initArray();
    for(int i = 0; i < 10; i++){
        arr.head[i] = (i + 1) * 10;
        arr.length++;
    }
    displayArray(arr);
    return 0;
}
