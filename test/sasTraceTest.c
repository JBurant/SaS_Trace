#include <time.h>
#include <sasTrace.h>
#include <sasTraceInit.h>

#define FILE_ID 1

static uint8_t trace_buffer_t[1024];

uint64_t dummyTimer()
{
	time_t retTime;
	return (uint64_t)time(&retTime);
}

int main ()
{
	sas_return_t retVal = sas_init_buffer(trace_buffer_t, 1024, dummyTimer);

	if(RET_OK == retVal)
	{
		SAS_TRACE_0(MEDIUM, FILE_ID);  //Init successfull
	}
}
