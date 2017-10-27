/**
 * @file cirbuf.c 
 * @brief This file contains the function implementations 
 *         for performing circular buffer operations
 *
 * These functions were originally developed by Rhea Cooper
 *  and Brian Kelly modified and improved the code.  
 *
 * @author Brian Kelly and Rhea Cooper
 * @date October 24, 2017
 *
 */

#include "cirbuf.h"

CB_status CB_Init(CB_t *buf, uint32_t length)
{
	buf->size=length;
	buf->buffer_pointer=malloc(length*sizeof(uint32_t*));

	if(NULL == buf->buffer_pointer)
	{
		return BUFFER_ALLOCATION_FAILURE;
	}

	buf->head=buf->buffer_pointer;
	buf->tail=buf->buffer_pointer;
	buf->count=0;
	return NO_ERROR;
}

CB_status CB_IsEmpty(CB_t *buf)
{
	if(NULL == buf)
	{
		return NULL_POINTER;
	}
	if(buf->tail == buf->head)
	{
		return BUFFER_EMPTY;
	}
	else
	{
		return NO_ERROR;
	}
}

CB_status CB_IsFull(CB_t *buf)
{
	if(NULL == buf)
	{
		return NULL_POINTER;
	}
	if( buf->count == buf->size)
	{
		return BUFFER_FULL;
	}
	else
	{
		return NO_ERROR;
	}
}

CB_status CB_AddItem(CB_t *buf, uint8_t *data)
{   
	if(NULL == buf)
	{
		return NULL_POINTER;
	}

	if(buf->count == buf->size)
	{
 	     return BUFFER_FULL;
	}

 	else 
	{     
		*(buf->head)=*data;
/*		printf("\ndata stored inside= %d", *(buf->head));
		printf("\ncount in loop %d", buf->count); */
		/* still to implement wrap around*/
		(buf->head)=(buf->head)++; 
		if((buf->head)>((buf->buffer_pointer)+(buf->size)-1));
			buf->head=buf->buffer_pointer;
		
		buf->count++;
	    return NO_ERROR;
	}
}

CB_status CB_RemoveItem(CB_t *buf, uint8_t *data_rem)
{  
	if(NULL == buf)
	{
		return NULL_POINTER;	
    }

	if(0 == buf->count)
	{
        return BUFFER_EMPTY;
    }
	else
	{
        *data_rem=*(buf->tail);
/*		printf("\ndata removed inside is %d", *data_rem); */
		/*still to implement wrap around*/
        (buf->tail)++;
	if((buf->tail)>((buf->buffer_pointer)+(buf->size)-1));
		buf->tail=buf->buffer_pointer;
	buf->count--;
/*        printf("\ncount after remove= %d",buf->count); */
		return NO_ERROR;
	}
} 

CB_status CB_Peek(CB_t *buf, uint32_t position)
{
	if(NULL == buf)
	{
		return NULL_POINTER;
	}
	if(0 == buf->count)
	{
		return BUFFER_EMPTY;
	}
	else
	{
		if(NULL != (buf->buffer_pointer + position))
		{
			#ifdef VERBOSE
			printf("Value a position %d is %d", position, *(buf->buffer_pointer + position));
			#endif
		}
		else
		{
			#ifdef VERBOSE
			printf("no value");
			#endif
		}
		return NO_ERROR;
	}
}

CB_status CB_Destroy(CB_t *buf)
{
	if(NULL == buf)
	{
		return NULL_POINTER;
	}
	else
	{
		free(buf->buffer_pointer);
		return NO_ERROR;
	}
}
