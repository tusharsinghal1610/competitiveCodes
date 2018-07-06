#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node * pushNode(node *root,int data){
	node *temp=new node;
	temp->data=data;
	temp->next=NULL;
	if(root == NULL){
		root=temp;
		return root;
	}
	node *last,*temp1=root;
	while(temp1!=NULL){
		last=temp1;
	    temp1=temp1->next;
	}
	last->next = temp;
	return root;
}
void traverse(node *root){
	while(root){
		cout<<root->data;
		cout<<"\n";
		root=root->next;
	}
}
node * reverse(node* head){
	if(head == NULL){
		return head;
	}
	node *ahead,* temp = head;
	node * previous = NULL;
	while(temp->next!=NULL){
		ahead=temp->next;
		temp->next=previous;
		previous=temp;
		temp=ahead;
	}
	temp->next=previous;
	return temp;
}
node * reverseKsteps(node *head,int k){
	if(head == NULL){
		return NULL;
	}
	int count =0;
	node *ahead,*temp = head;
	node *previous = NULL;
	while(temp != NULL && count <k){
		ahead=temp->next;
		temp->next=previous;
		previous=temp;
		temp=ahead;
		count++;
	}
	head->next = reverseKsteps(temp,k);
	return previous;
}
node * iterativeRev(node *root,int k){
	int count=0;
	node *temp=root;
	while(root!=NULL){
		count++;
		root=root->next;
	}
	root=temp;
	node **a=new node*[count];
	int i=0;
	while(temp!=NULL){
		a[i]=temp;
		temp=temp->next;
		i++;
	}
/*	for(i=0;i<count;i++){
		cout<<a[i]->data<<endl;
	}*/
	i=0;
	while(i<count){
		int j=k-1;
		while(j>0){
			cout<<count<<i<<j<<endl;
			if(i+j>=count){
				j--;
				continue;
			}
			a[i+j]->next= a[i+j-1];
			j--;
		}
		if(i+2*k-1<count){
			a[i]->next=a[i+2*k-1];
		}
		else if(i+k<count){
			a[i]->next=a[count-1];
		}
		else{
			a[i]->next=NULL;
		}
		i=i+k;
	}
	
	return a[k-1];
	
}
int main(){
	
	node *root=NULL;
	root=pushNode(root,1);
	root=pushNode(root,2);
	root=pushNode(root,3);
	root=pushNode(root,4);
	root=pushNode(root,5);
	root=pushNode(root,6);
	root=pushNode(root,7);
	root=pushNode(root,8);
	root = pushNode(root,9);
	root = pushNode(root,10);
	traverse(root);
	cout<<"\n---------------------reversing----------------\n";
	root = iterativeRev(root,5);
	traverse(root);
	return 0;
}
