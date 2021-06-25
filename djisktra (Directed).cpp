#include<bits/stdc++.h>                     // "Hello there"
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

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll mxm() {return LLONG_MIN;}template<typename... Args>ll mxm(ll a, Args... args) { return max(a,mxm(args...)); }
ll mnm() {return LLONG_MAX;}template<typename... Args>ll mnm(ll a, Args... args) { return min(a,mnm(args...)); }

const int MOD = 1e9 + 7;
long long int powxy(long long int x, long long int y) 
{
    if (y == 0) return 1;if (y%2 == 1) return (x*powxy(x, y-1))%MOD;
    long long int t = powxy(x, y/2);return (t*t)%MOD;
}
void DPM(map<ll,ll>m1)
{
    for(auto it = m1.begin();it!=m1.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;
}
void DPV(vector<ll>v)
{
    FOR(i,v.size())cout<<v[i]<<" ";cout<<endl;
}
void DPS(set<ll>s1)
{
    for(auto it =s1.begin();it!=s1.end();it++)cout<<*it<<" ";cout<<endl;
}

ll dx[4] = { 0,0,1,-1 };
ll dy[4] = { 1,-1,0,0 };
string pos = "RLDU";


int main()
{
    FAST;
    ll i ,j , T = 1;
    // cin>>T;
    while(T--)
    {
        i=0;j=0;

        ll n,m; cin>>n>>m;

        vector<ll>adj[n+10];

        map< pair<ll,ll> , ll>m1;

        FOR1(i,m)
        {
            ll a,b,c; cin>>a>>b>>c;

            if( m1.find( {a,b} )  != m1.end() )
            {
                m1[ {a,b} ] = min(c , m1[ {a,b} ] ) ;
            } 
            else m1 [ {a,b} ] = c;
            
            adj[a].pb(b);
        }

        vector<ll>dist(n+10);
        VFILL(dist,99999999999999999);

        set< pair<ll,ll> >s1;
        s1.insert( {0,0} ); 
        dist[0] = 0;

        while( !s1.empty() )
        {
            auto p1 = *(s1.begin() );
            s1.erase( s1.begin() );

            ll cost = p1.first; ll node = p1.second;

            for(auto u : adj[node] )
            {
                if( dist[u] > cost + m1[ {node , u} ] )
                {
                    s1.erase( {dist[u] , u});
                    dist[u] = cost + m1[ {node , u} ];
                    s1.insert ( { dist[u] , u}   );
                }
            }

        }

        FOR(i,n)cout<<dist[i]<<" ";

    }


}  

