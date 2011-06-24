#include <iostream>
using namespace std;

class foo{
    public:
        ostream& operator<<(ostream&) const{
        }
    private:
        int i;
};


