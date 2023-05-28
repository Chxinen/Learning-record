#include<bits/stdc++.h>
using namespace std;
const int Maxsize=1001;
int arr[Maxsize][Maxsize];
typedef struct node *Stack;
struct node {
	int data[Maxsize];
	int top;
};
int pop(Stack s) {
	if(s->top>0) return s->data[--(s->top)];
	else return -1;
}
int push(Stack s,int m,int item) {
	int d;
	if(s->top<m) {//why not s->top<=m ?
		d=item;
		s->data[++(s->top)]=item;
		return d;
	} else return -1;
}
int main() {
	int m,n,k;
	cin>>m>>n>>k;
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=n; j++) {
			cin>>arr[i][j];
		}
	}
	for(int i=1; i<=k; i++) {
		Stack s;
		s=new struct node;
		int flag=0,cnt=1,flag2=0,d;
		for(int l=1; l<=n||(s->top&&d<=n);) {
			if(flag2==0) d=push(s,m,cnt++);//入栈，top++，cnt++；
			if(arr[i][l]==d) {
				d=pop(s);//出栈，top--；
				l++;
				flag2=1;
			} else flag2=0;
			if(d==-1) {
				cout<<"NO"<<endl;
				flag=1;
				break;
			} //元素用完,栈满
		}
		if(flag==0)cout<<"YES"<<endl;
	}
	return 0;
}
