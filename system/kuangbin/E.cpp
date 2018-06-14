#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
struct tt{
    struct dd{
        int sum,laz;
    }p[100010<<2];
    void pushup(int rt){
        p[rt].sum=p[rt<<1].sum+p[rt<<1|1].sum;
    }
    void pushdown(int rt,int m){
        if(p[rt].laz){
            p[rt<<1].laz=p[rt<<1|1].laz=p[rt].laz;
            p[rt<<1].sum=(m-(m>>1))*p[rt].laz;
            p[rt<<1|1].sum=(m>>1)*p[rt].laz;
            p[rt].laz=0;
        }
    }
    void build(int l,int r,int rt){
        p[rt].laz=0;
        if(l==r){
            p[rt].sum=1;
            return ;
        }
        int m=(l+r)/2;
        build(l,m,rt<<1);
        build(m+1,r,rt<<1|1);
        pushup(rt);
    }
    void update(int ql,int qr,int pp,int l,int r,int rt){
        //cout<<l<<" "<<r<<" "<<pp<<endl;
        if(ql<=l&&qr>=r){
            p[rt].laz=pp;
            p[rt].sum=(r-l+1)*pp;
            return ;
        }
        pushdown(rt,r-l+1);
        int m=(l+r)/2;
        if(ql<=m) update(ql,qr,pp,l,m,rt<<1);
        if(qr>m) update(ql,qr,pp,m+1,r,rt<<1|1);
        pushup(rt);
    }
    int query(int ql,int qr,int l,int r,int rt){
        if(ql==l&&qr==r){
            return p[rt].sum;
        }
        pushdown(rt,r-l+1);
        int m=(l+r)/2;
        int ans=0;
        if(ql<=m) ans+=query(ql,qr,l,m,rt<<1);
        if(qr>m) ans+=query(ql,qr,m+1,r,rt<<1|1);
        return ans;
    }
}seg;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\GitHub\\ACM-ICPC\\other\\in.txt","r",stdin);
    #endif
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++){
        int n;
        scanf("%d",&n);
        seg.build(1,n,1);
        //cout<<seg.p[1].sum<<endl;
        int q,a,b,c;
        scanf("%d",&q);
        //cout<<T<<n<<q<<endl;
        while(q--){
            scanf("%d%d%d",&a,&b,&c);
            seg.update(a,b,c,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",ca,seg.p[1].sum);
    }
    return 0;
}