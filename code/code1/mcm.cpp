#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <climits>
#include <cassert>
using namespace std;

template<class iter>
int mcm(iter i, iter j){
//stupid recursive
	if(i+1 == j)
		return 0;
	int min=INT_MAX;
	int c;
	for(iter k=i+1; k < j; ++k){
		c = mcm(i,k) + mcm(k,j) + (*i)*(*k)*(*j);
		min = c<min?c:min;
	}
	return min;
}

int mcm2(vector<int> s){
	int n = s.size();
	vector< vector<int> > costs(n-1, vector<int>(n-1));
	for(int i=0;i<n;++i){
		for(int j=i;j<n;++j){
			if(i==j)
				costs[i][j]=0;
			else
				costs[i][j]=costs
		}
	}
}

int main(){
	vector<int> sizes;
	int i;
	while(cin >> i)
		sizes.push_back(i);
	copy(sizes.begin(), sizes.end(), ostream_iterator<int>(cout," "));
	cout<<endl;

	int mincost = mcm(sizes.begin(),sizes.end()-1);
	cout << mincost << endl;

	mincost = mcm2(sizes);
	cout << mincost << endl;
	return 0;
}


