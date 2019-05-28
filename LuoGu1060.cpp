#include <iostream>
#define maxn 30000+5
using namespace std;
struct good
{
	int price;
	int value;
};
struct good goods[maxn];
int m,n;
int num,ans,tmpvalue,tmpprice;
void DFS(int k)
{
	if(k>=n)
		{
			if(tmpvalue>ans)
				ans=tmpvalue;
			return;
		}

	DFS(k+1);
	if(tmpprice+goods[k].price>m)
		{
			if(tmpvalue>ans)
				ans=tmpvalue;
			return;
		}
	else
	{
		tmpprice+=goods[k].price;
		tmpvalue+=goods[k].value;
		DFS(k+1);
		tmpprice-=goods[k].price;
		tmpvalue-=goods[k].value;
	}
}
int main(void)
{
	cin>>m>>n;
	for(int i=0;i<n;i++)
	{
		cin>>goods[i].price>>num;
		goods[i].value=num*goods[i].price;
	}
	DFS(0);
	cout<<ans<<endl;
}
