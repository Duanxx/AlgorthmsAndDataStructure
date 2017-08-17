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
    pSLL->ulNum = 0;

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
    if (pSll->ulNum == 0)
    {
        pSll->pHead = pNode;
        pSll->pTail = pNode;
        pSll->ulNum = 1;
        return DUANXX_OK;
    }

    /** 3 */
    pNode->pNext = pSll->pHead;
    pSll->pHead = pNode;
    pSll->ulNum = pSll->ulNum + 1;

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
    if (pSll->ulNum == 0)
    {
        pSll->pHead = pNode;
        pSll->pTail = pNode;
        pSll->ulNum = 1;
        return DUANXX_OK;
    }

    /** 3 */
    pNode->pNext = NULL;
    pSll->pTail->pNext = pNode;
    pSll->pTail = pNode;
    pSll->ulNum = pSll->ulNum + 1;
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
    if (pSll == NULL || pSll->ulNum == 0)
    {
        return DUANXX_ERR;
    }

    /** 3 */
    if (pSll->ulNum == 1)
    {
        Duanxx_Free(pSll->pHead);
        SLL_init(pSll);
        return DUANXX_OK;
    }

    /** 4 */
    pTmpNode = pSll->pHead->pNext;
    Duanxx_Free(pSll->pHead);
    pSll->pHead = pTmpNode;
    pSll->ulNum =  pSll->ulNum - 1;

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
    if (pSll == NULL || pSll->ulNum == 0)
    {
        return DUANXX_ERR;
    }

    /** 3 */
    if (pSll->ulNum == 1)
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
    pSll->ulNum = pSll->ulNum - 1;

    return DUANXX_OK;
}

/**
* @brief   释放一个单链表
*
* @param pSll    单链表指针
*
*       1、如果 pSll为 NULL，则退出
*       2、如果单链表的节点数目为0，则退出
*       3、如果单链表的节点数目>=1，则pSll的头指针和尾指针为空，pSll的节点数目为0
*/
RET_E SLL_freeList(pSLL_S pSll)
{
    pSLL_NODE_S pTmpNode = NULL;
    pSLL_NODE_S pTmpNextNode = NULL;

    /** 1、2 */
    if (pSll == NULL || pSll->ulNum == 0)
    {
        return DUANXX_ERR;
    }

    /** 3 */
    pTmpNode = pSll->pHead;
    while(pTmpNode != NULL)
    {
        pTmpNextNode = pTmpNode->pNext;
        Duanxx_Free(pTmpNode);
        pTmpNode = pTmpNextNode;
    }

    SLL_init(pSll);
    return DUANXX_OK;
}

/**
* @brief   将链表的数据打印出来
*
* @param pSll    单链表指针
*
*       1、如果 pSll为 NULL，则退出
*       2、如果单链表的节点数目为0，则提示链表为空
*       3、如果单链表的节点数目>=1，则将链表打印出来
*/
RET_E SLL_displayList(pSLL_S pSll)
{
    ULONG ulIndex = 0;
    pSLL_NODE_S pTmpNode = NULL; 

    /** 1 */
    if (pSll == NULL)
    {
        return DUANXX_ERR;
    }

    /** 2 */
    if (pSll->ulNum == 0)
    {
        printf_s("\n SLL is empty !\n");
        return DUANXX_OK;
    }

    /** 3 */
    pTmpNode = pSll->pHead;
    printf_s("\n SLL is :\n");
    for (ulIndex = 0; ulIndex < pSll->ulNum ; ++ulIndex)
    {
        printf_s("%d", pTmpNode->ulData);
        if (ulIndex != pSll->ulNum - 1)
        {
            printf_s("->");
        }
        pTmpNode = pTmpNode->pNext;
    }

    return DUANXX_OK;
}

/**
* @brief   数据是否在链表中
*
* @param pSll    单链表指针
* @param ulData  待测试数据
*
*       1、如果 pSll为 NULL，则返回错误
*       2、如果单链表的节点数目为0，则返回错误
*       3、如果单链表的节点数目>=1，返回查找结果
*/
RET_E SLL_isInList(pSLL_S pSll, ULONG ulData)
{
    pSLL_NODE_S pTmpNode = NULL;

    /** 1,2 */
    if (pSll == NULL || pSll->ulNum == 0)
    {
        return DUANXX_ERR;
    }

    /** 3 */
    pTmpNode = pSll->pHead;
    while (pTmpNode != NULL)
    {
        if (pTmpNode->ulData == ulData)
        {
            return DUANXX_OK;
        }
        pTmpNode = pTmpNode->pNext;
    }

    return DUANXX_ERR;
}

/**
* @brief   计算链表节点的数目
*
* @param pSll    单链表指针
* @param ulData  待测试数据
*
*       1、如果 pSll为 NULL，则返回 -1
*       2、返回单链表的节点数目
*/
INT32 SLL_count(pSLL_S pSll)
{
    /** 1 */
    if (pSll == NULL)
    {
        return -1;
    }

    /** 2 */
    return pSll->ulNum;
}