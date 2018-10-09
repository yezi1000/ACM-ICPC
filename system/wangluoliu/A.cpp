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
#define eps 1e-5
#define pi acos(-1)
#define mp make_pair
#define PH push
#define pb push_back
#define PII pair<int,int>
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
#define rd(x) scanf("%d",&x)
#define rdd(x,y) scanf("%d%d",&x,&y)
#define rddd(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define rl(x) scanf("%lld",&x)
#define rll(x,y) scanf("%lld%lld",&x,&y)
#define rlll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define pr(x) printf("%d",x)
#define prn(x) printf("%d\n",x)
typedef long long ll;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
const int N=100000+10;
const int mo=1e9+7;
#define maxn 110
#define maxm 5050
#define ll long long
#define inf (1ll<<55)
struct dinic{
	int la[maxn],cur[maxn],tot,d[maxn],s,t;
	queue<int>q;ll flow;
	struct edge{int v,ne,f;}e[maxm<<1];
	inline void add(int u,int v,int f){
		e[tot].v=v,e[tot].ne=la[u],e[tot].f=f,la[u]=tot++;
		e[tot].v=u,e[tot].ne=la[v],e[tot].f=0,la[v]=tot++;
	}
	void init(){tot=flow=0;memset(la,-1,sizeof(la));}
	inline bool bfs(){
		memset(d,0,sizeof(d));
		q.push(s);d[s]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=la[u];~i;i=e[i].ne){
				int v=e[i].v,f=e[i].f;
				if(d[v]||!f)continue;
				d[v]=d[u]+1;
				if(v==t){while(!q.empty())q.pop();return 1;}
				q.push(v);
			}
		}
		return d[t]!=0;
	}
	inline ll dfs(int u,ll a){
		if(!a||u==t)return a;
		ll sum=0;
		for(int &i=cur[u];~i;i=e[i].ne){
			int v=e[i].v,f=e[i].f;
			if(d[v]!=d[u]+1||!f)continue;
			ll tmp=dfs(v,min(a-sum,(ll)f));
			e[i].f-=tmp,e[i^1].f+=tmp,sum+=tmp;
			if(sum>=a)return a;
		}
		if(!sum)d[u]=0;
		return sum;
	}
	inline void maxflow(){
		while(bfs()){
			for(int i=1;i<=n;++i)cur[i]=la[i];
			flow+=dfs(s,inf);
		}
	}
}dinic; 
void init(){
	n=getint(),m=getint();dinic.init();
	dinic.s=getint(),dinic.t=getint();
	for(int i=1;i<=m;++i){
		int u=getint(),v=getint(),f=getint();
		dinic.add(u,v,f);
	}
}
void solve(){
	dinic.maxflow();
	printf("%lld\n",dinic.flow);
}
int main(){
	init();
	solve();
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
#endif
#ifndef ONLINE_JUDGE
	printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
#endif
}
