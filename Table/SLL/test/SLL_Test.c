/*****************************************************************************
*                                                                            *
*  @file     SLL_Test.c                                                      *
*  @brief    单链测试实现文件                                                  *
*                                                                            *
*  @author   Duanxx                                                          *
*  @email    duanxxnj@163.com                                                *
*  @date     2017-08-12                                                      *
*                                                                            *
*****************************************************************************/

#include <string.h>
#include "Table/SLL/test/SLL_Test.h"


/**
* @brief 单链表测试
*/
RET_E SLL_TEST()
{
    (void)SLL_init_TEST();
    (void)SLL_addNodeToHead_TEST();

    return DUANXX_OK;
}

/**
* @brief 单链表初始化测试
*   测试内容：
*   1、  Input：pSLL 为 NULL
*        Expected :  DUNAXX_ERR
*   
*   2、  Input : pSLL 为正常输入
*        Expected : 判断 pSLL内容是否正确
*                   pHead、pTail应为NULL，num应为0
*
*/
RET_E SLL_init_TEST()
{
    pSLL_S pSll = NULL;
    SLL_S sll;

    /** Test 1 */
    if( SLL_init(pSll) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_init_TEST : Test 1 ");
    }

    /** Test 2 */
    pSll = &sll;
    SLL_init(pSll);
    if (pSll->pHead != NULL ||
        pSll->pTail != NULL ||
        pSll->num != 0)
    {
        Duanxx_TestFail("SLL_init_TEST : Test 2 ");
    }

    return DUANXX_OK;
}

/**
* @brief 单链表头插入节点测试
*   测试内容：
*   1、  Input：pSLL 空指针， pNode 非空指针
*        Expected : DUANXX_ERR
*   
*   2、  Input : pSLL 空指针， pNode 空指针
*        Expected : DUANXX_ERR
*
*   3、  Input : pSLL = 非空指针， pNode = 空指针
*        Expected : DUANXX_ERR
*
*   4、  Input : pSLL = 非空指针， pNode = 非空指针
*                pSLL 链表中元素个数为0
*        Expected : DUANXX_OK
*                pSLL 头指针和尾指针同时指向 pNode
*                pSLL 节点数目为1
*
*   5、  Input : pSLL = 非空指针， pNode = 非空指针
*                pSLL 链表中元素个数 >= 1
*        Expected : DUANXX_OK
*                pSLL 头指针指向 pNode
*                pSLL 节点数目自增1
*/
RET_E SLL_addNodeToHead_TEST()
{
    pSLL_S pSll = NULL;
    SLL_S Sll;

    pSLL_NODE_S pNode = NULL;
    pSLL_NODE_S pNode2 = NULL;
    SLL_NODE_S Node;
    SLL_NODE_S Node2;

    /** Test 1 */
    pSll = NULL;
    pNode = &Node;
    if (SLL_addNodeToHead(pSll, pNode) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 1 ");
    }

    /** Test 2 */
    pSll = NULL;
    pNode = NULL;
    if (SLL_addNodeToHead(pSll, pNode) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 2 ");
    }

    /** Test 3 */
    pSll = &Sll;
    pNode = NULL;
    if (SLL_addNodeToHead(pSll, pNode) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 3 ");
    }

    /** Test 4 */
    pSll = &Sll;
    pNode = &Node;
    SLL_init(pSll);
    memset(pNode, 0, sizeof(SLL_NODE_S));
    SLL_addNodeToHead(pSll, pNode);

    if (!(pSll->pHead != NULL && 
        pSll->pHead == pSll->pTail &&
        pSll->num == 1))
    {
        Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 4 ");
    }

    /** Test 5 */
    pNode2 = &Node2;
    memset(pNode2, 0, sizeof(SLL_NODE_S));
    SLL_addNodeToHead(pSll, pNode2);

    if (!(pSll->pHead != NULL && 
        pSll->pHead == pNode2 &&
        pSll->pTail == pNode &&
        pSll->num == 2))
    {
        Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 5 ");
    }

    return DUANXX_OK;
}