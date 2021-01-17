#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1e6+10;
const int INF = 1e9+10;
int H,W,N;
long long A,B,C;
int pos_h[MAXN];
int pos_w[MAXN];
int min_move_cost[508][508];
int queue_h[MAXN];
int queue_w[MAXN];
int adj_h[5]={0,-1,0,1};
int adj_w[5]={-1,0,1,0};

priority_queue <pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > pq;
long long sol[508][508][5];

int main() {

	cin>>H>>W>>A>>B>>C>>N;

	for(int i=0;i<N;i++)
        cin>>pos_h[i]>>pos_w[i];

	int qst,qls;
	qst=0; qls=N;

	for(int i=0;i<=H;i++)
        for(int j=0;j<=W;j++)
            min_move_cost[i][j]=INF;

	for(int i=0;i<N;i++) {
		queue_h[i]=pos_h[i];
		queue_w[i]=pos_w[i];
		min_move_cost[queue_h[i]][queue_w[i]]=0;
	}

	while(qst<qls) {
		int new_c=min_move_cost[queue_h[qst]][queue_w[qst]]+1;
		for(int i=0;i<4;i++) {
			int new_h=queue_h[qst]+adj_h[i];
			int new_w=queue_w[qst]+adj_w[i];
			if(new_h<0||new_h>H) continue;
			if(new_w<0||new_w>W) continue;
			if(min_move_cost[new_h][new_w]<INF) continue;
			min_move_cost[new_h][new_w]=new_c;
			queue_h[qls]=new_h;
			queue_w[qls++]=new_w;
		}
		qst++;
	}

	long long LINF=1000000007;
	LINF*=LINF;
	for(int i=0;i<=H;i++) for(int j=0;j<=W;j++) for(int k=0;k<5;k++) sol[i][j][k]=LINF;

	pq.push(make_pair(0,pos_h[0]*5000+pos_w[0]+40000000));
	while(pq.size()) {
		long long now_cost=pq.top().first;
		int now_temp=pq.top().second;
		int now_type=now_temp/10000000;
		now_temp%=10000000;
		int now_h=now_temp/5000;
		int now_w=now_temp%5000;
		pq.pop();
		if(sol[now_h][now_w][now_type]<LINF) continue;
		sol[now_h][now_w][now_type]=now_cost;
		if(now_type==4) {
			for(int i=0;i<4;i++) {
				int new_h=now_h+adj_h[i];
				int new_w=now_w+adj_w[i];
				if(new_h<0||new_h>H) continue;
				if(new_w<0||new_w>W) continue;
				pq.push(make_pair(now_cost+C,new_h*5000+new_w+40000000));
			}
			for(int i=0;i<4;i++) {
				pq.push(make_pair(now_cost+B,now_h*5000+now_w+10000000*i));
			}
		} else {
			pq.push(make_pair(now_cost+C*min_move_cost[now_h][now_w],now_h*5000+now_w+40000000));
			int new_h=now_h+adj_h[now_type];
			int new_w=now_w+adj_w[now_type];
			if(new_h<0||new_h>H) continue;
			if(new_w<0||new_w>W) continue;
			pq.push(make_pair(now_cost+A,new_h*5000+new_w+10000000*now_type));
		}
	}
	cout<<sol[pos_h[N-1]][pos_w[N-1]][4];
	return 0;
}

