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
const int N=150000+10;
int a[N],b[N];
bool isp(int n){
    for(int j=2;j*j<=n;j++)
        if(n%j==0) return false;
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n;
    rd(n);
    fr(i,n) rdd(a[i],b[i]);
    vector<int>dv;
    for(int j=2;j*j<=a[n];j++){
        if(a[n]%j==0){
            if(isp(j)) dv.pb(j);
            if(isp(a[n]/j)) dv.pb(a[n]/j);
        }
    }
    for(int j=2;j*j<=b[n];j++){
        if(b[n]%j==0){
            if(isp(j)) dv.pb(j);
            if(isp(b[n]/j)) dv.pb(b[n]/j);
        }
    }
    sort(all(dv));
    dv.erase(unique(all(dv)),dv.end());
    for(auto s:dv){
        bool mark=true;
        for(int i=1;i<n;i++){
            if(a[i]%s!=0&&b[i]%s!=0){
                mark=false;
                break;
            }
        }
        if(mark){
            prn(s);
            return 0;
        }
    }
    prn(-1);
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}