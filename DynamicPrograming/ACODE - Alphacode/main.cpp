#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;
string tab[26]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","19","20","21","22","23","24","25","26","1"};
ll dp[5010];
ll calcul(int pos){
if(s[pos]=='0')
return 0;

if(pos>=s.length()-1)
return 1;

if(dp[pos]!=-1)
return dp[pos];
ll res=0;



    ///read the current as alone
res+=(calcul(pos+1));

if((s[pos+1]-'0'<7&&s[pos]=='2')||(s[pos]=='1')){
///can be readed differently
res+=(calcul(pos+2));

}

return dp[pos]=res;
}
int main()
{


    while(cin>>s&&s!="0"){
    memset(dp,-1,sizeof dp);
    cout<<calcul(0)<<endl;
    }
    return 0;
}
