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
	char find_num[20];//�����
	char bar_code[14];//ͼ��������
	char book_name[20];//����
	char wirter_name[20];//��������
	char press[22];//������
	char time[10];//����ʱ��
	char price[10];//����
	int canborrow;//�ɽ�����
	int have;//������

	int hot;//�����
	int news;//�¶�
};

struct library x[N];


void MENU(int a)//���˵�
{
	printf("                 /\\        /\\      \n");
	printf("          ������//\\\\      //\\\\���� \n");
	printf("          ���� /�� \\\\    //   \\    \n");
	printf("          (1)     ��\\\\  //       (2) \n");
	printf("          �ܡ���     \\\\//        �� \n");
	printf("          ��    ��.-'^'-.      �� \n");
	printf("          ϵ    ��.' a___a `.    ϵ \n");
	printf("          ͳ     ==��(___)��==   ͳ \n");
	printf("          ��������'. ._I_. .'       \n");
	printf("          ����    /.`-----'.\\   \n");
	printf("          [###(__)#### [###(__)####]\n");


}

void MENU1(int a)//����˵�
{	
	system("cls");
	printf("**************************************************************\n");
	printf("          .-._    ****************����ϵͳv1.0*************\n"); 
	printf("         {_}^ )o  ********************************************\n");
	printf("{\\________//~`    *(1)ͼ����Ϣ���          (2)ͼ����Ϣ����***\n");
	printf(" (         )      *(3)ͼ����Ϣ��ѯ          (4)ͼ����Ϣ�޸�***\n");
	printf(" /||~~~~~||\\      *(5)ͼ����Ϣ���          (6)ͼ����Ϣɾ��***\n");
	printf("|_\\\\_    \\\\_\\_    *(7)�û�ϵͳ�鿴          (8)�����Һ�ĳĳ***\n");
	printf("\"\' \"\"\'    \"\"\'\"\'   ********************************************\n");
	printf("**************************************************************\n");
	printf("*******************************(0)����������******************\n");
	printf("**************************************************************\n");
}

void MENU2(int b)//�û��˵�
{
		printf("	***********************************************************\n");
		printf("	************************�û�ϵͳv1.0*********************\n");
		printf("	*********(1)ͼ����Ϣ���           (2)�ȶ�ͼ���Ƽ�*********\n");
		printf("	*********(3)ͼ����Ϣ��ѯ           (4)�����Һ�ĳĳ*********\n");
		printf("	***********************************************************\n");
		printf("	***********************************************************\n");
		printf("	*************************************(0)����������*********\n");
		printf("	***********************************************************\n");


}

void xxx(int a)
{
	printf("                  ���ܡ�  �   ����     \n");
	printf("          ��  ���M���������t�r   �M ����       \n");
	printf("          ��  ��������������䡫�� ����      \n");
	printf("          ����  ���������������� ���ܨM      \n");
	printf("          �� �� �M �����񡡡��� �񡡣�       \n");
	printf("            �������𡡡ࡤ�t�s���ࡡ�𡡣��� \n");
	printf("          ��   �q�������r����     ���q�������r   \n");
//	printf("            �X�T �ȡȡȨT��������T�ȡȡȨT�[\n");
//	printf("                     :");

}

char * mimaxiugai(char a[])
{
	char c1[20];
	char c2[20];
	char c3[20];
	for(int l=0;l<3;l++)
	{
		printf("\t\t����ԭ���룺");
		scanf("%s",c1);
		
		printf("\t\t���������룺");
		scanf("%s",c2);
		
		printf("\t\tȷ�������룺");
		scanf("%s",c3);

		if(strcmp(a,c1)==0&&strcmp(c2,c3)==0)
		{
			strcpy(a,c2);
			printf("�����޸ĳɹ�\n");break;
		}
		
	}
	return a;
}

void mima (int a)//����ϵͳ
{
	char log_mima[20];
	char mima_store[20];
	char temp[3]="xg";
	
	FILE *mp;
	mp=fopen("mimaben.dat","rb");

	fscanf(mp,"%s",mima_store);

	fclose(mp);

	
	xxx(1);
	printf("            �X�T �ȡȡȨT��������T�ȡȡȨT�[\n");
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
			printf("            �X�T �ȡȡȨT�������T�ȡȡȨT�[\n");
			printf("     ������%d�λ��ᣡ:",2-i);
			scanf("\r");
			system("cls");
			
		}
		else
			ME1Main(1);
	//	system("cls");
		if(i==2)
			printf("�밴�س����˳�");
		
	}
}

