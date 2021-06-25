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

void DPV(vector<ll>v)
{
    FOR(i,v.size())cout<<v[i]<<" ";cout<<endl;
}

vector<ll>adj[100000 + 9999] , vis(100000 + 9999) , Prev(1000000 + 9999);
bool done = false;
vector<ll>ans[100];
ll cn = 0 ;

void dfs(ll u )
{
    // if(done)return;
    if( vis[u] == 1)return;

    if( vis[u] == 2)
    {
        cn++;
        vector<ll>tmp;
        done = true;

        ll cur = u;
        tmp.pb(cur);
        cur = Prev[cur];
        vis[cur] = 1;

        while(cur != u)
        {
            tmp.pb(cur);
            cur = Prev[cur];
            vis[cur] = 1;
        }
        tmp.pb(u);
        vis[u] = 1;
        
        ans[cn] = tmp;
        
        return; 
    }


    vis[u] = 2;
    for(auto v : adj[u] )
    {
        if(v == Prev[u] )continue;
        Prev[v] = u;
        dfs(v);
    
    }
    
    vis[u] = 1;

}

int main()
{
    FAST;
    ll i ,j , T = 1;
    // cin>>T;
    while(T--)
    {
        i=0;j=0;

        ll n,m; cin>>n>>m;

        while(m--)
        {
            ll u,v; cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);   
        }

        FOR1(i,n)
        {
            // if(done)break;
            if( !vis[i] )dfs(i);
        }
        
        if(done)
        {
            // cout<<ans.size()<<endl;
            DPV(ans[1] );
            DPV( ans[2] );
        }
        else cout<<"IMPOSSIBLE";
    }
}  

