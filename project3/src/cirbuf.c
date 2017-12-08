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

#ifdef KL25Z
#define START_CRITICAL() (__enable_irq())
#define END_CRITICAL()   (__disable_irq())
#endif

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
	#ifdef KL25Z
	START_CRITICAL();
	#endif 
	if(NULL == buf)
	{
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return NULL_POINTER;
	}
	if(buf->tail == buf->head && buf->count==0)
	{
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return BUFFER_EMPTY;
	}
	else
	{
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return NO_ERROR;
	}


}




CB_status CB_IsFull(CB_t *buf)
{	
	#ifdef KL25Z
	START_CRITICAL();
	#endif 
	if(NULL == buf)
	{		
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return NULL_POINTER;
	}
	if( buf->count == buf->size)
	{	
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return BUFFER_FULL;
	}
	else
	{	
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return NO_ERROR;
	}
}

CB_status CB_AddItem(CB_t *buf, uint8_t *data)
{	
	#ifdef KL25Z
	START_CRITICAL();
	#endif 
	if(buf == NULL){
		#ifdef KL25Z
		END_CRITICAL();
		#endif
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
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return BUFFER_FULL;
    }
	
	#ifdef KL25Z
	END_CRITICAL();
	#endif
	return NO_ERROR;
}

CB_status CB_RemoveItem(CB_t *buf, uint8_t *data_rem)
{	
	#ifdef KL25Z
	START_CRITICAL();
	#endif 
	if(buf == NULL)
	{
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return NULL_POINTER;	
  	}
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
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return BUFFER_EMPTY;
	}

	#ifdef KL25Z
	END_CRITICAL();
	#endif
	return NO_ERROR;
}

CB_status CB_Peek(CB_t *buf, uint32_t position,uint8_t *ptr)
{
	#ifdef KL25Z
	START_CRITICAL();
	#endif 
	if(buf==NULL){
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return NULL_POINTER;
	}
	if(buf->count==0){
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return BUFFER_EMPTY;
	}
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
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return NO_ERROR;
	}
}


CB_status CB_Destroy(CB_t *buf)
{
	#ifdef KL25Z
	START_CRITICAL();
	#endif 
	if(NULL == buf)
	{	
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return NULL_POINTER;
	}
	else
	{
		free((void*)buf->buffer_pointer);
		buf->buffer_pointer=NULL;
		free((void*)buf);
		buf=NULL;
		#ifdef KL25Z
		END_CRITICAL();
		#endif
		return NO_ERROR;
	}
}
