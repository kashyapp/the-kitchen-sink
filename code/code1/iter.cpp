#include <iostream>
using namespace std;

class Container{
	public:
	class iterator{
		virtual iterator& begin() =0;
		virtual iterator& next() =0;
		virtual iterator& end() =0;
		virtual Container& deref() =0;
	};
	int getIval();
	private:
	int ival;
};


class Test:public Container{
	private:
		double fval; 
};
