# Cryengine Superluminal Plugin

An implementation for the [Superluminal](https://www.superluminal.eu) Performance API for Cryengine.

## Usage 
### Prerequisites
The Performance API files need to be copied from your local Superluminal installation into your engines SDK folder at `Code/SDKs/Superluminal` .

### Preparation
Clone this project into your engines Plugin folder at `Code/CryPlugins` .

Add the Plugin to your engines CMake build script and copy the correct `PerformanceAPI.dll` from the sdk folder to your target binary folder.

Optionally you can add the dll to `CopyFilesToBin.cmake` to have it copied on CMake generation.

Add `CrySuperluminal` to your projects loaded plugins in your `.cryproject`
### Include the code
To use ther Superluminal API in your cryengine project you just need to add this snippet to your project CMakeLists.txt:
 ```cmake
 include(${CRYENGINE_DIR}/Code/CryPlugins/CrySuperluminal/IncludeSuperluminal.cmake)
 ```
 From there on, you can use the API like described in the [documentation](https://www.superluminal.eu/docs/documentation.html).

 Should you not want the profiling code to be generated, just set the `USE_SUPERLUMINAL` cmake option to false.
 This will replace all the calls to the API with empty instructions.
 
 Keep in mind that the CrySuperluminal Plugin needs to be loaded for this to work. 

 ## Result
 ![Profiling Example](https://i.imgur.com/prRZ8C8.jpg)


 ## Todo
 Add some functionality to trigger intrumentation events without the need to add to the code directly.