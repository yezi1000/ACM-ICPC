#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include <fstream>
#include<map>
#include<set>
#include<vector>
#define mp make_pair
#define eps 1e-8
#define pb push_back
#define PII pair<int,int>
#define VI vector<int>
#define X first
#define Y second
#define CL(a) memset(a,0,sizeof a)
#define SZ(x) ((int)(x).size())
#define rd(x) scanf("%d",&x)
#define rdd(x,y) scanf("%d%d",&x,&y)
#define rddd(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pr(x) printf("%d",x)
#define prn(x) printf("%d\n",x)
typedef unsigned long long ull;
typedef long long ll;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,a-2,p);}
using namespace std;
const int N=5004;
ll dp[N][N];
ll a[N];
int main () {
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif

	int n;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) 
		cin>>a[i];
	for(int i=1; i<=n; i++) 
		dp[1][i]=a[i];
	for(int i=2; i<=n; i++) 
		for(int j=1; j<=n-i+1; j++) 
			dp[i][j]=dp[i-1][j]^dp[i-1][j+1];
	for(int i=2; i<=n; i++)
		for(int j=1; j<=n-i+1; j++)
			dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j+1]));
	int q;
	cin>>q;
	while(q--) {
		int l,r;
		cin>>l>>r;
		cout<<dp[r-l+1][l]<<endl;
	}
	return 0;
}