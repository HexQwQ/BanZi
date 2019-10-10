#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-15;

int n;
double l,r;
double a[233];
double ans,now;

double calc(double x){
    double pro = 1.0,ans = 0;
    for(int i=n;i>=0;i--)
    {
        ans += pro*a[i];
        pro *= x;
    }
    return ans;
}

void SA(){
    // T=初始温度;
    double T = 1;
    while(T>eps)
    {
        now = ans + 1.0*(rand()*2 - RAND_MAX)*T;
        if( now < l )  now = l;
        if( now > r )  now = r;
        double delta=calc(now)-calc(ans);
        if( delta > 0 )  ans = now;
        // else if(exp(-delta/T)*RAND_MAX>rand())  ans=now; //记得 思考 - 
        // T*=t0;//t0一般在0.985-0.999之间，根据具体题目时间，随缘调试。。。
        T *= 0.995;
    }
}

int main(){
    scanf("%d %lf %lf",&n,&l,&r);
    for(int i=0;i<=n;i++)
        scanf("%lf",&a[i]);
    srand(time(0));
    int QAQ = 12;
    ans = (r+l)/2.0;
    while( QAQ-- )
        SA();
    printf("%.5lf\n",ans);
    return 0;
}


