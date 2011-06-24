#include <algorithm>
#include <iostream>
using namespace std;

template<class T> struct print : public unary_function<T, void>
{
  print(ostream& out) : os(out), count(0) {}
  void operator() (T x) { os << x << ' '; ++count; }
  ostream& os;
  int count;
};

int main()
{
  int A[] = {1, 4, 2, 8, 5, 7};
  const int N = sizeof(A) / sizeof(int);

  print<int> P = for_each(A, A + N, print<int>(cout));
  cout << endl << P.count << " objects printed." << endl;
}
