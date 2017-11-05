//ʹ�ô˴���ʹ��ͷ�ļ��ж���ĺ���ʵ��
#include <stdio.h>
#include <stdlib.h>  //�ṩexit()������ԭ�� 
#include "list.h" //ʹ��˫����˵����ͷ�ļ�ֻ���ڱ����������� 

static void CopyToNode(Item item,Node *pnode);//���ޱ��ļ�ʹ��

//������нӿں������
void InitializeList(List *plist)
{
	*plist=NULL;//NULLΪ�꣬����� 
}

bool ListIsEmpty(const List *plist)
{
	if (*plist==NULL)
	    return true;
	else
	    return false;
}

bool ListIsFull(const List *plist)
{
	Node *pt;
	bool full;
	
	pt=(Node *)malloc(sizeof(Node));
	if (pt==NULL)
	    full=true;
	else
	    full=false;
	free(pt);  //�ͷ�ָ��pt�ڴ� 
	
	return full;
}

unsigned int ListItemCount(const List *plist)
{
	unsigned int count=0;
	Node *pnode=*plist;
	
	while (pnode!=NULL)
	{
		++count;
		pnode=pnode->next;//������һ���ڵ� 
	} 
	return count; 
} 

bool AddItem(Item item,List *plist)
{
	Node *pnew;
	Node *scan=*plist;//ͷָ��ĵ�ַ�Ǵ��ݸ�AddItem()�ĵڶ�������������*plist����ͷָ���ֵ 
	
	pnew=(Node*)malloc(sizeof(Node));
	if (pnew==NULL)
	    return false;
	
	CopyToNode(item,pnew);
	pnew->next=NULL;
	if (scan==NULL)
	    *plist=pnew;   //Ϊ���������pnew��������ͷ 
	else 
	{
		while (scan->next!=NULL)
		       scan=scan->next;//�ҵ������β 
		scan->next=pnew;//��pnew����������β 
	}
	
	return true;
}

void Traverse(const List *plist,void(*pfun)(Item item))
{
	Node *pnode=*plist;  //д��������ʼ 
	
	while (pnode!=NULL)
	{
		(*pfun)(pnode->item);//�Ѻ���Ӧ���������е��� 
		pnode=pnode->next;//��ǰ������һ�� 
	}
}

void EmptyTheList(List *plist)
{
	Node *psave;
	
	while (*plist!=NULL)
	{
		psave=(*plist)->next;//������һ���ڵ��ַ 
		free(*plist);//�ͷŵ�ǰ��ַ 
		*plist=psave;//��ǰ������һ���ڵ� 
	}
}

static void CopyToNode(Item item,Node *pnode)
{
	pnode->item=item;
} 

































