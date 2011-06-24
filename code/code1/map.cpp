#include <algorithm>
#include <map>
#include <iostream>
#include <typeinfo>
#include <string>
#include "boost/shared_ptr.hpp"

using namespace std;
using namespace boost;

class foo{
    public:
        foo(const char* s): _s(s){
            cerr << "hello ji " << _s << endl;
        }
        ~foo(){
            cerr << "bye  bye " << _s << endl;
        }
        foo(): _s("dummy"){
            cerr << "bye  bye " << _s << endl;
        }
        string& gets(){
            return _s;
        }
    private:
        std::string _s;
    //    foo();
};


int main(){

    map<const char*,shared_ptr<foo> > dict;
    shared_ptr<foo> f;
    char *s = new char[100];
    f = shared_ptr<foo>(new foo("asdf"));
    s = "kashyap";
    dict[s] = f;
    f = shared_ptr<foo>(new foo("sdfsaasdf"));
    s = "arun";
    dict[s] = f;
    f = shared_ptr<foo>(new foo("asdfdfgdsf"));
    s = "ping";
    dict[s] = f;

    for(map<const char*,shared_ptr<foo> >::iterator i=dict.begin(); i != dict.end(); ++i){
        cout << i->first << " -> " << i->second->gets() << endl;
//        dict.erase(i);
    }
    dict.clear();
    cerr<<"randomess\n";
    return 0;
}
