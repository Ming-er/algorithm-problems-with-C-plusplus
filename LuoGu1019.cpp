#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <iomanip>
#include <sstream>
#include <queue>
using namespace std;
#define _for(i,a,b) for(size_t i=(a);i<(b);i++)
#define _rep(i,a,b) for(size_t i=(a);i<=(b);i++)
template<typename T>
ostream& operator<<(ostream& os,const vector<T> &v)
{
    _for(i,0,v.size())
    os<<v[i]<<" ";
    return os;
}
template<typename T>
ostream& operator<<(ostream& os,const set<T> & st)
{
    const auto it=st.begin();
    for(;it!=st.end();it++)
    os<<*it<<" ";
    return os;
}
inline int readint()
{
    int x;
    scanf("%d",&x);
    return x;
}
const int maxn=30+5;
char ch;
int n;
string word[maxn];
int num[maxn][maxn];
int sum=0;
int ans=0;
int vis[maxn];
int match(int i,int j)
{

    bool pp=true;
    int ky=0;
    for(int k=word[i].size()-1;k>=0;k--){
        for(int kx=k;kx<word[i].size();kx++){
            if(word[i][kx]!=word[j][ky++]){
                pp=false;
                break;
            }
        }
        if(pp==true){
            return word[i].size()-k;        }
        ky=0;
        pp=true;//不行就继续
    }
    return 0;

}
void DFS(int t)
{
    bool flag=false;
    _for(i,0,n)
    {
        if(num[t][i]!=0&&vis[i]<2)
        {
            flag=true;
            sum+=(word[i].size()-num[t][i]);
            vis[i]++;
            //cout<<i<<" "<<word[i]<<endl;
            DFS(i);
            vis[i]--;
            sum-=(word[i].size()-num[t][i]);
        }
    }
    if(!flag)
    ans=max(ans,sum);
    return;
}
int main(void)
{
    n=readint();
    _for(i,0,n)
    cin>>word[i];
    _for(i,0,n)
    _for(j,0,n)
    num[i][j]=match(i,j);
    cin>>ch;
    memset(vis,0,sizeof(vis));
    _for(i,0,n)
    {
        if(ch==word[i][0])
        {
            sum=word[i].size();
            vis[i]++;
            DFS(i);
            vis[i]--;
            sum=0;
        }
    }
    /*_for(i,0,n)
    {
        _for(j,0,n)
        cout<<num[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<ans<<endl;
}
