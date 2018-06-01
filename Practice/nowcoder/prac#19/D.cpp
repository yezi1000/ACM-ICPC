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
typedef long long ll;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
const int N=1000000+10;
const int MAXN = 1400;
const int MAXM = 1400*1400;
const int INF = 0x3f3f3f3f;
struct Edge {
    int v, f;
    int next;
} edge[MAXM];
int n,m;
int cnt;
int first[MAXN], level[MAXN];
int q[MAXN];
void init() {
    cnt = 0;
    memset(first, -1, sizeof(first));
}
void read_graph(int u, int v, int f) {
    edge[cnt].v = v, edge[cnt].f = f;
    edge[cnt].next = first[u], first[u] = cnt++;
    edge[cnt].v = u, edge[cnt].f = 0;  //增加一条反向弧，容量为0
    edge[cnt].next = first[v], first[v] = cnt++;
}
int bfs(int s, int t) { //构建层次网络
    memset(level, 0, sizeof(level));
    level[s] = 1;
    int front = 0, rear = 1;
    q[front] = s;
    while(front < rear) {
        int x = q[front++];
        if(x == t) return 1;
        for(int e = first[x]; e != -1; e = edge[e].next) {
            int v = edge[e].v, f = edge[e].f;
            if(!level[v] && f) {
                level[v] = level[x] + 1;
                q[rear++] = v;
            }
        }
    }
    return 0;
}
int dfs(int u, int maxf, int t) {
    if(u == t) return maxf;
    int ret = 0;
    for(int e = first[u]; e != -1; e = edge[e].next) {
        int v = edge[e].v, f = edge[e].f;
        if(level[u] + 1 == level[v] && f) {
            int Min = min(maxf-ret, f);
            f = dfs(v, Min, t);
            edge[e].f -= f;
            edge[e^1].f += f;
            ret += f;
            if(ret == maxf) return ret;
        }
    }
    return ret;
}
int Dinic(int s, int t) { //Dinic
    int ans = 0;
    while(bfs(s, t)) ans += dfs(s, INF, t);
    return ans;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
#endif
    int n;
    rd(n);
    while(n--){
        int x,y;
        int sum=0;
        rdd(x,y);
        int tmp;
        init();
        int tt=0;
        for(int j=1;j<=x;j++){
            rd(tmp);
            sum+=tmp;
            read_graph(x+y+2,++tt,tmp);
            //cout<<x+y+2<<" "<<tt<<" "<<tmp<<endl;
        }
        for(int j=1;j<=y;j++){
            rd(tmp);
            read_graph(++tt,x+y+1,tmp);
            //cout<<tt<<" "<<x+y+1<<" "<<tmp<<endl;
        }
        //cout<<"ch"<<cnt<<endl;
        for(int j=1;j<=y;j++){
            int qq;
            rd(qq);
            while(qq--){
                rd(tmp);
                read_graph(tmp,x+j,80000000);
                //cout<<x+j<<" "<<tmp<<endl;
            }
        }
        cout<<sum-Dinic(x+y+2,x+y+1)<<endl;
    }
    return 0;
}