#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll k,l,m;
ll ni;
int  dp[1000010][2];
bool isibizi(ll n,bool toor ){
if(dp[n][toor]!=-1)
return dp[n][toor];

if(n==k||n==l||n==1)
return dp[n][toor]=toor;

bool try1=1-toor,try2=1-toor,try3=1-toor;
if(n>=k)
try1=isibizi(n-k,1-toor);
if(n>=l)
try2=isibizi(n-l,1-toor);
if(n>=1)
try3=isibizi(n-1,1-toor);
if(try1==toor||try2==toor||try3==toor)
return dp[n][toor]=toor;
return dp[n][toor]=1-toor;
}

int main()
{
    cin>>k>>l>>m;
    memset(dp,-1,sizeof dp);
    while(m--){
    cin>>ni;

    if(isibizi(ni,0))
    cout<<"B";
    else
    cout<<"A";
    }

    cout<<endl;
    return 0;
}
