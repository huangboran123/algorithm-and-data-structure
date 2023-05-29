// 数据结构课程设计.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include"malloc.h"
using namespace std;
#define ERROR 0
#define OK 1
//链表
typedef  int Elemtype;
typedef struct LNode {
	Elemtype date;
	struct LNode *next;
}LNode, *LinkList;
void CreatList_L(LinkList &L, int n) {
	int  i;
	LinkList p = NULL;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;                              //先建立一个带头节点的单链表
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d", &p->date);
		p->next = L->next; L->next = p;
	}
}

int GetElm_L(LinkList L, int i, Elemtype &e) {
	LinkList p;
	p = L->next; int j = 1;                        //查找第i个元素
	while (p&&j < i) {
		p = p->next; j++;
	}
	if (!p || j > i)return ERROR;
	e = p->date;
	return OK;
}

int ListInsert_L(LinkList &L, int i, Elemtype e) {

	LinkList p;
	LinkList s;                                //在第i个位置插入元素e
	p = L; int j = 0;
	while (p&&j < i - 1) {
		p = p->next; j++;
	}
	if (!p || j > i - 1)return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->date = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

int ListDelete_L(LinkList &L, int i, Elemtype &e) {

	LinkList p = L;
	int j = 0;
	LinkList q;                                //删除第i个元素并返回其值
	while (p->next&&j < i - 1) {
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->date;
	free(q);
	return OK;
}

void DisplayLinkList(LinkList L) {
	LinkList p = L->next;
	while (p) {                                      //输出单链表所有值
		printf("%d  ", p->date);
		p = p->next;
	}
	printf("\n");
}
void Destroy_L(LinkList &L) {
	LinkList p = L;
	LinkList q;
	while (p)                                         //销毁链表
	{
		q = p->next;
		free(p);
		p = q;

	}
}

typedef struct node {
	char name[20];
	char number[12];
	struct node *next;
}node,*Linkman;
                                            //创建联系人链表
void Adress_List(Linkman &L){                                                   
	char flag = 'y';
	L = (Linkman)malloc(sizeof(node));
	L->next = NULL;
	node *s;
	
	printf("创建一个通讯录:\n");
	
	while(flag=='Y'||flag=='y')
	{
		s = (Linkman)malloc(sizeof(node));
		printf("姓名:");
		scanf_s("%s", s->name,20);
		printf("号码:");
		scanf_s("%s", s->number,12);
		s->next = L->next;
		L->next = s;
		getchar();
		printf("继续输入？(y/n)");
		scanf_s("%c", &flag);
	}
}

                                         //头插法添加联系人
void Add_adresslist(Linkman &L) {
	node *n;
	n = (Linkman)malloc(sizeof(node));
	printf("请输入要创建的联系人\n");
	printf("姓名:");
	scanf_s("%s", n->name,20);
	printf("号码:");
	scanf_s("%s", n->number,12);
	n->next = L->next;
	L->next = n;
}
#define MAX_NAME 20
                                      //删除联系人
void delet_adresslist(Linkman &L) {
	char name1[20] ;
	node *p, *q;
	p = L;
	q = p->next;
	printf("请选择要删除的联系人:");
	scanf_s("%s",name1,20);
	while(q) 
	{
		if (strcmp(q->name,name1)==0)
		{
			p->next = q->next;           //删除操作核心语句
			free(q);
			q = p->next;              //为使q为空
		}
		else {
			p = p->next;
			q = p->next;
		}
	}
}
                                             //查找联系人信息
void Search_adresslist(Linkman &L) {
	
	char name2[20];
	node *p, *q;
	p = L;
	q = p->next;
	printf("请输入查找的联系人姓名:");
	scanf_s("%s", name2, 20);
	while (q)
	{
		if (strcmp(q->name, name2) == 0)
		{
			printf("该联系人电话是:%s\n",q->number);
			break;
		}
		else {
			p = p->next;
			q = p->next;
		}
	}
}
                                  //更新联系人信息
void Update_adresslist(Linkman &L) {
	
	char name3[20];
	node *p, *q;
	p = L;
	q = p->next;
	printf("请输入要更新的联系人姓名:");
	scanf_s("%s", name3, 20);
	while (q)
	{
		if (strcmp(q->name, name3) == 0)
		{
			printf("请输入更新电话:");
			scanf_s("%s", q->number,12);
			break;
		}
		else {
			p = p->next;
			q = p->next;
		}
	}


}
                       //输出通讯录所有信息
void Print_adresslist(Linkman L) {

	printf("----姓名----  ----电话---- \n");
	node *p, *q;
	p = L;
	q = p->next;
	while (q) {
		printf(" %s           %s\n", q->name, q->number);
		p = p->next;
		q = p->next;
	}
	printf("---------------------------\n");
}




 

void ShowMainMenu() {
	printf("\n");
	printf("*******************算法与数据结构******************\n");
	printf("* 1  单链表的基本操作及应用                       *\n");
	printf("* 2  栈的基本操作及应用                           *\n");
	printf("* 3  数组的基本操作及应用                         *\n");
	printf("* 4  树的基本操作及应用                           *\n");
	printf("* 5  图的基本操作及应用                           *\n");
	printf("* 6  退出                                         *\n");
	printf("***************************************************\n");
}

void Linklist() {
	LinkList L = NULL;
	Linkman M = NULL;
	int choice;
	int choice2;
	Elemtype e;
	int i, n;

	do {
		printf("\n");
		printf("**************单链表的基本操作及应用***************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  插入                                         *\n");
		printf("* 3  删除                                         *\n");
		printf("* 4  查找                                         *\n");
		printf("* 5  显示                                         *\n");
		printf("* 6  通讯录（应用）                               *\n");
		printf("* 7  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("--------创建单链表---------\n"); 
			printf("请输入链表元素个数和元素值:"); scanf_s("%d", &n);
			CreatList_L(L,n);
			break;
		case 2:
			printf("--------插入元素-------\n");
			printf("请输入插入位序和元素值:");
			scanf_s("%d%d", &i, &e);
			ListInsert_L(L, i, e);
			break;
		case 3:
			printf("--------删除元素-------\n");
			printf("请输入删除元素位序:"); scanf_s("%d", &i);
			ListDelete_L(L, i, e);
			break;
		case 4:
			printf("--------查找元素-------\n");
			printf("请输入被查找元素位序:"); scanf_s("%d", &i);
			if (GetElm_L(L, i, e)) printf("第%d个元素值为%d\n", i, e);
			else printf("第%d个元素不存在", i);
			break;
		case 5:
			printf("--------显示链表-------\n");
			DisplayLinkList(L);
			break;
		case 6:
			
			printf("--------通讯录---------\n");
			
			do {
				printf("请选择操作 1-创建通讯录 2-添加联系人 3-删除联系人 4-查找联系人 5-更新联系人信息 6-输出通讯录 7-退出\n");
				scanf_s("%d", &choice2);
				switch (choice2)
				{
				case 1:Adress_List(M);
					break;
				case 2:Add_adresslist(M);
					break;
				case 3:delet_adresslist(M);
					break;
				case 4:
					Search_adresslist(M);
					break;
				case 5:
					Update_adresslist(M);
					break;
				case 6:Print_adresslist(M);
					break;
				case 7:break;
				
				}

			} while (choice2!=7);
			
			break;
		case 7: break;
		
		}
	} while (choice!= 7);
}
//栈
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define BUFFERSIZE 256
typedef  char  SElemType;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}sqstack;                                                                     //定义栈底栈顶

int InitStack(sqstack &S) {
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));          //构建空栈
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
int Push(sqstack &S, SElemType e) {                                            // 入栈
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = e;
	S.top++;
	return OK;
}

