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
const int maxn=100000+10;
char s[maxn],t[maxn];
int sa[maxn],ta[maxn];
int sb[maxn],tb[maxn];
int scnt,tcnt;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    string a,b;
    while(cin>>a>>b){
        int ls=strlen(s);
		int lt=strlen(t);
		CL(sa);CL(sb);CL(ta);CL(tb);
		for (int i=0; i<ls; i++) {
			if (s[i]=='c') {
				scnt++;
			} else if (s[i]=='a') {
				sa[scnt]++;
			} else sb[scnt]++;
		}
		for (int i=0; i<lt; i++) {
			if (t[i]=='c') {
				tcnt++;
			} else if (t[i]=='a') {
				ta[tcnt]++;
			} else tb[tcnt]++;
		}
		if (scnt!=tcnt) {
			printf("No\n");
			continue;
		}
		int f=1;
		for (int i=0; i<=scnt; i++) {
			if ((sa[i]-ta[i])%2!=0||(sb[i]-tb[i])%2!=0) {
				f=0;
				break;
			}
		}
		printf("%s\n",f?"Yes":"No");
    }
    #ifndef ONLINE_JUDGE
    //printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}