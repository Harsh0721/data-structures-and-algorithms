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


void compute_lps (string pat , int lps[] )
{
    int n = pat.size() ,i=0,j=1;

    while(j<n)
    {
        if( pat[i] == pat[j] )
        {
            lps[j] = i + 1;
            i++; j++;
        }
        else
        {
            if(i > 0 )
            {
                i = lps[i-1];
            }
            else i = 0 , j++;
        }
    }
}

int Search(string pat , string text , int lps[] )
{
    int n = text.size() , m = pat.size() , i=0, j=0 , ans = 0;

    while(i<n)
    {

        if( text[i] == pat[j] )
        {
            i++; j++;
        }
        else
        {
            if(j > 0 )
            {
                j = lps[j-1];
            }
            else j = 0 , i++;
        }

        if(j == m )
        {
            ans++;
            j = lps[j-1]; 
        }
    }

    return ans;

}
   
const ll  NN = 3* (1e5) + 100;
int main()
{
    FAST;
    ll i ,j , TC = 1;
    //  cin>>TC;
    FOR1(T,TC)
    {

        string s;cin>>s;
								
        int lps[ s.size() + 1 ];
								memset(lps,0,sizeof lps);
        compute_lps(s,lps);
        cout<<lps[s.size() - 1];
        
        
    }
}  











/* A C A C A B A C A C A  B  A  C  A  C  A  C 
   0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
   i j 

   A C A C A B A C A C A  B  A  C  A  C  A  C 
   0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
   i   j 

   A C A C A B A C A C A  B  A  C  A  C  A  C 
   0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
     i   j

   A C A C A B A C A C A  B  A  C  A  C  A  C 
   0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
       i   j  

   A C A C A B A C A C A  B  A  C  A  C  A  C          
   0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
         i   j   
         pat[i] != pat[j] ->

															3			5
         A C A C A B 
             		i			j  -> pat[0..i] = pat[j-i...j-1]
																									pat[0..1...2] = pat[2..3..4]  
				                     pat[0..0] = pat[2..2] => pat[0..0] = pat[4..4]  
																									
															now if pat[1] = pat[5] : i.e pat[ lps[i-1]  ] = pat[j] => pat[0..1] = pat[4..5] 

															i = lps[i-1];
													
			A C A C A B A C A C A  B  A  C  A  C  A  C          
   0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
					i							j																																			not eq => i = lps[i-1];

			A C A C A B A C A C A  B  A  C  A  C  A  C          
   0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
			i									j

			A C A C A B A C A C A  B  A  C  A  C  A  C          
   0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
			i											j	

			A C A C A B A C A C A  B  A  C  A  C  A  C          
   0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
					i											j	

			A C A C A B A C A C A  B  A  C  A  C  A  C          
   0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17			lps[j] = i+1; if equal
							i											j			
															
				A C A C A B A C A C A  B  A  C  A  C  A  C          
   	0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
										i											j													
								
				A C A C A B A C A C A  B  A  C  A  C  A  C          
   	0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
												i											j		

				A C A C A B A C A C A  B  A  C  A  C  A  C          
   	0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
														i												 j																					

   A C A C A B A C A C A  B  A  C  A  C  A  C          
   	0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
																i												 j						 

			
   A C A C A B A C A C A  B  A  C  A  C  A  C          
   	0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
																		i												 		j				

			A C A C A B A C A C A  B  A  C  A  C  A  C          
   	0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
																				i												 		j																																     
   

			A C A C A B A C A C A  B  A  C  A  C  A  C          
   	0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
																						i												 				j				

				A C A C A B A C A C A  B  A  C  A  C  A  C          
   	0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
																									i												 				j					

			A C A C A B A C A C A  B  A  C  A  C  A  C          
   	0 1 2 3 4 5 6 7 8 9 10 11 12	13 14 15 16 17
																												i												 				j			

																													A C A C A = 				A  C  A  C  A																																							
																													0........4 =    12...........16 
																													now check if 5 = 17 if yes 0....5 = 12...17
																													
																														A C A        = 	A C A
																														0....2							=   14...16
																														now check if 3 = 17

																															3 = 17 so 0...4 = 14..17
																															so lps = 4



   LPS 0 0
       1 0
       2 1
       3 2
       4 3
       5 0
       6 1
       7 2
       8 3
       9 4
       10 5
       11 6
       12	7
       13 8
       14 9
       15 10
       16 11
       17 2























*/
// vector<vector<int>> vec( n , vector<int> (m, 0));  2d vector 
// to_string(a)
//  s1.substr(1,3) 3 char of s1 starting from 1   s1.sub(pos) starting from pos
// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// reverse(v1.begin() + a , v1.begin() + b) reverse starting from a to b-1
// A lambda function is written like   [](argument1,argument2,.....){//code}
// to create unordered map for pairs unordered_map<pair<ll, ll>, ll, pair_hash> slopeCount;
// unordered_set<pair<ll, ll>, pair_hash> seen;
