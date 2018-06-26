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
#define rd(x) x=in()
#define rdd(x,y) scanf("%d%d",&x,&y)
#define rddd(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pr(x) printf("%d",x)
#define prn(x) printf("%d\n",x)
typedef long long ll;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
const int N=1000000+10;
int a[N],b[N],c[2*N];
void up(int x){
    while(c[x]==1){
        c[x-1]=c[x]=0;c[x+1]++;
        x+=2;
    }
}
void cha(int x){
    if(c[x]<2) return ;
    int t=x-2; if(!t) t=1;
    c[x+1]++;if(x!=1) c[t]++;
    c[x]-=2;
}
inline void writeAbs(int a)
{
    if (a >= 10) writeAbs(a/10);
    putchar('0'+a%10);
}
inline void write(int a)
{
    if (a < 0) putchar('-');
    writeAbs(abs(a));
}
inline int in()
{
    register int num=0;
    register char ch;
    do ch=getchar(); while (ch<'0' || ch>'9');
    do num=num*10+ch-'0', ch=getchar(); while (ch>='0' && ch<='9');
    return num;
}
int main(){
    //傻逼题还卡常
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int la,lb;
    rd(la);
    fr(i,la) rd(a[i]);
    rd(lb);
    fr(i,lb) rd(b[i]);
    int ml=max(la,lb);
    for(int j=ml;j>=1;j--){
        c[j]+=a[j]+b[j];
        if(c[j]==2||c[j]==3){
            cha(j);cha(j+1);
            if(j==1) cha(j);
        }
        if(c[j]) up(j+1);
        if(c[j+1]) up(j+2);
        if(c[j+2]) up(j+3);
    }
    int k=2000000;
    while(c[k]==0) k--;
    write(k); putchar('\n');
    for(int i = 1; i <= k; i ++) { write(c[i]); if(i != k) putchar(' '); }
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}