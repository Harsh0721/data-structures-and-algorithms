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



ll dx[4] = { 0,0,1,-1 };
ll dy[4] = { 1,-1,0,0 };
string pos = "RLDU";

// check the limits dummy
const ll  NN = 3* (1e5) + 100;

class Node
{
	public:
	int data;
	Node* next;

};

Node* start = NULL;

Node* create_ll(Node* start)
{
	start = new Node();
	start->data = 1;

	Node* tmp = new Node();
	tmp = start;

	// cout<<"Enter elements"<<endl;
	int n; cin>>n;
	while(n--)
	{
		
		// cout<<"Enter data"<<endl;
		int d; cin>>d;

		Node* t2 = new Node();
		t2->data = d;
		t2->next = NULL;

		tmp->next = t2;
		tmp = t2;
	}

	return start;
}

void display_ll(Node* Start)
{
	Node* tmp = new Node();
	tmp = Start;

	while(tmp != NULL)
	{
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}

}

Node* add_node(Node* start)
{
	// cout<<"1 : add at start"<<endl<<"2 : add at last"<<endl<<"3: add after value x "<<endl;
	int opt; cin>>opt;

	Node* new_node = new Node();

	if(opt == 1)
	{
		new_node->data = 0;
		new_node->next = start;
		start = new_node;
	}
	else if(opt == 2)
	{
		new_node = start;

		while(new_node->next != NULL)
		{
			new_node = new_node->next;
		}

		Node* new_node_at_last = new Node();
		new_node_at_last->data = 7;

		new_node->next = new_node_at_last;
		new_node_at_last->next = NULL;

	}
	
	return start;

}

Node* delete_node(Node* start , int key)
{
	Node* tmp_node = start ;
	Node* prev_node = new Node();

	if(start->data == key)
	{
		start = start->next;
		delete tmp_node;
	}
	else
	{
		tmp_node = start->next;
		Node *prev_node = start;

		while(tmp_node != NULL && tmp_node->data != key)
		{
			prev_node = tmp_node;
			tmp_node = tmp_node->next;
		}

		if(tmp_node == NULL)return tmp_node;
		else 
		{
			prev_node->next = tmp_node->next;
			delete tmp_node;
		}
	}
	
		return start;

}

void change(Node* head)
{
	// Node* cur = *head;
	// while(head)
	// {
	// 	head->data += 3;
	// 	head = head->next;
	// }

	// head = head->next;
	// head = head->next;

	// head->next = NULL;
	// head = NULL;
	// display_ll(head);
	cout<<endl<<endl;
}
int main()
{
    FAST;
    ll i ,j , T = 1;
    // cin>>T;
    while(T--)
    {
        i=0;j=0;

		start = create_ll(start);
		change(start);
		display_ll(start);cout<<endl;
		// start = add_node(start);
		// display_ll(start);cout<<endl;
		// start = add_node(start);
		// display_ll(start);cout<<endl;
		// start = delete_node(start,0);
		// display_ll(start);cout<<endl;
		// start = delete_node(start,5);
		// display_ll(start);cout<<endl;
		// start = delete_node(start,7);
		// display_ll(start);cout<<endl;
		



        
        
    }
}  





































// vector<vector<int>> vec( n , vector<int> (m, 0));  2d vector 
// to_string(a)
//  s1.substr(1,3) 3 char of s1 starting from 1   s1.sub(pos) starting from pos
// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// reverse(v1.begin() + a , v1.begin() + b) reverse starting from a to b-1
// A lambda function is written like   [](argument1,argument2,.....){//code}
