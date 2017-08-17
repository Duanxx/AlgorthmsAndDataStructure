/*****************************************************************************
*                                                                            *
*  @file     SLL_Test.c                                                      *
*  @brief    单链测试实现文件                                                  *
*                这个文件中仅仅是对链表基本操作的测试                             *
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
    (void)SLL_displayList_TEST();
    (void)SLL_isInList_TEST();
    return DUANXX_OK;
}


/**
* @brief 用于判断单链表和给定的节点指针数组是否完全匹配
*           节点指针数组存放的是给单链表分配的节点的指针序列
*           简而言之，节点指针数组就是单链表的数组化
*           从理论上讲，这两个应该是一样的才对
*
* @param pNodeList 节点指针数组
* @param ulLen     节点指针数组中元素的个数
* @param pSll      单链表指针
* @param szTestStr 测试用例的说明性字符串
*
*/
RET_E SLL_IsListMatched(pSLL_NODE_S arrNodeList[], ULONG ulLen, pSLL_S pSll, char *szTestStr)
{
    ULONG ulIndex = 0;
    pSLL_NODE_S pTmpNode = NULL;

    if (ulLen == 0)
    {
        if (pSll->pHead != NULL ||
            pSll->pTail != NULL ||
            pSll->ulNum != 0)
        {
            Duanxx_TestFail(szTestStr);
            return DUANXX_ERR;
        }
    }

    if (ulLen == 1)
    {
        if (pSll->pHead != pSll->pTail ||
            pSll->pHead != arrNodeList[0] ||
            pSll->ulNum != 1)
        {
            Duanxx_TestFail(szTestStr);
            return DUANXX_ERR;
        }
    }

    pTmpNode = pSll->pHead;

    if (pSll->ulNum != ulLen)
    {
        Duanxx_TestFail(szTestStr);
        return DUANXX_ERR;
    }

    for (ulIndex = 0; ulIndex < ulLen; ++ulIndex)
    {
        if (arrNodeList[ulIndex] != pTmpNode)
        {
            Duanxx_TestFail(szTestStr);
            return DUANXX_ERR;
        }
        pTmpNode = pTmpNode->pNext;
    }

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
    if (pSll == NULL)
    {
        assert(0);
    }

    SLL_init(pSll);
    if (pSll->pHead != NULL ||
        pSll->pTail != NULL ||
        pSll->ulNum != 0)
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
    pSLL_NODE_S NodeList[SLL_TEST_LEN];

    int index = 0;

    /** Test 1 */
    pSll = NULL;
    pNode = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    if (pNode == NULL)
    {
        assert(0);
    }

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
    if (pSll == NULL)
    {
        assert(0);
    }

    pNode = NULL;
    if (SLL_addNodeToHead(pSll, pNode) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 3 ");
    }
    Duanxx_Free(pSll);

    /** Test 4 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    pNode = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    if (pSll == NULL || pNode == NULL)
    {
        assert(0);
    }

    SLL_init(pSll);
    memset(pNode, 0, sizeof(SLL_NODE_S));

    if ( !( SLL_addNodeToHead(pSll, pNode) == DUANXX_OK &&
        pSll->pHead != NULL && 
        pSll->pHead == pSll->pTail &&
        pSll->ulNum == 1) )
    {
        Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 4 ");
    }
    Duanxx_Free(pNode);
    Duanxx_Free(pSll);


    /** Test 5 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    if (pSll == NULL)
    {
        assert(0);
    }
    SLL_init(pSll);

    /** 将链表中每个节点的指针都存储起来 */
    for (index = 0; index < SLL_TEST_LEN; ++index)
    {
        pNode = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
        if (pNode == NULL)
        {
            assert(0);
        }
        memset(pNode, 0, sizeof(SLL_NODE_S));

        NodeList[index] = pNode;
        if (SLL_addNodeToHead(pSll, pNode) != DUANXX_OK)
        {
            Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 5 : 1");
        }        
    }
    


    /** 由于是向链表头添加节点，所以链表中的顺序和 NodeList 中节点的顺序相反
        依次比较链表中所有节点的指针是否正确
    */
    pNode = pSll->pHead;
    for (index = SLL_TEST_LEN - 1; index >=0; --index)
    {
        if (pNode == NULL || pNode != NodeList[index])
        {
            Duanxx_TestFail("SLL_addNodeToHead_TEST : Test 5 : 3");
            break;
        }
        pNode = pNode->pNext;
    }

    /** 由于是测试代码，必须自己手动释放开辟的内存，而不应该调用链表释放函数 */
    for (index = 0; index < SLL_TEST_LEN; ++index)
    {
        Duanxx_Free(NodeList[index]);
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
*                pSLL 尾指针指向 pNode
*                pSLL 节点数目自增1
*
*/
RET_E SLL_addNodeToTail_TEST()
{
    pSLL_S pSll = NULL;
    pSLL_NODE_S pNode = NULL;
    pSLL_NODE_S NodeList[SLL_TEST_LEN];
    int index = 0;

    /** Test 1 */
    pSll = NULL;
    pNode = (pSLL_NODE_S)malloc(sizeof(pSLL_NODE_S));
    if (pNode == NULL)
    {
        assert(0);
    }

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
    if (pSll == NULL)
    {
        assert(0);
    }

    if (SLL_addNodeToTail(pSll, pNode) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_addNodeToTail_TEST : Test 3");
    }
    Duanxx_Free(pSll);

    /** Test 4 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    pNode = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
    if (pSll == NULL || pNode == NULL)
    {
        assert(0);
    }

    SLL_init(pSll);
    memset(pNode, 0, sizeof(SLL_NODE_S));

    if ( !( SLL_addNodeToTail(pSll, pNode) == DUANXX_OK &&
        pSll->pHead != NULL && 
        pSll->pHead == pSll->pTail &&
        pSll->ulNum == 1) )
    {
        Duanxx_TestFail("SLL_addNodeToTail_TEST : Test 4 ");
    }
    Duanxx_Free(pNode);
    Duanxx_Free(pSll);

    /** Test 5 */
    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    if (pSll == NULL)
    {
        assert(0);
    }
    SLL_init(pSll);

    /** 将链表中每个节点的指针都存储起来 */
    for (index = 0; index < SLL_TEST_LEN; ++index)
    {
        pNode = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
        if (pNode == NULL)
        {
            assert(0);
        }
        memset(pNode, 0, sizeof(SLL_NODE_S));

        NodeList[index] = pNode;
        if (SLL_addNodeToTail(pSll, pNode) != DUANXX_OK)
        {
            Duanxx_TestFail("SLL_addNodeToTail_TEST : Test 5 : 1");
        }        
    }    

    /** 保证链表头指针和尾指针正确 */
    if (pSll->ulNum != SLL_TEST_LEN ||
        pSll->pHead != NodeList[0] ||
        pSll->pTail != NodeList[SLL_TEST_LEN - 1] )
    {
        Duanxx_TestFail("SLL_addNodeToTail_TEST : Test 5 : 2");
    }

    /** 由于是向链表头添加节点，所以链表中的顺序和 NodeList 中节点的顺序相反
        依次比较链表中所有节点的指针是否正确
    */
    pNode = pSll->pHead;
    for (index = 0; index < SLL_TEST_LEN; ++index)
    {
        if (pNode == NULL || pNode != NodeList[index])
        {
            Duanxx_TestFail("SLL_addNodeToTail_TEST : Test 5 : 3");
            break;
        }
        pNode = pNode->pNext;
    }

    /** 由于是测试代码，必须自己手动释放开辟的内存，而不应该调用链表释放函数 */
    for (index = 0; index < SLL_TEST_LEN; ++index)
    {
        Duanxx_Free(NodeList[index]);
    }
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
        pSll->ulNum == 0))
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
        pSll->ulNum == 1))
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
        pSll->ulNum == 0))
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
        pSll->ulNum == 1))
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

