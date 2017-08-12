/*****************************************************************************
*                                                                            *
*  @file     SLL.c                                                           *
*  @brief    单链实现文件                                                      *
*                                                                            *
*  @author   Duanxx                                                          *
*  @email    duanxxnj@163.com                                                *
*  @date     2017-08-11                                                      *
*                                                                            *
*****************************************************************************/


#include "Table/SLL/src/SLL.h"

/**
* @brief   单链表初始化
*       单链表的初始化仅仅是将单链表的头指针和尾指针置为空
*       同时将单链表的个数置为0
*/
RET_E SLL_init(pSLL_S pSLL)
{
    if (pSLL == NULL)
    {
        return DUANXX_ERR;
    }

    pSLL->pHead = NULL;
    pSLL->pTail = NULL;
    pSLL->num = 0;

    return DUANXX_OK;
}

/**
* @brief   向单链表头添加节点
*           
* @param pSll    单链表指针
* @param pNode   节点指针
*
*       1、如果 pSll 或者 pNode 有一个为NULL，则退出
*       2、如果单链表的节点数目为0，则单链表头指针和尾指针指向该节点，且链表节点数目为1
*       3、如果单链表的节点数目>=1，则单链表头插入节点，且链表节点数目自增1
*/
RET_E SLL_addNodeToHead(pSLL_S pSll, pSLL_NODE_S pNode)
{
     if (pSll == NULL || pNode == NULL)
     {
         return DUANXX_ERR;
     }

     if (pSll->num == 0)
     {
         pSll->pHead = pNode;
         pSll->pTail = pNode;
         pSll->num = 1;
         return DUANXX_OK;
     }

     pNode->pNext = pSll->pHead;
     pSll->pHead = pNode;
     pSll->num = pSll->num + 1;

     return DUANXX_OK;
}