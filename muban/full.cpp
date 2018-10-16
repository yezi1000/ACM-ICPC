Header:
#include<bits/stdc++.h>
#include<time.h>
#define eps 1e-8
#define pi 3.14159265358979
#define MP make_pair
#define PH push
#define PB push_back
#define PII pair<int,int>
#define VI vector<int>
#define X first
#define Y second
#define sqr(x) ((x)*(x))
#define CL(a) memset(a,0,sizeof a)
#define fr(i,n) for(int i=1;i<=n;i++)
#define FR(i,S,n) for(int i=S;i<=n;i++)
#define dr(i,n) for(int i=n;i;i--)
#define DR(i,n,S) for(int i=n;i>=S;i--)
#define SZ(x) ((int)(x).size())
#define rd(x) scanf("%d",&x)
#define pr(x) printf("%d",x)
typedef long long ll;
const int N=1111;
const int M=100000007;
ll expow(ll a,ll b,ll p) {ll v=1; for (; b; b>>=1,a=a*a%p)if (b&1)v=v*a%p; return v;}
inline ll inv2(ll b){return b==1?1:(mod-mod/b)*inv2(mod%b)%mod;}
/*
ll fac[1000005];
void init(){
    fac[0]=fac[1]=1;
    for (int i=2;i<=1000000;i++) fac[i]=fac[i-1]*i%mod;
}
ll C(ll n,ll m){
    return fac[n]*inv2(fac[m])%mod*inv2(fac[n-m])%mod;
}
*/
using namespace std;
IO：
fread:
namespace IO {
    const int MX = 4e7;
    char buf[MX]; int c, sz;
    void init(){
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool II(int &t){
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}
记得IO::init

getchar:
inline int in()
{
        register int num=0;
        register char ch;
        do ch=getchar(); while (ch<'0' || ch>'9');
        do num=num*10+ch-'0', ch=getchar(); while (ch>='0' && ch<='9');
        return num;
}
inline ll in()
{
        register ll num=0;
        register char ch;
        do ch=getchar(); while (ch<'0' || ch>'9');
        do num=num*10+ch-'0', ch=getchar(); while (ch>='0' && ch<='9');
        return num;
}
java高精度
import java.io.PrintWriter;
import java.math.BigInteger;
import java.math.BigDecimal;
import java.util.Scanner;
public class Main {
    static BigInteger gcd(BigInteger a,BigInteger b){
        if(!b.equals(BigInteger.ZERO)) return gcd(b,a.mod(b));
        return a;
    }
    public static void main(String args[]){
        Scanner cin=new Scanner(System.in);
        PrintWriter cout = new PrintWriter(System.out, true);

        int n,m;
        BigInteger a,b,c;
        BigDecimal aa,bb,cc;
        String s;
        BigInteger zero = new BigInteger("0");
//        int T = cin.nextInt();
//        while(T>0)
        while(cin.hasNext())
        {
//        	T--;
            n = cin.nextInt();
	        a = BigInteger.valueOf(n);
	        b = cin.nextBigInteger();
	        c = cin.nextBigInteger(2);//二进制
	        System.out.println(c.toString(2));
        	aa = cin.nextBigDecimal();
        	System.out.println(a+" "+aa);
            if(a.compareTo(zero)==0)break;
	        a = a.add(b);
	        a = a.subtract(b);
	        a = a.divide(b);
	        a = a.multiply(b);
	        a = a.remainder(b);//a%b
	        a = a.pow(n);
	        s = aa.toPlainString();
        	if (s.charAt(n) == '0')
				cout.println("0");
            int x = 0, y = s.length() - 1;
            cout.println(s.substring(x, y));
        }
    }
}
数学：
快速幂
long long modexp ( long long a, long long b, int mod ) {
        long long res = 1;
        while ( b > 0 ) {
                if ( b & 1 )
                        res = res * a % mod;
                b = b >> 1;
                a = a * a % mod;
        }
        return res;
}
欧拉筛
bool isprime[10000001];
int prime[10000001];
int p=0;
void get_prime ( int n )
{
        memset ( isprime, true, sizeof ( isprime ) );
        isprime[0] = isprime[1] = false;
        for ( int k = 2; k <= n; k++ )
        {
                if ( isprime[k] )
                        prime[p++] = k;
                for ( int i = 0; i < p; i++ )
                {
                        if ( k * prime[i] > n )
                                break;
                        isprime[k * prime[i]] = false;
                        if ( k % prime[i] == 0 )
                                break;
                }
        }
}
GCD
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int extgcd(int a,int b,int &x,int &y){
    if (b==0){
        x=1,y=0;
        return a;
    }
    int q=gcd(b,a%b,y,x);
    y-=a/b*x;
    return q;
}
BM:
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {
        ll res=1;
        a%=mod;
        assert(b>=0);
        for(; b; b>>=1) {
                if(b&1)res=res*a%mod;
                a=a*a%mod;
        }
        return res;
}

int _;
ll n;
namespace linear_seq {
        const int N=10010;
        ll res[N],base[N],_c[N],_md[N];
        vector<int> Md;
        void mul(ll *a,ll *b,int k) {
                rep(i,0,k+k) _c[i]=0;
                rep(i,0,k) if (a[i]) rep(j,0,k) _c[i+j]=(_c[i+j]+a[i]*b[j])%mod;
                for (int i=k+k-1; i>=k; i--) if (_c[i])
                                rep(j,0,SZ(Md)) _c[i-k+Md[j]]=(_c[i-k+Md[j]]-_c[i]*_md[Md[j]])%mod;
                rep(i,0,k) a[i]=_c[i];
        }
        int solve(ll n,VI a,VI b) { // a 系数 b 初值 b[n+1]=a[0]*b[n]+...
                //        printf("%d\n",SZ(b));
                ll ans=0,pnt=0;
                int k=SZ(a);
                assert(SZ(a)==SZ(b));
                rep(i,0,k) _md[k-1-i]=-a[i];
                _md[k]=1;
                Md.clear();
                rep(i,0,k) if (_md[i]!=0) Md.push_back(i);
                rep(i,0,k) res[i]=base[i]=0;
                res[0]=1;
                while ((1ll<<pnt)<=n) pnt++;
                for (int p=pnt; p>=0; p--) {
                        mul(res,res,k);
                        if ((n>>p)&1) {
                                for (int i=k-1; i>=0; i--) res[i+1]=res[i];
                                res[0]=0;
                                rep(j,0,SZ(Md)) res[Md[j]]=(res[Md[j]]-res[k]*_md[Md[j]])%mod;
                        }
                }
                rep(i,0,k) ans=(ans+res[i]*b[i])%mod;
                if (ans<0) ans+=mod;
                return ans;
        }
        VI BM(VI s) {
                VI C(1,1),B(1,1);
                int L=0,m=1,b=1;
                rep(n,0,SZ(s)) {
                        ll d=0;
                        rep(i,0,L+1) d=(d+(ll)C[i]*s[n-i])%mod;
                        if (d==0) ++m;
                        else if (2*L<=n) {
                                VI T=C;
                                ll c=mod-d*powmod(b,mod-2)%mod;
                                while (SZ(C)<SZ(B)+m) C.pb(0);
                                rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
                                L=n+1-L;
                                B=T;
                                b=d;
                                m=1;
                        } else {
                                ll c=mod-d*powmod(b,mod-2)%mod;
                                while (SZ(C)<SZ(B)+m) C.pb(0);
                                rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
                                ++m;
                        }
                }
                return C;
        }
        int gao(VI a,ll n) {
                VI c=BM(a);
                c.erase(c.begin());
                rep(i,0,SZ(c)) c[i]=(mod-c[i])%mod;
                return solve(n,c,VI(a.begin(),a.begin()+SZ(c)));
        }
};
int main() {
        int T;
        //ptr();
        scanf("%d", &T);
        while(T--) {
                scanf("%lld",&n);
                printf("%lld\n",linear_seq::gao(VI{1,1,2,3,5,8},n - 2));
        }
        return 0;
}

期望求法:
1.期望dp方程，通过之前某个位置的期望，推算当前的期望，通常拿上一个状态的期望乘以从那个状态转移到当前状态的概率加上当前的权值。
如果没有环，则是直接用dp来递推，如果有环，常会用高斯消元来搞。
2.概率dp，求出最后的所有末状态的dp，并且算出每个状态的权值，把概率乘以权值累加起来。
3.排列组合。对于某种权值，计算它的贡献，即 包括这种权值的状态数/总状态数*权值，然后积累所有权值类型

Lucas 求c(n,m)
ll Comb ( ll a, ll b, ll p ) {
	if ( a < b )   return 0;
	if ( a == b )  return 1;
	if ( b > a - b )   b = a - b;
	ll ans = 1, ca = 1, cb = 1;
	for ( ll i = 0; i < b; ++i ) {
		ca = ( ca * ( a - i ) ) % p;
		cb = ( cb * ( b - i ) ) % p;
	}
	ans = ( ca * expow ( cb, p - 2, p ) ) % p;
	return ans;
}
ll Lucas ( int n, int m, int p ) {
	ll ans = 1;
	while ( n && m && ans ) {
		ans = ( ans * Comb ( n % p, m % p, p ) ) % p;
		n /= p;
		m /= p;
	}
	return ans;
}
struct Matrix
{
    long long ma[N][N];
    long long n,m;
};
Matrix matMul(Matrix m1, Matrix m2, long long mod)
{
    Matrix ans;
    memset(ans.ma,0,sizeof(ans.ma));
    for(int i=0;i<m1.n;i++)
        for(int j=0;j<m2.m;j++)
            for(int k=0;k<m1.m;k++)
                ans.ma[i][j]=(ans.ma[i][j]+m1.ma[i][k]*m2.ma[k][j]+mod)%mod;
    ans.n=m1.n; ans.m=m2.m;
    return ans;
}
Matrix matPow(Matrix m1, long long k, long long mod)
{
    Matrix ans;
    for(int i=0;i<m1.n;i++)
        for(int j=0;j<m1.m;j++)
            ans.ma[i][j] = (i==j);
    ans.n=ans.m=m1.n;
    while(k)
    {
        if(k&1)ans = matMul(ans,m1,mod);
        m1 = matMul(m1,m1,mod);
        k>>=1;
    }
    return ans;
}

数据结构
树状数组
#define maxn 50047    
int c[maxn], a[maxn];   
int n,t;  
int Lowbit(int x)  // 2^k  
{  
    return x&(-x);  
}  
void update(int i, int x)//i点增量为x  
{  
    while(i <= n)  
    {  
        c[i] += x;  
        i += Lowbit(i);  
    }  
}  
int sum(int x)//区间求和 [1,x]  
{  
    int sum=0;  
    while(x>0)  
    {  
        sum+=c[x];  
        x-=Lowbit(x);  
    }  
    return sum;  
}  
int Getsum(int x1,int x2) //求任意区间和  
{   
    return sum(x2) - sum(x1-1);   
}
int main()   
{   
    int i , j;  
    scanf("%d",&t);   
    int count = 0;   
    while(t--)   
    {   
        count++;   
        memset(a,0,sizeof(a));   
        memset(c,0,sizeof(c));   
        scanf("%d",&n);   
        for(i = 1; i <= n; i++) //i须从1开始  
        {   
            scanf("%d",&a[i]);   
            update(i,a[i]); //初始的人数  
        }     
        printf("Case %d:\n",count);   
        char oper[11];   
        while(scanf("%s",oper)==1)   
        {   
            if(strcmp(oper,"End")==0)   
                break;   
            scanf("%d%d",&i,&j);   
            if(strcmp(oper,"Query")==0)   
            {   
                printf("%d\n",Getsum(i,j));   
            }   
            if(strcmp(oper,"Add")==0) //表示第i个营地增加j个人  
            {   
                a[i] += j;   
                update(i,j);   
            }   
            if(strcmp(oper,"Sub")==0) //表示第i个营地减少j个人  
            {   
                a[i] -= j;   
                update(i,-j);   
            }   
        }   
    }   
    return 0;   
}   

普通线段树，单点修改区间求和
#define lson l , m , rt << 1  
#define rson m + 1 , r , rt << 1 | 1  
const int maxn = 55555;  
int sum[maxn<<2];  
void PushUP(int rt) {  
       sum[rt] = sum[rt<<1] + sum[rt<<1|1];  
}  
void build(int l,int r,int rt) {  
       if (l == r) {  
              scanf("%d",&sum[rt]);  
              return ;  
       }  
       int m = (l + r) >> 1;  
       build(lson);  
       build(rson);  
       PushUP(rt);  
}  
void update(int p,int add,int l,int r,int rt) {  
       if (l == r) {  
              sum[rt] += add;  
              return ;  
       }  
       int m = (l + r) >> 1;  
       if (p <= m) update(p , add , lson);  
       else update(p , add , rson);  
       PushUP(rt);  
}  
int query(int L,int R,int l,int r,int rt) {  
       if (L <= l && r <= R) {  
              return sum[rt];  
       }  
       int m = (l + r) >> 1;  
       int ret = 0;  
       if (L <= m) ret += query(L , R , lson);  
       if (R > m) ret += query(L , R , rson);  
       return ret;  
}  
int main() {  
       int T , n;  
       scanf("%d",&T);  
       for (int cas = 1 ; cas <= T ; cas ++) {  
              printf("Case %d:\n",cas);  
              scanf("%d",&n);  
              build(1 , n , 1);  
              char op[10];  
              while (scanf("%s",op)) {  
                     if (op[0] == 'E') break;  
                     int a , b;  
                     scanf("%d%d",&a,&b);  
                     if (op[0] == 'Q') printf("%d\n",query(a , b , 1 , n , 1));  
                     else if (op[0] == 'S') update(a , -b , 1 , n , 1);  
                     else update(a , b , 1 , n , 1);  
              }  
       }  
       return 0;  
}  
struct segment_tree {
	int l, r;
	ll sum, lazy;
} tree[maxn << 2];

void build(int k, int l, int r) {
	tree[k].l = l;
	tree[k].r = r;
	if (l == r) {
		cin >> tree[k].sum;
		return;
	}
	int mid = (l + r) >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
	tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
}

void pushdown(int k) {
	if (tree[k].l < tree[k].r && tree[k].lazy) {
		tree[k << 1].lazy += tree[k].lazy;
		tree[k << 1].sum += (tree[k << 1].r - tree[k << 1].l + 1) * tree[k].lazy;
		tree[k << 1 | 1].lazy += tree[k].lazy;
		tree[k << 1 | 1].sum += (tree[k << 1 | 1].r - tree[k << 1 | 1].l + 1) * tree[k].lazy;
		tree[k].lazy = 0;
	}
}

void update(int k, int l, int r, ll val) {
	pushdown(k);
	if (tree[k].l == l && tree[k].r == r) {
		tree[k].lazy += val;
		tree[k].sum += (tree[k].r - tree[k].l + 1) * val;
		return;
	}
	int mid = (tree[k].l + tree[k].r) >> 1;
	if (mid >= r) {
		update(k << 1, l, r, val);
	} else if (mid < l) {
		update(k << 1 | 1, l, r, val);
	} else {
		update(k << 1, l, mid, val);
		update(k << 1 | 1, mid + 1, r, val);
	}
	tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
}

ll query(int k, int l, int r) {
	pushdown(k);
	if (tree[k].l == l && tree[k].r == r) {
		return tree[k].sum;
	}
	int mid = (tree[k].l + tree[k].r) >> 1;
	if (mid >= r) {
		return query(k << 1, l, r);
	} else if (mid < l) {
		return query(k << 1 | 1, l, r);
	} else {
		return query(k << 1, l, mid) + query(k << 1 | 1, mid + 1, r);
	}
}

const int MAXN = 100005;  
const int MAXM = 2000005;  
vector<int> hash;  
int a[MAXN];  
int tot;  
struct NODE  
{  
    int count;  
    int left, right;  
};  
int root[MAXN];  
NODE node[MAXM];  
int null;  
int newnode(int count, int left, int right)  
{  
    node[tot].count=count;  
    node[tot].left=left;  
    node[tot].right=right;  
    return tot++;  
}  
int insert(int rt, int l, int r, int k)  
{  
    if (l <= k && k <= r)  
    {  
        if (l == r)  
        {  
            return newnode(node[rt].count + 1, 0, 0);  
        }  
        int m = (l + r) >> 1;  
        return newnode(node[rt].count + 1,  
                       insert(node[rt].left, l, m, k),  
                       insert(node[rt].right, m + 1, r, k));  
    }  
    return rt;  
}  
  
int query(int p, int q, int l, int r, int k)  
{  
    if (l == r)  
    {  
        return hash[l];  
    }  
    int m = (l + r) >> 1;  
    int cot = node[node[q].left].count - node[node[p].left].count;  
    if (cot >= k)  
    {  
        return query(node[p].left, node[q].left, l, m, k);  
    }  
    return query(node[p].right, node[q].right, m + 1, r, k - cot);  
}  
  
int main()  
{  
    int cas;  
    scanf("%d", &cas);  
    while(cas --)  
    {  
        int n, q;  
        scanf("%d%d", &n, &q);  
        hash.clear();  
        tot = 0;  
        for(int i = 1; i <= n; i ++)  
        {  
            scanf("%d", &a[i]);  
            hash.push_back(a[i]);  
        }  
        sort(hash.begin(), hash.end());  
        hash.erase(unique(hash.begin(), hash.end()), hash.end());  
        int m = hash.size();  
        null = newnode(0, 0, 0);  
        root[0] = newnode(0, 0, 0);  
        for(int i = 1; i <= n; i ++)  
        {  
            a[i] = lower_bound(hash.begin(), hash.end(), a[i]) - hash.begin();  
            root[i] = insert(root[i - 1], 0, m - 1, a[i]);  
        }  
        while(q--)  
        {  
            int l, r, k;  
            scanf("%d%d%d", &l, &r, &k);  
            printf("%d\n", query(root[l - 1], root[r], 0, m - 1, k));  
        }  
    }  
    return 0;  
}  

莫队：
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fod(i,a,b) for(i=a;i>=b;i--)
#define MAXN 300050
using namespace std;
struct node {
	int ls, rs, sm;
} tr[20 * MAXN];
struct number {
	int x, y;
} b[MAXN];
bool cmp ( number x, number y ) {
	return x.x < y.x;
}
int rt[MAXN], a[MAXN], n, m, num, nd, pt[MAXN];
void build ( int lst, int now, int l, int r, int v ) {
	if ( l == r ) {
		tr[now].sm = tr[lst].sm + 1;
		return;
	}
	int mid = ( l + r ) / 2;
	if ( v <= mid ) {
		tr[now].rs = tr[lst].rs;
		tr[now].ls = ++nd;
		build ( tr[lst].ls, nd, l, mid, v );
	} else {
		tr[now].ls = tr[lst].ls;
		tr[now].rs = ++nd;
		build ( tr[lst].rs, nd, mid + 1, r, v );
	}
	tr[now].sm = tr[tr[now].ls].sm + tr[tr[now].rs].sm;
}
int find ( int lst, int now, int l, int r, int v ) {
	if ( l == r ) return l;
	int mid = ( l + r ) / 2;
	int ls1 = tr[lst].ls, ls2 = tr[now].ls, sum = tr[ls2].sm - tr[ls1].sm;
	if ( sum < v ) return find ( tr[lst].rs, tr[now].rs, mid + 1, r, v - sum );
	else return find ( tr[lst].ls, tr[now].ls, l, mid, v );
}
int main() {
	scanf ( "%d", &n);
	int i, j;
	num = 0, nd = 0;
	fo ( i, 1, n ) {
		scanf ( "%d", &a[i] );
		b[i].x = a[i];
		b[i].y = i;
	}
	scanf ( "%d", &m);
	sort ( b + 1, b + n + 1, cmp );
	fo ( i, 1, n ) {
		if ( b[i].x != b[i - 1].x ) num++;
		pt[num] = b[i].x;
		a[b[i].y] = num;
	}
	fo ( i, 1, n ) {
		rt[i] = ++nd;
		build ( rt[i - 1], rt[i], 1, n, a[i] );
	}
	fo ( i, 1, m ) {
		int x, y, k;
		scanf ( "%d%d%d", &x, &y, &k );
		printf ( "%d\n", pt[find ( rt[x - 1], rt[y], 1, n, k )] );
	}
}

图论
Tarjan强联通分量缩点：
struct data {
	int to,next;
} tu[N*2];
int head[N];
int ip;
int dfn[N], low[N];///dfn[]表示深搜的步数，low[u]表示u或u的子树能够追溯到的最早的栈中节点的次序号
int sccno[N];///缩点数组，表示某个点对应的缩点值
int step;
int scc_cnt;///强连通分量个数
void init() {
	ip=0;
	memset(head,-1,sizeof(head));
}
void add(int u,int v) {
	tu[ip].to=v,tu[ip].next=head[u],head[u]=ip++;
}
vector<int> scc[N];///得出来的缩点，scc[i]里面存i这个缩点具体缩了哪些点
stack<int> S;
void dfs(int u) {
	dfn[u] = low[u] = ++step;
	S.push(u);
	for (int i = head[u]; i !=-1; i=tu[i].next) {
		int v = tu[i].to;
		if (!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (!sccno[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		scc_cnt += 1;
		scc[scc_cnt].clear();
		while (1) {
			int x = S.top();
			S.pop();
			if (sccno[x] != scc_cnt) scc[scc_cnt].push_back(x);
			sccno[x] = scc_cnt;
			if (x == u) break;
		}
	}
}
void tarjan(int n) {
	memset(sccno, 0, sizeof(sccno));
	memset(dfn, 0, sizeof(dfn));
	step = scc_cnt = 0;
	for (int i = 1; i <=n; i++)
		if (!dfn[i]) dfs(i);
}
欧拉回路
int n,m;
int g[N][N];
stack<int> st;
void dfs(int u)
{
    for(int i=1;i<=n;i++)
        if(g[u][i])
        {
            g[u][i]=g[i][u]=0;
            st.push(i);
            dfs(i);
            break;
        }
}
void fleury(int u)
{
    while(!st.empty())st.pop();
    st.push(u);
    while(!st.empty())
    {
        int flag=1;
        for(int i=1;i<=n;i++)
            if(g[st.top()][i])
            {
                flag=0;
                break;
            }
        if(flag)
        {
            printf("%d ",st.top());
            st.pop();
        }
        else
            dfs(st.top());
    }
}
void solve()
{
    int res=0, u=1;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=1;j<=n;j++)
            sum+=g[i][j];
        if(sum&1)u=i,res++;
    }
    if(res==0 || res==2)fleury(u);
    else printf("Sorry! no euler path.");
    printf("\n");
}
二分图判断：
const int mxn=1005;
bool mp[mxn][mxn],know[mxn][mxn];
int n,x,color[mxn];
bool flag;
inline void dfs(int u) {
	if(!flag) return;
	for(int i=1; i<=n; i++) {
		if(know[u][i]) {
			if(color[i]) {
				if(color[i]==color[u]) {
					flag=0;
					return;
				}
				continue;
			}
			color[i]=3-color[u];
			dfs(i);
		}
	}
}
int main() {
	while(~scanf("%d",&n)) {
		flag=1;
		memset(mp,0,sizeof(mp));
		memset(know,0,sizeof(know));
		memset(color,0,sizeof(color));
		for(int i=1; i<=n; i++)
			while(~scanf("%d",&x) && x)
				mp[i][x]=1;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) {
				if(i==j) continue;
				if(!mp[i][j] || !mp[j][i])
					know[i][j]=know[j][i]=1;
			}
		for(int i=1; i<=n; i++) {
			if(!flag) break;
			if(!color[i])
				color[i]=1,dfs(i);
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

二分图匹配：
bool mp[110][310];
int n,x,m;
bool flag[310];
int pre[310];
inline int find(int cur) {
	int i;
	for(i = 1; i <= m; i++) {
		if(mp[cur][i]&&!flag[i]) {
			flag[i] = true;
			if(pre[i] == -1 || find(pre[i])) {
				pre[i] = cur;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		memset(mp,0,sizeof(mp));
		memset(pre,-1,sizeof(pre));
		int x,y;
		for(int i=1; i<=n; i++) {
			scanf("%d",&x);
			for(int k=1; k<=x; k++) {
				scanf("%d",&y);
				mp[i][y]=true;
			}
		}
		int sum=0;
		for(int i=1; i<=n; i++) {
			memset(flag,false,sizeof(flag));
			sum+=find(i);
		}
		if(sum==n)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}


MST:
前向星+krusal
const int MAX = 105;
int pre[MAX],cnt;
struct edge {
	int u,v,w;
} e[5050];
inline bool cmp(edge a,edge b) {return a.w<b.w;}
void init (int N) {
	for ( int j = 1; j <=N; j++ )
		pre[j] = j;
}
void add(int u,int v,int w){
	e[++cnt].u=u;e[++cnt].v=v;e[++cnt].w=w;
}
int found ( int x ) {
	int r = x;
	while ( pre[r] != r )
		r = pre[r];
	int i = x, j;
	while ( i != r ) {
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}
void bin ( int a, int b ) {
	int ra = found ( a );
	int rb = found ( b );
	if ( ra != rb )
		pre[ra] = rb;
}
inline long long kruskal(int n,int m) {
	long long ans=0;
	init(n);
	sort(e+1,e+m+1,cmp);
	for (int j=1; j<=m; j++) {
		int u=found(e[j].u),v=found(e[j].v),w=e[j].w;
		if (u!=v) pre[u]=v,ans+=w;
	}
	return ans;
}
int main() {
	int n,m;
	while (~scanf("%d",&n)&&n) {
		m=n*(n-1)/2;
		for (int j=1; j<=m; j++) {
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			e[j].u=x;
			e[j].v=y;
			e[j].w=z;
		}
		long long ans=kruskal(n,m);
		printf("%lld\n",ans);
	}
	return 0;
}

const int MAX = 150050;
int pre[MAX];
void init ( )
{
	for ( int j = 0; j < MAX; j++ )
		pre[j] = j;
}
int found ( int x )
{
	int r = x;
	while ( pre[r] != r )
		r = pre[r];
	int i = x, j;
	while ( i != r )
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}
void bin( int a, int b )
{
	int ra = found ( a );
	int rb = found ( b );
	if ( ra != rb )
		pre[ra] = rb;
}
prim:
struct number{
    int x,i;
    bool operator < (const number &a) const {
        return x>a.x;//最小值优先，因为默认是大根堆的说。。。 
    }
}A,B;//中转站而已 
priority_queue <number> q;//堆 
int map[5005][5005],n,m,a,b,c,ans;
bool v[5005];
int main(){
    memset(v,false,sizeof(v));
    memset(map,-1,sizeof(map));
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        if (map[a][b]==-1||c<map[a][b]) map[a][b]=c;
        if (map[b][a]==-1||c<map[b][a]) map[b][a]=c;
    }
    v[1]=true;
    for (int i=1;i<=n;i++)
        if (map[1][i]!=-1){
            A.x=map[1][i];
            A.i=i;
            q.push(A);
        }
    for (int i=1;i<n;i++){
        if (q.empty()){
            printf("orz");
            return 0;
        }
        B=q.top();
        q.pop();
        while (v[B.i]){
            B=q.top();
            q.pop();
            if (q.empty()){
                printf("orz");
                return 0;
            }
        }
        ans+=B.x;
        v[B.i]=true;
        for (int j=1;j<=n;j++)
        if (map[B.i][j]!=-1&&!v[j]){
            A.x=map[B.i][j];
            A.i=j;
            q.push(A);
        }
    }
    printf("%d",ans);
    return 0;
}
最短路
无优化SPFA
#define INF 0x3f3f3f3f
const int MAX_E=100000+5;
const int MAX_P=10000+5;
using namespace std;
struct node {
	int next,v,val;
} edge[MAX_E];
int head[MAX_P], n, m, visit[MAX_P], cnt, d[MAX_P];
queue<int> q;
void add ( int x, int y, int z ) {
	edge[++cnt].v = y;
	edge[cnt].next = head[x];
	edge[cnt].val = z;
	head[x] = cnt;
}
void spfa() {
	q.push ( 1 );
	visit[1] = 1;
	d[1] = 0;
	while ( !q.empty() ) {
		int a = q.front();
		q.pop();
		visit[a] = 0;
		for ( int i = head[a]; i != -1; i = edge[i].next ) {
			if ( d[edge[i].v] > d[a] + edge[i].val ) {
				if ( !visit[edge[i].v] ) {
					d[edge[i].v] = d[a] + edge[i].val;
					q.push ( edge[i].v );
					visit[edge[i].v] = 1;
				} else {
					d[edge[i].v] = d[a] + edge[i].val;
				}
			}
		}
	}
}
void init() {
	memset ( head, -1, sizeof ( head ) );
	memset ( d, 0x3f, sizeof ( d ) );
	memset ( visit, 0, sizeof ( visit ) );
	while ( !q.empty() )
		q.pop() ;
}

双优化SPFA（单组）:
const int maxne = 600001;//最大边数
const int maxnn = 20001;//最大点数
const unsigned long long int inf = 6000000000;//初值
int n, e, s, cnt;//n顶点数,e边数,s起点,cnt邻接表表头
int last[maxne], q[maxne], check[maxnn];
long long dis[maxnn];
bool is[maxnn], fuhuan;
struct line
{
	int to, next, v;
} l[maxne];
void add ( int u, int v, int w )
{
	l[++cnt].to = v;
	l[cnt].next = last[u];
	last[u] = cnt;
	l[cnt].v = w;
}
void spfa ( int a )
{
	for ( int i = 1; i <= n; i++ ) dis[i] = inf;
	dis[a] = 0;
	is[a] = 1;
	q[0] = a;
	check[a]++;
	int head = 0, tail = 1;
	while ( head != tail )
	{
		int now = q[head++];
		if ( head == n + 1 ) head = 0;
		for ( int i = last[now]; i; i = l[i].next )
		{
			if ( dis[now] + l[i].v < dis[l[i].to] && dis[now] != inf )
			{
				dis[l[i].to] = dis[now] + l[i].v;
				if ( !is[l[i].to] )
				{
					is[l[i].to] = 1;
					if ( dis[l[i].to] < dis[q[head]] )
					{
						head--;
						if ( head == -1 ) head = n;
						q[head] = l[i].to;
						check[l[i].to]++;
						if ( check[l[i].to] == n )
						{
							fuhuan = 1;
							return;
						}
					}
					else
					{
						q[tail++] = l[i].to;
						if ( check[l[i].to] == n )
						{
							fuhuan = 1;
							return;
						}
						if ( tail == n + 1 ) tail = 0;
					}
				}
			}
		}
		is[now] = 0;
	}
}

堆优化dij
#define ll long long
#define INF 0x3f3f3f3f
int n, m, s, head[50010], cnt;
ll d[10010];
bool used[10010];
struct node
{
	int to, next, w;
} edge[500010];
void add ( int u, int v, int w )
{
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	edge[cnt].w = w;
	head[u] = cnt++;
}//前向星。
typedef pair<int, int> P; //用于存到达点的最短路径
void dijkstra ( int s )
{
	priority_queue<P, vector<P>, greater<P> > q; //按照P第一个元素从小到大取出的队列
	fill ( d, d + n + 1, INF );
	fill ( used, used + n + 1, false );
	d[s] = 0;
	q.push ( P ( 0, s ) );
	while ( !q.empty() )
	{
		P p = q.top();
		q.pop();
		int u = p.second;
		if ( used[u] ) continue;
		used[u] = true;
		int pp = head[u];
		while ( pp != -1 )
		{
			int v = edge[pp].to;
			if ( !used[v] && d[v] > d[u] + edge[pp].w )
			{
				d[v] = d[u] + edge[pp].w;
				q.push ( P ( d[v], v ) );
			}
			pp = edge[pp].next;
		}
	}
}
//记得memset(head,-1

拓扑排序
const int MAXN = 505;
vector<int> Graph[MAXN];
int TopNum[MAXN], NodeNum[MAXN];;
int NumVertex, NumEdge;
void TopSort() {
        priority_queue<int, vector<int>, greater<int> > que;
        for (int i=1; i<=NumVertex; ++i)
                if (Graph[i][0] == 0) que.push(i);
        int cnt = 0;
        while (!que.empty()) {
                int u = que.top();
                que.pop();
                TopNum[u] = ++cnt;
                for (int i=1; i<Graph[u].size(); ++i) {
                        if (--Graph[Graph[u][i]][0] == 0) que.push(Graph[u][i]);
                }
        }
        if (cnt != NumVertex) return;
        for (int i=1; i<=NumVertex; ++i) if (Graph[i][0]) puts("somerwhere of the graph has a cycle");
        for (int i=1; i<=NumVertex; ++i) NodeNum[TopNum[i]] = i;
        for (int i=1; i<=NumVertex; ++i) printf("%d%c", NodeNum[i], i==NumVertex?'\n':' ');
}

DINIC网络流
const int MAXN = 210;
const int MAXM = 210*210;
const int INF = 0x3f3f3f3f;
struct Edge {
	int v, f;
	int next;
} edge[MAXM];
int n, m;
int cnt;
int first[MAXN], level[MAXN];
int q[MAXN];
void init() {
	cnt = 0;
	memset(first, -1, sizeof(first));
}
void read_graph(int u, int v, int f) {
	edge[cnt].v = v, edge[cnt].f = f;
	edge[cnt].next = first[u], first[u] = cnt++;
	edge[cnt].v = u, edge[cnt].f = 0;  //增加一条反向弧，容量为0
	edge[cnt].next = first[v], first[v] = cnt++;
}
int bfs(int s, int t) { //构建层次网络
	memset(level, 0, sizeof(level));
	level[s] = 1;
	int front = 0, rear = 1;
	q[front] = s;
	while(front < rear) {
		int x = q[front++];
		if(x == t) return 1;
		for(int e = first[x]; e != -1; e = edge[e].next) {
			int v = edge[e].v, f = edge[e].f;
			if(!level[v] && f) {
				level[v] = level[x] + 1;
				q[rear++] = v;
			}
		}
	}
	return 0;
}
int dfs(int u, int maxf, int t) {
	if(u == t) return maxf;
	int ret = 0;
	for(int e = first[u]; e != -1; e = edge[e].next) {
		int v = edge[e].v, f = edge[e].f;
		if(level[u] + 1 == level[v] && f) {
			int Min = min(maxf-ret, f);
			f = dfs(v, Min, t);
			edge[e].f -= f;
			edge[e^1].f += f;
			ret += f;
			if(ret == maxf) return ret;
		}
	}
	return ret;
}
int Dinic(int s, int t) { //Dinic
	int ans = 0;
	while(bfs(s, t)) ans += dfs(s, INF, t);
	return ans;
}
int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		init();
		for(int i=0; i<n; i++) {
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			read_graph(x,y,z);
		}
		printf("%d\n",Dinic(1,m));
	}
}
ISAP
int read() {
    int x=0,f=1;
    char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
    for (;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
const int maxn=205;
const int maxm=205;
const int inf=2e9+7;
struct edge {
    int v,w,nxt;
} e[maxm<<1];
int h[maxn],tot,n,m,gap[maxn],last[maxn],d[maxn],que[maxn],ql,qr;
vector<int> inv[maxn];
void add(int u,int v,int w) {
    e[++tot]=(edge){v,w,h[u]};
    h[u]=tot;
    e[++tot]=(edge){u,0,h[v]};
    h[v]=tot;
}
void init(int s,int t) {
    memset(gap,0,sizeof gap),memset(d,0,sizeof d),++gap[d[t]=1];
    for (int i=1;i<=n;++i) last[i]=h[i];
    que[ql=qr=1]=t;
    while (ql<=qr) {
        int x=que[ql++];
        for (int i=h[x],v=e[i].v;i;i=e[i].nxt,v=e[i].v) if (!d[v]) ++gap[d[v]=d[x]+1],que[++qr]=v;
    }
}
int aug(int x,int s,int t,int mi) {
    if (x==t) return mi;
    int flow=0;
    for (int &i=last[x],v=e[i].v;i;i=e[i].nxt,v=e[i].v) if (d[x]==d[v]+1) {
        int tmp=aug(v,s,t,min(mi,e[i].w));
        flow+=tmp,mi-=tmp,e[i].w-=tmp,e[i^1].w+=tmp;
        if (!mi) return flow;
    }
    if (!(--gap[d[x]])) d[s]=n+1;
    ++gap[++d[x]],last[x]=h[x];
    return flow;
}
int maxflow(int s,int t) {
    init(s,t);
    int ret=aug(s,s,t,inf);
    while (d[s]<=n) ret+=aug(s,s,t,inf);
    return ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
#endif
    while (~scanf("%d%d",&m,&n)) {
        tot=1,memset(h,0,sizeof h);
        for (int i=1;i<=n;++i) inv[i].clear();
        for (int i=1;i<=m;++i) {
            int u=read(),v=read(),w=read();
            add(u,v,w);
            if (w) inv[v].push_back(u);
        }
        int ans=maxflow(1,n);
        printf("%d\n",ans);
    }
    return 0;
}
MCMF 最小费用最大流
#define N 1100
#define INF 0x3f3f3f3f
struct Edge {
	int from,to,cap,flow,cost;
	Edge(int u,int v,int ca,int f,int co):from(u),to(v),cap(ca),flow(f),cost(co) {};
};
int n,m,s,t;
vector<Edge> edges;
vector<int> G[N];
int inq[N];//是否在队列中
int d[N];//距离
int p[N];//上一条弧
int a[N];//流量变化值
const int MAXN=2;
void init(int n) { //初始化
	for(int i=1; i<=n; i++)
		G[i].clear();
	edges.clear();
}

void addedge(int from,int to,int cap,int cost) { //加边
	edges.push_back(Edge(from,to,cap,0,cost));
	edges.push_back(Edge(to,from,0,0,-cost));
	int m=edges.size();
	G[from].push_back(m-2);
	G[to].push_back(m-1);
}

bool SPFA(int s,int t,int &flow,int &cost) { //寻找最小费用的增广路，使用引用同时修改原flow,cost
	for(int i=1; i<=n; i++)
		d[i]=INF;
	memset(inq,0,sizeof(inq));
	d[s]=0;
	inq[s]=1;
	p[s]=0;
	a[s]=INF;
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()) {
		int u=Q.front();
		Q.pop();
		inq[u]--;
		for(int i=0; i<G[u].size(); i++) {
			Edge& e=edges[G[u][i]];
			if(e.cap>e.flow && d[e.to]>d[u]+e.cost) { //满足可增广且可变短
				d[e.to]=d[u]+e.cost;
				p[e.to]=G[u][i];
				a[e.to]=min(a[u],e.cap-e.flow);
				if(!inq[e.to]) {
					inq[e.to]++;
					Q.push(e.to);
				}
			}
		}
	}
	if(d[t]==INF) return false;//汇点不可达则退出
	if(flow+a[t]>=MAXN){
		cost+=(MAXN-flow)*d[t];
		flow=MAXN;
		return false;
	}
	else {
		flow+=a[t];
		cost+=a[t]*d[t];
	}
	int u=t;
	while(u!=s) { //更新正向边和反向边
		edges[p[u]].flow+=a[t];
		edges[p[u]^1].flow-=a[t];
		u=edges[p[u]].from;
	}
	return true;
}
int MincotMaxflow(int s,int t) {
	int flow=0,cost=0;
	while(SPFA(s,t,flow,cost));
	return cost;
}
int main() {
	while(~scanf("%d%d",&n,&m)) {
		init(n);
		int x,y,z;
		for(int j=0; j<m; j++) {
			scanf("%d%d%d",&x,&y,&z);
			addedge(x,y,1,z);
			addedge(y,x,1,z);
		}
		printf("%d\n",MincotMaxflow(1,n));
	}
	return 0;
}
另一个MCMF：
#define N 1000
#define INF 100000000
struct Edge
{
    int from,to,cap,flow,cost;
    Edge(int u,int v,int ca,int f,int co):from(u),to(v),cap(ca),flow(f),cost(co){};
};
struct MCMF{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[N];
    int inq[N];//是否在队列中
    int d[N];//距离
    int p[N];//上一条弧
    int a[N];//可改进量
    void init(int n)//初始化
	{
        this->n=n;
        for(int i=0;i<n;i++)
            G[i].clear();
        edges.clear();
    }
    void addedge(int from,int to,int cap,int cost)//加边
    {
        edges.push_back(Edge(from,to,cap,0,cost));
        edges.push_back(Edge(to,from,0,0,-cost));
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool SPFA(int s,int t,int &flow,int &cost)//寻找最小费用的增广路，使用引用同时修改原flow,cost
    {
        for(int i=0;i<n;i++) d[i]=INF;
        memset(inq,0,sizeof(inq));
        d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            inq[u]--;
            for(int i=0;i<G[u].size();i++)
            {
                Edge& e=edges[G[u][i]];
                if(e.cap>e.flow && d[e.to]>d[u]+e.cost)//满足可增广且可变短
                {
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to])
                    {
                        inq[e.to]++;
                        Q.push(e.to);
                    }
                }
            }
        }
        if(d[t]==INF) return false;//汇点不可达则退出
        flow+=a[t];
        cost+=d[t]*a[t];
        int u=t;
        while(u!=s)//更新正向边和反向边
        {
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
            u=edges[p[u]].from;
        }
        return true;
    }
    int MincotMaxflow(int s,int t)
    {
        int flow=0,cost=0;
        while(SPFA(s,t,flow,cost));
        return cost;
    }
};
int main()
{
    MCMF mcmf;
    return 0;
}

常见算法
dp[i][v]=max{dp[i-1][v],dp[i-1][v-c[i]]+w[i]}
memset(dp,0,sizeof(dp));//要求背包不一定全满
for(dp[0]=0,i=1;i<n;i++)dp[i]=-INF;//要求背包必须全满
for(i=0;i<n;i++)
    for(j=m;j>=w[i];j--)
        dp[j]=max{dp[j],dp[j-w[i]]+v[i]};
return dp[n][m];
///完全背包O(n*m)转移方程：dp[i][v]=max{dp[i-1][v-k*c[i]]+k*w[i]};
for(i=0;i<n;i++)
    for(j=w[i];j>=m;j--)
        dp[j]=max{dp[j],dp[j-w[i]]+v[i]};
///多重背包
//O(n*m)
//转移方程：dp[i][v]=max{dp[i-1][v-k*c[i]]+k*w[i]};
memset(dp,0,sizeof(dp));
for(i=0;i<n;i++)
{
    memset(counts,0,sizeof(counts));
    for(j=w[i];j<=m;j++)
        if(dp[j]<dp[j-w[i]]+v[i] && counts[j-w[i]]<sum[i])
            dp[j]=dp[j-w[i]]+v[i], counts[j]=counts[j-w[i]]+1;
}
///多重背包(单调队列优化)
//O(n*m)
//dp[i][j*w[i]+k]=max{dp[i-1][jj*w[i]+k]+(j-jj)*v[i]};
//  =max{(dp[i-1][jj*w[i]+k]-jj*v[i]) + j*v[i]};
//单调队列优化形如下式的DP:
//dp[i]=max/min(f[k]) + g[i];(k<i && f[k]与j无关，g[i]与k无关)
memset(dp,0,sizeof(dp));
for(i=1;i<=n;i++)
{
    num[i] = min(num[i],m/w[i]);
    for(k=0;k<w[i];k++)//分成w[i]份转移
    {
        int head=0,tail=0;
        for(j=0;j<=(m-k)/w[i];j++)
        {
            int t=dp[j*w[i]+k]-j*v[i];//当前值进队列
            while(head<tail && t>=f[tail-1].f)
                tail--;//单调队列降序
            f[tail].f=t;f[tail++].pos=j;
            while(head<tail && f[head].pos+num[i]<j)
                head++;//保证num[i]足够
            dp[j*w[i]+k] = f[head].f+j*v[i];
        }
    }
}
///二维费用背包
//转移方程：dp[i][v][u]=max{dp[i-1][v][u],dp[i-1][v-a[i]][u-b[i]]+w[i]};
///长度DP
///最大连续子序列之和
//O(n)
int solve(int a[],int n)
{
    int i,maxx;
    int sum[N]={0};
    sum[0]=max(a[0],0);
    for(i=1;i<n;i++)
        sum[i]=max(sum[i-1]+a[i],a[i]);
    return sum[i-1];
}

///最大子矩阵和
//O(n*n*m)
int n,m,g[N][N],a[N];
int maxSumLen()
{
    a[0] = max(a[0],0);
    int ans = 0;
    for(int i=1;i<=m;i++)
        a[i]=max(a[i],a[i]+a[i-1]),ans=max(ans,a[i]);
    return ans;
}
int maxSum()
{
    int res = 0;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
                a[k]=g[j][k]-g[i-1][k];
            res=max(res,maxSumLen());
        }
    return res;
}
void solve()
{
    memset(g,0,sizeof(g));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&g[i][j]);
            g[i][j] += g[i-1][j];
        }
    printf("%d\n",maxSum());
}

///最长递增子序列(LIS)
//O(n^2)
//转移方程：b[k]=max(max(b[j]|a[j]<a[k],j<k)+1,1);
int LIS(int *a,int len)
{
    int i,j,maxx=0;
    int b[N];
    for(i=0;i<len;i++)
    {
        b[i] = 1;
        for(j=0;j<i;j++)
            if(a[i]>a[j])
                b[i] = max(b[i],b[j]+1);
    }
    for(i=0;i<len;i++)
        if(b[i]>maxx)
            maxx = b[i];
    return maxx;
}

//二分O(n*logn);
int fen(int num,int l,int r,int b[])
{
    int mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(num>=b[mid]) l=mid+1;
        else r=mid-1;
    }
    return l;
}
int LIS(int a[],int b[],int len)
{
    int i,lenn;
    b[0]=a[0];
    lenn=1;
    for(i=1;i<len;i++)
    {
        if(a[i]>=b[lenn-1]) b[lenn++]=a[i];
        else b[fen(a[i],0,lenn-1,b)]=a[i];
    }
    return lenn;
}
///最长公共子序列(LCS)
//O(n*m)
int dp[N][N],n,m;
int LCS(char *a, char *b)
{
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
        {
			if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
		}
    return dp[n][m];
}
///树dp
//O(n*m*m)
//n节点技能树点m个技能获得最大权值的办法
//dp[k][i] 在以k节点为根节点的子树中选择i权值的最大value, w[i] i节点所需权值
vector<int>g[N];
int dp[N][N],w[N];
void init(int n, int m)
{
    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)dp[i][j]=-INF;
    for(int i=0;i<=n;i++)g[i].clear();
}
void dfs(int pos,int fa)
{
    int i,j,k;
    for(i=0;i<g[pos].size();i++)if(g[pos][i]!=fa)dfs(g[pos][i],pos);
    for(k=0,i=0;i<=m;i++)k=max(k,dp[pos][i]),dp[pos][i]=k;
    for(i=0;i<g[pos].size();i++)
        if(g[pos][i]!=fa)
            for(j=m;j>=w[pos];j--)//降序更新，防止重复加上子树的权值
                for(k=1;j+k<=m;k++)
                    dp[pos][j+k] = max(dp[pos][j+k], dp[pos][j]+dp[g[pos][i]][k]);
}
int dp[N][35],num[N];
void ST(int n)
{
    for(int i=0;i<n;i++)
        dp[i][0] = num[i];

    int k = (int)(log((double)n) / log(2.0));
    for(int j=1;j<=k;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
            dp[i][j] = max(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
}
//查询i和j之间的最值,注意i是从0开始的
int RMQ(int l,int r)
{
    int mid = (int)(log((double)(r-l+1)) / log(2.0));
    int t = max(dp[l][mid],dp[r-(1<<mid)+1][mid]);
    return t;
}

///二维RMQ
//预处理 O(n*m*logn*logm)
//数组下标从1开始
int val[N][N];
int dp[N][N][9][9];
int mm[N];//二进制位数减一，使用前初始化
void initRMQ(int n,int m)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j][0][0] = val[i][j];
    for(int ii = 0; ii <= mm[n]; ii++)
        for(int jj = 0; jj <= mm[m]; jj++)
            if(ii+jj)
                for(int i = 1; i + (1<<ii) - 1 <= n; i++)
                    for(int j = 1; j + (1<<jj) - 1 <= m; j++)
                    {
                        if(ii)dp[i][j][ii][jj] = max(dp[i][j][ii-1][jj],dp[i+(1<<(ii-1))][j][ii-1][jj]);
                        else dp[i][j][ii][jj] = max(dp[i][j][ii][jj-1],dp[i][j+(1<<(jj-1))][ii][jj-1]);
                    }
}
//查询矩形内的最大值(x1<=x2,y1<=y2)
int rmq(int x1,int y1,int x2,int y2)
{
    int k1 = mm[x2-x1+1];
    int k2 = mm[y2-y1+1];
    x2 = x2 - (1<<k1) + 1;
    y2 = y2 - (1<<k2) + 1;
    return max(max(dp[x1][y1][k1][k2],dp[x1][y2][k1][k2]),max(dp[x2][y1][k1][k2],dp[x2][y2][k1][k2]));
}
int main()
{
    //在外面对mm数组进行初始化
    mm[0] = -1;
    for(int i = 1; i < N; i++)
        mm[i] = ((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
    int n,m;
    int Q;
    int r1,c1,r2,c2;
    while(scanf("%d%d",&n,&m) == 2)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d",&val[i][j]);
        initRMQ(n,m);
        scanf("%d",&Q);
        while(Q--)
        {
            scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
            if(r1 > r2)swap(r1,r2);
             if(c1 > c2)swap(c1,c2);
            int tmp = rmq(r1,c1,r2,c2);
            printf("%d ",tmp);
        }
    }
    return 0;
}

字符串
///KMP
//O(n+m),n%(n-next[n])==0得到循环节
void getNext(char *pre, int len, int *next)
{
    int i = 0,j = -1;
    next[0] = -1;
    while(i < len)
    {
        if(j == -1 || pre[i] == pre[j])
        {
            i++,j++;
            //next[i] = j;
            if(pre[i]!=pre[j]) next[i] = j;
            else next[i] = next [j];
        }
        else   j = next[j];
    }
}
int kmp(char *str, char *pre)
{
    int lenp = strlen(pre), lens = strlen(str);
    int next[lenp+1];
    getNext(pre, lenp, next);
    int i,j; i=j=0;
    while(i < lens && j < lenp)
    {
        if(j == -1 || str[i] == pre[j]) i++, j++;
        else j = next[j];
//        if(j == lenp) sum++;//记数(去掉while()中的j<lenp);
    }
    if(j >= lenp) return i - lenp;
    else return -1;
}

求数字循环节
VI a;
int nxt[N];
int main() {
    int n,tmp;
    scanf("%d",&n);
    for (int j=0; j<n; j++) {
        scanf("%d",&tmp);
        a.PB(tmp);
    }
    reverse(a.begin(),a.end());
    nxt[0] = -1;
    for (int i = 0, j = -1; i < n; ++i, ++j) {
        while (j != -1 && a[j] != a[i]) j = nxt[j];
        nxt[i+1] = j+1;
    }
    int k=0x3f3f3f3f,p=0x3f3f3f3f;
    for (int i=1;i<=n;i++) {
        int kk = n-i,pp = i-nxt[i];
        if (pp + kk < k+p||(pp + kk == k+p && pp < p)) k = kk, p = pp;
    }
    printf("%d %d",k,p);
    return 0;
}

///扩展kmp
//next[i]:pre[i...lenp-1]与pre[0...lenp-1]的最长公共前缀
//extend[i]:str[i...lens-1]与pre[0...lenp-1]的最长公共前缀
void getEnext(char pre[],int len,int next[])
{
    next[0]=len;
    int j=0;
    while(j+1<len && pre[j]==pre[j+1])j++;
    next[1]=j;
    int k=1;
    for(int i=2;i<len;i++)
    {
        int p=next[k]+k-1;
        int L=next[i-k];
        if(i+L<p+1)next[i]=L;
        else
        {
            j=max(0,p-i+1);
            while(i+j<len && pre[i+j]==pre[j])j++;
            next[i]=j;
            k=i;
        }
    }
}
void ekmp(char pre[],char str[],int next[],int extend[])
{
    int lenp=strlen(pre),lens=strlen(str);
    getEnext(pre,lenp,next);
    int j=0;
    while(j<lens && j<lenp && pre[j]==str[j])j++;
    extend[0]=j;
    int k=0;
    for(int i=1;i<lens;i++)
    {
        int p=extend[k]+k-1;
        int L=next[i-k];
        if(i+L<p+1)extend[i]=L;
        else
        {
            j=max(0,p-i+1);
            while(i+j<lens && j<lenp && str[i+j]==pre[j])j++;
            extend[i]=j;
            k=i;
        }
    }
}

AC自动机
#define N 100010
#define M 201
#define ZIFU 128
char str[N][M];
int num[N],n,m;
struct Trie
{
    int next[N][ZIFU],fail[N];
    vector<int>ends[N];
    int root,L;
    int idx(char c)
    {
        return c;
    }
    int newnode()
    {
        for(int i = 0;i < ZIFU;i++)
            next[L][i] = -1;
        ends[L++].clear();
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void inserts(char s[],int id)
    {
        int len = strlen(s);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][idx(s[i])] == -1)
                next[now][idx(s[i])] = newnode();
            now = next[now][idx(s[i])];
        }
        ends[now].push_back(id);
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < ZIFU;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < ZIFU;i++)
                if(next[now][i] == -1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int query(char buf[])
    {
        int sum=0;
        for(int i = 0;i < n;i++)
            num[i] = 0;
        int len=strlen(buf);
        int now=root;
        for(int i=0;i<len;i++)
        {
            now=next[now][idx(buf[i])];
            int temp = now;
            while( temp != root )
            {
                for(int j=0;j<ends[temp].size();j++)
                    num[ends[temp][j]]++,sum++;
                temp = fail[temp];
            }
        }
        return sum;
    }

};
char buf[1000010];
Trie ac;
int main()
{
    scanf("%d",&n);
    ac.init();
    for(int i=0;i<n;i++)
    {
        scanf("%s",&str[i]);
        ac.inserts(str[i],i);
    }
    ac.build();
    scanf("%s",&buf);
    printf("%d\n",ac.query(buf));
    return 0;
}


