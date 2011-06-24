#include <iostream>
#include <string>
using namespace std;

void foo(){
    throw string("kashyap");
}

class throwingclass{
    public:
    throwingclass(){
        throw 100;
    }
};

int main(){
    try{
        throw exception();
    }
    catch(exception &e){
        cout << e.what() << endl;
    }
    catch(string &s){
        cout << s << endl;
    }
    catch(...){
        cout << "unknown shit\n";
    }
    
    throwingclass t;
    try{
    }
    catch(int &i){
        cout<<i<<endl;
    }
    catch(...){
        cout<<"foo\n";
    }
    return 0;
}
