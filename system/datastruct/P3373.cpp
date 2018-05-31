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
int p;
ll c[N*5];
struct sgt{
    long long sum[2000010];
    long long addv[2000010];
    long long mulv[2000010];
    void build(int o,int l,int r){
        addv[o]=0;
        mulv[o]=1;
        if(l==r)sum[o]=c[l];
        else{
            int mid=(l+r)>>1;
            int lson=o<<1;
            int rson=lson|1;
            build(lson,l,mid);
            build(rson,mid+1,r);
            sum[o]=(sum[lson]+sum[rson])%p;
        }
    }    
    void push_down(int o,int l,int r,int mid,int lson,int rson){
        mulv[lson]=(mulv[lson]*mulv[o])%p;
        mulv[rson]=(mulv[rson]*mulv[o])%p;
        addv[lson]=(addv[lson]*mulv[o])%p;
        addv[rson]=(addv[rson]*mulv[o])%p;
        sum[lson]=(sum[lson]*mulv[o])%p;
        sum[rson]=(sum[rson]*mulv[o])%p;
        mulv[o]=1;
        addv[lson]=(addv[lson]+addv[o])%p;
        addv[rson]=(addv[rson]+addv[o])%p;
        sum[lson]=(sum[lson]+(mid-l+1)*addv[o])%p;
        sum[rson]=(sum[rson]+(r-mid)*addv[o])%p;
        addv[o]=0;
    }
    void addall(int o,int l,int r,int a,int b,int x){
        if(l>=a && r<=b){
            addv[o]=(addv[o]+x)%p;
            sum[o]=(sum[o]+(r-l+1)*x)%p;
            return;
        }
        else{
            int mid=(l+r)>>1;
            int lson=o<<1;
            int rson=lson|1;
            if(mulv[o]!=1 || addv[o])push_down(o,l,r,mid,lson,rson);
            if(a<=mid)addall(lson,l,mid,a,b,x);
            if(b>mid)addall(rson,mid+1,r,a,b,x);
            sum[o]=(sum[lson]+sum[rson])%p;
        }
    }
    void mulall(int o,int l,int r,int a,int b,int x){
        if(l>=a && r<=b){
            mulv[o]=(mulv[o]*x)%p;
            addv[o]=(addv[o]*x)%p;
            sum[o]=(sum[o]*x)%p;
            return;
        }
        else{
            int mid=(l+r)>>1;
            int lson=o<<1;
            int rson=lson|1;
            if(mulv[o]!=1 || addv[o])push_down(o,l,r,mid,lson,rson);
            if(a<=mid)mulall(lson,l,mid,a,b,x);
            if(b>mid)mulall(rson,mid+1,r,a,b,x);
            sum[o]=(sum[lson]+sum[rson])%p;
        }
    }
    long long query(int o,int l,int r,int a,int b){
        if(l>=a && r<=b)return sum[o]%p;
        else{
            int mid=(l+r)>>1;
            int lson=o<<1;
            int rson=lson|1;
            long long ans=0;
            if(mulv[o]!=1 || addv[o])push_down(o,l,r,mid,lson,rson);
            if(a<=mid)ans+=query(lson,l,mid,a,b);
            if(b>mid)ans+=query(rson,mid+1,r,a,b);
            return ans%p;
        }
    }
};
sgt tree;
int n,m,i,f;
int x,y;
long long k;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    scanf("%d%d%d",&n,&m,&p);
    for(i=1;i<=n;i++)scanf("%d",&c[i]);
    tree.build(1,1,n);
    for(i=1;i<=m;i++){
        scanf("%d",&f);
        switch(f){
            case 1:{
                scanf("%d%d%d",&x,&y,&k);
                tree.mulall(1,1,n,x,y,k);
                break;
            }
            case 2:{
                scanf("%d%d%d",&x,&y,&k);
                tree.addall(1,1,n,x,y,k);
                break;
            }
            case 3:{
                scanf("%d%d",&x,&y);
                printf("%lld\n",tree.query(1,1,n,x,y));
                break;
            }    
        }
    }
    return 0;
}