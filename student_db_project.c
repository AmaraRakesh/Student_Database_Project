#include "own_header.h"
int num=1,ary[20]={0},i=0;
void main()
{
	SLL *head=0;
	char op;
	while(1){
	printf("***** STUDENT RECORD MENU *****\n");
	printf("a/A :add new record\n");
	printf("d/D :delete a record\n");
	printf("s/S :show the list\n");
	printf("m/M :modify a record\n");
	printf("v/V :save\n");
	printf("e/E :exit\n");
	printf("t/T :sort the list\n");
	printf("l/L :delete all the records\n");
	printf("r/R :reverse the list\n\n");
	printf("Enter your choice:\n");
	scanf(" %c",&op);
	system("clear");
	if(op>='A' && op<='Z')
		op=op+32;

	switch(op){
		case 'a':stud_add(&head);break;
		case 'd':delete_node(&head);break;
		case 's':print_node(head);break;
		case 'm':modify_node(&head);break;
	      	case 'v':save_file(head);break;
		case 'e':save_nosave(head);break;
		case 't':sort_list(head);break;
		case 'l':delete_allnodes(&head);break;
		case 'r':reverse_links(&head);break;
		default :printf("Wrong choice\n");
	}

   }
}

void stud_add(SLL **ptr)
{

	SLL *new=malloc(sizeof(SLL));
	printf("Enter the Name & Percentage\n");
	scanf("%s %f",new->name,&new->per);

	if(*ptr==0)
	{
		new->next=*ptr;
		*ptr=new;

	}
	else{
		new->next=*ptr; // addding nodes at begin
		*ptr=new;
	}
	// for Rollno	
	int t1;
	if(ary[0]!=0) //checking 0th pos of array...
	{
		sort_array(ary);
		(*ptr)->rollno=ary[0];
		ary[0]=0;
		for(t1=1;t1<i;t1++)
			ary[t1-1]=ary[t1];
		i--;
		
	}
	else
		(*ptr)->rollno=num++;

}

//Printing Nodes
void print_node(SLL *ptr)
{
	if(ptr==0)
	{
		printf("No Records Found\n");
		return;
	}
	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->per);
		ptr=ptr->next;
	}
}

//Delete node based on roll/name...
void delete_node(SLL **ptr)
{
	if(*ptr==0){
		printf("No Records Found\n");
		return;
	}
	SLL *del=*ptr,*prev;
	char op1;
	int n;
	char dname[20];
	printf("R/r:enter roll to del\nN/n:enter name to del\n");
	scanf(" %c",&op1);
	if(op1>='A' && op1<='Z')
		op1+=32;
	switch(op1)
	{
	case'r':

    		 printf("Enter rollno\n");
    		 scanf("%d",&n);

		 while(del)
		 {
			 if(del->rollno==n)
			 {
				 if(del==*ptr)
					 *ptr=del->next;	
				 else
					 prev->next=del->next;

				ary[i++]=del->rollno;
				 free(del);
				 return;
			 }
			 prev=del;
			 del=del->next;
		 }
		 break;
	case 'n':
    		 printf("Enter name\n");
    		 scanf("%s",dname);

		 while(del)
		 {
			 if(strcmp(del->name,dname)==0)
			 {
				 if(del==*ptr)
					 *ptr=del->next;	
				 else
					 prev->next=del->next;

				 ary[i++]=del->rollno;
				 free(del);
				 return;
			 }
			 prev=del;
			 del=del->next;
		}
			break;
	}
}


void sort_array(int *a)
{
	int j,k,t;
	for(j=0;j<i-1;j++)
	{
		for(k=0;k<i-1-j;k++)
		{
			if(a[k]>a[k+1])
			{
				t=a[k];
				a[k]=a[k+1];
				a[k+1]=t;
			}
		}
	}
	
}

			
void modify_node(SLL **ptr)
{
	char op;
	printf("Enter which way to search for modification\n");
	printf("R/r : to search a rollno\nN/n:to search a name\n");
	printf("P/p: percentage based\n");
	scanf(" %c",&op);
	switch(op)
	{
		case 'r':
		{
			int num;
			printf("Enter rollno\n");
			scanf("%d",&num);
			search_node_rnum(*ptr,num);break;
		}
		case 'n':
		{
			char n[20];
			printf("Enter name\n");
			scanf("%s",n);
			search_node_name(*ptr,n);
			break;

		}
		case 'p':
		{
			float f;
			printf("Enter marks\n");
			scanf("%f",&f);
			search_node_marks(*ptr,f);
			break;

		}

		
	}
	
}
void search_node_marks(SLL *ptr,float f)
{
	SLL *ptr1=ptr;
	int i=0;
	while(ptr1)
	{
		if(ptr1->per==f)
		{
			i=1;
			printf("%d %s %f\n",ptr1->rollno,ptr1->name,ptr1->per);
		}
		ptr1=ptr1->next;
	}
	if(!i)
		printf("Records not found based on your entered percentage\n");
	else
	{
		int num;
		printf("Enter the rollno\n");
		scanf("%d",&num);
		search_node_rnum(ptr,num);
	}
}

