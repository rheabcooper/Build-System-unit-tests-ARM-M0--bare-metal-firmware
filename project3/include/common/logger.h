/*
 * logger.h
 *
 *  Created on: Dec 3, 2017
 *      Author: rhco4796
 */

#ifndef INCLUDES_LOGGER_H_
#define INCLUDES_LOGGER_H_

void log_integer_host(int32_t integer_value,uint8_t length);

void flush();
void log_string_host(uint8_t * data);

void log_data_host(uint8_t * data,uint8_t length);

void log_data(uint8_t * data,uint8_t length);

void log_string(uint8_t * data);

void log_integer(uint32_t integer_value,uint8_t length);



#endif /* INCLUDES_LOGGER_H_ */