int Pop(sqstack &S, SElemType &e) {                                             //出栈
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	S.top--;
	return OK;
}
int PrintTop(sqstack S, SElemType e) {                                         //取栈顶元素
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);

	cout << e << endl;
	return OK;
}
//判断空栈
int StackEmpty(sqstack S) {
	if (S.top == S.base)
		return OK;
	else return ERROR;
}
void Stack() {
	sqstack S;
	InitStack(S);
	SElemType e = NULL;
	char c;
	int n;
	do {
		printf("\n");
		printf("****************栈的基本操作及应用*****************\n");
		printf("* 1  进栈                                         *\n");
		printf("* 2  出栈                                         *\n");
		printf("* 3  取栈顶元素                                   *\n");
		printf("* 4  表达式求解（应用）                           *\n");
		printf("* 5  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("--------进栈-------\n");
			cout << "请输入一个字符" << endl;
			cin >> c;
			Push(S, c);
			break;
		case 2:
			printf("--------出栈-------\n");
			PrintTop(S, e);
			Pop(S, e);
			
			break;
		case 3:
			printf("--------取栈顶元素-------\n");
			PrintTop(S, e);
			break;
		case 4:
			printf("--------表达式求值-------\n"); break;
		case 5:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 5);
}
//数组
#define MAXSIZE 12500
#define defut_size 10
#define OK 1
typedef int ELemType;
typedef struct {
	int i, j;
	ELemType e;
}Triple;
typedef struct {
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;
}TSMatrix;
//用三元组创建稀疏矩阵
int CreatSMatrix(TSMatrix &M) {
	int i, m, n;
	ELemType e;

	printf("请输入矩阵行数,列数，非零元个数:\n");
	scanf_s("%d,%d,%d", &M.mu, &M.nu, &M.tu);
	for (i = 1; i <= M.tu; i++)
	{
		int k = 1;
		while (k) {
			printf("请按行序列输入:\n");
			scanf_s("%d,%d,%d", &m, &n, &e);
			k = 0;
			if (m<1 || m>M.mu || n<1 || n>M.nu)
				k = 1;
			if (m < M.data[i - 1].i || m == M.data[i - 1].i&&n <= M.data[i - 1].j)
				k = 1;
		}
		M.data[i].i = m;
		M.data[i].j = n;
		M.data[i].e = e;
	}
	return OK;
}
//输出矩阵三元组形式
int PrintSMatrix(TSMatrix M) {
	int i;
	printf("%d行%d列非零元个数:\n", M.mu, M.nu, M.tu);
	printf("  行   列     元素值\n");
	printf("------------------\n");
	for (int i = 1; i <= M.tu; i++)
	{
		printf("%4d%4d%8d\n", M.data[i].i, M.data[i].j, M.data[i].e);

	}
	return OK;
}
//输出矩阵矩阵形式
int PrintSMatrixs(TSMatrix M) {
	int i, j;
	printf("%d行%d列%d个非零元素。\n", M.mu, M.nu, M.tu);
	ELemType *temp = (ELemType *)malloc(M.mu*M.nu * sizeof(ELemType));
	for (i = 0; i < M.mu*M.nu; i++)temp[i] = 0;
	for (i = 1; i <= M.tu; i++)
		temp[(M.data[i].i - 1)*M.nu + M.data[i].j - 1] = M.data[i].e;
	for (i = 1; i <= M.mu; i++, puts("   "))
		for (j = 1; j <= M.nu; j++)
			printf("%d      ", temp[(i - 1)*M.nu + j - 1]);
	return OK;
}
//稀疏矩阵的转置
int TransposeSMatrix(TSMatrix M, TSMatrix &T) {
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	while (T.tu) {
		int q = 1;
		for (int col = 1; col <= M.nu; col++)
			for (int p = 1; p <= M.tu; p++)
				if (M.data[p].j == col)
				{
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					q++;
				}
		return OK;
	}

}
int MultSMatrixs(TSMatrix M, TSMatrix N, TSMatrix &Q) {
	if (M.nu != N.mu) return ERROR;
	Q.mu = M.mu; Q.nu = N.nu; Q.tu = 0;
	if (M.tu*N.tu != 0) {
		ELemType *q;
		q = (ELemType*)malloc((M.mu*N.nu+1) * sizeof(ELemType));
		for (int r = 0; r < M.mu*N.nu+1; r++) q[r] = 0;
		for (int m = 1; m <= M.tu; m++)
		{
			for (int n = 1; n <= N.tu; n++)
			{
				if (M.data[m].j == N.data[n].i)
					q[(M.data[m].i - 1)*Q.nu + N.data[n].j - 1] = q[(M.data[m].i - 1)*Q.nu + N.data[n].j - 1] + M.data[m].e*N.data[n].e;
			}
		}

		for (int k = 1; k <= Q.mu; k++)
		{
			for (int l = 1; l <= Q.nu; l++)
			{
				if (q[(k - 1)*Q.nu + l - 1])
				{
					Q.tu = Q.tu + 1;
					Q.data[Q.tu].i = k;
					Q.data[Q.tu].j = l;
					Q.data[Q.tu].e = q[(k - 1)*Q.nu + l - 1];
				}
			}
		}
		return OK;



	}
}

void Array() {
	TSMatrix M;
	TSMatrix N;
	TSMatrix Q;
	int n;
	do {
		printf("\n");
		printf("*************稀疏矩阵的压缩存储及应用**************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  显示                                         *\n");
		printf("* 3  矩阵乘法（应用）                             *\n");
		printf("* 4  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------创建-------\n");
			CreatSMatrix(M);
			
			break;
		case 2:
			printf("---------显示-------\n");
			PrintSMatrixs(M);
			break;
		case 3:
			printf("---------矩阵乘法-------\n");
			printf("请输入第一个矩阵\n");
			CreatSMatrix(M);
			printf("请输入第二个矩阵\n");
			CreatSMatrix(N);
			printf("矩阵相乘为\n");
			MultSMatrixs(M, N, Q);
			PrintSMatrixs(Q);
			break;
		case 4:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 4);
}

//二叉树
#define maxsize 60
typedef char TElemType;

typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


typedef struct {
	BiTree *base;
	BiTree *top;
	int stacksize;
}sqstack_Bitree;                                                                     //定义栈底栈顶

int InitStack_Bitree(sqstack_Bitree &S) {
	//S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));          //构建空栈
	S.base = new BiTree[maxsize];
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
int Push_Bitree(sqstack_Bitree &S, BiTree e) {                                            // 入栈
	if (S.top - S.base >= S.stacksize) {
		//S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = e;
	S.top++;
	return OK;
}

int Pop_Bitree(sqstack_Bitree &S, BiTree &e) {                                             //出栈
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	S.top--;
	return OK;
}                                                      //先序遍历创建二叉树

int StackEmpty_Bitree(sqstack_Bitree S) {
	if (S.top == S.base)
		return OK;
	else return ERROR;
}
//创建二叉树
int CreatBiTree(BiTree&T)
{
	char ch = NULL;
	cin >> ch;
	if (ch == '#')T = NULL;
	else {
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))exit(OVERFLOW);
		T->data = ch;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
	return OK;

}
int PrintElement(TElemType e)
{
	printf("%c", e);
	return OK;

}
//先序遍历二叉树
int PreOrderTraverse(BiTree T, int(*Visit)(TElemType e))
{
	if (T) {
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit)) return OK;
		return ERROR;
	}
	else return OK;
}
//中序遍历二叉树
int InOderTraverse(BiTree &T, int(*Visit)(TElemType e))
{
	if (T) {
		if (InOderTraverse(T->lchild, Visit))
			if (Visit(T->data))
				if (InOderTraverse(T->rchild, Visit)) return OK;
	}
	else return OK;

}
//后序遍历二叉树
int PostOderTraverse(BiTree &T, int(*Visit)(TElemType e))
{
	if (T) {
		if (PostOderTraverse(T->lchild, Visit))
			if (PostOderTraverse(T->rchild, Visit))
				if (Visit(T->data)) return OK;

	}
	else return OK;

}
//求二叉树高度
int Height_Of_Bitree(BiTree T)
{
	int L, R;
	if (T == NULL)
		return 0;
	else {
		L = Height_Of_Bitree(T->lchild);
		R = Height_Of_Bitree(T->rchild);
		return L > R ? L + 1 : R + 1;
	}

}
//求二叉树叶子结点个数
int Leaf_Of_Bitree(BiTree T) {
	if (T == NULL) return 0;
	if ((T->lchild == NULL) && (T->rchild == NULL)) return 1;
	return Leaf_Of_Bitree(T->lchild) + Leaf_Of_Bitree(T->rchild);
}
//栈方法遍历求非叶子结点的左孩子(中序)
int LeftChild(BiTree T, char huang, int(*Visit)(TElemType))
{
	sqstack_Bitree S; BiTree p = T;
	InitStack_Bitree(S);
	while (p || !StackEmpty_Bitree(S)) {
		if (p)
		{
			Push_Bitree(S, p);
			if (p->data == huang)
			{
				if (p->lchild == NULL)
				{
					printf("该结点无左孩子\n");
				}
				else { printf("该结点左孩子为:"); Visit(p->lchild->data); printf("\n"); }
			}
			p = p->lchild;
		}
		else
		{
			Pop_Bitree(S, p);
			p = p->rchild;
		}

	}
	return OK;
}
//栈方法遍历求非叶子结点的右孩子（中序）
int RightChild(BiTree T, char huang, int(*Visit)(TElemType))
{
	sqstack_Bitree S; BiTree p = T;
	InitStack_Bitree(S);
	while (p || !StackEmpty_Bitree(S)) {
		if (p)
		{
			Push_Bitree(S, p);
			if (p->data == huang)
			{
				if (p->rchild == NULL)
				{
					printf("该结点无右孩子\n");
				}
				else { printf("该结点右孩子为:"); Visit(p->rchild->data); printf("\n"); }
			}
			p = p->lchild;
		}
		else
		{
			Pop_Bitree(S, p);
			p = p->rchild;
		}

	}
	return OK;
}

