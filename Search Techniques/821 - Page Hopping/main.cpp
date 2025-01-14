#include <bits/stdc++.h>
#define INF 100000
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int Adjmat[110][110];
int nb_nodes=0;
int a,b;
int choose(int n, int k) {
    if (k > n) {
        return 0;
    }
    int  r = 1;
    for (int d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}
void warshall(){

    for(int k=0;k<110;k++)
    for(int i=0;i<110;i++)
    for(int j=0;j<110;j++)
    Adjmat[i][j]=min(Adjmat[i][j],Adjmat[i][k]+Adjmat[k][j]);



}
int main()
{
    int t=0;

    while(cin>>a>>b&&(a>0&&b>0)){
    for(int i=0;i<110;i++)
    for(int j=0;j<110;j++)
    if(i==j)
    Adjmat[i][j]=0;
    else
    Adjmat[i][j]=INF;

    t++;
    map<int,int> nodes;
    int x,y;
    Adjmat[a-1][b-1]=1;
        nodes[a-1]++;
        nodes[b-1]++;
    while(cin>>x>>y&&x>0&&y>0){
        x--;
        y--;
        Adjmat[x][y]=1;
        nodes[x]++;
        nodes[y]++;
    }
    nb_nodes=nodes.size();
    warshall();
    int somme=0;
    for(int i=0;i<110;i++)
    for(int j=0;j<110;j++)
    if(Adjmat[i][j]<110&&i!=j){
    somme+=Adjmat[i][j];
    }
    //cout<<somme<<endl;

    double avg=(somme/(2.0*choose(nb_nodes,2)));
    printf("Case %d: average length between pages = %.3f clicks\n",t,avg);}

    return 0;
}
