#include "stack.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

int is_empty_1();
STACK_TYPE pop_1();
void push_1(STACK_TYPE value);
void destroy_stack_1();


int is_empty_2();
STACK_TYPE  pop_2();
void push_2(STACK_TYPE);
void destroy_stack_2();

static Stack * ToeNode_1;
static Stack * TopNode_2;

void push_1(STACK_TYPE value)
{
	Stack *new_node;

	new_node=malloc(sizeof(Stack));
	assert(new_node!=NULL);
	new_node->value=value;
	new_node->next=ToeNode_1;
	ToeNode_1=new_node;
}

STACK_TYPE  pop_1()
{
	Stack * first_node;

    assert (!is_empty_1());
	first_node = ToeNode_1;
	STACK_TYPE value = first_node->value;
	ToeNode_1=first_node->next;
	free(first_node);
	return value;
}

int is_empty_1()
{
	return ToeNode_1==NULL;
}

void destroy_stack_1()
{
	while(!is_empty_1()) pop_1();
}

void push_2(STACK_TYPE value)
{
	Stack *new_node;

	new_node=malloc(sizeof(Stack));
	assert(new_node!=NULL);
	new_node->value=value;
	new_node->next=TopNode_2;
	TopNode_2=new_node;
}

STACK_TYPE  pop_2()
{
	Stack * first_node;

    assert (!is_empty_2());
	first_node = TopNode_2;
	STACK_TYPE value = first_node->value;
	TopNode_2=first_node->next;
	free(first_node);
	return value;
}

int is_empty_2()
{
	return TopNode_2==NULL;
}

void destroy_stack_2()
{
	while(!is_empty_2())	pop_2();
}
