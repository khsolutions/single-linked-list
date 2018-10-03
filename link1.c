#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *link;
};

struct node *root =NULL;

void createnode(int);
void display();
void addnode();
void addatbegin();
void reverse();
void swap();
void delete();
void length();
int main()

{
	createnode(100);

	createnode(200);

	createnode(300);

	createnode(400);

	createnode(500);

	display();

	addnode();

	display();

	addatbegin();

	display();

	reverse();

	display();

	swap();

	display();

	delete();

	display();

	length();

	return 0;
}

void createnode(int val)
{
	struct node *temp;

	struct node *p= root;

	temp = (struct node*)malloc(sizeof(struct node));

	temp->data = val;

	temp->link = NULL;

	if(root == NULL)
	{
		root = temp;
		return;
	}

	while(p->link != NULL)
	{
		p= p->link;
	}

	p->link = temp;
}

void display()
{
	  printf("\n");
	struct node *p =root;

	while(p!=NULL)
	{
		printf("-->%d",p->data);

		p=p->link;
	}
}

void addnode()
{

	int val1,val2;

	printf("\nenter the node data to be inserted\n");

	scanf("%d",&val2);

	struct node *p=root;

	struct node *temp =NULL;

	temp= (struct node*)malloc(sizeof(struct node));

	temp->data = val2;

	temp->link =NULL;

	printf("enter the previous node data to add new node after it\n");

	scanf("%d",&val1);

	while(p->data !=val1)
	{
		p=p->link;
	}

	temp->link = p->link;

	p->link = temp;

}

   void addatbegin()
{
	int val;

	 struct node *temp = NULL ;

	printf("\nenter the node data to add at begin\n");
	scanf("%d",&val);

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = val;

	temp->link = root;

	root = temp;
}

 void reverse()
{
	struct node *p = root;

	struct node *temp=NULL;

	struct node *ref = p->link;

	struct node *sn = root;
 
	while(ref)
	{
		    temp  = ref -> link;
		ref->link = p;
		p=ref;
		ref=temp;
        }

	sn->link  = NULL;

	root = p;
}

 void swap()
{
     int val;

     struct node *p=root;
     struct node *q;
     struct node *r;

     printf("\nenter the node data to swap\n");
     scanf("%d",&val);

     if(p->data == val)
     {
	  q=p->link;
	  r=q->link;
	 root = q;
	 q->link=p;
	 p->link=r;
	 return;
     } 
   else
   {
     
   while(p->link->link->data!= val)
         p=p->link;
       
        q=p->link;
	r=q->link;
        p->link  = r;
        q->link = r->link;
	r->link = q;
        return ;
    }
    
 }
  
 void delete()
{
	int val;
	struct node *p = root;
	struct node *temp=NULL;

	printf("\nenter the node data to delete\n");
	scanf("%d",&val);

	if(p->data == val)
	{
	   root =p->link;

	   free(p);
	}
	else if(p->data!=val)
	{
		while(p->link->data!=val)
			p=p->link;
 		temp=p->link;
		p->link = temp->link;
		free(temp);
	}
	else
	{
		while(p->link->link!=NULL)
			p=p->link;

		 temp= p->link;
		 p->link = temp->link;
        }
}
	void length()
{
	int i=0;
	struct node *p=root;

	while(p!=NULL)
	{
		i++;
		p=p->link;
	}
	printf("\nthe length of the list is :%d",i);
}
