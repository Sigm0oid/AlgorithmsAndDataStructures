#include <bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> tmp(366);
    tmp.assign(366,0);

    int T ;
    cin >> T ;
    for (int t=0;t<T;t++)
    {
        set<string> wrong;
        int n ;
        cin >> n ;

        map<string ,vector<int> > mp ;

        for (int i=0;i<n;i++)
        {
            string c ;
            int left,right,v ;
            cin >> c >> left >> right >> v ;
            for (int j=0;j<v;j++)
            {
                string s ;
                cin >> s ;
                if(mp.find(s)==mp.end())
                mp[s]=tmp;

                if(mp[s][left]!=0)
                {
                wrong.insert(s);
                continue;
                }
                if(mp[s][right]!=0)
                {
                wrong.insert(s);
                continue;
                }
                if(left==right)
                mp[s][left]=3;
                else{
                mp[s][left]=1;
                mp[s][right]=2;
                }


            }
        }
        for (auto k =mp.begin();k!=mp.end();k++)
        {
            if(wrong.find(k->first)!=wrong.end())
            continue;

            int current=k->second[0];
            for(int i=1;i<366;i++){
                if(((k->second[i]==1||k->second[i]==3)&&current==1))
                {wrong.insert(k->first);break;}
                if(k->second[i]==2&&current==1)
                current=0;
                if(k->second[i]==1&&current==0)
                current=1;
            }
            //cout<<endl;
        }
        cout<<wrong.size()<<endl;
        for(auto k:wrong)
        cout<<k<<endl;
    }
    return 0;
}
