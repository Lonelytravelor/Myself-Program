#include<stdio.h>
#include<stdlib.h> 
#include <windows.h>
#define MAX 200

struct Message;
struct StackLink;
typedef struct StackLink *Stack;
typedef struct StackLink *Position;
typedef struct Message Message;

struct Message
{
	char name[15];
	char sex[15];
	char tele[15];
	char address[15];
};

struct StackLink
{
	int Data;
	Position Next;
 };
 
//������������ 
void Tips();
int IsEmpty( Stack T );
Stack Create();
int Push ( int X, Stack T);
int PrintStack( Stack T );
void StackInitial( Stack T );
void bea(int max);
void Menu();
void Insert( Stack T,struct Message *Mess );
void PrintLink(struct Message *Mess );
void PrintMessage( int i ,struct Message *Mess);

 //�����Ƿ�Ϊ�� 
 int IsEmpty( Stack T )
 {
 	return T->Next == NULL;
  } 
 
 //����һ��ջ��Ԫ�أ���Ϊ��ǽڵ� 
Stack Create()
{
	Position P = ( Position )malloc( sizeof( struct StackLink ));
	if( !P ){
		printf("Not Of Space!");
		exit(-1);
	}else{
		P->Data = 0;
		P->Next = NULL;
	}
	
	return P;
}

//��ջ 
int Push ( int X, Stack T)
{
	int i = 0;
	Position P = ( Position )malloc( sizeof( struct StackLink ));
	
	if( !P ){
		printf("Not Of Space!");
		exit(-1);
	}else{
		P->Data = X;
		P->Next = NULL;
	}	
	P->Next = T->Next;
	T->Next = P;
	i = 1;
	
	return i; 
}

//��ջ������ջ��Ԫ�� 
int Pop ( Stack T ){
	int Temp = -1;
	
	if( IsEmpty( T ) ){
		printf("Stack Is Empty!");
		system("pause");
	}else{
		Position P = T->Next;
		Temp = P->Data;
		T->Next = P->Next;
		free( P );
	}
	
	return Temp;
}

//�������ջ 
int PrintStack( Stack T )
{
	int i = 0;
	Position Temp = T;
	 
	while( !IsEmpty( Temp )){
		printf("%d ",Temp->Next->Data);
		Temp = Temp->Next;
		i++;
	}
	
	return i;
}

//��ʼ��ջ�Ĵ�С
void StackInitial( Stack T )
{
	int i = MAX;
	
	for( ; i >0 ; i-- ){
		Push( i , T );
	}
	
 } 
 
 //���ļ��е���Ϣ��������
// int ReadData( struct Message *Mess )
// {
// 	
// 	return 0;
// }
 
 //���������Ϣд���ı��ļ���
//void WriteData( int i , struct Message *Mess )
//{
// 	FILE *fp = NULL ;
//	fp = fopen( "D:\\����\\MailList\\Message.txt","a" );
//	if( fp ){
//		fputs( Mess[i].name,fp);
//		fputs("\n",fp);
//		fputs( Mess[i].sex,fp);
//		fputs("\n",fp);
//		fputs( Mess[i].tele,fp);
//		fputs("\n",fp);
//		fputs( Mess[i].address,fp);
//		fputs("\n",fp);
//	}
//	else{
//		printf("�����쳣");
//		exit(0);
//	}
//	fclose(fp);
//} 

//�ڽ���ʱ�����е���Ϣ�������ı��ļ���
 void WriteData(  struct Message *Mess )
{
	int k = 0,i;
 	FILE *fp = NULL ;
 	
 	printf("���ڱ���...\n"); 
	Sleep(1500); 
	fp = fopen( "D:\\Message.txt","w" );
	for( i = 1; i <= MAX ; i++ ){
		if( strcmp(Mess[i].name,"***") ){
			if( fp ){
				fputs( Mess[i].name,fp);
				fputs("\n",fp);
				fputs( Mess[i].sex,fp);
				fputs("\n",fp);
				fputs( Mess[i].tele,fp);
				fputs("\n",fp);
				fputs( Mess[i].address,fp);
				fputs("\n",fp);
			}else{
			printf("�����쳣");
			exit(0);
			}
		}
	}
	printf("����ɹ�"); 
	fclose(fp);
} 
  
 //�ȴ��������Ż�����
 void sleeped(int m)
 {
 	int i;
 	
 	for( i = 0; i < m; i++ ){
 		Sleep(150);
 		printf(".");
	 }
	 printf("\n");
	 
  } 
  
