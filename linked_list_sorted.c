#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	struct node *next;
	struct node *prev;
	int data;
}listNode;

typedef struct list
{
	listNode *head;
	int count;
}link_list;

static listNode *
listnode_new(void)
{
       	listNode *node;
	node = malloc(sizeof (listNode));
       	return node;
}

static listNode *
listnode_add(link_list *_list, int val)
{
	listNode *node;
	listNode *n;
	int temp = 0;

	node = listnode_new();
	node->data = val;

	if (_list->count == 0)
	{
		_list->head = node;
		_list->count++;
		return node;
	}
	
	for(n = _list->head; n; n->next)
	{
		if((val>temp) && (val<=n->data))
		{
			if (! n->prev){
				node->next = _list->head;
				_list->head->prev = node;
				_list->head = node;
				_list->count++;
				return node;
			}
			else{
				n->prev->next = node;
				node->prev = n->prev;
				node->next = n;
				n->prev = node;
				_list->count++;
				return node;
			}
		}
		else if(n->next == NULL)
		{	
			n->next = node;
			node->prev = n;
			_list->count++;
			return node;
		}
		else
		{
			temp = n->data;
			n = n->next;
		}	
	}
}

void print_list(link_list *list){
	listNode *current = list->head;
	while(current != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
}

void main()
{
	link_list test_list;
	
	test_list.count = 0;
        test_list.head = NULL;

	listnode_add(&test_list, 3);
	listnode_add(&test_list, 2);
        listnode_add(&test_list, 5);
        listnode_add(&test_list, 5);
 	listnode_add(&test_list, 8);
	listnode_add(&test_list, 3);
        listnode_add(&test_list, 1);
        listnode_add(&test_list, 2);

	printf("Head value = %d\n", test_list.head->data);
	printf("Count = %d\n",  test_list.count);
	print_list(&test_list);
}

