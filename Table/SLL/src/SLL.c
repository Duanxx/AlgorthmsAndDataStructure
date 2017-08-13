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
    /** 1 */
    if (pSll == NULL || pNode == NULL)
    {
        return DUANXX_ERR;
    }

    /** 2 */
    if (pSll->num == 0)
    {
        pSll->pHead = pNode;
        pSll->pTail = pNode;
        pSll->num = 1;
        return DUANXX_OK;
    }

    /** 3 */
    pNode->pNext = pSll->pHead;
    pSll->pHead = pNode;
    pSll->num = pSll->num + 1;

    return DUANXX_OK;
}


/**
* @brief   向单链表尾添加节点
*           
* @param pSll    单链表指针
* @param pNode   节点指针
*
*       1、如果 pSll 或者 pNode 有一个为NULL，则退出
*       2、如果单链表的节点数目为0，则单链表头指针和尾指针指向该节点，且链表节点数目为1
*       3、如果单链表的节点数目>=1，则单链表尾插入节点，且链表节点数目自增1
*/
RET_E SLL_addNodeToTail(pSLL_S pSll, pSLL_NODE_S pNode)
{
    /** 1 */
    if (pSll == NULL || pNode == NULL)
    {
        return DUANXX_ERR;
    }

    /** 2 */
    if (pSll->num == 0)
    {
        pSll->pHead = pNode;
        pSll->pTail = pNode;
        pSll->num = 1;
        return DUANXX_OK;
    }

    /** 3 */
    pNode->pNext = NULL;
    pSll->pTail->pNext = pNode;
    pSll->pTail = pNode;
    pSll->num = pSll->num + 1;
    return DUANXX_OK;
}


/**
* @brief   从单链表头删除节点
*
*       在使用free(ptr);后，一定要做 ptr = NULL;
*       这里直接使用宏定义：DUANXX_Free(ptr)实现
*
* @param pSll    单链表指针
*
*       1、如果 pSll为 NULL，则退出
*       2、如果单链表的节点数目为0，则退出
*       3、如果单链表的节点数目为1，删除该节点，且pSll的头指针和尾指针为空，pSll的节点数目为0
*       4、如果单链表的节点数目>1，删除头节点，pSll的节点数目自减1
*
*/
RET_E SLL_deleteFromHead(pSLL_S pSll)
{
    pSLL_NODE_S pTmpNode = NULL;

    /** 1、2 */
    if (pSll == NULL || pSll->num == 0)
    {
        return DUANXX_ERR;
    }

    /** 3 */
    if (pSll->num == 1)
    {
        Duanxx_Free(pSll->pHead);
        SLL_init(pSll);
        return DUANXX_OK;
    }

    /** 4 */
    pTmpNode = pSll->pHead->pNext;
    Duanxx_Free(pSll->pHead);
    pSll->pHead = pTmpNode;
    pSll->num =  pSll->num - 1;

    return DUANXX_OK;
}

/**
* @brief   从单链表尾部删除节点
*
*
* @param pSll    单链表指针
*
*       1、如果 pSll为 NULL，则退出
*       2、如果单链表的节点数目为0，则退出
*       3、如果单链表的节点数目为1，删除该节点，且pSll的头指针和尾指针为空，pSll的节点数目为0
*       4、如果单链表的节点数目>1，删除尾节点，pSll的节点数目自减1
*
*/
RET_E SLL_deleteFromTail(pSLL_S pSll)
{
    pSLL_NODE_S pTmpNode = NULL;

    /** 1、2 */
    if (pSll == NULL || pSll->num == 0)
    {
        return DUANXX_ERR;
    }

    /** 3 */
    if (pSll->num == 1)
    {
        Duanxx_Free(pSll->pTail);
        SLL_init(pSll);
        return DUANXX_OK;
    }

    /** 4 */
    pTmpNode = pSll->pHead;
    while(pTmpNode->pNext != pSll->pTail)
    {
        pTmpNode = pTmpNode->pNext;
    }
    Duanxx_Free(pSll->pTail);
    pSll->pTail = pTmpNode;
    pSll->num = pSll->num - 1;

    return DUANXX_OK;
}