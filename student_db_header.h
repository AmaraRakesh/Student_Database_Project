#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>

typedef struct st
{
	int rollno;
	char name[30];
	float per;
	struct st *next;
}SLL;
void stud_add(SLL **);
void print_node(SLL *);
void delete_node(SLL **);
void modify_node(SLL **);
void sort_array(int*);
void search_node_rnum(SLL *,int );
void search_node_name(SLL *,char * );
void search_node_marks(SLL *,float);
void save_nosave(SLL *);
void save_file(SLL *);
void delete_allnodes(SLL **);
void sort_list(SLL *);
void reverse_links(SLL **);
