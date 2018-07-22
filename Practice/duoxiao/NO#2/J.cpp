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
const int N=1000000+5;
int n, m, q, x, y, xx, yy, t, ans;
vector<int> BIT[N];
vector<PII >a[N];
vector< pair<PII,PII> > b[N];
void Add(int x, int y, int z) {
    for (int i = x; i <= n; i += i & -i)
        for (int j = y; j <= m; j += j & -j)
            BIT[i][j] += z;
}
int Sum(int x, int y) {
    int ans = 0;
    for (int i = x; i; i -= i & -i)
        for (int j = y; j; j -= j & -j)
            ans += BIT[i][j];
    return ans;
}
template <class T>
inline void scan_d(T &ret) {
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    rddd(n,m,q);
    fr(i,n){
        fr(j,m){
            scan_d(x);
            a[x].pb(mp(i,j));
        }
    }
    fr(i,n) fr(j,m+1) BIT[i].pb(0);
    fr(i,q){
        int x,xx,y,yy,t;
        scan_d(x); scan_d(y);scan_d(xx);scan_d(yy); scan_d(t);
        b[t].pb({{x,y},{xx,yy}});
        Add(x,y,1);Add(x,yy+1,-1);
        Add(xx+1,y,-1);Add(xx+1,yy+1,1);
    }
    fr(i,n*m){
        for(int j=0;j<b[i].size();j++){
            Add(b[i][j].fi.fi, b[i][j].fi.se, -1);
            Add(b[i][j].fi.fi, b[i][j].se.se + 1, 1);
            Add(b[i][j].se.fi + 1, b[i][j].fi.se, 1);
            Add(b[i][j].se.fi + 1, b[i][j].se.se + 1, -1);
        }
        for (int j = 0; j < a[i].size(); j++)
            if (Sum(a[i][j].fi, a[i][j].se))
                ans++;
        for (int j = 0; j < b[i].size(); j++) {
            Add(b[i][j].fi.fi, b[i][j].fi.se, 1);
            Add(b[i][j].fi.fi, b[i][j].se.se + 1, -1);
            Add(b[i][j].se.fi + 1, b[i][j].fi.se, -1);
            Add(b[i][j].se.fi + 1, b[i][j].se.se + 1, 1);
        }
    }
    prn(ans);
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}