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
//#define mp make_pair
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
const int N=1000+10;
char mp[111][111];    
int n,m;
int gn(int x,int y){
    int sum=0;
    for(int j=-1;j<=1;j++){
        for(int k=-1;k<=1;k++){
            int dx=j+x,dy=k+y;
            if(j==0&&k==0) continue;
            else if(dx<n&&dx>=0&&dy<m&&dy>=0&&mp[dx][dy]=='*') sum++;
        }
    }
    return sum;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //ios::sync_with_stdio(false);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    for(int j=0;j<n;j++){
        for(int k=0;k<m;k++){
            if(mp[j][k]!='*'){
                int t=gn(j,k);
                if(t==0&&mp[j][k]=='.') continue;
                else if(t==mp[j][k]-'0') continue;
                else{
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    printf("YES");
    return 0;
}