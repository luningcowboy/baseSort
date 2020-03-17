重点:
`initTable:`
1. 初始化table, 分配内存空间
2. 检查内存分配是否成功
3. 设置table length和size
4. 返回table
`insertTable:`
1. 检查插入位置是否有问题
2. 检查是否需要重新分配内存，如果需要，重新分配内存
3. 平移内存中的值，空出pos上的值
4. 给pos上的元素赋值
5. length增加
`delTable`
1. 进行位置判断
2. 找到制定位置，直接平移数组
3. 修改数组长度
`refreshTable`和`selectTable`没什么问题

语法注意:
`t.head = (int*)malloc(SIZE * sizeof(int));`
`t.head = (int*)realloc(t.head, (t.size + 1) * sizeof(int));`
