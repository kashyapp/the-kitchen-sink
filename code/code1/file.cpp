#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
using namespace std;



int main(int argc, char ** argv){
    assert(argc>1||!"Must specify filename argument");
    string s,t;
    ifstream f(argv[1]);
    int count=0;
    cerr << "begin read of file : " << argv[1] << endl;
    while(getline(f,t)){
        s += t + '\n';
        count++;
    }
    cerr << count << " lines read in from file : " << argv[1] << endl << endl;
    cout << s;
    return 0;
}

