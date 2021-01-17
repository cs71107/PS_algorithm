#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
typedef vector<int> vi;

typedef struct CHT{
    ll la[MAXN], lb[MAXN]; int lz[MAXN];
    int stkn=0,pt=1;
    void insert(ll a, ll b, int z){
        while(stkn>pt){
            if(a==la[stkn] && b>=lb[stkn]) stkn--;
            else if((lb[stkn]-b)*(la[stkn]-la[stkn-1])<(a-la[stkn])*(lb[stkn-1]-lb[stkn])) stkn--;
            else break;
        }
        if(a==la[stkn] && b>=lb[stkn] && z!=0)
            return;
        la[++stkn]=a;
        lb[stkn]=b;
        lz[stkn]=z;
    }
    pli query(ll x){
        while(pt<stkn && (lb[pt]-lb[pt+1])<(la[pt+1]-la[pt])*x) pt++;
        return make_pair(la[pt]*x+lb[pt],lz[pt]);
    }
}CHT;

ll a[MAXN],D[2][MAXN],S[MAXN];
int pre[205][MAXN];

int main(){
    int n,k;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        S[i]=S[i-1]+a[i];
    }
    for(int i=1;i<=k;i++){
        CHT c; c.insert(0,0,0);
        for(int j=1;j<=n;j++){
            pli temp=c.query(S[j]);
            D[i&1][j]=temp.first;
            pre[i][j]=temp.second;
            c.insert(S[j],D[(i+1)&1][j]-S[j]*S[j],j);
        }
    }
    cout<<D[k&1][n]<<"\n";


    int here=n;
    vi ans;
    ans.push_back(-1);
    for(int i=1;i<=k;i++){
        ans.push_back(pre[k-i+1][here]);
        here=pre[k-i+1][here];
    }
    sort(ans.begin(),ans.end());
    for(int i=1;i<=k;i++){
        if(ans[i]==0) ans[i]=1;
        if(ans[i]<=ans[i-1]) ans[i]=ans[i-1]+1;
        cout<<ans[i]<<" ";
    }

    return 0;
}

