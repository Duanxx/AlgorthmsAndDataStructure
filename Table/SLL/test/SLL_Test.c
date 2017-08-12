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
* @brief ������ͷ����ڵ����
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