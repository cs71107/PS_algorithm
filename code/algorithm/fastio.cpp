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
const int MAXN = 2e5+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

int A[MAXN];
char S[MAXN];

namespace fio {
	const int BSIZE = 1<<18;
	char buffer[BSIZE];
	char wbuffer[BSIZE];
	char ss[30];
	int pos = BSIZE;
	int wpos = 0;
	int cnt = 0;

	inline char readChar() {
		if(pos == BSIZE) {
			fread(buffer, 1, BSIZE, stdin);
			pos = 0;
		}
		return buffer[pos++];
	}
	inline int readInt() {
		char c = readChar();

		while ((c < '0' || c > '9') && (c ^ '-')) {
			c = readChar();
		}
		int res = 0;

		bool neg = (c == '-');

		if (neg) c = readChar();

		while (c > 47 && c < 58) {
			res = res * 10 + c - '0';
			c = readChar();
		}

        if(neg)return -res;
        else return res;
	}
	inline void writeChar(char x){
        if(wpos==BSIZE){
            fwrite(wbuffer,1,BSIZE,stdout);
            wpos = 0;
        }
        wbuffer[wpos++] = x;
	}
    inline void writeInt(int x){
        if(x<0){
            writeChar('-');
            x = -x;
        }
        if(!x){
            writeChar('0');
        }
        else {
            cnt = 0;
            while(x){
                ss[cnt] = (x%10)+'0';
                cnt++;
                x/=10;
            }
            for(int j=cnt-1;j>=0;j--){
                writeChar(ss[j]);
            }
        }

    }
    inline void my_flush(){
        if(wpos){
            fwrite(wbuffer,1,wpos,stdout);
            wpos = 0;
        }
    }

}

int main()
{
    int n,m,k,a,b,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int tc;

    n = fio::readInt();

    for(int i=0;i<n;i++){
        a = fio::readInt();
        b = fio::readInt();
        fio::writeInt(a+b);
        fio::writeChar('\n');
    }

    fio::my_flush();

    return 0;
}

