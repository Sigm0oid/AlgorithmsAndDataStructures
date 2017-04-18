#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll wasted=0;
ll nb_bottle,nb_moves;
 ll capacity[100010];
 ll current_capacity[100010];
 ll to_add[100010];

 void add(ll y,ll x ){
 if(x>=nb_bottle)
     {
        wasted=y;
        return;
     }
 y+=to_add[x];
 ll to_add=min(capacity[x]-current_capacity[x],y);
 current_capacity[x]+=to_add;
 y-=to_add;
 //cout<<" new y "<<y<<endl;
 add(y,x+1);
return;
 }

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--){
    wasted=0;
       scanf("%lld %lld",&nb_bottle,&nb_moves);
        memset(current_capacity,0,sizeof current_capacity);
        memset(capacity,0,sizeof capacity);
        memset(to_add,0,sizeof to_add);
            for(ll i=0;i<nb_bottle;i++)
            scanf("%lld",&capacity[i]);
                for(ll i=0;i<nb_moves;i++){
                    ll x,y;
                    scanf("%lld %lld",&x,&y);
                    to_add[x-1]+=y;
                }
    add(0,0);
    printf("%lld\n",wasted);
    for(ll i=0;i<nb_bottle;i++)
    {
    printf("%lld",current_capacity[i]);
    if(i!=nb_bottle-1)
    printf(" ");
    }
    printf("\n");
    }
    return 0;
}
