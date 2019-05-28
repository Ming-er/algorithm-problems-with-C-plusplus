#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=35;
int v,n;
int vol[maxn];
int ans=0;
int sum=0;
void DFS(int num)
{
	if(num==n)
	{
		ans=max(ans,sum);
		return;
	}
	DFS(num+1);
	if(sum+vol[num]>v)
	{
		ans=max(ans,sum);
		return;
	}
	sum+=vol[num];
	DFS(num+1);
	sum-=vol[num];
}
int main(void)
{
	cin>>v>>n;
	for(int i=0;i<n;i++)
		cin>>vol[i];
	DFS(0);
	cout<<v-ans<<endl;
}
