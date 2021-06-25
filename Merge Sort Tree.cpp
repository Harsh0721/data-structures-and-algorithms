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

const int mx = 1e5;
vector< int>tree[mx] ;
vector<int>input;

void merge(vector<int>&v1 , vector<int>&v2 , vector<int>&result){

    int n = v1.size() , m = v2.size() , i = 0  , j = 0;

    while( i<n && j<m ){

        if( v1[i] < v2[j] )
        {
            result.pb( v1[i] );
            i++;
        }
        else 
        {
            result.pb( v2[j] );
            j++;
        }
    }

    while(i<n)result.pb( v1[i] ) ,i++;
    while(j<m)result.pb( v2[j] ), j++;
}


void buildTree(int nodeIdx, int l , int r)
{
    if(l == r){
        tree[nodeIdx].pb( input[l]  );
        return;
    }

    int mid = (l+r)/2;

    buildTree(2*nodeIdx , l , mid );
    buildTree(2*nodeIdx , mid+1,r);
    merge(tree[2*nodeIdx] , tree[2*nodeIdx + 1] , tree[nodeIdx]);

}

int queries(int nodeIdx, int nl ,int nr , int l , int r, int k)
{
    if(nl > r || nr < l )
    {
        return 0;
    }

    if(nl >= l && nr <= r)
    {
        return upper_bound( tree[nodeIdx].begin() , tree[nodeIdx].end() , k) - tree[nodeIdx].begin() - 1; // no of elements <= k
    }

    int mid = (nl + nr)/2;
    int ansL = queries(2*nodeIdx , nl,mid,l,r,k);
    int ansR = queries(2*nodeIdx + 1 , mid+1,nr,l,r,k);

    return ansL + ansR;

}

const ll  NN = 3* (1e5) + 100;
int main()
{
    FAST;
    ll i ,j , TC = 1;
    //  cin>>TC;
    FOR1(T,TC)
    {
        int n; cin>>n;
        FOR(i,n){
            int value; cin>>value;
            input.pb(value);
        }

        buildTree(1,0,n-1);
        
        
        
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