//递归求非根结点双亲
int Parent(BiTree T, char huang, int(*Visit)(TElemType))
{
	if (T) {
		if (T->lchild) {
			if (T->lchild->data == huang)
				Visit(T->data);
			else {
				(Parent(T->lchild, huang, Visit));
				(Parent(T->rchild, huang, Visit));

			}
		}
		if (T->rchild) {
			if (T->rchild->data == huang)
				Visit(T->data);
			else {
				(Parent(T->lchild, huang, Visit));
				(Parent(T->rchild, huang, Visit));

			}
		}


		return OK;
	}
}


//队列的相关函数
typedef BiTree QElemType;
typedef struct QNode//队列节点，包括一个数据域和一个指针域，数据域为二叉树的指针类型
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front, rear; /* 队头、队尾指针 */
}LinkQueue;

int InitQueue(LinkQueue *Q)
{ /* 构造一个空队列Q */
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if (!(*Q).front)
		exit(OVERFLOW);
	(*Q).front->next = NULL;
	return OK;
}
int EnQueue(LinkQueue *Q, QElemType e)
{ /* 插入元素e为Q的新的队尾元素 */
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) /* 存储分配失败 */
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	(*Q).rear->next = p;
	(*Q).rear = p;
	return OK;
}
int QueueEmpty(LinkQueue Q)
{ /* 若Q为空队列,则返回TRUE,否则返回FALSE */
	if (Q.front == Q.rear)
		return OK;
	else
		return ERROR;
}
int DeQueue(LinkQueue *Q, QElemType *e)
{ /* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
	QueuePtr p;
	if ((*Q).front == (*Q).rear)
		return ERROR;
	p = (*Q).front->next;
	*e = p->data;
	(*Q).front->next = p->next;
	if ((*Q).rear == p)
		(*Q).rear = (*Q).front;
	free(p);
	return OK;
}


BiTree Point(BiTree T, TElemType s)
{ /* 返回二叉树T中指向元素值为s的结点的指针。另加 */
	LinkQueue q;
	QElemType a;
	if (T) /* 非空树 */
	{
		InitQueue(&q); /* 初始化队列 */
		EnQueue(&q, T); /* 根结点入队 */
		while (!QueueEmpty(q)) /* 队不空 */
		{
			DeQueue(&q, &a); /* 出队,队列元素赋给a */
			if (a->data == s)
				return a;
			if (a->lchild) /* 有左孩子 */
				EnQueue(&q, a->lchild); /* 入队左孩子 */
			if (a->rchild) /* 有右孩子 */
				EnQueue(&q, a->rchild); /* 入队右孩子 */
		}
	}
	return NULL;
}

