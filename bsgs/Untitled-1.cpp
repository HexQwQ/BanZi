#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll,ll> table;

ll mypow(ll a,ll b,ll m){
    ll inv = 1;
    while( b ){
        if( b&1 )  inv = inv*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return inv;
}

ll inv(ll a, ll p)
{
    return mypow(a,p-2,p);
}

ll A,B,C,M;

void gettable()
{
    table.clear();
    ll t, i;
    for(i=0,t=1;i<=M;i++,t=t*A%C)table[t]=i;
}

ll BSGS()
{
    ll d, i, j, Am, t, Aj, k;
    map<ll,ll>::iterator it;
    M=(ll)sqrt(C);
    gettable();
    Am=mypow(A,M,C);
    if(!Am)return -1;
    for(i=0;i<=M;i++)
    {
        Aj=B*inv(mypow(Am,i,C),C)%C;
        it=table.find(Aj);
        if(it!=table.end())return M*i+it->second;
    }
    return -1;
}

int main(int argc,char ** argv){
    scanf("%lld %lld %lld",&A,&B,&C);
    printf("%lld",BSGS());
}