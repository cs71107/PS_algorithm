#include <bits/stdc++.h>
#define f first
#define s second
#define MOD 1000000007
#define PMOD 998244353
#define pb(x) push_back(x)
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> plii;
typedef pair<int, pii> piii;
const int INF = 1e9+10;
const ll LINF = 1LL*INF*INF;
const int MAXN = 1e6+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

ll A[MAXN];

struct Node{
    Node *L,*R,*p;
    int key,cnt;
    ll vv,sum,lazy;
    bool rev;

    Node(int key_,ll vv_,Node *p) : key(key_),vv(vv_),p(p){
        L = R = nullptr;
        sum = vv_;
        cnt = 1;
        lazy = 0;
        rev = false;
    }
    Node(ll vv_) : Node(0,vv_,nullptr){}
    Node() : Node(0){}

};

struct splaytree{

    Node* rt;

    void Update(Node *x){
        x->cnt = 1;
        x->sum = x->vv;
        if(x->L){x->cnt+=x->L->cnt; x->sum+=x->L->sum;}
        if(x->R){x->cnt+=x->R->cnt; x->sum+=x->R->sum;}
    }

    void update_lazy(Node *x){
        x->vv+=x->lazy;
        if(x->L){
            x->L->lazy += x->lazy;
            x->L->sum += x->L->cnt*x->lazy;
        }
        if(x->R){
            x->R->lazy += x->lazy;
            x->R->sum += x->R->cnt*x->lazy;
        }
        x->lazy = 0;
    }

    void update_rev(Node *x){
        if(!x->rev)return;

        swap(x->L,x->R);

        if(x->L)x->L->rev = !x->L->rev;
        if(x->R)x->R->rev = !x->R->rev;
        x->rev = false;
    }


    void Rotate(Node *x)
    {
        Node *p = x->p;
        Node *v = NULL;

        if(!p)return;

        //update_rev(p);
       // update_rev(x);

        if(x==p->L){
            v = x->R;
            p->L = x->R;
            x->R = p;
        }
        else {
            v = x->L;
            p->R = x->L;
            x->L = p;
        }

        x->p = p->p;
        p->p = x;

        if(v)v->p = p;

        if(x->p){
            if(p==x->p->L)x->p->L = x;
            else x->p->R = x;
        }
        else {rt = x;}

        Update(p);// p must be before x because p is children of x
        Update(x);
        return;
    }

    void Splay(Node *x,Node *g = nullptr)
    {
        while(x->p!=g){
            Node* p = x->p;
            if(p->p==g){
                Rotate(x);
                break;
            }

            auto pp = p->p;

            if((p->L==x)==(pp->L==p)){
                Rotate(p);//zig-zig
            }
            else {
                Rotate(x);//zig-zag
            }
            Rotate(x);//zig
        }

        if(!g)rt = x;
    }

    void Insert(int key,ll value){

        Node* p = rt;
        Node** pos;
        if(!p){
            Node *x = new Node(key,value,nullptr);
            rt = x;
            return;
        }

        while(1){
            if(key==p->key)return;
            if(key<p->key){
                if(!p->L){
                    pos = &p->L; break;
                }
                p = p->L;
            }
            else {
                if(!p->R){
                    pos = &p->R; break;
                }
                p = p->R;
            }
        }

        Node *x = new Node;

        *pos = x;

        x->L = x->R = NULL;
        x->p = p;
        x->key = key;
        x->vv = value;

        Splay(x);
    }

    bool Find(int key){

        Node* p = rt;

        if(!p)return false;

        while(p){
            if(p->key==key)break;
            if(key<p->key){
                if(!p->L)break;
                p = p->L;
            }
            else {
                if(!p->R)break;
                p = p->R;
            }
        }
        Splay(p);

        return (key==(p->key));
    }

    void Delete(int key){

        if(!Find(key))return ;

        Node* p = rt;// now p's key is key

        if(p->L&&p->R){
            rt = p->L; rt->p = NULL;

            Node* x = rt;
            while(x->R)x = x->R;
            x->R = p->R;
            p->R->p = x;

            delete p;
        }
        else if(p->L){

            rt = p->L;
            rt->p = NULL;

            delete p;
        }
        else if(p->R){

            rt = p->R;
            rt->p = NULL;

            delete p;
        }
        else {
            rt = NULL;
            delete p;
        }

        return;
    }

    void kth(int k)//0-based,but if tree has dummy node, then, it woudld behave like 1-based
    {
        Node* x = rt;

        //update_lazy(x);
        //update_rev(x);

        while(1){
            while(x->L && x->L->cnt>k){
                x = x->L;
                //update_lazy(x);
                //update_rev(x);
            }
            if(x->L)k-=x->L->cnt;
            if(!k)break;
            k--;
            x = x->R;
            //update_lazy(x);
            //update_rev(x);
        }

        Splay(x);
    }

    Node* Interval(int st,int en){
        kth(en+1);
        auto tmp = rt;
        kth(st-1);
        Splay(tmp,rt);
        return (rt->R->L);
    }

    void rev(int st,int en){
        Node *x = Interval(st,en);
        x->rev = !x->rev;
    }

    void init(int n){
        rt = NULL;

        rt = new Node(-INF,0,nullptr);

        auto cur = rt;

        for(int i=1;i<=n;i++){
            cur->R = new Node(i,A[i],cur);//key,value,parent
            cur = cur->R;
        }

        cur->R = new Node(INF,0,cur);

        Node* bb;

        for(int i=n;i>=1;i--){
            Update(cur);
            if((i==(n>>1))){
                bb = cur;
            }
            cur = cur->p;
        }
        Splay(bb);
    }
}tree;

int main()
{
    ll n,m,k,a,b,x,y,q;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int tc;
    int op;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a>>x;
        if(a==1){
            cin>>y;
            tree.Insert(x,y);
        }
        else {
            tree.kth(x);
            cout<<(tree.rt->key)<<"\n";
        }
    }

    cout<<(tree.rt->key)<<" "<<(tree.rt->vv)<<"\n";


    return 0;
}
