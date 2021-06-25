#include<bits/stdc++.h>      // "Hello there"
using namespace std;


//  ->uncomment for ordered set                                     
// #include <ext/pb_ds/assoc_container.hpp>    
// #include <ext/pb_ds/tree_policy.hpp>     
// using namespace __gnu_pbds;
// // typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;   // for pair
// typedef tree<int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

//  ->uncomment for unordered map of pairs.

// #include<functional>        
// template <typename T>
// inline void hash_combine(std::size_t &seed, const T &val) {seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);}
// template <typename T> inline void hash_val(std::size_t &seed, const T &val) {hash_combine(seed, val);}
// template <typename T, typename... Types>
// inline void hash_val(std::size_t &seed, const T &val, const Types &... args) {hash_combine(seed, val);    hash_val(seed, args...);}
// template <typename... Types>
// inline std::size_t hash_val(const Types &... args) {  std::size_t seed = 0; hash_val(seed, args...);return seed;}

// struct pair_hash
//  {   
//      template <class T1, class T2>
//     std::size_t operator()(const std::pair<T1, T2> &p) const 
//     {
//         return hash_val(p.first, p.second);
//     }
// };


 

#define pb push_back
#define ll long long int
#define SORTA(v) sort(v.begin(),v.end())
#define SORTD(v) sort(v.begin(),v.end(),greater<>())
#define endl '\n'
#define FOR(i,n) for(ll i = 0;i<n;i++)
#define FOR1(i,n) for(ll  i=1;i<=n;i++)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define REVERSE(s) reverse(s.begin(),s.end())
#define GCD(a,b) __gcd(a,b)
#define VFIND(v1,val) find(v1.begin() , v1.end() , val )
#define VFILL(v1 , val)   std::fill(v1.begin(), v1.end(), val);
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define all(x) x.begin() , x.end() 


const int MOD = 1e9 + 7;
long long int INF = LLONG_MAX;




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

// check the limits dummy
ll Time = 0;

//  Back Edge is an edge that connects a vertex to a vertex that is discovered before it's parent
// NOTE : PARENT IS CUR'N NODE TO BE COMPUTED AND PAR IS PARENT OF CUR NODE.

void DFS1( vector< vector<ll> > &adj , vector<ll>&vis , vector<ll>&eariliest_discovered_ancestor , vector<ll>&discovery_time , ll Parent ,ll par)
{
    if(vis[Parent])return;
    vis[Parent] = 1;
    

    discovery_time[Parent] = eariliest_discovered_ancestor[Parent] = ++Time;

    for(auto Child : adj[Parent] )
    {
        
        if( Child == par)continue;

        if( vis[Child] )        // Parent--->Child can't be bridge, but we can update lowest ancestor time
        {
            eariliest_discovered_ancestor[Parent] = min(eariliest_discovered_ancestor[Parent] , discovery_time[Child]); 
        }
        else
        {
            
            DFS1(adj,vis,eariliest_discovered_ancestor,discovery_time,Child,Parent);

            eariliest_discovered_ancestor[Parent] = min(eariliest_discovered_ancestor[Child] , eariliest_discovered_ancestor[Parent] ); // if child can reach an ancestor than cur node can also reach that ancestor
            if( eariliest_discovered_ancestor[Child] > discovery_time[Parent] )        // i.e. the lowest ancestor of Child which is not its parent comes after Parent, so we need Parent--->Child to get to Child;
            {
                cout<<Child<<"----"<<Parent<<endl;
            }

        }

    }

}

void DFS2( vector< vector<ll> > &adj , vector<ll>&vis , vector<ll>&eariliest_discovered_ancestor , vector<ll>&discovery_time , ll Parent ,ll par)
{
    if(vis[Parent])return;
    vis[Parent] = 1;
    int children = 0;

    discovery_time[Parent] = eariliest_discovered_ancestor[Parent] = ++Time;

    for(auto Child : adj[Parent] )
    {
        
        if( Child == par)continue;
      

        if( vis[Child] )        // Parent--->Child can't be bridge, but we can update lowest ancestor time
        {
            eariliest_discovered_ancestor[Parent] = min(eariliest_discovered_ancestor[Parent] , discovery_time[Child]); 
        }
        else
        {
            children++;
            
            DFS2(adj,vis,eariliest_discovered_ancestor,discovery_time,Child,Parent);

            eariliest_discovered_ancestor[Parent] = min(eariliest_discovered_ancestor[Child] , eariliest_discovered_ancestor[Parent] ); // if child can reach an ancestor than cur node can also reach that ancestor

            if( par >=0 && eariliest_discovered_ancestor[Child] > discovery_time[Parent] )      // par is not null and one of its children's eariliest_discovered_ancestor is more than discovery_time of Parent
            {
                cout<<Parent<<" "<<endl;
            }
            else if(children > 1 && par == -1) // else parent is null and it have more than 1 children
            {
                cout<<Parent<<" "<<endl;
            }

        }

    }

}
const ll  NN = 3* (1e5) + 100;
int main()
{
    FAST;
    ll i ,j , TC = 1;
     cin>>TC;
    FOR1(T,TC)
    {
        ll n,m; cin>>n>>m;
        vector< vector<ll> > adj(n+1);
        vector<ll>vis(n+1),eariliest_discovered_ancestor(n+1),discovery_time(n+1); 
        FOR(i,n)adj[i].clear() , vis[i] = 0 , eariliest_discovered_ancestor[i] = 0 , discovery_time[i] = 0;
        FOR(i,m)
        {
            ll a,b; cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

      
        Time = 0; 
        
        // discovery_time -> intime of ith vertex or discovery time
        // eariliest_discovered_ancestor -> lowest time of it's any ancestor 
        DFS1(adj,vis,eariliest_discovered_ancestor,discovery_time,0,-1);  // <------ For bridges.
        // DFS2(adj,vis,eariliest_discovered_ancestor,discovery_time,0,-1);   <----- FOR Articulation points.
        cout<<endl<<endl;


        
        
        
    }
}  


// this test data provides correct result
// 3
// 5 5
// 1 0
// 0 2
// 2 1 
// 0 3
// 3 4
// 4 3
// 0 1
// 1 2
// 2 3
// 7 8
// 0 1
// 1 2 
// 2 0
// 1 3
// 1 4
// 1 6
// 3 5
// 4 5



































// vector<vector<int>> vec( n , vector<int> (m, 0));  2d vector 
// to_string(a)
//  s1.substr(1,3) 3 char of s1 starting from 1   s1.sub(pos) starting from pos
// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// reverse(v1.begin() + a , v1.begin() + b) reverse starting from a to b-1
// A lambda function is written like   [](argument1,argument2,.....){//code}
// to create unordered map for pairs unordered_map<pair<ll, ll>, ll, pair_hash> slopeCount;
// unordered_set<pair<ll, ll>, pair_hash> seen;
