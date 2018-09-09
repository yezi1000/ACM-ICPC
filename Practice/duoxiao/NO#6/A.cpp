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
const int N=100000+10;
const ll mo=1e9+7;

inline int in(){
    register int num=0;
    register char ch;
    do ch=getchar(); while (ch<'0' || ch>'9');
    do num=num*10+ch-'0', ch=getchar(); while (ch>='0' && ch<='9');
    return num;
}

queue<int>match;
priority_queue<int>a[20000];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int _;
    rd(_);
    fr(cas,_){
        int n,nl;
        rd(n);
        nl=(1<<n);
        //cout<<n<<" "<<nl<<endl;
        int tmp;
        while(!match.empty())match.pop();
        for(int j=1;j<=nl;j++){
            while(!a[j].empty()) a[j].pop();
            match.push(j);
            for(int k=1;k<=n;k++){
                tmp=in();
                a[j].push(tmp);
                //cout<<j<<" "<<k<<endl;
            }
            //cout<<j<<endl;
        }
        //cout<<match.size()<<endl;
        while(match.size()!=1){
            int p1=match.front();match.pop();
            int p2=match.front();match.pop();
            if(a[p1].top()>a[p2].top()) a[p1].pop(),match.push(p1);
            else a[p2].pop(),match.push(p2);
        }
        printf("Case #%d: %d\n",cas,match.front());
    }
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}