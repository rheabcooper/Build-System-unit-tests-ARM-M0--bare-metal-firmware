/**
 * @file platform.h
 * @brief A header file to create a layer to be platform independent. 
 *
 * A header file for creating an independent layer to switch between 
 * platform specific lower-level functions.      
 *
 * This file was originally developed by Rhea Cooper. 
 *
 * @author Brian Kelly and Rhea Cooper
 * @date September 23, 2017
 *
 */

#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include "common.h"
#include "debug.h"

/**
 * @brief A feature to enable the printf functionality to be platform independent.
 *
 * Printf functionality needs to be disabled for the KL25z platform and enabled
 * for BBB and HOST platforms.  A compile time switch can be used for this.
 *
 */
#ifdef KL25Z
#endif

#ifdef BBB
	#define VERBOSE
#endif

#ifdef HOST
	#define VERBOSE
#endif

#endif /* __PLATFORM_H__ */
