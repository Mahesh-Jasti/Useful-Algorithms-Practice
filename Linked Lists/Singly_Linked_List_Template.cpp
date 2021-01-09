#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}* head;

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

int main() {
	// your code goes here
	head=NULL;
	while(1){
	    int type;
	    cin >> type;
	    if(type==1){ /// Addition of numbers to list at the END
	        int n;
	        cin >> n;
	        cout << "Linked List after elements are Added at the End is printed\n";
	        if(!n){
	            PrintList(head);
	            continue;
	        }
	        for(int i=0;i<n;i++){
	        	int x;
	        	cin >> x;
	        	head=AddListEnd(head,x);
	        }
	        PrintList(head);
	    }
	    else if(type==2){ /// Addition of numbers to list at the START
	        int n;
	        cin >> n;
	        cout << "Linked List after elements are Added at the Beginning is printed\n";
	        if(!n){
	            PrintList(head);
	            continue;
	        }
	        for(int i=0;i<n;i++){
	        	int x;
	        	cin >> x;
	        	head=AddListStart(head,x);
	        }
	        PrintList(head);
	    }
	    else if(type==3){ /// Addition of numbers to list at the MIDDLE
	        int n;
	        cin >> n;
	        cout << "Linked List after elements are Added for Each Query is printed\n";
	        if(!n){
	            PrintList(head);
	            continue;
	        }
	        for(int i=0;i<n;i++){
	        	int x;
	        	int pos;
	        	cin >> pos >> x;
	        	head=AddListMiddle(head,x,pos);
	        	PrintList(head);
	        }
	    }
	    else if(type==4){ /// Deletion of numbers in the list at the BEGINNING
	        int n;
	        cin >> n;
	        cout << "Linked List after deletion of Elements\n";
	        if(!n){
	            PrintList(head);
	            continue;
	        }
	        for(int i=0;i<n;i++){
	        	head=DeleteListStart(head);
	        	PrintList(head);
	        }
	    }
	    else if(type==5){ /// Deletion of numbers in the list at the END
	        int n;
	        cin >> n;
	        cout << "Linked List after deletion of Elements\n";
	        if(!n){
	            PrintList(head);
	            continue;
	        }
	        for(int i=0;i<n;i++){
	        	head=DeleteListEnd(head);
	        	PrintList(head);
	        }
	    }
	    else if(type==6){ /// Deletion of numbers in the list at the MIDDLE
	        int n;
	        cin >> n;
	        cout << "Linked List after deletion of Elements\n";
	        if(!n){
	            PrintList(head);
	            continue;
	        }
	        for(int i=0;i<n;i++){
	        	int pos;
	        	cin >> pos;
	        	head=DeleteListMiddle(head,pos);
	        	PrintList(head);
	        }
	    }
	    else if(type==7){ /// Deletion of the whole Linked List
	    	head=Deletion(head);
	    	cout << "Linked List Deleted\n";
	    }
	    else if(type==8){ /// Count of no. of elements in Linked list
	    	int count=ElementCount(head);
	    	cout << "Linked List Size : " << count << "\n"; 
	    }
	    else if(type==-1) return 0;
	}
	return 0;
}