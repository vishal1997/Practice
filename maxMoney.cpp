#include <iostream>
#include <vector>
using namespace std;

int main() {
	//code
	//code
	int T,N,money;
	cin>>T;
	vector<int> totalMoney(T,0);
	for(int i=0;i<T;i++) {
	    cin>>N;
	    cin>>money;
	    for(int j=0;j<N;j+=2) {
	        totalMoney[i]+=money;
	    }
	}
	for (int i=0;i<T;i++)
	    cout<<"\n"<<totalMoney[i];
	return 0;
}
