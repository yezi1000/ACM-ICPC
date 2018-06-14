#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
struct segment{
    struct dd{
        int l,r;
        int sum;
        int mid(){return (l+r)/2;}
        int leg(){return (r-l+1);}
    }p[(200000<<4)];
    void pushup(int rt){
        p[rt].sum=max(p[rt<<1].sum,p[rt<<1|1].sum);
    }
    void build(int l,int r,int rt){
        p[rt].l=l;p[rt].r=r;
        if(l==r){
            scanf("%d",&p[rt].sum);
            return ;
        }
        int m=p[rt].mid();
        build(lson);
        build(rson);
        pushup(rt);
        //cout<<l<<" "<<r<<" "<<p[rt].sum<<endl;
    }
    void update(int pos,int add,int rt){
        if(p[rt].l==p[rt].r){
            p[rt].sum=add;
            return ;
        }
        int m=p[rt].mid();
        if(pos<=m) update(pos,add,rt<<1);
        else update(pos,add,rt<<1|1);
        pushup(rt);
    }
    int query(int ql,int qr,int rt){
        if(ql<=p[rt].l&&p[rt].r<=qr){
            return p[rt].sum;
        }
        int m=p[rt].mid();
        int res=0;
        if(ql<=m)  res=max(res,query(ql,qr,rt<<1));
        if(qr>m) res=max(res,query(ql,qr,rt<<1|1));
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
        char op[10];
        while(q--){
            scanf("%s",op);
            int a,b;
            scanf("%d%d",&a,&b);
            //cout<<a<<" "<<b<<endl;
            if(op[0]=='Q') printf("%d\n",seg.query(a,b,1));
            else seg.update(a,b,1);
        }
    }
    return 0;
}
