#ifndef LIST_H_    //ʹ��#ifndefָ���ֹ��ΰ���һ���ļ� 
#define LIST_H_
#include <stdbool.h>  //ΪC99֮���еĲ���ֵ 

//��������ض���������
#define NAME 30
#define NUMBER 20
#define GENDER 5
struct information         //��struct������һϵ�б���������÷��ɲ��ն�����λ�ֶεĴ��� 
{
	char name[NAME];
	char number[NUMBER];
	char gender[GENDER];
	int chinese;
	int math;
	int english;
	float average;
}; 

typedef struct information Item;   //��Item����Ϊstruct information ����

typedef struct node   //�˴�Ϊһ���ڵ� 
{
	Item item;
	struct node * next; //�ýڵ�ʼ��ָ����һ������ 
} Node; 

typedef Node * List;  //��Listָ��ָ��ڵ�

//�����ṩ��������в����ĺ���ԭ�� 

void InitializeList(List * plist);//��ʼ������ĺ���

bool ListIsEmpty(const List *plist);//��������Ƿ�Ϊ�յĺ���

bool ListIsFull(const List *plist);//���������ƣ���������Ƿ������ĺ���

unsigned int ListItemCount(const List *plist);//�����б��е������ĺ���

bool AddItem(Item item,List *plist);//�����ĺ���

void Traverse(const List *plist,void(*pfun)(Item item));//����غ���������ÿһ��ĺ��������У�pfunΪָ��һ��������ָ��

void EmptyTheList(List *plist);//�ͷ������ڴ棬ʹ��������Ϊ��

#endif 
