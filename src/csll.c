#include "csll.h"
#include <stdio.h>

csll_t * csll_create (destroy_data_f destroy_data)
{
    csll_t * p_new_csll = calloc(1, sizeof(csll_t));

    if (NULL == p_new_csll)
    {
        goto EXIT;
    }

    p_new_csll->p_head            = NULL;
    p_new_csll->p_tail            = NULL;
    p_new_csll->size              = 0;
    p_new_csll->destroy_data_func = destroy_data;

EXIT:
    return (p_new_csll);
}

int csll_destroy (csll_t ** pp_csll)
{
    int retval = CSLL_ERR;

    if ((NULL == pp_csll) || (NULL == *pp_csll))
    {
        goto EXIT;
    }

    csll_t * p_csll = *pp_csll;

    // from head to tail, destroy all nodes and data
    csll_node_t * p_curr = p_csll->p_head;
    csll_node_t * p_last = p_csll->p_tail;

    while (p_curr != p_last)
    {
        csll_node_t * p_next = p_curr->p_next;

        if (NULL != p_csll->destroy_data_func)
        {
            p_csll->destroy_data_func(p_curr->p_data);
        }

        free(p_curr);
        p_curr = p_next;
    }

    // Free the last node
    if (NULL != p_csll->destroy_data_func)
    {
        p_csll->destroy_data_func(p_last->p_data);
    }

    free(p_last);
    free(p_csll);
    *pp_csll = NULL;
    retval   = CSLL_OK;

EXIT:
    return (retval);
}

int csll_prepend (csll_t * p_csll, void * p_data)
{
    int retval = CSLL_ERR;

    if (NULL == p_csll)
    {
        goto EXIT;
    }

    csll_node_t * p_new_node = calloc(1, sizeof(csll_node_t));

    if (NULL == p_new_node)
    {
        goto EXIT;
    }

    p_new_node->p_data = p_data;

    if (NULL == p_csll->p_head)
    {
        p_csll->p_head     = p_new_node;
        p_csll->p_tail     = p_new_node;
        p_new_node->p_next = p_new_node;
    }
    else
    {
        p_new_node->p_next     = p_csll->p_head;
        p_csll->p_head         = p_new_node;
        p_csll->p_tail->p_next = p_new_node;
    }

    p_csll->size++;
    retval = CSLL_OK;

EXIT:
    return (retval);
}

int csll_append (csll_t * p_csll, void * p_data)
{
    int retval = CSLL_ERR;

    if (NULL == p_csll)
    {
        goto EXIT;
    }

    csll_node_t * p_new_node = calloc(1, sizeof(csll_node_t));

    if (NULL == p_new_node)
    {
        goto EXIT;
    }

    p_new_node->p_data = p_data;

    if (NULL == p_csll->p_head)
    {
        p_csll->p_head     = p_new_node;
        p_csll->p_tail     = p_new_node;
        p_new_node->p_next = p_new_node;
    }
    else
    {
        p_new_node->p_next     = p_csll->p_head;
        p_csll->p_tail->p_next = p_new_node;
        p_csll->p_tail         = p_new_node;
    }

    p_csll->size++;
    retval = CSLL_OK;

EXIT:
    return (retval);
}

/*** end of file ***/
