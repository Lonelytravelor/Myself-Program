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
 
//声明函数区域 
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

 //检验是否为空 
 int IsEmpty( Stack T )
 {
 	return T->Next == NULL;
  } 
 
 //创建一个栈顶元素，作为标记节点 
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

//入栈 
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

//出栈并返回栈顶元素 
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

//遍历这个栈 
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

//初始化栈的大小
void StackInitial( Stack T )
{
	int i = MAX;
	
	for( ; i >0 ; i-- ){
		Push( i , T );
	}
	
 } 
 
 //将文件中的信息读入数组
// int ReadData( struct Message *Mess )
// {
// 	
// 	return 0;
// }
 
 //将插入的信息写入文本文件中
//void WriteData( int i , struct Message *Mess )
//{
// 	FILE *fp = NULL ;
//	fp = fopen( "D:\\桌面\\MailList\\Message.txt","a" );
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
//		printf("操作异常");
//		exit(0);
//	}
//	fclose(fp);
//} 

//在结束时将所有的信息保存在文本文件中
 void WriteData(  struct Message *Mess )
{
	int k = 0,i;
 	FILE *fp = NULL ;
 	
 	printf("正在保存...\n"); 
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
			printf("操作异常");
			exit(0);
			}
		}
	}
	printf("保存成功"); 
	fclose(fp);
} 
  
 //等待函数，优化体验
 void sleeped(int m)
 {
 	int i;
 	
 	for( i = 0; i < m; i++ ){
 		Sleep(150);
 		printf(".");
	 }
	 printf("\n");
	 
  } 
  
// 加载数据函数
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
//初始化整个通讯录
 void NameInitial ( struct Message *Mess ) 
 {
 	int i = 1;
	for( i; i<= MAX; i++){
		strcpy(Mess[i].name,"***");
	}
	
 }
 
 //打印整个通讯录 
void PrintLink(struct Message *Mess )
{
	int i = -1,k = 0;
	
	printf("即将为您打印所有联系人");
	sleeped(6);
	for( i = 1; i <= MAX ; i++ ){
		if( strcmp(Mess[i].name,"***") ){
			k = 1;
			PrintMessage( i , Mess );
			Sleep(150);
		}
	}
	 if( !k ){
	 	printf("\n通讯录为空...\n"); 
	 }
		
 } 
 
//美化函数1 
void bea(int max)
{
	int i;
	
	for(i = 0; i < max ; i++){
		printf("*");
	}
	printf("\n");
}

//美化函数2 
void bea2(int max)
{
	int i;
	printf("  ");
	for(i = 0; i < max ; i++){
		printf("-");
	}
	printf("\n");
}

//打印单个信息 
void PrintMessage( int i ,struct Message *Mess)
{
	bea2(45);
	printf(" |   序号 ：      %-16d             |\n", i );
	printf(" |   姓名 ：      %-16s             |\n",  Mess[i].name);
	printf(" |   性别 ：      %-16s             |\n", Mess[i].sex );
	printf(" |   电话 ：      %-16s             |\n", Mess[i].tele );
	printf(" |   地址 ：      %-16s             |\n", Mess[i].address );
	bea2(45);
	
}
//删除函数（）
void Delete( Stack T,struct Message *Mess ) 
{
	int i,Temp;
	
	printf("请输入你要删除的联系人的序号：\n");
	scanf("%d",&Temp);
 	strcpy(Mess[Temp].name,"***");
 	Push( Temp , T );
 	Tips();
 	
 } 
 
