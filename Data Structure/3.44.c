#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// input functions
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

TreePtr buildTree(int preorder[], int postorder[], int preStart, int preEnd, int postStart, int postEnd) {
    if (preStart > preEnd) {
        return NULL;
    }

    // The first element in preorder is the root
    TreePtr root = create_node(preorder[preStart]);

    if (preStart == preEnd) {
        return root;
    }

    // Find the index of the left subtree root in postorder
    int leftRootVal = preorder[preStart + 1];
    int leftRootIndex = findIndex(postorder, postStart, postEnd, leftRootVal);

    // Calculate the size of the left subtree
    int leftSubtreeSize = leftRootIndex - postStart + 1;

    // Recursively build the left and right subtrees
    root->left = buildTree(preorder, postorder, preStart + 1, preStart + leftSubtreeSize, postStart, leftRootIndex);
    root->right = buildTree(preorder, postorder, preStart + leftSubtreeSize + 1, preEnd, leftRootIndex + 1, postEnd - 1);

    return root;
}

// output functions
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

    FILE *fin;
	fin = fopen("input5.txt", "r");
	if (fin == NULL) {
        printf("Failed to open input file.\n");
        exit(1);
    }

    int N;
	fscanf(fin,"%d ",&N);

    clock_t start = clock();
	for (int i=0; i<N; i++){
		int M;
		fscanf(fin,"%d",&M);
		
		int preorder[10003];
		for (int j=0; j<M; j++){
			fscanf(fin,"%d",&preorder[j]);
		}
		int postorder[10003];
		for (int j=0; j<M; j++){
			fscanf(fin,"%d",&postorder[j]);
		}

		TreePtr tree = buildTree(preorder,postorder,0, M - 1, 0, M - 1);
        int output[10003];
		int k=0;
		inorder(tree,output,&k);
		for (int j=0; j<k-1; j++){
			printf("%d ",output[j]);
		}
		printf("%d\n",output[k-1]);
		destroy_node(tree);
	}
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

	return 0;
}
