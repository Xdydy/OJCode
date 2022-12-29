/*
Description

虽然蒜头君并没有多少钱，但是蒜头君办了很多张银行卡，共有 n 张，以至于他自己都忘记了每张银行卡里有多少钱了。他只记得一些含糊的信息，这些信息主要以下列三种形式描述：

银行卡 a 比银行卡 b 至少多 c 元。
银行卡 a 比银行卡 b 至多多 c 元。
银行卡 a 和银行卡 c 里的存款一样多。
但是由于蒜头君的记忆有些差，他想知道是否存在一种情况，使得银行卡的存款情况和他记忆中的所有信息吻合。

Input
第一行输入两个整数 n 和 m，分别表示银行卡数目和蒜头君记忆中的信息的数目。(1≤n,m≤10000)

接下来 m 行：

如果每行第一个数是 1，接下来有三个整数 a,b,c，表示银行卡 a 比银行卡 b 至少多 c元。

如果每行第一个数是 2，接下来有三个整数 a,b,c，表示银行卡 a 比银行卡 b 至多多 c元。

如果每行第一个数是 3，接下来有两个整数 a,b，表示银行卡 a 和 b 里的存款一样多。(1≤n,m,a,b,c≤10000)

Output
如果存在某种情况与蒜头君的记忆吻合，输出Yes，否则输出No。

Sample Input 1

3 3
3 1 2
1 1 3 1
2 2 3 2
Sample Output 1

Yes

很明显，题目中出现了几个约束条件：
银行卡 a 比银行卡 b 至少多 c 元。
银行卡 a 比银行卡 b 至多多 c 元。
银行卡 a 和银行卡 c 里的存款一样多。

转化为不等式方程组：

a-b>=c
a-b<=c
a=c
*/

#include<bits/stdc++.h>
using namespace std;

const int maxn=10100;
const int inf=0x3f3f3f3f;

int n,m;

struct node{
	int v,w;
	node(){ }
	node(int _v,int _w){
		v=_v;
		w=_w;
	}
};

vector <node> g[maxn];
int dst[maxn];
queue <int> qu;
bool inq[maxn];
int cnt[maxn];


int add(int u,int v,int w){
	g[u].push_back(node(v,w));
//	g[v].push_back(node());
}

int spfa(int u){
	memset(inq,0,sizeof inq);
	memset(dst,inf,sizeof dst);
	memset(cnt,0,sizeof cnt);
	dst[u]=0;
	qu.push(u);
	inq[u]=1;
	cnt[u]=1;
	while(!qu.empty()){
		u=qu.front();
		qu.pop();
		inq[u]=0;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v;
			int w=g[u][i].w;
			if(dst[v]>dst[u]+w){
				dst[v]=dst[u]+w;
				if(!inq[v]){
					qu.push(v);
					inq[v]=1;
					cnt[v]++;
					if(cnt[v]>n+1){
					return 0;	
					}
				}
			}
		}
	}
	return 1;
}


int main(){
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int d,a,b,c;
		cin >> d;
		if(d==1){
			cin >>a>>b>>c;
			g[a].push_back(node(b,-c));
		}else if(d==2){
			cin >>a>>b>>c;
			g[b].push_back(node(a,-c));
		}else{
			cin >>a>>b;
			g[a].push_back(node(b,0));
			g[b].push_back(node(a,0));
		}
	}
	
	for(int i=1;i<=n;i++){
		add(0,i,0);
	}
	if(spfa(0)){
	    cout << "Yes"<<endl;
    }else{
	    cout << "No";
    }
	return 0;
}
