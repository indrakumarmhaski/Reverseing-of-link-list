#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
   int info;               //Structure of singly linked list
   struct node *next;
};

struct node *START=NULL;

struct node* creatNode()   //Fuction to create a node
{
   struct node *n;
   n=(struct node*)malloc(sizeof(struct node));
   n->next=NULL;
   printf("\nEnter a number");
   scanf("%d",&n->info);
   return(n);
}

void insertNode()      //Fucntion insert a node in list
{
   struct node *n;
   n=creatNode();
   if(START==NULL)
      START=n;
   else
    {
       struct node *t;
       t=START;
       while(t->next!=NULL)
       {
	 t=t->next;
       }
       t->next=n;
    }
}

void printList()           //To print the list
{
  if(START==NULL)
  {
    printf("\nList has no element to show\n");
  }
  else
  {
     struct node *t;
     t=START;
     printf("\nPrinting the link list: ");
     while(t!=NULL)
     {
       printf(" %d",t->info);
       t=t->next;
     }
  }
}

int stack[20];         //A Stack
int top=-1;

void initStack()       //To initialize stack
{
  if(START==NULL)
  {
     printf("\nFirst initialize the link list");
  }
  else
  {
    struct node *t;
    t=START;
    while(t!=NULL)
    {
      top++;
      stack[top]=t->info;
      t=t->next;
    }
  }

}

void printStack()  //To print the list in reverse order
{
   initStack();
   int t=top;
   printf("\nPrinting the stack: ");
   for(int k=t;k>=0;k--)
   {
      printf(" %d",stack[k]);
   }
}

int menu()
{
  int m;
  printf("\nEnter one to insert an element to the link list");
  printf("\nEnter two to view link list");
  printf("\nEnter three to view the reverse of link list");
  printf("\nEnter four to exit");
  printf("\nYour choice: ");
  scanf("%d",&m);
  printf("\n");
  return(m);
}

void main()
{
  clrscr();

  while(1)
  {
     switch(menu())
       {
	   case 1:
		   insertNode();
		   break;
	   case 2:
		   printList();
		   break;
	   case 3:
		   printStack();
		   break;
	   case 4:
		   exit(0);
	   default:
		   break;
       }

  }


  getch();

}
