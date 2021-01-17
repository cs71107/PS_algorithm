#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
int m, d, par[MAXN+1], cnt[MAXN+1];
struct point {
    int x, y, idx;
    point() {}
    point(int _x, int _y, int _idx)
        :x(_x), y(_y), idx(_idx) {}
    bool operator<(point i) const {
        return y < i.y || y == i.y && x < i.x;
    }
}p[MAXN+1];
bool compx(point i, point j) { return i.x < j.x || i.x == j.x&&i.y < j.y; }
int root(int h) {
    if (h == par[h]) return h;
    return par[h] = root(par[h]);
}
set<point> st;
void act() {
    sort(p, p + m, compx);
    for (int i = 0, h = 0; i < m; i++) {
        while (p[i].x - p[h].x>d) st.erase(p[h++]);
        for (set<point>::iterator it = st.lower_bound(point(-1e9, p[i].y - d, -1));
        it != st.end() && it->y <= p[i].y;) {
            par[root(it->idx)] = root(p[i].idx);
            st.erase(it++);
        }
        st.insert(p[i]);
    }
}
int main() {
    scanf("%d %d", &m, &d);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        p[i] = point(a + b, a - b, i);
        par[i] = i;
    }
    act();
    for (int i = 0; i < m; i++) p[i].x *= -1;
    st.clear();
    act();
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < m; i++) {
        ans1 += cnt[root(i)]++ == 0;
        ans2 = max(ans2, cnt[root(i)]);
    }
    printf("%d %d", ans1, ans2);
    return 0;
}
