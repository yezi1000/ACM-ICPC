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
#define eps 1e-6
#define pi acos(-1)
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
int low(int x){ return x&(-x);}
int f(int l,int r){
	if(l>=r) return 0;
	else if(r-low(r)>=l) return f(l,r-low(r))+1;
	else return f(l,r-1)+1;
}
void div(int n){
	stack<int>w;
	while(n){
		w.push(n%2);
		n/=2;
	}
	while(!w.empty()){
		cout<<w.top();
		w.pop();
	}
}
int main() {
	int n=1;
	while(n<50){
		int maxn=0,ml,mr;
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(maxn<=f(j,k)){
					maxn=f(j,k);
					ml=j;mr=k;
				}
			}
		}
		cout<<n<<" ";
		div(n);
		cout<<" "<<maxn<<" "<<ml<<" "<<mr<<endl;
		n++;
	}
	return 0;
}