后缀数组（待续）
查询s,b,两串最长公共子串
const int MAXN=100010;
//以下为倍增算法求后缀数组
int wa[MAXN],wb[MAXN],wv[MAXN],Ws[MAXN];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
/**< 传入参数：str,sa,len+1,ASCII_MAX+1 */
void da(const char r[],int sa[],int n,int m) {
	int i,j,p,*x=wa,*y=wb,*t;
	for (i=0; i<m; i++) Ws[i]=0;
	for (i=0; i<n; i++) Ws[x[i]=r[i]]++; //以字符的ascii码为下标
	for (i=1; i<m; i++) Ws[i]+=Ws[i-1];
	for (i=n-1; i>=0; i--) sa[--Ws[x[i]]]=i;
	/*cout<<"SA"<<endl;;
	for(int i=0;i<n+1;i++)cout<<sa[i]<<' ';*/
	for (j=1,p=1; p<n; j*=2,m=p) {
		for (p=0,i=n-j; i<n; i++) y[p++]=i;
		for (i=0; i<n; i++) if (sa[i]>=j) y[p++]=sa[i]-j;
		for (i=0; i<n; i++) wv[i]=x[y[i]];
		for (i=0; i<m; i++) Ws[i]=0;
		for (i=0; i<n; i++) Ws[wv[i]]++;
		for (i=1; i<m; i++) Ws[i]+=Ws[i-1];
		for (i=n-1; i>=0; i--) sa[--Ws[wv[i]]]=y[i];
		for (t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
	return;
}
int sa[MAXN],Rank[MAXN],height[MAXN];
//求height数组
/**< str,sa,len */
void calheight(const char *r,int *sa,int n) {
	int i,j,k=0;
	for (i=1; i<=n; i++) Rank[sa[i]]=i;
	for (i=0; i<n; height[Rank[i++]]=k)
		for (k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++);
	// Unified
	for (int i=n; i>=1; --i) ++sa[i],Rank[i]=Rank[i-1];
}
char str[MAXN];

#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=55555,K=5;
const int inf=0x3f3f3f3f;

#define sqr(x) (x)*(x)
int k,n,idx;   //k为维数,n为点数
struct point
{
    int x[K];
    bool operator < (const point &u) const
    {
     return x[idx]<u.x[idx];
    }
}po[N];

typedef pair<double,point>tp;
priority_queue<tp>nq;

struct kdTree
{
    point pt[N<<2];
    int son[N<<2];

    void build(int l,int r,int rt=1,int dep=0)
    {
        if(l>r) return;
        son[rt]=r-l;
        son[rt*2]=son[rt*2+1]=-1;
        idx=dep%k;
        int mid=(l+r)/2;
        nth_element(po+l,po+mid,po+r+1);
        pt[rt]=po[mid];
        build(l,mid-1,rt*2,dep+1);
        build(mid+1,r,rt*2+1,dep+1);
    }
    void query(point p,int m,int rt=1,int dep=0)
    {
        if(son[rt]==-1) return;
        tp nd(0,pt[rt]);
        for(int i=0;i<k;i++) nd.first+=sqr(nd.second.x[i]-p.x[i]);
        int dim=dep%k,x=rt*2,y=rt*2+1,fg=0;
        if(p.x[dim]>=pt[rt].x[dim]) swap(x,y);
        if(~son[x]) query(p,m,x,dep+1);
        if(nq.size()<m) nq.push(nd),fg=1;
        else
        {
            if(nd.first<nq.top().first) nq.pop(),nq.push(nd);
            if(sqr(p.x[dim]-pt[rt].x[dim])<nq.top().first) fg=1;
        }
        if(~son[y]&&fg) query(p,m,y,dep+1);
    }
}kd;
void print(point &p)
{
    for(int j=0;j<k;j++) printf("%d%c",p.x[j],j==k-1?'\n':' ');
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=0;i<n;i++) for(int j=0;j<k;j++) scanf("%d",&po[i].x[j]);
        kd.build(0,n-1);
        int t,m;
        for(scanf("%d",&t);t--;)
        {
             point ask;
             for(int j=0;j<k;j++) scanf("%d",&ask.x[j]);
             scanf("%d",&m); kd.query(ask,m);
             printf("the closest %d points are:\n", m);
             point pt[20];
             for(int j=0;!nq.empty();j++) pt[j]=nq.top().second,nq.pop();
             for(int j=m-1;j>=0;j--) print(pt[j]);
        }
    }
    return 0;
}
const int INF = 0x3f3f3f3f;
const int MaxNode = 205;
const int MaxEdge = 40005;
struct Edge {
	int to,vol,next;
	double cost;
} edge[MaxEdge];
int Pre[MaxNode],Path[MaxNode],Head[MaxNode],cnt;
double Dist[MaxNode];
bool vis[MaxNode];
void addedge(int u, int v, int vol, double cost) {
	edge[cnt].to = v;
	edge[cnt].vol = vol;
	edge[cnt].cost = cost;
	edge[cnt].next = Head[u];
	Head[u] = cnt++;
	edge[cnt].to = u;
	edge[cnt].vol = 0;
	edge[cnt].cost = -cost;
	edge[cnt].next = Head[v];
	Head[v] = cnt++;
}
bool Spfa(int s, int t) {
	for(int i = 0; i < MaxNode; i++) Dist[i] = INF*1.0;
	memset(Pre, -1, sizeof(Pre));
	memset(vis, false, sizeof(vis));
	Dist[s] = 0.0;
	queue<int>Q;
	vis[s] = true;
	Q.push(s);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		vis[u] = false;
		for (int e = Head[u]; e != -1; e = edge[e].next) {
			int v = edge[e].to;
			if (edge[e].vol > 0 && Dist[v] - Dist[u] - edge[e].cost > eps) {
				Dist[v] = Dist[u] + edge[e].cost;
				Pre[v] = u;
				Path[v] = e;
				if(!vis[v]) {
					vis[v] = true;
					Q.push(v);
				}
			}
		}
	}
	return Pre[t] != -1;
}
double MCMF(int s, int t) {
	double cost = 0.0;
	int max_flow = 0;
	int u, v, e;
	while(Spfa(s, t)) {
		int f = INF;
		for (u = t; u != s; u = Pre[u]) {
			f = min(f, edge[Path[u]].vol);
		}
		for(u = t; u != s; u = Pre[u]) {
			e = Path[u];
			edge[e].vol -= f;
			edge[e^1].vol += f;
		}
		max_flow += f;
		cost += 1.0*f*Dist[t];
	}
	return cost;
}
void init() {
	memset(Head,-1,sizeof(Head));
	cnt = 0;
}
int main() {
	int t,n,m,a,b;
	scanf("%d",&t);
	while(t--) {
		init();
		scanf("%d%d",&n,&m);
		int S=0,T=n+1;
		for(int i = 1; i <= n; i++) {
			scanf("%d%d",&a,&b);
			int c=a-b;
			if(c > 0) addedge(S,i,c,0.0);
			else if(c < 0) addedge(i,T,-c,0.0);
		}
		for(int i=1; i<=m; i++) {
			int u,v,cap;
			double p;
			scanf("%d%d%d%lf",&u,&v,&cap,&p);
			p = -log2(1.0-p);
			if(cap > 0) addedge(u,v,1,0.0);
			if(cap > 1) addedge(u,v,cap-1,p);
		}
		double ans = pow(2,-MCMF(S,T));
		printf("%.2f\n",1.0-ans);
	}
#ifndef ONLINE_JUDGE
	printf("My Time:%.3lfms\n",(double)clock()/CLOCKS_PER_SEC);
#endif
	return 0;

}
