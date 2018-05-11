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
int rk[N],C[2*N],n;
void change(int x,int v) {
	for (; x<=n; x+=x&(-x)) {
		C[x]+=v;
	}
}
int getsum(int x) {
	int res=0;
	for (; x; x-=x&(-x))
		res+=C[x];
	return res;
}
struct node {
	int x,y,v;
	const bool operator<(const node &b)const{
		if(x==b.x) return y<b.y;
		else return x<b.x;
	}
}Q[N];
int ans[N];
int main(){
	int m;
	rd(n);rd(m);
	for (int j=1; j<=n; j++) rd(rk[j]);
	for (int j=0; j<m; j++){
		rd(Q[j].x);rd(Q[j].y);
		Q[j].v=j;
	}
	sort(Q,Q+m);
	int cnt=0;
	for(int j=1;j<=n;j++){
		change(rk[j],1);
		while(Q[cnt].x==j){
			ans[Q[cnt].v]=getsum(Q[cnt].y);
			cnt++;
			//cout<<cnt<<" "<<j<<endl;
		}
	}
	//cout<<"sad"<<endl;
	//for(int j=1;j<=n;j++) cout<<getsum(j)<<endl;
	//cout<<"sad"<<endl;
	for(int j=0;j<m;j++) printf("%d\n",ans[j]);
	return 0;
}
/*
6 3
3 2 5 4 6 1
4 4
2 5
6 4
5 5
*/
