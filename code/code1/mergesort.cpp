#include <iostream>
#include <vector>

using namespace std;

template <class T>
void sort(T begin, T end) {
    if (begin == end) return;
    T mid = (begin + end)/2;
    sort(begin, mid);
    sort(mid + 1, end);
}

template <class T>
void print(T begin, T end) {
    for (; begin != end; begin++) {
        cout << *begin << ", ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 7, 5, 4, 8, 6, 9, 3, 2, 10};
    int l = sizeof(arr)/sizeof(int);

    sort(&arr[0], &arr[0] + l);

    print(&arr[0], &arr[0] + l);

    return 0;
}