/**
* @brief 单链表显示测试
*
*   测试内容：
*   1、  Input：pSLL 空指针
*        Expected : DUANXX_ERR
*
*   2、  Input：pSLL 非空指针
*              单链表的元素个数为0
*        Expected : DUANXX_OK
                提示链表为空
*
*   3、  Input：pSLL 非空指针
*              单链表的元素个>=1
*        Expected : DUANXX_OK
*                显示链表
*/
RET_E SLL_displayList_TEST()
{
    pSLL_S pSll = NULL;
    pSLL_NODE_S pNode = NULL;
    int index = 0;

    /** Test 1、2 人工视检 */

    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    if (pSll == NULL)
    {
        assert(0);
    }
    SLL_init(pSll);

    /** 将链表中每个节点的指针都存储起来 */
    for (index = 0; index < SLL_TEST_LEN; ++index)
    {
        pNode = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
        if (pNode == NULL)
        {
            assert(0);
        }
        memset(pNode, 0, sizeof(SLL_NODE_S));
        pNode->ulData = index;

        SLL_addNodeToTail(pSll, pNode);
    }    

    SLL_displayList(pSll);

    SLL_freeList(pSll);

    SLL_displayList(pSll);

    Duanxx_Free(pSll);

    return DUANXX_OK;
}

/**
* @brief 单链表显示测试
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
*              单链表的元素个>=1
*        Expected : 返回查找结果
*                
*/
RET_E SLL_isInList_TEST()
{
    /** Test 1、2 人工视检 */
    pSLL_S pSll = NULL;
    pSLL_NODE_S pNode = NULL;
    ULONG ulIndex = 0;

    /** Test 1、2 人工视检 */

    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    if (pSll == NULL)
    {
        assert(0);
    }
    SLL_init(pSll);

    for (ulIndex = 0; ulIndex < SLL_TEST_LEN; ++ulIndex)
    {
        pNode = (pSLL_NODE_S)malloc(sizeof(SLL_NODE_S));
        if (pNode == NULL)
        {
            assert(0);
        }
        memset(pNode, 0, sizeof(SLL_NODE_S));
        pNode->ulData = ulIndex;

        SLL_addNodeToTail(pSll, pNode);
    }    

    for (ulIndex = 0; ulIndex < pSll->ulNum; ++ulIndex)
    {
        if (SLL_isInList(pSll, ulIndex) != DUANXX_OK)
        {
            Duanxx_TestFail("SLL_isInList_TEST : Test 3 : 1");
            printf_s("ulIndex = %d\n", ulIndex);
        }
    }

    if (SLL_isInList(pSll, ulIndex) != DUANXX_ERR)
    {
        Duanxx_TestFail("SLL_isInList_TEST : Test 3 : 2");
    }

    return DUANXX_OK;
}