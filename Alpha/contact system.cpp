/*
	Name: Contact System
	Copyright: 
	Author: ZYXeeker
	Date: 23/07/18 17:00
	Description: 
*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>
#include<conio.h>

char Cover()
{
	printf("**********************************************************************\n");
	printf("*                   欢迎使用ZYXeeker通讯录管理系统                   *\n");
	printf("**********************************************************************\n");
	printf("*>>>>请选择系统功能：                                                *\n");
	printf("*                         a.通讯信息录入                             *\n");
	printf("*                         b.通讯信息显示                             *\n");	
	printf("*                         c.通讯信息保存                             *\n");
	printf("*                         d.通讯信息删除                             *\n");
	printf("*                         e.通讯信息修改                             *\n");
	printf("*                         f.通讯信息查询                             *\n");
	printf("*                         g.退出系统                                 *\n");
	printf("**********************************************************************\n");
	printf(">>>请输入相应功能的代号：\n");
}

char Cover1()
{
	printf("			**********************\n");
	printf("			* 1.按编号查询       *\n");
	printf("			**********************\n");
	printf("			* 2.按姓名查询       *\n");
	printf("			**********************\n");
	printf("			* 3.按电话号码查询   *\n");
	printf("			**********************\n");
}

char Image_user()
{
	printf("************************************\n");
	printf("*     _____      *       编号      *\n");
	printf("*   /       \\    *******************\n");
	printf("*  |         |   *       姓名      *\n");
	printf("*  |         |   *******************\n");
	printf("*   \\ _____ /    *     电话号码    *\n");
	printf("*   /\\ / \\ /\\    *******************\n");
	printf("*  /  \\   /  \\   *       地址      *\n");
	printf("************************************\n");
	
}

struct User{
	char num[3];
	char name[20];
	char phone[13];
	char add[20];
	struct User * next;
};

struct User * head = NULL;
struct User * prev,* current,* tmp;

int i = 0;

void ReadData()
{
	FILE *fin;
	head = current;
	if((fin = fopen("my.txt","rb"))!=NULL)
	{
		tmp = (struct User *)malloc(sizeof(struct User));
		for(;tmp->next != NULL;)
		{
			current = (struct User *)malloc(sizeof(struct User));
			fread(current,sizeof(struct User),1,fin);
			tmp->next = current->next;
			if(head == NULL)
				head = current;
			else
				prev->next = current;
			current->next = NULL;
			prev = current;
		}
	}
	free(tmp);
}

void SaveData()
{
	FILE *fout;
	fout = fopen("my.txt","wb");
	current = head;		
	while(current != NULL)
	{
		fwrite(current,sizeof(struct User),1,fout);
		current = current->next;
	}
	fclose(fout);
	free(current);
	printf("success！\n");
}
void User_printf()
{
	current = head;
	while(current != NULL)
	{
		Image_user();
		printf("%s\n",current->num);
		printf("%s\n",current->name);
		printf("%s\n",current->phone);
		printf("%s\n",current->add);
		current = current->next;	
	}
	free(current);
}

void delay(long int number)
{
    long int i=0,j=0;
    for(i=0;i<number;i++)
        for(j=0;j<number;j++);
}

int main()
{
	int i,k_start,t_start;
    t_start = i = k_start = 0;
    /*while(t_start < 50)
    {
        if(k_start ==0)
        {
            for(i=0;i<10;i++)
                printf("\n");
            //for(i=0;i<20;i++)
              //  printf(" ");
            printf("STRATING,PLEASE WAITING");
        }
        delay(5000);
        printf(">");
        delay(5000);
        k_start++;
        if(k_start==50)
            k_start = 0;
		t_start++;
    }*/
	system("cls");
	Cover();
	i = 1;
	char n_input,n_num[3],num_input[3],name_input[20],phone_input[13],n_del[3];
	int n_choose,n1_choose;
	while(scanf("%c",&n_input)!=EOF)
	{
		if(n_input == 'a')
		{
			int j = 1;
			while(j == 1)
			{
				current = (struct User *)malloc(sizeof(struct User));
				if(head == NULL)
					head = current;
				else
					prev->next = current;
				current->next = NULL;
				Image_user();
				puts("please enter by their location:");
				scanf("%s %s %s %s",&current->num,&current->name,&current->phone,&current->add);
				prev = current;
				puts("Do you want to input next?enter 1 to continue or 0 to exit");
				scanf("%d",&j);
				system("cls");
			}
		}
		if(n_input == 'b')
		{
			ReadData();
			User_printf();
		}
		if(n_input == 'c')
		{
			SaveData();
		} 
		if(n_input == 'd')
		{
			struct User * temp = NULL;
			i = 0;
			int tmp_del,k;
			char a[3];
			ReadData();
			User_printf();
			printf("Which one do want to delete?\n");
			printf("Please input the number:");
			scanf("%s",&n_del);
			current = head;
			for(;strcmp(n_del,current->num)!=0;)
			{
				current = current->next;
				tmp = current;
			}
			if(head == current)
			{
				current = current->next;
				head = current;
				current = NULL;
				i=1;
			}
			if(i != 1)
			{
				sscanf(n_del,"%d",&tmp_del);
				tmp_del = tmp_del - 1;
				sprintf(n_del,"%d",tmp_del);
				if(current->next != NULL)
				{
					current = head;
					for(;strcmp(n_del,current->num) != 0;)
						current = current->next;
					current->next = tmp->next;
				}
				else
				{
					current = head;
					for(;strcmp(n_del,current->num) != 0;)
						current = current->next;
					current->next = NULL;
				}
			}
			current = head;
			i = 1;
			do
			{
				sprintf(current->num,"%d",i);
				i++;
				if(current->next == NULL)
					k = 1;
				else
					k = 0;
				current = current->next;
			}
			while(k != 1);
			SaveData();
		}
		if(n_input == 'e')
		{
			ReadData();
			User_printf();
			printf("Which one do you want to alter?\n");
			printf("Please enter the number:\n");
			scanf("%s",&n_num);
			current = head;
			while(strcmp(n_num,current->num) != 0)
				current = current->next;
			printf("Please choose the number:\n");
			printf("1.name\n2.phone\n3.address\n");
			scanf("%d",&n_choose);
		 	printf("please enter the data:\n"); 
			if(n_choose==1)
				scanf("%s",&current->name);
			if(n_choose==2)
				scanf("%s",&current->phone);
			if(n_choose==3)
				scanf("%s",&current->add);
			printf("Saving...\n");
			SaveData();
		}
		if(n_input == 'f')
		{
			FILE *fp;
			ReadData();
			Cover1();
			printf(">>>Please choose the number:\n");
			scanf("%d",&n1_choose);
			if(n1_choose == 1)
			{
				printf(">>Enter the number:\n");
				scanf("%s",&num_input);
				current = head;
				while(strcmp(num_input,current->num) != 0)
					current = current->next;
				printf("%s %s %s\n",current->name,current->phone,current->add);
				free(current);
			}
			if(n1_choose == 2)
			{
				printf(">>enter name:\n");
				scanf("%s",&name_input);
				current = head;
				while(strcmp(name_input,current->name) != 0)
					current = current->next;
				printf("%s %s %s\n",current->name,current->phone,current->add);
				free(current);
			}
			if(n1_choose == 3)
			{
				printf(">>enter phone:\n");
				scanf("%s",&phone_input);
				while(strcmp(phone_input,current->phone) != 0)
					current = current->next;
				printf("%s %s %s\n",current->name,current->phone,current->add);
				free(current);
			}
		}
		if(n_input == 'g')
			exit(0);
		getchar();
		system("pause");
		system("cls");			 
		Cover();
	}

}
