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
const int N=1000000;
const int maxnode = 4000 * 100 + 10;  
const int sigma_size = 26;  
  
// 字母表为全体小写字母的Trie  
struct Trie {  
  int ch[maxnode][sigma_size];  
  int val[maxnode];  
  int sz; // 结点总数  
  void clear() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); } // 初始时只有一个根结点  
  int idx(char c) { return c - 'a'; } // 字符c的编号  
  
  // 插入字符串s，附加信息为v。注意v必须非0，因为0代表“本结点不是单词结点”  
  void insert(const char *s, int v) {  
    int u = 0, n = strlen(s);  
    for(int i = 0; i < n; i++) {  
      int c = idx(s[i]);  
      if(!ch[u][c]) { // 结点不存在  
        memset(ch[sz], 0, sizeof(ch[sz]));  
        val[sz] = 0;  // 中间结点的附加信息为0  
        ch[u][c] = sz++; // 新建结点  
      }  
      u = ch[u][c]; // 往下走  
    }  
    val[u] = v; // 字符串的最后一个字符的附加信息为v  
  }  
  
  // 找字符串s的长度不超过len的前缀  
  bool find(const char *s, int len) {  
    int u = 0;  
    for(int i = 0; i < len; i++) {  
      if(s[i] == '\0') break;  
      int c = idx(s[i]);  
      if(!ch[u][c]) break;  
      u = ch[u][c];  
      if(val[u] != 0) return true; // 找到一个前缀  
    }  
    return false;  
  }  
};
char s[140];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    L[0].init();L[1].init();
    while(gets(s)){
        if(strlen(s)==0) break;
        add(s,strlen(s));
        //cout<<s<<endl;
    }
    while(gets(s)){
        cout<<s<<" "<<strlen(s)<<endl;
        printf("%d\n",query(s,strlen(s)));
    }
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}