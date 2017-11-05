//使用此代码使得头文件中定义的函数实现
#include <stdio.h>
#include <stdlib.h>  //提供exit()函数的原型 
#include "list.h" //使用双引号说明此头文件只需在本工程里面找 

static void CopyToNode(Item item,Node *pnode);//仅限本文件使用

//下面进行接口函数设计
void InitializeList(List *plist)
{
	*plist=NULL;//NULL为宏，代表空 
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
	free(pt);  //释放指针pt内存 
	
	return full;
}

unsigned int ListItemCount(const List *plist)
{
	unsigned int count=0;
	Node *pnode=*plist;
	
	while (pnode!=NULL)
	{
		++count;
		pnode=pnode->next;//设置下一个节点 
	} 
	return count; 
} 

bool AddItem(Item item,List *plist)
{
	Node *pnew;
	Node *scan=*plist;//头指针的地址是传递给AddItem()的第二个参数，所以*plist就是头指针的值 
	
	pnew=(Node*)malloc(sizeof(Node));
	if (pnew==NULL)
	    return false;
	
	CopyToNode(item,pnew);
	pnew->next=NULL;
	if (scan==NULL)
	    *plist=pnew;   //为空链表，则把pnew放在链表开头 
	else 
	{
		while (scan->next!=NULL)
		       scan=scan->next;//找到链表结尾 
		scan->next=pnew;//把pnew添加至链表结尾 
	}
	
	return true;
}

void Traverse(const List *plist,void(*pfun)(Item item))
{
	Node *pnode=*plist;  //写出了链表开始 
	
	while (pnode!=NULL)
	{
		(*pfun)(pnode->item);//把函数应用于链表中的项 
		pnode=pnode->next;//并前进到下一项 
	}
}

void EmptyTheList(List *plist)
{
	Node *psave;
	
	while (*plist!=NULL)
	{
		psave=(*plist)->next;//保存下一个节点地址 
		free(*plist);//释放当前地址 
		*plist=psave;//并前进至下一个节点 
	}
}

static void CopyToNode(Item item,Node *pnode)
{
	pnode->item=item;
} 

































