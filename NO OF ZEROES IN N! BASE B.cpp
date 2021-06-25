#include<bits/stdc++.h>                     //....hello world
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;  

#define pb push_back
#define ll long long int
#define SORTA(v) sort(v.begin(),v.end())
#define SORTD(v) sort(v.begin(),v.end(),greater<>())
#define endl '\n'
#define FOR(i,n) for(long long int i = 0;i<n;i++)
#define FOR1(i,n) for(long long int i=1;i<=n;i++)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define REVERSE(s) reverse(s.begin(),s.end())
#define GCD(a,b) __gcd(a,b)
#define VFIND(v1,val) find(v1.begin() , v1.end() , val )
#define VFILL(v1 , val)   std::fill(v1.begin(), v1.end(), val);
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define all(x) x.begin() , x.end() 


ll calc(ll a , ll b)
{
    ll count = 0;
    ll tb = b;

    while(a >0 )
    {
        count += a/b;
        a /= b;
    }

    return count;

}

int main()
{
    FAST;
    ll i ,j , T = 1;
    // cin>>T;
    while(T--)
    {
        i=0;j=0;

        ll a,b; cin>>a>>b;

        ll tb = b , ta = a , c = 0 ;

        vector< pair<ll,ll> > v1;


        for(i=2;i*i<=tb;i++)
        {
            c=0;
            
            if(b%i == 0)
            {
                while(b%i==0)c++ , b= b / i;
                v1.pb({i,c} );
            }
        }
        
        if(b > 1)v1.pb({b , 1 } );


        ll ans = 1e18;
        
        FOR(i,v1.size() )
        {
            ans = min(ans , calc(a,v1[i].first) / v1[i].second ) ;
        }

        cout<<ans;






        
        
    }
}  

