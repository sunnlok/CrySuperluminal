#pragma once
//Empty proxy header to allow easy toggling of performance api inclusion


namespace PerformanceAPI
{
	struct PERFORMANCEAPI_EXPORT InstrumentationScope final
	{
		InstrumentationScope(const char* inName) {};
		InstrumentationScope(const char* inName, const char* inContext) {};
		~InstrumentationScope() {};
	};

	void SetCurrentThreadName(const char* inThreadName) {};

	#define PERFORMANCEAPI_INSTRUMENT(Name)						void;
	#define PERFORMANCEAPI_INSTRUMENT_CONTEXT(Name, Context)	void;
	#define PERFORMANCEAPI_INSTRUMENT_FUNCTION()				void;
	#define PERFORMANCEAPI_INSTRUMENT_FUNCTION_CONTEXT(Context)	void;
}