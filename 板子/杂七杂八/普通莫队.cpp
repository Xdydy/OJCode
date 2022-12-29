//对于每个询问在一行中输出分数A/B表示从该询问的区间[L,R]中随机抽出两只袜子颜色相同的概率。
//若该概率为0则输出0/1，否则输出的A/B必须为最简分数。


#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
struct node {
	int l,r,ID;
} qu[50005];
int be[50005],color[50005],sum[50005];
LL ans1[50005],ans2[50005],ans;
int l,r;
int n,m,bs;
bool cmp(node a,node b) {
	if (be[a.l]!=be[b.l]) return a.l<b.l;
	return a.r<b.r;
}
inline void update(int col,int val) {
	if (val==-1) ans-=2*sum[col]-2,sum[col]--;
	else ans+=2*sum[col],sum[col]++;
}
LL gcd(LL a,LL b) {
	if (b==0) return a;
	return gcd(b,a%b);
}
int main() {
	scanf("%d%d",&n,&m);bs=sqrt(n);
	for (int i=1;i<=n;i++) {scanf("%d",&color[i]);be[i]=(i-1)/bs+1;}
	for (int i=1;i<=m;i++) {scanf("%d%d",&qu[i].l,&qu[i].r);qu[i].ID=i;}
	sort(qu+1,qu+m+1,cmp);
	l=1,r=0;//先把区间记空
	for (int i=1;i<=m;i++) {
		while (l>qu[i].l) update(color[l-1],1),l--;
		while (r<qu[i].r) update(color[r+1],1),r++;
		while (l<qu[i].l) update(color[l],-1),l++;
		while (r>qu[i].r) update(color[r],-1),r--;
		int ID=qu[i].ID;
		ans1[ID]=ans;ans2[ID]=(LL)(qu[i].r-qu[i].l+1)*(qu[i].r-qu[i].l);
		if (ans==0) ans2[ID]=1;
		LL tmp=gcd(ans1[ID],ans2[ID]);
		ans1[ID]/=tmp;ans2[ID]/=tmp;
	}
	for (int i=1;i<=m;i++) printf("%lld/%lld\n",ans1[i],ans2[i]);
	return 0;
}
/*
-1:(sum-1)*(sum-2)-(sum)*(sum-1)=-2*sum+2
+1:(sum+1)*(sum)-(sum)*(sum-1)=2*sum
*/
