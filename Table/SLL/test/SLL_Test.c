/*****************************************************************************
*                                                                            *
*  @file     SLL_Test.c                                                      *
*  @brief    ��������ʵ���ļ�                                                  *
*                ����ļ��н����Ƕ�������������Ĳ���                             *
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
    (void)SLL_displayList_TEST();
    (void)SLL_isInList_TEST();
    return DUANXX_OK;
}


/**
* @brief �����жϵ�����͸����Ľڵ�ָ�������Ƿ���ȫƥ��
*           �ڵ�ָ�������ŵ��Ǹ����������Ľڵ��ָ������
*           �����֮���ڵ�ָ��������ǵ���������黯
*           �������Ͻ���������Ӧ����һ���ĲŶ�
*
* @param pNodeList �ڵ�ָ������
* @param ulLen     �ڵ�ָ��������Ԫ�صĸ���
* @param pSll      ������ָ��
* @param szTestStr ����������˵�����ַ���
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

    /** ��������ÿ���ڵ��ָ�붼�洢���� */
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
    


    /** ������������ͷ��ӽڵ㣬���������е�˳��� NodeList �нڵ��˳���෴
        ���αȽ����������нڵ��ָ���Ƿ���ȷ
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

    /** �����ǲ��Դ��룬�����Լ��ֶ��ͷſ��ٵ��ڴ棬����Ӧ�õ��������ͷź��� */
    for (index = 0; index < SLL_TEST_LEN; ++index)
    {
        Duanxx_Free(NodeList[index]);
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
*                pSLL βָ��ָ�� pNode
*                pSLL �ڵ���Ŀ����1
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

    /** ��������ÿ���ڵ��ָ�붼�洢���� */
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

    /** ��֤����ͷָ���βָ����ȷ */
    if (pSll->ulNum != SLL_TEST_LEN ||
        pSll->pHead != NodeList[0] ||
        pSll->pTail != NodeList[SLL_TEST_LEN - 1] )
    {
        Duanxx_TestFail("SLL_addNodeToTail_TEST : Test 5 : 2");
    }

    /** ������������ͷ��ӽڵ㣬���������е�˳��� NodeList �нڵ��˳���෴
        ���αȽ����������нڵ��ָ���Ƿ���ȷ
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

    /** �����ǲ��Դ��룬�����Լ��ֶ��ͷſ��ٵ��ڴ棬����Ӧ�õ��������ͷź��� */
    for (index = 0; index < SLL_TEST_LEN; ++index)
    {
        Duanxx_Free(NodeList[index]);
    }
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
        pSll->ulNum == 0))
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
        pSll->ulNum == 1))
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
        pSll->ulNum == 0))
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
        pSll->ulNum == 1))
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

/**
* @brief ��������ʾ����
*
*   �������ݣ�
*   1��  Input��pSLL ��ָ��
*        Expected : DUANXX_ERR
*
*   2��  Input��pSLL �ǿ�ָ��
*              �������Ԫ�ظ���Ϊ0
*        Expected : DUANXX_OK
                ��ʾ����Ϊ��
*
*   3��  Input��pSLL �ǿ�ָ��
*              �������Ԫ�ظ�>=1
*        Expected : DUANXX_OK
*                ��ʾ����
*/
RET_E SLL_displayList_TEST()
{
    pSLL_S pSll = NULL;
    pSLL_NODE_S pNode = NULL;
    int index = 0;

    /** Test 1��2 �˹��Ӽ� */

    pSll = (pSLL_S)malloc(sizeof(SLL_S));
    if (pSll == NULL)
    {
        assert(0);
    }
    SLL_init(pSll);

    /** ��������ÿ���ڵ��ָ�붼�洢���� */
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
* @brief ��������ʾ����
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
*              �������Ԫ�ظ�>=1
*        Expected : ���ز��ҽ��
*                
*/
RET_E SLL_isInList_TEST()
{
    /** Test 1��2 �˹��Ӽ� */
    pSLL_S pSll = NULL;
    pSLL_NODE_S pNode = NULL;
    ULONG ulIndex = 0;

    /** Test 1��2 �˹��Ӽ� */

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