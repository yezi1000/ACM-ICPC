#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<stack>
#include<time.h>
#include<map>
#include<cstring>
#define eps 1e-8
#define pi acos(-1)
#define mp make_pair
#define PH push
#define pb push_back
#define PII pair<int,int>
#define VI vector<int>
#define fi first
#define se second
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
const int N=100000+10;
int last[N];
int ans[N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int T;
    scanf("%d",&T);
	while (T--) {
		int n, m;
		scanf("%d%d",&n,&m);
		for (int i = 1; i <= n; i++)
			last[i] = i;
		int l, r;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d",&l,&r);
			last[l] = max(last[l],r);
		}
		set <int> vis;
		for (int i = 1; i <= n; i++) vis.insert(i);
		l = 1, r = 0;
		for (int i = 1; i <= n; i++) {
			if (r > last[i]) continue;
			while (l < i) {
				vis.insert(ans[l]);
				l++;
			}
			while (r < last[i]) {
				ans[++r] = *vis.begin();
				vis.erase(ans[r]);
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c",ans[i],i==n?'\n':' ');
	}

    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}