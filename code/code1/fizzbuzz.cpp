#include <iostream>
using namespace std;
int main(){
    for(int i=1;i<=100;++i){
        bool fizz = (0==i%3);
        bool buzz = (0==i%5);
        if(fizz && buzz)
           cout << "fizzbuzz" << endl; 
        else if(buzz)
            cout << "buzz" << endl;
        else if(fizz)
            cout << "fizz" << endl;
        else
            cout << i << endl;
    }
    return 0;
}
