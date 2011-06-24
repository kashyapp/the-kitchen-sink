#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::copy;
using std::cout;
using std::cin;
using std::endl;
using std::ostream_iterator;

template <class iter>
void swap(iter a, iter b) {
    std::swap(a,b);
    iter c;
    *c = *a;
    *a = *b;
    *b = *c;
}

template <class iter>
void reverse(iter start, iter end){
    std::reverse(start,end);
    int n = end - start;

    for(int i = 0; i < n/2; ++i){
        swap(start + i, end -1 -i);
    }
}

template <class iter>
void rotate(iter start, iter end, int n){
    reverse(start, start+n);
    reverse(start+n, end);
    reverse(start, end);
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int n = sizeof(a)/sizeof(int);
    rotate(a, a + n, 3);

    copy(a, a+n, ostream_iterator<int>(cout, "; ")); cout<<endl;
    return 0;
}
