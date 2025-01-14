#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<vii> Adjlist;
vector<ll> strengths,vis;
ll n,k,d;
set<ll> stations;
map<ii,ll> roads;
set<ll> res;
vector<ll> parent;

void bfs(ll s){
//cout<<"bfs"<<endl;
vis[s]=1;
queue<ii> q;
q.push(ii(s,0));
while(!q.empty()){
    ii u=q.front();
    q.pop();
    if(u.second>k)
    continue;
    for(ll i=0;i<Adjlist[u.first].size();i++){
        ll v=Adjlist[u.first][i].first;

        if(vis[v]==1&&v!=parent[u.first]){
        res.insert(roads[ii(min(v,u.first),max(v,u.first))]);
        }
        else if(vis[v]==0){
        vis[v]=1,parent[v]=u.first,q.push(ii(v,u.second+1));
        }
    }
}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>k>>d;
    Adjlist.resize(n);
    vis.resize(n);
    parent.resize(n);
    for(ll i=0;i<k;i++){
    ll x;
    cin>>x;
    x--;
    stations.insert(x);
    }
    for(ll i=1;i<=(n-1);i++){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    Adjlist[a].push_back(ii(b,1));
    Adjlist[b].push_back(ii(a,1));
    roads[ii(min(a,b),max(a,b))]=i;
    }
    for(auto i=stations.begin();i!=stations.end();i++){
        parent.assign(n,-1
        );
        bfs(*i);
    }
    cout<<res.size()<<endl;
    for(auto i=res.begin();i!=res.end();i++){
        cout<<(*i)<<" ";
    }
    return 0;
}
