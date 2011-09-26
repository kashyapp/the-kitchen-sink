#include <iostream>
using namespace std;

class Topic {
    public:
        void print() {
            cout << "kashyap" << endl;
        }
};

void batch(Topic **topics) {
    cout << topics << " " << *topics << endl;
    topics[0]->print();
}

void single(Topic* &topic) {
    cout << topic << " " << &topic << endl;
    batch(&topic);
}

int main() {
    Topic *topics = new Topic[5];
    Topic *topic = new Topic;
    cout << topic << " " << &topic << endl;
    single(topic);
    return 0;
}
