#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
int main(){
    int a[]={1,2,3,4,5,6,7,8,9,0};
    vector<int> b(&a[0],&a[10]);

    for(vector<int>::iterator i = b.begin();
            i!=b.end();
            ){
        cout << *i << endl;
        int c;
        cin >> c;
        if(c == 0){
            b.erase(i);
            cout << " ---- " << *i << endl;
        }
        else {
            i++;
        }
    }
    copy(b.begin(),b.end(),ostream_iterator<int>(cout," "));
    cout << endl;
    return 0;
}
