#include <ext/hash_set>
#include <iostream>
#include <string>
#include <iterator>
using namespace std;
using __gnu_cxx::hash_set;

#define TYPE long
#define HASH hash_set<TYPE>
#define PERIOD 1000

int main(){
    TYPE s;
    HASH h;
    int n=PERIOD;
    do{
        cin >> s;
        h.insert(s);
        if(--n == 0){
           cout << h.size() << endl;
            n=PERIOD;
        }
    } while(cin);
    for(HASH::iterator i = h.begin();
            i!=h.end();
            i++)
        cerr << *i << endl;
    
    return 0;
}
