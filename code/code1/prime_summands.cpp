#include <iostream>
#include <vector>
using namespace std;

#define N 10000
vector<int> primes;

void calc_primes() {
    int num[N+1];
    for (int i = 2; i <= N; ++i) {
        num[i] = i;
    }
    for(int i = 2; i <= N; ++i) {
        if (num[i] > 0) { 
            int prime = num[i];
            primes.push_back(prime);
            for(int j = prime * 2; j <= N; j += prime) {
                num[j] = 0;
            }
        }
    }
}

int countsummands(int n) {
    int start = 0;
    int end = 0;
    int sum = 2;

    int counter = 0;

    do {
        if (sum > n) {
            sum -= primes[start++];
        } else if (sum == n) {
            counter++;
            for (int i = start; i <= end; i++) { cerr << primes[i] << " "; } cerr << endl;
            sum = sum - primes[start++] + primes[++end];
        } else {
            sum += primes[++end];
        }
    } while(primes[end] <= n);

    return counter;
}

int main() {
    int n;
    calc_primes();
    while (cin >> n) {
        cout << countsummands(n) << endl;
    }
    return 0;
}
