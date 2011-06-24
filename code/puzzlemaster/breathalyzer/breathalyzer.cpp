#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

using std::ifstream;
using std::transform;
using std::vector;
using std::string;
using std::copy;
using std::ostream_iterator;
using std::cout;


//#define FILEPATH /var/tmp/twl06.txt
#define FILEPATH twl06.txt

vector<string> slurp(char *path) {
    ifstream in(path);
    
    vector<string> words;
    string s;
    
    while (in >> s) {
        transform(s.begin(), s.end(), s.begin(), toupper);
        words.push_back(s);
    }
    
    return words;
}

int distance(string s, string t) {

}

int main(int argc, char **argv) {
    vector<string> words = slurp(argv[1]);
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, ", "));


    return 0;
}


