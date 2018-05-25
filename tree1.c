/*
 *	二叉树的创建与遍历
 *
 */
#include <stdio.h>
#include <stdlib.h>


typedef char ElemType;


/* 二叉树结构 */
typedef struct BiTNode 
{
	ElemType Data; /* 节点数据 */
	struct BiTNode *lchild, *rchild; /* 左右孩子指针 */

}BiTNode, *BiTree;


/* 二叉树的建立 */
/* 按前序输入二叉树结点的值 */
void CreateBiTree(BiTree *T)
{
	ElemType ch;
	ElemType temp;

	scanf("%c", &ch);
	temp = getchar();


	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (*T == NULL)
		{
			exit(-1);
		}
		
		(*T)->Data = ch; /* 生成根结点 */
		printf("输入%c的左孩子：", ch);
		CreateBiTree(&(*T)->lchild); /* 构造左子树 */
		printf("输入%c的右孩子：", ch);
		CreateBiTree(&(*T)->rchild); /* 构造右子树 */
	}
}


/* 二叉树的遍历 */
/* 前序遍历法 */
void BiTreeTravalB(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	
	printf("%c", T->Data); /* 打印结点值 */

	BiTreeTravalB(T->lchild); 
	BiTreeTravalB(T->rchild);
}

/* 中序遍历法 */
void BiTreeTravalM(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	
	BiTreeTravalM(T->lchild);

	printf("%c", T->Data);

	BiTreeTravalM(T->rchild);
}


/* 后序遍历法 */
void BiTreeTravalZ(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	
	BiTreeTravalZ(T->lchild);

	//printf("%c", T->Data);
	BiTreeTravalZ(T->rchild);
	
	printf("%c", T->Data);
}




int main()
{
	BiTree Tree;

	CreateBiTree(&Tree);
	
	printf("traval result:\n");
	
	//BiTreeTravalB(Tree);
	//BiTreeTravalM(Tree);
	BiTreeTravalZ(Tree);

	printf("\n");

	return 0;
}








