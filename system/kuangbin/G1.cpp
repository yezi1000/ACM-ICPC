//segment tree
#include<cstdio>
#include<algorithm>
#include<iostream>
#define mp make_pair
using namespace std;
struct tt{
    struct dd{
        int mx,mn;
    }p[100010<<2];
    void pushup(int rt){
        p[rt].mx=max(p[rt<<1].mx,p[rt<<1|1].mx);
        p[rt].mn=min(p[rt<<1].mn,p[rt<<1|1].mn);
    }
    void build(int l,int r,int rt){
        if(l==r){
            int tmp;
            scanf("%d",&tmp);
            p[rt].mn=p[rt].mx=tmp;
			//cout<<l<<" "<<r<<" "<<tmp<<endl;
            return ;
        }
        int m=(l+r)/2;
        build(l,m,rt<<1);
        build(m+1,r,rt<<1|1);
        pushup(rt);
    }
    pair<int,int> query(int ql,int qr,int l,int r,int rt){
        //cout<<l<<" "<<r<<" "<<rt<<endl;
        if(ql<=l&&qr>=r){
            return mp(p[rt].mn,p[rt].mx);
        }
        pair<int,int>res,qa;res.first=1000000001;res.second=-1;
        int m=(l+r)/2;
        if(ql<=m){
            qa=query(ql,qr,l,m,rt<<1);
            res.first=min(res.first,qa.first);
            res.second=max(res.second,qa.second);
        }
        if(qr>m){
            qa=query(ql,qr,m+1,r,rt<<1|1);
            res.first=min(res.first,qa.first);
            res.second=max(res.second,qa.second);
        }
        return res;
    }
}seg;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n,q;
    while(~scanf("%d%d",&n,&q)){
        seg.build(1,n,1);
        while(q--){
            int l,r;
            scanf("%d%d",&l,&r);
            pair<int,int>as=seg.query(l,r,1,n,1);
            printf("%d\n",as.second-as.first);
        }
    }
    return 0;
}
