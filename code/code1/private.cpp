#include <iostream>
using namespace std;
template<class T>
class base{
    public:
    static T* instance(){
        static T* in = new T;
    }
};

class derived: public base<derived>{
    friend class base<derived>;
    private:
    derived(){
        cout<<"awesome\n";
    }
};

int main(){
    derived *p = derived::instance();
    return 0;
}
