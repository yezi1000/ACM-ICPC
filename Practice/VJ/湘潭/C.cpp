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
const int N=100000+10;
struct node{
    int l,r,sum;
}p[N*20];
int tot,a[N],T[N],n,m;
int build(int l,int r){
    int rt=++tot;
    p[rt].sum=0;
    if(l<r){
        int m=(l+r)>>1;
        p[rt].l=build(l,m);
        p[rt].r=build(m+1,r);
    }
    return rt;
}
int update(int pre,int l,int r,int pos){
    int nc=++tot;
    p[nc]=p[pre];p[nc].sum++;
    if(l<r){
        int m=(l+r)>>1;
        if(pos<=m) p[nc].l=update(p[pre].l,l,m,pos);
        else p[nc].r=update(p[pre].r,m+1,r,pos);
    }
    return nc;
}
int query(int u,int v,int l,int r,int k){
    if(l>=r) return l;
    int m=(l+r)>>1;
    int num=p[p[v].r].sum-p[p[u].r].sum+k;
    if(num<=m)return query(p[u].l,p[v].l,l,m,num);//右边的数一定大于左边
    else return query(p[u].r,p[v].r,m+1,r,k);//父亲的右儿子一定比自己大
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int t;
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        tot=0;
        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
        }
        T[0]=build(1, n);
        for(int i=1; i<=n; i++){
            T[i]=update(T[i-1], 1, n,a[i]);
        }
        while(m--){
            int l, r, k;
            scanf("%d%d", &l, &r);
            int x=query(T[l-1], T[r], 1, n, 0);
            printf("%d\n", x);
        }
    }
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}