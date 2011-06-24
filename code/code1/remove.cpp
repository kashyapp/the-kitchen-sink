#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

int main(){
    int foo[] = {1, 2 , 1, 3, 1, 4, 1, 5};
    int *begin = &foo[0];
    int *end = begin + sizeof(foo)/sizeof(int);
    copy(begin, end, ostream_iterator<int>(cout, " "));
    cout<<endl;
    int *newend = remove(begin, end, 1);
    copy(begin, end, ostream_iterator<int>(cout, " "));
    cout<<endl;
    copy(begin, newend, ostream_iterator<int>(cout, " "));
    cout<<endl;

    return 0;
}
