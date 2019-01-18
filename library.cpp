#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define N 100

void ME1Main(int a);
int MEMain(int a);
int Cnt (struct library a[]);


struct library
{
	char find_num[20];//索书号
	char bar_code[14];//图书条形码
	char book_name[20];//书名
	char wirter_name[20];//作者名字
	char press[22];//出版社
	char time[10];//出版时间
	char price[10];//定价
	int canborrow;//可借数量
	int have;//藏书量

	int hot;//浏览量
	int news;//新度
};

struct library x[N];


void MENU(int a)//主菜单
{
	printf("                 /\\        /\\      \n");
	printf("          　　　//\\\\      //\\\\　　 \n");
	printf("          　　 /　 \\\\    //   \\    \n");
	printf("          (1)     　\\\\  //       (2) \n");
	printf("          管　　     \\\\//        用 \n");
	printf("          理　    　.-'^'-.      户 \n");
	printf("          系    　.' a___a `.    系 \n");
	printf("          统     ==　(___)　==   统 \n");
	printf("          　　　　'. ._I_. .'       \n");
	printf("          　　    /.`-----'.\\   \n");
	printf("          [###(__)#### [###(__)####]\n");


}

void MENU1(int a)//管理菜单
{	
	system("cls");
	printf("**************************************************************\n");
	printf("          .-._    ****************管理系统v1.0*************\n"); 
	printf("         {_}^ )o  ********************************************\n");
	printf("{\\________//~`    *(1)图书信息浏览          (2)图书信息排序***\n");
	printf(" (         )      *(3)图书信息查询          (4)图书信息修改***\n");
	printf(" /||~~~~~||\\      *(5)图书信息添加          (6)图书信息删除***\n");
	printf("|_\\\\_    \\\\_\\_    *(7)用户系统查看          (8)关于我和某某***\n");
	printf("\"\' \"\"\'    \"\"\'\"\'   ********************************************\n");
	printf("**************************************************************\n");
	printf("*******************************(0)返回主界面******************\n");
	printf("**************************************************************\n");
}

void MENU2(int b)//用户菜单
{
		printf("	***********************************************************\n");
		printf("	************************用户系统v1.0*********************\n");
		printf("	*********(1)图书信息浏览           (2)热度图书推荐*********\n");
		printf("	*********(3)图书信息查询           (4)关于我和某某*********\n");
		printf("	***********************************************************\n");
		printf("	***********************************************************\n");
		printf("	*************************************(0)返回主界面*********\n");
		printf("	***********************************************************\n");


}

void xxx(int a)
{
	printf("                  ◢＼　  ☆　   ／◣     \n");
	printf("          　  　∕　　﹨　╰╮   ∕ 　﹨       \n");
	printf("          　  　▏　　～～′′～～ 　｜      \n");
	printf("          　　  ﹨／　　　　　　 　＼∕      \n");
	printf("          　 　 ∕ 　　●　　　 ●　＼       \n");
	printf("            ＝＝　○　∴·╰╯　∴　○　＝＝ \n");
	printf("          　   ╭───╮　　     　╭───╮   \n");
//	printf("            ╔═ ∪∪∪═输入密码═∪∪∪═╗\n");
//	printf("                     :");

}

char * mimaxiugai(char a[])
{
	char c1[20];
	char c2[20];
	char c3[20];
	for(int l=0;l<3;l++)
	{
		printf("\t\t输入原密码：");
		scanf("%s",c1);
		
		printf("\t\t输入新密码：");
		scanf("%s",c2);
		
		printf("\t\t确认新密码：");
		scanf("%s",c3);

		if(strcmp(a,c1)==0&&strcmp(c2,c3)==0)
		{
			strcpy(a,c2);
			printf("密码修改成功\n");break;
		}
		
	}
	return a;
}

void mima (int a)//密码系统
{
	char log_mima[20];
	char mima_store[20];
	char temp[3]="xg";
	
	FILE *mp;
	mp=fopen("mimaben.dat","rb");

	fscanf(mp,"%s",mima_store);

	fclose(mp);

	
	xxx(1);
	printf("            ╔═ ∪∪∪═输入密码═∪∪∪═╗\n");
	printf("                     :");
	for(int i=0;i<3;i++)
	{
		
		scanf("%s",&log_mima);
		system("cls");
		if(strcmp(log_mima,temp)==0)
		{
			strcpy(mima_store,mimaxiugai(mima_store));
			fopen("mimaben.dat","wb+");
			fprintf(mp,"%s",mima_store);
			fclose(mp);
			break;
		}
		if(strcmp(log_mima,mima_store)!=0)
		{
			xxx(1);
			printf("            ╔═ ∪∪∪═密码错误═∪∪∪═╗\n");
			printf("     您还有%d次机会！:",2-i);
			scanf("\r");
			system("cls");
			
		}
		else
			ME1Main(1);
	//	system("cls");
		if(i==2)
			printf("请按回车键退出");
		
	}
}

