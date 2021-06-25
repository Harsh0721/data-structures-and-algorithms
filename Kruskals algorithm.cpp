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
void DPV(vector<ll>v)
{
    FOR(i,v.size())cout<<v[i]<<" ";cout<<endl;
}
void DPS(set<ll>s1)
{
    for(auto it =s1.begin();it!=s1.end();it++)cout<<*it<<" ";cout<<endl;
}


struct edge
{
    int from,to,weight;
};

struct DSU
{
    int parent,rank;
};

int Find(int a , vector<DSU>&subset )
{
    if( subset[a].parent != a)
    {
        subset[a].parent = Find( subset[a].parent , subset);
    }

    return subset[a].parent;
}
void Merge(int a , int b , vector<DSU>&subset )
{
    if( subset[a].rank > subset[b].rank )
    {
        subset[b].parent = a;
    }
    else if( subset[a].rank < subset[b].rank )
    {
        subset[a].parent = b;
    }
    else
    {
        subset[b].parent = a;
        subset[a].rank++;
    }
}

bool comp(edge a , edge b)
{
    return a.weight <b.weight;
}
int main()
{
    FAST;
    ll i ,j , TC = 1;
    //  cin>>TC;
    FOR1(T,TC)
    {
        i=0;j=0;

        int n,m; cin>>n>>m;         // minimum spanning tree

        vector<edge>v1,ans;
        FOR(i,m)
        {
            int a,b,c; cin>>a>>b>>c;
            v1.pb( edge() );
            v1[i].from = a; v1[i].to = b;v1[i].weight = c;
        }

        vector<DSU>subset;
        FOR(i,n)
        {
            subset.pb( DSU() );
            subset[i].parent = i;
            subset[i].rank = 0;
        }

        sort(v1.begin(),v1.end(),comp);
        int e = 0;i=0;

        

        while(e<n-1 && i <m)
        {
            int x = Find( v1[i].from , subset );
            int y = Find( v1[i].to , subset);

            if(x != y) // they belong to different sets , i.e. upon adding this edge we won't create a cycle.
            {
                ans.pb( v1[i] );
                e++;
                Merge(x,y,subset);
            }
            i++;
            
        }
        FOR(i,ans.size() )
        {
            cout<<ans[i].from<<" "<<ans[i].to<<" "<<ans[i].weight<<endl;
        }
        



        
        
    }
}  





































// vector<vector<int>> vec( n , vector<int> (m, 0));  2d vector 
// to_string(a)
//  s1.substr(1,3) 3 char of s1 starting from 1   s1.sub(pos) starting from pos
// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// reverse(v1.begin() + a , v1.begin() + b) reverse starting from a to b-1
// A lambda function is written like   [](argument1,argument2,.....){//code}
