#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[65][10];
ll n;
ll solve(ll x,ll start){
    if(x==1)
    return 10-start;
    if(dp[x][start]!=-1)
    return dp[x][start];
    ll res=0;
    for(int i=start;i<10;i++){
    res+=solve(x-1,i);
    }
return dp[x][start]=res;

}

int main()
{

    int T;
    cin>>T;
    memset(dp,-1,sizeof dp);
    while(T--){

    int nb_test;
    cin>>nb_test;
    cin>>n;
    cout<<nb_test<<" "<<solve(n,0)<<endl;
    }
    return 0;
}