#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000050
//欧拉线性筛：在线性时间内筛素数的同时求出所有数的欧拉函数
int N;
int tot;
int phi[MAXN];//保存各个数字的欧拉函数 
int prime[MAXN]; //按顺序保存素数
bool mark[MAXN];//判断是否是素数
void get_phi(){
    phi[1] = 1;
    for(int i = 2; i <= MAXN; i++){//相当于分解质因数的逆过程
        if(!mark[i]){
            prime[++tot] = i;
            phi[i] = i-1;
        }
        for(int j = 1; j <= tot; j++){
            if(i * prime[j] > N) break;
            mark[i * prime[j]] = 1;//确定i*prime[j]不是素数
            if(i % prime[j] == 0){//判断prime[j] 是否为 i的约数
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else{//prime[j] - 1 就是 phi[prime[j]],利用了欧拉函数的积性
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
}