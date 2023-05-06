#include<bits/stdc++.h>
using namespace std;
const int Maxsize=1001;
typedef struct node *stack;
struct node {
	int data[Maxsize];
	int top;
};
int pop(stack s) {
	if(s->top>0) return s->data[(s->top)--];
	else return -1;
}
int push(stack s,int m,int item) {
	if(top<m) {
		s->data[(s->top)++]=item;
		return s->data[(s->top)++];
	} else return -1;
}
int main() {
	int m,n,k;
	cin>>m>>n>>k;
	int cnt=1;
	for(int i=0; i<k; i++) {
		stack s;
		for(int l=1; l<=n; l++) {
			cin>>value;
			int d=push(s,m,l);
			if(value==d)
				d=pop(s);//出栈，top--；
			else d=push(s,m,l); //入栈，top++，cnt++；
			if(d==-1) {
				cout<<"NO"<<endl;
				flag=1;
			} //元素用完,栈满

		}
		if(flag==0)cout<<"YES"<<endl;
	}
	return 0;
}
