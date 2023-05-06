#include<bits/stdc++.h>
using namespace std;
typedef struct node* List;
struct node {
	int address,data,next;
	List Next;
};
List head1;
int Length(List l) {
	cout<<"Length";
	List p=l;
	int length=1;
	while(l->Next->next!=-1) {
		cout<<"Length";
		length++;
		l=l->Next;
	}
	cout<<"Length";
	return length;
}
void create_list(List l1,int k) {
	head1=l1;
	
//	q=(List)malloc(sizeof(struct node));
	int add,num,n;

//	cout<<"create_list";
}
void output(List l,int cnt1,int cnt2,int k) {
	cout<<"output";
	List p=l;
	for(int i=0; i<cnt2; i++) p=p->Next;
	for(int i=0; i<cnt1-1; i++) {
		for(int j=0; j<(cnt1-i-1)*k+1; j++) p=p->Next;
		for(int m=0; m<k; m++) {
			cout<<p->next<<" "<<p->data<<" "<<p->address<<endl;
			p=p->Next;
		}
		p=l;
		for(int i=0; i<cnt2; i++) p=p->Next;
	}
	return;
}
int main() {
	List l1,l2;
	head1=l1;
	int add,num,k,n,m;
	cin>>add>>num>>k;
	while(num--) {
		List p=(List)malloc(sizeof(struct node));
		cin>>add>>m>>n;
//		q->address=n;
//		q->data=num;
//		q->next=add;
		p->address=add;
		p->data=m;
		p->next=n;	
			
		l1=p; 
//		cout<<l1->data<<endl;
		l1=l1->Next;
//		q=q->Next;
//		q=(List)malloc(sizeof(struct node));	
	}	
	l1->Next=NULL;
	cout<<head1->Next->data;//√ª”√ 
	int length=Length(l1);
	int cnt1=length/k;
	int cnt2=length%k;
	output(l2,cnt1,cnt2,k);
	return 0;
}
