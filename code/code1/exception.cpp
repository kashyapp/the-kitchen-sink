#include <algorithm>
#include <vector>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>

void bar(int i){
	std::ostringstream oss;
	oss << i << " is stupid, you are too!";
	throw std::invalid_argument(oss.str());
}

void foo(int i) throw(std::exception){
	std::ostringstream oss;
	switch(i){
		case 0:
			int j;
			std::cout << i << std::endl;
			break;
		case 1:
			std::cout << i << std::endl;
			break;
		case 2:
			std::cout << i << std::endl;
			bar(i);
			break;
		default:
			std::cout << i << std::endl;
			oss << "i = " << i << ", input out of range in foo(int i)";
			throw std::out_of_range(oss.str());
	}
}

int main(int argc, char **argv){
	try{
		foo(atoi(argv[1]));
	}
	catch(std::bad_exception &ex){
		std::cerr << ex.what() << " bad exception " << std::endl;
	}
	catch(std::exception &ex){
		std::cerr << ex.what() << " caught in main() " << std::endl;
	}
	catch(...){
		std::cerr << "unknown exception caught in main()" << std::endl;
	}
	return 0;
}
