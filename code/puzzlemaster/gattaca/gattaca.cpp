/**
 * Copyright 2011 Kashyap
 * Author: kashyapp@gmail.com
 */
#include <sys/time.h>
#include <stdint.h>

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#ifdef DBG
#define DEBUG debug(true) << "[DEBUG] "
#else
#define DEBUG debug(false)
#endif

std::ostream& debug(bool yes) {
    std::cerr.clear(yes
            ?std::ios_base::goodbit
            :std::ios_base::badbit);
    return std::cerr;
}

/** 
 * a simple timer struct
 */
struct timer {
    std::string name;
    uint64_t t0;

    private:
    uint64_t now() {
        timeval tv;
        gettimeofday(&tv, NULL);

        return (1000 * tv.tv_sec) + (tv.tv_usec / 1000);
    }

    public:
    explicit timer(const std::string &_name) : name(_name), t0(now()) {
    }

    ~timer() {
        DEBUG << "{TIMER} " << name << " " << now() - t0 << std::endl;
    }
};

/**
 * our main data types
 */
struct node {
    uint32_t start;
    uint32_t end;
    uint64_t score;

    /** 
     * compares finish times, basically
     */
    bool operator< (const node &rhs) const {
        if ( end != rhs.end )
            return end < rhs.end;
        else
            return start < rhs.start;
    }
};
typedef std::vector<node> data_t;

std::ostream& operator<<(std::ostream& o, const node& n) {
    o << "[" << n.start << " " << n.end << " " << n.score << "]";
    return o;
}

/** 
 * we don't care about the actual string
 */
void discard_dna(std::istream &in) {
    timer t("discard_dna");
    int l;
    in >> l;

    char buffer[81];
    in.getline(buffer, 81);

    for (; l > 0; l-=80) {
        in.getline(buffer, 81);
    }
}

/**
 * ugly duckling parser
 * for integers
 * from a char*
 */
template<typename T>
char* parse(char *s, T *number) {
    *number = 0;
    while (' ' == *s || '\t' == *s) {
        ++s;
    }
    while ('0' <= *s && '9' >= *s) {
        *number = (*number * 10) + (*s - '0');
        ++s;
    }
    // DEBUG << "parse: " << *number << std::endl;

    return s;
}

/**
 * slurp the data into the data_t
 */
data_t slurp(std::istream &in) {
    timer t("slurp");

    char s[120];
    in.getline(s, 120);

    int n;
    sscanf(s, "%d", &n);

    data_t data;
    data.reserve(n);

    while (n--) {
        in.getline(s, 120);

        node t;
        parse(parse(parse(s,
                        &t.start), &t.end), &t.score);

        // in >> t.start >> t.end >> t.score;
        data.push_back(t);
    }

    return data;
}

/**
 * binary search 
 */
uint64_t fnd(data_t::const_iterator i, data_t::const_iterator j, int needle) {
    uint64_t score = 0;

    node dummy;
    dummy.start = 0;
    dummy.end = needle;

    data_t::const_iterator lfound = std::lower_bound(i, j, dummy);

    if (lfound - 1 >= i) {
        score = (lfound - 1) -> score;
        // DEBUG << "found: " << *(lfound - 1) << std::endl;
    } else {
        // DEBUG << "not found" << std::endl;
    }

    // DEBUG << " " << j->end << " " << needle << " " << score << std::endl;
    return score;
}


/** std::sort by finish times
 *
 */
void sort(data_t *data) {
    timer t("std::sort");
    std::sort(data->begin(), data->end());
}

/**
 * and then do stuff
 */
int solve(data_t *data) {
    timer t("solve");

    uint64_t score = 0;

    for (data_t::iterator i = data->begin();
            i != data->end();
            ++i) {
        // DEBUG << "before : " << *i << std::endl;
        i->score = score = std::max(
                score,
                i->score + fnd(data->begin(), i, i->start));
        // DEBUG << "after  : " << *i << std::endl;
    }

    return data->back().score;
}

int main(int argc, char **argv) {
    char *filename = argv[1];

    std::ifstream in(filename);

    discard_dna(in);
    data_t data = slurp(in);

    sort(&data);

    std::cout << solve(&data) << std::endl;

    return 0;
}
