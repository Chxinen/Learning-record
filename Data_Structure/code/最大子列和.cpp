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
//������Ŀ�������Կ�֪����Ϊ��ֵʱ��������Ϊ��ֵʱ����
//�ڱ���ȡ�ȵ���������ô����ʹ�õ����ֵ���ʱȡ��С�±� =>����ʵ�־ͻ�����
//��������˼·������ͷָ���βָ�룬Ȼ��䣬
//��������˼·�ٿ�ʼ�룬��������˷�ʱ�䡣�ǳ��򵥵�һ����������һ���� 
//�����ж�һ��Ҫ�������п����ԣ�����©�������������������ȥ
//�����簴���д���ʼmax����Ϊ0����Ϊsum����Ϊ0���ֲ�����sum>=max�� 
