#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int inf=2e9;
int n,m,root;
struct edge{
	int u,v,w;
}d[maxn];
int pre[maxn],inw[maxn],id[maxn],vis[maxn];
int zhuliu(int root)
{
	int ans=0;
	while( 1 )
	{
		for(int i=1;i<=n;i++)	inw[i]=inf;
		for(int i=1; i<=m ;i++)
		{
			int u=d[i].u,v=d[i].v;
			if( u!=v&&d[i].w<inw[v] )//为每个点找最小入边 
				inw[v]=d[i].w,pre[v]=u;
		}
		for(int i=1;i<=n;i++)//没有入边就无解 
			if( i!=root&&inw[i]==inf )	return -1;
		int cnt=0;
		for(int i=1;i<=n;i++)	vis[i]=id[i]=0;
		for(int i=1;i<=n;i++)
		{
			if( i==root )	continue;
			ans+=inw[i];
			int v=i;
			//首先vis[i]!=i是避免重复走环,!id[v]是不能走到之前的环去
			//v!=root因为root没有入边,可以退出了 
			while( vis[v]!=i&&v!=root&&!id[v] )
				vis[v]=i,v=pre[v];
			if( !id[v]&&v!=root )//没走到根节点,说明有环
			{
				id[v]=++cnt;//标记环中的点
				for(int u=pre[v];u!=v;u=pre[u] )
					id[u]=cnt;	
			} 
		}
		if( cnt==0 )	break;//无环,是最小树形图
		for(int i=1;i<=n;i++)	
			if( !id[i] )	id[i]=++cnt;
		for(int i=1;i<=m;i++)
		{
			int u=d[i].u,v=d[i].v;
			d[i].u=id[u],d[i].v=id[v];//缩点
			if( id[u]!=id[v] )	d[i].w-=inw[v];//修改边权 
		}
		root=id[root];
		n=cnt; 
	}
	return ans;
}
int main()
{
	cin >> n >> m >> root;
	for(int i=1;i<=m;i++)	cin >> d[i].u >> d[i].v >> d[i].w;
	cout << zhuliu( root );	
}