//队列方法求双亲
TElemType Parent2(BiTree T, TElemType e)
{ /* 初始条件: 二叉树T存在,e是T中某个结点 */
	/* 操作结果: 若e是T的非根结点,则返回它的双亲,否则返回＂空＂ */
	LinkQueue q;
	QElemType a;
	if (T) /* 非空树 */
	{
		InitQueue(&q); /* 初始化队列 */
		EnQueue(&q, T); /* 树根入队 */
		while (!QueueEmpty(q)) /* 队不空 */
		{
			DeQueue(&q, &a); /* 出队,队列元素赋给a */
			if (a->lchild&&a->lchild->data == e || a->rchild&&a->rchild->data == e)
				/* 找到e(是其左或右孩子) */
				return a->data; /* 返回e的双亲的值 */
			else /* 没找到e,则入队其左右孩子指针(如果非空) */
			{
				if (a->lchild)
					EnQueue(&q, a->lchild);
				if (a->rchild)
					EnQueue(&q, a->rchild);
			}
		}
	}
	return NULL; /* 树空或没找到e */
}

TElemType LeftSibling(BiTree T, TElemType e)
{ /* 初始条件: 二叉树T存在,e是T中某个结点 */
	/* 操作结果: 返回e的左兄弟。若e是T的左孩子或无左兄弟,则返回＂空＂ */
	TElemType a;
	BiTree p;
	if (T) /* 非空树 */
	{
		a = Parent2(T, e); /* a为e的双亲 */
		p = Point(T, a);    /* p为指向结点a的指针 */
		if (p->lchild&&p->rchild&&p->rchild->data == e) /* p存在左右孩子且右孩子是e */
			return p->lchild->data; /* 返回p的左孩子(e的左兄弟) */
	}
	return NULL; /* 树空或没找到e的左兄弟 */
}

