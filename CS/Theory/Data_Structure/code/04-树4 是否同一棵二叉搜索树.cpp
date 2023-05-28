#include<iostream>
using namespace std;
typedef struct node* Tree;
struct node {
	int data;
	Tree left=NULL,right=NULL;
};
Tree create(Tree root,int item) {
	if(root==NULL) {
		root=new struct node;
		root->data=item;
		root->left=root->right=NULL;
	} else {
		if(item>root->data) root->right=create(root->right,item);
		if(item<root->data) root->left=create(root->left,item);
	}
	return root;
	
}
int check(Tree root1,Tree root2) {
	if(root1==NULL&&root2==NULL){
		return 1;
	}
	if(root1->data==root2->data) {
		return check(root1->left,root2->left)&&check(root1->right,root2->right);
	} else return 0;
}
int main() {
	int n,l,m;
	while(scanf("%d",&n)) {
		if(n==0) break;
		else cin>>l;
		Tree root1=NULL;
		for(int i=0; i<n; i++) {
			cin>>m;
			root1=create(root1,m);
		}
		while(l--) {
			Tree root=NULL;
			for(int i=0; i<n; i++) {
				cin>>m;
				root=create(root,m);
			}
			if(check(root1,root)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}
//ÅÐ¶ÏÊ÷ÊÇ·ñÏàµÈ£¬¹¹Ôì¶þ²æËÑË÷Ê÷£¬µÝ¹é 
