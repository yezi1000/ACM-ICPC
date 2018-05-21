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
const int maxn=100000+10;
int t,n,q,l,r;
int c[maxn];///a[]原数组,c[]树状数组
struct node{
    int l,r,pos,ans;
    bool const operator<(const &node b)const{
        if(l!=b.l) retrun l<b.l;
        else return r<b.r;
    }
}p[maxn];
int lowbit(int x){
    return x&(-x);
}
void Add(int pos,int val)///单点修改{
    for(int i=pos;i<=n;i+=lowbit(i))
        c[i]+=val;
}
int Sum(int pos)///从0位置到pos位置的区间和
{
    int ret=0;
    for(int i=pos;i>0;i-=lowbit(i))
        ret+=c[i];
    return ret;
}
unordered_map<int,int>ww;
vector<int>ha;
int main(){
    int t;
    rd(t);
    while(t--){
        CL(c);
        int n;
        rd(n);
        int cnt=0;
        int tmp;
        for(int j=0;j<n;j++){
            scanf("%d",&a[j]);
            ha.pb(a[j]);
        }
        sort(ha,ha+n);//排序hash
        ha.erase(unique(ha.first(),ha.end()),ha.end());
        int ss=ha.size();
        for(int j=0;j<ss;j++) ww[ha[j]]=j+1;//ww保存值ha[j]对应的hash映射
        int Q;
        rd(Q);
        for(int j=1;j<=Q;j++){
            scanf("%d%d",&p[j].l,&p[j].r);
            p[j].pos=j;
        }
        sort(p+1,p+Q+1);
        int cnt=0,tot=1;//tot保存查询区间序号 cnt表示当前扫到了原数组的哪个值
        for(int j=0;j<n;){
            while(j<p[tot].l) {Add(ww[a[j]],-1);j++;}
            while(p[tot].l<j) j++;
            while(p[tot].r<j) Add(ww[a[j]],1);
            p[tot].ans=Sum(ss);j++;
        }
        for(int j)
    }
}