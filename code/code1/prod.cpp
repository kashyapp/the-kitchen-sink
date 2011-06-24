#include <iostream>
#include <vector>
#include <iterator>


template <class T>
int prod(T first, T last, int preprod){
    if(first == last) return 1;
    int t = prod(first+1, last, *first * preprod);
    int p = *first * t;
    *first = t * preprod;
    return p;
}

int main(){
    std::vector<int> a;
    int i;
    while (std::cin >> i)
        a.push_back(i);
    prod(a.begin(),a.end(),1);
    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;

    int b[]= {1,2,3,4,5,6,1,3};
    prod(b,b+8,1);
    std::copy(b,b+8, std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;
    return 0;
}
