#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode, * LinkedList;
typedef enum Status {
    error,
    success
} Status;

//º¯ÊýµÄÉùÃ÷
Status InitList(LinkedList L);
void DestroyList(LinkedList L);
Status InsertList(LNode* p, ElemType data);
Status DeleteList(LNode* p, ElemType e);
void TraverseList(LinkedList L);
Status SearchList(LinkedList L, ElemType e);
Status ReverseList(LinkedList* L);
Status ringlist(LinkedList L);
Status xchangelist(LinkedList L,int x);
LNode* FindMidNode(LinkedList L);
void show(void);
int judge_int(void);
