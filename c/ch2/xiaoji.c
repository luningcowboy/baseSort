// 百钱买百鸡
// 鸡翁1，值钱5
// 鸡母1，值钱3
// 鸡雏3，值钱1
// 用100元买100只鸡，问公鸡，母鸡，小鸡各多少只?
// gj x * 5
// mj y * 3
// xj z * (1/3)
// x + y + z = 100
// x * 5 + y * 3 + z * (1/3) = 100
#include <stdio.h>
int main()
{
    int x = 20;
    int y = 33;
    int z = 100;
    int maxCount = 0;
    int maxFei = 0;
    int j = 0;
    for (int i = 0; i < x; ++i) {
        for (int k = 0; k < y; ++k) {
            j = 100 - i - k;
            maxFei = i * 5 + k * 3 + j / 3;
            if (j % 3 == 0 && maxFei == 100) {
                printf("gj:%d, mj:%d, xj:%d \n", i, k, j);
            }
        }
    }
    return 0;
}