TElemType RightSibling(BiTree T, TElemType e)
{ /* 初始条件: 二叉树T存在,e是T中某个结点 */
	/* 操作结果: 返回e的右兄弟。若e是T的右孩子或无右兄弟,则返回＂空＂ */
	TElemType a;
	BiTree p;
	if (T) /* 非空树 */
	{
		a = Parent2(T, e); /* a为e的双亲 */
		p = Point(T, a); /* p为指向结点a的指针 */
		if (p->lchild&&p->rchild&&p->lchild->data == e) /* p存在左右孩子且左孩子是e */
			return p->rchild->data; /* 返回p的右孩子(e的右兄弟) */
	}
	return NULL; /* 树空或没找到e的右兄弟 */
}



//void Find_bro(BiTree T,char huang , int(*Visit)(TElemType))
//{
//	if (T) {
//		if (T->lchild->data == huang)
//			if (T->rchild) Visit(T->rchild->data);
//			else T = T->lchild;
//		Find_bro(T, huang, Visit);
//	}
//
//
//
//}

void Bitree() {
	BiTree T = NULL;
	char ch1;
	char ch2;
	int n;
	do {
		printf("\n");
		printf("**************二叉树的基本操作及应用***************\n");
		printf("* 1  创建二叉树                                   *\n");
		printf("* 2  遍历二叉树（先/中/后）                       *\n");
		printf("* 3  计算树的深度                                 *\n");
		printf("* 4  计算叶子结点个数                             *\n");
		printf("* 5  查找双亲                                     *\n");
		printf("* 6  查找兄弟                                     *\n");
		printf("* 7  Huffman编码（应用）                          *\n");
		printf("* 8  退出\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------创建二叉树--------\n");
			CreatBiTree(T);
			break;
		case 2:
			printf("---------*遍历二叉树-------\n");
			printf("该二叉树先序序列为:\n");
			PreOrderTraverse(T, PrintElement);
			printf("\n");
			printf("该二叉树中序序列为:\n");
			InOderTraverse(T, PrintElement);
			printf("\n");
			printf("该二叉树后序序列为:\n");
			PostOderTraverse(T, PrintElement);
			printf("\n");
			break;
		case 3:
			printf("---------计算树的深度------\n");
			printf("该二叉树高为:%d\n", Height_Of_Bitree(T));
			break;
		case 4:
			printf("---------计算叶子结点个数-------\n");
			printf("该二叉树叶子结点数为:%d\n", Leaf_Of_Bitree(T));
			break;
		case 5:
			printf("---------查找双亲-------\n");
			printf("请输入结点的数据值:\n");
			cin >> ch1;
			Parent(T, ch1, PrintElement);
			break;
		case 6:
			printf("---------查找兄弟-------\n");
			printf("请输入结点的数据值:\n");
			cin >> ch2;
			if(LeftSibling(T,ch2))
				printf("该点有左兄弟:%c\n", LeftSibling(T, ch2));
			else if(RightSibling(T,ch2))
				printf("该点有右兄弟:%c\n", RightSibling(T, ch2));
			else printf("该点没有兄弟");
			break;
		case 7:
			printf("---------Huffman编码-------\n"); break;
		case 8:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 8);
}

