#include<iostream>
using namespace std;
int binarySearch(int arr[], int len, int item){
    int min = 0;
    int max = len - 1;
    while(min <= max){
        int mid = (min + max) / 2;
        int guess = arr[mid];
        if(guess == item) return mid;
        if(guess < item) min += 1;
        else max -= 1;
    }
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int len = sizeof(arr) / sizeof(int);
    int ret = binarySearch(arr, 5, 4); 
    cout<<ret<<endl;

    return 0;
}
