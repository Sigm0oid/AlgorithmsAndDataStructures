#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
vector<vii> Adjlist;
vi vis,depth,fuel,res;
ll n;
ll dis[500010];

void dfs(ll x ,ll dep){
    depth[dep]=x;
    vis[x]=1;
    //if(x!=0)
//    for(ll j=0;j<dep;j++)
//    {
//        if(fuel[depth[dep]]>=dis[dep]-dis[j])
//        res[depth[j]]++;
//    }

    ll l=lower_bound(dis,dis+dep,dis[dep]-fuel[depth[dep]])-dis;
        res[depth[l-1]]--;
        res[depth[dep-1]]++;




    for(ll i=0;i<Adjlist[x].size();i++){
        ii u=Adjlist[x][i];
        if(!vis[u.first]){
        dis[dep+1]=dis[dep]+u.second,dfs(u.first,dep+1);
        res[x]+=res[u.first];
        }

    }


}

int main()
{
 //   freopen("car.in","r",stdin);


    ll t;
    scanf("%lld",&t);
    while(t--){
        Adjlist.clear();
        depth.clear();
        vis.clear();
        fuel.clear();
        memset(dis,0,sizeof dis);
        res.clear();
        scanf("%lld",&n);
        Adjlist.resize(n);
        depth.resize(n);
        vis.resize(n);
        fuel.resize(n);
        res.resize(n);
            for(ll i=0;i<n;i++){scanf("%lld",&fuel[i]);}
            for(ll i=0;i<(n-1);i++){
                ll a,b,c;
                scanf("%lld %lld %lld",&a,&b,&c);
                a--,b--;
                Adjlist[a].push_back(ii(b,c));
                Adjlist[b].push_back(ii(a,c));
                }
    dfs(0,0);
    for(ll i=0;i<n;i++)printf("%lld ",res[i]);
    printf("\n");
    }


    return 0;
}
