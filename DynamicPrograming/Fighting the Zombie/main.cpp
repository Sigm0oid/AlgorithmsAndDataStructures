#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int h,s;
iii convert_spell(string a){
iii spell;
int x=0,y=0,z=0;
int i=0;
string tmp="";
while(a[i]!='d'){
tmp+=a[i];
i++;
}
x=(atoi)(tmp.c_str());
i++;
tmp="";
while(a[i]!='+'&&a[i]!='-'&&i<a.length()){
tmp+=a[i];
i++;
}
y=(atoi)(tmp.c_str());
if(i==a.length())
z=0;
else{
    tmp="";
    for(int j=i;j<a.length();j++){
        tmp+=a[j];
    }
    z=(atoi)(tmp.c_str());
}
spell.first=x;
spell.second.first=y;
spell.second.second=z;
return spell;
}


double match(int x,int y,int required,int actual){
cout<<"x ="<<x<<" y= "<<y<<"actual ="<<actual<<" req="<<required<<endl;
if(x==0)
return (actual>=required);
if (actual>=required)
return (double)pow(y,x);
if(actual+(y*x)<required)
return 0;
//if((actual+x)>=required)
//return pow(y,x);
double res=0;
for(int i=1;i<=y;i++){
res+=match(x-1,y,required,actual+i);
}
return res;
}
double getprob(iii spell){
int required=h;
required-=spell.second.second;
//cout<<"  good proba "<<match(spell.first,spell.second.first,required,0)<<" all  ones "<<pow(spell.second.first,spell.first)<<endl;
return (double)match(spell.first,spell.second.first,required,0)/pow(spell.second.first,spell.first);

}


int main()
{
    freopen("fighting_the_zombie.txt","r",stdin);
    //freopen("fighting_the_zombie_output.txt","w",stdout);
    int t;
    cin>>t;
    double  prob_win=0;
    for(int j=0;j<t;j++){
    prob_win=0;
    cin>>h>>s;
    vector<iii>spells;

        for(int i=0;i<s;i++){
        string a;
        cin>>a;
        spells.push_back(convert_spell(a));
        cout<<"calculating for x= "<<spells[i].first<<" y="<<spells[i].second.first<<endl;
        prob_win=max(prob_win,getprob(spells[i]));

        }




    printf("Case #%d: %.6f\n",j+1,prob_win);
    }
    return 0;
}
