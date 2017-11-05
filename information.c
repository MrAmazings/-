//此源代码与list.c一起编译
#include <stdio.h>
#include <stdlib.h>
#include "list.h" //定义了List,Item

void showname(Item item);
void shownmber(Item item);
void showgender(Item item);
char *s_gets(char *st,int n)//一种获取字符串的函数

int main(void)
{
	List info;
	Item temp;
	
	//初始化
	InitializeList(&info) ;
	if (ListIsFull(&info))
	{
		fprintf(stderr,"No memory available. Bye!\n");
		exit(1);
	}
	
	puts("Enter your name: ");
	while (s_gets(temp.name,NAME)!=NULL&&temp.name[0]!='\0')
	{
		puts("Enter your school number: ");
		scanf("%s",&temp.number);
		while(getchar()!='\n')
		     continue;
		puts("Enter your gender: ");
		scanf("%s",&temp.gender);
		while(getchar()!='\n')
		     continue;
	    puts("Enter your Chinese: ");
	    scanf("%d",&temp.chinese);
	    puts("Enter your math: ");
	    scanf("%d",&temp.math);
	    puts("Enter your English: ");
	    scanf("%d",&temp.english);
	    average=(float)(&temp.chinese+&temp.math+&temp.english)/3.0;
	    printf("%.2f",average);
	    
	    if (AddItem(temp,&info)==false)
	    {
	    	fprintf(stderr,"Problem allocating memory\n");
	    	break;
		}
		if (ListIsFull(&info))
		{
			puts("The list is now full.");
			break;
		}
		puts("Enter the information of next student(empty line to stop):\n");
    }
    
    if (ListIsEmpty(&info))
        printf("No data entered.");
    else
    {
    	printf("Here is  the information:\n");
    	Traverse(&info,showname);
    	Traverse(&info,shownumber);
    	Traverse(&info,showgender);
	}
	printf("You entered %d students' information.\n",ListItemCount(&info));
	
	EmptyTheList(&info)
	printf("Done!\n");
	
	return 0;
}

void showname(Item item)
{
	printf("Enter your name: %s",item.name);
} 

void shownumber(Item item)
{
	printf("Enter your school number: %s",item.number);
}

void showgender(Item item)
{
	printf("Enter your gender(m/w): %s",item.gender);
}


char *s_gets(char *st,int n)
{
	char ret_val;
	char *find;
	
	ret_val=fgets(st,n,stdin);
	if (ret_val)
	{
		find=strchr(st,"\n");
		if (find)
		    *find='\0';
		else
		while(getchar()!='\n')
		     continue;
	}
	return ret_val;
}
