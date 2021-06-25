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

struct Node
{
    int data , height;
    
    Node* left,*right;

    Node(int x)
    {
        this->data = x;
        this->height = 0;
        this->left = this->right = NULL;
    }
    
};

// check the limits dummy
const ll  NN = 3* (1e5) + 100;


void Update_Heights(Node* root)
{
    int LH = -1 , RH = -1;

    if(root->left)LH = root->left->height;
    if(root->right)RH = root->right->height;

    root->height = 1 + max(LH,RH);

}
Node* Rotate_left(Node* root)
{
    Node* Y = root->right;

    root->right = Y->left;
    Y->left = root;
    
    Update_Heights(root);
    Update_Heights(Y);

    return Y;

}

Node* Rotate_right(Node* root)
{
    Node* Y = root->left;

    root->left = Y->right;
    Y->right = root;

    Update_Heights(root);
    Update_Heights(Y);

    return Y;

}

int Get_bf(Node* root)
{
    int LH = 0 , RH = 0;

    if(root->left)LH = 1 + root->left->height;
    if(root->right)RH = 1 + root->right->height;
    return RH-LH;

}


Node* Delete(Node* root , int data)
{
    
}
Node* Insert(Node* root , int data)
{
    if(!root)
    {
        return  new Node(data);
    }


    if(root->data > data)
    {
        root->left = Insert(root->left,data);
    }
    else if(root->data < data)
    {
        root->right = Insert(root->right,data);
    }
    else return root;
    
    

    Update_Heights(root);
    
    int BF = Get_bf(root);

    // if(root->data == 10)cout<<BF<<" ";
    

    if(BF > 1 && data > root->right->data ) // RR
    {
        // return Rotate_left(root);
        root = Rotate_left(root);
    }
    else if(BF > 1 && data < root->right->data) //RL
    {
        root->right = Rotate_right(root->right);
        // return   root = Rotate_left(root);
        root = Rotate_left(root);

    }
    else if(BF < -1 && data < root->left->data)//LL
    {
        // return Rotate_right(root);
        root = Rotate_right(root);

    }
    else if(BF < -1 && data > root->left->data) //LR
    {
        root->left = Rotate_left(root->left);
        // return Rotate_right(root);
        root = Rotate_right(root);
    }

    return root;
}

void Preorder(Node* root)
{
    if(!root)return;

    cout<<root->data<<" ";

    Preorder(root->left);
    Preorder(root->right);

}
int main()
{
    FAST;
    ll i ,j , T = 1;
    // cin>>T;
    while(T--)
    {
        i=0;j=0;

        int n; cin>>n;

        Node* root = NULL;

        while(n--)
        {
           
            cin>>j;
            root = Insert(root,j);
        }

        Preorder(root);


        
        
    }
}  





































// vector<vector<int>> vec( n , vector<int> (m, 0));  2d vector 
// to_string(a)
//  s1.substr(1,3) 3 char of s1 starting from 1   s1.sub(pos) starting from pos
// assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
// reverse(v1.begin() + a , v1.begin() + b) reverse starting from a to b-1
// A lambda function is written like   [](argument1,argument2,.....){//code}
