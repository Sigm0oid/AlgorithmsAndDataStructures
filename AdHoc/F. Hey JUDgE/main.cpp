#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;
bool ok;
bool valid(vector<int> prob){
return (prob[1]>0&&prob[2]>0&&prob[3]>0&&prob[4]>0&&prob[5]>0);
}
void isibizi(vector<int> prob){


if(valid(prob)){

ok=true;
return ;
}

if(ok)
return ;

    for(int i=1;i<6;i++){
        for(int j=1;j<6;j++){
            if(i==j&&(i+j)<6){
                //cout<<" cc "<<i<<endl;
                if(prob[i]>1){
                prob[i]-=2;
                prob[i+i]++;
                isibizi(prob);
                prob[i+i]--;
                prob[i]+=2;
                }
            }else{

                    if(prob[i]>0&&prob[j]>0&&(i+j)<6)
                        {
                            prob[i]--;
                            prob[j]--;
                            prob[i+j]++;
                            isibizi(prob);
                            prob[i+j]--;
                            prob[i]++;
                            prob[j]++;

                        }
                    }

        }
    }

}
int main()
{
        ll  t;
        scanf("%lld",&t);
        while(t--){
        ok=false;
        cin>>s;
        vector<int> tab;
        tab.resize(6);
        for(int i=0;i<7;i++)
        tab[s[i]-'A'+1]++;
        isibizi(tab);
        if(ok)
        cout<<"YES\n";
        else
        cout<<"NO\n";
        }
    return 0;
}
