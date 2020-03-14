#include <stdio.h>
#define maxSize 6

typedef struct {
    int data;
    int cur;
} component;

// 将结构体数组中所有分量连接到备用链表中
void reserveArr(component* arr);
// 初始化静态链表
int initArr(component* arr);
// 输出数据
void displayArr(component* arr, int body);
// 从备用链表上摘下空间节点
int mallocArr(component* arr);

int main()
{
    component arr[maxSize];
    int body = initArr(arr);
    displayArr(arr, body);
    return 0;
}

void reserveArr(component* arr)
{
    for (int i = 0; i < maxSize; i++) {
        arr[i].cur = i + 1; // 将每个数组分量链接到一起
        arr[i].data = -1;
    }
    arr[maxSize - 1].cur = 0; // 链表最后一个节点的游标值为0
}
int mallocArr(component* arr)
{
    int i = arr[0].cur;
    if (arr[0].cur) {
        arr[0].cur = arr[i].cur;
    }
    return i;
}
int initArr(component* arr)
{
    reserveArr(arr);
    int body = mallocArr(arr);
    int tmpBody = body;
    for (int i = 1; i < 4; i++) {
        int j = mallocArr(arr);
        arr[tmpBody].cur = j;
        arr[j].data = i;
        tmpBody = j;
    }
    arr[tmpBody].cur = 0;
    return body;
}
void displayArr(component* arr, int body)
{
    int tmpBody = body;
    while (arr[tmpBody].cur) {
        printf("%d, %d ", arr[tmpBody].data, arr[tmpBody].cur);
        tmpBody = arr[tmpBody].cur;
    }
    printf("%d, %d \n", arr[tmpBody].data, arr[tmpBody].cur);
}
