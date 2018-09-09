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
using namespace std;
const int N=100000+10;
int a[N],B,cnt[N],h[N];
int ans[N];
int now;
struct node{
    int l,r,nn;
    const bool operator<(const node &b){
        if(l/B==b.l/B) return r<b.r;
        else return l/B<b.l/B;
    }
}p[N];
void add(int n){
    n=a[n];
    cnt[n]++;
    now=now+(cnt[n]*cnt[n]*cnt[n]-(cnt[n]-1)*(cnt[n]-1)*(cnt[n]-1));
}
void del(int n){
    n=a[n];
    if(cnt[n]!=0) {
        cnt[n]--;
        now=now+(cnt[n]*cnt[n]*cnt[n]-(cnt[n]+1)*(cnt[n]+1)*(cnt[n]+1));
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n;
    while(~rd(n)){
        B=sqrt(n);
        fr(i,n) rd(a[i]),h[i]=a[i];
        sort(h+1,h+n+1);
        int d=unique(h+1,h+n+1)-h-1;
        fr(i,n) a[i]=lower_bound(h+1,h+d+1,a[i])-h;
        //fr(i,n) cout<<a[i]<<" ";
        //cout<<endl;
        int Q;
        rd(Q);
        fr(i,Q) rdd(p[i].l,p[i].r),p[i].nn=i;
        sort(p+1,p+Q+1);
        int nl=1,nr=0;
        now=0;
        //cout<<"e"<<endl;
        for(int j=1;j<=Q;j++){
            while(nr<p[j].r) add(++nr);
            while(nr>p[j].r) del(nr--);
            while(nl<p[j].l) del(nl++);
            while(nl>p[j].l) add(--nl);
            //cout<<cnt[1]<<" "<<cnt[2]<<endl;
            ans[p[j].nn]=now;
        }
        fr(i,Q) prn(ans[i]);
    }
    
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}