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

char S[MAXN];
char T[MAXN];
int fail[MAXN];

int main()
{
    int n,m,k,a,b,x,y;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>S;
    cin>>T;


    n = strlen(S);
    m = strlen(T);

    for(int i=1,j=0;i<m;i++){
        while(j>0&&T[i]!=T[j])j = fail[j-1];
        if(T[i]==T[j])fail[i] = ++j;
    }

    vector<int> res;

    for(int i=0,j=0;i<n;i++){

        while(j>0&&S[i]!=T[j])j = fail[j-1];

        if(S[i]==T[j]){
            if(j==m-1){
                res.push_back(i-m+2);
                j = fail[j];
            }
            else j++;
        }
    }

    cout<<(int)res.size()<<"\n";

    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";

    return 0;
}