int Cnt (struct library a[])//����
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

void paixu(struct library a[])//����
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
	printf("\n**********���ɽ�������***********\n");
    for(i=0;i<cnt-1;i++)
	    for(j=0;j<cnt-i-1;j++)
		    if(a[j].canborrow>a[j+1].canborrow)
			{
		        temp=a[j];
		        a[j]=a[j+1];
		        a[j+1]=temp;
			}

    printf("    �����    ͼ��������                ����          ��������                ������     ����ʱ��      ����\t�ɽ�����\t������\t\n");
    for(i=0;i<cnt;i++)
    printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",a[i].find_num,a[i].bar_code,a[i].book_name,a[i].wirter_name,a[i].press,a[i].time,a[i].price,a[i].canborrow,a[i].have);
	printf("��������������˵�\n");

	FILE *tp;
	tp=fopen("library.dat","ab+");
	for(m=0;m<cnt;m++)
		fprintf(tp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",a[m].find_num,a[m].bar_code,a[m].book_name,a[m].press,a[m].time,a[m].price,a[m].canborrow,a[m].have);
	fclose(tp);
}

void Browse (struct library a[])//���
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

	printf("    �����    ͼ��������                ����          ��������                ������     ����ʱ��      ����\t�ɽ�����\t������\t\n");
	int i=0;
	do
	{
		fscanf(fp,"%s%s%s%s%s%s%s%d%d\n",a[i].find_num,a[i].bar_code,a[i].book_name,a[i].wirter_name,a[i].press,a[i].time,a[i].price,&a[i].canborrow,&a[i].have);
		printf("\n");
		printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",a[i].find_num,a[i].bar_code,a[i].book_name,a[i].wirter_name,a[i].press,a[i].time,a[i].price,a[i].canborrow,a[i].have);
		i++;
	}while(!feof(fp));
	printf("\n                                                            �ܲ�����%d\n",i);
	
}