int Cnt (struct library a[])//计数
{
	FILE *fp;
	fp=fopen("library.dat","r");
	if(fp==NULL)
	{
		printf("can not open the library.dat\n");
		exit(1);
	}
	int i=0;
	do
	{
		fscanf(fp,"%s%s%s%s%s%s%s%d%d\n",a[i].find_num,a[i].bar_code,a[i].book_name,a[i].wirter_name,a[i].press,a[i].time,a[i].price,&a[i].canborrow,&a[i].have);
		i++;
	}while(!feof(fp));
	return (i);
}

void paixu(struct library a[])//排序
{

	int cnt;
	cnt=Cnt(x);

	FILE *fp;
	fp=fopen("library.dat","rb");
	int m;
	for(m=0;m<cnt;m++)
	    fscanf(fp,"%s%s%s%s%s%s%s%d%d\n",a[m].find_num,a[m].bar_code,a[m].book_name,a[m].wirter_name,a[m].press,a[m].time,a[m].price,&a[m].canborrow,&a[m].have);
	fclose(fp);
	struct library temp;
	int i,j;
    system("cls");
	printf("\n**********按可借量排序***********\n");
    for(i=0;i<cnt-1;i++)
	    for(j=0;j<cnt-i-1;j++)
		    if(a[j].canborrow>a[j+1].canborrow)
			{
		        temp=a[j];
		        a[j]=a[j+1];
		        a[j+1]=temp;
			}

    printf("    索书号    图书条形码                书名          作者名字                出版社     出版时间      定价\t可借数量\t藏书量\t\n");
    for(i=0;i<cnt;i++)
    printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",a[i].find_num,a[i].bar_code,a[i].book_name,a[i].wirter_name,a[i].press,a[i].time,a[i].price,a[i].canborrow,a[i].have);
	printf("按任意键返回主菜单\n");

	FILE *tp;
	tp=fopen("library.dat","ab+");
	for(m=0;m<cnt;m++)
		fprintf(tp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",a[m].find_num,a[m].bar_code,a[m].book_name,a[m].press,a[m].time,a[m].price,a[m].canborrow,a[m].have);
	fclose(tp);
}

void Browse (struct library a[])//浏览
{
	int cnt;
	cnt=Cnt(x);

	memset(a,0,(sizeof(struct library)*cnt));
	FILE *fp;
	fp=fopen("library.dat","rb");
	if(fp==NULL)
	{
		printf("can not open the library.dat\n");
		exit(1);
	}

	printf("    索书号    图书条形码                书名          作者名字                出版社     出版时间      定价\t可借数量\t藏书量\t\n");
	int i=0;
	do
	{
		fscanf(fp,"%s%s%s%s%s%s%s%d%d\n",a[i].find_num,a[i].bar_code,a[i].book_name,a[i].wirter_name,a[i].press,a[i].time,a[i].price,&a[i].canborrow,&a[i].have);
		printf("\n");
		printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",a[i].find_num,a[i].bar_code,a[i].book_name,a[i].wirter_name,a[i].press,a[i].time,a[i].price,a[i].canborrow,a[i].have);
		i++;
	}while(!feof(fp));
	printf("\n                                                            总藏书量%d\n",i);
	
}

void Find()   //查询
{

	int cnt;
	cnt=Cnt(x);
	struct library c[N];
	int i=0,k=0;
	int x,m=1;
    char name[20];
	char j;
    
	FILE *fp;
	fp=fopen("library.dat","rb");

	for(int o=0;o<cnt;o++)
		{
			fscanf(fp,"%s%s%s%s%s%s%s%d%d",c[o].find_num,c[o].bar_code,c[o].book_name,c[o].wirter_name,c[o].press,c[o].time,c[o].price,&c[o].canborrow,&c[o].have);
		}
	while(m==1)
	{
	printf("1:按照索书号查询\n");
	printf("2:按照图书条形码查询\n");
	printf("3:按照书名查询\n");
	printf("4:按照作者查询\n");
	printf("5:按照出版社查询\n");
	
	printf("选择查询方式");
	getchar();
	scanf("%d",&x);

	while(x==3)
	{
		printf("请输入您要查找的图书的书名：");  
        scanf("%s",&name); 
	    printf("\n"); 
   	    do
	    {  
			    if(strcmp(name,c[i].book_name)==0)
			    {
			    	printf("    索书号    图书条形码                书名          作者名字                出版社     出版时间      定价\t可借数量\t藏书量\t\n"); 
			    	printf("\n");
			    	printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",c[i].find_num,c[i].bar_code,c[i].book_name,c[i].wirter_name,c[i].press,c[i].time,c[i].price,c[i].canborrow,c[i].have); 
			    	k++;
					c[i].hot++;
			    	break;
		    	}
		    	i++;
		    }while(i<cnt);
	    	printf("                                                                总共找到%d本\n",k);
			
			printf("返回上一级请按【Y】\n");
				printf("继续按书名查询请按【o】!\n");
				getchar();
				scanf("%c",&j);
				if(j!='Y'&&j!='y')
				{
					x=1;
					break;
				}
				else
				{
					system("cls");
					printf("返回上一级请按【Y】\n");
					printf("继续查询请按【o】!\n");
					getchar();
					scanf("%c",&j);
					if(j=='Y'&&j=='y')
					{
						x=0;
						break;
					}
					else
					{
						system("cls");
						printf("返回主界面双击回车\n");
						printf("继续查询请按【o】!\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'&&j=='y')
						{
							fflush(stdin);
							getchar();
							system("cls");
						}
					}
				}
			break;
	}
	while(x==2)
	{
		printf("请输入您要查找的图书的条形码：");  
        scanf("%s",&name); 
	    printf("\n"); 
   	    do
	    {  
			    if(strcmp(name,c[i].bar_code)==0)
			    {
			    	printf("    索书号    图书条形码                书名          作者名字                出版社     出版时间      定价\t可借数量\t藏书量\t\n"); 
			    	printf("\n");
			    	printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",c[i].find_num,c[i].bar_code,c[i].book_name,c[i].wirter_name,c[i].press,c[i].time,c[i].price,c[i].canborrow,c[i].have); 
			    	k++;c[i].hot++;
			    	break;
		    	}
		    	i++;
		    }while(i<cnt);
	    	printf("                                                                总共找到%d本\n",k);
			
			printf("返回上一级请按【Y】\n");
				printf("继续按图书的条形码查询请按【o】!\n");
				getchar();
				scanf("%c",&j);
				if(j!='Y'&&j!='y')
				{
					x=1;
					break;
				}
				else
				{
					system("cls");
					printf("返回上一级请按【Y】\n");
					printf("继续查询请按【o】!\n");
					getchar();
					scanf("%c",&j);
					if(j=='Y'&&j=='y')
					{
						x=0;
						break;
					}
					else
					{
						system("cls");
						printf("返回主界面双击回车\n");
						printf("继续查询请按【o】!\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'&&j=='y')
						{
							fflush(stdin);
							getchar();
							system("cls");
						}
					}
				}
			break;
	}
	while(x==1)
	{
		printf("请输入您要查找的图书的索书号：");  
        scanf("%s",&name); 
	    printf("\n"); 
   	    do
	    {  
			    if(strcmp(name,c[i].find_num)==0)
			    {
			    	printf("    索书号    图书条形码                书名          作者名字                出版社     出版时间      定价\t可借数量\t藏书量\t\n"); 
			    	printf("\n");
			    	printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",c[i].find_num,c[i].bar_code,c[i].book_name,c[i].wirter_name,c[i].press,c[i].time,c[i].price,c[i].canborrow,c[i].have); 
			    	k++;c[i].hot++;
			    	break;
		    	}
		    	i++;
		    }while(i<cnt);
	    	printf("                                                                总共找到%d本\n",k);
			
				printf("返回上一级请按【Y】\n");
				printf("继续按索书号查询请按【o】!\n");
				getchar();
				scanf("%c",&j);
				if(j!='Y'&&j!='y')
				{
					x=1;
			//		break;
				}
				else
				{
					system("cls");
					printf("返回上一级请按【Y】\n");
					printf("继续查询请按【o】!\n");
					getchar();
					scanf("%c",&j);
					if(j=='Y'&&j=='y')
					{
						x=0;
						break;
					}
					else
					{
						system("cls");
					//	choose=2;
						break;
					}
				}
				system("cls");
			//	break;	
	}
	while(x==4)
	{
		printf("请输入您要查找的图书的作者：");  
        scanf("%s",&name); 
	    printf("\n"); 
   	    do
	    {  
			    if(strcmp(name,c[i].wirter_name)==0)
			    {
			    	printf("    索书号    图书条形码                书名          作者名字                出版社     出版时间      定价\t可借数量\t藏书量\t\n"); 
			    	printf("\n");
			    	printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",c[i].find_num,c[i].bar_code,c[i].book_name,c[i].wirter_name,c[i].press,c[i].time,c[i].price,c[i].canborrow,c[i].have); 
			    	k++;c[i].hot++;
			    	break;
		    	}
		    	i++;
		    }while(i<cnt);
	    	printf("                                                                总共找到%d本\n",k);
			
			printf("返回上一级请按【Y】\n");
				printf("继续按图书的作者查询请按【o】!\n");
				getchar();
				scanf("%c",&j);
				if(j!='Y'&&j!='y')
				{
					x=1;
					break;
				}
				else
				{
					system("cls");
					printf("返回上一级请按【Y】\n");
					printf("继续查询请按【o】!\n");
					getchar();
					scanf("%c",&j);
					if(j=='Y'&&j=='y')
					{
						x=0;
						break;
					}
					else
					{
						system("cls");
						printf("返回主界面双击回车\n");
						printf("继续查询请按【o】!\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'&&j=='y')
						{
							fflush(stdin);
							getchar();
							system("cls");
						}
					}
				}
				break;
	}
	while(x==5)
	{
		printf("请输入您要查找的图书的出版社：");  
        scanf("%s",&name); 
	    printf("\n"); 
   	    do
	    {  
			    if(strcmp(name,c[i].press)==0)
			    {
			    	printf("    索书号    图书条形码                书名          作者名字                出版社     出版时间      定价\t可借数量\t藏书量\t\n"); 
			    	printf("\n");
			    	printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",c[i].find_num,c[i].bar_code,c[i].book_name,c[i].wirter_name,c[i].press,c[i].time,c[i].price,c[i].canborrow,c[i].have); 
			    	k++;c[i].hot++;
			    	break;
		    	}
		    	i++;
		    }while(i<cnt);
	    	printf("                                                                总共找到%d本\n",k);
			
			printf("返回上一级请按【Y】\n");
				printf("继续按图书的出版社查询请按【o】!\n");
				getchar();
				scanf("%c",&j);
				if(j!='Y'&&j!='y')
				{
					x=1;
					break;
				}
				else
				{
					system("cls");
					printf("返回上一级请按【Y】\n");
					printf("继续查询请按【o】!\n");
					getchar();
					scanf("%c",&j);
					if(j=='Y'&&j=='y')
					{
						x=0;
						break;
					}
					else
					{
						system("cls");
						printf("返回主界面双击回车\n");
						printf("继续查询请按【o】!\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'&&j=='y')
						{
							fflush(stdin);
							getchar();
							system("cls");
						}
					}
				}
				break;
	}
break;
}

}  

void Change(struct library c[])//修改
{

	int cnt;
	cnt=Cnt(x);

	char ISBN[14];
	char j;
	int i=0;
	int m=1,n=1,k=1;
	int v=2147483647;

	FILE *fp;
	

	while(m==1)
	{
		fp=fopen("library.dat","rb");
		for(int o=0;o<cnt;o++)
		{
			fscanf(fp,"%s%s%s%s%s%s%s%d%d",c[o].find_num,c[o].bar_code,c[o].book_name,c[o].wirter_name,c[o].press,c[o].time,c[o].price,&c[o].canborrow,&c[o].have);
		}
		printf("请输入您要修改的图书的ISBN：");  
		scanf("%s",&ISBN); 
		
		do
		{
			
			if(strcmp(ISBN,c[i].bar_code)==0)
			{
				printf("    索书号    图书条形码                书名          作者名字                出版社     出版时间      定价\t可借数量\t藏书量\t\n"); 
				printf("\n");
				printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",c[i].find_num,c[i].bar_code,c[i].book_name,c[i].wirter_name,c[i].press,c[i].time,c[i].price,c[i].canborrow,c[i].have); 
				v=i;
				break;
			}
			i++;
		}while(i<cnt);

		fclose(fp);
		if(v!=2147483647)
		{
			printf("确认修改此图书信息！！？？\n");
			printf(" 【Y】  or  【N】      \n");
			getchar();
			scanf("%c",&j);
			while(j=='Y'||j=='y')
			{
				fp=fopen("library.dat","wb+");
				for(i=0;i<cnt;i++)
					if(i!=v)
						fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[i].find_num,c[i].bar_code,c[i].book_name,c[i].wirter_name,c[i].press,c[i].time,c[i].price,c[i].canborrow,c[i].have);
				fclose(fp);

				while(n==1)
				{
					char xian[22];
					printf("请选择您要修改的内容\n");
					printf("(1)索书号\n(2)图书条形码\n(3)书名\n(4)作者名字\n(5)出版社\n(6)出版时间\n(7)定价\n");
					getchar();
					scanf("%d",&k);
					while(k==1)
					{
						system("cls");
						printf("原索书号:%s\n",c[v].find_num);
						printf("现索书号:");
						scanf("%s",xian);
						printf("\n");
						printf("确认修改此信息请按【y】\n");
						printf("按任意键重新输入\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",xian,c[v].bar_code,c[v].book_name,c[v].wirter_name,c[v].press,c[v].time,c[v].price,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("修改其他信息请按【y】\n");
							printf("返回上一级请按回车键\n");
							getchar();
							scanf("%c",&j);
							if(j=='Y'||j=='y')
							{
								k=0;
								break;
							}
							else
							{
								k=0;
								n=0;
								break;
							}
						}
					}while(k==2)
					{
						system("cls");
						printf("原图书条形码:%s\n",c[v].bar_code);
						printf("现图书条形码:");
						scanf("%s",xian);
						printf("\n");
						printf("确认修改此信息请按【y】\n");
						printf("按任意键重新输入\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[v].find_num,xian,c[v].book_name,c[v].wirter_name,c[v].press,c[v].time,c[v].price,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("修改其他信息请按【y】\n");
							printf("返回上一级请按回车键\n");
							getchar();
							scanf("%c",&j);
							if(j=='Y'||j=='y')
							{
								k=0;
								break;
							}
							else
							{
								k=0;
								n=0;
								break;
							}
						}
					}while(k==3)
					{
						system("cls");
						printf("原书名:%s\n",c[v].book_name);
						printf("现书名:");
						scanf("%s",xian);
						printf("\n");
						printf("确认修改此信息请按【y】\n");
						printf("按任意键重新输入\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[v].find_num,c[v].bar_code,xian,c[v].wirter_name,c[v].press,c[v].time,c[v].price,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("修改其他信息请按【y】\n");
							printf("返回上一级请按回车键\n");
							getchar();
							scanf("%c",&j);
							if(j=='Y'||j=='y')
							{
								k=0;
								break;
							}
							else
							{
								k=0;
								n=0;
								break;
							}
						}
					}while(k==4)
					{
						system("cls");
						printf("原作者:%s\n",c[v].wirter_name);
						printf("现作者:");
						scanf("%s",xian);
						printf("\n");
						printf("确认修改此信息请按【y】\n");
						printf("按任意键重新输入\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[v].find_num,c[v].bar_code,c[v].book_name,xian,c[v].press,c[v].time,c[v].price,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("修改其他信息请按【y】\n");
							printf("返回上一级请按回车键\n");
							getchar();
							scanf("%c",&j);
							if(j=='Y'||j=='y')
							{
								k=0;
								break;
							}
							else
							{
								k=0;
								n=0;
								break;
							}
						}
					}while(k==5)
					{
						system("cls");
						printf("原出版社:%s\n",c[v].press);
						printf("现出版社:");
						scanf("%s",xian);
						printf("\n");
						printf("确认修改此信息请按【y】\n");
						printf("按任意键重新输入\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[v].find_num,c[v].bar_code,c[v].book_name,c[v].wirter_name,xian,c[v].time,c[v].price,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("修改其他信息请按【y】\n");
							printf("返回上一级请按回车键\n");
							getchar();
							scanf("%c",&j);
							if(j=='Y'||j=='y')
							{
								k=0;
								break;
							}
							else
							{
								k=0;
								n=0;
								break;
							}
						}
					}while(k==6)
					{
						system("cls");
						printf("原出版日期:%s\n",c[v].time);
						printf("现出版日期:");
						scanf("%s",xian);
						printf("\n");
						printf("确认修改此信息请按【y】\n");
						printf("按任意键重新输入\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[v].find_num,c[v].bar_code,c[v].book_name,c[v].wirter_name,c[v].press,xian,c[v].price,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("修改其他信息请按【y】\n");
							printf("返回上一级请按回车键\n");
							getchar();
							scanf("%c",&j);
							if(j=='Y'||j=='y')
							{
								k=0;
								break;
							}
							else
							{
								k=0;
								n=0;
								break;
							}
						}
					}while(k==7)
					{
						system("cls");
						printf("原价格:%s\n",c[v].price);
						printf("现价格:");
						scanf("%s",xian);
						printf("\n");
						printf("确认修改此信息请按【y】\n");
						printf("按任意键重新输入\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[v].find_num,c[v].bar_code,c[v].book_name,c[v].wirter_name,c[v].press,c[v].time,xian,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("修改其他信息请按【y】\n");
							printf("返回上一级请按回车键\n");
							getchar();
							scanf("%c",&j);
							if(j=='Y'||j=='y')
							{
								k=0;
								break;
							}
							else
							{
								k=0;
								n=0;
								break;
							}
						}
					}break;
				}
			}					
	/*		while(j!='Y'&&j!='y')                             功能有些问题
			{
				system("cls");
				printf("修改其他图书信息，请按【Y】\n");
				printf("返回主界面，请按回车键两次！\n");
				scanf("%c",&j);
				if(j=='Y'||j=='y')
				{
					
					system("cls");

				}
				else
				{
					system("cls");
					m=2;
					break;
				}
			}*/
		}
		if(v==2147483647)
		{
			printf("无此书信息！！\n");
			printf("修改其他图书信息，请按【Y】\n");
			printf("返回主界面，请按回车键两次！\n");
			getchar();
			scanf("%c",&j);
			if(j=='Y'||j=='y')
			{
				system("cls");
			}
			else
			{
				break;
			}
		}
		break;
	}
}

void Add(struct library a[])//添加
{
	struct library c[N];
	char j;
	int m=1,k=0;             
	int i,q=1;

	FILE *fp,*mp;
	fp=fopen("library.dat","ab+");
	mp=fopen("library.dat","rb");
	
	while(m==1)
	for(i=0;i<N;i++)
	{
		for(int o=0;o<N;o++)
	{	
		fscanf(mp,"%s%s%s%s%s%s%s%d%d",c[o].find_num,c[o].bar_code,c[o].book_name,c[o].wirter_name,c[o].press,c[o].time,c[o].price,&c[o].canborrow,&c[o].have);}
		printf("添加第%d个书籍信息\n",k+1);
		printf("索书号:");
		scanf("%s",a[i].find_num);
	    printf("图书条形码:");
		scanf("%s",a[i].bar_code);
		getchar();
        for(int x=0;x<N+k;x++)
			if(strcmp(a[i].bar_code,c[x].bar_code)==0)
				q=0;
        if(q==1)
		{
	        printf("书名:");
			scanf("%s",a[i].book_name);

			printf("作者名字:");
			scanf("%s",a[i].wirter_name);

			printf("出版社:");
			scanf("%s",a[i].press);
	
			printf("出版时间:");
			scanf("%s",a[i].time);

			printf("定价:");
			scanf("%s",a[i].price);

			printf("可借数量:");
			scanf("%d",&a[i].canborrow);

			printf("藏书量:");
			scanf("%d",&a[i].have);

	        printf("确认添加信息请按【Y】\n");
	        printf("重新输入请按【n】\n");
			printf("返回主界面请按y、n除外任意键\n");
			getchar();
	        scanf("%c",&j);
	        if(j=='Y'||j=='y')
			{
				system("cls");
		        fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",a[i].find_num,a[i].bar_code,a[i].book_name,a[i].wirter_name,a[i].press,a[i].time,a[i].price,a[i].canborrow,a[i].have);
		        printf("\t\t信息添加成功！\n");
				fclose(fp);
				fp=fopen("library.dat","ab+");
				k++;
				printf("继续输入请按【Y】\n");
				printf("退出按任意键!\n");
				getchar();
				scanf("%c",&j);
				if(j=='Y'||j=='y')
				{
					system("cls");
					break;
				}
				else
				{
					m=2;
					i=N+1;
					break;
				}
			}
			else if(j=='n'||j=='N')
			{
				m=1;
				system("cls");
				break;
			}
			else
			{
				m=2;
				i=N+1;
				break;
			}
		
			printf("\n继续输入请按【Y】\n");
			printf("\n(否则按任意键退出!)\n");
			scanf("%c",&j);
			if(j=='Y'||j=='y')
				m=1;
			else
				break;
		}
		else 
		{
			printf("该图书信息已存在！\n");
			printf("继续输入请按【Y】\n");
			printf("按两下任意键退出!\n");
			j=getchar();
			if(j=='Y'||j=='y')
			{
				system("cls");
				m=1;
			}
			else
			{	m=2;
				break;
			}
		}
	}
	fclose(mp);
	fclose(fp);
}

void Delete()     //删除
{
	struct library b;
	struct library c[N];

	int cnt;
	cnt=Cnt(x);
	int m=1,q=1;
	char j;
	int i,v;

	FILE *fp,*mp;
	mp=fopen("library.dat","r");

	while(m==1)
	{
		printf("请输入需要删除图书的ISBN: \n");
		scanf("%s",b.bar_code);;

		for(int o=0;o<cnt;o++)
		{
			fscanf(mp,"%s%s%s%s%s%s%s%d%d",c[o].find_num,c[o].bar_code,c[o].book_name,c[o].wirter_name,c[o].press,c[o].time,c[o].price,&c[o].canborrow,&c[o].have);
		}
		for(int x=0;x<cnt;x++)
			while(strcmp(b.bar_code,c[x].bar_code)==0)
			{
				q=0;;
				v=x;
				break;
			}
		if(q==1)
		{
			printf("抱歉！未找到此图书信息\n");
			printf("重新输入请按【y】\n");
			printf("按两次回车键返回！\n");
			getchar();
			scanf("%c",&j);
			if(j=='Y'||j=='y')
				system("cls");
			else
			{
				m=2;
				break;
			}


			
		}
		else
		{
			printf("    索书号    图书条形码                书名          作者名字                出版社     出版时间      定价\t可借数量\t藏书量\t\n");
			printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",c[v].find_num,c[v].bar_code,c[v].book_name,c[v].wirter_name,c[v].press,c[v].time,c[v].price,c[v].canborrow,c[v].have);
			printf("确认删除此图书信息！！？？\n");
			printf(" 【Y】  or  【N】      \n");
			getchar();
			scanf("%c",&j);
			while(j=='Y'||j=='y')
			{
				fp=fopen("library.dat","wb+");

				for(i=0;i<cnt;i++)
					if(i!=v)
						fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[i].find_num,c[i].bar_code,c[i].book_name,c[i].wirter_name,c[i].press,c[i].time,c[i].price,c[i].canborrow,c[i].have);
				fclose(fp);
				system("cls");
				
				j='j';
			}
			while(j!='Y'&&j!='y')
			{
				system("cls");
				printf("删除成功！！\n");
				printf("删除其他图书信息，请按【Y】\n");
				printf("返回主界面，请按回车键两次！\n");
				getchar();
				scanf("%c",&j);
				if(j=='Y'||j=='y')
				{
					system("cls");
					break;
				}
				else
				{
					m=2;
					break;
				}
			}	
		}	
	}	
	fclose(mp);
}

void paixu2(struct library a[])//热度
{

	int cnt;
	cnt=Cnt(x);

	FILE *fp;
	fp=fopen("library.dat","rb");
	int m;
	for(m=0;m<cnt;m++)
	    fscanf(fp,"%s%s%s%s%s%s%s%d%d%d\n",a[m].find_num,a[m].bar_code,a[m].book_name,
		a[m].wirter_name,a[m].press,a[m].time,a[m].price,&a[m].canborrow,&a[m].have,&a[m].hot);
	fclose(fp);
	struct library temp;
	int i,j;
    system("cls");
	printf("\n**********图书推荐***********\n");
    for(i=0;i<cnt-1;i++)
	    for(j=0;j<cnt-i-1;j++)
		    if(a[j].hot<a[j+1].hot)
			{
		        temp=a[j];
		        a[j]=a[j+1];
		        a[j+1]=temp;
			}

    printf("    索书号    图书条形码                书名          作者名字                出版社     出版时间      定价\t可借数量\t藏书量\t热度\n");
    for(i=0;i<cnt;i++)
    printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t%d\n",a[i].find_num,a[i].bar_code,a[i].book_name,a[i].wirter_name,a[i].press,a[i].time,a[i].price,a[i].canborrow,a[i].have,a[i].hot);
	printf("按任意键返回主菜单\n");

	FILE *tp;
	tp=fopen("library.dat","ab+");
	for(m=0;m<cnt;m++)
	fprintf(tp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",a[m].find_num,a[m].bar_code,a[m].book_name,a[m].press,a[m].time,a[m].price,a[m].canborrow,a[m].have,a[m].hot);
	fclose(tp);
}

void GD2()
{
    char str[] = "我们几个不仅仅是程序猿，还是单身狗哦这是我们的QQ，1 7 1 7 3 9 4 9 1 ，1 2 8 6 8 8 2 0 9  2 ，2 0 6 1 4 3 1 6 3 6 ，2 6 4 4 6 9 6 7 2 9  ，2 4 5 1 3 7 8 5 8 7 ，1 4 1 3 4 0 4 3 2 9 ，加我们哦，";
    int i,j;
	for(int t=0;t<3;t++)
	{
		for(i=0;i<strlen(str);i+=2)
		{
			system("cls");
			printf("\t\t");
			for(j=i;j<strlen(str);j+=2)
			{
				printf("%c%c",str[j],str[j+1]);
			}
			Sleep(100);
			printf("\n");
		}
	}
}

void GD1()
{
    char str[] = "此系统是我们几个人的努力下而成，问题自然会有，这是我支付宝账号1 3 1 4 0 0 2 5 8 0 7 ，您的捐赠是对我们的支持";
    int i,j;
	for(int t=0;t<3;t++)
	{
		for(i=0;i<strlen(str);i+=2)
		{
		//	system("cls");
			printf("\t\t");
			for(j=i;j<strlen(str);j+=2)
			{
				printf("%c%c",str[j],str[j+1]);
			}
			Sleep(100);
			printf("\n");
		}
	}
}


void About(int a)//关于我和某某
{
	if(a==1)
	{
		char x;
		printf("你的性别是boy还是gril?(b/g)\n");
		x=getchar();
		scanf("%c",&x);
		if(x=='b')
		{GD1();}
		else
		{GD2();}
	}
}

void ME2Function(int c)//用户菜单功能
{
	while(c==1)
	{
		Browse(x);
		printf("按任意键返回上一级\n");break;
	}
	while(c==2)
	{
		paixu2(x);
		printf("按任意键返回上一级\n");break;
	}
	while(c==3)
	{
		Find();
		printf("按任意键返回上一级\n");
		break;
	}
	while(c==4)
	{
		About(1);
		printf("按任意键返回上一级\n");break;
	}
	while(c==5)
	{
		printf("返回主界面\n");
		system("cls");
		MEMain(1);
		break;
	}

}

int ME2Main(int d)//用户菜单主程序
{
	int choose,xuan;
	while(d==7)
	{
		MENU2(1);
		printf("\n	\t\t\t==>请选择操作：");
		scanf("%d",&choose);
		system("cls");
	
		switch(choose)
		{
			case 1:xuan=1;break;
			case 2:xuan=2;break;
			case 3:xuan=3;break;
			case 4:xuan=4;break;
			case 0:xuan=5;break;
			default :printf("错误!错误!错误!\n按任意键返回，重新输入：");break;
		}
		ME2Function(xuan);
		fflush(stdin);
		getchar();
		system("cls");
	}
	return 0;
}




void ME1Function(int a)//管理菜单功能
{
	while(a==1)
	{
		Browse(x);
		printf("\n                                                         按任意键返回上一级\n");
		break;
	}

	while(a==2)
	{
		paixu(x);
		printf("按任意键返回上一级\n");break;
	}

	while(a==3)
	{
		Find();
		printf("按任意键返回上一级\n");break;
	}

	while(a==4)
	{
		Change(x);
		printf("按任意键返回上一级\n");break;
	}
	while(a==5)
	{
		Add(x);
		printf("按任意键返回上一级\n");break;
	}
	while(a==6)
	{
		Delete();
		printf("按任意键返回上一级\n");break;
	}

	while(a==7)
	{	
		ME2Main(7);
		printf("按任意键返回上一级\n");break;
	}

	while(a==8)
	{
		About(1);
		printf("按任意键返回上一级\n");break;
	}
	while(a==0)
	{
		MEMain(1);
		break;
	}
}


void ME1Main(int a)//管理菜单主程序
{
	int xuan;//菜单显示参数
	int choose=0;//选择菜单参数

	while(true)
	{
		MENU1(1);
		printf("\n\t\t\t==>请选择操作：");
		scanf("%d",&choose);
		system("cls");
		switch(choose)
		{
			case 1:xuan=1;break;
			case 2:xuan=2;break;
			case 3:xuan=3;break;
			case 4:xuan=4;break;
			case 5:xuan=5;break;
			case 6:xuan=6;break;
			case 7:xuan=7;break;
			case 8:xuan=8;break;
			case 0:xuan=0;break;
			default :printf("错误!错误!错误!\n按任意键返回，重新输入\n");break;
		}
		ME1Function(xuan);
		fflush(stdin);
		getchar();
		system("cls");
	}
}

void MEFunction(int a)//主菜单功能
{
	while(a==1)
	{
		//测试成功
		mima(1);
		break;
	}

	while(a==2)
	{
		ME2Main(7);
		break;
	}

}

int MEMain(int a)//主菜单主程序
{
	int xuan;
	int choose=0;

	while(true)
	{
		MENU(1);
		printf("\n\t\t==>请选择操作：");
		scanf("%d",&choose);
		system("cls");
		switch(choose)
		{
			case 1:xuan=1;break;
			case 2:xuan=2;break;
			case 0:xuan=0;return 0;
			default :printf("错误!错误!错误!\n按任意键返回，重新输入\n");break;
		}
		MEFunction(xuan);
		fflush(stdin);
		getchar();
		system("cls");
	}
}

int main()
{
	system("color F4");

	FILE *fb;
	fb = fopen("library.dat","rb");
	if(fb==NULL)
	{
		printf("Can not open the library.dat\n");
		exit(0);
	}
	
	system("cls");

	MEMain(1);
	
	fclose(fb);
	return 0;
}
