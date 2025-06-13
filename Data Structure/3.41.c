#include <stdio.h>
#include <stdlib.h>

/* Number of Rotation in AVL Tree Construction */

typedef struct AvlTree* avl;

struct AvlTree {
	int element;
	int height;
	avl left;
	avl right;
};


int height (avl t){
	// from the leaf calculate the height.
	if (t == NULL)
		return -1;
	else {
		int left_height = height(t->left);
		int right_height = height(t->right);
		if (left_height > right_height){
			return left_height+1;
		}
		else {
			return right_height+1;
		}
	}	
}


avl create_node(int value){
	avl tree = (avl)malloc(sizeof(struct AvlTree));
	tree->element = value;
	tree->height = 0;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}

avl Make_null (avl t){
	if (t != NULL){
		Make_null(t->left);
		Make_null(t->right);
		free (t);
	}
	return NULL;
}

avl Find_min(avl t){
	avl tree;
	if (t->left!=NULL){
		tree = Find_min(t->left);
	} 
	else 
		tree = t;
	return tree;
}

avl Find_max(avl t){
	avl tree;
	if (t->right!=NULL){
		tree = Find_max(t->right);
	}
	else 
		tree = t;
	return tree;
}

// Deal with rotations in the insertion and deletion
int max(int a,int b){
	if (a>b)
		return a;
	else
		return b;
}

avl left_rotation(avl x){
	avl y = x->right;
	x->right = y->left;
	y->left = x; //finish swap pointers

	//Update heights of x,y
	x->height = max(height(x->left),height(x->right))+1;
	y->height = max(x->height,height(y->right))+1;
	
	return y;
}


avl right_rotation(avl x){
	avl y = x->left;
	x->left = y->right;
	y->right = x; //finish swap pointers

	//Update heights of x,y
	x->height = max(height(x->left),height(x->right))+1;
	y->height = max(x->height,height(y->left))+1;
	
	return y;
}

// double rotation implementation

avl left_right_rotation(avl x){
	x->left = left_rotation(x->left);
	// step1: left rotation to the left child
	return right_rotation(x);
	// step2: right rotation
}


avl right_left_rotation(avl x){
	x->right = right_rotation(x->right);
	// step1: right rotation to the right child
	return left_rotation(x);
	// step2: left rotation
}

avl insert(int value,avl t,int* num){
	// we cannot determine the change of height before the insertion is done
	if (t==NULL){
		t = create_node(value);
	}
	else if (value < t->element){
		t->left = insert(value,t->left,num);
		if ( height(t->left)-height(t->right) == 2 ){ //need rotation
			if (value < t->left->element){
				t = right_rotation(t);
				(*num)++;
			}
			else{ 
				t = left_right_rotation(t);
				*num += 2;
			}
		}
	}
	else if (value > t->element){
		t->right =  insert(value,t->right,num);
		if ( height(t->right) - height(t->left) == 2){
			if (value > t->right->element){
				t = left_rotation(t);
				(*num)++;
			}
			else{
				t = right_left_rotation(t);	
				*num += 2;
			} 
		}
	}
	// update height
	t->height = max(height(t->left),height(t->right)) + 1;
	return t; // we return the root of the tree
}
// When using AVL insert function,we must 
// assign the output of to t since the root may change after insertion

int main(){
	int N;
	scanf("%d ",&N);
	for (int i=0; i<N; i++){
		int M;
		scanf("%d",&M);
		int rotation_num = 0;
		avl tree = NULL;
		int* arr = (int*)malloc(M * sizeof(int));
		for (int j=0; j<M; j++){
			scanf("%d",&arr[j]);
			tree = insert(arr[j], tree, &rotation_num);
		}
		printf("%d\n",rotation_num);
   		tree = Make_null(tree);	// useful in the end.
	}
	return 0;
}

