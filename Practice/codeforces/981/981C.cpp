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
#define pr(x) printf("%d",x)
#define prn(x) printf("%d\n",x)
typedef long long ll;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
const int N=100000+10;
VI e[N];
VI a;
bool vis[N];
void dfs(int n){
    vis[n]=true;
    int cnt=0;
    for(int j=0;j<e[n].size();j++){
        if(!vis[e[n][j]]){
            cnt++;
            dfs(e[n][j]);
        }
    }
    if(cnt==0) a.pb(n);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n;rd(n);
    int u,v;
    for(int j=1;j<n;j++){
        rdd(u,v);
        e[u].pb(v);e[v].pb(u);
    }
    int rt=1,ff=0;
    for(int j=1;j<=n;j++){
        if(e[j].size()>2){
            ff++;
            rt=j;
        }
    }
    if(ff>1)cout<<"No";
    else{
        dfs(rt);
        bool f=false;
        for(int j=1;j<=n;j++){
            if(vis[j]==false) {f=true;break;}
        }
        if(f) cout<<"No";
        else{
            cout<<"Yes"<<endl;
            cout<<a.size()<<endl;
            for(int j=0;j<a.size();j++){
                cout<<rt<<" "<<a[j]<<endl;
            }
        }
    }
}

