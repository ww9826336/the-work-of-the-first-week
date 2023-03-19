#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef int ElemType;
typedef struct DuLNode {
    ElemType data;
    struct DuLNode* left, * right;//分别为左指针与右指针；
} DuLNode, * DuLinkedList;
typedef enum Status {
    error,
    success,
} Status;

//函数的声明
Status InitList_DuL(DuLinkedList* L);//创建空链表
void DestroyList_DuL(DuLinkedList* L);//清空链表
Status InsertLeftList_DuL(DuLNode* p, DuLNode* q);//左插入数据
Status InsertRightList_DuL(DuLNode* p, DuLNode* q);//右插入数据
Status DeleteList_DuL(DuLNode* p, ElemType* e);//删除链表中的指定数据
void TraverseList_DuL(DuLinkedList L);//遍历链表
Status Reverselist_DuL(DuLinkedList L);
void show(void);
int judge_int(void);
