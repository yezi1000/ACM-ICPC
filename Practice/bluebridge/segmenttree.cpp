#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
using namespace std;
using namespace segtree{
    int MX=100000+10;
    struct node{
        int l,r;
        ll val,laz;
        int mid(){return (l+r)/2;}
        int leg(){return r-l+1;}
    }p[MX<<2];
    void init(){
        memset(p,0,sizeof(p));
    }
    void pushup(int rt){
        p[rt].val=p[rt<<1].val+p[rt<<|1].val;
    }
    void pushdown(int rt,int num){
        if(p[rt].laz){
            p[rt<<1].laz=p[rt].laz;
            p[rt<<1|1]+=p[rt].laz;
            p[rt<<1]+=p[rt].laz*(num-(num>>1));
            p[rt<<1|1]+=p[rt].laz*(num>>1);
            p[rt].laz=0;
        }
    }
    void build(int l,int r,int rt){
        p[rt].l=l;p[rt].l=r;
        p[rt].laz=0;
        if(l==r){
            scanf("%lld",&p[rt].val);
            return ;
        }
        int m=p[rt].mid();
        build(lson);
        build(rson);
        pushup(rt);
    }
    void update(int c,int l,int r,int rt){
        if(p[rt].l==l&&p[rt].r==r){
            add[rt]+=c;
            sum[rt]+=1LL*c*(r-l+1);
            return ;
        }
        if(p[rt].l==p[rt].r) return ;
        pushdown(rt,p[rt].leg());
        int m=p[rt].mid();
        if(r<=m) update(c,l,r,rt<<1);
        else if(l>=m) update(c,l,r,rt<<1|1);
        else{
            update(c,l,m,rt<<1);
            update(c,m+1,r,rt<<1|1);
        }
        pushup(rt);
    }
    ll query(int l,int r,int rt){
        if(l==p[rt].l&&r==p[rt].r){
            return p[rt].val;
        }
        pushdown(rt,p[rt].leg());
        int m=p[rt].mid();
        ll ans=0;
        if(r<=m) ans+=query(l,r,rt<<1);
        else if(l>m) ans+=query(l,r,rt<<1|1);
        else{
            ans+=query(l,m,rt<<1);
            ans+=query(m+1,r,rt<<1|1);
        }
        retrun ans;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    
}