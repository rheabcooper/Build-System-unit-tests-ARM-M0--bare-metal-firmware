/**
 * @file cirbuf.h
 * @brief A header file to perform circular buffer operations. 
 *
 * A header file containing functions to perform memory manipulation.
 *
 * This header file was all developed by Brian Kelly.
 *
 * @author Brian Kelly and Rhea Cooper
 * @date October 15, 2017
 *
 */

#ifndef __CIRBUF_H__
#define __CIRBUF_H__


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct{
	uint32_t *buffer_pointer;
	uint32_t *aptr;
	uint32_t *head;  //inptr
	uint32_t *tail;  //outptr
	uint32_t size;
	uint32_t count;
	
}CB;

typedef enum{
	NO_ERROR,
    BUFFER_FULL,
    BUFFER_EMPTY,
    NULL_POINTER,
    NO_LENGTH,
    BUFFER_ALLOCATION_FAILURE
 }CB_e;

CB_e CB_is_empty(CB *buf);

CB_e CB_is_full(CB *buf);

CB_e buffer_add_item(CB *buf,int32_t data);

CB_e CB_buffer_remove_item(CB *buf,int32_t *data_rem);

CB_e CB_peek(CB *buf,uint32_t position,int32_t *ptr);

CB_e CB_destroy(CB *buf);

CB_e CB_print(CB *buf);

CB_e CB_init(CB *buf,uint32_t length);






#endif /* __CIRBUF_H__ */
