#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

bool foo(int *p, const char *s, int bufsize) {
    while (bufsize--) {
        cout << *s++;
    }
    cout << endl;
    *p = 39;
    return true;
}

void decode(string &s) {
    const char* c_str = s.c_str();
    int length = s.length();

    string::iterator write = s.begin();
    int read_index = 0;

    while (read_index < length) {
        int p;
        if(c_str[read_index] == '$' 
                && (read_index + 4 < length) 
                && foo(&p, &c_str[read_index + 1], 4) 
                && isascii(p)) 
        {
            *write = (char) p;
            read_index += 5;
        } else {
            *write = c_str[read_index];
            read_index++;
        }
        write++;
    }
    s.erase(write, s.end());

}

int main() {
    string s = "sita$0020and$0020gita$123";
    //output string should be "site and gita$123"
    //$123 should remain unchanged since it is not 4 digits
    cout << (void*)s.c_str() << " " << (void*)s.data() << " " << s.length() << " " << s.capacity() << endl;

    decode(s);
    cout << s << endl;

    cout << (void*)s.c_str() << " " << (void*)s.data() << " " << s.length() << " " << s.capacity() << endl;
 
    return 0;
}
