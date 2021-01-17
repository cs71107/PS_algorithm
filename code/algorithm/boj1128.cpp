#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,w,maxx;
ll f[60],ww[60];
ll m[51][51];
struct node
{
	ll c,w;
};
node a[60];

bool cmp(node a,node b)
{
	if (a.w!=b.w) return a.w>b.w;
	else return a.c>b.c;
}

void myfind(int i,ll w,ll c,int flag)
{
	if (c>maxx) maxx=c;
	if (i>=n) return ;

	if (f[n-1]-f[i]+a[i].c+c<=maxx) return;

	if (f[n-1]-f[i]+a[i].c+c>=maxx && ww[n-1]-ww[i]+a[i].w<=w)
	{
		maxx=f[n-1]-f[i]+a[i].c+c;
		return ;
	}
	if (flag==0 && a[i].w==a[i-1].w)
	{

			myfind(i+1,w,c,0);
			return ;
	}else
	{

	myfind(i+1,w,c,0);

	if (w<a[i].w) return ;
	myfind(i+1,w-a[i].w,c+a[i].c,1);
	}

}

int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i].w>>a[i].c;
    }
    cin>>w;
    maxx=0;
    sort(a,a+n,cmp);
    f[0]=a[0].c;
    ww[0]=a[0].w;
    for (int i=1;i<n;i++)
    {
        f[i]=f[i-1]+a[i].c;
        ww[i]=ww[i-1]+a[i].w;
    }

    myfind(0,w,0,1);

    cout<<maxx<<endl;


	return 0;
}

