#include <bits/stdc++.h>
using namespace std;
typedef long long lt;
typedef unsigned int ui;

int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

const int maxn=500010;
ui s;
int n,Q,rt;
struct node{int v,nxt;}E[maxn<<1];
int head[maxn],tot;
int hi[maxn];
int fa[maxn][25],dep[maxn],mxd[maxn];
int son[maxn],top[maxn];
vector<int> pre[maxn],nxt[maxn];
lt ans[maxn*10];

ui get(ui x) 
{
	x^=x<<13;
	x^=x>>17;
	x^=x<<5;
	return s=x; 
}

void add(int u,int v)
{
	E[++tot].nxt=head[u];
	E[tot].v=v;
	head[u]=tot;
}

void dfs1(int u,int pa)
{
	dep[u]=mxd[u]=dep[pa]+1;
	for(int i=head[u];i;i=E[i].nxt)
	{
		int v=E[i].v;
		if(v==pa) continue;
		dfs1(v,u);
		if(mxd[v]>mxd[u]) mxd[u]=mxd[v],son[u]=v; 
	}
}

void dfs2(int u,int tp)
{
	top[u]=tp;
	if(u==tp)
	{
		int x=u;
		for(int i=0;i<=mxd[u]-dep[u];++i)
		{
			pre[u].push_back(x);
			x=fa[x][0];
		}
		x=u;
		for(int i=0;i<=mxd[u]-dep[u];++i)
		{
			nxt[u].push_back(x);
			x=son[x];
		}
	}
	
	if(son[u]) dfs2(son[u],tp);
	for(int i=head[u];i;i=E[i].nxt)
	{
		int v=E[i].v;
		if(v==son[u]||v==fa[u][0]) continue;
		dfs2(v,v);
	}
}

int solve(int u,int k)
{
	if(k==0) return u;
	u=fa[u][hi[k]];
	k-=1<<hi[k];
	k-=dep[u]-dep[top[u]];
	u=top[u];
	return k>=0?pre[u][k]:nxt[u][-k];
}

int main()
{
	n=read(); Q=read(); s=read();
	
	hi[0]=-1;
	for(int i=1;i<=n;++i)
	{
		fa[i][0]=read();
		add(fa[i][0],i); add(i,fa[i][0]);
		if(fa[i][0]==0) rt=i;
		hi[i]=hi[i>>1]+1;
	}
	
	dfs1(rt,0); dfs2(rt,rt);
	for(int i=1;(1<<i)<=n;++i)
	for(int u=1;u<=n;++u)
	fa[u][i]=fa[fa[u][i-1]][i-1];
	
	for(int i=1;i<=Q;++i)
	{
		int x=(get(s)^ans[i-1])%n+1;
		int k=(get(s)^ans[i-1])%dep[x];

		ans[i]=solve(x,k);
	}
	
	lt res=ans[1];
	for(int i=2;i<=Q;++i)
	res^=(lt)i*ans[i];
	
	printf("%lld",res);
	return 0;
}
