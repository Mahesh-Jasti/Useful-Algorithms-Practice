#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode{
	int data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}* root;

struct BinaryTreeNode* BuildBinaryTree(int inOrder[], int preOrder[], int inOrderStart, int inOrderEnd, int n){
	static int preOrderIndex=0;
	struct BinaryTreeNode* newNode;
	if(inOrderStart>inOrderEnd){
		return NULL;
	}
	newNode=(struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
	if(!newNode){
		return NULL;
	}
	newNode->data=preOrder[preOrderIndex];
	preOrderIndex++;
	if(inOrderStart==inOrderEnd){
		return newNode;
	}
	int inOrderIndex;
	for(int i=0;i<n;i++){
		if(newNode->data==inOrder[i]){
			inOrderIndex=i;
			break;
		}
	}
	newNode->left=BuildBinaryTree(inOrder,preOrder,inOrderStart,inOrderIndex-1,n);
	newNode->right=BuildBinaryTree(inOrder,preOrder,inOrderIndex+1,inOrderEnd,n);
	return newNode;
}

void PrintInOrder(struct BinaryTreeNode* root){
	if(root){
		PrintInOrder(root->left);
		cout << root->data << " ";
		PrintInOrder(root->right);
	}
	else return;
}

void PrintPreOrder(struct BinaryTreeNode* root){
	if(root){
		cout << root->data << " ";
		PrintPreOrder(root->left);
		PrintPreOrder(root->right);
	}
	else return;
}

void PrintPostOrder(struct BinaryTreeNode* root){
	if(root){
		PrintPostOrder(root->left);
		PrintPostOrder(root->right);
		cout << root->data << " ";
	}
	else return;
}

void MaxElement(struct BinaryTreeNode* root, int *max){
	if(root){
		if(root->data>*max) *max=root->data;
		MaxElement(root->left,max);
		MaxElement(root->right,max);
	}
	else return;
}

int main(){
	// CODE goes here
	root=NULL;
	int n;
	cin >> n;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
	}
	root=BuildBinaryTree(a,b,0,n-1,n);
    int max=INT_MIN;
    MaxElement(root, &max);
    cout << max << "\n";
	return 0;
}

