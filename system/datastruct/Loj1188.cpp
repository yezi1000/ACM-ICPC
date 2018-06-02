#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<time.h>
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
const int N=10000+10;
int a[10*N],ans[10*N],cnt[10*N];
int bl;
int nl,nr,now;
struct node{
    int l,r,nn;
    const bool operator<(const node &b)const{
        if(l/bl==b.l/bl) return r<b.r;
        else return l/bl<b.l/bl;
    }
}p[5*N];
void add(int n){
    cnt[a[n]]++;
    if(cnt[a[n]]==1) now++;
}
void del(int n){
    cnt[a[n]]--;
    if(cnt[a[n]]==0) now--;
}
int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    // #endif
    int _;
    rd(_);
    for(int ca=1;ca<=_;ca++){
        printf("Case %d:\n",ca);
        int n,m;
        memset(cnt,0,sizeof(cnt));
        rdd(n,m);
        bl=sqrt(n);
        for(int j=1;j<=n;j++) rd(a[j]);
        for(int j=1;j<=m;j++) rdd(p[j].l,p[j].r),p[j].nn=j;
        sort(p+1,p+m+1);
        //for(int j=1;j<=m;j++) printf("%d %d\n",p[j].l,p[j].r);
        nl=1,nr=0,now=0;
        for(int j=1;j<=m;j++){
            while(nr<p[j].r) add(++nr);
            while(nr>p[j].r) del(nr--);
            while(nl<p[j].l) del(nl++);
            while(nl>p[j].l) add(--nl);
            ans[p[j].nn]=now;
        }
        for(int j=1;j<=m;j++) prn(ans[j]);
    }
    // #ifndef ONLINE_JUDGE
    // printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    // #endif
    return 0;
}