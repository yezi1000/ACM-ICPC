#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<time.h>
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
#define    mem(a,b)         memset((a),(b),sizeof(a))
typedef long long ll;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
const int N=100000+10;
int cnt;
struct node{
    int l,r;
}p[N];
int v[N];
vector<int>e[N];//存边
int xu[N];
void dfs(int n){
    p[n].l=++cnt;
    xu[cnt]=n;
    for(int j=0;j<(int)e[n].size();j++) dfs(e[n][j]);
    p[n].r=cnt;
    return ;
}
struct Dictionarie_Tree {
    int tree[N<<5][3],top;
    void init() { mem(tree[0],0),top=1; }
    void ins(int x,int id) {
        int rt,nxt,u,t;
        for(rt=0,t=31;~t;rt=nxt,--t) {
            nxt=tree[rt][u=x>>t&1];
            if(!nxt)mem(tree[top],0),tree[rt][u]=nxt=top++;
            tree[nxt][2]=id;
        }
    }
    int query(int x,int l) {
        int rt,nxt,u,t,ans=0;
        for(rt=0,t=31;~t;rt=nxt,--t) {
            u=x>>t&1,ans<<=1;
            if((nxt=tree[rt][!u])&&tree[nxt][2]<=l)ans+=1;
            else nxt=tree[rt][u];
        }
        return ans;
    }
} D;
struct nodd {
    int id,l,r,x;
    bool operator < (nodd &m) const {
        return l>m.l;
    }
}querr[N];
int ans[N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n,q;
    while(cin>>n>>q){
        cnt=0;
        D.init();
        for(int j=1;j<=n;j++) e[j].clear();
        for(int j=1;j<=n;j++) rd(v[j]);
        int tpp;
        for(int j=2;j<=n;j++){
            rd(tpp);
            e[tpp].pb(j);
        }
        dfs(1);
        //for(int j=1;j<=n;j++) cout<<j<<" "<<p[j].l<<" "<<p[j].r<<endl;
        int tl,tmp;
        for(int j=1;j<=q;j++){
            scanf("%d%d",&tl,&tmp);
            querr[j].id=j;querr[j].l=p[tl].l;querr[j].r=p[tl].r;querr[j].x=tmp;
        }
        sort(querr+1,querr+q+1);
        int s=n;
        for(int j=1;j<=q;j++){
            while(s>=querr[j].l) D.ins(v[xu[s]],s),--s;
            ans[querr[j].id]=D.query(querr[j].x,querr[j].r);
        }
        for(int j=1;j<=q;j++) cout<<ans[j]<<endl;
    }
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}
