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
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 105555;
ll sum[maxn<<2];
int mo;
void PushUP(int rt) {
	sum[rt] = sum[rt<<1]*sum[rt<<1|1]%mo;
}
void build(int l,int r,int rt) {
	if (l == r) {
		sum[rt]=1;
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUP(rt);
}
void update(int p,int add,int l,int r,int rt) {
	if (l == r) {
		sum[rt]=add;
		return ;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p, add, lson);
	else update(p, add, rson);
	PushUP(rt);
}
int main() {
    int _;
    rd(_);
    while(_--){
        int q;
        rd(q);
        rd(mo);
        build(1,q,1);
        char op[5];
        int tp;
        for(int j=1;j<=q;j++){
            //cout<<j<<endl;
            scanf("%s %d",op,&tp);
            tp%=mo;
            if(op[0]=='M') update(j,tp,1,q,1);
            else update(tp,1,1,q,1);
            printf("%d\n",sum[1]);
        }
    }
    return 0;
}
