#include<cstdio>
#include<time.h>
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
#define rdd(x,y) scanf("%d%d",&x,&y)
#define rddd(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pr(x) printf("%d",x)
#define prn(x) printf("%d\n",x)
typedef long long ll;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
const int N=100000+10;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n;cin>>n;
    string s[6]={"purple", "green", "blue", "orange", "red", "yellow"};
    string o[6]={"Power", "Time", "Space", "Soul", "Reality", "Mind"};
    bool a[6]={false};
    int cnt=6;
    while(n--){
        string tmp;
        cin>>tmp;
        for(int j=0;j<6;j++) if(tmp==s[j])a[j]=true,cnt--;
    }
    cout<<cnt<<endl;
    for(int j=0;j<6;j++)if(a[j]==false) cout<<o[j]<<endl;
    #ifndef ONLINE_JUDGE
    printf("\nMy Time:%.3lfms",(double)clock()/CLOCKS_PER_SEC);
    #endif
}