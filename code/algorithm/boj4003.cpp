#include <bits/stdc++.h>
using namespace std;
const int MAX = 100020;
struct report {
    int s, e;
    report() {}
    report(int s, int e) : s(s), e(e) {}
    bool operator < (const report &t) const {
        if(s == t.s) return e < t.e;
        return s < t.s;
    }
};
int n, m, k, yFull, nFull;
report yes[MAX], no[MAX];
void input(){
    cin>>n>>k>>m;
    int i;
    for(i = 0; i<m; i++){
        int ts, te, c;
        cin>>ts>>te>>c;
        if(c == 0) no[nFull++] = report(ts, te);
        else yes[yFull++] = report(ts, te);
    }
}
bool none[MAX];
int cnt, lFind[MAX], rFind[MAX];
void init(){
    sort(yes, yes+yFull);
    sort(no, no+nFull);
    int i, now;
    now = 1;
    for(i = 1; i<yFull; i++){
        while(yFull && yes[now-1].e >= yes[i].e)
            now--;
        yes[now++] = yes[i];
    }
    yFull = now;

    cnt = n;
    int j = 1;
    for(i = 0; i<nFull; i++){
        if(j < no[i].s) j = no[i].s;
        for(; j <= no[i].e; j++){
            none[j] = 1;
            cnt--;
        }
    }

    for(i = 1; i<=n; i++){
        if(!none[i]) lFind[i] = i;
        else lFind[i] = lFind[i-1];
    }

    for(i = n; i>=1; i--){
        if(!none[i]) rFind[i] = i;
        else rFind[i] = rFind[i+1];
    }
}
int lef[MAX], lFull, rgh[MAX], rFull;
vector < int > res;
void solve(){
    int i;
    if(cnt == k){
        for(i = 1; i<=n; i++)
            if(lFind[i] == i)
                res.push_back(i);
    } else {
        int last;
        last = 0;
        for(i = 0; i<yFull; i++){
            if(last < yes[i].s){
                lef[lFull++] = lFind[yes[i].e];
                last = lFind[yes[i].e];
            }
        }
        last = n+1;
        for(i = yFull-1; i>=0; i--){
            if(last > yes[i].e){
                rgh[rFull++] = rFind[yes[i].s];
                last = rFind[yes[i].s];
            }
        }
        if(lFull == k){
            for(i = 0; i<lFull; i++){
                if(lef[i] == rgh[rFull-1-i]){
                    res.push_back(lef[i]);
                }
            }

        } else {
            for(i = 0; i<yFull; i++){
                if(lFind[lFind[yes[i].e]-1] < yes[i].s)
                    res.push_back(lFind[yes[i].e]);
            }
        }
    }

    if(res.empty()) puts("-1");
    else {
        for(i = 0; i<res.size(); i++)
            printf("%d\n", res[i]);
    }
}
int main(){
    input();
    init();
    solve();
    return 0;
}
