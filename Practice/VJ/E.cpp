#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<time.h>
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
#define rdd(x,y) scanf("%d%d",&x,&y)
#define rddd(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pr(x) printf("%d",x)
#define prn(x) printf("%d\n",x)
typedef long long ll;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int N=100000+10;
const int maxn = 1e5 + 10;
int n,m,sum1[maxn],sum2[maxn],sum3[maxn],rsum1[maxn],rsum2[maxn],rsum3[maxn],a[maxn];
int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
#endif
	while(~scanf("%d%d",&n,&m)) {
		scanf("%d",&a[1]);
		sum1[1] = sum2[1] = sum3[1] = a[1];
		for(int i = 2; i <= n; i ++) {
			scanf("%d",&a[i]);
			sum1[i] = sum1[i-1] & a[i];
			sum2[i] = sum2[i-1] | a[i];
			sum3[i] = sum3[i-1] ^ a[i];
		}
		rsum1[n] = rsum2[n] = rsum3[n] = a[n];
		for(int i = n-1; i >= 1; i --) {
			rsum1[i] = rsum1[i+1] & a[i];
			rsum2[i] = rsum2[i+1] | a[i];
			rsum3[i] = rsum3[i+1] ^ a[i];
		}
		int q;
		while(m --) {
			scanf("%d",&q);
			if(q == 1) printf("%d %d %d\n",rsum1[q+1],rsum2[q+1],rsum3[q+1]);
			else if(q == n) printf("%d %d %d\n",sum1[n-1],sum2[n-1],sum3[n-1]);
			else printf("%d %d %d\n",sum1[q-1] & rsum1[q+1],sum2[q-1]|rsum2[q+1],sum3[q-1]^rsum3[q+1]);
		}
	}
#ifndef ONLINE_JUDGE
	printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
#endif
}
