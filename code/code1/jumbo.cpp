#include <iostream>
#include <memory>
using namespace std;

class Mumbo{
    public:
        int i;
        Mumbo():i(125){
            cout << "mumbo is born" << endl;
        }
        ~Mumbo(){
            cout << "mumbo is dying" << endl;
        }
    private:
        Mumbo(const Mumbo& m):i(m.i){
            cout << "mumbo is born by a copy" << endl;
            i = i*i;
        }
};

Mumbo getMumbo(){
    cout << "we are in getmumbo" << endl;
    return Mumbo();
}

class Jumbo{
    public:
    void foo(){
        cout << "we are foo" << endl;
        m = auto_ptr<Mumbo>(new Mumbo(getMumbo()));
        cout << "we are fooed" << endl;
    }
    void bar(){
        cout << "we are bar" << endl;
        cout << m->i << endl;
        cout << "we are bared" << endl;
    }
    private:
        auto_ptr<Mumbo> m;
};

int main(){
    Jumbo j;
    j.foo();
    j.bar();
    return 0;
}
