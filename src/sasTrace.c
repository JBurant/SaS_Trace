/*
* DESCRIPTION :
*       Main source file, contains initialization and tracing system.
*		
* LICENSE :
*       This file is a part of the Simple and Stupid (SaS) software suite. The software is open source and licensed under the Thumbs-Up license. 
*       License statement:
*         Anyone is allowed to use, copy and modify the source code as they please. The only requirement is to keep the mention about the author and (if satisfied with the code)
*         give him Thumbs-Up in case we should ever meet. The author is not responsible for the way the software is used.
*
* AUTHOR : Jiri Burant    
*   
* START DATE : 04.17.2018
*/

#include <stdint.h>
#include "sasTrace.h"
#include "sasTraceInit.h"

#define NULL 0

typedef uint8_t trace_buffer_t;

static inline sas_return_t sas_general_trace(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number);

static const uint8_t MIN_TRACE_LENGTH;

static sas_trace_timer_callback_t *s_timer_callback;
static uint8_t  *s_trace_buffer_ptr;
static uint16_t  s_trace_buffer_length;
static uint16_t  s_current_buffer_position;
static uint16_t  s_trace_counter;

sas_return_t sas_init_buffer(uint8_t *trace_buffer_ptr, uint16_t trace_buffer_length, sas_trace_timer_callback_t *timer_callback)
{
	if(timer_callback != NULL)
	{
		s_timer_callback = timer_callback;
	}
	else
	{
		return RET_NULL_POINTER;
	}

	if(trace_buffer_length > (MIN_TRACE_LENGTH))
	{
		s_trace_buffer_length = trace_buffer_length;
	}
	else
	{
		return RET_WRONG_LENGTH;
	}
	
	if(s_trace_buffer_ptr != NULL)
	{
		s_trace_buffer_ptr = (trace_buffer_t*) trace_buffer_ptr;
	}
	else
	{
		return RET_NULL_POINTER;
	}
	
	s_current_buffer_position = 0;
	s_trace_counter = 0;
	
	return RET_OK;
}

static inline sas_return_t sas_general_trace(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number)
{
	*(s_trace_buffer_ptr + s_current_buffer_position) = s_trace_counter;
	s_current_buffer_position += sizeof(s_trace_counter);
	*(s_trace_buffer_ptr + s_current_buffer_position) = file_id;
    s_current_buffer_position += sizeof(file_id);
	*(s_trace_buffer_ptr + s_current_buffer_position) = line_number;
    s_current_buffer_position += sizeof(line_number);
	*(s_trace_buffer_ptr + s_current_buffer_position) = sev_level;
	s_current_buffer_position += sizeof(sev_level);
}

void sas_trace_0(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number)
{
	sas_general_trace(sev_level, file_id, line_number);
}

void sas_trace_1(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1)
{
	sas_general_trace(sev_level, file_id, line_number);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p1;
	s_current_buffer_position += sizeof(p1);
}

void sas_trace_2(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1, uint32_t p2)
{
	sas_general_trace(sev_level, file_id, line_number);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p1;
	s_current_buffer_position += sizeof(p1);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p2;
	s_current_buffer_position += sizeof(p2);
}

void sas_trace_3(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1, uint32_t p2, uint32_t p3)
{
	sas_general_trace(sev_level, file_id, line_number);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p1;
	s_current_buffer_position += sizeof(p1);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p2;
	s_current_buffer_position += sizeof(p2);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p3;
	s_current_buffer_position += sizeof(p3);
}

void sas_trace_4(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4)
{
	sas_general_trace(sev_level, file_id, line_number);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p1;
	s_current_buffer_position += sizeof(p1);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p2;
	s_current_buffer_position += sizeof(p2);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p3;
	s_current_buffer_position += sizeof(p3);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p4;
	s_current_buffer_position += sizeof(p4);
}

void sas_trace_5(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5)
{
	sas_general_trace(sev_level, file_id, line_number);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p1;
	s_current_buffer_position += sizeof(p1);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p2;
	s_current_buffer_position += sizeof(p2);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p3;
	s_current_buffer_position += sizeof(p3);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p4;
	s_current_buffer_position += sizeof(p4);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p5;
	s_current_buffer_position += sizeof(p5);
}

void sas_trace_6(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6)
{
	sas_general_trace(sev_level, file_id, line_number);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p1;
	s_current_buffer_position += sizeof(p1);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p2;
	s_current_buffer_position += sizeof(p2);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p3;
	s_current_buffer_position += sizeof(p3);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p4;
	s_current_buffer_position += sizeof(p4);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p5;
	s_current_buffer_position += sizeof(p5);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p6;
	s_current_buffer_position += sizeof(p6);
}

void sas_trace_7(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7)
{
	sas_general_trace(sev_level, file_id, line_number);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p1;
	s_current_buffer_position += sizeof(p1);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p2;
	s_current_buffer_position += sizeof(p2);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p3;
	s_current_buffer_position += sizeof(p3);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p4;
	s_current_buffer_position += sizeof(p4);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p5;
	s_current_buffer_position += sizeof(p5);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p6;
	s_current_buffer_position += sizeof(p6);
	*(s_trace_buffer_ptr + s_current_buffer_position) = p7;
	s_current_buffer_position += sizeof(p7);
}
