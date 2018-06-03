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
int a[N];
namespace seg {
	const int MX=100000+10;
	struct node {
		int l,r,orr,andd;
		int mid() {return (l+r)/2;}
		int leg() {return r-l+1;}
	} p[MX<<2];
	void init() {
		memset(p,0,sizeof(p));
	}
	void pushup(int rt) {
		p[rt].orr=p[rt<<1].orr|p[rt<<1|1].orr;
		p[rt].andd=p[rt<<1].andd&p[rt<<1|1].andd;
	}
	void build(int l,int r,int rt) {
		p[rt].l=l;
		p[rt].r=r;
        cout<<l<<" "<<r<<endl;
		if(l==r) {
			p[rt].orr=a[l];
			p[rt].andd=a[l];
			return ;
		}
		int m=p[rt].mid();
		build(lson);
		build(rson);
		pushup(rt);
	}
	int queryor(int l,int r,int rt) {
		if(l==p[rt].l&&r==p[rt].r) {
			return p[rt].orr;
		}
		int m=p[rt].mid();
		int ans=0;
		if(r<=m) ans|=queryor(l,r,rt<<1);
		else if(l>m) ans|=queryor(l,r,rt<<1|1);
		else {
			ans|=queryor(l,m,rt<<1);
			ans|=queryor(m+1,r,rt<<1|1);
		}
		return ans;
	}
	int queryand(int l,int r,int rt) {
		if(l==p[rt].l&&r==p[rt].r) {
			return p[rt].andd;
		}
		int m=p[rt].mid();
		int ans=0;
		if(r<=m) ans&=queryand(l,r,rt<<1);
		else if(l>m) ans&=queryand(l,r,rt<<1|1);
		else {
			ans&=queryand(l,m,rt<<1);
			ans&=queryand(m+1,r,rt<<1|1);
		}
		return ans;
	}
}
int xo;
int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
#endif
	int n,q;
	while(~rdd(n,q)) {
		for(int j=1; j<=n; j++) rd(a[j]);
		xo=a[1];
		for(int j=2; j<=n; j++) xo^=a[j];
		seg::init();
		seg::build(1,n,1);
		int tmp;
		for(int j=1; j<=q; j++) {
			rd(tmp);
			int a1,a2,a3;
			a1=seg::queryand(1,tmp-1,1)&seg::queryand(tmp+1,n,1);
			a2=seg::queryor(1,tmp-1,1)|seg::queryor(tmp+1,n,1);
			a3=xo^a[tmp];
			printf("%d %d %d\n",a1,a2,a3);
		}
	}
#ifndef ONLINE_JUDGE
	printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
#endif
}
