/*************************************************************************
 @Author: luning
 @Created Time : 一 12/30 22:31:54 2019
 @File Name: main.cpp
 @Description:
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    std::vector<int> tv{1,2,3,4};
    int * a = &tv[0];
    cout<<*a<<endl;
    a += 1;
    cout<<*a<<endl;
    return 0;
}
