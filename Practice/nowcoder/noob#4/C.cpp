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
int mm[1111][1111];
int co[1111][1111];
int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
bool check(int n){
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
            if(co[j][k]>=2)
                return true;
        }
    }
    return false;
}
bool ch2(int n){
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
            if(mm[j][k]==0) return false;
        }
    }
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n,m;
    rdd(n,m);
    int tx,ty;
    for(int j=1;j<=m;j++){
        rdd(tx,ty);
        mm[tx][ty]=1;
    }
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
            for(int l=0;l<4;l++){
                int dx=dir[l][0]+j,dy=dir[l][1]+k;
                if(dx>=1&&dx<=n&&dy>=1&&dy<=n){
                    co[j][k]+=mm[dx][dy];
                }
            }
        }
    }
    //int tt=1;
    while(check(n)){
    	//cout<<"eoo"<<endl;
    	/*for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)
				cout<<co[j][k]<<" ";
			cout<<endl;
    	}*/
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(co[j][k]>=2&&mm[j][k]!=1){
					//cout<<"tm"<<j<<" "<<k<<endl;
                    mm[j][k]=1;
                    co[j][k]=0;
                    for(int l=0;l<4;l++){
                        int dx=j+dir[l][0],dy=k+dir[l][1];
                        if(dx>=1&&dx<=n&&dy>=1&&dy<=n){
							co[dx][dy]++;
							//cout<<j<<"ch"<<dx<<" "<<dy<<endl;
                        }
                    }
                }
                if(co[j][k]>=2&&mm[j][k]==1) co[j][k]=0;
            }
        }
        //tt++;
        //if(tt>10) break;
    }
    if(ch2(n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    #ifndef ONLINE_JUDGE
    printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
}
