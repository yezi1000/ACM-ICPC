#include<cstdio>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
struct segment{
    struct dd{
        int l,r;
        int sum;
        int mid(){return (l+r)/2;}
        int leg(){return (r-l+1);}
    }p[(50000<<4)];
    void pushup(int rt){
        p[rt].sum=max(p[rt].sum,p[rt].sum);
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
    }
    void update(int pos,int add,int rt){
        if(p[rt].l==p[rt].r){
            p[rt].sum+=add;
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
        if(ql<=m)  res+=query(ql,qr,rt<<1);
        if(qr>m) res+=query(ql,qr,rt<<1|1);
        return res;
    }
}seg;
int main(){
    int T,n;
    scanf("%d",&T);
    for(int cs=1;cs<=T;cs++){
        printf("Case %d:\n",cs);
        scanf("%d",&n);
        seg.build(1,n,1);
        char op[10];
        while(1){
			scanf("%s",op);
            if(op[0]=='E') break;
            int a,b;
            scanf("%d%d",&a,&b);
            if(op[0]=='Q') printf("%d\n",seg.query(a,b,1));
            else if(op[0]=='S') seg.update(a,-b,1);
            else seg.update(a,b,1);
        }
    }
    return 0;
}
