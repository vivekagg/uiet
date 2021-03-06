/*
		    DS Lab- 6
	   CSE Sec 2, Group 5
	      Oct 10, 2012
	       UE 113090
AIM: Implementation of Stack using Linked Lists
*/

#include<stdio.h>
#include<stdlib.h>
struct nodeS {
  int info;
  struct nodeS *top;
  struct nodeS *next;    //next points to var of type node
};
typedef struct nodeS *NODEPTR;
//*******Global Variable*****
//********Functions Prototypes**********
NODEPTR getNode(void);
void freeNode(NODEPTR);
void push(NODEPTR *, int);
int pop(NODEPTR *);       //returns data poped
void display(NODEPTR);  //pass top

//*********Main Function**************
int main(){
  NODEPTR start;    //p is a ptr to struct nodeS
  start=getNode();
  start->info=0;
  start->next=NULL;
  start->top=start;
  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. Print\n");
  printf("4. Exit\n");
  while(1){
    int query;
    printf("\nEnter operation: ");
    scanf("%d",&query);
    if(query==1){
      int data;
      printf("\nEnter data to push: ");
      scanf("%d",&data);
      push(&(start->top),data);
    }
    else if(query==2){
      int dataPoped;
      //pop(start);
      dataPoped=pop(&(start->top));
      if(dataPoped!=-1)
        printf("\nSuccessfully Poped %d\n",dataPoped);

    }
    else if(query==3){
      printf("The Stack is ");
      if((start->top)->next==NULL){
        printf("empty\n");
      }
      else{
        printf("\n------------------------------------------\n");
        display(start->top);
        printf("\n------------------------------------------");
      }
      printf("\n");
    }//end q=3
    else if(query==4){
      printf("\nThank You\n");
      exit(0);
    }
  }//end while
}//end main


//=====================FUNCTIONS=================================

NODEPTR getNode(void){
  ///removes a node from available list and returns a ptr to it
  NODEPTR p;
  p=(NODEPTR)malloc(sizeof(struct nodeS));
  return(p);
}//end getnode

void freeNode(NODEPTR  p){
  ///returns the node(p) to the available list
  free(p);
}//end freenode

void display(NODEPTR p){
  if (p->next==NULL){
    return;
  }
  //printf("-----------------------------------");
  printf("\t%d",p->info);
  //printf("-----------------------------------");
  p=p->next;
  display(p);
}

void push(NODEPTR *tempTop,int x){
  ///if p is not null, inserts x into node after the node pointed by p
  NODEPTR q;
  q=getNode();
  q->info=x;//info saved in new node
  q->next=*tempTop;//NOTE next points to the previous item on stack
  //traverse to find last node
  //tempStart=top(tempStart);
  *tempTop=q;//prev last node containing null now points to new node
}//end insert after

int pop(NODEPTR *tempTop){
  //NODEPTR ptr;
  //ptr=tempStart;
  if((*tempTop)->next==NULL){//if node before top is null
    printf("\nStack UnderFlow\n");
    return(-1);
  }
  else{
    int dataPoped;
    NODEPTR temp;
    dataPoped=(*tempTop)->info;//84
    //printf("\n%d\n",(tempTop)->info);  //debug
    //printf("%d",ptr->info);   //debug
    temp=*tempTop;
    *tempTop=(*tempTop)->next;//top points to prev node  //NOTE modifies global variable !
    freeNode(temp);  //free memory
    //ptr->next=NULL;
    //TODO make this top's location one before current position
    return(dataPoped);
  }
}