// �������ݺ���
void Loading ( struct Message *Mess , Stack T )
{
	FILE *fp = fopen("D:\\Message.txt","r");
	int k = 1  ;
	int i;
	char str[20];
	if( fp ){
		while( fgets( str , 20 , fp )){
			if( str[strlen(str) - 1 ] == '\n'){
				str[strlen(str) - 1 ] = '\0';
			}
			k %= 4;
			switch( k ){
				case 1 :
					i = Pop( T );
					strcpy(Mess[i].name,str);
					k++;
					break;
				case 2 :
					strcpy(Mess[i].sex,str);
					k++;
					break;
				case 3 :
					strcpy(Mess[i].tele,str);
					k++;
					break;
				case 0 :
					strcpy(Mess[i].address,str);
					k++;
					break;
			} 
		}
	}
	
	
 } 
//��ʼ������ͨѶ¼
 void NameInitial ( struct Message *Mess ) 
 {
 	int i = 1;
	for( i; i<= MAX; i++){
		strcpy(Mess[i].name,"***");
	}
	
 }
 
 //��ӡ����ͨѶ¼ 
void PrintLink(struct Message *Mess )
{
	int i = -1,k = 0;
	
	printf("����Ϊ����ӡ������ϵ��");
	sleeped(6);
	for( i = 1; i <= MAX ; i++ ){
		if( strcmp(Mess[i].name,"***") ){
			k = 1;
			PrintMessage( i , Mess );
			Sleep(150);
		}
	}
	 if( !k ){
	 	printf("\nͨѶ¼Ϊ��...\n"); 
	 }
		
 } 
 
//��������1 
void bea(int max)
{
	int i;
	
	for(i = 0; i < max ; i++){
		printf("*");
	}
	printf("\n");
}

//��������2 
void bea2(int max)
{
	int i;
	printf("  ");
	for(i = 0; i < max ; i++){
		printf("-");
	}
	printf("\n");
}

//��ӡ������Ϣ 
void PrintMessage( int i ,struct Message *Mess)
{
	bea2(45);
	printf(" |   ��� ��      %-16d             |\n", i );
	printf(" |   ���� ��      %-16s             |\n",  Mess[i].name);
	printf(" |   �Ա� ��      %-16s             |\n", Mess[i].sex );
	printf(" |   �绰 ��      %-16s             |\n", Mess[i].tele );
	printf(" |   ��ַ ��      %-16s             |\n", Mess[i].address );
	bea2(45);
	
}
//ɾ����������
void Delete( Stack T,struct Message *Mess ) 
{
	int i,Temp;
	
	printf("��������Ҫɾ������ϵ�˵���ţ�\n");
	scanf("%d",&Temp);
 	strcpy(Mess[Temp].name,"***");
 	Push( Temp , T );
 	Tips();
 	
 } 
 
//���뺯������
void Insert( Stack T,struct Message *Mess ) 
{
	int i , Temp =  Pop( T );
	if( Temp == -1 ){
		printf(" ͨѶ¼������ ");
		system("pause");
	}else{
		printf("\n");
		printf("������������ ");
		scanf("%s",&Mess[Temp].name);
		printf("�������Ա� "); 
		scanf("%s",&Mess[Temp].sex);
		printf("������绰�� "); 
		scanf("%s",&Mess[Temp].tele);
		printf("�������ַ�� "); 
		scanf("%s",&Mess[Temp].address);
		printf("\n");
	}
	printf("���Ե�"); 
	sleeped(3);
	Tips(); 
	printf("���Ǵ���ϵ�˵���Ϣ...\n"); 
	PrintMessage( Temp , Mess );
	printf("����������ô����ȷ��������1��ȡ��������0��\n");
	scanf("%d",&i);
	if( i ){
		Insert(  T, Mess );
	}
	
}

