/*
		    DS Lab- 5
	   CSE Sec 2, Group 5
	      Oct 17, 2012
	       UE 113090
AIM: Implementation of Postfix using Stack of Linked Lists
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>    //for exponent, pow
#include"ds7postfix.h"      //contains functions for stack implementation; reduces complexity
//********Global Variables*************
const int TRUE=1;
const int FALSE=0;
char input[30];
NODEPTR start,top;      //p is a ptr to struct nodeS
//********Functions Prototypes**********
void addop();
void subop();
void mulop();
void divop();
void expop();
void postfix(char *);
//*********of ds7postfix.h*******
NODEPTR getNode(void);
void freeNode(NODEPTR);
void push(NODEPTR *, int);
int pop(NODEPTR *);       //returns data poped
void display(NODEPTR);  //pass top
//*********Main Function**************
int main(){
    start=getNode();
    start->info=0;
    start->next=NULL;
    top=start;
    printf("\nEnter Postfix String: ");
    gets(input);
    postfix(input);
    printf("\nValue of expression %s\t=",input);
    display(top);
    printf("\n");
    
}//end main
void postfix(char *input){
  int i,valid=TRUE;
  for(i=0;input[i]!='\0'&&valid;i++){
    //printf("%c\n",input[i]);
    //if(input[i]=='0'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'){
    ////push(start,(int)input[i]);
    //printf("%d",input[i]);    //debug
    //}
    //else if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'||input[i]=='$'){
    //printf("%c",input[i]);    //debug
    //}
    //else{
    //printf("\nInvalid String !\n");
    //}
    switch(input[i]){
    case '0': push(&top,0); break;
    case '1': push(&top,1); break;
    case '2': push(&top,2); break;
    case '3': push(&top,3); break;
    case '4': push(&top,4); break;
    case '5': push(&top,5); break;
    case '6': push(&top,6); break;
    case '7': push(&top,7); break;
    case '8': push(&top,8); break;
    case '9': push(&top,9); break;
/*
    case '0': push(start,0); break;
    case '1': push(start,1); break;
    case '2': push(start,2); break;
    case '3': push(start,3); break;
    case '4': push(start,4); break;
    case '5': push(start,5); break;
    case '6': push(start,6); break;
    case '7': push(start,7); break;
    case '8': push(start,8); break;
    case '9': push(start,9); break;  
 */  
    case '+': addop(); break;
    case '-': subop(); break;
    case '*': mulop(); break;
    case '/': divop(); break;
    case '$': expop(); break;
    default: printf("\nInvalid String !\n"); valid=FALSE; break;
    }//end switch
  }//end for
  
}
void addop(void){
    int op1,op2,value;
    op2=pop(&top);
    op1=pop(&top);
    value=op1+op2;
    push(&top,value);
/*
    op2=pop(start);
    op1=pop(start);
    value=op1+op2;
    push(start,value);
 */
}
void subop(void){
    int op1,op2,value;
    op2=pop(&top);
    op1=pop(&top);
    value=op1-op2;
    push(&top,value);
/*
    op2=pop(start);
    op1=pop(start);
    value=op1-op2;
    push(start,value);
 */
}
void mulop(void){
    int op1,op2,value;
    op2=pop(&top);
    op1=pop(&top);
    value=op1*op2;
    push(&top,value);
/*
    op2=pop(start);
    op1=pop(start);
    value=op1*op2;
    push(start,value);
 */
}

void divop(void){
    int op1,op2,value;
    op2=pop(&top);
    op1=pop(&top);
    value=op1/op2;
    push(&top,value);
/*    

    op2=pop(start);
    op1=pop(start);
    value=op1/op2;
    push(start,value);
 */
}

void expop(void){
    int op1,op2,value;
    op2=pop(&top);
    op1=pop(&top);
    value=op1+op2;//pow(op1,op2);
    push(&top,value);
/*    op2=pop(start);
    op1=pop(start);
    value=op1+op2;//pow(op1,op2);
    push(start,value);
 */
}

