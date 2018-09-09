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
const int mo=1e9+7;
#include<bits/stdc++.h>
int x[N],y[N];
bool check(int u,int v,int n,double m)
{
    int c=0;
    for(int i=0;i<n;i++)
        //if((x2-x1)(y3-y1)=(x3-x1)(y2-y1))
        if((ll)(x[v]-x[u])*(y[i]-y[u])==(ll)(x[i]-x[u])*(y[v]-y[u]))
            c++;
    return 1.0*c/n>=m;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int t=1,T;
    for(scanf("%d",&T);t<=T;t++)
    {
        int n;
        double m;
        scanf("%d%lf",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d%d",&x[i],&y[i]);
        int f=0;
        for(int i=0;i<max(n/100,1000);i++){
            int u=rand()%n;
            int v=rand()%n;
            while(u==v)v=rand()%n;
            if(check(u,v,n,m)){
                f=1;
                break;
            }
        }
        if(f)puts("Yes");
        else puts("No");
    }

    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}