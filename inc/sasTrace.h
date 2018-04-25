/*
* DESCRIPTION :
*       Declares common API functions for software tracing.
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

#ifndef SAS_TRACE_H
#define SAS_TRACE_H

#include <stdint.h>

//Severity levels, from lowest to highest.
typedef enum sas_sev_level
{
	NONE     = 0,
        LOW      = 1,
	MEDIUM   = 2,
	HIGH     = 3,
	SEVERE   = 4,
	CRITICAL = 5
} sas_sev_level_t;

#define SAS_TRACE_0(level, file_id) sas_trace_0(level, file_id, (uint16_t) __LINE__)
#define SAS_TRACE_1(level, file_id, p1) sas_trace_1(level, file_id, (uint16_t) __LINE__, p1)
#define SAS_TRACE_2(level, file_id, p1, p2) sas_trace_2(level, file_id, (uint16_t) __LINE__, p1, p2)
#define SAS_TRACE_3(level, file_id, p1, p2, p3) sas_trace_3(level, file_id, (uint16_t) __LINE__, p1, p2, p3)
#define SAS_TRACE_4(level, file_id, p1, p2, p3, p4) sas_trace_4(level, file_id, (uint16_t) __LINE__, p1, p2, p3, p4)
#define SAS_TRACE_5(level, file_id, p1, p2, p3, p4, p5) sas_trace_5(level, file_id, (uint16_t) __LINE__, p1, p2, p3, p4, p5)
#define SAS_TRACE_6(level, file_id, p1, p2, p3, p4, p5, p6) sas_trace_6(level, file_id, (uint16_t) __LINE__, p1, p2, p3, p4, p5, p6)
#define SAS_TRACE_7(level, file_id, p1, p2, p3, p4, p5, p6, p7) sas_trace_7(level, file_id, (uint16_t) __LINE__, p1, p2, p3, p4, p5, p6, p7)

void sas_trace_0(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number);
void sas_trace_1(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1);
void sas_trace_2(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1, uint32_t p2);
void sas_trace_3(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1, uint32_t p2, uint32_t p3);
void sas_trace_4(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4);
void sas_trace_5(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5);
void sas_trace_6(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6);
void sas_trace_7(sas_sev_level_t sev_level, uint16_t file_id, uint16_t line_number, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6, uint32_t p7);

#endif // SAS_TRACE_H
