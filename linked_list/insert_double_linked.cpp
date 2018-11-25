// insertion operations

#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
	struct NODE *prev;
	int info;
	struct NODE *next;
} dlink;

dlink *start;
//start = (dlink *)malloc(sizeof(dlink));

void createlist(dlink *);
void insertatstart(int);
void displaydl(dlink *);

int main(){
	dlink *node;
	node = (dlink *)malloc(sizeof(dlink));
	start = node;
	createlist(node);
	int val;
	char op='2';
	while(op!=3){
		printf("1 -> Insert value\n");
		printf("2 -> Display list\n");
		printf("3 -> Terminate\n");
		printf("Enter the choice of operation on your linked list: \n");
		fflush(stdin);
		op = getchar();
		switch(op){
			case '1':
				printf("Enter the value you want to insert: \n");
				scanf("%d", &val);
				insertatstart(val);
				node = start;
				break;
			case '2':
				displaydl(node);
				break;
			case '3':
				printf("Terminating ......................../");
				exit(0);
		}
	}
}

void createlist(dlink *node){
	dlink *curr;
	int i=1;
	char ch;
	printf("Enter the value of the %d node: ", i);
	scanf("%d", &node->info);
	node->next = NULL;
	node->prev = NULL;
	i++;
	printf("Enter 'n' to quit else 'y' to continue: ");
	fflush(stdin);
	ch = getchar();
	
	while(ch!='n'){
		curr = (dlink *)malloc(sizeof(dlink));
		node->next = curr;
		curr->prev = node;
		node = curr;
		printf("Enter the value of the %d node: ", i);
		scanf("%d", &node->info);
		node->next = NULL;
		i++;
		printf("Enter 'n' to quit else 'y' to continue: ");
		fflush(stdin);
		ch = getchar();
	}
}

void displaydl(dlink *node){
	dlink *ptr;
	printf("Printing forward: \n");
	while(node!=NULL){
		ptr = node;
		printf("%d\t", node->info);
		node = node->next;
	}
	printf("\n");
	node = ptr;
	while(node!=NULL){
		printf("%d\t", node->info);
		node = node->prev;
	}
	printf("\n");
}

void insertatstart(int val){
	dlink *insert;
	insert = (dlink *)malloc(sizeof(dlink));
	insert->info = val;
	insert->next = start;
	insert->prev = NULL;
	start->prev = insert;
	start = insert;		
	
}




