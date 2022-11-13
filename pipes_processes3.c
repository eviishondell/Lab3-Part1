#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main(int argc, char **argv)
{
int pipefd1[2];
int pipefd2 [2] ;
int pid, pid2, pid3;
int status;
char *cat_args[] = {"cat","scores", NULL};
char *grep_args[] = ("grep","Lakers", NULL);
char *sort_args[] = {"sort", NULL, NULL};
grep_args [1] = argv[1];
if (argc < 1) {
printf ( "Please enter a grep argument: \n" ) ;
exit(1);
}
pipe(pipefdl);
pipe(pipefd2) ;
pid = fork() ;
if (pid == 0) //cat process
{
dup2(pipefd1[1], 1) ;
// close unused half of pipe
close (pipefd1 [1]) ;
close(pipefd1[0]) ;
close(pipefd2[0]);
close (pipef2[1]) ;
execvp(*cat_args, cat args);
}

else if (pid < 0){
  perror("cat fork error");
}

else{
  pid2 = fork();
  if (pid2 == 0){
    dup2(pipefd1[0],0);
    dup2(pipefd2[1],1);

    close (pipefd1[1]) ;
    close (pipefdi[0]) ;
    close (pipefd2[0]) ;
    close (pipefd2[1]) ;

    execvp(*grep_args, grep_args);
  }
  else if (pid3 < 0) {
    perror("sort fork error\n");
  }
}
}


close (pipefd1 [1]) ;
close(pipefd1[0]);
close (pipefd2[0]) ;
close (pipefd2 [1]) ;

int i;
for (1=0; 1<3; i++){
wait(&status);
}
}








// struct node {

// int data; //Data of the node

// struct node *nextptr; //Address of the next node

// }*HeadNode;

// const int MAXSIZE = 8;

// int Stack[8], top = -1;

// // Remark Refer follows link for more details on "?: ternary operator;

// // https://www.geeksforgeeks.org/conditional-or-ternary-operator-in-c-c/

// int isempty() {return (top == -1)? 1 : 0;}

// int isfull() {return (top == MAXSIZE)? 1 : 0;}

// int peek() {return HeadNode->data;}

// int push(int data);

// void displayList();

// int pop();

// void print_green() {printf("\033[1;32m");}

// void print_cyan() {printf("\033[1;36m");}

// void print_reset() {printf("\033[0m");}

// int main() {

// int opt, data;

// while(1){

// printf("***Stack with Single Linked List*** \n");

// printf(" [1] Push \n");

// printf(" [2] Pop \n");

// printf(" [3] Peak \n");

// printf(" [4] Exit \n");

// printf("Select Operation to the Stack :> ");

// scanf("%d", &opt);

// switch (opt){

// // case 1:

// printf("Input new insert data to the Stack:> ");

// scanf("%d", &data);

// push(data);

// displayList();

// break;

// // case 2:

// if (!isempty()) printf(">: Data \"%d\" pop out Stack: \n", data = pop());

// else printf(":> Stack is empty.\n");

// displayList();

// break;

// // case 3:

// if(!isempty()) printf(">: Element at top of the Stack: %d\n" ,peek());

// else printf(">: Stack is empty.\n");

// break;

// // case 4:

// goto exitloop;

// default:

// printf (">: Error! No action being taken! \n");

// }

// }

// exitloop: ;

// return 0;

// }

// int push(int data) {

// // int data;

// char name[50];

// struct node *stNode;

// if(!isfull()){

// stNode = (struct node*)malloc(sizeof(struct node));

// if(stNode == NULL) printf(" Memory can not be allocated.");

// else {

// top++;

// stNode->data = data; //Links the data part

// stNode->nextptr = NULL;

// if(HeadNode != NULL) stNode->nextptr = HeadNode; //Links the address part

// HeadNode = stNode;

// }

// }else 
// {printf(">: Could not insert data, Stack is full.\n");
// }
// }

// int pop() {

// int data;

// struct node *delNode;

// if(!isempty()){

// delNode = HeadNode;

// data = delNode->data;

// HeadNode = HeadNode->nextptr;

// free(delNode);

// top--;

// return data;

// } else printf(">: Could not retrieve data, Stack is empty.\n");

// }

// void displayList(){

// struct node *stNode;

// print_green();

// printf(">: Current data in Stack: \n");

// if(HeadNode == NULL) printf(" Stack is empty. \n");

// else {

// stNode = HeadNode;

// while(stNode != NULL){

// printf(" Data = %d\n", stNode->data); // prints the data of current node

// stNode = stNode->nextptr; // advances the position of current node

// }

// }

// print_reset();

// }