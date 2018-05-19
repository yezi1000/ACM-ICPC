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
vector<string>q;
int main(){
    string s;
    int k;
    cin>>s>>k;
    int n=s.size();
    for (int i=0;i<n;i++){
    	for (int j=1;j<=min(k,n-i);j++){
      	    string t=s.substr(i,j);
            q.push_back(t);
        }
    }
    sort(q.begin(),q.end(),less<string>());
    q.erase(unique(q.begin(),q.end()),q.end());
    cout<<q.size()<<endl;
    sort(q.begin(),q.end(),less<string>());     
    for(int j=0;j<q.size();j++) cout<<q[j]<<endl;
    if(q[1]>q[3]) cout<<"fucxk"<<endl;
    return 0;
}