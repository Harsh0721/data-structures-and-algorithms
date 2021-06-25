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

const int MOD = 1e9 + 7;
long long int INF = 1e17;




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
const ll  NN = 3* (1e5) + 100;

int alldone = 15;
int dp[5][15];
int dis[5][5];
int NEXT[5][15];
int n = 4;

void Path( )
{
    int start = 0 , state = 1 ;

    while(1)
    {
        cout<<start<<" ";
        int temp = start;
        start = NEXT[start][state];

        state = ( state |  (1<< start ) ) ;

        if(start == -1)return;

    }

}

int Solve(int mask , int cur )
{
    // cout<<mask<<" "<<cur<<" "<<dp[cur][mask]<<endl;
    if(mask == alldone )
    {
        NEXT[cur][mask] = 0;
        return dis[cur][0];
    }
    else if(cur >= n)return 0;

    if( dp[cur][mask] != -1)
    {
        return dp[cur][mask];
    }

    int ans = 100 , index = -1;

    for(int i=0; i<n; i++)
    {
        
        if(  ( (1<<i)  & mask) == 0  )
        {
            int new_ans =   dis[cur][i] + Solve( mask | (1<<i) , i  ) ;

            if(new_ans < ans )
            {
                index = i;
                ans = new_ans;
            }
        }
    }

   dp[cur][mask] = ans;
   NEXT[cur][mask] = index;
   return dp[cur][mask];
}
int main()
{
    FAST;
    ll i ,j , TC = 1;
    //  cin>>TC;
    FOR1(T,TC)
    {
        memset(dp,0,sizeof dp);
        memset(dis,0,sizeof dis);
        // int n;
        cin>>n;

        FOR(i,n)
        {
            FOR(j,n)
            {
                cin>>dis[i][j] ;
                // cout<<dis[i][j]<<" ";
            }
            // cout<<endl;
            dis[i][i] = 0;
        }

        FOR(i,4)
        {
            FOR(j,16)dp[i][j] = -1 , NEXT[i][j] = -1;
        }
        cout<<Solve(1,0)<<endl;
        Path();
        
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
