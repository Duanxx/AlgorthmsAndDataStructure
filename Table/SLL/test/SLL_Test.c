/*****************************************************************************
*                                                                            *
*  @file     SLL_Test.c                                                      *
*  @brief    ��������ʵ���ļ�                                                  *
*                                                                            *
*  @author   Duanxx                                                          *
*  @email    duanxxnj@163.com                                                *
*  @date     2017-08-12                                                      *
*                                                                            *
*****************************************************************************/

#include <string.h>
#include "Table/SLL/test/SLL_Test.h"


/**
* @brief ���������
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
* @brief �������ʼ������
*   �������ݣ�
*   1��  Input��pSLL Ϊ NULL
*        Expected :  DUNAXX_ERR
*   
*   2��  Input : pSLL Ϊ��������
*        Expected : �ж� pSLL�����Ƿ���ȷ
*                   pHead��pTailӦΪNULL��numӦΪ0
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
* @brief ������ͷ����ڵ����
*
*   �������ݣ�
*   1��  Input��pSLL ��ָ�룬 pNode �ǿ�ָ��
*        Expected : DUANXX_ERR
*   
*   2��  Input : pSLL ��ָ�룬 pNode ��ָ��
*        Expected : DUANXX_ERR
*
*   3��  Input : pSLL = �ǿ�ָ�룬 pNode = ��ָ��
*        Expected : DUANXX_ERR
*
*   4��  Input : pSLL = �ǿ�ָ�룬 pNode = �ǿ�ָ��
*                pSLL ������Ԫ�ظ���Ϊ0
*        Expected : DUANXX_OK
*                pSLL ͷָ���βָ��ͬʱָ�� pNode
*                pSLL �ڵ���ĿΪ1
*
*   5��  Input : pSLL = �ǿ�ָ�룬 pNode = �ǿ�ָ��
*                pSLL ������Ԫ�ظ��� >= 1
*        Expected : DUANXX_OK
*                pSLL ͷָ��ָ�� pNode
*                pSLL �ڵ���Ŀ����1
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
* @brief ������ͷ����ڵ����
*
*   �������ݣ�
*   1��  Input��pSLL ��ָ�룬 pNode �ǿ�ָ��
*        Expected : DUANXX_ERR
*   
*   2��  Input : pSLL ��ָ�룬 pNode ��ָ��
*        Expected : DUANXX_ERR
*
*   3��  Input : pSLL = �ǿ�ָ�룬 pNode = ��ָ��
*        Expected : DUANXX_ERR
*
*   4��  Input : pSLL = �ǿ�ָ�룬 pNode = �ǿ�ָ��
*                pSLL ������Ԫ�ظ���Ϊ0
*        Expected : DUANXX_OK
*                pSLL ͷָ���βָ��ͬʱָ�� pNode
*                pSLL �ڵ���ĿΪ1
*
*   5��  Input : pSLL = �ǿ�ָ�룬 pNode = �ǿ�ָ��
*                pSLL ������Ԫ�ظ��� >= 1
*        Expected : DUANXX_OK
*                pSLL βָ��ָ�� pNode
*                pSLL �ڵ���Ŀ����1
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
* @brief ������ͷɾ���ڵ����
*
*   �������ݣ�
*   1��  Input��pSLL ��ָ��
*        Expected : DUANXX_ERR
*
*   2��  Input��pSLL �ǿ�ָ��
*              �������Ԫ�ظ���Ϊ0
*        Expected : DUANXX_ERR
*
*   3��  Input��pSLL �ǿ�ָ��
*              �������Ԫ�ظ���Ϊ1
*        Expected : DUANXX_OK
*              ɾ���ýڵ㣬����pSLL��ͷ�ڵ��β�ڵ�ΪNULL
*              pSLL�ڵ���ĿΪ0
*
*   4��  Input��pSLL �ǿ�ָ��
*              �������Ԫ�ظ��� > 1
*        Expected : DUANXX_OK
*              ɾ��pSllͷ�㣬
*              pSLL�ڵ���Ŀ�Լ�1
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
        /** ���ͷָ���ڴ��ͷ�ʧ�ܣ���ô�����ͷŸ��ڴ�ռ� */
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
        /** ���ͷָ���ڴ��ͷ�ʧ�ܣ���ô�����ͷŸ��ڴ�ռ� */
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
* @brief ������βɾ���ڵ����
*
*   �������ݣ�
*   1��  Input��pSLL ��ָ��
*        Expected : DUANXX_ERR
*
*   2��  Input��pSLL �ǿ�ָ��
*              �������Ԫ�ظ���Ϊ0
*        Expected : DUANXX_ERR
*
*   3��  Input��pSLL �ǿ�ָ��
*              �������Ԫ�ظ���Ϊ1
*        Expected : DUANXX_OK
*              ɾ���ýڵ㣬����pSLL��ͷ�ڵ��β�ڵ�ΪNULL
*              pSLL�ڵ���ĿΪ0
*
*   4��  Input��pSLL �ǿ�ָ��
*              �������Ԫ�ظ��� > 1
*        Expected : DUANXX_OK
*              ɾ��pSllβ�㣬
*              pSLL�ڵ���Ŀ�Լ�1
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
        /** ���βָ���ڴ��ͷ�ʧ�ܣ���ô�����ͷŸ��ڴ�ռ� */
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
        /** ���ͷָ���ڴ��ͷ�ʧ�ܣ���ô�����ͷŸ��ڴ�ռ� */
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