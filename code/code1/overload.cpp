#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class filename_t	: public std::string {};
class tablename_t	: public std::string {};

void read(const filename_t &foo){
	cout << "reading file\n";
}

void read(const tablename_t &foo){
	cout << "reading table\n";
}

int main(){
	return 0;
}
	
