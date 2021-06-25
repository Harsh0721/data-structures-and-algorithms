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
const int M = 1e9 + 7;

long long int powxy(long long int x, long long int y) 
{
    if (y == 0) return 1;
    if (y%2 == 1) return (x*powxy(x, y-1))%M;
    long long int t = powxy(x, y/2);
    return (t*t)%M;
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

ll n; vector<ll>adj[10000] , vis(10000); 

void bfs(ll v)
{
    list<ll>q1;

    q1.push_back(v); vis[v] = 1;

    while( !q1.empty() )
    {
        v = queue.front();
        cout<<v<<" ";
        queue.pop_front();

        for( auto x : adj[s] )
        {
            if( !vis[x] )
            {
                vis[x] = true;
                q1.push_back(x);
            }
        }

    }


}

int main()
{
    FAST;
    ll i ,j , T = 1;
    // cin>>T;
    while(T--)
    {
        i=0;j=0;

        adj[0].pb(1);
        adj[0].pb(2);
        adj[1].pb(2);
        adj[2].pb(0);
        adj[2].pb(3);
        adj[3].pb(3);

        

        
        
    }
}  

