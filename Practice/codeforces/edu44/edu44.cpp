#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<cstring>
#define eps 1e-8
#define pi acos(-1)
#define mp make_pair
#define PH push
#define pb push_back
#define PII pair<ll,ll>
#define VI vector<int>
#define fi first
#define se second
#define N(a,b) a=N(a,b)
#define Min(a,b) a=min(a,b)
#define sqr(x) ((x)*(x))
#define CL(a) memset(a,0,sizeof a)
#define fr(i,n) for(int i=1;i<=n;i++)
#define FR(i,S,n) for(int i=S;i<=n;i++)
#define dr(i,n) for(int i=n;i;i--)
#define DR(i,n,S) for(int i=n;i>=S;i--)
#define SZ(x) ((int)(x).size())
#define all(n) n.begin(),n.end()
#define rd(x) scanf("%d",&x)
#define pr(x) printf("%d",x)
#define prn(x) printf("%d\n",x)
typedef long long ll;
typedef unsigned long long ull;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
#define mo 1000000007
VI a;
int main () {
	int n,k,l;
	rd(n);
	rd(k);
	rd(l);
	int t=n*k;
	for (int j=0; j<t; j++) {
		int tmp;
		rd(tmp);
		a.pb(tmp);
	}
	sort(a.begin(),a.end());
	int cnt=upper_bound(a.begin(),a.end(),a[0]+l)-a.begin();
	ll ans=0;
	if (cnt<n)return 0*puts("0");
	for (int i=1; i<=n; ++i)ans+=a[min(cnt-i,(n-i)*k)];
	cout<<ans;
	return 0;
}