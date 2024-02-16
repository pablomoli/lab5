//Pablo Molina
//02/09/2024
// Lab Friday 3:30pm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node *tmp = head;
	int c = 0;
	while (tmp != NULL)
	{
		c++;
		tmp = tmp->next;
	}
	return c;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node *tmp = head;
	if (tmp == NULL){
		return NULL;
	}
	int len = length(head);
	char *str = malloc(len+1);
	
	for (int i = 0; i < len; i++)
	{
		str[i] = tmp->letter;
		tmp = tmp->next;
	}
	str[len] = '\0';
	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node *new = (node *)malloc(sizeof(node));
	if (new == NULL)
        exit(1);
    new->letter = c;
    new->next = NULL;

	node* tmp = *pHead;
	if(tmp == NULL){
		*pHead = new;
		return;
	}

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	while(*pHead != NULL) {
        node *tmp = *pHead;
        *pHead =  tmp->next;
        free(tmp);
    }
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}