void search_node_name(SLL *ptr,char *s)
{
	SLL *ptr1=ptr;
	int i=0;
	while(ptr1)
	{
		if(strcmp(ptr1->name,s)==0)
		{
			i=1;
			printf("%d %s %f\n",ptr1->rollno,ptr1->name,ptr1->per);
		}
		ptr1=ptr1->next;
	}
	if(!i)
		printf("Records not found based on your entered name\n");
	else
	{
		int num;
		printf("Enter the rollno\n");
		scanf("%d",&num);
		search_node_rnum(ptr,num);
	}
}

void search_node_rnum(SLL *ptr,int num)
{
	SLL *temp=0;
	while(ptr)
	{
		if(ptr->rollno==num)
		{
			temp=ptr;
			break;
		}

		ptr=ptr->next;

	}
	if(temp==0)
	{
		printf("Enter a choice from main menu a/A\n");
		return;
	}
	else
	{
		char op;
		printf("enter choice to modifiy\n");
		printf("n/N:name\np/P:percentage\n");
		scanf(" %c",&op);
		switch(op)
		{
			case'n':
			{
				char s[20];
				printf("Enter name to modifiy\n");
				scanf("%s",s);
				strcpy(temp->name,s);
				break;
			}
			case 'p':
			{
				float m;
				printf("Enter the marks\n");
				scanf("%f",&m);
				temp->per=m;
				break;
			}
		}
	}



}
void save_nosave(SLL *ptr){
	char op;
	printf("S/s:save and exit\nE/e exit without saving\n");
	scanf(" %c",&op);
	int flag=0;
	if(ptr==0)
		flag=1;
	if(op=='s'||op=='S'){
	FILE *fp=fopen("data","w");
	while(ptr){
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->per);
		ptr=ptr->next;
	}
	if(flag==0)
	printf("Data saved in file successfully\n");
	else
		printf("Data is not there EXIT\n");
	exit(0);
	}
	else
		exit(0);
}
void save_file(SLL *ptr){
	if(ptr==0){
		printf("No records found\n");
		return ;
	}
	FILE *fp=fopen("data","w");
	while(ptr){
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->per);
		ptr=ptr->next;
	}
	printf("Data saved in file successfully\n");
}
void delete_allnodes(SLL **ptr){
	if(*ptr==0){
		printf("No data found\n");
		return;
	}
	SLL *del=*ptr;
	while(del){
		*ptr=del->next;
		free(del);
		del=*ptr;
	}
	printf("all the records deleted\n");
}
void sort_list(SLL *ptr){
	if(ptr==0){
		printf("No data found\n");
		return;
	}
	SLL *p1,*p2,*t=ptr;
	p1=ptr;
	int c=0,i,j;
	while(t){
		c++;
		t=t->next;
	}
	printf("%d\n",c);
	SLL temp;
	for(i=0;i<c-1;i++){
		p2=p1->next;
		for(j=0;j<c-1-i;j++){
			if(p1->per>p2->per)
			{
				temp.per=p1->per;
				strcpy(temp.name,p1->name);
				temp.rollno=p1->rollno;

				p1->rollno=p2->rollno;
				strcpy(p1->name,p2->name);
				p1->per=p2->per;

				p2->rollno=temp.rollno;
				strcpy(p2->name,temp.name);
				p2->per=temp.per;

			}
			p2=p2->next;
		}
		p1=p1->next;
	}
}
void reverse_links(SLL **ptr){
	if(*ptr==0)
	{
		printf("No records found\n");
		return ;
	}
	int i,c=0;
	SLL *t=*ptr;
	while(t){
		c++;
		t=t->next;
	}
	SLL *temp=*ptr;
	if(c>=2){
		SLL **arr;
		arr=malloc(sizeof(SLL *)*c);

		for(i=0;i<c;i++){
			arr[i]=temp;
			temp=temp->next;
	}
	for(i=1;i<c;i++)
		arr[i]->next=arr[i-1];

		arr[0]->next=0;
		*ptr=arr[c-1];
	}
}
