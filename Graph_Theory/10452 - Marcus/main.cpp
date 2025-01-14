#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m;
bool found=false;
string pat="IEHOVA#";
string res="";
vector<string> mat;
bool inbound(ll x,ll y){
    return (x>=0&&y>=0&&x<n&&y<m);
}
int xi[3]={-1,0,0};
int yi[3]={0,1,-1};

void dfs(ll x,ll y,ll pos,string path){

if(pos==7)
{
    found=true;
    res=path;
    return ;
}
if(found){return;}

for(int i=0;i<3;i++){
    ll a=x+xi[i];
    ll b=y+yi[i];
    if(inbound(a,b)&&mat[a][b]==pat[pos]){
    string tmp=path;
    if(i==0)
    tmp+=" forth";
    if(i==1)
    tmp+=" right";
    if(i==2)
    tmp+=" left";
    dfs(a,b,pos+1,tmp);
    }

}
}

int main()
{

    ll t;
    cin>>t;
    ll x,y;
    while(t--){
    found=false;
    mat.clear();
    res="";
    cin>>n>>m;
    string s;
    for(int j=0;j<n;j++){
    cin>>s;
    mat.push_back(s);
    for(ll i=0;i<s.length();i++){
        if(s[i]=='@')
        x=j,y=i;
    }
    }
    dfs(x,y,0,"");
    for(ll i=1;i<res.length();i++)
    cout<<res[i];
    cout<<endl;
    }
    return 0;
}
