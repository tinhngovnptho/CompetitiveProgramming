#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long n,k,sott,tong=0,soht;
 cin>>n>>k;
 soht=n;
 tong=n*2;
 sott=n;
 for (int i=2;i<=k;i++)
 {
  sott=soht*2+tong-sott;
  tong=tong+sott;
  tong%=1000000007;
  soht=sott;
 }
 cout<<tong;
}
