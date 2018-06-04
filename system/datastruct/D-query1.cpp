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
    int l,r;
    int sum;
}p[N<<5];
int tot,a[N],root[N];
int n,m;
int build(int l,int r){//返回新建的节点编号
    int rt=++tot;
    p[rt].sum=0;
    if(l<r){
        int m=(l+r)>>1;
        p[rt].l=build(l,m);
        p[rt].r=build(m+1,r);
    }
    return rt;
}
int update(int pos,int c,int v,int l,int r){
    int nc=++tot;
    p[nc]=p[c];p[nc].sum+=v;
    if(l==r) return nc;
    int m=(l+r)>>1;
    if(pos<=m) p[nc].l=update(pos,p[c].l,v,l,m);
    else p[nc].r=update(pos,p[c].r,v,m+1,r);
    return nc;
}
int query(int pos,int c,int l,int r){
    if(l==r) return p[c].sum;
    int m=(l+r)>>1;
    if(m>=pos) return p[p[c].r].sum+query(pos,p[c].l,l,m);
    return query(pos,p[c].r,m+1,r);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    while(cin>>n){   
        tot=0;
        int m;
        int maxn=0;
        for(int j=1;j<=n;j++)
            rd(a[j]);
        root[0]=build(1,n);
        map<int,int>mm;
        for(int j=1;j<=n;j++){
            if(mm.find(a[j])==mm.end())
                root[j]=update(j,root[j-1],1,1,n);
            else{
                int t=update(mm[a[j]],root[j-1],-1,1,n);
                root[j]=update(j,t,1,1,n);
            }
            mm[a[j]]=j;
        }
        rd(m);
        while(m--){
            int l,r;
            rdd(l,r);
            prn(query(l,root[r],1,n));
        }
    }
    return 0;
}