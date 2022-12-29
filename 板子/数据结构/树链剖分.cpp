#include<bits/stdc++.h>
using namespace std; 
  
#define ll long long 
#define Pair pair<int,int>
#define clean(a,b) memset(a,b,sizeof(a))
const int MAXN=1e5+10;
const int INF32=0x3f3f3f3f;
const ll INF64=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
const double PI=acos(-1.0);
const double EPS=1.0e-8;
 
class Segment{
	int P;
	int Tree[MAXN<<2],Lazy[MAXN<<2],Size[MAXN<<2];
	
	void PushDown(int rt){
		if(Lazy[rt]==0) return ;
		Tree[rt<<1]=(Tree[rt<<1]+Size[rt<<1]*Lazy[rt]+P)%P;
		Tree[rt<<1|1]=(Tree[rt<<1|1]+Size[rt<<1|1]*Lazy[rt]+P)%P;
		
		Lazy[rt<<1]=(Lazy[rt<<1]+Lazy[rt]+P)%P;
		Lazy[rt<<1|1]=(Lazy[rt<<1|1]+Lazy[rt]+P)%P;
		Lazy[rt]=0;
	}
	public : void SetMod(int Mod){
		P=Mod;
	}
	public : void Build(int l,int r,int rt,int a[]){
		Size[rt]=r-l+1;
		if(l==r){
			Tree[rt]=a[l];
			return ;
		}int mid=(l+r)>>1;
		Build(l,mid,rt<<1,a);Build(mid+1,r,rt<<1|1,a);
		Tree[rt]=(Tree[rt<<1]+Tree[rt<<1|1]+P)%P;
	}
	public : void Update(int ql,int qr,int val,int l,int r,int rt){
		if(ql<=l&&r<=qr){
			Tree[rt]+=Size[rt]*val;
			Lazy[rt]+=val;
			return ;
		}int mid=(l+r)>>1;
		PushDown(rt);
		if(ql<=mid) Update(ql,qr,val,l,mid,rt<<1);
		if(qr>mid) Update(ql,qr,val,mid+1,r,rt<<1|1);
		Tree[rt]=(Tree[rt<<1]+Tree[rt<<1|1]+P)%P;
	}
	public : int Query(int ql,int qr,int l,int r,int rt){
		if(ql<=l&&r<=qr) return Tree[rt];
		PushDown(rt);
		int mid=(l+r)>>1;
		int ans=0;
		if(ql<=mid) ans=(ans+Query(ql,qr,l,mid,rt<<1)+P)%P;
		if(qr>mid) ans=(ans+Query(ql,qr,mid+1,r,rt<<1|1)+P)%P;
		return ans;
	}
	public : void Show(int l,int r,int rt){
		printf("rt=%d l=%d r=%d Tree[rt]=%d\n",rt,l,r,Tree[rt]);
		if(l==r) return ;
		int mid=(l+r)>>1;
		Show(l,mid,rt<<1);Show(mid+1,r,rt<<1|1);
	}
};
struct Node1{
	int v,val,nxt;
	Node1(int _v=0,int _val=0,int _nxt=0){
		v=_v;val=_val;nxt=_nxt;
	}
};
Segment Seg;
Node1 Edge[MAXN<<2];
int Head[MAXN],Ecnt;
int Deep[MAXN],Fa[MAXN],Size[MAXN],Son[MAXN];
int Idx[MAXN],Icnt;//重新标号 
int Top[MAXN];
int A[MAXN],B[MAXN];
int n,m,R,P;
 
void Intt(){
	clean(Head,-1);Ecnt=0;
	clean(Deep,0);clean(Fa,-1);clean(Size,0);clean(Son,-1);
	Icnt=0;
}
void AddEdge(int u,int v,int val){
	Edge[Ecnt]=Node1(v,val,Head[u]);
	Head[u]=Ecnt++;
}
int DFS1(int u,int fa,int dep){
	Deep[u]=dep;
	Fa[u]=fa;
	Size[u]=1;
	int maxson=-1;
	for(int i=Head[u];i+1;i=Edge[i].nxt){
		int temp=Edge[i].v;
		if(temp==fa) continue;
		Size[u]+=DFS1(temp,u,dep+1);
		if(Size[temp]>maxson){
			maxson=Size[temp];
			Son[u]=temp;
		}
	}return Size[u];
}
void DFS2(int u,int topfa){
	Idx[u]=++Icnt;
//	cout<<"u,Idx[u]"<<u<<" "<<Idx[u]<<endl;
	Top[u]=topfa;
	B[Idx[u]]=A[u];
	if(Son[u]==-1) return ;
	DFS2(Son[u],topfa);
	for(int i=Head[u];i+1;i=Edge[i].nxt){
		int temp=Edge[i].v;
		if(Idx[temp]==0){
			DFS2(temp,temp);
		}
	}
}
void UpdatePath(int l,int r,int val){
	while(Top[l]!=Top[r]){
		if(Deep[Top[l]]<Deep[Top[r]]) swap(l,r);
		Seg.Update(Idx[Top[l]],Idx[l],val,1,n,1);
		l=Fa[Top[l]];
	}
	if(Deep[l]>Deep[r]) swap(l,r);
	Seg.Update(Idx[l],Idx[r],val,1,n,1);
}
int QueryPath(int l,int r){
	int ans=0;
	while(Top[l]!=Top[r]){
		if(Deep[Top[l]]<Deep[Top[r]]) swap(l,r);
		ans=(ans+Seg.Query(Idx[Top[l]],Idx[l],1,n,1)+P)%P;
		l=Fa[Top[l]];
	}
	if(Deep[l]>Deep[r]) swap(l,r);
	ans=(ans+Seg.Query(Idx[l],Idx[r],1,n,1)+P)%P;
	return ans;
}
void UpdateSubTree(int rt,int val){
	int l=Idx[rt],r=Idx[rt]+Size[rt]-1;
	Seg.Update(l,r,val,1,n,1);
}
int QuerySubTree(int rt){
	int l=Idx[rt],r=Idx[rt]+Size[rt]-1;
	int ans=Seg.Query(l,r,1,n,1);
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&R,&P);
	Intt();Seg.SetMod(P);
	for(int i=1;i<=n;++i){
		scanf("%d",&A[i]);
	}
	for(int i=1;i<n;++i){
		int x,y;scanf("%d%d",&x,&y);
		AddEdge(x,y,1);AddEdge(y,x,1);
	}
	DFS1(R,-1,1);
	DFS2(R,R);
	Seg.Build(1,n,1,B);
	for(int i=1;i<=m;++i){
		int oper;scanf("%d",&oper);
		if(oper==1){//x,y,z,x节点到y节点上路径的所有节点+z 
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			UpdatePath(x,y,z);
		}
		else if(oper==2){//求x，y节点的 路径之和 
			int x,y;scanf("%d%d",&x,&y);
			printf("%d\n",QueryPath(x,y));
		}
		else if(oper==3){//x节点的子树都+z 
			int x,z;scanf("%d%d",&x,&z);
			UpdateSubTree(x,z);
		}
		else{//求x节点的子树和 
			int x;scanf("%d",&x);
			printf("%d\n",QuerySubTree(x));
		}
	}
	
	
}