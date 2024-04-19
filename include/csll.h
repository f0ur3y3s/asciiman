
// insertion beginning
// insertion at end
// insertion in between the nodes
// delete front
// delete last
// delete in between nodes

#ifndef CSLL_H
#define CSLL_H

#include <stdlib.h>

typedef int (*destroy_data_f)(void * p_data);

typedef struct csll_node_t
{
    struct csll_node_t * p_next;
    void *               p_data;
} csll_node_t;

typedef struct csll_t
{
    csll_node_t *  p_head;
    csll_node_t *  p_tail;
    destroy_data_f destroy_data_func;
    size_t         size;
} csll_t;

typedef enum csll_retval_t
{
    CSLL_ERR = -1,
    CSLL_OK  = 0,
    CSLL_EMPTY,
    CSLL_INVALID,
    CSLL_NOT_FOUND
} csll_retval_t;

/**
 * @brief Create a new circular singly linked list on heap
 *
 * @param destroy_data Function pointer to destroy data that is enqueued
 *
 * @return csll_t*
 * @retval On success, pointer to new circular singly linked list
 * @retval On failure, NULL
 */
csll_t * csll_create (destroy_data_f destroy_data);

/**
 * @brief Destroy the circular singly linked list
 *
 * @note This function will destroy all the nodes and data in the list using the
 * destroy_data function passed in from create.
 * @note *pp_csll will be set to NULL after destruction.
 *
 * @param pp_csll Pointer to pointer to circular singly linked list
 * @return int
 * @retval On success, CSLL_OK (0)
 * @retval On failure, CSLL_ERR (-1)
 */
int csll_destroy (csll_t ** pp_csll);

/**
 * @brief Prepend data to the circular singly linked list
 *
 * @param p_csll Pointer to circular singly linked list
 * @param p_data Pointer to data to be enqueued
 * @return int
 * @retval On success, CSLL_OK (0)
 * @retval On failure, CSLL_ERR (-1)
 */
int csll_prepend (csll_t * p_csll, void * p_data);

/**
 * @brief Append data to the circular singly linked list
 *
 * @param p_csll Pointer to circular singly linked list
 * @param p_data Pointer to data to be enqueued
 * @return int
 * @retval On success, CSLL_OK (0)
 * @retval On failure, CSLL_ERR (-1)
 */
int csll_append (csll_t * p_csll, void * p_data);

/**
 * @brief Insert data after a target node in the circular singly linked list
 *
 * @param p_csll Pointer to circular singly linked list
 * @param p_target Pointer to target node after which data is to be enqueued
 * @param p_data Pointer to data to be enqueued
 * @return int
 * @retval On success, CSLL_OK (0)
 * @retval On failure, CSLL_ERR (-1)
 */
int csll_insert (csll_t * p_csll, csll_node_t * p_target, void * p_data);
int csll_predel (csll_t * p_csll, void * p_data);
int csll_postdel (csll_t * p_csll, void * p_data);
int csll_delete (csll_t * p_csll, csll_node_t * p_node_target, void * p_data);

#endif // CSLL_H

/*** end of file ***/