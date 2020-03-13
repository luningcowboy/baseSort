#include <stdio.h>
#include <stdlib.h>
#define Size 5
typedef struct Table {
    int* head;
    int length;
    int size;
} table;

table initTable()
{
    table t;
    t.head = (int*)malloc(Size * sizeof(int));
    if (!t.head) {
        printf("initTable: 分配内存失败");
        exit(0);
    }
    t.length = 0;
    t.size = Size;
    return t;
}
// table t 要操作的table
// int elem 需要插入的元素
// int pos 需要插入的元素位置
table insertTable(table t, int elem, int pos)
{
    // 检查插入位置是否在数组内
    if (pos > t.length + 1 || pos < 1) {
        printf("insertTable error:插入的位置不在数组范围内");
        return t;
    }
    // 如果数组已经满了，重新分配内存空间
    if (t.length == t.size) {
        t.head = (int*)realloc(t.head, (t.size + 1) * sizeof(int));
        if (!t.head) {
            printf("insertTable err: 分配内存失败");
            return t;
        }
        t.size += 1;
    }
    // 向后移动从插入位置到最后的内存
    for (int i = t.length - 1; i >= pos - 1; i--) {
        t.head[i + 1] = t.head[i];
    }
    // 设置插入位置的值
    t.head[pos - 1] = elem;
    t.length++;
    return t;
}
// table t 执行删除操作的数组
// int pos 删除元素的位置
table delTable(table t, int pos)
{
    if (pos > t.length || pos < 1) {
        printf("delTable err: 需要删除的元素超出范围");
        exit(0);
    }
    // 删除操作:所有pos后的元素位置向前移动
    for (int i = pos; i < t.length; i++) {
        t.head[i - 1] = t.head[i];
    }
    t.length--;
    return t;
}
// 这个算法只是返回第一个查找到的元素
int selectTable(table t, int elem)
{
    for (int i = 0; i < t.length; i++) {
        if (t.head[i] == elem) {
            return i + 1;
        }
    }
    return -1;
}
// 修改元素
// 这个也有缺陷，只能修改查找到的第一个元素
table amendTable(table t, int elem, int newElem){
    int pos = selectTable(t, elem);
    // 处理查找失败的情况
    if(pos != -1){
        t.head[pos - 1] = newElem;
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
    for(int i = 1; i <= Size; i++){
        t.head[i - 1] = i;
        t.length++;
    }
    printf("原顺序表:\n");
    displayTable(t);

    printf("删除元素:\n");
    t = delTable(t, 1);
    displayTable(t);

    printf("在第二个位置插入5:\n");
    t = insertTable(t, 5, 2);
    displayTable(t);

    printf("查找元素3:\n");
    int pos = selectTable(t, 3);
    printf("%d\n", pos);

    printf("将元素3的值修改为6:\n");
    t = amendTable(t, 3, 6);
    displayTable(t);

    return 0;
}
