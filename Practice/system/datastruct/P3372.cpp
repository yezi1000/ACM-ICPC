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
#define rdd(x,y) scanf("%d%d",&x,&y)
#define rddd(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pr(x) printf("%d",x)
#define prn(x) printf("%d\n",x)
typedef long long ll;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
const int N=100000+10;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
namespace seg{//区间修改区间查值
    const int MX=100000+10;
    struct node{
        int l,r;
        ll val,laz;
        int mid(){return (r+l)/2;}
        int leg(){return (r-l+1);}
    }p[MX<<2];
    void init(){
        memset(p,0,sizeof(p));
    }
    void pushup(int rt){
        p[rt].val=p[rt<<1].val+p[rt<<1|1].val;
    }
    void pushdown(int rt,int n){
        if(p[rt].laz){
            p[rt<<1|1].laz+=p[rt].laz;
            p[rt<<1].laz+=p[rt].laz;
            p[rt<<1].val+=p[rt].laz*(n-(n>>1));
            p[rt<<1|1].val+=p[rt].laz*(n>>1);
            p[rt].laz=0;
        }
    }
    void build(int l,int r,int rt){
        p[rt].l=l;p[rt].r=r;p[rt].laz=0;
        if(l==r){
            scanf("%lld",&p[rt].val);
            return ;
        }
        int m=p[rt].mid();
        build(lson);
        build(rson);
        pushup(rt);
    }
    void update(int c,int l,int r,int rt){
        if(p[rt].l==l&&p[rt].r==r){
            p[rt].laz+=c;
            p[rt].val+=1LL*c*(p[rt].leg());
            return ;
        }
        if(p[rt].l==p[rt].r) return ;
        pushdown(rt,p[rt].leg());
        int m=p[rt].mid();
        if(r<=m) update(c,l,r,rt<<1);
        else if(l>m) update(c,l,r,rt<<1|1);
        else{
            update(c,l,m,rt<<1);
            update(c,m+1,r,rt<<1|1);
        }
        pushup(rt);
    }
    ll query(int l,int r,int rt){
        if(l=p[rt].l&&r==p[rt].r)return p[rt].val;
        pushdown(rt,p[rt].leg());
        int m=p[rt].mid();
        ll res=0;
        if(r<=m) res+=query(l,r,rt<<1);
        else if(l>m) res+=query(l,r,rt<<1|1);
        else{
            res+=query(l,m,rt<<1);
            res+=query(m+1,r,rt<<1|1);
        }
        return res;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n,m;
    rdd(n,m);
    int tmp;
    int l,r,k,op;
    seg::init();
    seg::build(1,n,1);
    while(m--){
        rd(op);
        if(op==1){
            rddd(l,r,k);
            seg::update(k,l,r,1);
        }
        else{
            rdd(l,r);
            printf("%lld\n",seg::query(l,r,1));
        }
    }
    return 0;
}
