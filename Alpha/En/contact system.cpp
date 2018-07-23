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
	printf("*                         b.通讯信息显示                             *\n");	printf("*                         c.通讯信息保存                             *\n");
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
            printf("系统启动中，请稍后");
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
			printf("请按顺序输入:\n");
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
			printf("保存成功！\n");
		} 
		if(n_input == 'd')
		{
			User_printf();
			FILE *fop;
			//fin = fopen("my.txt","rb");
			printf("你要删除哪个?\n");
			//char str[sizeof(User)];
			printf("请输入数字:\n");
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
			printf("你要修改那个？\n");
			printf("请输入编号：\n");
			scanf("%s",&n_num);
			for(i = 1;i<11;i++)
			{
				if(strcmp(users[i].num,n_num)==0)
				{
					printf("请选择修改项目:\n");
					printf("1.姓名\n2.电话\n3.地址\n");
				 	scanf("%d",&n_choose);
				 	printf("请输入修改的参数:\n"); 
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
			printf("修改成功\n");
		}
		if(n_input == 'f')
		{
			FILE *fp;
			if((fp = fopen("my.txt","rb"))!=NULL)
				for(i = 1;i<11;i++)
					fread(&users[i],sizeof(struct User),1,fp);
			Cover1();
			printf(">>>请输入功能编号：\n");
			scanf("%d",&n1_choose);
			if(n1_choose == 1)
			{
				printf(">>请输入查询编号：\n");
				scanf("%s",&num_input);
				for(i = 1;i<11;i++)
				if(strcmp(users[i].num,num_input)==0)
					printf("%s %s %s\n",users[i].name,users[i].phone,users[i].add);
				
			}
			if(n1_choose == 2)
			{
				scanf("%s",&name_input);
				printf(">>请输入查询姓名：\n");
				for(i = 1;i<11;i++)
				if(strcmp(users[i].name,name_input)==0)
					printf("%s %s %s\n",users[i].name,users[i].phone,users[i].add);
			}
			if(n1_choose == 3)
			{
				scanf("%s",&phone_input);
				printf(">>请输入查询电话号码：\n");
				for(i = 1;i<11;i++)
				if(strcmp(users[i].phone,phone_input)==0)
					printf("%s %s %s\n",users[i].name,users[i].phone,users[i].add);
			}
		}
		if(n_input == 'g')
			exit(0);
		getchar();
		system("pause");
		system("cls");			//清屏 
		Cover();
	}

}

