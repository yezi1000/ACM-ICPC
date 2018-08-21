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
const int OutputBufferSize = 67108864;//输出缓冲区大小
namespace output {
char buffer[OutputBufferSize];
char *s=buffer;
inline void flush() {
	assert(stdout!=NULL);
	fwrite(buffer,1,s-buffer,stdout);
	s=buffer;
	fflush(stdout);
}
inline void print(const char ch) {
	if (s-buffer>OutputBufferSize-2)flush();
	*s++=ch;
}
inline void print(char* str) {
	while (*str!=0)print(char(*str++));
}
inline void print(int x) {
	char buf[25]= {0},*p=buf;
	if (x<0)print('-'),x=-x;
	if (x==0)print('0');
	while (x)*(++p)=x%10,x/=10;
	while (p!=buf)print(char(*(p--)+'0'));
}
}
unordered_map<unsigned long long,int>w;
struct node {
	vector<int>a;
	int sz;
	const bool operator<(const node &b) {
		if (sz==b.sz) {
			for (int j=0; j<sz; j++) {
				if (a[j]==b.a[j]) continue;
				else return a[j]<b.a[j];
			}
			return false;
		} else return sz<b.sz;
	}
} *p;
unsigned long long *las,*hx;
char s[1000010];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    las=new unsigned long long [1000010];
	hx=new unsigned long long [1000010];
	p=new struct node [1000010];

	scanf("%s",s+1);
	int sz=strlen(s+1),cnt=0;
	hx[0]=1;
	for (int j=1; j<=sz; j++) hx[j]=hx[j-1]*131;
	for (int j=sz; j>0; j--) las[j]=las[j+1]*131+(s[j]-'a'+1);
	//for(int j=1;j<=sz;j++) cout<<j<<" "<<las[j]<<endl;
	for (int j=1; j<=sz; j++) {
		unsigned long long xx,xxx;
		xx=las[1]-las[j+1]*hx[j];
		xxx=las[j+1]+xx*hx[sz-j];
		//cout<<xx<<" "<<hx[sz-j]<<" "<<las[j+1]<<" "<<xxx<<endl;
		if (w.find(xxx)==w.end()) w[xxx]=++cnt;
		p[w[xxx]].a.push_back(j-1);
		p[w[xxx]].sz++;
	}
	sort(p+1,p+cnt+1);
	output::print(cnt);output::print('\n');
	for (int j=1; j<=cnt; j++) {
		//cout<<"sz:"<<p[j].sz<<" ";
		output::print(p[j].sz);
		int ma=-1;
		for (auto ww:p[j].a) {
			ma++;
			if (ma==-1) {
				output::print(ww);
				output::print('\n');
			} else {
				output::print(' ');
				output::print(ww);
			}
		}
		output::print('\n');
	}
	output::flush();
	//cout<<w.size()<<endl;

    
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}