#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct Node 
{
	int data;
	Node *pre,*next;
}*head,*plast;
void input()
{
	Node *pnext;
	head=(Node*)malloc(sizeof(Node));
	if(head==NULL)
	{
		cout<<"something wrong!"<<endl;
		return ;
	}
	head->next=NULL;
	head->pre=NULL;
	cout<<"please input your data (when input -1 it will stop)"<<endl;
	plast=head;
	while(1)
	{
		int n;
		cin>>n;
		if(n==-1)
		break;
		pnext=(Node*)malloc(sizeof(Node));
		pnext->data=n;
		plast->next=pnext;
		pnext->pre=plast;
		plast=pnext;
	}
	plast->next=NULL;
	cout<<"over input! press enter to continue......"<<endl;
	getchar();
//	system("cls");
}
void output1()
{
	Node *temp;
	Node *p;
	temp=head;
	cout<<"positive sequence:"<<endl;
	while(temp->next!=NULL)
	{
		p=temp->next;
		cout<<p->data<<endl;
		temp=temp->next;
	}
}
void output2()
{
	Node *temp;
	Node *p;
	temp=plast;
	cout<<"reverse sequence:"<<endl;
	while(temp!=head)
	{
		p=temp;
		cout<<p->data<<endl;
		temp=temp->pre;
	}
}
void insert()
{
	int n;
	Node *p;
	Node *temp;
	int i=1;
	p=head;
	cout<<"please input the number of the one you want to insert in"<<endl;
	cin>>n;
	while(i<n && p!=NULL)
	{
		i++;
		p=p->next;
	}
	cout<<"please input your data"<<endl;
	int d;
	cin>>d;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=d;
	if(p==NULL)
	{
		cout<<"the data you input will insert in the last"<<endl;
		temp->pre=p;
		p->next=temp;
		temp->next=NULL;
		plast=temp;//important
	}
	else
	{
		temp->pre=p;
		temp->next=p->next;
		p->next->pre=temp;
		p->next=temp;
	}
	cout<<"the new result:"<<endl;
	output1();
	output2();
}
void deleteNode()
{
	int n;
	int i=1;
	Node *p;
	Node *d;
	p=head;
	cout<<"please input the number you what to delete"<<endl;
	cin>>n;
	while(i<n && p!=NULL)
	{
		i++;
		p=p->next;
	}
	if(p==NULL)
	{
		cout<<"error!"<<endl;
		return ;
	}
	d=p->next;
	if(d->next!=NULL)
	{
		p->next=d->next;
		d->next->pre=p;
	}
	else
	{
		p->next=NULL;
		plast=p;//important
	}
	cout<<"the new result:"<<endl;
	output1();
	output2();
}
int main()
{
	input();
	output1();
	output2(); 
	insert();
	deleteNode();
	return 0;
}
