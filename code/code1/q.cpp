#include <stack>
#include <iostream>
using namespace std;


template <class T>
class queue { 
    private: 
        stack<T> s;

    public:
        void enqueue(T t) {
            s.push(t);
        }
        
        T deque() {
            T t = s.top();
            s.pop();
        
            if (s.empty()) {
                return t;
            } else {
                T p = deque();
                s.push(t);
                return p;
            }
        }
        
        bool empty() {
            return s.empty();
        }
};

int main() {
    char c;
    queue<char> q;
    while (cin.get(c)) {
        if (c == '.') {
            if (q.empty()) {
                cerr << "empty queue" << endl;
            }
            else {
                cout.put(q.deque());
            }
        } else {
            q.enqueue(c);
        }
    }
    return 0;
}