//���Һ�������������Ҫ���ҵ��˵����֣���Ϊ��չʾ����˵���Ϣ��δ�ҵ��򷵻�û���ҵ�����ϵ�˵���Ϣ
void Find( struct Message *Mess )
{
	char Temp[15];
	int i = 1,k = 0;
	
	printf("������������ҵ��˵������� ");
	scanf("%s",Temp);
	for( i = 1; i <= MAX ; i++ ){
		if( !strcmp(Mess[i].name,Temp) ){
			k = 1; 
			printf("\n");
			printf("���ҳɹ������Ǵ���ϵ�˵���Ϣ:\n"); 
			PrintMessage( i , Mess );
		}
	}
	if( !k ){
		printf("û���ҵ�����ϵ�ˣ�\n");
	} 
	
 } 
 
 //���޸�������������Ҫ�޸ĵ��˵����֣���Ϊ�������������д��Ϣ 
void Updata( struct Message *Mess )
{
	char Temp[15];
	int i = 1,k = 0;
	
	printf("�����������޸ĵ��˵������� ");
	scanf("%s",Temp);
	for( i = 1; i <= MAX ; i++ ){
		if( !strcmp(Mess[i].name,Temp) ){
			k = 1; 
			printf("\n");
			printf("���Ǵ���ϵ�˵���Ϣ:\n"); 
			PrintMessage( i , Mess );
			printf("\n");
			printf("�����㽫������д����ϵ�˵���Ϣ...");
			printf("\n");
			printf("������������ ");
			scanf("%s",&Mess[i].name);
			printf("�������Ա� "); 
			scanf("%s",&Mess[i].sex);
			printf("������绰�� "); 
			scanf("%s",&Mess[i].tele);
			printf("�������ַ�� "); 
			scanf("%s",&Mess[i].address);
			printf("\n");
			Tips();
		}
	}
	if( !k ){
		printf("û���ҵ�����ϵ�ˣ�\n");
	} 
	
 } 

//��ʾ��Ϣ 
void Tips()
{
	printf("       ");
	bea2(24);
	printf("       |    ��  ��  ��  ��  ��   |\n");
	printf("       ");
	bea2(24);
	printf("\n");
}
 
//�˵����� 
void Menu()
{
	bea(50);
	printf("***                                            ***\n");
	printf("***                   ���˵�                   ***\n"); 
	printf("***                                            ***\n");
	printf("***                                            ***\n");
	printf("***              1.�鿴������ϵ��              ***\n"); 
	printf("***                                            ***\n");
	printf("***              2.����ĳ����ϵ��              ***\n");
	printf("***                                            ***\n");
	printf("***              3.ɾ��ĳ����ϵ��              ***\n");
	printf("***                                            ***\n");
	printf("***              4.�޸�ĳ����ϵ��              ***\n");
	printf("***                                            ***\n");
	printf("***              5.��ѯĳ����ϵ��              ***\n");
	printf("***                                            ***\n");
	printf("***              6.�˳�����������              ***\n");
	printf("***                                            ***\n");
	printf("***                                            ***\n");
	printf("***                                            ***\n");
	bea(50);
}
//����������

 

int main()
{
	int i = -1,K = -1;
	struct Message Mess[MAX];	
	Stack T = Create();
	StackInitial( T );
	NameInitial( Mess );
	Loading( Mess , T );
	while( 1 )
	{
		Menu(); 
		printf("\n����������ʵ�ֵĹ��ܵ����...\n"); 
		scanf( "%d" ,&i );
		
		switch( i )
		{
			case 1 :
				PrintLink( Mess );
				break;
			case 2 :
				Insert( T, Mess );
				break;
			case 3 :
				Delete( T, Mess );
				break;
			case 4 :
				Updata( Mess );
				break;
			case 5 :
				Find( Mess );
				break;
			case 6 :
				printf("�Ƿ񱣴��������޸ģ���ȷ��������1��ȡ��������0��\n");
				scanf("%d",&K);
				if( K == 0 ){
					exit(0);
				}else{
					WriteData( Mess ); 
					getchar();
					exit(0); 	
				}
			default:
				printf("����������ֲ����ϸ�ʽ������������\n"); 
				break;
		}
	 } 
	
	
	return 0;
	
}
