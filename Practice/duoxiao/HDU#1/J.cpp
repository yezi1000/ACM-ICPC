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
template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int B;
struct node{
    int l,r,id;
    const bool operator<(const node &b){
        if(l/B==b.l/B) return r>b.r;
        else return l/B<b.l/B;
    }
}p[N];
int a[N],cnt[N],ans[N],now;
void del(int t){
    cnt[t]++;
    if(cnt[t]==1) now++;
}
void add(int t){
    cnt[t]--;
    if(cnt[t]==0) now--;
}
void solve(int q){
    sort(p+1,p+q+1);
    int nl=1,nr=0;
    for(int j=1;j<=q;j++){
        while(nr<p[j].r) add(++nr);
        while(nr>p[j].r) del(nr--);
        while(nl<p[j].l) del(nl++);
        while(nl>p[j].l) add(--nl);
        ans[p[j].id]=now;
    }
    for(int j=1;j<=q;j++) prn(ans[j]);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n,m;
    B=sqrt(100000);
    while(~rdd(n,m)){
        //cout<<n<<" "<<m<<endl;
        memset(cnt,0,(n+10)*sizeof(int));
        now=0;
        //cout<<n<<" "<<m<<endl;
        for(int j=1;j<=n;j++) {
            scan_d(a[j]);
            //rd(a[j]);
            cnt[a[j]]++;
            if(cnt[a[j]]==1) now++;
        }
        //cout<<now<<endl;
        for(int j=1;j<=m;j++) scan_d(p[j].l),scan_d(p[j].r),p[j].l++,p[j].r--,p[j].id=j;
        //for(int j=1;j<=m;j++) cout<<p[j].l<<" "<<p[j].r<<endl;
        solve(m);
    }
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}