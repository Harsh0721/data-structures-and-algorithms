#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;  

#define pb push_back
#define ll long long int
#define db double
#define SORTA(v) sort(v.begin(),v.end())
#define SORTD(v) sort(v.begin(),v.end(),greater<>())
#define endl '\n'
#define nod(N) floor(log10(N)) + 1
#define LB(a) lower_bound(a)
#define UB(a) upper_bound(a)
#define F first
#define S second
#define FOR(i,n) for(long long int i = 0;i<n;i++)
#define FOR1(i,n) for(long long int i=1;i<=n;i++)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define REVERSE(s) reverse(s.begin(),s.end())
#define LBV(v,a) lower_bound(v.begin(),v.end(),a)
#define UBV(v,a) upper_bound(v.begin(),v.end(),a)
#define GCD(a,b) __gcd(a,b)
#define MAX pow((ll)2,63) - 999;
#define ITX(it,x1) for(auto it = x1.begin();it!=x1.end();it++)
#define I insert
#define stll(x) stoll(x, nullptr, 10);
#define VFIND(v1,val) find(v1.begin() , v1.end() , val )
#define VFILL(v1 , val)   std::fill(v1.begin(), v1.end(), val);
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define all(x) x.begin() , x.end() 

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll mxm() {return LLONG_MIN;}
template<typename... Args>
ll mxm(ll a, Args... args) { return max(a,mxm(args...)); }
ll mnm() {return LLONG_MAX;}
template<typename... Args>
ll mnm(ll a, Args... args) { return min(a,mnm(args...)); }
ll cl(ll a, ll b){if(a%b == 0)return a/b;else return a/b + 1;}
const int MOD = 1e9 + 7;

long long int powxy(long long int x, long long int y) 
{
    if (y == 0) return 1;
    if (y%2 == 1) return (x*powxy(x, y-1))%MOD;
    long long int t = powxy(x, y/2);
    return (t*t)%MOD;
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
void DPA(ll arr[],ll n)
{
    FOR(i,n)cout<<arr[i]<<" ";cout<<endl;
}

ll dx[4] = { 0,0,1,-1 };
ll dy[4] = { 1,-1,0,0 };
string pos = "RLDU";

const int N = 5*100000;

vector< pair<ll,ll>  >adj[N];


int main()
{
    FAST;
    ll i ,j , T = 1;
    // cin>>T;
    while(T--)
    {
        i=0;j=0;

        vector<ll>prev(N),cost(N);

        VFILL(cost,999999999999999);

        ll n , m; cin>>n>>m;
        map< pair<ll,ll> , ll >m1;


        FOR1(i,m)
        {
            ll a,b,c; cin>>a>>b>>c;

            if( m1.find(  {a,b}  )  != m1.end() )
            {
                m1[{a,b} ] = min( m1[{a,b} ] , c);
            }
            else m1[{a,b} ] = c;
            
            if( m1.find(  {b,a}  )  != m1.end() )
            {
                m1[{b,a} ] = min( m1[{b,a} ] , c);
            }
            else m1[{b,a} ] = c;
            
            

        }
        
        cost[0] = 0 ;
        ITX(it,m1)
        {
            pair<ll,ll>p1 = it->first;

            adj[ p1.F ].pb( {it->second , p1.S } );
        }        

        set< pair<ll,ll> > s1;
        s1.I( { 0 , 0 }  ) ;

        while( !s1.empty() )
        {
            auto it = s1.begin();
            pair<ll,ll>p1 = *it;

            s1.erase(it);                // COST INDEX

            for(auto u : adj[ p1.S ])  // START COST END
            {
                pair<ll,ll>p2 = u;

                if(  cost[u.S] > p1.F + p2.F  )
                {
                    s1.erase( {cost[u.S] , u.S }    );
                    cost[u.S] = p1.F + p2.F;

                    s1.I ( { cost[u.S] , u.S } );

                    prev[ u.S ] = p1.S;    
                }
                
            }

        }
        
        
        
        FOR(i,n)cout<<cost[i]<<" ";
        
        // ll START = n;
        // vector<ll>ans;
            
        // while( START != 1)
        // {
        //     ans.pb(START);
        //     START = prev[START];

        // }
        
        // ans.pb(1);
        
        // REVERSE(ans);
        
        // DPV(ans);
        

        

        


        
    }
}  

