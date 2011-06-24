#include <iostream>
#include <list>
#include <vector>

using namespace std;

class foo{
    public:
    foo(int i):_i(i)
    {
        cerr <<"creating new instance of foo with i = " << _i << endl;
    }
    ~foo(){
        cerr << "killing instance of foo with i = " << _i << endl;
    }
    foo(const foo& x):_i(x._i){
        cerr << "copying instance of foo with i = " << _i << endl;
    }
    foo(){
        cerr << "construct instance of foo" << endl;
    }
    foo& operator = (const foo& p){
        cerr << "assigning instance of foo" << endl;
        _i = p._i;
    } 
    private:
    int _i;
};

int main(int argc, char **argv){
    vector<foo> bar;
    int k;
    while(cin >> k){
        bar.push_back(foo(k));
    }
    vector<foo> barr = bar;
    return 0;
}