//插入函数（）
void Insert( Stack T,struct Message *Mess ) 
{
	int i , Temp =  Pop( T );
	if( Temp == -1 ){
		printf(" 通讯录已满！ ");
		system("pause");
	}else{
		printf("\n");
		printf("请输入姓名： ");
		scanf("%s",&Mess[Temp].name);
		printf("请输入性别： "); 
		scanf("%s",&Mess[Temp].sex);
		printf("请输入电话： "); 
		scanf("%s",&Mess[Temp].tele);
		printf("请输入地址： "); 
		scanf("%s",&Mess[Temp].address);
		printf("\n");
	}
	printf("请稍等"); 
	sleeped(3);
	Tips(); 
	printf("这是此联系人的信息...\n"); 
	PrintMessage( Temp , Mess );
	printf("你想继续添加么？（确定请输入1，取消请输入0）\n");
	scanf("%d",&i);
	if( i ){
		Insert(  T, Mess );
	}
	
}

//查找函数，输入你想要查找的人的名字，并为你展示这个人的信息，未找到则返回没有找到该联系人的信息
void Find( struct Message *Mess )
{
	char Temp[15];
	int i = 1,k = 0;
	
	printf("请输入你想查找的人的姓名： ");
	scanf("%s",Temp);
	for( i = 1; i <= MAX ; i++ ){
		if( !strcmp(Mess[i].name,Temp) ){
			k = 1; 
			printf("\n");
			printf("查找成功，这是此联系人的信息:\n"); 
			PrintMessage( i , Mess );
		}
	}
	if( !k ){
		printf("没有找到此联系人！\n");
	} 
	
 } 
 
 //查修改数，输入你想要修改的人的名字，并为你这个人重新填写信息 
void Updata( struct Message *Mess )
{
	char Temp[15];
	int i = 1,k = 0;
	
	printf("请输入你想修改的人的姓名： ");
	scanf("%s",Temp);
	for( i = 1; i <= MAX ; i++ ){
		if( !strcmp(Mess[i].name,Temp) ){
			k = 1; 
			printf("\n");
			printf("这是此联系人的信息:\n"); 
			PrintMessage( i , Mess );
			printf("\n");
			printf("下面你将重新填写此联系人的信息...");
			printf("\n");
			printf("请输入姓名： ");
			scanf("%s",&Mess[i].name);
			printf("请输入性别： "); 
			scanf("%s",&Mess[i].sex);
			printf("请输入电话： "); 
			scanf("%s",&Mess[i].tele);
			printf("请输入地址： "); 
			scanf("%s",&Mess[i].address);
			printf("\n");
			Tips();
		}
	}
	if( !k ){
		printf("没有找到此联系人！\n");
	} 
	
 } 

//提示信息 
void Tips()
{
	printf("       ");
	bea2(24);
	printf("       |    操  作  成  功  ！   |\n");
	printf("       ");
	bea2(24);
	printf("\n");
}
 
//菜单界面 
void Menu()
{
	bea(50);
	printf("***                                            ***\n");
	printf("***                   主菜单                   ***\n"); 
	printf("***                                            ***\n");
	printf("***                                            ***\n");
	printf("***              1.查看所有联系人              ***\n"); 
	printf("***                                            ***\n");
	printf("***              2.插入某个联系人              ***\n");
	printf("***                                            ***\n");
	printf("***              3.删除某个联系人              ***\n");
	printf("***                                            ***\n");
	printf("***              4.修改某个联系人              ***\n");
	printf("***                                            ***\n");
	printf("***              5.查询某个联系人              ***\n");
	printf("***                                            ***\n");
	printf("***              6.退出并保存数据              ***\n");
	printf("***                                            ***\n");
	printf("***                                            ***\n");
	printf("***                                            ***\n");
	bea(50);
}
//主操作界面

 

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
		printf("\n请输入你想实现的功能的序号...\n"); 
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
				printf("是否保存所做的修改？（确定请输入1，取消请输入0）\n");
				scanf("%d",&K);
				if( K == 0 ){
					exit(0);
				}else{
					WriteData( Mess ); 
					getchar();
					exit(0); 	
				}
			default:
				printf("所输入的数字不符合格式，请重新输入\n"); 
				break;
		}
	 } 
	
	
	return 0;
	
}
