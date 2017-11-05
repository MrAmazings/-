#ifndef LIST_H_    //使用#ifndef指令，防止多次包含一个文件 
#define LIST_H_
#include <stdbool.h>  //为C99之后有的布尔值 

//下面进行特定程序声明
#define NAME 30
#define NUMBER 20
#define GENDER 5
struct information         //以struct来创建一系列变量，相关用法可参照二进制位字段的创立 
{
	char name[NAME];
	char number[NUMBER];
	char gender[GENDER];
	int chinese;
	int math;
	int english;
	float average;
}; 

typedef struct information Item;   //将Item定义为struct information 类型

typedef struct node   //此处为一个节点 
{
	Item item;
	struct node * next; //让节点始终指向下一个链接 
} Node; 

typedef Node * List;  //让List指针指向节点

//下面提供对链表进行操作的函数原型 

void InitializeList(List * plist);//初始化链表的函数

bool ListIsEmpty(const List *plist);//检测链表是否为空的函数

bool ListIsFull(const List *plist);//与上面类似，检测链表是否已满的函数

unsigned int ListItemCount(const List *plist);//计算列表中的项数的函数

bool AddItem(Item item,List *plist);//添加项的函数

void Traverse(const List *plist,void(*pfun)(Item item));//让相关函数作用于每一项的函数。其中，pfun为指向一个函数的指针

void EmptyTheList(List *plist);//释放所有内存，使链表设置为空

#endif 
