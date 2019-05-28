#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=20+5;
struct number
{
	string num;
};
struct number numbers[maxn];
struct Rule
{
	bool operator()(const number& n1,const number& n2)
	{
		return n1.num+n2.num>n2.num+n1.num;
	}
};
int n;
int main(void)
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>numbers[i].num;
	sort(numbers,numbers+n,Rule());
	for(int i=0;i<n;i++)
		cout<<numbers[i].num;
}
