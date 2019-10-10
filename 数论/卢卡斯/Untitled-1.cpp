#include<bits/stdc++.h>

// #define mian main
#define ll long long
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9') f=(c=='-')?-1:1,c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
    return f*x;
}
inline void exgcd(ll a,ll b ,ll &x,ll &y){
    if(!b){x=1,y=0;return;}
    exgcd(b,a%b,x,y);
    ll t=x;
    x=y,y=t-(a/b)*y;
}
inline ll inv(ll a,ll b){
    ll x,y;
    return exgcd(a,b,x,y),(x%b+b)%b;
}
inline ll ksm(ll a,ll b,ll p){
    ll ans=1;
    while(b){
        if(b&1)
            ans=a*ans%p;
        a=a*a%p;
        b>>=1;
    }
    return ans%p;
}
inline ll crt(ll x,ll p,ll mod){
    return inv(p/mod,mod)*(p/mod)*x;
}
inline ll fac(ll x,ll a,ll b){
    if(!x)
        return 1;
    ll ans=1;
    for(ll i=1;i<=b;i++)
    if(i%a)
            ans*=i,ans%=b;
    ans=ksm(ans,x/b,b);
    for(ll i=1;i<=x%b;i++)
        if(i%a)
            ans*=i,ans%=b;
    return ans*fac(x/a,a,b)%b;
}
inline ll C(ll n,ll m,ll a,ll b){
    ll N=fac(n,a,b),M=fac(m,a,b),Z=fac(n-m,a,b),sum=0;
    for(ll i=n;i;i=i/a)
        sum+=i/a;
    for(ll i=m;i;i=i/a)
        sum-=i/a;
    for(ll i=n-m;i;i=i/a)
        sum-=i/a;
    return N*ksm(a,sum,b)%b*inv(M,b)%b*inv(Z,b)%b;
}
inline void exlucas(ll n,ll m,ll p){
    ll t=p,ans=0;
    for(ll i=2;i*i<=p;i++){
        ll k=1;
        while(t%i==0)
            k*=i,t/=i;
        ans+=crt(C(n,m,i,k),p,k),ans%=p;
    }
    if(t>1)
        ans+=crt(C(n,m,t,t),p,t),ans%=p;
    printf("%lld",ans%p);
}
int main(){
    ll n=read(),m=read(),p=read();
    exlucas(n,m,p);
    return 0;
}