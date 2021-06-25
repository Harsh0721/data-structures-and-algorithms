#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;  

#define pb push_back
#define ll long long int
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
#define ITX(it,x1) for(auto it = x1.begin();it!=x1.end();it++)
#define I insert
#define VFIND(v1,val) find(v1.begin() , v1.end() , val )
#define VFILL(v1 , val)   std::fill(v1.begin(), v1.end(), val);
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define all(x) x.begin() , x.end() 

const int N = 1e6;

int n;

vector<int>par(N) , Size(N); 



void MakeSet() // to initialize all elements of set as individual's i.e. size of each set is 1
{
    FOR1(i,n)
    {
        par[i] = i , Size[i] = 1;
        MIN[i] = i ; MAX[i] = i;
    }
   
}

int find(int x) 
{
    int root = x;
    while( par[root] != root) root = par[root];

    int id = x;

    while( id != root)  // height compression setting par of each node to root directly
    {
        int next = par[id];
        par[id] = root;
        id = next;
    }
    
    return par[x];
    
}

void Union(int a , int b)
{
    
   
    
        int x = find(b); // x is par b 
            
        int y = find(a); // y is par a
        
        if( Size[x] < Size[y] )swap(x,y); // x > y
            
        par[y] = x;   a = x; b =y;
        
        if(a != b ) Size[x] += Size[y]; 
        
        
}


int main()
{
    FAST;
    ll i ,j , T = 1;
    // cin>>T;
    while(T--)
    {
        i=0;j=0;
        cin>>n;
        MakeSet();
        
    }
}  

