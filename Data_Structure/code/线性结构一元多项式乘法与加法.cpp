#include<iostream>
using namespace std;
struct node1 {
	int m,n;
} no1[1001];
struct node2 {
	int m,n;
} no2[1001];
int node3[5000]= {0};
int main() {
	int a,b,ca=0,cb=0;
	cin>>a;
	for(int i=0; i<a; i++) {
		cin>>no1[i].m>>no1[i].n;
		if(no1[i].m==no1[i].n&&no1[i].m==0)ca++;
	}
	cin>>b;
	for(int i=0; i<b; i++) {
		cin>>no2[i].m>>no2[i].n;
		if(no2[i].m==no2[i].n&&no2[i].m==0) cb++;
	}
	if(ca==a||cb==b) cout<<"0 0";
	else {
		int cnt=0,max=0,count1=0,count=0;
		for(int j=0; j<b; j++) {
			for(int i=0; i<a; i++) {
				cnt=no1[i].n+no2[j].n;
				if(node3[cnt]==0) {
					count++;
					node3[cnt]=no1[i].m*no2[j].m;
				} else node3[cnt]+=no1[i].m*no2[j].m;
				if(node3[cnt]==0) {
					count1++;
				}
				if(cnt>max) max=cnt;
			}
		}
		int flag=0;
		if(count==count1)cout<<"0 0";
		while(count-count1) {
			if(node3[max]) {
				if(flag==0) {
					cout<<node3[max]<<" "<<max;
					flag++;
				} else {
					cout<<" "<<node3[max]<<" "<<max;
				}
				count--;
			}
			max--;
		}
	}
//	if(count1) {
//		if(flag)
//			cout<<" 0 0";
//		else{
//			cout<<"0 0";
//			flag++;
//		}
//	}
	cout<<endl;


	int count2=0,cnt=0,cnt1=0,cnt2=0,flag=0;
	while(1) {
		if(cnt1==a||cnt2==b)break;
		if((cnt1||cnt2)&&flag==1)cout<<" ";
		if(no1[cnt1].n==no2[cnt2].n) {
			if(no1[cnt1].m+no2[cnt2].m==0&&no1[cnt1].n==0) {
				count2++;
			} else {
				cout<<no1[cnt1].m+no2[cnt2].m<<" "<<no1[cnt1].n;
				flag=1;
			}
			cnt1++;
			cnt2++;
			cnt++;
		} else if(no1[cnt1].n>no2[cnt2].n) {			
			if(no1[cnt1].m==0&&no1[cnt1].n==0) {
				count2++;
			} else {
				cout<<no1[cnt1].m<<" "<<no1[cnt1].n;
				flag=1;
			}
			cnt1++;
			cnt++;
		} else {			
			if(no2[cnt2].m==0&&no2[cnt2].n==0) {
				count2++;
			} else {
				cout<<no2[cnt2].m<<" "<<no2[cnt2].n;
				flag=1;				
			}
			cnt2++;
			cnt++;
		}

	}
	if(count2==cnt) cout<<"0 0";
	else {
		if(cnt1==a&&cnt2<b) {
			for(int i=cnt2; i<b; i++)
				if(no2[i].m==0&&no2[i].n==0)continue;
				else {
					cout<<" ";
					cout<<no2[i].m<<" "<<no2[i].n;
				}
		} else if(cnt1<a&&cnt2==b) {
			for(int i=cnt1; i<a; i++)
				if(no1[i].m==0&&no1[i].n==0) continue;
				else{
					cout<<" ";
					cout<<no1[i].m<<" "<<no1[i].n;
				}
		}
	}
	return 0;
}


//零多项式：系数全为0的多项式
