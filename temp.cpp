#include<bits/stdc++.h>
#define lli long long int 
#define mod 1000000007
using namespace std;
bool prime [1000001];
lli sieve(lli a){memset(prime,true,sizeof(prime));lli p,i;for(p=2;p*p<=a;p++){if(prime[p]==true){for(i=p*2;i<=a;i+=p)prime[i]=false;}}return 0;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
priority_queue<lli, std::vector<lli>, std::greater<lli> >third;
int main(){
	ifstream cin("input.in");
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);	
	cout.precision(20);

}
