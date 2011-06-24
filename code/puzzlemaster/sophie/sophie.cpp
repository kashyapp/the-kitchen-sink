#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <climits>
#include <map>
#include <iterator>
#include <algorithm>
#include <functional>

#define CERR Debug()
#define DEBUG true

std::ostream& Debug() {
    std::clog.clear(DEBUG
            ? std::ios_base::goodbit
            : std::ios_base::badbit);
    return std::clog;
} 

typedef int LocId;
typedef std::map<LocId, double> PathsT;

struct Location {
    double probability;
    PathsT paths;
};

struct Home { 
    std::vector<Location>  locations;

    Home(int nloc) : locations(nloc) {
    }

    void setProbability(int locId, double probability) {
        locations[locId].probability = probability;
    }

    void addPath(int from, int to, double time) {
        locations[from].paths[to] = time;
        locations[to].paths[from] = time;
    }

    double findsophie();
};

std::ostream& operator<< (std::ostream &out, const Location& loc) {
    const PathsT &p = loc.paths;
    out << "[P: " << loc.probability << "] "; 

    for (PathsT::const_iterator i = p.begin(); i != p.end(); ++i) {
        out << "\n\t\t"  <<  i->first << " - " << i->second;
    }

    return out;
}

std::ostream& operator<< (std::ostream &out, const Home& home) {
    const std::vector<Location> &l = home.locations;
    for (size_t i = 0; i < l.size(); ++i) {
        out << i << " " << l[i] << std::endl;
    }
    return out;
}

//try brute force first
// all paths and calculate expected value
double Home::findsophie() {
    return 6;
}

//the last location is the start location
Home slurp(char *filename) {
    std::ifstream in(filename);

    int nloc;
    in >> nloc;
    
    // the return value
    Home home(nloc);

    std::map<std::string, int> loc2id;
    while (nloc--) {
        std::string loc;
        double probability;
        in >> loc >> probability;
        loc2id[loc] = nloc;

        home.setProbability(nloc, probability);
    }

    int npaths;
    in >> npaths;
    while (npaths--) {
        std::string from, to;
        double time;
        in >> from >> to >> time;

        int fromId = loc2id[from];
        int toId   = loc2id[to];

        home.addPath(fromId, toId, time);
    }

    return home;
}

int main(int argc, char **argv) {
    Home home = slurp(argv[1]);

    Debug() << home << std::endl;
    std::cout << std::fixed << std::setprecision(2) << home.findsophie() << std::endl;

    return 0;
}
