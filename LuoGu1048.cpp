#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=100+5;
const int maxm=1000+5;
int ti,n;
int dp[maxn][maxm];
struct medicine
{
	int t;
	int v;
};
struct medicine medicines[maxn];
int main(void)
{
	cin>>ti>>n;
	for(int i=1;i<=n;i++)
		cin>>medicines[i].t>>medicines[i].v;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=ti;j++)
		{
			if(j-medicines[i].t>=0)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-medicines[i].t]+medicines[i].v);
			else dp[i][j]=dp[i-1][j];
		}
	cout<<dp[n][ti]<<endl;
}
