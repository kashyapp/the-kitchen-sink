struct node{
	struct node * left;
	struct node * right;
	int val;
};

void traverse(node * p){
	vector<node> stack;
	while(p!= NULL){
		while(p!=NULL){
			if(p->right !=NULL){
				push(p->right);
			}
			push(p);
			p = p->left;
		}
		p = pop();
		while(stack.is_not_empty && p->right == NULL){
			print p;
			p = pop();
		}
		print p;
		if(stack.is_not_empty)
			root = pop();
	}
}
