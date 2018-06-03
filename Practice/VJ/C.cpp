#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<vector>  
#include<map>  
#include <set>  
#include <bits/stdc++.h>  
using namespace std;  
const int N = 1e5+10;  
typedef long long LL;  
vector<int>p[N];  
set<LL>st;  
int vis[N],out[N], link[N];  
  
int main()  
{  
    int  m;  
    LL n;  
    while(scanf("%lld %d", &n, &m)!=EOF)  
    {  
        for(int i=0;i<=n;i++) p[i].clear();  
        st.clear();  
        memset(link,0,sizeof(link));  
        memset(out,0,sizeof(out));  
        for(int i=0;i<m;i++)  
        {  
            LL x, y;  
            scanf("%lld %lld", &x, &y);  
            p[x].push_back(y),p[y].push_back(x);  
            st.insert(x*n+y),st.insert(y*n+x);  
            out[x]++,out[y]++;  
        }  
        int maxt=sqrt(1.0*m);  
        memset(vis,0,sizeof(vis));  
        LL ans=0;  
        int x, y, z;  
        for(int i=1;i<=n;i++)  
        {  
            vis[i]=1,x=i;  
            for(int j=0;j<p[x].size();j++)  
            {  
                y=p[x][j];  
                link[y]=x;  
            }  
            for(int j=0;j<p[x].size();j++)  
            {  
                y=p[x][j];  
                if(vis[y]) continue;  
                LL sum=0;  
                if(out[y]<=maxt)  
                {  
                    for(int k=0;k<p[y].size();k++)  
                    {  
                        int z=p[y][k];  
                        if(link[z]==x) sum++;  
                    }  
                }  
                else  
                {  
                    for(int k=0;k<p[x].size();k++)  
                    {  
                        int z=p[x][k];  
                        if(st.find(z*n+y)!=st.end()) sum++;  
                    }  
                }  
                ans=ans+(sum*(sum-1)/2);  
            }  
        }  
        printf("%lld\n",ans);  
    }  
    return 0;  
}  