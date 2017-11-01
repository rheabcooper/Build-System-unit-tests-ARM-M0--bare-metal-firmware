/**
 * @file - main.c 
 * @brief - A main file for executing various function calls for the projects 
 *
 * These functions were originally developed by Rhea Cooper
 *  and Brian Kelly modified and improved the code.  
 *
 * This file is used to execute the functions for ECEN5813's projects.  
 * 
 * @author Brian Kelly and Rhea Cooper
 * @date October 15, 2017
 *
 */

#ifdef PROJECT1
#include "project1.h"
#endif 

#ifdef PROJECT2
#include "project2.h"
#endif

int main(void)
{
	#ifdef PROJECT1	
		project1(); 
	#endif

	#ifdef PROJECT2
		project2();
	#endif

	return 0;
}
