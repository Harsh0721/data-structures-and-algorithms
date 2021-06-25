#include<bits/stdc++.h>                     //19UCC029 HARSH DHINGRA
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

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};



void create_dl(Node** start)
{
    Node* P = new Node();
    P->data = 1;
    P->next = P->prev = NULL;

    *start = P;


    int n;cin>>n;
    while(n--)
    {
        int D; cin>>D;
        Node *t2 = new Node();
        t2->data = D; t2->next = NULL; t2->prev = P;
        P->next = t2; P = t2;
    }

}

void add_after(Node** start , int after , int nval)
{
    Node* cur = *start;
    while(cur)
    {
        if(cur->data == after )
        {
            Node* temp = new Node();
            temp->data = nval;
            temp->prev = cur;
            temp->next = cur->next;
            cur->next = temp;
            break;
        }
        cur = cur->next;
    }
}

void delete_node(Node** start , int value)
{
    Node* cur = *start;

    if(!cur)return;

    if(cur->data == value)
    {
        
        cur->next->prev = NULL;
        *start = cur->next;
        delete cur;
        return;
    }

    Node* prev = *start;

    while(cur)
    {
        if(cur->data == value)
        {
            prev->next = cur->next;
            if(cur->next) cur->next->prev = prev;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;

    }



}

void display_dl(Node* Start)
{
	Node* tmp = new Node();
	tmp = Start;

	while(tmp != NULL)
	{
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
    cout<<endl;

}





ll dx[4] = { 0,0,1,-1 };
ll dy[4] = { 1,-1,0,0 };
string pos = "RLDU";

// check the limits dummy
void Solve()
const ll  NN = 3* (1e5) + 100;
int main()
{
    FAST;
    ll i ,j , T = 1;
    // cin>>T;
    while(T--)
    {
        i=0;j=0;
        Node* start = NULL;
        create_dl(&start);display_dl(start);
        delete_node(&start,7);display_dl(start);
        add_after(&start,2,3);display_dl(start);
        delete_node(&start,1);display_dl(start);
        add_after(&start,5,6);display_dl(start);

        
        
        
    }
}  





































// vector<vector<int>> vec( n , vector<int> (m, 0));  2d vector 
// to_string(a)
//  s1.substr(1,3) 3 char of s1 starting from 1   s1.sub(pos) starting from pos
// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// reverse(v1.begin() + a , v1.begin() + b) reverse starting from a to b-1
// A lambda function is written like   [](argument1,argument2,.....){//code}
