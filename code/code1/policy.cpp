#include <iostream>

template <int I> struct policy
{
        static const int i = I;
};

template <class Policy = policy<0> > // default Policy is policy<0>
struct host
{
    void perform()
    {
        std::cout << "Using policy< " << Policy::i << " >" << std::endl;
    }
};

int main()
{
    host< policy<1> > a;
    a.perform();
	host<> b;
	b.perform();
}
