#include <iostream>
#include <set>
using namespace std;
set<int> st;
main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		st.insert(x);
	}
	cout<<st.size()<<endl;
	set<int>::iterator p;
	for(p=st.begin();p!=st.end();p++)cout<<*p<<" ";
}
