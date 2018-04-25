/*
* DESCRIPTION :
*       Declares initialization functions of the trace system.
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

#ifndef SAS_TRACE_INIT_H
#define SAS_TRACE_INIT_H

typedef enum sas_file_mode
{
	OPEN_ONLY_ONCE,
	OPEN_EACH_TIME
} sas_file_mode_t;

typedef enum sas_return
{
	RET_OK,
	RET_WRONG_LENGTH,
	RET_NULL_POINTER
} sas_return_t;

typedef uint64_t (sas_trace_timer_callback_t)(void);

sas_return_t sas_init_buffer(uint8_t *trace_buffer_ptr, uint16_t trace_buffer_length, sas_trace_timer_callback_t *timer_callback);
//sas_return_t sas_init_file  (uint8_t *trace_buffer_ptr);

#endif //SAS_TRACE_INIT_H
