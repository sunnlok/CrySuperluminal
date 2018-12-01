#pragma once
//Empty proxy header to allow easy toggling of performance api inclusion


namespace PerformanceAPI
{
	struct InstrumentationScope final
	{
		InstrumentationScope(const char* inName) {};
		InstrumentationScope(const char* inName, const char* inContext) {};
		~InstrumentationScope() {};
	};

	void SetCurrentThreadName(const char* inThreadName) {};

	#define PERFORMANCEAPI_INSTRUMENT(Name)						PerformanceAPI::InstrumentationScope __instrumentation_scope__((Name));
	#define PERFORMANCEAPI_INSTRUMENT_CONTEXT(Name, Context)	PerformanceAPI::InstrumentationScope __instrumentation_scope__((Name), (Context));
	#define PERFORMANCEAPI_INSTRUMENT_FUNCTION()				PERFORMANCEAPI_INSTRUMENT(__FUNCTION__)
	#define PERFORMANCEAPI_INSTRUMENT_FUNCTION_CONTEXT(Context)	PERFORMANCEAPI_INSTRUMENT_CONTEXT(__FUNCTION__, (Context))
}