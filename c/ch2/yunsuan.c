// 添加 + - x / 4个运算符使等式 5 5 5 5 5=5 成立
// x / 优先级高于 + -
#include<stdio.h>
int op(int nums[5], int ops[4]){
    int ret = 0;
    return ret;
}
int main(){
    int operate[4] = {1,2,3,4};
    int nums[5] = {5,5,5,5,5};
    int result = 5;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            for(int k = 0; k < 4; ++k){
                for(int p = 0; p < 4; ++p){
                    int ops[4] = {i, j, k, p};
                    int tmp = op(nums,ops);
                    printf("xxxxx\n");
                }
            }
        }
    }
    return 0;
}
