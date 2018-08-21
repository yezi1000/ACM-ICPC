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
const int N=700+10;
int g[N][N],a[N];
bool R[N][N],L[N][N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n;rd(n);
    fr(i,n) rd(a[i]);
    fr(i,n){
        fr(j,n){
            g[i][j]=__gcd(a[i],a[j]);
            if(g[i][j]!=1) g[i][j]=1;
            else g[i][j]=0;
        }
    }
    FR(i,1,n) L[i][i]=R[i][i]=1;
    FR(j,1,n-1) FR(i,1,n-j) {
        int k=i+j;
        FR(p,i+1,k) L[i][k]|=(g[i][p]&L[p][k]&R[i+1][p]);
        FR(p,i,k-1) R[i][k]|=(g[p][k]&L[p][k-1]&R[i][p]);
    }
    FR(i,1,n) {
        if(L[i][n]&&R[1][i]) {
            printf("Yes");
            return 0;
        }
    }
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}