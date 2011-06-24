#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <climits>
#include <iterator>
#include <math/common_factor_rt.hpp>
#include <algorithm>
#include <functional>

using namespace std;

#define CERR Debug()

std::ostream& Debug() {
    std::clog.clear(false
            ? std::ios_base::goodbit
            : std::ios_base::badbit);
    return std::clog;
} 

struct SKU;
typedef vector<SKU> data_t;

struct scope {
    string s;

    scope(string _s) : s(_s) {
        CERR << "Entering scope : "<< s << endl;
    }

    ~scope() {
        CERR << "Exiting scope  : "<< s << endl;
    }
};

struct SKU {
    string id;
    long weight;
    long cost;

    SKU(string _sku, long _weight, long _cost)
    : id(_sku), weight(_weight), cost(_cost)
    {}
};

ostream& operator<<(ostream &o, const SKU &sku) {
    o << "[" << sku.id << ": " << sku.weight << ", " << sku.cost << "]";
    return o;
}

ostream& operator<< (ostream &o, const data_t &data) {
    copy(data.begin(), data.end(), ostream_iterator< SKU >(o, "\n"));
    return o;
}

struct weightCompare : public binary_function<SKU, SKU, bool> {
    bool operator() (SKU s1, SKU s2) {
        return s1.weight > s2.weight;
    }
};

//prune useless weights
data_t::iterator prune(data_t &data) {
    scope s("prune");

    sort(data.begin(), data.end(), weightCompare());

    data_t::iterator prev = data.begin();
    for (data_t::iterator i = data.begin() + 1; i != data.end(); i++) {
        if (prev->cost > i->cost) {
            *(++prev) = *i;
        }
    }

    return ++prev;
}

data_t slurp(istream &in) {
    data_t data;

    string sku;
    
    while (in >> sku) {
        long weight;
        long cost;

        in >> weight;
        in >> cost;

        data.push_back(SKU(sku, weight, cost));
    }
    
    //CERR << data << endl;

    return data;
}

long getgcd (long target, const data_t &data) {
    scope s("getgcd");

    long gcd;
    long lcm;

    gcd = lcm = target;

    for (size_t i = 0; i < data.size(); ++i) {
        gcd = boost::math::gcd(gcd, data[i].weight);
        lcm = boost::math::lcm(lcm, data[i].weight);
    }

    CERR << gcd << endl;
    return gcd;
}

long getUpperBound(long target, const data_t &data) {
    scope s("get upper bound");

    long cost = LONG_MAX;
    long upper_bound = LONG_MAX;
    for (size_t i = 0; i < data.size(); ++i) {
        int count;
        SKU d = data[i];

        if (target % d.weight == 0) {
            count = target/d.weight;
        } else {
            count = target/d.weight + 1;
        }

        if (count * d.cost < cost) {
            cost = count * d.cost;
            upper_bound = count * d.weight;
        }
    }
    
    CERR << upper_bound << endl;

    return upper_bound;
}

long solve(long target, const data_t &data) {
    scope s("solve");
    
    long gcd = getgcd(target, data);
    long upper_bound = getUpperBound(target, data);

    vector<long> costs(upper_bound + 1);
    costs[0] = 0;

    size_t n = data.size();
    for (long w = gcd; w <= upper_bound; w += gcd) {
        long min = LONG_MAX;
        for (size_t j = 0; j < n; ++j) {
            SKU item = data[j];
            long w1, temp;
            if ((w1 = w - item.weight) >= 0) {
                temp = costs[w1/gcd] + item.cost;
            } else {
                temp = item.cost;
            }
            if (temp < min) {
                min = temp;
            }
        }
        costs[w/gcd] = min;
        //CERR << w << "-" << costs[w/gcd] << endl;
    }
     
    return costs[target/gcd];
}

int main(int argc, char **argv) {
    char *filename = argv[1];

    ifstream in(filename);

    long weight;
    in >> weight;

    data_t data = slurp(in);

    data_t::iterator new_end = prune(data);
    data.erase(new_end, data.end());

    CERR << data << endl;

    long cost = solve(weight, data);

    cout << cost << endl;

    return 0;
}
