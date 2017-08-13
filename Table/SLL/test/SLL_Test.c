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
    (void)SLL_addNodeToTail_TEST();
    (void)SLL_deleteFromHead_TEST();

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

    /** Test 1 */
    if( SLL_init(pSll) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_init_TEST : Test 1 ");
    }

    /** Test 2 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    SLL_init(pSll);
    if (pSll->pHead != NULL ||
        pSll->pTail != NULL ||
        pSll->num != 0)
    {
        Duanxx_TestFail("SLL_init_TEST : Test 2 ");
    }
    Duanxx_Free(pSll);

    return DUANXX_OK;
}

/**
* @brief 单链表头插入节点测试
*
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
*
*/
RET_E SLL_addNodeToHead_TEST()
{
    pSLL_S pSll = NULL;

    pSLL_NODE_S pNode = NULL;
    pSLL_NODE_S pNode2 = NULL;

    /** Test 1 */
    pSll = NULL;
    pNode = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    if (SLL_addNodeToHead(pSll, pNode) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 1 ");
    }
    Duanxx_Free(pNode);

    /** Test 2 */
    pSll = NULL;
    pNode = NULL;
    if (SLL_addNodeToHead(pSll, pNode) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 2 ");
    }

    /** Test 3 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    pNode = NULL;
    if (SLL_addNodeToHead(pSll, pNode) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 3 ");
    }
    Duanxx_Free(pSll);

    /** Test 4 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    pNode = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    SLL_init(pSll);
    memset(pNode, 0, sizeof(SLL_NODE_S));

    if ( !( SLL_addNodeToHead(pSll, pNode) == DUANXX_OK &&
        pSll->pHead != NULL && 
        pSll->pHead == pSll->pTail &&
        pSll->num == 1) )
    {
        Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 4 ");
    }
    Duanxx_Free(pNode);
    Duanxx_Free(pSll);


    /** Test 5 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    pNode = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    pNode2 = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));

    SLL_init(pSll);
    memset(pNode, 0, sizeof(SLL_NODE_S));
    memset(pNode2, 0, sizeof(SLL_NODE_S));

    if ( !(SLL_addNodeToHead(pSll, pNode) == DUANXX_OK &&
        SLL_addNodeToHead(pSll, pNode2) == DUANXX_OK &&
        pSll->pHead != NULL && 
        pSll->pHead == pNode2 &&
        pSll->pTail == pNode &&
        pSll->num == 2) )
    {
        Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 5 ");
    }
    Duanxx_Free(pNode);
    Duanxx_Free(pNode2);
    Duanxx_Free(pSll);

    return DUANXX_OK;
}

/**
* @brief 单链表头插入节点测试
*
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
*                pSLL 尾指针指向 pNode
*                pSLL 节点数目自增1
*
*/
RET_E SLL_addNodeToTail_TEST()
{
    pSLL_S pSll = NULL;
    pSLL_NODE_S pNode = NULL;
    pSLL_NODE_S pNode2 = NULL;

    /** Test 1 */
    pSll = NULL;
    pNode = (pSLL_NODE_S)malloc(sizeof(pSLL_NODE_S));
    if (SLL_addNodeToTail(pSll, pNode) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_addNodeToTail_TEST : Test 1")
    }
    Duanxx_Free(pNode);

    /** Test 2 */
    pSll = NULL;
    pNode = NULL;
    if (SLL_addNodeToTail(pSll, pNode) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_addNodeToTail_TEST : Test 2");
    }

    /** Test 3 */ 
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    pNode = NULL;
    if (SLL_addNodeToTail(pSll, pNode) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_addNodeToTail_TEST : Test 3");
    }
    Duanxx_Free(pSll);

    /** Test 4 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    pNode = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    SLL_init(pSll);
    memset(pNode, 0, sizeof(SLL_NODE_S));

    if ( !( SLL_addNodeToTail(pSll, pNode) == DUANXX_OK &&
        pSll->pHead != NULL && 
        pSll->pHead == pSll->pTail &&
        pSll->num == 1) )
    {
        Duanxx_TestFail("SLL_addNodeToTail_TEST : Test 4 ");
    }
    Duanxx_Free(pNode);
    Duanxx_Free(pSll);

    /** Test 5 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    pNode = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    pNode2 = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    SLL_init(pSll);
    memset(pNode, 0, sizeof(SLL_NODE_S));
    memset(pNode2, 0, sizeof(SLL_NODE_S));

    if ( !( SLL_addNodeToTail(pSll, pNode) == DUANXX_OK &&
         SLL_addNodeToTail(pSll, pNode2) == DUANXX_OK &&
         pSll->pHead == pNode &&
         pSll->pTail == pNode2 &&
         pSll->num == 2 ))
    {
        Duanxx_TestFail("SLL_addNodeToTail_TEST : Test 5 ");
    }
    Duanxx_Free(pNode2);
    Duanxx_Free(pNode);
    Duanxx_Free(pSll);

    return DUANXX_OK;
}

/**
* @brief 单链表头删除节点测试
*
*   测试内容：
*   1、  Input：pSLL 空指针
*        Expected : DUANXX_ERR
*
*   2、  Input：pSLL 非空指针
*              单链表的元素个数为0
*        Expected : DUANXX_ERR
*
*   3、  Input：pSLL 非空指针
*              单链表的元素个数为1
*        Expected : DUANXX_OK
*              删除该节点，并且pSLL的头节点和尾节点为NULL
*              pSLL节点数目为0
*
*   4、  Input：pSLL 非空指针
*              单链表的元素个数 > 1
*        Expected : DUANXX_OK
*              删除pSll头点，
*              pSLL节点数目自减1
*
*/
RET_E SLL_deleteFromHead_TEST()
{
    pSLL_S pSll = NULL;
    pSLL_NODE_S pNode1 = NULL;
    pSLL_NODE_S pNode2 = NULL;

    /** Test 1 */
    pSll = NULL;

    if (SLL_deleteFromHead(pSll) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_deleteFromHead_TEST : Test 1");
    }

    /** Test 2 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    SLL_init(pSll);

    if (SLL_deleteFromHead(pSll) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_deleteFromHead_TEST : Test 2");
    }
    Duanxx_Free(pSll);

    /** Test 3 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    SLL_init(pSll);    

    pNode1 = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    memset(pNode1, 0, sizeof(SLL_NODE_S));
    SLL_addNodeToHead(pSll, pNode1);

    if ( !(SLL_deleteFromHead(pSll) == DUANXX_OK &&
        pSll->pHead == NULL &&
        pSll->pTail == NULL &&
        pSll->num == 0))
    {
        /** 如果头指针内存释放失败，那么重新释放该内存空间 */
        if (pSll->pHead == pNode1)
        {
            Duanxx_Free(pSll->pHead);
            pNode1 = NULL;
        }
        Duanxx_TestFail("SLL_deleteFromHead_TEST : Test 3");
    }
    Duanxx_Free(pSll);

    /** Test 4 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    SLL_init(pSll);    

    pNode1 = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    memset(pNode1, 0, sizeof(SLL_NODE_S));
    SLL_addNodeToHead(pSll, pNode1);

    pNode2 = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    memset(pNode2, 0, sizeof(SLL_NODE_S));
    SLL_addNodeToTail(pSll, pNode2); 

    if ( !(SLL_deleteFromHead(pSll) == DUANXX_OK &&
        pSll->pHead == pNode2 && 
        pSll->pTail == pNode2 &&
        pSll->num == 1))
    {
        /** 如果头指针内存释放失败，那么重新释放该内存空间 */
        if (pSll->pHead == pNode1)
        {
            Duanxx_Free(pSll->pHead);
            pNode1 = NULL;
        }
        Duanxx_TestFail("SLL_deleteFromHead_TEST : Test 4");
    }
    Duanxx_Free(pNode2);
    Duanxx_Free(pSll);

    return DUANXX_OK;
}

