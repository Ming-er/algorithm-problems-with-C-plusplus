#include <iostream>
#include <cstring>
using namespace std;
struct Point
{
    int x;
    int y;
};
typedef long long LL;
const int maxn=25;
LL dp[maxn][maxn];
const int dir1[2][2]={{1,0},{0,1}};
const int dir2[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
bool horse[maxn][maxn];
Point B,C;
inline void gethorse(int x,int y)
{
    horse[x][y]=true;
    for(int i=0;i<8;i++)
        horse[x+dir2[i][0]][y+dir2[i][1]]=true;
    return;
}
int main(void)
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    memset(horse,false,sizeof(horse));
    cin>>B.x>>B.y>>C.x>>C.y;
    gethorse(C.x,C.y);
    for(int i=0;i<=B.x;i++)
        for(int j=0;j<=B.y;j++)
        {
            if(i==0&&j!=0)
                dp[i][j]=dp[i][j-1];
            else if(j==0&&i!=0)
                dp[i][j]=dp[i-1][j];
            else if(i!=0&&j!=0)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]*=(!horse[i][j]);

        }
    cout<<dp[B.x][B.y];
}
