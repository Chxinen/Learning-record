#include<iostream>
using namespace std;
int arr[100001];
int main() {
	int k;
	cin>>k;
	int sum=0,max=-1,tempfirst=0,templast=0,first=0,last=0,flag=0,cnt=0;
	for(int i=0; i<k; i++) {
		cin>>arr[i];
        if(arr[i]<0) cnt++;
		sum+=arr[i];
		if(sum>=0){
			if(flag==0){
				tempfirst=i;
				flag=1;
			}
			templast=i;			
		}
		if(sum<0) {
			sum=0;
			flag=0;
		} else if(sum>max) {			
			first=tempfirst;
			last=templast;
			max=sum;
		} 
	}	
    if(cnt==k) cout<<"0 "<<arr[0]<<" "<<arr[k-1];
	else cout<<max<<" "<<arr[first]<<" "<<arr[last];
	return 0;
}
//根据题目自身特性可知，和为负值时就舍弃，为正值时保留
//在必须取等的条件下怎么才能使得当最大值相等时取最小下标 =>不好实现就换方向啊
//最清晰的思路就是找头指针和尾指针，然后变，
//有完整的思路再开始码，否则就是浪费时间。非常简单的一个东西搞了一上午 
//条件判断一定要考虑所有可能性，不能漏掉，否则特殊情况过不去
//（比如按这个写法最开始max不能为0，因为sum可能为0，又不能让sum>=max） 
