#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tab[60];
int main()
{
    memset(tab,0,sizeof tab);
    string s;
    map<char,ll> dict;
    cin>>s;
    for(ll i=0;i<s.length();i++){
    if(s[i]>'Z')
    tab[s[i]-'a']++;
    else
    tab[s[i]-'A'+26]++;
    dict[s[i]]++;
    }
    ll res=0;
    while(tab[27]>0&&tab['l'-'a']>0&&tab['u'-'a']>1&&tab[1]>0&&tab[0]>1&&tab['r'-'a']>0&&tab['s'-'a']>0){

    res++;
    tab[27]--;
    tab['l'-'a']-=1;
    tab['u'-'a']-=2;
    tab[1]-=1;
    tab[0]-=2;
    tab['r'-'a']-=1;
    tab['s'-'a']-=1;
    }

        cout<<res<<endl;
        return 0;
}
