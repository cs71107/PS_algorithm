#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX_N 3000
using namespace std;
typedef long long ll;
ll n, x, y, z, res;
vector<ll> ypos;
ll max(ll a, ll b, ll c, ll d,ll e) {
    return max(max(a, b), max(c, max(d, e)));
}
struct element {
    ll x, y, z;
    bool operator<(const element &A)const {
        return x < A.x;
    }
};
struct mseg {    //왼쪽 끝부터 최대 연속 합,오른쪽 끝부터 최대 연속 합,구간 합, 구간의 최대 연속 합
    ll lsum, rsum, tsum, msum;
};
mseg seg[4 * MAX_N];
element ele[MAX_N];
ll get_ypos(ll pos) {
    return lower_bound(ypos.begin(), ypos.end(), pos) - ypos.begin();
}
void update(ll pos, ll val, ll node, ll x, ll y) {
    if (y < pos || pos < x)
        return;
    if (x == y) {
        seg[node].tsum += val;
        seg[node].lsum += val;
        seg[node].rsum += val;
        seg[node].msum += val;
        return;
    }
    ll mid = (x + y) >> 1;
    update(pos, val, node * 2, x, mid);
    update(pos, val, node * 2 + 1, mid + 1, y);
    seg[node].lsum = max(seg[node * 2].lsum, seg[node * 2].tsum + seg[node * 2 + 1].lsum);
    seg[node].rsum = max(seg[node * 2 + 1].rsum, seg[node * 2 + 1].tsum + seg[node * 2].rsum);
    seg[node].tsum = seg[node * 2].tsum + seg[node * 2 + 1].tsum;
    seg[node].msum = max(seg[node * 2].rsum + seg[node * 2 + 1].lsum, seg[node * 2].msum, seg[node * 2 + 1].msum, seg[node].lsum, seg[node].rsum);
}
ll query(ll lo, ll hi, ll node, ll x, ll y) {
    if (y < lo || hi < x)
        return 0;
    if (lo <= x&&y <= hi)
        return seg[node].msum;
    ll mid = (x + y) >> 1;
    return max(query(lo, hi, node * 2, x, mid), query(lo, hi, node * 2 + 1, mid + 1, y));
}
int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &x, &y, &z);
        ele[i] = { x,y,z };
        ypos.push_back(y);
    }
    sort(ele, ele + n);
    sort(ypos.begin(), ypos.end());
    ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());
    const ll MAX_Y = ypos.size();
    for (int i = 0; i < n; i++) {
        memset(seg, 0, sizeof(seg));
        if (i&&ele[i].x == ele[i - 1].x)
            continue;
        for (int j = i; j < n; j++) {
            ll pos = get_ypos(ele[j].y);
            update(pos, ele[j].z, 1, 0, MAX_Y - 1);
            if (j != n - 1 && ele[j].x == ele[j + 1].x)
                continue;
            ll q = query(0, MAX_Y - 1, 1, 0, MAX_Y - 1);
            res = max(q, res);
        }
    }
    printf("%lld\n", res);
    return 0;
}



