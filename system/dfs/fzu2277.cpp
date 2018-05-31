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
namespace bit {
const int MX=300000+10;
int c[MX],n;
void init(int x) {
	memset(c,0,sizeof(c));
    n=x;
}
int lowbit(int x) {
	return x&(-x);
}
void update(int x,int u) {//单点修改
	while (x<=n) {
		c[x]=(c[x]+u)%mo;
		x+=lowbit(x);
	}
}
void iupdate(int l,int r,int u){//区间修改
    update(l,u);
    update(r+1,-u+mo);
}
int sum(int x) {
	int sum=0;
	while (x>0) {
		sum=(sum+c[x])%mo;
		x-=lowbit(x);
	}
	return sum%mo;
}
int getsum(int l,int r) {
	return sum(r)-sum(l-1);
}
} // binary indexed tree
const int N=300000+10;
struct node{
    int l,r;
}p[N];
vector<int>e[N];
int r[N],a[N],cnt;
int dep[N];
void dfs(int t,int dep){
    p[t].l=++cnt;
    dep[t]=dep;
    for(int j=0;j<(int)e[t].size();j++) dfs(e[t][j],dep+1);
    p[t].r=cnt;
}
int kk;
void up(int v,int x){
    bit::iupdate(p[v].l,p[v].r,x);
    for(int j=0;j<e[v].size();j++) dfs2(e[v][j]);
}
void init(int q){
    bit::init(q);
    for(int j=1;j<=q;j++) e[j].clear();
    cnt=0;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int T;
    scanf("%d",&T);
    //cout<<T<<endl;
    while(T--){
        int n;
        int tx;
        scanf("%d",&n);
        init(n);
        for(int j=2;j<=n;j++){
            scanf("%d",&tx);
            e[tx].pb(j);
            r[j]=tx;
        }
        dfs(1);
        //cout<<"e"<<endl;
        int q,v,x;
        scanf("%d",&q);
        while(q--){
            int t;
            scanf("%d",&t);
            if(t==1){
                scanf("%d%d%d",&v,&x,&kk);
                up(v,x);
            }
            else {
                scanf("%d",&v);
                printf("%d\n",bit::sum(v));
            }
        }
        //cout<<"e"<<endl;
    }
    return 0;
}