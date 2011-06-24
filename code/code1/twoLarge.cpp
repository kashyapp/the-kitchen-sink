#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iterator>
using namespace std;

template <class InputIterator>
InputIterator twoLarge(InputIterator begin, InputIterator end){
	InputIterator one = begin;
	InputIterator two = one; two++;
	//cout << *one << " " << *two << endl;
	if(*one < *two)
		swap(one, two);
	//cout << *one << " " << *two << endl;

	InputIterator i = begin; i++; i++;
	for(; i != end; i++){
	 	if(*i > *two){
			if(*i > *one){
				two = one;
				one = i;
			}
			else{
				two = i;
			}
		}
	//cout << *one << " " << *two << endl;
	}
	return two;
}


template <class T>
vector<T>::iterator twoLarge(vector<T>::iterator begin, vector<T>::iterator end){
  return begin;
}

int main(){
	vector <int> foo;
	int k;
	while(cin >> k)
		foo.push_back(k);
	vector <int>::iterator i = twoLarge(foo.begin(),foo.end());
	cout << *i << endl;

	return 0;
}