//图
#define MAX_VERTEX_NUM 20
#define Flase 0
#define True 1
int visited[MAX_VERTEX_NUM];
typedef int InfoType;
typedef char VertexType;


typedef struct ArcNode {        //弧结点类型
	int adjvex;
	struct ArcNode *nextarc;
	InfoType *info;
}ArcNode;

typedef struct {                //邻接链表
	VertexType data;
	ArcNode   *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;
//返回输入字符在结点数组中的位置
int Get_Position(ALGraph G, char ch)
{
	for (int i = 0; i < G.vexnum; i++)
		if (G.vertices[i].data == ch)
			return i;
	return ERROR;
}
//读入一个字符
char Get_Char()
{
	char ch;
	cin >> ch;

	if (('ch' >= 'a'&&ch <= 'z') || ('ch' >= 'A'&&'ch' <= 'Z'))
		return ch;
	else return ERROR;
}

void Node_Link(ALGraph &G, ArcNode  *list, ArcNode *node1, ArcNode  *node2)
{
	ArcNode *p = list;
	node2->nextarc = p;
	G.vertices[node1->adjvex].firstarc = node2;

}
//邻接表创建无向图
void Creat_Graph(ALGraph & G)
{
	char c1, c2;
	ArcNode *node1 = NULL, *node2 = NULL;
	cout << "请输入顶点个数" << endl;
	cin >> G.vexnum;
	cout << "请输入边的个数" << endl;
	cin >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++)                   //初始化顶点信息
	{
		G.vertices[i].data = Get_Char();

		G.vertices[i].firstarc = NULL;
	}
	for (int i = 0; i < G.arcnum; i++)
	{
		c1 = Get_Char();
		c2 = Get_Char();
		node1 = (ArcNode*)malloc(sizeof(ArcNode));
		node2 = (ArcNode*)malloc(sizeof(ArcNode));
		node1->adjvex = Get_Position(G, c1);

		node2->adjvex = Get_Position(G, c2);

		if (G.vertices[node1->adjvex].firstarc == NULL)             //将弧结点连接到各顶点邻接单链表中   
		{
			node2->nextarc = NULL;
			G.vertices[node1->adjvex].firstarc = node2;
		}
		else Node_Link(G, G.vertices[node1->adjvex].firstarc, node1, node2);



		if (G.vertices[node2->adjvex].firstarc == NULL)
		{
			node1->nextarc = NULL;
			G.vertices[node2->adjvex].firstarc = node1;
		}
		else Node_Link(G, G.vertices[node2->adjvex].firstarc, node2, node1);


	}

}
//建立无向网
int CreateUDN(ALGraph &G)
{
	int i, w ,d, s;
	
	ArcNode *p, *q;
	printf("输入结点数目和边数\n");
	scanf_s("%d%d", &G.vexnum, &G.arcnum);   /* 输入结点数目和边数 */
	
	getchar();

	printf("输入顶点\n");
	for (i = 0; i < G.vexnum; i++)      /* 输入顶点 */
	{
		scanf_s("%c", &G.vertices[i].data,3); /* 输入顶点 */
		getchar();
		G.vertices[i].firstarc= NULL;  /* 首先初始化为NULL */
	}

	for (i = 1; i <= G.arcnum; i++)
	{
		printf("输入一条边依附的起点序号和终点序号\n");
		cin >> s;  /* 输入一条边依附的起点序号和终点序号 */
		cin >> d;
		cin >> w;
		p= (struct ArcNode*)malloc(sizeof(struct ArcNode));
		q = (struct ArcNode*)malloc(sizeof(struct ArcNode));

		p->info = (InfoType *)malloc(sizeof(InfoType));
		q->info = (InfoType *)malloc(sizeof(InfoType));

		p->adjvex= d;/* 保存该弧所指向的顶点位置 */
		q->adjvex = s;/* 保存该弧所指向的顶点位置 */

		*(p->info) = w;/* 保存权值到一个结点里 */
		*(q->info) = w;/* 保存权值到一个结点里 */

		p->nextarc= G.vertices[s].firstarc;
		G.vertices[s].firstarc= p;

		q->nextarc= G.vertices[d].firstarc;
		G.vertices[d].firstarc= q;
	}
	return OK;
}

