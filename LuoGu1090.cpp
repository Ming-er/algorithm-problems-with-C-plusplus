#include <bits/stdc++.h>
using namespace std;
const int maxn=10000+5;
inline int readint()
{
	int n;
	cin>>n;
	return n;
}
int n,ans;
priority_queue<int,vector<int>,greater<int> > pq;
int main(void)
{
	n=readint();
	for(int i=0;i<n;i++)
		pq.push(readint());
	while(n!=1)
	{
		int n1=pq.top();
		pq.pop();
		int n2=pq.top();
		pq.pop();
		ans+=(n1+n2);
		pq.push(n1+n2);
		n--;
	}
	cout<<ans;
}
