#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
struct segtree{
    struct dd{
        ll sum,laz;
    }p[(100000<<2)];
    void pushup(int rt){
        p[rt].sum=p[rt<<1].sum+p[rt<<1|1].sum;
    }
    void pushdown(int rt,int m){
        if(p[rt].laz){
            p[rt<<1].laz+=p[rt].laz;
            p[rt<<1|1].laz+=p[rt].laz;
            p[rt<<1].sum+=1LL*p[rt].laz*(m-(m>>1));
            p[rt<<1|1].sum+=1LL*p[rt].laz*(m>>1);
            p[rt].laz=0;
        }
    }
    void build(int l,int r,int rt){
    	p[rt].laz=0;
    	//cout<<l<<" "<<r<<" "<<rt<<endl;
        if(l==r){
            scanf("%lld",&p[rt].sum);
            return ;
        }
        int m=(l+r)/2;
        build(l,m,rt<<1);
        build(m+1,r,rt<<1|1);
        pushup(rt);
    }
    void update(int ql,int qr,ll ad,int l,int r,int rt){
        if(ql<=l&&qr>=r){
            p[rt].sum+=ad*(r-l+1);
            p[rt].laz+=ad;
            return ;
        }
        pushdown(rt,r-l+1);
        int m=(l+r)/2;
        if(ql<=m) update(ql,qr,ad,l,m,rt<<1);
        if(qr>m) update(ql,qr,ad,m+1,r,rt<<1|1);
        pushup(rt);
    }
    ll query(int ql,int qr,int l,int r,int rt){
    	//cout<<p[rt].l<<" "<<p[rt].r<<endl;
        if(ql<=l&&qr>=r)
            return p[rt].sum;
        pushdown(rt,r-l+1);
        int m=(l+r)/2;
        ll ans=0;
        if(ql<=m) ans+=query(ql,qr,l,m,rt<<1);
        if(qr>m) ans+=query(ql,qr,m+1,r,rt<<1|1);
        return ans;
    }
}seg;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int n,q;
    while(~scanf("%d%d",&n,&q)){
        seg.build(1,n,1);
        int a,b;
        ll c;
        char op[10];
        while(q--){
            scanf("%s",op);
            if(op[0]=='Q'){
                scanf("%d%d",&a,&b);
                printf("%lld\n",seg.query(a,b,1,n,1));
            }
            else {
                scanf("%d%d%lld",&a,&b,&c);
                seg.update(a,b,c,1,n,1);
            }
        }
    }
    return 0;
}
