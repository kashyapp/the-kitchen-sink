#include <iostream>
using namespace std;

class Foo{
    public:
    Foo(int j) 
        :i(bar(j)) {}
    void pom(){
        cout << i << endl;
    }
    private:
        Foo();
        int i;
        int bar(int j){
            return j*j;
        }
};

int main(){
   Foo a(3);
   a.pom();
   return 0;
}
