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
#define FOR(i,n) for(ll i = 0;i<n;i++)
#define FOR1(i,n) for(ll  i=1;i<=n;i++)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define REVERSE(s) reverse(s.begin(),s.end())
#define GCD(a,b) __gcd(a,b)
#define VFIND(v1,val) find(v1.begin() , v1.end() , val )
#define VFILL(v1 , val)   std::fill(v1.begin(), v1.end(), val);
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define all(x) x.begin() , x.end() 

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
void DPV(vector<int>v)
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

void heapify_Max(vector<int>&v1 , int i , int n)
{
    int Max = i , L = 2*i + 1 , R = 2*i + 2;

    if( L < n && v1[L] > v1[i]  )Max = L;
    if(R < n && v1[Max] < v1[R])Max = R;

    if(Max != i)
    {
        swap( v1[i] , v1[Max]);
        heapify_Max(v1,Max,n);
    }

}

void heapify_Min(vector<int>&v1 , int i , int n)
{
    int Min = i , L = 2*i + 1 , R = 2*i + 2;

    if( L < n && v1[L] < v1[i]  )Min = L;
    if(R < n && v1[Min] > v1[R])Min = R;

    if(Min != i)
    {
        swap( v1[i] , v1[Min]);
        heapify_Min(v1,Min,n);
    }

}

// check the limits dummy
const ll  NN = 3* (1e5) + 100;
int main()
{
    FAST;
    ll i ,j , T = 1;
    // cin>>T;
    while(T--)
    {
        i=0;j=0;
        
        int n;cin>>n;
        vector<int>v1(n);
        FOR(i,n)cin>>v1[i];

        for(i=n/2-1; i>=0;i--)heapify_Min(v1,i,n);

        for(i=n-1;i>=0;i--)
        {
            swap( v1[i] , v1[0] );
            heapify_Min(v1,0,i);
        }
        DPV(v1);
        
    }
}  





































// vector<vector<int>> vec( n , vector<int> (m, 0));  2d vector 
// to_string(a)
//  s1.substr(1,3) 3 char of s1 starting from 1   s1.sub(pos) starting from pos
// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// reverse(v1.begin() + a , v1.begin() + b) reverse starting from a to b-1
// A lambda function is written like   [](argument1,argument2,.....){//code}
