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
long long int INF = 1e16;



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

int main()
{
    FAST;
    ll i ,j , TC = 1;
    //  cin>>TC;
    FOR1(T,TC)
    {
        i=0;j=0;

        int n,m,src; cin>>n>>m>>src;        //shortest path from src to every other node

        vector<edge>v1,ans;
        FOR(i,m)
        {
            int a,b,c; cin>>a>>b>>c;
            v1.pb( edge() );
            v1[i].from = a; v1[i].to = b;v1[i].weight = c;
        }

        vector<int>dis(n);
        fill(dis.begin(),dis.end(),INF);
        // FOR(i,n)cout<<dis[i]<<" ";
        dis[src]=0;

        FOR1(i,n-1) //  (vertices-1) * edges also check for n = 1 , or simply just compute n times.
        {
            FOR(j,m)
            {
                int F = v1[j].from , T = v1[j].to , W = v1[j].weight;

                if( dis[F] != INF && dis[F] + W < dis[T] )
                {
                    dis[T] = dis[F] + W;
                }

            }
        }

        FOR(i,n)
        {
            bool iteration = false;
            FOR(j,m)
            {
                int F = v1[j].from , T = v1[j].to , W = v1[j].weight;

                if( dis[F] != 1000 && dis[F] + W < dis[T] )
                {
                    iteration = true;
                    dis[T] = -99999;
                    // cout<<"-ve cycle"<<endl;
                }
            }

            if(!iteration)break;
        }
        FOR(i,n)cout<<dis[i]<<" ";


        



        
        
    }
}  





// https://www.cmi.ac.in/~madhavan/nptel-algorithms-2015/week4/pdf/nptel-week4-module3-bellman-ford.pdf 
//  check eg in this for proof of why we have to run loop n times.

// NOTE N-1 CYLCES TO RELAX 
// 1 CYLCE TO DETECT -VE CYCLE
// N-2 CYCLES TO REWRITE IMAPCT OF THIS 1 -VE CYCLE.































// vector<vector<int>> vec( n , vector<int> (m, 0));  2d vector 
// to_string(a)
//  s1.substr(1,3) 3 char of s1 starting from 1   s1.sub(pos) starting from pos
// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// reverse(v1.begin() + a , v1.begin() + b) reverse starting from a to b-1
// A lambda function is written like   [](argument1,argument2,.....){//code}
