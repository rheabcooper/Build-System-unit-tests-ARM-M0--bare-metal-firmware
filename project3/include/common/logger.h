/*
 * logger_queue.h
 *
 *  Created on: Dec 3, 2017
 *      Author: rhco4796
 */

#ifndef INCLUDES_LOGGER_QUEUE_H_
#define INCLUDES_LOGGER_QUEUE_H_


typedef enum logidtype{
	LOGGER_INITIALIZED,
	GPIO_INITIALIZED,
	SYSTEM_INITIALIZED,
	SYSTEM_HALTED,
	INFO,
	WARNING,
	ERROR,
	PROFILING_STARTED,
	PROFILING_RESULT,
	PROFILING_COMPLETED,
	DATA_RECEIVED,
	DATA_ANALYSIS_STARTED,
	DATA_ALPHA_COUNT,
	NUMERIC_COUNT,
	DATA_PUNCTUATION_COUNT,
	DATA_MISC_COUNT,
	DATA_ANALYSIS_COMPLETED,
	HEARTBEAT
}log_id;

typedef struct{
	log_id logid;
	uint32_t timestamp;
	uint8_t loglength;
	uint8_t *payload;
	uint8_t checksum;

}Log_t;



Log_t *main_log;


void create_log(Log_t * logger_ptr, log_id ID, uint8_t length, uint8_t *pl);
void log_item(Log_t * logger_ptr);
void destroy_log(Log_t *logger_ptr);











#endif /* INCLUDES_LOGGER_QUEUE_H_ */
