#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#define LOOP 20


static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec - t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

typedef struct TreeNode
{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
}NODE;


NODE *node_setting(NODE *node,int arr[],int index)
{                                                                                                                                                                  
    if(index <sizeof(arr)) {
        if(arr[index]==0)
            return NULL;
        else {
            node = malloc(sizeof(NODE));
            node ->data = arr[index];
            node->left  = node_setting(node ->left,arr,index*2+1);
            node->right = node_setting(node ->right,arr,index*2+2);
            return node;
        }
    } else
        return NULL;
}



void flatten(NODE *node){
	NODE *p = (NODE *)malloc(sizeof(NODE));
	while(node!=NULL){
		if(node->left!=NULL){
			p=node->left;
			while(p->right!=NULL){
				  p=p->right;
			}
			p->right=node->right;
			node->right=node->left;
			node->left=NULL;

		}
		node=node->right;
	}

}



void print_tree(NODE *node)
{
    if ( !node ) return;
    printf( "%d\n", node->data );
    print_tree(node->right);
    print_tree(node->left);
}

int main()
{
	struct timespec start, end;
    double cpu_time;
    clock_gettime(CLOCK_REALTIME, &start);
    for (int j = 0; j < LOOP; j++) {

	int num[]= {1,2,5,3,4,0,6};
	NODE *root=NULL;
	root = node_setting(root,num,0);
	printf("before\n");
	print_tree(root);
    
    flatten(root);
	printf("affter\n");
	print_tree(root);
    }
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = (double) diff_in_second(start, end) / LOOP;

    FILE *fp;
    fp = fopen("time.dat", "a");
    assert(fp);

    fprintf(fp, "method\ttime\n");
    fprintf(fp, "iterative\t%.9lf\n", cpu_time);

    fclose(fp);

    printf("execution time : %lf sec\n", cpu_time);

    return 0;
}

