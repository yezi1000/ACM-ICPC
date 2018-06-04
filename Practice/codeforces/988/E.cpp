#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<ctime>
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
bool f(string s){
    int cnt=0;
    if(s.find("00")==string::npos) cnt++;
    if(s.find("25")==string::npos) cnt++;
    if(s.find("57")==string::npos)cnt++;
    if(s.find('5')==string::npos||s.find('5')==string::npos) cnt++;
    if(cnt==4) return false;
    return true;
}
int ff[10];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    string str;
    cin>>str;
    string t;
    int ss=str.size();
    for(int j=0;j<ss;j++) if(str[j]=='0'||str[j]=='2'||str[j]=='5'||str[j]=='7') t+=str[j];
    sort(all(t));
    //cout<<t<<endl;
    if(!f(t)) cout<<-1<<endl;
    else{
        for(int j=ss-1;j>=0;j--){
            if(ff[str[j]-'0']==0) ff[str[j]-'0']=j;
        }
        int ou=100000000;
        if(t.find("00")!=string::npos){
            for(int j=ff[0]-1;j>=0;j--){
                if(str[j]=='0') ou=min(ou,2*ss-j-ff[0]);
            }
        } 
    }
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}