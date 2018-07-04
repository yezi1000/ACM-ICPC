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
const int N=400000+10;
vector<PII>w;
int dd[N];
int main() {
	int n,d,k;
	rddd(n,d,k);
	if(d==2) {
		if(n==2) cout<<"1 2"<<endl;
		else cout<<"-1"<<endl;
		return 0;
	}
	int gg=min(n,d);
	for(int j=2; j<=gg; j++) {
		w.pb(mp(j-1,j));
		//cout<<"fr"<<j-1<<" "<<j<<endl;
		dd[j-1]++;
		dd[j]++;
	}
	int cnt=1,tot=gg+1;
	for(int j=1; j<=gg; j++) {
		bool f=false;
		cnt=min(cnt,d/2);
		if(dd[j]<=k) {
			int add=cnt*(k-dd[j]);
			for(int q=1; q<=add; q++) {
				if(tot==n+1) {
					f=true;
					break;
				}
				w.pb(mp(j,tot));
				tot++;
			}
			dd[j]=k;
		}
		//cout<<j<<" "<<cnt<<endl;
		if(gg%2==0) {
			if(j<gg/2) cnt++;
			if(j>gg/2) cnt--;
		} else {
			if(j<=gg/2) cnt++;
			else cnt--;
		}
		if(f) break;
	}
	if(tot!=n+1) {
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(int j=0; j<(int)w.size(); j++) cout<<w[j].first<<" "<<w[j].second<<endl;
#ifndef ONLINE_JUDGE
	printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}

