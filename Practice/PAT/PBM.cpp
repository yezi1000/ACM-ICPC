#include<iostream>
#include<stdio.h>
#include<vector>
#include<functional>
#define MAXN 505
#define INFINITY 65535
using namespace std;
 
int Cmax,Sp,M,N;
int SBike[MAXN],G[MAXN][MAXN],visited[MAXN];
int dist[MAXN];
vector<int>result;
vector<int>CurResult;
int SendBike=0,GetBike=0;
int MinSendBike=INFINITY,MinGetBike=INFINITY;
 
int FindMin()
{
    int tmp=INFINITY;
    int Mini=-1,i;
    for (i=1;i<=N;i++)
    {
        if (!visited[i] && dist[i]<tmp)
        {
            tmp=dist[i];
            Mini=i;
        }
    }
    return Mini;
}
 
void Dijkra()
{
    int i,v;
    dist[0]=0;
    visited[0]=1;
    for (i=1;i<=N;i++)
    {
        if (G[0][i]<INFINITY)dist[i]=G[0][i];
    }
 
    while (1)
    {
        v=FindMin();
        if (v==-1)break;
        visited[v]=1;
        for (i=1;i<=N;i++)
        {
            if (!visited[i] && dist[i]>dist[v]+G[v][i])
            dist[i]=dist[v]+G[v][i];
        }
    }
}
 
void Count()
{
    int i;
    GetBike=0;
    SendBike=0;
    for (i=0;i<CurResult.size();i++)
    {
        if (GetBike+SBike[CurResult[i]]>=Cmax/2)GetBike=GetBike+SBike[CurResult[i]]-Cmax/2;
        else {SendBike+=(Cmax/2-GetBike-SBike[CurResult[i]]);GetBike=0;}
    }
}
 
void DFS(int src)
{
    if (src==Sp)
    {
        Count();
        if ((SendBike<MinSendBike)||(SendBike==MinSendBike && GetBike<MinGetBike))
        {
            MinSendBike=SendBike;
            MinGetBike=GetBike;
            result=CurResult;
        }
        return ;
    }
    int i;
    for (i=1;i<=N;i++)
    {
        if (src!=i && !visited[i] && dist[i]==dist[src]+G[src][i])
        {
            CurResult.push_back(i);
            visited[i]=1;
            DFS(i);
            visited[i]=0;
            CurResult.pop_back();
        }
    }
}
int main()
{
    scanf("%d %d %d %d",&Cmax,&N,&Sp,&M);
    int i,j,a,b,v;
    for (i=1;i<=N;i++)scanf("%d",&SBike[i]);
 
    for (i=0;i<=N;i++)
    {
        visited[i]=0;
        dist[i]=INFINITY;
        for (j=0;j<=N;j++)G[i][j]=INFINITY;
    }
 
    for (i=0;i<M;i++)
    {
        scanf("%d %d %d",&a,&b,&v);
        G[a][b]=G[b][a]=v;
    }
 
    Dijkra();
    for (i=0;i<=N;i++)visited[i]=0;
    visited[0]=1;
 
    DFS(0);
 
    printf("%d 0",MinSendBike);
    for (i=0;i<result.size();i++)printf("->%d",result[i]);
    printf(" %d",MinGetBike);
    return 0;
}
