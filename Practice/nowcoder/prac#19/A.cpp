#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define INF 0X3F3F3F3F
#define N 500005
#define M 500005
#define Ull unsigned long long
#define FF(i, a, b) for(int i = a; i <= b; ++i)
#define RR(i, a, b) for(int i = a; i >= b; --i)
#define FJ(i, a, b) for(int i = a; i < b; ++i)
#define SC(x) scanf("%d", &x)
#define SCC(x, y) scanf("%d%d", &x, &y)
#define SCCC(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define SS(x) scanf("%s", x)
#define PR(x) printf("%d\n", x)
#define PII pair<int, int>
#define PLL pair<unsigned long long, unsigned long long>
#define MP make_pair
#define PB push_back
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
using namespace std;
typedef long long ll;
inline void II(int &n){char ch = getchar(); n = 0; bool t = 0;
for(; ch < '0'; ch = getchar()) if(ch == '-') t = 1;
for(; ch >= '0'; n = n * 10 + ch - '0', ch = getchar()); if(t) n =- n;}
inline void OO(int a){if(a < 0) {putchar('-'); a = -a;}
if(a >= 10) OO(a / 10); putchar(a % 10 + '0');}
char str[N];
struct node{
    ll w, h, S, SB;
    node(){}
    node(ll ww, ll hh, ll SS, ll SSB): w(ww), h(hh), S(SS), SB(SSB){}
};
int sta[N], spos;
int tar[N];
node get(ll L, ll R){
    if(L + 1 == R) return node(1, 1, 1, 1);
    ++L; --R;
    ll l = L, r = L;
    ll cur = 1, pos = L;
    ll totw = 0, mxh = 0;
    ll cnt = 0, sum = 0;
    while(l < R){
        r = tar[l];
        node tmp = get(l, r);
        if(tmp.h > mxh) mxh = tmp.h;
        totw += tmp.w;
        ++cnt;
        sum += tmp.SB;
        l = r + 1;
        cur = 1;
        r = l;
        pos = r;
    }
    totw += cnt + 1;
    return node(totw, mxh + 1, totw * (mxh + 1), totw * (mxh + 1) - sum);
}
int n;
int main(){
    //IN;
    SC(n);
    FF(i, 1, n){
        SS(str + 1);
        int len = strlen(str + 1);
        ll R = len;
    ll l = 1, r = 1;
    ll cur = 1, pos = 1;
    ll totw = 0, mxh = 0;
    ll cnt = 0, sum = 0;
        FF(i, 1, len){
            if(str[i] == '('){
                sta[++spos] = i;
            }else {
                tar[sta[spos]] = i;
                --spos;
            }
        }
        while(l < R){
            r = tar[l];
            node tmp = get(l, r);
            if(tmp.h > mxh) mxh = tmp.h;
            totw += tmp.w;
            ++cnt;
            sum += tmp.SB;
            l = r + 1;
            cur = 1;
            r = l;
            pos = r;
        }
        cout << sum << endl;
    }
    return 0;
}