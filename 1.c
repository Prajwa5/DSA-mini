#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char info;
	int priHour;
	int priSec;
	int priMin;
	struct node *next;
}NODE;

typedef struct queue
{
	NODE *head;
}QUEUE;

void initList(QUEUE *pq);
void AddEvent(QUEUE *pq,char event, int min,int sec,int hour);
void DeleteEvent(QUEUE *pq,char *event, int *min,int *sec,int *hour);


void initList(QUEUE *pq)
{
	pq->head=NULL;
}

void AddEvent(QUEUE *pq, char event, int min,int sec,int hour)
{
    NODE *newNode=malloc(sizeof(NODE));
	strcpy(newNode->info,event);
	newNode->priHour=hour;
	newNode->priMin=min;
	newNode->priSec=sec;
	newNode->next=NULL;
	
	NODE *p=pq->head;
	NODE *q=NULL;
	
	while(p!=NULL &&  p->priHour < newNode->priHour &&  p->priMin < newNode->priMin &&  p->priSec < newNode->priSec)
	{
		q=p;
		p=p->next;
	}
	if(q==NULL)
	{
		newNode->next=pq->head;
		pq->head=newNode;
	}
	else
	{
		newNode->next=p;
		q->next=newNode;
	}
}

void DeleteEvent(QUEUE *pq, char *event, int *min,int *sec,int *hour )
{
    NODE *p=pq->head;
	*event=p->info;
	*hour=p->priHour;
	*min=p->priMin;
	*sec=p->priSec;
	pq->head=pq->head->next;
	
	free(p);
}
