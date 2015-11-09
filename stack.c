#include<assert.h>
#include<malloc.h>
#include"stack.h"
int is_empty_1();
Data top_1();
Data pop_1();
void push_1(Data value);
void destroy_stack_1();


int is_empty_2();
Data top_2();
Data  pop_2();
void push_2(Data);
void destroy_stack_2();

static Stack * TopNode_1;
static Stack * TopNode_2;

void push_1(Data value)
{
	Stack *new_node;

	new_node=malloc(sizeof(Stack));
	assert(new_node!=NULL);
	new_node->value=value;
	new_node->next=TopNode_1;
	TopNode_1=new_node;
}

Data  pop_1()
{
	Stack * first_node;

    assert (!is_empty_1());
	first_node = TopNode_1;
	Data value = first_node->value;
	TopNode_1=first_node->next;
	free(first_node);
	return value;
}
Data top_1()
{
	assert (!is_empty_1());
	return TopNode_1->value;
}
int is_empty_1()
{
	return TopNode_1==NULL;
}

void destroy_stack_1()
{
	while(!is_empty_1()) pop_1();
}

void push_2(Data value)
{
	Stack *new_node;

	new_node=malloc(sizeof(Stack));
	assert(new_node!=NULL);
	new_node->value=value;
	new_node->next=TopNode_2;
	TopNode_2=new_node;
}

Data  pop_2()
{
	Stack * first_node;
    assert (!is_empty_2());
	first_node = TopNode_2;
	Data value = first_node->value;
	TopNode_2=first_node->next;
	free(first_node);
	return value;
}
Data top_2()
{
	assert (!is_empty_2());
	return TopNode_2->value;
}
int is_empty_2()
{
	return TopNode_2==NULL;
}

void destroy_stack_2()
{
	while(!is_empty_2())	pop_2();
}
