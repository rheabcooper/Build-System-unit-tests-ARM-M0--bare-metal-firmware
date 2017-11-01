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
	buf->buffer_pointer=(uint8_t*)malloc(length*sizeof(uint8_t));
	if(buf->buffer_pointer==NULL)
	{
		return BUFFER_ALLOCATION_FAILURE;
	}
	buf->head=buf->buffer_pointer;
	buf->tail=buf->buffer_pointer;
	buf->aptr=buf->buffer_pointer;
	buf->count=0;
	return NO_ERROR;
}

CB_status CB_IsEmpty(CB_t *buf)
{
	if(NULL == buf)
	{
		return NULL_POINTER;
	}
	if(buf->tail == buf->head && buf->count==0)
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
	if(buf == NULL){
		return NULL_POINTER;
	}
	if((buf->count)!=buf->size)
	{
		*(buf->head)=*data;
		(buf->head)=(buf->head+1);
		if((buf->head)>((buf->buffer_pointer)+(buf->size-1)))
			buf->head=buf->buffer_pointer;
		buf->count++;
	}
	else
	{
		return BUFFER_FULL;
        }	
	return NO_ERROR;
}

CB_status CB_RemoveItem(CB_t *buf, uint8_t *data_rem)
{
	if(buf == NULL)
		return NULL_POINTER;	
  	if(buf->count!=0)
	{
      		*(data_rem)=*(buf->tail);
		(buf->tail)=(buf->tail)+1;
		if((buf->tail)>((buf->buffer_pointer)+(buf->size-1)))
			buf->tail=buf->buffer_pointer;
		buf->count--;
        		
	}			
	else
	{
		return BUFFER_EMPTY;
	}
	return NO_ERROR;
}

CB_status CB_Peek(CB_t *buf, uint32_t position,uint8_t *ptr)
{
	if(buf==NULL){
		return NULL_POINTER;
	}
	if(buf->count==0)
		return BUFFER_EMPTY;
	else
	{
		*ptr=*((buf->buffer_pointer)+position);
		if(ptr!=NULL)
		{	
			#ifdef VERBOSE
			printf("Value a position %d is %d", position ,*ptr);
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
		free((void*)buf->buffer_pointer);
		buf->buffer_pointer=NULL;
		free((void*)buf);
		buf=NULL;
		return NO_ERROR;
	}
}
