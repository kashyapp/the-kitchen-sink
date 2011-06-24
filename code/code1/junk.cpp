#include <iostream>
using namespace std;

class base {
    public: virtual void run(){
                cout << "base" << endl;
            }
};
class derived : public base {
    public: virtual void run(){
                cout << "derived" << endl;
            }
};
int main(){
    base b;
    derived d;
    b.run();
    d.run();
    b = d;
    b.run();
    return 0;
}