//邻接表建立有向图 
int CreateDG(ALGraph &G)
{
	int i, s, d;
	ArcNode*p;
	printf("输入结点数目和边数\n");
	scanf_s("%d%d", &G.vexnum, &G.arcnum);/* 输入结点数目和边数 */
	getchar();
	printf("输入顶点\n");
	for (i = 0; i < G.vexnum; i++)/* 输入顶点 */
	{
		scanf_s("%c", &G.vertices[i].data,3);/* 输入顶点 */
		getchar();
		G.vertices[i].firstarc = NULL;/* 首先初始化为NULL */
	}
	
	for (i = 1; i <= G.arcnum; i++)
	{
		printf("输入一条边依附的起点序号和终点序号\n");
		cin >> s;  /* 输入一条边依附的起点序号和终点序号 */
		cin >> d;
		
		p= (struct ArcNode*)malloc(sizeof(struct ArcNode));

		p->adjvex= d;/* 保存该弧所指向的终点位置 *//*下两句代码相当于单链表的插入操作*/
		p->nextarc= G.vertices[s].firstarc;/* 保存顶点所对应的终点位置 */
		G.vertices[s].firstarc = p;
	}
	return OK;
}

//邻接表建立有向网
int CreateDN(ALGraph &G)
{
	int i, s, d, w;
	ArcNode*p;
	printf("输入结点数目和边数 \n");
	scanf_s("%d%d", &G.vexnum, &G.arcnum);/* 输入结点数目和边数 */
	getchar();
	printf("输入顶点 \n");
	for (i = 0; i < G.vexnum; i++)/* 输入顶点 */
	{
		scanf_s("%c", &G.vertices[i].data,3);/* 输入顶点 */
		getchar();
		G.vertices[i].firstarc= NULL;/* 首先初始化为NULL */
	}

	for (i = 1; i <= G.arcnum; i++)
	{
		printf("输入一条边依附的起点序号和终点序号 \n");
		cin >> s;  /* 输入一条边依附的起点序号和终点序号 */
		cin >> d;
		cin >> w;
		getchar();
		p= (struct ArcNode*)malloc(sizeof(struct ArcNode));

		p->adjvex = d;/* 保存该弧所指向的终点位置 */

		p->info = (InfoType*)malloc(sizeof(InfoType));
		*(p->info) = w;/* 下两句代码相当于单链表的插入操作 */
		p->nextarc= G.vertices[s].firstarc;/* 保存顶点所对应的终点位置 */
		G.vertices[s].firstarc= p;
	}
	return OK;
}

//输出无向图的邻接表
void Print_Infograph(ALGraph G)
{
	int i = 0;
	ArcNode *node = NULL;
	printf("图信息如下:\n");
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%d(%c) ", i, G.vertices[i].data);
		node = G.vertices[i].firstarc;
		while (node)
		{
			printf("—>%d(%c) ", node->adjvex, G.vertices[node->adjvex].data);

			node = node->nextarc;
		}
		printf("\n");
	}

}
//打印无向网
void PrintALGraphUDN(ALGraph G)/* 打印无向网每个结点的单链表 */
{
	int i = 0;
	ArcNode *node = NULL;
	printf("图信息如下:\n");
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%d(%c) ", i, G.vertices[i].data);
		node = G.vertices[i].firstarc;
		while (node)
		{
			printf("—>(weight:%d)%d(%c) ",*(node->info), node->adjvex, G.vertices[node->adjvex].data);

			node = node->nextarc;
		}
		printf("\n");
	}
}

//打印有向图
void PrintALGraphDG(ALGraph G)/* 打印有向图每个结点的单链表 */
{
	int i = 0;
	ArcNode *node = NULL;
	printf("图信息如下:\n");
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%d(%c) ", i, G.vertices[i].data);
		node = G.vertices[i].firstarc;
		while (node)
		{
			printf("—>%d(%c) ", node->adjvex, G.vertices[node->adjvex].data);

			node = node->nextarc;
		}
		printf("\n");
	}
}
//打印有向网
void PrintALGraphDN(ALGraph G)
{
	int i = 0;
	ArcNode *node = NULL;
	printf("图信息如下:\n");
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%d(%c) ", i, G.vertices[i].data);
		node = G.vertices[i].firstarc;
		while (node)
		{
			printf("—>(weight:%d)%d(%c) ", *(node->info), node->adjvex, G.vertices[node->adjvex].data);

			node = node->nextarc;
		}
		printf("\n");
	}
}


int LocateVex(ALGraph G, VertexType v) {
	//确定点v在G中的位置
	for (int i = 0; i < G.vexnum; ++i)
		if (G.vertices[i].data == v)
			return i;
	return -1;
}


typedef int QElemType1;
typedef struct QNode1//队列节点，包括一个数据域和一个指针域，数据域为二叉树的指针类型
{
	QElemType1 data;
	struct QNode1 *next;
}QNode1, *QueuePtr1;

typedef struct
{
	QueuePtr1 front, rear; /* 队头、队尾指针 */
}LinkQueue1;

