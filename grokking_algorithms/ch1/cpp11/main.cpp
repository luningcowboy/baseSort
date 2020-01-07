#include <iostream>
#include <vector>
using std::cout;
using std::endl;

template <typename T>
int binary_search(const std::vector<T>& list, const int& item)
{
    int low = 0;
    int high = list.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        T guess = list[mid];
        if (guess == item)
            return mid;
        if (guess > item)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
template <typename T>
const T* binary_search2(const std::vector<T>& list, const T& item)
{
    const T* low = &list.front();
    const T* high = &list.back();

    while (low <= high) {
        const T* guess = low + ((high - low) / 2);
        if (*guess == item)
            return guess;
        if (*guess > item)
            high = guess - 1;
        else
            low = guess + 1;
    }
    return nullptr;
}
int main()
{
    std::vector<int> my_list = { 1, 2, 3, 4, 5 };
    cout << binary_search(my_list, 3) << endl;
    const int* ret = binary_search2(my_list, 4);
    cout << *ret << endl;
    cout << ret << endl;
    return 0;
}
