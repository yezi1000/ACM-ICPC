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
inline int read(){
    int x=0,f=1;char ch = getchar();
    while('0'>ch||ch>'9'){if('-'==ch)f=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
using namespace std;
const int N=100000+10;

//head end

int n,m,w[N],b[N];

struct node{
    int to,next;
}G[N<<1];
int head[N],tot;


// chairTree begin
const int MN=100000+10;
int rt[MN],ls[MN*20],rs[MN*20],sum[MN*20],chairtree,siz;

void build(int &rt,int l,int r){
    rt=++chairtree;
    sum[rt]=0;
    if(l>=r)return ;
    int m =((r-l)>>1)+l;
    build(ls[rt],l,m);
    build(rs[rt],m+1,r);
}

void update(int& rt,int l,int r,int last,int pos){
    rt=++chairtree;
    ls[rt]=ls[last];
    rs[rt]=rs[last];
    sum[rt]=sum[last]+1;

    if(l>=r) return ;
    int m=((r-l)>>1)+l;
    if(pos<=m) update(ls[rt],l  ,m,ls[last],pos);
    else       update(rs[rt],m+1,r,rs[last],pos);
}

int query(int rt,int l,int r,int last,int lca,int flca,int k){
    if(l>=r) return l;
    int m=((r-l)>>1)+l;
    int cnt=sum[ls[rt]]+sum[ls[last]]-sum[ls[lca]]-sum[ls[flca]];
    if(k<=cnt) query(ls[rt],l  ,m,ls[last],ls[lca],ls[flca],k);
    else       query(rs[rt],m+1,r,rs[last],rs[lca],rs[flca],k-cnt);
}

void dfs(int rt,int l,int r){
    int m = ((r-l)>>1)+l;
    printf("%d",sum[rt]);
    if(l>=r) return ;printf("( ");
    dfs(ls[rt],l,m);printf("_%*d,",2,ls[rt]);
    dfs(rs[rt],m+1,r);printf("_%*d )",2,rs[rt]);
}

//chairTree end

void add(int u,int v){
    G[++tot].to=v,G[tot].next=head[u],head[u]=tot;
    G[++tot].to=u,G[tot].next=head[v],head[v]=tot;
}

int dep[N],fa[N],sz[N],son[N];
void dfs1(int u,int f,int d){
    dep[u]=d,fa[u]=f,sz[u]=1,son[u]=0;
    for(int i=head[u],to;i;i=G[i].next){
        to=G[i].to;
        if(to==f)continue;
        dfs1(to,u,d+1);
        sz[u]+=sz[to];
        if(sz[son[u]]<sz[to])son[u]=to;
    }
}

int tree[N],top[N],pre[N],cnt;
void dfs2(int u,int tp){
    top[u]=tp,tree[u]=++cnt,pre[tree[u]]=u;
    update(rt[u],1,siz,rt[fa[u]],w[u]);
    if(!son[u])return;
    dfs2(son[u],tp);
    for(int i=head[u],to;i;i=G[i].next){
        to=G[i].to;
        if(to==fa[u]||to==son[u])continue;
        dfs2(to,to);
    }
}

int Lca(int x,int y){
    int fx=top[x],fy=top[y];
    while(fx!=fy){
        if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);
        x=fa[fx],fx=top[x];
    }
    if(dep[x]>dep[y])swap(x,y);
    return x;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    n=read(),m=read();
    for(int i=1;i<=n;i++) w[i]=read(),b[i]=w[i];
    for(int i=1;i< n;i++) add(read(),read());
    fa[1]=0;
    sort(b+1,b+n+1);
    siz = unique(b+1,b+n+1)-(b+1);
    for(int i=1;i<=n;i++) w[i]=lower_bound(b+1,b+siz+1,w[i])-b;
    build(rt[0],1,siz);
    dfs(rt[0],1,siz);
    dfs1(1,0,1),dfs2(1,1);
    while(m--){
        int u,v,k;
        u=read(),v=read(),k=read();
        int lca=Lca(u,v);
        printf("%d\n",(b[query(rt[u],1,siz,rt[v],rt[lca],rt[fa[lca]],k)]));
    }


    
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}