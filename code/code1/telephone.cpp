#include <iostream>
using namespace std;

char getCharKey(int telephoneKey, int place){
    static const char* keypad[] = {
        "0",
        "1",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    char c;

    return keypad[telephoneKey][place];
}

void printTelephoneWords(int phoneNumber){
    class Foo{
        public: static void foo(char *str, int phoneNumber){
            if(phoneNumber){
                int i = 0; 
                int n = phoneNumber%10;
                while((*str = getCharKey(n,i++)) != '\0'){
                    foo(str-1,phoneNumber/10);
                }
            }
            else{
                cout << str+1 << endl;
            }
        }
    };

    int l=0;
    for(int t=phoneNumber; t; t/=10,++l);

    char *s=new char[l+1];
    s[l]='\0';

    Foo::foo(s+l-1,phoneNumber);
}


int main(){
    int i;
    while(cin >> i){
        printTelephoneWords(i);
    }
    return 0;
}
