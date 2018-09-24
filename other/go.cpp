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
#define eps 1e-5
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
#define rd(x) scanf("%d",&x)
#define rdd(x,y) scanf("%d%d",&x,&y)
#define rddd(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define rl(x) scanf("%lld",&x)
#define rll(x,y) scanf("%lld%lld",&x,&y)
#define rlll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define pr(x) printf("%d",x)
#define prn(x) printf("%d\n",x)
typedef long long ll;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
const int N=100000+10;
const int mo=1e9+7;
string s,mr,ml,t;
int k;
int getval(string tt){
	int sum=0;
	for(auto v:tt){
		sum=sum*10+(v-'0');
	}
	return sum;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
#endif
	//freopen("1002.in","r",stdin);
	//freopen("C:\\Users\\hlc\\Desktop\\c++\\out.out","w",stdout);
	int _;
	//ios::sync_with_stdio(false);
	//string ttt="123495";
	//cout<<getval(ttt)<<endl;
	cin>>_;
	while(_--) {
		int tim,tt;
		cin>>s>>tim;
		t=s;
		mr=s;
		ml=s;
		int ss=s.size();
		for(int j=0; j<ss; j++) {
			int minn=ml[j]-'0',mx=j;
			for(int k=j+1; k<ss; k++) {
				int tmp=ml[k]-'0';
				if(tmp<=minn) {
					if(tmp==0&&j==0) continue;
					else {
						minn=tmp;
						mx=k;
					}
				}
				//cout<<j<<" "<<k<<endl;
			}
			if(mx!=j)swap(ml[j],ml[mx]);
		}
		for(int j=0; j<ss; j++) {
			int minn=mr[j]-'0',mx=j;
			for(int k=j+1; k<ss; k++) {
				int tmp=mr[k]-'0';
				if(tmp>=minn) {
					minn=tmp;
					mx=k;
				}
			}
			if(mx!=j)swap(mr[j],mr[mx]);
		}
		int mmr=getval(mr),mml=getval(ml);
		tt=tim;
		int nt=getval(t);
		while(nt!=mml&&tim!=0) {
			int las=-1;
			for(int j=0; j<ss; j++) {
				if(tim==0||mml==nt) break;
				int minn=t[j]-'0',mx=j;
				for(int k=j+1; k<ss; k++) {
					int tmp=t[k]-'0';
					if(tmp<minn) {
						if(tmp==0&&j==0) continue;
						else {
							minn=tmp;
							mx=k;
						}
					}
				}
				if(mx!=j) {
					swap(t[j],t[mx]);
					if(j>=1&&t[j]==t[j-1]&&t[mx]<t[las]) swap(t[mx],t[las]);
					las=mx;
					tim--;
					nt=getval(t);
				}
			}
			//cout<<t<<" "<<ml<<endl;
		}
		int ns=getval(s);
		while(ns!=mmr&&tt!=0) {
			int las=-1;
			for(int j=0; j<ss; j++) {
				if(tt==0||ns==mmr) break;
				int minn=s[j]-'0',mx=j;
				for(int k=j+1; k<ss; k++) {
					int tmp=s[k]-'0';
					if(tmp>minn) {
						minn=tmp;
						mx=k;
					}
				}
				//cout<<j<<" "<<mx<<endl;
				if(mx!=j) {
					//cout<<"de"<<mx<<endl;
					swap(s[j],s[mx]);
					if(j>=1&&s[j]==s[j-1]&&s[mx]>s[las])
						swap(s[mx],s[las]);
					las=mx;
					tt--;
					ns=getval(s);
				}
			}
			//cout<<s<<endl;
		}
		cout<<t<<" "<<s<<endl;
		//cout<<ml<<" "<<mr<<endl;
	}
#ifndef ONLINE_JUDGE
	printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
#endif
}
