#include <iostream>
#include <vector>

#define LEFT 0
#define RIGHT 1

int main() {
}

template <class T>
int bincount(vector<T> v) {
    int l = findBoundary(v, LEFT);
    int r = findBoundary(v, RIGHT);

    return r - l + 1;
}

int lastoccur(int arr[], int first, int last, int ele) {
    if (first > last) return -1;
    int mid = first + last / 2;
    if (a[mid] == ele) {
        int next = lastoccur(arr, mid + 1, last, ele);
        if (next == -1) {
            return mid;
        } else {
            return next;
        }
    }

    return lastoccur(arr, first, mid - 1, ele);
}