int InitQueue1(LinkQueue1 *Q)
{ /* 构造一个空队列Q */
	(*Q).front = (*Q).rear = (QueuePtr1)malloc(sizeof(QNode1));
	if (!(*Q).front)
		exit(OVERFLOW);
	(*Q).front->next = NULL;
	return OK;
}
int EnQueue1(LinkQueue1 *Q, QElemType1 e)
{ /* 插入元素e为Q的新的队尾元素 */
	QueuePtr1 p = (QueuePtr1)malloc(sizeof(QNode1));
	if (!p) /* 存储分配失败 */
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	(*Q).rear->next = p;
	(*Q).rear = p;
	return OK;
}
int QueueEmpty1(LinkQueue1 Q)
{ /* 若Q为空队列,则返回TRUE,否则返回FALSE */
	if (Q.front == Q.rear)
		return OK;
	else
		return ERROR;
}
int DeQueue1(LinkQueue1 *Q, QElemType1 *e)
{ /* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
	QueuePtr1 p;
	if ((*Q).front == (*Q).rear)
		return ERROR;
	p = (*Q).front->next;
	*e = p->data;
	(*Q).front->next = p->next;
	if ((*Q).rear == p)
		(*Q).rear = (*Q).front;
	free(p);
	return OK;
}

void BFS(ALGraph G, int v) {
	LinkQueue1 Q;
	ArcNode *p;
	QElemType1 u;
	for (int i = 0; i < G.vexnum; i++)visited[i] = 0;
	cout << G.vertices[v].data << "   ";
	visited[v] = True;//置已访问标记
	InitQueue1(&Q);
	EnQueue1(&Q, v);                          //访问过的顶点入队列
	while (!QueueEmpty1(Q)) {
		DeQueue1(&Q, &u);
		p = G.vertices[u].firstarc;          //找到 v 的第一个邻接点
		while (p != NULL)                      /*判断邻接点是否存在*/
		{
			if (!visited[p->adjvex])         //邻接点存在未被访问
			{
				cout << G.vertices[p->adjvex].data << "   ";
				visited[p->adjvex] = True;       //置已访问标志
				EnQueue1(&Q, p->adjvex);      //邻接点入队列
			}
			p = p->nextarc;   //沿着 v 的邻接点链表顺序搜索
		}
	}
}

void DFS(ALGraph G, int v)
{
	//按深度优先递归遍历连通图G
	//图G为邻接表类型
	cout << G.vertices[v].data << "   ";
	visited[v] = True;    						//访问第v个顶点，并置访问标志数组相应分量值为true
	ArcNode *p = G.vertices[v].firstarc;		//p指向v的边链表的第一个边结点
	while (p != NULL) {              				//边结点非空
		int w = p->adjvex;               		//表示w是v的邻接点
		if (!visited[w])  DFS(G, w);   			//如果w未访问，则递归调用DFS
		else p = p->nextarc;
	}
}




void Graph() {
	ALGraph G;
	int n;
	do {
		printf("\n");
		printf("****************图的基本操作及应用*****************\n");
		printf("* 1  创建无向图                                    *\n");
		printf("* 2  创建无向网                                    *\n");
		printf("* 3  创建有向图                                    *\n");
		printf("* 4  创建有向网                                    *\n");
		printf("* 5  遍历                                          *\n");
		printf("* 6  拓扑排序                                      *\n");
		printf("* 7  最小生成树（应用）                            *\n");
		printf("* 8  最短路径（应用）                              *\n");
		printf("* 9  关键路径（应用）                              *\n");
		printf("* 10 退出                                          *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------创建无向图-------\n");
			Creat_Graph(G);
			Print_Infograph(G);

			break;
		case 2:
			printf("---------创建无向网-------\n");
			CreateUDN(G);
			PrintALGraphUDN(G);
			break;
		case 3:
			printf("---------创建有向图-------\n");
			CreateDG(G);
			PrintALGraphDG(G);
			break;
		case 4:
			printf("---------创建有向网-------\n");
			CreateDN(G);
			PrintALGraphDN(G);
			break;
		case 5:
			printf("---------遍历-------\n");
			printf("请选择遍历方式 1-广度遍历 2-深度遍历\n");
			int ce;
			scanf_s("%d", &ce);
			switch (ce) {
			case 1:printf("请输入遍历开始结点数据值\n");
				int v;
				scanf_s("%d",&v);
				BFS(G,v);
				break;
			case 2:
				printf("请输入遍历开始结点数据值\n");
				int s;
				scanf_s("%d", &s);
				DFS(G, s);
				break;
			}
			
			break;
		case 6:
			printf("---------拓扑排序-------\n"); break;
		case 7:
			printf("---------最小生成树-------\n"); break;
		case 8:
			printf("---------最短路径-------\n"); break;
		case 9:
			printf("---------关键路径-------"); break;
		case 10:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 10);
}

void main() {
	int main_choice;
	do {
		ShowMainMenu();
		printf("请选择：");
		scanf_s("%d", &main_choice);
		switch (main_choice) {
		case 1:Linklist(); break;
		case 2:Stack(); break;
		case 3:Array(); break;
		case 4:Bitree(); break;
		case 5:Graph(); break;
		case 6:break;
		default:printf("ERROR!"); break;
		}
	} while (main_choice != 6);
}

