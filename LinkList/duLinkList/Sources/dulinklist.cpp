#include"dulinklist.h"
Status InitList_DuL(DuLinkedList* L) {
    DuLinkedList List;
    List = (DuLinkedList)malloc(sizeof(DuLNode));//头结点不存有有效数据
    if (List == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    List->right = NULL;
    List->left = NULL;
    *L = List;
    return success;
}

void DestroyList_DuL(DuLinkedList* L) {
    DuLinkedList temp;

    while (*L != NULL)
    {
        temp = *L;
        *L = (*L)->right;
        free(temp);
    }
}

Status InsertLeftList_DuL(DuLNode* p, DuLNode* q) {
    if (p->right == NULL)//当链表为空时，直接连接p、q，使得q成为第一个节点
    {
        p->right = q;
        q->left = p;
    }
    else
    {
        DuLinkedList temp;
        temp = p->right;//temp标记未插入前的第一个节点
        p->right = q;//将新节点赋给第一个节点的位置
        q->right = temp;//将新节点的右端与原先的第一个节点连接
        temp->left = q;//新节点与第一个节点的左端连接
        q->left = p;
        return success;
    }
}

Status InsertRightList_DuL(DuLNode* p, DuLNode* q) {
    while (p->right != NULL)//直接遍历到链表最右端
    {
        p = p->right;
    }
    p->right = q;//将节点相连接
    q->left = p;
    return success;
}

Status DeleteList_DuL(DuLNode* p, ElemType* e) {
    if (p->right == NULL)
    {
        printf("链表为空，无法删除\n");
        return error;
    }
    else
    {
        DuLinkedList posNode = p->right, posNodeFront = p;
        //找到删除结点的位置
        while (posNode->data != *e)
        {
            posNodeFront = posNode;//双指针开始右移，直到找到目标数据或者到最后一个节点
            posNode = posNode->right;
            if (posNode == NULL)//到链表尽头
            {
                printf("该数据不存在\n");
                return error;
            }
        }
        if (posNode->right != NULL)//如果目标节点不是最后一个节点，将目标节点的左节点与右节点相连
        {
            posNodeFront->right = posNode->right;
            posNode->right->left = posNodeFront;
        }
        else//如果目标节点是最后一个节点，直接断开连接
        {
            posNodeFront-> right= NULL;
        }
        free(posNode);
        return success;
    }
}
Status Reverselist_DuL(DuLinkedList L) {
    DuLinkedList p1=L->right;
    DuLinkedList left = NULL;
    DuLinkedList right = NULL;
    while (p1 != NULL)//每次只改变一个节点左右指针的指向，循环完后即可让反向改变从而反转
    {
        right = p1->right;//标记下一个节点
        p1->right = left;//让当前所在节点的右指针指向左节点
        p1->left = right;//让当前所在节点的左指针指向右节点
        left = p1;//指针循环往右移动
        p1 = right;//让当前节点位置往后移动从而实现每个节点的左右指针改向
    }
    L->right = left;//链表反转后，应该让头结点（辅助节点）的右端指向最后一个节点
    return success;
}

void TraverseList_DuL(DuLinkedList L) {
    if (L == NULL)
    {
        printf("未创建链表，请创建链表\n");
    }
    else if (L->right == NULL)
    {
        printf("当前链表为空\n");
    }
    else
    {
        DuLinkedList temp = L->right;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->right;
        }
        printf("\n");
    }
}

void show(void)
{
    printf("\n\n\n\n双链表ADT\n\n");
    printf("1.创建空链表\n");
    printf("2.销毁链表\n");
    printf("3.头插法插入数据\n");
    printf("4.尾插法插入数据\n");
    printf("5.删除数据\n");
    printf("6.遍历链表\n");
    printf("7.反转链表\n");
    printf("8.退出\n");
    printf("\n请输入对应的数字(1-8)：");
}

int judge_int(void)  //防止用户乱输入其他的字符
{
    int len, num = 0, arg = 1;
    char word[10];
    int m, j = 1, k;
    while (j)
    {
        scanf_s("%s", word,9);
        len = strlen(word);
        for (m = 0; m < len; m++)//逐个元素检查
        {
            if (word[m] < '0' || word[m]>'9')  //检验是否有乱输入其他字符
            {
                printf("请输入整数：");
                break;
            }
            else
            {
                if (m == len - 1)
                    j = 0;//如果所有元素都是数字，进入下一步判断数字是否合法
            }
        }
    }
    j = len - 1;
    for (m = 0; m < len; m++)  // 将字符重新转换为数字
    {
        for (k = 0; k < j; k++)
            arg *= 10;
        num += (word[m] - '0') * arg;
        arg = 1;
        j--;
    }
    return num;
}

int main(void)
{
    int choice, num = 0;
    DuLinkedList head;
    head = NULL;

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch (choice)
        {
        case 1://创建空链表
        {
            if (InitList_DuL(&head))
            {
                printf("空链表创建成功\n");
            }
            else
            {
                printf("空链表创建失败\n");
            }
            break;
        }
        case 2://销毁链表
        {
            DestroyList_DuL(&head);
            printf("链表销毁成功\n");
            break;
        }
        case 3://左插法插入数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                DuLinkedList newNode;//创建新节点
                if (InitList_DuL(&newNode))//赋予新节点数据
                {
                    printf("请输入数据：");
                    scanf_s("%d", &newNode->data);
                    if (InsertLeftList_DuL(head, newNode))//开始插入数据
                    {
                        printf("数据插入成功\n");
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                else
                {
                    printf("数据插入失败\n");
                }
            }
            break;
        }
        case 4://右插法插入数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else//同上
            {
                DuLinkedList newNode;
                if (InitList_DuL(&newNode))
                {
                    printf("请输入数据：");
                    scanf_s("%d", &newNode->data);
                    if (InsertRightList_DuL(head, newNode))
                    {
                        printf("数据插入成功\n");
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                else
                {
                    printf("数据插入失败\n");
                }
            }
            break;
        }
        case 5://删除数据
        {
            if (head == NULL)
            {
                printf("链表未创建，请先创建链表\n");
            }
            else
            {
                printf("你要删除的数据为：");
                scanf_s("%d", &num);
                if (DeleteList_DuL(head, &num))
                {
                    printf("数据删除成功\n");
                }
                else
                {
                    printf("数据删除失败\n");
                }
            }
            break;
        }
        case 6://遍历链表
        {
            TraverseList_DuL(head);
            break;
        }
        case 7://反转链表
        {
            if (head == NULL || head->right == NULL)
            {
                printf("链表为空或者链表只含有两个结点\n");
                printf("链表反转失败\n");
            }
            else
            {
                if (Reverselist_DuL(head))
                {
                    printf("链表反转成功\n");
                }
                else
                {
                    printf("链表反转失败\n");
                }

            }
            break;
        }
        case 8://退出程序 
        {
            DestroyList_DuL(&head);
            break;
        }
        default:
        {
            printf("请重新输入数字!(1-8)\n");
            break;
        }
        }
    } while (choice != 8);//当输入7的时候循环结束，退出

    return 0;
}