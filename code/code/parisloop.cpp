/**
City Tour of Paris is awesome !
 
It seems like all the tourists who visits Paris wants to go for a city tour in
bus. Some people go alone, other people go in groups and don't want to board the
bus unless they can all go together. And Paris is so good that everyone who has
a tour wants to tour again and again. A bus ticket costs 1 Euro per person. Your
job is to figure out how much money the tour bus will make today.
 
The tour bus can hold k people at once. People queue for it in groups. Groups
board the tour bus, one at a time, until there are no more groups left or there
is no room for the next group; then the tour bus goes, whether it's full or not.
Once the city tour is over, all of its passengers re-queue in the same order.
The bus will run R times in a day.
 
For example, suppose R=4, k=6, and there are four groups of people with sizes:
1, 4, 2, 1. The first time the tour bus goes, the first two groups [1, 4] will
ride, leaving an empty seat (the group of 2 won't fit, and the group of 1 can't
go ahead of them). Then they'll go to the back of the queue, which now looks
like 2, 1, 1, 4. The second time, the bus will hold 4 people: [2, 1, 1]. Now the
queue looks like 4, 2, 1, 1. The third time, it will hold 6 people: [4, 2]. Now
the queue looks like [1, 1, 4, 2]. Finally, it will hold 6 people: [1, 1, 4].
The tour bus has made a total of 21 Euros.
 
Input format: The first line contains three space-separated integers: R, k and
N.  The second line contains N space-separated integers gi, each of which is the
size of a group that wants to ride. g0 is the size of the first group, g1 is the
size of the second group, etc.
 
Output format: For each test case, output one line containing the number of
Euros made by the tour bus.
 
Also,
1 <= R <= 10^8
1 <= k <= 10^9
1 <= N <= 1000
1 <= gi <= 10^7
gi <= k
 
Sample Input:
4 6 4
1 4 2 1
 
Sample Output:
21
*/

/**
 * OPTIMIZATIONS
 * actually simulate queue
 * circular buffer
 * calculate next and total from each start point
 * figure out the loop point and then do simple calculation
 */


#include <iostream>
using namespace std;
int main() {
    int R, k, N;
    cin >> R >> k >> N;
    
    int groups[1000];
    int   next[1000];
    unsigned int  total[1000];
    
    for (int i = 0; i < N; ++i) {
        cin >> groups[i];
    }
    
    for (int j = 0; j < N; ++j) {
        int   i = j,
            tmp = groups[i];
     
        do {
            i = (i+1)%N;
            tmp += groups[i];
        } while (tmp <= k && i != j);
     
        next[j] = i;
        total[j] = tmp - groups[i];
    }
    
    unsigned long long money = 0;
    int nxt;
    for (int i = 0, nxt = 0; i < R; ++i, nxt = next[nxt]) {
        money += total[nxt];
    }
    
    cout << money << endl;
    
    return 0;
}
