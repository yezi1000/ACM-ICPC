#include <iostream>    
#include <cstdio>    
#include <string>    
#include <cstring>    
#include <algorithm>    
#include <queue>    
#include <vector>    
#include <set>    
#include <stack>    
#include <map>    
#include <climits>    
#include <functional>    
  
using namespace std;  
  
#define LL long long    
const int INF = 0x3f3f3f3f;  
  
LL n;  
  
LL qpow(LL x, LL y)  
{  
    LL ans = 1;  
    while (y)  
    {  
        if (y & 1) ans *= x;  
        y >>= 1;  
        x *= x;  
    }  
    return ans;  
}  
  
int main()  
{  
    while (~scanf("%lld", &n))  
    {  
        int sum = 0;  
        for (long long i = 1; i <= 15; i++)  
        {  
            if (qpow(i, i) > n) break;  
            sum++;  
        }  
        printf("%d\n", sum);  
    }  
    return 0;  
}  