/**
* @brief 单链表尾删除节点测试
*
*   测试内容：
*   1、  Input：pSLL 空指针
*        Expected : DUANXX_ERR
*
*   2、  Input：pSLL 非空指针
*              单链表的元素个数为0
*        Expected : DUANXX_ERR
*
*   3、  Input：pSLL 非空指针
*              单链表的元素个数为1
*        Expected : DUANXX_OK
*              删除该节点，并且pSLL的头节点和尾节点为NULL
*              pSLL节点数目为0
*
*   4、  Input：pSLL 非空指针
*              单链表的元素个数 > 1
*        Expected : DUANXX_OK
*              删除pSll尾点，
*              pSLL节点数目自减1
*
*/
RET_E SLL_deleteFromTail_TEST()
{
    pSLL_S pSll = NULL;
    pSLL_NODE_S pNode1 = NULL;
    pSLL_NODE_S pNode2 = NULL;

    /** Test 1 */
    pSll = NULL;

    if (SLL_deleteFromTail(pSll) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_deleteFromTail_TEST : Test 1");
    }

    /** Test 2 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    SLL_init(pSll);

    if (SLL_deleteFromTail(pSll) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_deleteFromTail_TEST : Test 2");
    }
    Duanxx_Free(pSll);

    /** Test 3 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    SLL_init(pSll);    

    pNode1 = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    memset(pNode1, 0, sizeof(SLL_NODE_S));
    SLL_addNodeToTail(pSll, pNode1);

    if ( !(SLL_deleteFromTail(pSll) == DUANXX_OK &&
        pSll->pHead == NULL &&
        pSll->pTail == NULL &&
        pSll->num == 0))
    {
        /** 如果尾指针内存释放失败，那么重新释放该内存空间 */
        if (pSll->pTail == pNode1)
        {
            Duanxx_Free(pSll->pTail);
            pNode1 = NULL;
            Duanxx_TestFail("SLL_deleteFromTail_TEST : Test 3");
        }
    }
    Duanxx_Free(pSll);

    /** Test 4 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    SLL_init(pSll);    

    pNode1 = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    memset(pNode1, 0, sizeof(SLL_NODE_S));
    SLL_addNodeToHead(pSll, pNode1);

    pNode2 = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    memset(pNode2, 0, sizeof(SLL_NODE_S));
    SLL_addNodeToTail(pSll, pNode2); 

    if (!( SLL_deleteFromTail(pSll) == DUANXX_OK &&
        pSll->pHead == pNode1 && 
        pSll->pTail == pNode1 &&
        pSll->num == 1))
    {
        /** 如果头指针内存释放失败，那么重新释放该内存空间 */
        if (pSll->pTail == pNode2)
        {
            Duanxx_Free(pSll->pTail);
            pNode2 = NULL;
        }
        Duanxx_TestFail("SLL_deleteFromHead_TEST : Test 4");
    }
    Duanxx_Free(pNode1);
    Duanxx_Free(pSll);

    return DUANXX_OK;
}