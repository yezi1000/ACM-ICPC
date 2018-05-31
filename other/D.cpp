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
#define INF 0x3f3f3f3f
typedef long long ll;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
const int N=100000+10;
vector<int>e[N];
vector<int>qq[111];
int col[N];
int d[111][N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n,m,k,s;
    rdd(n,m);rdd(k,s);
    int a,b;
    for(int j=0;j<n;j++) {
        rd(col[j]);col[j]--;
        qq[col[j]].pb(j);
    }
    for(int j=0;j<m;j++){
        rdd(a,b);--a;--b;
        e[a].pb(b);e[b].pb(a);
    }
    for(int j=0;j<k;j++){
        for(int i=0;i<n;i++) d[j][i]=900000000;
        queue<int>q;
        for(int i:qq[j]){
            d[j][i]=0;
            q.push(i);
        }
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(int i:e[v]){
                d[j][i]=min(d[j][i],d[j][v]+1);
                q.push(i);
            }
        }
    }
    vector<int>ts(k);
    for(int i=0;i<n;i++){
        for(int q=0;q<k;q++) ts[q]=d[q][i];
        sort(all(ts));
        int ans=0;
        for(int kk=0;kk<s;kk++) ans+=ts[kk];
        cout<<ans<<" ";
    }
    return 0;
}