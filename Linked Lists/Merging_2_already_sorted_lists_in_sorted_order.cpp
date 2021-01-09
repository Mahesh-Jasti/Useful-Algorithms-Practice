#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}* head1, *head2, * final;

int ElementCount(struct Node* head){
	int count=0;
	struct Node* cur=head;
	while(cur!=NULL){
		count++;
		cur=cur->next;
	}
	return count;
}

void PrintList(struct Node* head){
	struct Node* cur=head;
	while(cur!=NULL){
		cout << cur->data << " ";
		cur=cur->next;
	}
	if(head!=NULL)cout << "\n";
}

struct Node* AddListEnd(struct Node* head, int x){
	if(head==NULL){
		head=(struct Node*)malloc(sizeof(struct Node));
		head->data=x;
		head->next=NULL;
		return head;
	}
	struct Node* cur=head;
	while((cur->next)!=NULL){
		cur=cur->next;
	}
	struct Node* temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=NULL;
	cur->next=temp;
	return head;
}

struct Node* AddListStart(struct Node* head, int x){
	if(head==NULL){
		head=(struct Node*)malloc(sizeof(struct Node));
		head->data=x;
		head->next=NULL;
		return head;
	}
	struct Node* temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=head;
	return temp;
}

struct Node* AddListMiddle(struct Node* head, int x, int pos){
	struct Node* cur=head;
	int count;
	count=ElementCount(head);
	if(pos<1){
		struct Node* newHead=AddListStart(head,x);
		return newHead;
	}
	else if(pos>=count){
		struct Node* newHead=AddListEnd(head,x);
		return newHead;
	}
	struct Node* i=head;
	struct Node* j;
	for(int k=2;k<=pos;k++)	i=i->next;
	j=i->next;
	struct Node* temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=j;
	i->next=temp;
	return head;
}

struct Node* DeleteListStart(struct Node* head){
	if(head==NULL){
		cout << "Invalid\n";
		return head;
	}
	struct Node* newHead=head->next;
	free(head);
	return newHead;
}

struct Node* DeleteListEnd(struct Node* head){
	if(head==NULL){
		cout << "Invalid\n";
		return head;
	}
	struct Node* i=head;
	struct Node* j;
	if(i->next==NULL){
		head=NULL;
		return head;
	}
	while(i->next!=NULL){
		j=i;
		i=i->next;
	}
	free(i);
	j->next=NULL;
	return head;
}

struct Node* DeleteListMiddle(struct Node* head, int pos){
	if(head==NULL){
		cout << "Invalid\n";
		return head;
	}
	struct Node* cur=head;
	int count;
	count=ElementCount(head);
	if(pos<=1){
		struct Node* newHead;
		newHead=DeleteListStart(head);
		return newHead;
	}
	else if(pos>=count){
		struct Node* newHead;
		newHead=DeleteListEnd(head);
		return newHead;
	}
	struct Node* i=head->next;
	struct Node* j=head;
	struct Node* k=head->next->next;
	for(int l=2;l<pos;l++){
		j=j->next;
		i=i->next;
		k=k->next;
	}
	j->next=k;
	free(i);
	return head;
}

struct Node* Deletion(struct Node* head){
	if(head==NULL) return head;
	while(head!=NULL){
		head=DeleteListStart(head);
	}
	return head;
}

struct Node* ReverseList(struct Node* head){
	if(head==NULL || head->next==NULL) return head;
	struct Node* HEAD=NULL,* newHead;
	while(head){
		newHead=head->next;
		head->next=HEAD;
		HEAD=head;
		head=newHead;
	}
	return HEAD;
}

int main() {
	head1=NULL;
	head2=NULL;
	final=NULL;
	// your code goes here
	while(1){
		int x;
		cin >> x;
		if(x==-1) break;
		head1=AddListEnd(head1,x);
	}
	while(1){
		int x;
		cin >> x;
		if(x==-1) break;
		head2=AddListEnd(head2,x);
	}
	bool flag;
	while(head1!=NULL && head2!=NULL){
		if(head1->data>=head2->data){
			final=AddListEnd(final,head2->data);
			head2=head2->next;
		}
		else if(head2->data>head1->data){
			final=AddListEnd(final,head1->data);
			head1=head1->next;
		}
		if(head2==NULL) flag=false;
		else if(head1==NULL) flag=true;
	}
	if(flag){
		while(head2){
			final=AddListEnd(final,head2->data);
			head2=head2->next;
		}
	}
	else{
		while(head1){
			final=AddListEnd(final,head1->data);
			head1=head1->next;
		}
	}
	PrintList(final);
	return 0;
}