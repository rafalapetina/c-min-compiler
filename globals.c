#include "globals.h"

int paramCounter(TreeNode *t){
	int tmp = 0;
	/* Selects the left child (list of parameters/arguments) */
	t = t->child[0];
	while(t != NULL){
		tmp++;
		t = t->sibling;
	}
	return tmp;
}