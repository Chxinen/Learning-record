#include<bits/stdc++.h>
using namespace std;
const int Maxsize=31;
int Pre[Maxsize];
int Mid[Maxsize];
typedef struct node* Stack;
struct node{
	int mid[Maxsize];
	int top;
};
void push(Stack S,int m){
	if(S->top<Maxsize-1) S->mid[++S->top]=m;
	return;
}
int pop(Stack S){
	if(S->top==-1) return -1;
	else return S->mid[S->top--];
}
int flag=0;
void PostOrderTraversal(int root,int mid,int num) {
	if(num==0) return;
	if(num==1) {
		if(flag)cout<<" "<<Pre[root];
		else {
			cout<<Pre[root];
			flag=1;
		}
		return;
	}
	int i,lroot,rroot,rmid,lnum,rnum;
	for(i=0;Pre[root]!=Mid[mid+i];i++);
	lnum=i;
	rnum=num-lnum-1;
	rmid=mid+lnum+1;
	lroot=root+1;
	rroot=root+lnum+1;
	PostOrderTraversal(lroot,mid,lnum);
	PostOrderTraversal(rroot,rmid,rnum);
	cout<<" "<<Pre[root];
}
int main() {
	int num,m,cnt1=1,cnt2=1,root=1,mid=1;
	string s;
	Stack S=new struct node;//给S分配一个地址后top会自动为0 
	cin>>num;
	for(int i=1;i<=2*num;i++){
		cin>>s;
		if(s.size()==4){
			cin>>m;//there was a mistake of cin>>s>>m
			Pre[cnt2++]=m;
			push(S,m);	
		} 
		else Mid[cnt1++]=pop(S);
	}
	PostOrderTraversal(root,mid,num); 
	return 0;
}
//把结点通过长度（树的结点数）进行划分 
