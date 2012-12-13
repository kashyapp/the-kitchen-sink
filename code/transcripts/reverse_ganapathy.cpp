//recursive
//
	
//first trial right!!!
void reverse(node **head){
	node* first;
	node* next;
	if(*head == NULL)
		return;
	first = *head;
	next = first->next;
	if(next == NULL)
		return;
	reverse(&next);
	first->next->next = first;
	first->next = NULL;
	*head = next;
}


