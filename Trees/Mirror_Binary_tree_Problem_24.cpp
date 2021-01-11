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

void PrintLevelOrder(struct BinaryTreeNode* root){
	/// Globally declared QUEUE will be used here ///
	struct BinaryTreeNode* temp;
	queue<struct BinaryTreeNode* > q;
	if(!root) return;
	q.push(root);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
		cout << temp->data << " ";
	}
	cout << "\n";
	return;
}

int BinaryTreeSize(struct BinaryTreeNode* root){
	if(!root) return 0;
	return BinaryTreeSize(root->left) + 1 + BinaryTreeSize(root->right);
}

int BinaryTreeHeight(struct BinaryTreeNode* root){
	int left=0,right=0;
	if(!root) return 0;
	left=BinaryTreeHeight(root->left)+1;
	right=BinaryTreeHeight(root->right)+1;
	if(left>right) return left;
	else return right;
}

void LeafNodesCount(struct BinaryTreeNode* root, int* count){
	if(!root) return;
	if(!root->left && !root->right){ 
	    *count+=1;
	    return;
	}
	if(root->left) LeafNodesCount(root->left,count);
	if(root->right) LeafNodesCount(root->right,count); 
}

void RootToLeafPaths(struct BinaryTreeNode* root, vector<int> v){
	if(!root) return;
	v.push_back(root->data);
	if(!root->left && !root->right){
		for(int i=0;i<v.size();i++){
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	RootToLeafPaths(root->left,v);
	RootToLeafPaths(root->right,v);
}

struct BinaryTreeNode* MirrorBinaryTree(struct BinaryTreeNode* root){
	struct BinaryTreeNode* temp;
	if(root){
		MirrorBinaryTree(root->left);
		MirrorBinaryTree(root->right);
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
	return root;
}

int main(){
	// CODE goes here

	// SAMPLE INPUT
	//	6
	//	4 2 5 1 6 3 
	//	1 2 4 5 3 6

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
	root=MirrorBinaryTree(root);
	PrintPreOrder(root);
	cout << "\n";
	PrintInOrder(root);
	cout << "\n";
	PrintPostOrder(root);
	cout << "\n";
	PrintLevelOrder(root);
	cout << "\n";
	return 0;
}

