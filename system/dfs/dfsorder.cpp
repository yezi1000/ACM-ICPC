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
#define pr(x) printf("%d",x)
#define prn(x) printf("%d\n",x)
typedef long long ll;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
const int N=100000+10;
int r[N],in[N];//in入度,r根,存图方式不同
int cnt=0;//cnt存块
vector<int>e[N];//存边
vector<int>xu;//dfs序
bool vis[N];//避免遍历
struct node{//p[j]记录j点子树(包括自己)在dfs序中的下标集合(0起)
    int l,r;
}p[N];
void dfs(int n){
    //cout<<n<<endl;
    xu.pb(n);
    vis[n]=true;
    p[n].l=++cnt;
    for(int j=0;j<(int)e[n].size();j++) 
        if(!vis[e[n][j]]) dfs(e[n][j]);
    p[n].r=cnt;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("F:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n;
    int _,__;asinf
    scanf("%d",&n);
    for(int j=1;j<n;j++){
        scanf("%d%d",&_,&__);
        e[_].pb(__);
        e[__].pb(_);
    }
    dfs(1);
    cout<<cnt<<endl;
    for(int j=0;j<(int)xu.size();j++) cout<<xu[j]<<" ";
    cout<<endl;
    //cout<<xu.size()<<endl;
    for(int j=1;j<=n;j++) cout<<j<<" "<<p[j].l<<" "<<p[j].r<<endl;
    return 0;
}