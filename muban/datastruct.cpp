#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
namespace seg{//区间修改区间查值
    const int MX=100000+10;
    struct node{
        int l,r;
        ll val,laz;
        int mid(){return (r+l)/2;}
        int leg(){return (r-l+1);}
    }p[MX<<2];
    void init(){
        memset(p,0,sizeof(p));
    }
    void pushup(int rt){
        p[rt].val=p[rt<<1].val+p[rt<<1|1].val;
    }
    void pushdown(int rt,int n){
        if(p[rt].laz){
            p[rt<<1|1].laz+=p[rt].laz;
            p[rt<<1].laz+=p[rt].laz;
            p[rt<<1].val+=p[rt].laz*(n-(n>>1));
            p[rt<<1|1].val+=p[rt].laz*(n>>1);
            p[rt].laz=0;
        }
    }
    void build(int l,int r,int rt){
        p[rt].l=l;p[rt].r=r;p[rt].laz=0;
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
            p[rt].laz+=c;
            p[rt].val+=1LL*c*(p[rt].leg());
            return ;
        }
        if(p[rt].l==p[rt].r) return ;
        pushdown(rt,p[rt].leg());
        int m=p[rt].mid();
        if(r<=m) update(c,l,r,rt<<1);
        else if(l>m) update(c,l,r,rt<<1|1);
        else{
            update(c,l,m,rt<<1);
            update(c,m+1,r,rt<<1|1);
        }
        pushup(rt);
    }
    ll query(int l,int r,int rt){
        if(l=p[rt].l&&r==p[rt].r)return p[rt].val;
        pushdown(rt,p[rt].leg());
        int m=p[rt].mid();
        ll res=0;
        if(r<=m) res+=query(l,r,rt<<1);
        else if(l>m) res+=query(l,r,rt<<1|1);
        else{
            res+=query(l,m,rt<<1);
            res+=query(m+1,r,rt<<1|1);
        }
        return res;
    }
}
namespace bit {
const int MX=300000+10;
int c[MX],n;
void init(int x) {
	memset(c,0,sizeof(c));
    n=x;
}
int lowbit(int x) {
	return x&(-x);
}
void update(int x,int u) {//单点修改
	while (x<=n) {
		c[x]=(c[x]+u);
		x+=lowbit(x);
	}
}
void iupdate(int l,int r,int u){//区间修改
    update(l,u);
    update(r+1,-u);
}
int sum(int x) {
	int sum=0;
	while (x>0) {
		sum=(sum+c[x]);
		x-=lowbit(x);
	}
	return sum;
}
int getsum(int l,int r) {
	return sum(r)-sum(l-1);
}
} // binary indexed tree