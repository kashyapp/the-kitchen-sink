#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <vector>
#include <sstream>

using std::vector;
using std::ifstream;

#define X 0
#define Y 1

struct point_t {
    double coord[2];
    double xx() const { return coord[X]; }
    double yy() const { return coord[Y]; }
    double& x() { return coord[X]; }
    double& y() { return coord[Y]; }
    int id;
};

typedef vector<point_t> data_t;

namespace std {
    ostream& operator<<(ostream &o, const point_t &p) {
        o << "[" << p.xx() << "," << p.yy() << "]";
        return o;
    }

    ostream& operator<<(ostream &o, const data_t &data) {
        for (data_t::const_iterator i = data.begin();
                i != data.end();
                ++i) {
            o << *i << ", ";
        }
        return o;
    }
}

data_t slurp(char *filename) {
    data_t data;

    ifstream in(filename);
    
    point_t p;
    while (in >> p.id) {
        in >> p.x() >> p.y(); 
        data.push_back(p);
    }

    std::cout << data << std::endl;

    return data;
}

struct node_t {
    node_t *left;
    node_t *right;
    point_t point;
};

point_t get_median(data_t::iterator start, data_t::iterator end, axis_t ) {
    return point_t();
}

data_t::iterator partition(data_t::iterator start, data_t::iterator end, const point_t &median) {
    return start;
}

void build_tree(data_t::iterator start, data_t::iterator end) {
    point_t median = get_median(start, end);
    data_t::iterator split = partition(start, end, median);
    build_tree(start, median);
    build_tree(median, end);
}


int main(int argc, char **argv) {
    char *filename = argv[1];

    data_t data = slurp(filename);
}
