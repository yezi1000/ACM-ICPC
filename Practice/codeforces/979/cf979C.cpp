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
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
const int N=100000+10;
const int M=3*N;
ll n, A, B, noa, nob;
ll to[M], nxt[M], first[N], cnt;
ll sz[N], fa[N];
ll read() {
	ll x = 0, f = 1;    char ch = getchar();
	while(ch <  '0' || ch >  '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10 + ch - '0';ch = getchar();}
	return x*f;
}
void ins(int u, int v) {
	to[++cnt] = v, nxt[cnt] = first[u], first[u] = cnt;
}
void dfs(int u, int f) {
	sz[u] = 1; fa[u] = f;
	for(int i = first[u]; i; i = nxt[i]) {
		if(to[i] == f ) continue;
		dfs(to[i], u);
		sz[u] += sz[to[i]];
	}
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //ios::sync_with_stdio(false);
    n = read(); A = read(); B = read();
	for(int i = 1; i <= n - 1; ++i) {
		int x, y;
		x = read(); y = read();
		ins(x, y);	ins(y, x);
	}
	dfs(B, 0);
	ll t = A;
	while(fa[t] != B) t = fa[t];
	cout<<n*(n - 1) - sz[A]*(n - sz[t])<<endl;
	return 0;
}