void Find()   //��ѯ
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
	printf("1:��������Ų�ѯ\n");
	printf("2:����ͼ���������ѯ\n");
	printf("3:����������ѯ\n");
	printf("4:�������߲�ѯ\n");
	printf("5:���ճ������ѯ\n");
	
	printf("ѡ���ѯ��ʽ");
	getchar();
	scanf("%d",&x);

	while(x==3)
	{
		printf("��������Ҫ���ҵ�ͼ���������");  
        scanf("%s",&name); 
	    printf("\n"); 
   	    do
	    {  
			    if(strcmp(name,c[i].book_name)==0)
			    {
			    	printf("    �����    ͼ��������                ����          ��������                ������     ����ʱ��      ����\t�ɽ�����\t������\t\n"); 
			    	printf("\n");
			    	printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",c[i].find_num,c[i].bar_code,c[i].book_name,c[i].wirter_name,c[i].press,c[i].time,c[i].price,c[i].canborrow,c[i].have); 
			    	k++;
					c[i].hot++;
			    	break;
		    	}
		    	i++;
		    }while(i<cnt);
	    	printf("                                                                �ܹ��ҵ�%d��\n",k);
			
			printf("������һ���밴��Y��\n");
				printf("������������ѯ�밴��o��!\n");
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
					printf("������һ���밴��Y��\n");
					printf("������ѯ�밴��o��!\n");
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
						printf("����������˫���س�\n");
						printf("������ѯ�밴��o��!\n");
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
		printf("��������Ҫ���ҵ�ͼ��������룺");  
        scanf("%s",&name); 
	    printf("\n"); 
   	    do
	    {  
			    if(strcmp(name,c[i].bar_code)==0)
			    {
			    	printf("    �����    ͼ��������                ����          ��������                ������     ����ʱ��      ����\t�ɽ�����\t������\t\n"); 
			    	printf("\n");
			    	printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",c[i].find_num,c[i].bar_code,c[i].book_name,c[i].wirter_name,c[i].press,c[i].time,c[i].price,c[i].canborrow,c[i].have); 
			    	k++;c[i].hot++;
			    	break;
		    	}
		    	i++;
		    }while(i<cnt);
	    	printf("                                                                �ܹ��ҵ�%d��\n",k);
			
			printf("������һ���밴��Y��\n");
				printf("������ͼ����������ѯ�밴��o��!\n");
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
					printf("������һ���밴��Y��\n");
					printf("������ѯ�밴��o��!\n");
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
						printf("����������˫���س�\n");
						printf("������ѯ�밴��o��!\n");
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
		printf("��������Ҫ���ҵ�ͼ�������ţ�");  
        scanf("%s",&name); 
	    printf("\n"); 
   	    do
	    {  
			    if(strcmp(name,c[i].find_num)==0)
			    {
			    	printf("    �����    ͼ��������                ����          ��������                ������     ����ʱ��      ����\t�ɽ�����\t������\t\n"); 
			    	printf("\n");
			    	printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",c[i].find_num,c[i].bar_code,c[i].book_name,c[i].wirter_name,c[i].press,c[i].time,c[i].price,c[i].canborrow,c[i].have); 
			    	k++;c[i].hot++;
			    	break;
		    	}
		    	i++;
		    }while(i<cnt);
	    	printf("                                                                �ܹ��ҵ�%d��\n",k);
			
				printf("������һ���밴��Y��\n");
				printf("����������Ų�ѯ�밴��o��!\n");
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
					printf("������һ���밴��Y��\n");
					printf("������ѯ�밴��o��!\n");
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
		printf("��������Ҫ���ҵ�ͼ������ߣ�");  
        scanf("%s",&name); 
	    printf("\n"); 
   	    do
	    {  
			    if(strcmp(name,c[i].wirter_name)==0)
			    {
			    	printf("    �����    ͼ��������                ����          ��������                ������     ����ʱ��      ����\t�ɽ�����\t������\t\n"); 
			    	printf("\n");
			    	printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",c[i].find_num,c[i].bar_code,c[i].book_name,c[i].wirter_name,c[i].press,c[i].time,c[i].price,c[i].canborrow,c[i].have); 
			    	k++;c[i].hot++;
			    	break;
		    	}
		    	i++;
		    }while(i<cnt);
	    	printf("                                                                �ܹ��ҵ�%d��\n",k);
			
			printf("������һ���밴��Y��\n");
				printf("������ͼ������߲�ѯ�밴��o��!\n");
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
					printf("������һ���밴��Y��\n");
					printf("������ѯ�밴��o��!\n");
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
						printf("����������˫���س�\n");
						printf("������ѯ�밴��o��!\n");
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
		printf("��������Ҫ���ҵ�ͼ��ĳ����磺");  
        scanf("%s",&name); 
	    printf("\n"); 
   	    do
	    {  
			    if(strcmp(name,c[i].press)==0)
			    {
			    	printf("    �����    ͼ��������                ����          ��������                ������     ����ʱ��      ����\t�ɽ�����\t������\t\n"); 
			    	printf("\n");
			    	printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",c[i].find_num,c[i].bar_code,c[i].book_name,c[i].wirter_name,c[i].press,c[i].time,c[i].price,c[i].canborrow,c[i].have); 
			    	k++;c[i].hot++;
			    	break;
		    	}
		    	i++;
		    }while(i<cnt);
	    	printf("                                                                �ܹ��ҵ�%d��\n",k);
			
			printf("������һ���밴��Y��\n");
				printf("������ͼ��ĳ������ѯ�밴��o��!\n");
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
					printf("������һ���밴��Y��\n");
					printf("������ѯ�밴��o��!\n");
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
						printf("����������˫���س�\n");
						printf("������ѯ�밴��o��!\n");
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

void Change(struct library c[])//�޸�
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
		printf("��������Ҫ�޸ĵ�ͼ���ISBN��");  
		scanf("%s",&ISBN); 
		
		do
		{
			
			if(strcmp(ISBN,c[i].bar_code)==0)
			{
				printf("    �����    ͼ��������                ����          ��������                ������     ����ʱ��      ����\t�ɽ�����\t������\t\n"); 
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
			printf("ȷ���޸Ĵ�ͼ����Ϣ��������\n");
			printf(" ��Y��  or  ��N��      \n");
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
					printf("��ѡ����Ҫ�޸ĵ�����\n");
					printf("(1)�����\n(2)ͼ��������\n(3)����\n(4)��������\n(5)������\n(6)����ʱ��\n(7)����\n");
					getchar();
					scanf("%d",&k);
					while(k==1)
					{
						system("cls");
						printf("ԭ�����:%s\n",c[v].find_num);
						printf("�������:");
						scanf("%s",xian);
						printf("\n");
						printf("ȷ���޸Ĵ���Ϣ�밴��y��\n");
						printf("���������������\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",xian,c[v].bar_code,c[v].book_name,c[v].wirter_name,c[v].press,c[v].time,c[v].price,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("�޸�������Ϣ�밴��y��\n");
							printf("������һ���밴�س���\n");
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
						printf("ԭͼ��������:%s\n",c[v].bar_code);
						printf("��ͼ��������:");
						scanf("%s",xian);
						printf("\n");
						printf("ȷ���޸Ĵ���Ϣ�밴��y��\n");
						printf("���������������\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[v].find_num,xian,c[v].book_name,c[v].wirter_name,c[v].press,c[v].time,c[v].price,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("�޸�������Ϣ�밴��y��\n");
							printf("������һ���밴�س���\n");
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
						printf("ԭ����:%s\n",c[v].book_name);
						printf("������:");
						scanf("%s",xian);
						printf("\n");
						printf("ȷ���޸Ĵ���Ϣ�밴��y��\n");
						printf("���������������\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[v].find_num,c[v].bar_code,xian,c[v].wirter_name,c[v].press,c[v].time,c[v].price,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("�޸�������Ϣ�밴��y��\n");
							printf("������һ���밴�س���\n");
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
						printf("ԭ����:%s\n",c[v].wirter_name);
						printf("������:");
						scanf("%s",xian);
						printf("\n");
						printf("ȷ���޸Ĵ���Ϣ�밴��y��\n");
						printf("���������������\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[v].find_num,c[v].bar_code,c[v].book_name,xian,c[v].press,c[v].time,c[v].price,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("�޸�������Ϣ�밴��y��\n");
							printf("������һ���밴�س���\n");
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
						printf("ԭ������:%s\n",c[v].press);
						printf("�ֳ�����:");
						scanf("%s",xian);
						printf("\n");
						printf("ȷ���޸Ĵ���Ϣ�밴��y��\n");
						printf("���������������\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[v].find_num,c[v].bar_code,c[v].book_name,c[v].wirter_name,xian,c[v].time,c[v].price,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("�޸�������Ϣ�밴��y��\n");
							printf("������һ���밴�س���\n");
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
						printf("ԭ��������:%s\n",c[v].time);
						printf("�ֳ�������:");
						scanf("%s",xian);
						printf("\n");
						printf("ȷ���޸Ĵ���Ϣ�밴��y��\n");
						printf("���������������\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[v].find_num,c[v].bar_code,c[v].book_name,c[v].wirter_name,c[v].press,xian,c[v].price,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("�޸�������Ϣ�밴��y��\n");
							printf("������һ���밴�س���\n");
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
						printf("ԭ�۸�:%s\n",c[v].price);
						printf("�ּ۸�:");
						scanf("%s",xian);
						printf("\n");
						printf("ȷ���޸Ĵ���Ϣ�밴��y��\n");
						printf("���������������\n");
						getchar();
						scanf("%c",&j);
						if(j=='Y'||j=='y')
						{
							fp=fopen("library.dat","ab+");
							fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",c[v].find_num,c[v].bar_code,c[v].book_name,c[v].wirter_name,c[v].press,c[v].time,xian,c[v].canborrow,c[v].have);
							fclose(fp);
							system("cls");
							printf("�޸�������Ϣ�밴��y��\n");
							printf("������һ���밴�س���\n");
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
	/*		while(j!='Y'&&j!='y')                             ������Щ����
			{
				system("cls");
				printf("�޸�����ͼ����Ϣ���밴��Y��\n");
				printf("���������棬�밴�س������Σ�\n");
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
			printf("�޴�����Ϣ����\n");
			printf("�޸�����ͼ����Ϣ���밴��Y��\n");
			printf("���������棬�밴�س������Σ�\n");
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

void Add(struct library a[])//���
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
		printf("��ӵ�%d���鼮��Ϣ\n",k+1);
		printf("�����:");
		scanf("%s",a[i].find_num);
	    printf("ͼ��������:");
		scanf("%s",a[i].bar_code);
		getchar();
        for(int x=0;x<N+k;x++)
			if(strcmp(a[i].bar_code,c[x].bar_code)==0)
				q=0;
        if(q==1)
		{
	        printf("����:");
			scanf("%s",a[i].book_name);

			printf("��������:");
			scanf("%s",a[i].wirter_name);

			printf("������:");
			scanf("%s",a[i].press);
	
			printf("����ʱ��:");
			scanf("%s",a[i].time);

			printf("����:");
			scanf("%s",a[i].price);

			printf("�ɽ�����:");
			scanf("%d",&a[i].canborrow);

			printf("������:");
			scanf("%d",&a[i].have);

	        printf("ȷ�������Ϣ�밴��Y��\n");
	        printf("���������밴��n��\n");
			printf("�����������밴y��n���������\n");
			getchar();
	        scanf("%c",&j);
	        if(j=='Y'||j=='y')
			{
				system("cls");
		        fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t\n",a[i].find_num,a[i].bar_code,a[i].book_name,a[i].wirter_name,a[i].press,a[i].time,a[i].price,a[i].canborrow,a[i].have);
		        printf("\t\t��Ϣ��ӳɹ���\n");
				fclose(fp);
				fp=fopen("library.dat","ab+");
				k++;
				printf("���������밴��Y��\n");
				printf("�˳��������!\n");
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
		
			printf("\n���������밴��Y��\n");
			printf("\n(����������˳�!)\n");
			scanf("%c",&j);
			if(j=='Y'||j=='y')
				m=1;
			else
				break;
		}
		else 
		{
			printf("��ͼ����Ϣ�Ѵ��ڣ�\n");
			printf("���������밴��Y��\n");
			printf("������������˳�!\n");
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

void Delete()     //ɾ��
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
		printf("��������Ҫɾ��ͼ���ISBN: \n");
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
			printf("��Ǹ��δ�ҵ���ͼ����Ϣ\n");
			printf("���������밴��y��\n");
			printf("�����λس������أ�\n");
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
			printf("    �����    ͼ��������                ����          ��������                ������     ����ʱ��      ����\t�ɽ�����\t������\t\n");
			printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t\n",c[v].find_num,c[v].bar_code,c[v].book_name,c[v].wirter_name,c[v].press,c[v].time,c[v].price,c[v].canborrow,c[v].have);
			printf("ȷ��ɾ����ͼ����Ϣ��������\n");
			printf(" ��Y��  or  ��N��      \n");
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
				printf("ɾ���ɹ�����\n");
				printf("ɾ������ͼ����Ϣ���밴��Y��\n");
				printf("���������棬�밴�س������Σ�\n");
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

void paixu2(struct library a[])//�ȶ�
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
	printf("\n**********ͼ���Ƽ�***********\n");
    for(i=0;i<cnt-1;i++)
	    for(j=0;j<cnt-i-1;j++)
		    if(a[j].hot<a[j+1].hot)
			{
		        temp=a[j];
		        a[j]=a[j+1];
		        a[j+1]=temp;
			}

    printf("    �����    ͼ��������                ����          ��������                ������     ����ʱ��      ����\t�ɽ�����\t������\t�ȶ�\n");
    for(i=0;i<cnt;i++)
    printf("%10s  %14s  %20s  %10s  %22s  %10s  %10s\t  %d\t\t%d\t%d\n",a[i].find_num,a[i].bar_code,a[i].book_name,a[i].wirter_name,a[i].press,a[i].time,a[i].price,a[i].canborrow,a[i].have,a[i].hot);
	printf("��������������˵�\n");

	FILE *tp;
	tp=fopen("library.dat","ab+");
	for(m=0;m<cnt;m++)
	fprintf(tp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",a[m].find_num,a[m].bar_code,a[m].book_name,a[m].press,a[m].time,a[m].price,a[m].canborrow,a[m].have,a[m].hot);
	fclose(tp);
}

void GD2()
{
    char str[] = "���Ǽ����������ǳ���Գ�����ǵ���Ŷ�������ǵ�QQ��1 7 1 7 3 9 4 9 1 ��1 2 8 6 8 8 2 0 9  2 ��2 0 6 1 4 3 1 6 3 6 ��2 6 4 4 6 9 6 7 2 9  ��2 4 5 1 3 7 8 5 8 7 ��1 4 1 3 4 0 4 3 2 9 ��������Ŷ��";
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
    char str[] = "��ϵͳ�����Ǽ����˵�Ŭ���¶��ɣ�������Ȼ���У�������֧�����˺�1 3 1 4 0 0 2 5 8 0 7 �����ľ����Ƕ����ǵ�֧��";
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


void About(int a)//�����Һ�ĳĳ
{
	if(a==1)
	{
		char x;
		printf("����Ա���boy����gril?(b/g)\n");
		x=getchar();
		scanf("%c",&x);
		if(x=='b')
		{GD1();}
		else
		{GD2();}
	}
}

void ME2Function(int c)//�û��˵�����
{
	while(c==1)
	{
		Browse(x);
		printf("�������������һ��\n");break;
	}
	while(c==2)
	{
		paixu2(x);
		printf("�������������һ��\n");break;
	}
	while(c==3)
	{
		Find();
		printf("�������������һ��\n");
		break;
	}
	while(c==4)
	{
		About(1);
		printf("�������������һ��\n");break;
	}
	while(c==5)
	{
		printf("����������\n");
		system("cls");
		MEMain(1);
		break;
	}

}

int ME2Main(int d)//�û��˵�������
{
	int choose,xuan;
	while(d==7)
	{
		MENU2(1);
		printf("\n	\t\t\t==>��ѡ�������");
		scanf("%d",&choose);
		system("cls");
	
		switch(choose)
		{
			case 1:xuan=1;break;
			case 2:xuan=2;break;
			case 3:xuan=3;break;
			case 4:xuan=4;break;
			case 0:xuan=5;break;
			default :printf("����!����!����!\n����������أ��������룺");break;
		}
		ME2Function(xuan);
		fflush(stdin);
		getchar();
		system("cls");
	}
	return 0;
}




void ME1Function(int a)//����˵�����
{
	while(a==1)
	{
		Browse(x);
		printf("\n                                                         �������������һ��\n");
		break;
	}

	while(a==2)
	{
		paixu(x);
		printf("�������������һ��\n");break;
	}

	while(a==3)
	{
		Find();
		printf("�������������һ��\n");break;
	}

	while(a==4)
	{
		Change(x);
		printf("�������������һ��\n");break;
	}
	while(a==5)
	{
		Add(x);
		printf("�������������һ��\n");break;
	}
	while(a==6)
	{
		Delete();
		printf("�������������һ��\n");break;
	}

	while(a==7)
	{	
		ME2Main(7);
		printf("�������������һ��\n");break;
	}

	while(a==8)
	{
		About(1);
		printf("�������������һ��\n");break;
	}
	while(a==0)
	{
		MEMain(1);
		break;
	}
}


void ME1Main(int a)//����˵�������
{
	int xuan;//�˵���ʾ����
	int choose=0;//ѡ��˵�����

	while(true)
	{
		MENU1(1);
		printf("\n\t\t\t==>��ѡ�������");
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
			default :printf("����!����!����!\n����������أ���������\n");break;
		}
		ME1Function(xuan);
		fflush(stdin);
		getchar();
		system("cls");
	}
}

void MEFunction(int a)//���˵�����
{
	while(a==1)
	{
		//���Գɹ�
		mima(1);
		break;
	}

	while(a==2)
	{
		ME2Main(7);
		break;
	}

}

int MEMain(int a)//���˵�������
{
	int xuan;
	int choose=0;

	while(true)
	{
		MENU(1);
		printf("\n\t\t==>��ѡ�������");
		scanf("%d",&choose);
		system("cls");
		switch(choose)
		{
			case 1:xuan=1;break;
			case 2:xuan=2;break;
			case 0:xuan=0;return 0;
			default :printf("����!����!����!\n����������أ���������\n");break;
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
