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
#define ll  int
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
long long int INF = INT_MAX;




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
// NEXT IS FOR STORING PARH , DP IS FOR ANS , MAT IS FOR INTIAL COSTS.
int fans = 0,n =0 ;
int alvis;

void path( vector< vector<ll> > & NEXT , int start , int state )
{
    // cout<<start<<" ";
    int idx = start , cstate = state;
    
    int a = 10;
    while(1)
    {
        cout<<idx<<" ";
        int newidx = NEXT[cstate][idx];
        if(newidx == -1)break;
        cstate = cstate | (1<<newidx);
        idx = newidx;
    }
    


}
int solve( vector< vector<ll> > &dp , int state , int prev , vector< vector<ll> >&mat , vector< vector<ll> > &NEXT ) 
{
    if( state == alvis )
    {
        NEXT[state][prev] = 0;
        return mat[prev][0]; 
    }
    else if( dp[state][prev] != INF )
    {
        return dp[state][prev]; // dp state prev is like 0101 , 1 => only 1st and 3rd city are visited , and we are currently on 3rd city. 
    }

    int ans = INF , index = -1;

    for(int city=0; city<n;city++)
    {
        
        if(  ( (1<<city) & state )  == 0) // cityy is not already visited
        {
            // going from prev to this and this to all other, also we marked this city as visited.
            int new_ans = mat[prev][city] + solve(dp, state | (1<<city) , city,mat,NEXT); 

            if (new_ans<ans)
            {
                index = city;
                ans = new_ans;
            }
            
        }

    }
    // cout<<state<<" "<<prev<<" "<<ans<<endl;
    dp[state][prev] = ans;
    NEXT[state][prev] = index;
    return dp[state][prev];

}

const ll  NN = 3* (1e5) + 100;
int main()
{
    FAST;
    ll i ,j , TC = 1;
    //  cin>>TC;
    FOR1(T,TC)
    {
        cin>>n;
        // cout<<n<<endl;

        vector< vector<ll> > dp( pow(2,n) ) , NEXT( pow(2,n) );
        
        FOR(i, pow(2,n)  )
        {
            FOR(j,n)dp[i].pb(INF) ,NEXT[i].pb(-1);
        } 

        vector< vector<ll> > mat(n);
        FOR(i,n)
        {
            FOR(j,n)mat[i].pb(INF);
        }
        FOR(i,n)
        {
            FOR(j,n)cin>>mat[i][j];
        }
        alvis = pow(2,n) - 1;

        cout<<solve(dp,1,0,mat,NEXT)<<endl;
        path(NEXT,0,1);

    }
}  





































// vector<vector<int>> vec( n , vector<int> (m, 0));  2d vector 
// to_string(a)
//  s1.substr(1,3) 3 char of s1 starting from 1   s1.sub(pos) starting from pos
// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// reverse(v1.begin() + a , v1.begin() + b) reverse starting from a to b-1
// A lambda function is written like   [](argument1,argument2,.....){//code}
// to create unordered map for pairs unordered_map<pair<ll, ll>, ll, pair_hash> slopeCount;
// unordered_set<pair<ll, ll>, pair_hash> seen;
