#include<bits/stdc++.h>
using namespace std;
typedef struct node *point;
int arr[2005];
struct node {
	int d1,d2;
	point next=NULL;
};
void multiply(point p1,point p2) {
	int max=0,flag=0;
	point head1=p1;
	while(p2->next!=NULL) {
	//why not p2!=NULL =>when i create the list,i add one more space before null
		while(p1->next!=NULL) {
			arr[p1->d2+p2->d2]+=p1->d1*p2->d1;
			if(p1->d2+p2->d2>max) max=p1->d2+p2->d2;
			p1=p1->next;	
		}
		p2=p2->next;
		p1=head1;
	}
	for(int i=max;i>=0;i--){
		if(arr[i]) {
			if(flag==1)cout<<" "<<arr[i]<<" "<<i;
			else {
				cout<<arr[i]<<" "<<i;
				flag=1;
			}
		}
	}
	if(flag==0) cout<<"0 0";
	return;
}
void add(point p1,point p2) {
	int flag=0;
	while(p1->next!=NULL&&p2->next!=NULL) {
		if(p1->d2==p2->d2) {
			if(p1->d1+p2->d1) {
				if(flag==1)cout<<" "<<p1->d1+p2->d1<<" "<<p1->d2;
				else {
					cout<<p1->d1+p2->d1<<" "<<p1->d2;
					flag=1;
				}
			}
			p1=p1->next;
			p2=p2->next;
		} else if(p1->d2>p2->d2) {
			if(p1->d1)
				if(flag==1)cout<<" "<<p1->d1<<" "<<p1->d2;
				else {
					cout<<p1->d1<<" "<<p1->d2;
					flag=1;
				}
			p1=p1->next;
		} else {
			if(p2->d1)
				if(flag==1)cout<<" "<<p2->d1<<" "<<p2->d2;
				else {
					cout<<p2->d1<<" "<<p2->d2;
					flag=1;
				}
			p2=p2->next;
		}
	}
	if(p1->next!=NULL) {
		while(p1->next!=NULL) {
			if(p1->d1) {
				if(flag==1)cout<<" "<<p1->d1<<" "<<p1->d2;
				else {
					cout<<p1->d1<<" "<<p1->d2;
					flag=1;
				}
			}
			p1=p1->next;
		}
	} else {
		while(p2->next!=NULL) {
			if(p2->d1) {
				if(flag==1)cout<<" "<<p2->d1<<" "<<p2->d2;
				else {
					cout<<p2->d1<<" "<<p2->d2;
					flag=1;
				}
			}
			p2=p2->next;
		}
	}
	if(flag==0) cout<<"0 0";
	return;
}
point create(int n,point p) {
	p=new struct node;
	point head=p;
	int i,j;
	while(n--) {
		cin>>i>>j;
		p->d1=i;
		p->d2=j;
		p->next=new struct node;
		p=p->next;		
	}
	p=NULL;//not p->next=null
	return head;
}
int main() {
	int n,m;
	point p1,p2,head1,head2;
	cin>>n;
	head1=create(n,p1);
	cin>>m;
	head2=create(m,p2);
	multiply(head1,head2);
	cout<<endl;
	add(head1,head2);
	return 0;
}
//零多项式：系数全为0的多项式
