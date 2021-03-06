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
int i, j, ii, jj, x;
int v[200], st[200], dr[200];
char a[55][55];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    for(i = 1; i <= 4; i++){
        cin>> v[i];
        v[i]--;
    }
    for(ii = 'A'; ii <= 'D'; ii++){
        st[ii] = 1 + dr[ii - 1];
        dr[ii] = st[ii] + 9;
        for(i = st[ii]; i <= dr[ii]; i++){
            for(j = 1; j <= 50; j++){
                a[i][j] = ii;
            }
        }
    }
    for(ii = 1; ii <= 4; ii++){
        x = ii + 'A' - 1;
        jj = x + 1;
        if(jj == 'E'){
            jj = 'A';
        }
        for(i = st[jj] + 1; i < dr[jj]; i += 2){
            for(j = 1; j <= 50; j++){
                if( (i + j) % 2 == 1 && v[ii] > 0){
                    v[ii]--;
                    a[i][j] = x;
                }
            }
        }
    }
    cout<<"40 50\n";
    for(i = 1; i <= 40; i++){
        for(j = 1; j <= 50; j++){
            cout<< a[i][j];
        }
        cout<<"\n";
    }
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}