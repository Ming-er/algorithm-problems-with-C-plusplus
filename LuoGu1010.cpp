#include <iostream>
using namespace std;
int pow(int a,int b)
{
    int ans=1;
    for(int i=0;i<b;i++)
        ans*=a;
    return ans;
}
void DFS(int x)
{
    int num;
    for(int i=0;i<=15;i++)
        {
            num=i;
            if(pow(2,num)>x)
                {
                    num--;
                    break;
                }
        }
    if(num==0)
        cout<<"2(0)";
    else if(num==1)
        cout<<"2";
    else
    {
        cout<<"2(";
        DFS(num);
        cout<<")";
    }
    if(pow(2,num)!=x)
    {
        cout<<"+";
        DFS(x-pow(2,num));
    }

}
int main(void)
{
    int x;
    cin>>x;
    DFS(x);
}
