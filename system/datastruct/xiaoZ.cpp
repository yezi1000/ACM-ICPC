#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<ctime>
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
#define rl(x) scanf("%lld",&x)
#define rll(x,y) scanf("%lld%lld",&x,&y)
#define rlll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define pd(x) printf("%d",x)
#define pdn(x) printf("%d\n",x)
#define pl(x) printf("%lld",x)
#define pln(x) printf("%lld\n",x)
typedef long long ll;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
using namespace std;
const int N=50000+10;
int b[N],bl[N];
struct node{
    ll l,r,ne,de;
    int pt;
    const bool operator<(const node &b){
        return pt<b.pt;
    }
}q[N];
bool cmp1(node a,node b){
    if(bl[a.l]<bl[b.l]) return 1;
    if(bl[a.l]>bl[b.l]) return 0;
    return a.r<b.r;
}
bool cmp2(node a,node b){
    return a.pt<b.pt;
}
int nl,nr;
ll ans,p;
ll col[N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n,m;
    nl=1;
    rdd(n);
    for(int j=1;j<=n;j++)rd(b[j]);
    bl[0]=sqrt(n);
    for(int j=1;j<=n;j++) bl[j]=(j-1)/bl[0]+1;
    for(int j=1;j<=m;j++) rll(q[j].l,q[j].r),q[j].pt=j;
    //for(int j=1;j<=m;j++) pln(q[j].l);
    sort(q+1,q+m+1,cmp1);
    for (int i=1;i<=m;i++)
    {
        q[i].de=(q[i].r-q[i].l+1)*(q[i].r-q[i].l);
        if (nr<q[i].r){
            for (int j=nr+1;j<=q[i].r;j++)
                ans+=((col[b[j]]<<1)+1),col[b[j]]++;
        }
        if (nr>q[i].r){
            for (int j=nr;j>q[i].r;j--)
                ans-=((col[b[j]]<<1)-1),col[b[j]]--;
        }
        if (nl>q[i].l){
            for (int j=nl-1;j>=q[i].l;j--)
                ans+=((col[b[j]]<<1)+1),col[b[j]]++;
        }
        if (nl<q[i].l){
            for (int j=nl;j<q[i].l;j++)
                ans-=((col[b[j]]<<1)-1),col[b[j]]--;
        }
        q[i].ne=ans-(q[i].r-q[i].l+1);
        nl=q[i].l;nr=q[i].r;
    }
    sort(q+1,q+m+1,cmp2);
    for(int j=1;j<=m;j++){
        if(!q[j].ne){printf("0/1\n");continue;}
        p=gcd(q[j].ne,q[j].de);
        printf("%lld/%lld\n",q[j].ne/p,q[j].de/p);
    }
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
    return 0;
}