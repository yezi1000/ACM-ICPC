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
#include<assert.h>
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
const int N=100000+10;
const int mod=1000000007;
struct matrix {
	ll x[4][4];
};
matrix mutimatrix(matrix a,matrix b) {
	matrix temp;
	memset(temp.x,0,sizeof(temp.x));
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			for(int k=0; k<4; k++) {
				temp.x[i][j]+=a.x[i][k]*b.x[k][j];
				temp.x[i][j]%=mod;
			}
	return temp;
}
matrix k_powmatrix(matrix a,ll n) { //矩阵快速幂
	matrix temp;
	memset(temp.x,0,sizeof(temp.x));
	for(int i=0; i<4; i++)
		temp.x[i][i]=1;

	while(n) {
		if(n&1)
			temp=mutimatrix(temp,a);

		a=mutimatrix(a,a);
		n>>=1;
	}
	return temp;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    ll n;
	while(scanf("%lld",&n)!=EOF) {
		if(n==1) {
			printf("1\n");
			continue;
		}
		if(n==2) {
			printf("5\n");
			continue;
		}
		if(n==3) {
			printf("11\n");
			continue;
		}
		if(n==4) {
			printf("36\n");
			continue;
		}
		matrix st;
		memset(st.x,0,sizeof(st.x));
		st.x[0][0]=1;
		st.x[1][0]=5;
		st.x[2][0]=1;
		st.x[3][0]=-1;
		st.x[0][1]=1;
		st.x[1][2]=1;
		st.x[2][3]=1;
		matrix init;//初始矩阵
		memset(init.x,0,sizeof(init.x));
		init.x[0][0]=36;
		init.x[0][1]=11;
		init.x[0][2]=5;
		init.x[0][3]=1;
		st=k_powmatrix(st,n-4);//经过n-4次相乘
		st=mutimatrix(init,st);//然后再乘上初始矩阵
		printf("%lld\n",(st.x[0][0]+mod)%mod);
	}
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}