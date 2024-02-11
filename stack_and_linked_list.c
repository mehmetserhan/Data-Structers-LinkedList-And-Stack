#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node1{
	char *color;
	struct node1 *next;
}linked_list;

typedef struct node2{
	char *color;
	struct node2 *next;
}stack;

linked_list *first = NULL;
stack *top = NULL;
void createLinkedList();
void popBalloon();
void popAllBalloons();
void printBalloons();
void addToStack(char*);
void printStack();
int counter(linked_list*);
int stackCapacity();

char *colors[7] = {"Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Pink"};
char *balloons[1];

int n;
int main(){
	printf("Possible colors of balloons are: ");
	int h;
	for(h=0; h<sizeof(colors)/sizeof(colors[0]); h++){
		printf("%s ", colors[h]);
	}
	
	printf("\n\nHow many balloons do you want?: ");
	scanf("%d", &n);
	
	int i, rand_indx;
	srand((unsigned)time(NULL));
	for(i=0; i<n; i++){
		rand_indx = rand()%7;
		balloons[i] = colors[rand_indx];
	}
	
	createLinkedList(balloons);
	printBalloons();
	popAllBalloons();
    printStack();
	return 0;
}

void createLinkedList(){
	int i;
	linked_list *neww;
	linked_list *old;
	if(n == 0){
		first = NULL;
	}
	for(i = 0; i < n; i++){
		neww = (linked_list*)malloc(sizeof(linked_list));
		if(i == 0){
			first = neww;
			neww -> color = balloons[i];	
			neww -> next = first;
		}
		else{
			neww -> color = balloons[i];
			old -> next = neww;
			neww -> next = first;
		}
		old = neww;		
	}
	printf("-----------------------------------------------------\n");
}

void popBalloon(linked_list *silinecek){
	linked_list *temp = silinecek;
	if(temp == NULL){
		printf("Null list.\n");
		return;
	}
	else{
		while(temp -> next != silinecek)
			temp = temp -> next;
		temp -> next = silinecek -> next;
		first = silinecek -> next;
		addToStack(silinecek->color);
		free(silinecek);
	}
}

void popAllBalloons(){
	printf("OPERATIONS:\n\n");
	int p;
	for(p=0; p<n; p++){
		printf("%d. balloon got popped and added to the stack: %s\n", p+1, balloons[p]);
		popBalloon(first);
	}
	printf("-----------------------------------------------------\n");
}

void printBalloons(){
	linked_list *temp = first;
	if(temp == NULL){
		printf("Linked list is empty.\n");
		return;
	}
	else{
		printf("Total amonut of balloons got created: %d\n\n", counter(first));
		printf("ITEMS ON THE LINKED LIST:\n\n");
		int m;
		do{
			printf("%d. balloon is -> %s\n", m+1, balloons[m]);
			temp = temp -> next;
			m++;
		}while(temp != first);
	}
	printf("-----------------------------------------------------\n");
}

void addToStack(char *color){
	stack *neww = (stack*)malloc(sizeof(stack));
	neww -> color = color;
	if(top == NULL)
		neww -> next = NULL;
	else
		neww -> next = top;
	top = neww;
}

void printStack(){
	int countRed = 0, countOrange = 0, countYellow = 0, countGreen = 0, countBlue = 0, countPurple = 0, countPink = 0;
	stack *temp = top;
	printf("STACK ITEMS (from top to bottom):\n\n");
	while(temp!=NULL){
		if (!strcmp(temp->color, "Red")){
			printf("Red\n");
			countRed++;
		}
		else if(!strcmp(temp->color, "Orange")){
			printf("Orange\n");
			countOrange++;
		}
		else if(!strcmp(temp->color, "Yellow")){
			printf("Yellow\n");
			countYellow++;
		}
		else if(!strcmp(temp->color, "Green")){
			printf("Green\n");
			countGreen++;
		}
		else if(!strcmp(temp->color, "Blue")){
			printf("Blue\n");
			countBlue++;
		}
		else if(!strcmp(temp->color, "Purple")){
			printf("Purple\n");
			countPurple++;
		}
		else if(!strcmp(temp->color, "Pink")){
			printf("Pink\n");
			countPink++;
		}
		else{
			printf("An error got acquired.\n");
			return;
		}
		temp = temp -> next;	
	}
	printf("-----------------------------------------------------\n");
	printf("RESULT:\n\n");
	printf("Total amount of balloons got popped: %d\n", stackCapacity());
	printf("%d red\n", countRed);
	printf("%d orange\n", countOrange);
	printf("%d yellow\n", countYellow);
	printf("%d green\n", countGreen);
	printf("%d blue\n", countBlue);
	printf("%d purple\n", countPurple);
	printf("%d pink\n", countPink);
}

int counter(linked_list *first){
	int count=0;
	linked_list *temp = first;
	do{
		temp = temp -> next;
		count++;
	}while(temp != first);
	return count;
}

int stackCapacity(){
	stack *temp = top;
	int count = 0;
	do{
		temp = temp -> next;
		count++;
	}while(temp != NULL);
	return count;
}
