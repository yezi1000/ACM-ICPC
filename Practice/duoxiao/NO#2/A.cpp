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
int dp[N][2],ans[N];
int q,k;
const int mo=1000000007;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    while(~rdd(q,k)){
		memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int j=1;j<N-1;j++){
            dp[j][0]+=dp[j-1][0]+dp[j-1][1];
            if(j-k>=0) dp[j][1]+=dp[j-k][0];
        }
        //for(int j=1;j<10;j++) cout<<"de"<<dp[j][0]<<" "<<dp[j][1]<<endl;
        ans[0]=0;
        for(int j=1;j<N-1;j++)
			ans[j]=(ans[j-1]+dp[j][0]+dp[j][1])%mo;
        while(q--){
            int l,r;cin>>l>>r;
            if(l==r) cout<<(ans[l]-ans[l-1]+mo)%mo<<endl;
            else cout<<(ans[r]-ans[l-1]+mo)%mo<<endl;
        }
    }
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}
