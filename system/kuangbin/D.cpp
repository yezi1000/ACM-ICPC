#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define rd(x) scnaf("%d",&x);
#define rdd(x,y) scanf("%d%d",&x,&y)
using namespace std;
vector<int>q;
set<int>as;
struct node{
    struct dd{
        int l,r;
        int mx,laz;
        int mid(){return (l+r)/2;}
    }p[(10010<<2)];
    void pushup(int rt){
        p[rt].mx=max(p[rt<<1].mx,p[rt<<1|1].mx);
    }
    void pushdown(int rt){
        if(p[rt].laz){
            p[rt<<1].laz=p[rt<<1|1].laz=p[rt].laz;
            p[rt<<1].mx=p[rt<<1|1].mx=p[rt].laz;
        }
    }
    void build(int l,int r,int rt){
        p[rt].l=l;p[rt].r=r;p[rt].laz=0;
        if(l==r) {
            p[rt].mx=0;
            return ;
        }
        int m=p[rt].mid();
        build(l,m,rt<<1);
        build(m+1,r,rt<<1|1);
        pushup(rt);
    }
    void update(int ql,int qr,int pp,int rt){
        cout<<"up "<<ql<<" "<<qr<<" "<<pp<<" "<<endl;
        cout<<"rt "<<p[rt].l<<" "<<p[rt].r<<" "<<p[rt].mx<<" "<<p[rt].laz<<endl;
        if(p[rt].l>=ql&&p[rt].r<=qr) p[rt].mx=p[rt].laz=pp;
        pushdown(rt);
        int m=p[rt].mid();
        if(ql<=m) update(ql,qr,pp,rt<<1);
        if(qr>m) update(ql,qr,pp,rt<<1|1);
        pushup(rt);
    }
    void find(int rt){
        if(p[rt].l==p[rt].r) as.insert(p[rt].mx);
        int m=p[rt].mid();
        find(rt<<1);
        find(rt<<1|1);
    }
}seg;
struct nodd{
    int l,r;
}ask[11111];
int find(int n){
    return lower_bound(q.begin(),q.end(),n)-q.begin()+1;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,a,b;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            rdd(a,b);
            q.push_back(a);
            q.push_back(b);
            ask[j].l=a;ask[j].r=b;
        }
        sort(q.begin(),q.end());
        q.erase(unique(q.begin(),q.end()),q.end());
        int ss=q.size();
        for(int j=0;j<ss-1;j++)
            if(q[j+1]-q[j]>1) q.push_back(q[j]+1);
        sort(q.begin(),q.end());
        ss=q.size();
        for(int j=0;j<n;j++){
            int fl=find(ask[j].l),fr=find(ask[j].r);
            seg.update(fl,fr,j+1,1);
        }
        cout<<"eoo"<<endl;
        seg.find(1);
        cout<<as.size()<<endl;
    }
}