#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n+1],dp[n+1];
	for(int i=1; i<=n; i++) cin>>a[i];
	memset(dp , 1000000, sizeof(dp));
	dp[1]=0;
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=k; j++)
		{
			if(i-j>=1)
			dp[i]=min(dp[i], dp[i-j]+abs(a[i]-a[i-j]));
		}
	}
	cout<<dp[n];
}
