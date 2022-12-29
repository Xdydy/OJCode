//Q L R 代表询问你从第L支画笔到第R支画笔中共有几种不同颜色的画笔。
//R P Col 把第P支画笔替换为颜色Col。
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
struct node1 {
	int l,r,ti,ID;
} query[50005];
struct node2 {
	int x,newc,oldc;
} change[50005];
int be[50005],color[50005],cc[50005],cnt[1000005];
int Ans[50005],ans;
int l,r,num,Time;
int n,m,bs;
bool cmp(node1 a,node1 b) {
	if (be[a.l]!=be[b.l]) return a.l<b.l;
	if (be[a.r]!=be[b.r]) return a.r<b.r;
	return a.ti<b.ti;
}
inline void update1(int col,int val) {
	cnt[col]+=val;
	if (val==-1) ans-=(cnt[col]==0);
	else ans+=(cnt[col]==1);
}
inline void update2(int po,int newc) {
	if (l<=po && po<=r) update1(color[po],-1),update1(newc,1);
	color[po]=newc;
}
int main() {
	scanf("%d%d",&n,&m);bs=pow(n,0.666667);
	for (int i=1;i<=n;i++) {
		scanf("%d",&color[i]);
		cc[i]=color[i];
		be[i]=(i-1)/bs+1;
	}
	for (int i=1;i<=m;i++) {
		char op=0;int x,y;
		while (op!='Q'&&op!='R') op=getchar();
		scanf("%d%d",&x,&y);
		if (op=='Q') query[++num]=(node1){x,y,Time,num};
		else change[++Time]=(node2){x,y,cc[x]},cc[x]=y;
	}
	sort(query+1,query+num+1,cmp);
	Time=0;
	l=1,r=0;//先把区间记空
	for (int i=1;i<=num;i++) {
		while (Time<query[i].ti) update2(change[Time+1].x,change[Time+1].newc),Time++;
		while (Time>query[i].ti) update2(change[Time].x,change[Time].oldc),Time--;
		while (l>query[i].l) update1(color[l-1],1),l--;
		while (r<query[i].r) update1(color[r+1],1),r++;
		while (l<query[i].l) update1(color[l],-1),l++;
		while (r>query[i].r) update1(color[r],-1),r--;
		Ans[query[i].ID]=ans;
	}
	for (int i=1;i<=num;i++) printf("%d\n",Ans[i]);
	return 0;
}
