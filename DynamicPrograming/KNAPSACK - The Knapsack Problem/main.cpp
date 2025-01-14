#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll s,n;
vector<pair<ll,ll> > items;
ll dp[2010][2010];
ll knap (ll pos,ll capacity){
if(capacity<0)
return LLONG_MIN;

if(capacity==0)
return 0;
if(pos>=n)
return 0;

if(dp[pos][capacity]!=-1)
return dp[pos][capacity];

return dp[pos][capacity]=max(items[pos].second+knap(pos+1,capacity-items[pos].first),knap(pos+1,capacity));


}

int main()
{
    cin>>s>>n;
    for(ll i=0;i<n;i++){
    ll a,b;
    cin>>a>>b;
    items.push_back(ii(a,b));
    }
    memset(dp,-1,sizeof dp);
    cout<<knap(0,s)<<endl;
    return 0;
}
