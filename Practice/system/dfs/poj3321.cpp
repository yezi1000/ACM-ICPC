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
#define mo 1000000007
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
namespace bitt {
const int MX=300000+10;
int c[MX],n;
void init(int x) {
	memset(c,0,sizeof(c));
    n=x;
}
int lowbit(int x) {
	return x&(-x);
}
void update(int x,int u) {
	while (x<=n) {
		c[x]=(c[x]+u);
		x+=lowbit(x);
	}
}
int sum(int x) {
	int sum=0;
	while (x>0) {
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}
int getsum(int l,int r) {
	return sum(r)-sum(l-1);
}
} // binary indexed tree
const int N=300000+10;
int dep[N],r[N];
bool ha[N];
int cnt,head[N],tot;
struct node { //p[j]记录j点子树(包括自己)在dfs序中的下标集合(1起)
	int l,r;
} p[N];
struct Edge{
    int v,next;
}edge[N];
void add(int u,int v,int &k){
    edge[k].v=v,edge[k].next=head[u],head[u]=k++;
}
void init(){
    memset(head,-1,sizeof(head));
	memset(dep,0,sizeof(dep));
    cnt=0;
    tot=0;
}
void dfs(int n) {
	dep[n]=dep[r[n]]+1;
	p[n].l=++cnt;
	for(int k=head[n];k!=-1;k=edge[k].next) dfs(edge[k].v);
	p[n].r=cnt;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("F:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
	int n;
	int _,__;
	while (~scanf("%d",&n)) {
        init();
		for (int j=1; j<n; j++) {
			scanf("%d",&_);
			r[j]=_;
		}
		//for(int j=1;j<=n;j++)scanf("%d",&a[j]);
		dfs(1);
		bitt::init(n);
        for(int j=1;j<=n;j++){
            ha[j]=true;
            bitt::update(p[j].l,1);
        }
		int q;
		scanf("%d",&q);
		while (q--) {
			char s[10];
			int x;
			scanf("%s%d",s,&x);
			if (s[0]=='Q')
				printf("%d\n",bitt::getsum(p[x].l,p[x].r));
			else {
				if (ha[x]==true) bitt::update(p[x].l,-1);
				else bitt::update(p[x].l,1);
				ha[x]=!ha[x];
			}
		}
	}
	return 0;
}