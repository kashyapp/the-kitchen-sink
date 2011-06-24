#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cassert>
#include <stack>
#include <cstdlib>
#include <iterator>

using namespace std;

#define BLANK -1
#define WHITE 1
#define BLACK 0

typedef vector<vector<int> > people_t;

int getId(string name) {
    static int i = 0;
    static map<string, int> ids;
    if (ids.find(name) != ids.end()) {
//        cerr << name << " = " << ids[name] << endl;
    } else {
//        cerr << name << " : " << i << endl;
        ids[name] = i++;
    }
    return ids[name];
}

people_t *slurp(istream &in) {
    int n;
    in >> n;

    people_t *people = new people_t(n);

    while (n--) {
        string who;
        int m;
        
        in >> who;
        in >> m;

        while (m--) {
            string liar;
            in >> liar;
            people->at(getId(who)).push_back(getId(liar));
            people->at(getId(liar)).push_back(getId(who));
        }
    }

    return people;
}

// should be used only for BLACK(0) and WHITE(1)
int opposite(int color) {
    return 1-color;
}

vector<int> liarliar(people_t *people) {
    int n = people->size();
    vector<int> color(n, BLANK);

    stack<int> s;
    color[0]=WHITE;
    s.push(0);
    while (!s.empty()) {
        int current = s.top();
        s.pop();

        const vector<int> &liars = people->at(current);
        for(size_t j = 0; j < liars.size(); j++) {
            int liar = liars[j];

            if (color[liar] == BLANK) {
                s.push(liar);
                color[liar] = opposite(color[current]);
            } 
            assert(color[liar] == opposite(color[current]));
        }
    }

    vector<int> counts(2, 0);
    for(size_t i=0; i < color.size(); i++) {
//        cerr << i << " " << color[i] << endl;
        ++counts[color[i]];
    }

    return counts;
}

int main(int argc, char **argv) {

    const char *filename = argv[1];
    ifstream in(filename);

    vector<int> counts = liarliar(slurp(in));

    if (counts[0] < counts[1]) {
        cout << counts[1] << " " << counts[0] << endl;
    } else {
        cout << counts[0] << " " << counts[1] << endl;
    }

    return 0;
}
