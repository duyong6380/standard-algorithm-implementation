

typedef struct node
{
	int data;
	struct node *lchild,*rchild;
}BST;


BST* BSTree(BST *s , int k)
{
	if(s == NULL) return NULL;
	if(s->data = k) return s;
	else if(s->data > k) return BSTree(s->lchild,k);
	else return BSTree(s->rchild,k);
}

int main()
{

}
