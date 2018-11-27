start_sources()
sources_platform(ALL)
add_sources("CrySuperluminal_uber_0.cpp"
	SOURCE_GROUP "Root"
		"CrySuperluminalDLL.cpp"
		"CrySuperluminalDLL.h"
		"Superluminal.cpp"
		"Superluminal.h"
		"resource.h"
		"StdAfx.cpp"
		"StdAfx.h"
)

add_sources("NoUberFile"
	SOURCE_GROUP "Root"
		"StdAfx.cpp"
)

end_sources()
#END-FILE-LIST

CryEngineModule(CrySuperluminal PCH "StdAfx.cpp" SOLUTION_FOLDER "CryPlugins")

target_include_directories( ${THIS_PROJECT} PRIVATE ${SDK_DIR}/Superluminal/VS2017/x64 )
find_library(SUPERLUMINAL PerformanceAPI PATHS ${SDK_DIR}/Superluminal/VS2017/x64 )

target_link_libraries(${THIS_PROJECT} PRIVATE ${SUPERLUMINAL})
target_include_directories(${THIS_PROJECT} PRIVATE "${CRYENGINE_DIR}/Code/CryEngine/CryCommon" PUBLIC ../Interface)