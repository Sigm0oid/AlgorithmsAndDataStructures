#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,k1,k2;
vector<ll> s1;
vector<ll> s2;

ll dp[7010][2];
vector<ll> vis;
ll solve(ll pos,int player){


    if(pos==1)
    return 2LL;


    if(dp[pos][player]!=-1){
     if(dp[pos][player]==1)
     return 1LL;
     if(dp[pos][player]==0)
     return 2LL;
     if(dp[pos][player]==2)
     return 0LL;

    }
    if(vis[pos]==1) return 1LL;
    vis[pos]=1;

    ll res=0;
    if(player==0){
        for(ll i=0;i<s1.size();i++){
        ll next=(pos+s1[i]);
        if(next>n)
        next%=n;
        res=max(res,solve(next,1-player));
        }
    }
    else{
        for(ll i=0;i<s2.size();i++){
                ll next=(pos+s2[i]);
                if(next>n)
                next%=n;
             res=max(res,solve(next,1-player));
        }
    }
        vis[pos]=0;
      dp[pos][player]=res;
      if(dp[pos][player]==1)
        return 1LL;
     if(dp[pos][player]==0)
        return 2LL;
     if(dp[pos][player]==2)
        return 0LL;




}

int main()
{
    memset(dp,-1,sizeof dp);

    cin>>n;
    vis.resize(n+1);
    cin>>k1;
    for(ll i=0;i<k1;i++){
    ll x;
    cin>>x;
    s1.push_back(x);
    }
    cin>>k2;
    for(ll i=0;i<k2;i++){
    ll x;
    cin>>x;
    s2.push_back(x);
    }
    vector<string> res1;
    vector<string> res2;
    for(ll i=2;i<=n;i++){
        ll tmp1=solve(i,0);
        ll tmp2=solve(i,1);

        if(tmp1==0) res1.push_back("Win");
        if(tmp1==2) res1.push_back("Lose");
        if(tmp1==1) res1.push_back("Loop");

        if(tmp2==0) res2.push_back("Win");
        if(tmp2==2) res2.push_back("Lose");
        if(tmp2==1) res2.push_back("Loop");
    }
    for(ll i=0;i<res1.size();i++)
    cout<<res1[i]<<" ";
    cout<<endl;

    for(ll i=0;i<res2.size();i++)
    cout<<res2[i]<<" ";
    cout<<endl;

    return 0;
}

