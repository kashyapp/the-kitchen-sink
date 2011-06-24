#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string RemoveFirstOccurance(string s, char c){
	int i = s.find_first_of(c);
	int len = s.length();
	if (i < 0)
		return s;
	f (i == 0)
		return s.substr(1);
	return (s.substr(0, i) + s.substr(i+1));
}
vector<string> Permute(string s){
	vector<string> output;
	int len = s.length();
	if (len == 1)
		output.insert(output.end(), s);
	else{
		for (int i=0; i<len; i++){
			if ((i == len-1) || (s[i] != s[i+1])){
				vector<string> sstr = Permute(RemoveFirstOccurance(s, s[i]));
				int l = sstr.size();
				for(int j=0; j<l; j++){
					output.insert(output.end(), (s[i] + sstr[j]));
				}
			}
		}
	}
	return output;
}
