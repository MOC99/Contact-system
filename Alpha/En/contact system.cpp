#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>
#include<conio.h>

char Cover()
{
	printf("**********************************************************************\n");
	printf("*                   ��ӭʹ��ZYXeekerͨѶ¼����ϵͳ                   *\n");
	printf("**********************************************************************\n");
	printf("*>>>>��ѡ��ϵͳ���ܣ�                                                *\n");
	printf("*                         a.ͨѶ��Ϣ¼��                             *\n");
	printf("*                         b.ͨѶ��Ϣ��ʾ                             *\n");	printf("*                         c.ͨѶ��Ϣ����                             *\n");
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
}users[10];

int i = 0;

void Save_user()
{
	if(users[i].num != 0)
		i++;
	scanf("%s %s %s %s",&users[i].num,&users[i].name,&users[i].phone,&users[i].add);
}

void User_printf()
{

	for(i = 1;i<11;i++)
			{
			Image_user();
			printf("%s\n",users[i].num);
			printf("%s\n",users[i].name);
			printf("%s\n",users[i].phone);
			printf("%s\n",users[i].add);
			}
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
    while(t_start < 50)
    {
        if(k_start ==0)
        {
            for(i=0;i<10;i++)
                printf("\n");
            //for(i=0;i<20;i++)
              //  printf(" ");
            printf("ϵͳ�����У����Ժ�");
        }
        delay(5000);
        printf(">");
        delay(5000);
        k_start++;
        if(k_start==50)
            k_start = 0;
		t_start++;
    }
	system("cls");
	Cover();
	i = 1;
	char n_input,n_num[3],num_input[3],name_input[20],phone_input[13]/*,add_input[20]*/;
	int n_del,n_choose,n1_choose;
	while(scanf("%c",&n_input)!=EOF)
	{
		if(n_input == 'a')
		{
			Image_user();
			printf("�밴˳������:\n");
			Save_user();
		}
		if(n_input == 'b')
		{
			FILE *fp;
			if((fp = fopen("my.txt","rb"))!=NULL)
				for(i = 1;i<11;i++)
					fread(&users[i],sizeof(struct User),1,fp);
			User_printf();
		}
		if(n_input == 'c')
		{
			//char ch[]="\r\n";
			FILE *fp;
			fp=fopen("my.txt","wb");
			for(i = 1;i<11;i++)
				fwrite(&users[i],sizeof(struct User),1,fp);
				//fprintf(fp,"\r\n");
			fclose(fp);
			printf("����ɹ���\n");
		} 
		if(n_input == 'd')
		{
			User_printf();
			FILE *fop;
			//fin = fopen("my.txt","rb");
			printf("��Ҫɾ���ĸ�?\n");
			//char str[sizeof(User)];
			printf("����������:\n");
			scanf("%d",&n_del);
			for(i = 1;i<11;i++)
				{
					if(i==n_del)
					{
						//memset(users[i].num,'\0',sizeof(char) * 3);
						memset(users[i].name,'\0',sizeof(char) * 20);
						memset(users[i].phone,'\0',sizeof(char) * 13);
						memset(users[i].add,'\0',sizeof(char) * 20);
					}
				}
			for(i = 1;i<11;i++)
			{
				if(users[i].name[0]=='\0'&&users[i+1].name[0]!='\0')				{
					strcpy(users[i].name,users[i+1].name);
					strcpy(users[i].phone,users[i+1].phone);
					strcpy(users[i].add,users[i+1].add);
				}
				if(users[i].name[0]==users[i+1].name[0])
				{
					strcpy(users[i+1].name,users[i+2].name);
					strcpy(users[i+1].phone,users[i+2].phone);
					strcpy(users[i+1].add,users[i+2].add);
				}
				if(i==4)
				{
					memset(users[i].num,'\0',sizeof(char) * 3);
					memset(users[i].name,'\0',sizeof(char) * 20);
					memset(users[i].phone,'\0',sizeof(char) * 13);
					memset(users[i].add,'\0',sizeof(char) * 20);
				}
			}
			fop=fopen("temp.txt","wb");
			for (i = 1;i<11;i++)
				fwrite(&users[i],sizeof(struct User),1,fop);
			fclose(fop);
			//fclose(fin);
			remove("my.txt");
			rename("temp.txt","my1.txt");
		}
		if(n_input == 'e')
		{
			User_printf();
			printf("��Ҫ�޸��Ǹ���\n");
			printf("�������ţ�\n");
			scanf("%s",&n_num);
			for(i = 1;i<11;i++)
			{
				if(strcmp(users[i].num,n_num)==0)
				{
					printf("��ѡ���޸���Ŀ:\n");
					printf("1.����\n2.�绰\n3.��ַ\n");
				 	scanf("%d",&n_choose);
				 	printf("�������޸ĵĲ���:\n"); 
					if(n_choose==1)
					{
						scanf("%s",&users[i].name);
					}
					if(n_choose==2)
					{
						scanf("%s",&users[i].phone);
					}
					if(n_choose==3)
					{
						scanf("%s",&users[i].add);
					}
				}
			}
			printf("�޸ĳɹ�\n");
		}
		if(n_input == 'f')
		{
			FILE *fp;
			if((fp = fopen("my.txt","rb"))!=NULL)
				for(i = 1;i<11;i++)
					fread(&users[i],sizeof(struct User),1,fp);
			Cover1();
			printf(">>>�����빦�ܱ�ţ�\n");
			scanf("%d",&n1_choose);
			if(n1_choose == 1)
			{
				printf(">>�������ѯ��ţ�\n");
				scanf("%s",&num_input);
				for(i = 1;i<11;i++)
				if(strcmp(users[i].num,num_input)==0)
					printf("%s %s %s\n",users[i].name,users[i].phone,users[i].add);
				
			}
			if(n1_choose == 2)
			{
				scanf("%s",&name_input);
				printf(">>�������ѯ������\n");
				for(i = 1;i<11;i++)
				if(strcmp(users[i].name,name_input)==0)
					printf("%s %s %s\n",users[i].name,users[i].phone,users[i].add);
			}
			if(n1_choose == 3)
			{
				scanf("%s",&phone_input);
				printf(">>�������ѯ�绰���룺\n");
				for(i = 1;i<11;i++)
				if(strcmp(users[i].phone,phone_input)==0)
					printf("%s %s %s\n",users[i].name,users[i].phone,users[i].add);
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

