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
#define ll int
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

vector<int>temp;

void DFS1(vector< vector<ll > >&adj , int v , vector<int>&vis , stack<int>&s1 )
{
    if( vis[v] )return;
    vis[v] = 1;
   

    for(auto u : adj[v] )
    {
        if(!vis[u] )
        {
            DFS1(adj,u,vis,s1);
        }
    }
    
    s1.push(v);
}


void DFS2(vector< vector<ll > >&adj , int v , vector<int>&vis  )
{
    if( vis[v] )return;
    vis[v] = 1; temp.pb(v);

    for(auto u : adj[v] )
    {
        // if(v == 0)cout<<u<<" ";
        if(!vis[u] )
        {
            DFS2(adj,u,vis);
        }
    }

}

const ll  NN = 3* (1e5) + 100;
int main()
{
    FAST;
    ll i ,j , TC = 1;
    //  cin>>TC;
    FOR1(T,TC)
    {
        ll n,m; cin>>n>>m;

        vector< vector<ll> > adj1(n+1),adj2(n+1),SCC;
        vector<ll>vis(n+1);

        FOR(i,m)
        {
            ll a,b; cin>>a>>b;
            adj1[a].pb(b); adj2[b].pb(a);
        }

        stack<int>s1;
        FOR(i,n) if(!vis[i] ) DFS1(adj1,i,vis,s1); // creating stack

        fill(vis.begin() , vis.end() , 0);

        while(s1.size() > 0)            // DFS in reverse order with rev adjancy list.
        {
            temp.clear();
            cout<<s1.top()<<" ";
            if( !vis[ s1.top() ] )
            {
                DFS2(adj2,s1.top(),vis);
            }
            DPV(temp);cout<<endl;
            s1.pop();
            SCC.pb(temp);
        }

        cout<<endl;

        for(auto u : SCC)DPV(u);


        
        
    }
}  






/// PEHLE NORMAL DFS , JB V KE SAARE CHILD TRAVERSE HOJAYE PUSH TO STACK.
/// REVERSE ALL THE EDGES , FRR SE DFS, EVERYTIME WE'LL GET A S.C.C.
// O(V+E)

/*
    we do 2 DFS on basis of ending time in DFS1. similar to TOP sort.

    abb let's say 2 SCC C and C'.

    --------------EQUATION1:------------- 

    if there's and edge from C->C' then F[C] > F[C']  
    there will be an edge from C To C' but not from C' to C. IN normal graph  
    and there will be an edge from C' To C but not from C To C' in transpose. 

    PROOF : 
    IF AN EDGE FROM C' IS CHOSEN FIRST, WE CAN'T HAVE ANY EDGE FROM C' TO C ELSE C AND C' WILL BE IN 1 SCC.
    SO C WILL AUTO HAVE FINISH TIME > C' AS IT WILL BE DFS AFTERWARDS

    IF AN EDGE FROM C IS CHOSEN FIRST, WE HAVE AN EDGE FROM C->C' , SO AFTER ALL VERTICES OF C' ARE DISCOVERED
    WE COME BACK TO C AND HENCE FINISH TIME OF C > C'
    ----------------------------------------------------------------------------------------------------------

    SO WE CAN CONCLUDE , IF THERE IS AN EDGE FROM C TO C' IN E TRANSPORT , THEN F[C] < F[C'] IN NORMAL DFS 
    AND IF F[C] > F[C'] , THEN THERE CANT BE ANY EDGE FROM C TO C' IN E TRANSPORT (E IS GRAPH )

    so we start from C , it will go to all components in this subset i.e. all SCC. 
    BECAUSE IF F[C] > F[C'] THERE WILL BE NO EDGE FROM C TO C' IN ET , SO IT WILL ONLY VISIT VERTICES IN IT'S SCC.

    NOW ONCE C IS DONE , WE WILL TAKE NEXT BIGGEST F[C] i.e F[C']
    NOW F[C'] WILL HAVE AN EDGE FROM C->C' ( F[C'] < F[C] SO WE HAVE AN EDGE FROM C' TO C IN ET ) BUT AS ALL EDGES IN C
    ARE ALLREADY VISITED, WE WILL NO GO TO ANY EDGE IN C.

    SIMILARLY CONTINUE.

    [ if to goes to some vertex x it'll be present in this SCC ] 

*/




























// vector<vector<int>> vec( n , vector<int> (m, 0));  2d vector 
// to_string(a)
//  s1.substr(1,3) 3 char of s1 starting from 1   s1.sub(pos) starting from pos
// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// reverse(v1.begin() + a , v1.begin() + b) reverse starting from a to b-1
// A lambda function is written like   [](argument1,argument2,.....){//code}
// to create unordered map for pairs unordered_map<pair<ll, ll>, ll, pair_hash> slopeCount;
// unordered_set<pair<ll, ll>, pair_hash> seen;
