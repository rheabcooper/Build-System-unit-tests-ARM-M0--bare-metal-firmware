/**
 * @file cirbuf.h
 * @brief A header file to perform circular buffer operations. 
 *
 * A header file containing functions to perform memory manipulation.
 *
 * This header file was all developed by Brian Kelly.
 *
 * @author Brian Kelly and Rhea Cooper
 * @date October 24, 2017
 *
 */

#ifndef __CIRBUF_H__
#define __CIRBUF_H__

#include "common.h"

typedef struct{
	volatile uint32_t *buffer_pointer;  /* Buffer pointer template */
	volatile uint32_t *aptr;			   /* temp pointer */
	volatile uint32_t *head;            /* Pointer to the Head or newest item */
	volatile uint32_t *tail;  		   /* Pointer to the tail or oldest item */
	volatile uint32_t size;			   /* buffer size */
	volatile uint32_t count;			   /* current item count in the buffer */
}CB_t;

typedef enum{
    NO_ERROR,					/* success or no error */
    BUFFER_FULL,				/* the buffer is full */
    BUFFER_EMPTY,				/* the buffer is empty */
    NULL_POINTER,				/* the pointer is null */
    NO_LENGTH,					/* no length size allocated */
    BUFFER_ALLOCATION_FAILURE	/* buffer memory allocation failure */
 }CB_status;

/**
 * @brief A function to initialize the buffer 
 *
 * This function initializes an buffer in the memory space. 
 *
 * @param buf - unsigned 32-bit int buffer pointer to initialize
 * @param length - length of the buffer to allocate
 *
 * @return an enumerated status of the buffer or an error code
 */
CB_status CB_Init(CB_t *buf, uint32_t length);

/**
 * @brief A function to check if the buffer is empty
 *
 * This function checks the buffer to see if it is empty
 *
 * @param buf - unsigned 32-bit int buffer pointer
 *
 * @return an enumerated status of the buffer or an error code
 */
CB_status CB_IsEmpty(CB_t *buf);

/**
 * @brief A function to check if the buffer is full
 *
 * This function checks the buffer to see if it is full
 *
 * @param buf - unsigned 32-bit int buffer pointer
 *
 * @return an enumerated status of the buffer or an error code
 */
CB_status CB_IsFull(CB_t *buf);

/**
 * @brief A function to add item to the buffer 
 *
 * This function adds data to the buffer.  The corner cases
 * are considered in this function.  
 *
 * @param buf - unsigned 32-bit int buffer pointer to which 
 *                   the data item is to be added
 * @param data - unsigned 32-bit int data
 *
 * @return an enumerated status of the buffer - success or failure
 */
CB_status CB_AddItem(CB_t *buf, uint8_t *data);

/**
 * @brief A function to remove item from the buffer 
 *
 * This function removes data from the buffer.  The corner cases
 * are considered in this function.  
 *
 * @param buf - unsigned 32-bit int buffer pointer to which 
 *                   the data item is to be removed
 * @param data_rem - unsigned 32-bit int stored data variable
 *
 * @return an enumerated status of the buffer - success or failure
 */
CB_status CB_RemoveItem(CB_t *buf, uint8_t *data_rem);

/**
 * @brief A function to "peek" into the buffer 
 *
 * This function "peeks" an position in the buffer.  The corner cases
 * are considered in this function.  
 *
 * @param buf - unsigned 32-bit int buffer pointer to peek into
 * @param position - unsigned 32-bit int position in the buffer to peek at
 *
 * @return an enumerated status of the buffer or an error code
 */
CB_status CB_Peek(CB_t *buf, uint32_t position,uint8_t* ptr);

/**
 * @brief A function to destroy the buffer 
 *
 * This function destroys the buffer. 
 *
 * @param buf - unsigned 32-bit int buffer pointer to destroy
 *
 * @return an enumerated status of the buffer or an error code
 */
CB_status CB_Destroy(CB_t *buf);


#endif /* __CIRBUF_H__ */
