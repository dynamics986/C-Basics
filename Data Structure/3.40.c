#include <stdio.h>
#include <stdlib.h>

/* In-order Traversal of a Binary Tree */

typedef struct TreeNode* TreePtr; //pointer to a treenode

struct TreeNode{
	int element;
	TreePtr left;
	TreePtr right;
};

TreePtr create_node (int element){
	TreePtr new_node = (TreePtr)malloc(sizeof(struct TreeNode));
	new_node->element = element;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

// Breadth first insert
TreePtr bfi(int M,int arr[]){

	if (M == 0) return NULL; // If the array is empty, return NULL

	TreePtr root = create_node(arr[0]); // The first element is the root
	TreePtr* queue = (TreePtr*)malloc(M * sizeof(TreePtr)); // Queue for level order
	int front = 0, rear = 0;

	// Enqueue the root
	queue[rear++] = root;

	for (int i = 1; i < M; i++){
		TreePtr current = queue[front++]; // Dequeue the front node

		// Insert left child
		current->left = create_node(arr[i]);
		queue[rear++] = current->left; // Enqueue left child
	
		// Check i and enqueue the right child
		if (++i < M){
			current->right = create_node(arr[i]);
			queue[rear++] = current->right; // Enqueue right child
		}
		// printf("i=%d\n",i);
		// if (i==8){
		// 	for (int j=front;j<=rear;j++)
		// 	printf("queue[%d]=%d\n",j,queue[j]->element);
		// }
	}

	free(queue); // Free the queue memory
	return root; // Return the root of the constructed tree
}

void print_node(TreePtr t,int* output, int* k){
	if (t->element != 0){
		output[*k] = t->element;
		(*k)++;
	}
}

void inorder(TreePtr tree,int* output, int* k){
	if (tree!=NULL){
		inorder(tree->left,output,k);
		print_node(tree,output,k);
		inorder(tree->right,output,k);
	}
}

void destroy_node(TreePtr node){
	if (node != NULL){
		destroy_node(node->left);
		destroy_node(node->right);
		free(node);
	}
}

int main(){

    int N;
	scanf("%d ",&N);
	for (int i=0; i<N; i++){
		int M;
		scanf("%d",&M);
		int output[10000];
		int k=0;
		TreePtr tree;
		int arr[10003];
		for (int j=0; j<M; j++){
			scanf("%d",&arr[j]);
		}
		tree = bfi(M,arr);
		inorder(tree,output,&k);
		for (int j=0; j<k-1; j++){
			printf("%d ",output[j]);
		}
		printf("%d\n",output[k-1]);
		destroy_node(tree);
	}

	return 0;
}
