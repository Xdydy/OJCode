#include<bits/stdc++.h>
#define rep(i,a,n) for(ll i = a;i <= n;i++)
#define per(i,n,a) for(ll i = n;i >= a;i--)
#define enter putchar('\n')

using namespace std;
typedef long long ll;
const int M = 1000005;
const int INF = 1000000009;
const double eps = 1e-8;

ll read()
{
   ll ans = 0,op = 1;char ch = getchar();
   while(ch < '0' || ch > '9') {if(ch == '-') op = -1;ch = getchar();}
   while(ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0',ch = getchar();
   return ans * op;
}

ll n,m,p,w[105],sum,ans = 1;
ll mul(ll a,ll b,ll t)
{
   ll res = a * b - (ll)((long double)a / t * b + eps) * t;
   return (res % t + t) % t;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
   if(!b){x = 1,y = 0;return a;}
   ll d = exgcd(b,a%b,y,x);
   y -= a / b * x;
   return d;
}
ll inv(ll a,ll b)
{
   ll x,y;
   exgcd(a,b,x,y);
   return (x % b + b) % b;
}
ll CRT(ll b,ll t) {return mul(mul(b,inv(p/t,t),p),p/t,p);}
ll qpow(ll a,ll b,ll t)
{
   ll p = 1;
   while(b)
   {
      if(b & 1) p = mul(p,a,t);
      a = mul(a,a,t),b >>= 1;
   }
   return p;
}

ll fac(ll n,ll pi,ll pk)
{
   if(!n) return 1;
   ll res = 1;
   rep(i,2,pk) if(i % pi) res *= i,res %= pk;
   res = qpow(res,n/pk,pk);
   rep(i,2,n%pk) if(i % pi) res *= i,res %= pk;
   return res * fac(n / pi,pi,pk) % pk;
}

ll C(ll n,ll m,ll pi,ll pk)
{
   ll d = fac(n,pi,pk),d1 = fac(m,pi,pk),d2 = fac(n-m,pi,pk);
   ll k = 0;
   for(ll i = n;i;i /= pi) k += i / pi;
   for(ll i = m;i;i /= pi) k -= i / pi;
   for(ll i = n-m;i;i /= pi) k -= i / pi;
   return mul(mul(d,inv(d1,pk),pk),mul(qpow(pi,k,pk),inv(d2,pk),pk),pk);
}

ll exlucas(ll n,ll m)
{
   ll res = 0,tmp = p,pk;
   ll lim = sqrt(p);
   rep(i,2,lim) if(!(tmp % i))
   {
      pk = 1;
      while(!(tmp%i)) pk *= i,tmp /= i;
      res += CRT(C(n,m,i,pk),pk),res %= p;
   }
   if(tmp > 1) res += CRT(C(n,m,tmp,tmp),tmp),res %= p;
   return res;
}

int main()
{
   p = read();
   n = read(),m = read();
   rep(i,1,m) w[i] = read(),sum += w[i];
   if(sum > n) printf("Impossible\n"),exit(0);
   rep(i,1,m) ans *= exlucas(n,w[i]),ans %= p,n -= w[i];
   printf("%lld\n",ans);
   return 0;
}