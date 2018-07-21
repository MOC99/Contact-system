/*
	Name: Contact System
	Copyright: 
	Author: ZYXeeker
	Date: 21/07/18 10:50
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
	printf("*                   ��ӭʹ��HNIEͨѶ¼����ϵͳ                       *\n");
	printf("**********************************************************************\n");
	printf("*>>>>��ѡ��ϵͳ���ܣ�                                                *\n");
	printf("*                         a.ͨѶ��Ϣ¼��                             *\n");
	printf("*                         b.ͨѶ��Ϣ��ʾ                             *\n");	
	printf("*                         c.ͨѶ��Ϣ����                             *\n");
	printf("*                         d.ͨѶ��Ϣɾ��                             *\n");
	printf("*                         e.ͨѶ��Ϣ�޸�                             *\n");
	printf("*                         f.ͨѶ��Ϣ��ѯ                             *\n");
	printf("*                         g.�˳�ϵͳ                                 *\n");
	printf("**********************************************************************\n");
	printf(">>>��������Ӧ���ܵĴ��ţ�\n");
}

char Cover1()
{
	printf("			**********************\n");
	printf("			* 1.����Ų�ѯ       *\n");
	printf("			**********************\n");
	printf("			* 2.��������ѯ       *\n");
	printf("			**********************\n");
	printf("			* 3.���绰�����ѯ   *\n");
	printf("			**********************\n");
}

char Image_user()
{
	printf("************************************\n");
	printf("*     _____      *       ���      *\n");
	printf("*   /       \\    *******************\n");
	printf("*  |         |   *       ����      *\n");
	printf("*  |         |   *******************\n");
	printf("*   \\ _____ /    *     �绰����    *\n");
	printf("*   /\\ / \\ /\\    *******************\n");
	printf("*  /  \\   /  \\   *       ��ַ      *\n");
	printf("************************************\n");
	
}

struct User{
	char num[3];
	char name[20];
	char phone[13];
	char add[20];
	struct User * next;
}/*users[10]*/;
    struct User * head = NULL;
    struct User * prev,* current;
int i = 0;

/*void Save_user()			//����Save_user()���� 
{
	if(users[i].num != 0)
		i++;
	scanf("%s %s %s %s",&users[i].num,&users[i].name,&users[i].phone,&users[i].add);
}
*/
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
		//	Save_user();
		}
		if(n_input == 'b')
		{
			FILE *fp;
			if((fp = fopen("my.txt","rb"))!=NULL)
				while(current == NULL)
				{
					current = (struct User*)malloc(sizeof(struct User));
					fread(current,sizeof(struct User),1,fp);
					if(head = NULL)
						head = current;
					else
					current->next = NULL;
					//prev->next = current;
					prev = current;
				}
			free(current);
			User_printf();
		}
		if(n_input == 'c')
		{
			//char ch[]="\r\n";
			FILE *fp;
			fp=fopen("my.txt","wb");
			current = head;
			while(current != NULL)
			{
				fwrite(current,sizeof(struct User),1,fp);
				current = current->next;
			}
			//fprintf(fp,"\r\n");
			fclose(fp);
			free(current);
			printf("success��\n");
		} 
		if(n_input == 'd')
		{
			struct User * temp = NULL;
			char a[3];
			User_printf();
			FILE *out;
			//fin = fopen("my.txt","rb");
			printf("Which one do want to delete?\n");
			//char str[sizeof(User)];
			printf("Please input the number:\n");
			scanf("%s",&n_del);
			current = head;
			for(;strcmp(n_del,current->num)!=0;)
				current = current->next;
			temp = current->next;
			free(current);
			current = head;
			while(strcmp(n_del,current->num)>0)
				current = current->next;
			current->next = temp;
			free(temp);
			current = head;
			while(current->next == NULL)
			{
				for(i = 1;;i++)
					sprintf(current->num,"success",i);
				current = current->next;
			}
			out = fopen("temp.txt","wb");
			current = head;
			while(current != NULL)
			{
				fwrite(current,sizeof(struct User),1,out);
				current = current->next;
			}
			fclose(out);
			remove("my.txt");
			//rename("temp.txt","my1.txt");
		}
		if(n_input == 'e')
		{
			User_printf();
			printf("Which one do you want to alter?\n");
			printf("Please enter the number:\n");
			scanf("%s",&n_num);
			current = head;
			while(strcmp(n_del,current->num)!=0)
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
			printf("success\n");
			free(current);
		}
		if(n_input == 'f')
		{
			FILE *fp;
			if((fp = fopen("my.txt","rb"))!=NULL)
				
					fread(current,sizeof(struct User),1,fp);
			Cover1();
			printf(">>>Please choose the number:\n");
			scanf("%d",&n1_choose);
			if(n1_choose == 1)
			{
				printf(">>Enter the number:\n");
				scanf("%s",&num_input);
				current = head;
				while(strcmp(n_del,current->num)!=0)
					current = current->next;
				printf("%s %s %s\n",current->name,current->phone,current->add);
				free(current);
			}
			if(n1_choose == 2)
			{
				printf(">>enter name:\n");
				scanf("%s",&name_input);
				current = head;
				while(strcmp(name_input,current->name)!=0)
					current = current->next;
				printf("%s %s %s\n",current->name,current->phone,current->add);
				free(current);
			}
			if(n1_choose == 3)
			{
				printf(">>enter phone:\n");
				scanf("%s",&phone_input);
				while(strcmp(name_input,current->name)!=0)
					current = current->next;
				printf("%s %s %s\n",current->name,current->phone,current->add);
				free(current);
			}
		}
		if(n_input == 'g')
			exit(0);
		getchar();
		system("pause");
		system("cls");			//���� 
		Cover();
	}

}

