#include<bits/stdc++.h>
using namespace std;
struct Node{
	int address,data,next;
}node[100000];
void output(List l,int k)
{
	for(int i=0;i<k;i++)l=l->Next;
    List p=l;
    for(int i=0;i<k;i++){
    	p=p->Last;
        cout<<p->address<<" "<<p->data<<" "<<p->next<<endl;
    } 
    while(l->Next!=NULL){ 
   		cout<<l->address<<" "<<l->data<<" "<<l->next<<endl;	
		l=l->Next;
	} 
	return; 
}
int main()
{
	List l;
	int head,add,num,k,nexth;
	cin>>head>>num>>k;
	int cnt=num/k;
	for(int i=0;i<k;i++){
		cin>>add>>num>>nexth;
		node[add].data=num;
		node[add].next=nexth;
	}
	
	l=create_list(l,num);
	output(l,k);
	return 0;
}
