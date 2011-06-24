#include <algorithm>
#include <iterator>
#include <functional>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <utility>

struct Foo{
    int i;
    int j;
    int k;
};

namespace std{
    template <>
    struct less<Foo>{
        bool operator()(const Foo &a, const Foo &b){
            if(a.i != b.i)
                return a.i<b.i;
            if(a.j != b.j)
                return a.j<b.j;
            if(a.k != b.k)
                return a.k<b.k;
            return false;
        }
    };
}

struct lesser{
    bool operator()(const Foo &a, const Foo &b){
        if(a.i != b.i)
            return a.i<b.i;
        if(a.j != b.j)
            return a.j<b.j;
        return false;
    }
};

bool operator<(const Foo &a, const Foo &b){
    if(a.i != b.i)
        return a.i<b.i;
    if(a.j != b.j)
        return a.j<b.j;
    if(a.k != b.k)
        return a.k<b.k;
    return false;
}

std::ostream& operator<<(std::ostream &os, const Foo &f){
    os << '{' << f.i << ',' << f.j << ',' << f.k << '}';
    return os;
}

std::istream& operator>>(std::istream &is, Foo &f){
    is >> f.i >> f.j >> f.k;
    return is;
}

int main(){
    std::vector<Foo> foo;
    Foo t;
    while(std::cin >> t){
        foo.push_back(t);
    }
    std::vector<Foo> bar(foo);
    
    std::copy(foo.begin(), foo.end(), std::ostream_iterator<Foo>(std::cout," "));
    std::cout << std::endl;

    std::sort(foo.begin(), foo.end());
    std::copy(foo.begin(), foo.end(), std::ostream_iterator<Foo>(std::cout," "));
    std::cout << std::endl;

    typedef std::vector<Foo> vf;
    Foo q={2,3,3};
    vf::iterator i = std::lower_bound(foo.begin(), foo.end(), q, lesser());
    std::cout << *i << std::endl;
    vf::iterator j = std::upper_bound(foo.begin(), foo.end(), q, lesser());
    std::cout << *j << std::endl;
    std::pair<vf::iterator, vf::iterator> res = equal_range(foo.begin(), foo.end(), q, lesser());
    std::copy(res.first, res.second, std::ostream_iterator<Foo>(std::cout," "));
    std::cout << std::endl;
    std::copy(i, j, std::ostream_iterator<Foo>(std::cout," "));
    std::cout << std::endl;

    return 0;
}
