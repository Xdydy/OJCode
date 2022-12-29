#include <bits/stdc++.h>
using namespace std;  
 
#define ll long long  
//#define max(a,b) (a)>(b)?(a):(b)
//#define min(a,b) (a)<(b)?(a):(b) 
#define clean(a,b) memset(a,b,sizeof(a))// 水印 
//std::ios::sync_with_stdio(false);
const int MAXN=1e5+10;
const int INF=0x3f3f3f3f;
const ll mod=1e9+7;
 
struct node{
	int v,w,nxt;
	node(int _v=0,int _nxt=0):
	v(_v),nxt(_nxt){}
}edge[MAXN<<1];
int head[MAXN],ecnt;
int fa[MAXN][30],deep[MAXN];
int k;
int n,m;
 
map<string,int> mp1;
map<int,string> mp2;
 
void intt()
{
	mp1.clear();
	mp2.clear();
	clean(head,-1);
	clean(deep,0);
	clean(fa,-1);
	ecnt=0;
	k=1;
}
 
void add(int u,int v)
{
	edge[ecnt]=node(v,head[u]);
	head[u]=ecnt++;
}
 
void dfs(int u)
{
	for(int i=head[u];i+1;i=edge[i].nxt)
	{
		int temp=edge[i].v;
		if(deep[temp]==0)
		{
			deep[temp]=deep[u]+1;
			fa[temp][0]=u;//父节点是u 
			int up=0,pre=u;//从父节点开始向上找 
			while(fa[pre][up]>=0)
			{
				fa[temp][up+1]=fa[pre][up];//子节点的第2^(up+1)父辈是pre的2^up父辈 
				pre=fa[pre][up++];
			}
			dfs(temp);
		}
	}
}
 
int lca(int a,int b)
{
	if(deep[a]<deep[b])
		swap(a,b);
	int lim=log2(deep[a])+1;
	//使他们的深度相同 
	for(int i=lim;i>=0;--i)
	{
		if(deep[fa[a][i]]>=deep[b])
			a=fa[a][i];
	}
	if(a==b)
		return a;
	for(int i=lim;i>=0;--i)
	{
		if(fa[a][i]!=fa[b][i])
		{
			a=fa[a][i];
			b=fa[b][i];
		}
	}
	if(fa[a][0]==fa[b][0])
		return fa[a][0];
	else
		return -1;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	intt();
	cin>>n;
	string name1,name2;
	for(int i=1;i<=n;++i)
	{
		cin>>name1>>name2;
		if(mp1[name1]==0)//name1对应int 
		{
			mp1[name1]=k;
			mp2[k++]=name1;
		}
		if(mp1[name2]==0)//name2对应int 
		{
			mp1[name2]=k;
			mp2[k++]=name2;
		}
		add(mp1[name1],mp1[name2]);
//		add(mp1[name2],mp1[name1]);
	}
	deep[1]=1;
	dfs(1);
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>name1>>name2;
		if(name1==name2)
			cout<<name1<<endl;
		else
		{
			int ans=lca(mp1[name1],mp1[name2]);
			if(ans==-1)
				cout<<ans<<endl;
			else
				cout<<mp2[ans]<<endl;
		}
	}
}