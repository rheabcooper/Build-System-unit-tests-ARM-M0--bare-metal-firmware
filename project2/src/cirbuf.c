/**
 * @file cirbuf.c 
 * @brief This file contains the function implementations 
 *         for performing circular buffer operations
 *
 * These functions were originally developed by Rhea Cooper
 *  and Brian Kelly modified and improved the code.  
 *
 * @author Brian Kelly and Rhea Cooper
 * @date October 15, 2017
 *
 */

#include "cirbuf.h"



CB_e CB_is_empty(CB *buf)
{
	if(buf ==NULL)
		return NULL_POINTER;
	if(buf->tail==buf->head){
		printf("\nempty");
		return BUFFER_EMPTY;
	}
	else{
		return NO_ERROR;
	}
}
CB_e CB_is_full(CB *buf)
{
	if(buf ==NULL)
		return NULL_POINTER;
	if(buf->count=buff->size){
		return BUFFER_FULL;
	}
	else{
		return NO_ERROR;
	}
}

CB_e buffer_add_item(CB *buf,int32_t data)
{   
	if(buf == NULL){
		return NULL_POINTER;
	}
	if(buf->count==buf->size)
 	     return BUFFER_FULL;
 	else 
	{     
		buf->head=&data;
		printf("\ndata stored inside= %d", *(buf->head));
		printf("\ncount in loop %d", buf->count);
		/* still to implement wrap around*/
		(buf->head)=(buf->head)++;
		
		buf->count++;
		printf("\ncount after add= %d",buf->count);
	    return NO_ERROR;
	}
}

CB_e CB_buffer_remove_item(CB *buf,int32_t *data_rem)
{   uint32_t i;
	if(buf == NULL)
		return NULL_POINTER;	
    if(buf->count==0)
        return BUFFER_EMPTY;
    else
	{
        *data_rem=*(buf->tail);
		printf("\ndata removed inside is %d", *data_rem);
		/*still to implement wrap around*/
        (buf->tail)++;
		buf->count--;
        printf("\ncount after remove= %d",buf->count);		
		return NO_ERROR;
	}
} 

CB_e CB_peek(CB *buf,uint32_t position,int32_t *ptr)
{
	int32_t value;
	if(buf==NULL){
		return NULL_POINTER;
	}
	if(buf->count==0)
		return BUFFER_EMPTY;
	else
	{
		*ptr=*((buf->aptr)+position);
		if(*ptr!=NULL)
		{
			printf("Value a position %d is %d", position ,*ptr);
		}
		else
		{
			printf("no value");
		}
		return NO_ERROR;
	}
}

CB_e CB_destroy(CB *buf)
{
	if(buf==NULL)
		return NULL_POINTER;
	else
	{
		free(buf->buffer_pointer);
		return NO_ERROR;
	}
}

CB_e CB_print(CB *buf)
{   uint32_t i;
    
    for(i=0;i<buf->size;i++)
    {
        printf("%d",*((buf->aptr)+i));
    }
    return NO_ERROR;
}

CB_e CB_init(CB *buf,uint32_t length)
{
	buf->size=length;
	buf->buffer_pointer=malloc(length*sizeof(uint32_t*));
	if(buf->buffer_pointer==NULL)
	{
		return BUFFER_ALLOCATION_FAILURE;
		printf("\nBuffer not allocated");
	}
	buf->head=buf->buffer_pointer;
	buf->tail=buf->buffer_pointer;
	buf->aptr=buf->buffer_pointer;
	buf->count=0;
	return NO_ERROR;
}




