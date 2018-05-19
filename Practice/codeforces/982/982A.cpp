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
typedef unsigned long long ull;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
ll inv(ll a,ll p) {return expow(a,p-2,p);}
using namespace std;
const int N=1000+10;
string s;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("F:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    cin>>s;
    if(n==1&&s[0]=='0') {cout<<"No";return 0;}
    bool f=false;
    for(int j=0;j<n;j++){
        if(s[j]=='0'){
            int cnt=0;
            if(j==n-1||s[j+1]=='0') cnt++;
            if(j==0||s[j-1]=='0') cnt++;
            if(cnt==2){f=true;break;}
        }
        else{
            if(j+1<n&&s[j+1]=='1'){f=true;break;}
            if(j-1>=0&&s[j-1]=='1'){f=true;break;}
        }
    }
    if(f) cout<<"No";
    else cout<<"Yes";
    return 0;
}