#include <bits/stdc++.h>
using namespace std;

int main()
{
	char tab[1000];
	for (int i=0;i<1000;i++)
	{
		tab[i]='.' ;
	}
	tab['A']='A';
	tab['E']='3';
	tab['H']='H';
	tab['I']='I';
	tab['J']='L';
	tab['L']='J';
	tab['M']='M';
	tab['O']='O';
	tab['S']='2';
	tab['T']='T';
	tab['U']='U';
	tab['V']='V';
	tab['W']='W';
	tab['X']='X';
	tab['Y']='Y';
	tab['Z']='5';
	tab['1']='1';
	tab['2']='S';
	tab['3']='E';
	tab['5']='Z';
	tab['8']='8';
	tab['0']='0' ;
	string s ;
	while (getline(cin,s)&&s.length()>0)
	{

        bool notp = false,regularp=false ,mirored=false ;
        for(int i=0;i<s.length();i++)
        if(s[i]=='0')
        s[i]='O';
        string s1 = s ;

        reverse(s1.begin(),s1.end());
        if (s==s1)
        regularp=true ;

		string s2;
        for (int i=0;i<s.length();i++)
        {

			s2+=tab[s[i]] ;


        }

        reverse(s2.begin(),s2.end());
        if(s2==s){
        mirored=true;
        }

        if (regularp==true && mirored==true)
			cout << s << " -- is a mirrored palindrome." << endl<<endl ;
		else if (mirored)
			cout << s << " -- is a mirrored string." << endl <<endl;
		else if (regularp)
			cout << s << " -- is a regular palindrome." << endl <<endl;
		else
			cout << s << " -- is not a palindrome." << endl <<endl;
	}
}
