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
namespace bit {
const int MX=500000+10;
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
        c[x]=(c[x]+u);
        x+=lowbit(x);
    }
}
void iupdate(int l,int r,int u){//区间修改
    update(l,u);
    update(r+1,-u);
}
int sum(int x) {
    int sum=0;
    while (x>0) {
        sum=(sum+c[x]);
        x-=lowbit(x);
    }
    return sum;
}
int getsum(int l,int r) {
    return sum(r)-sum(l-1);
}
} // binary indexed tree
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n,m;
    rdd(n,m);
    bit::init(n);
    int tmp;
    for(int j=1;j<=n;j++){
        rd(tmp);bit::update(j,tmp);
    }
    int op,x,k;
    for(int j=1;j<=m;j++){
        rddd(op,x,k);
        if(op==1)bit::update(x,k);
        else prn(bit::getsum(x,k));
    }
    return 0;
}