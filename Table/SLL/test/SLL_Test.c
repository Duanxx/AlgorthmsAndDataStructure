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
ulong SLL_TEST()
{
    (void)SLL_init_TEST();

    return DUANXX_OK;
}

/**
* @brief �������ʼ������
*   �������ݣ�
*   1��  Input��pSLL Ϊ NULL
*        Opera :  ��
*   
*   2��  Input : pSLL Ϊ��������
*        Opera : �ж� pSLL�����Ƿ���ȷ
*                pHead��pTailӦΪNULL
*                numӦΪ0
*/
ulong SLL_init_TEST()
{
    /** Test 1 */
    pSLL_S pSLL = NULL;
    if( SLL_init(pSLL) != DUANXX_ERR)
    {
        duanxx_Assert("SLL_init_TEST : Test 1 ");
    }

    /** Test 2 */
    pSLL = (pSLL_S)malloc(sizeof(SLL_S));    
    memset(pSLL, 0, sizeof(SLL_S));
    SLL_init(pSLL);
    if (pSLL->pHead != NULL ||
        pSLL->pTail != NULL ||
        pSLL->num != 0)
    {
        duanxx_Assert("SLL_init_TEST : Test 2 ");
    }

    printf_s("SLL_init_TEST pass \n");

    return DUANXX_OK;
}