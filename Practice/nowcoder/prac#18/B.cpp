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
typedef unsigned long long ull;
ull expow(ull a,ull b,ull p) {ull v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
const int N=100000+10;
const ull mo=2000000000000000003;
struct node{
    int x,y;
    int n;
};
vector<node>Q;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int sz,ans=0,cnt=0;
    cin>>sz;
    for(int j=0;j<sz;j++){
        node bb;
        rd(bb.x);rd(bb.y);bb.n=j;
        Q.push_back(bb);
    }
    for(int j=0;j<sz;j++){
        PII pp,qq;
        int pre=j-1,nxt=j+1;
        if(j==0) pre=sz-1;
        if(j==sz-1) nxt=0;
        pp.first=Q[j].x-Q[pre].x;pp.second=Q[j].y-Q[pre].y;
        qq.first=Q[nxt].x-Q[j].x;qq.second=Q[nxt].y-Q[j].y;
        if(pp.fi*qq.se>pp.se*qq.fi){
            ans++;
        }
        else if(pp.fi*qq.se<pp.se*qq.fi) cnt++;
    }
    if(ans>=cnt) printf("counterclockwise\n");
    else printf("clockwise\n");
    return 0;
}