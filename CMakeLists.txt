cmake_minimum_required(VERSION 3.10)
project(FlappyDXTK)

if(MSVC_VERSION GREATER 1700)
  set(COMPILER_VERSION "12")
elseif(MSVC_VERSION GREATER 1600)
  set(COMPILER_VERSION "11")
endif()

#Enable folders grouping in IDE
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set (APP_MANIFEST_NAME Package.appxmanifest)

set(EXE_NAME FlappyDXTK)
set(SHORT_NAME ${EXE_NAME})
set(PACKAGE_NAME "se.coderox.FlappyDXTK")
set(PUBLISHER_NAME "coderox")
set(PACKAGE_GUID "6515217e-dfd4-5edb-80df-4e0326346efc")

configure_file(
    cmake/${APP_MANIFEST_NAME}
    ${CMAKE_CURRENT_BINARY_DIR}/${APP_MANIFEST_NAME}
    @ONLY
)

set(SOURCE_FILES
    source/App.cpp
#    source/Main.cpp
#    source/Main.h
    source/pch.cpp
    source/pch.h
    ${CMAKE_CURRENT_BINARY_DIR}/${APP_MANIFEST_NAME}
    cmake/TemporaryKey.pfx
)

set(COMMON_FILES
#    source/common/DeviceResources.cpp
#    source/common/DeviceResources.h
#    source/common/DirectXHelper.h
#    source/common/StepTimer.h
)

set(CONTENT_FILES
#    source/content/Sample3DSceneRenderer.cpp
#    source/content/SampleFpsTextRenderer.cpp
#    source/content/Sample3DSceneRenderer.h
#    source/content/SampleFpsTextRenderer.h
#    source/content/ShaderStructures.h
)

set(PIXELSHADER_FILES
#    source/content/SamplePixelShader.hlsl
)

set(VERTEXSHADER_FILES
#    source/content/SampleVertexShader.hlsl
)

set(ASSET_FILES ${ASSET_FILES}
    assets/LockScreenLogo.scale-200.png
    assets/SplashScreen.scale-200.png
    assets/Square44x44Logo.scale-200.png
    assets/Square44x44Logo.targetsize-24_altform-unplated.png
    assets/Square150x150Logo.scale-200.png
    assets/StoreLogo.png
    assets/Wide310x150Logo.scale-200.png
)

set_property(SOURCE ${ASSET_FILES} PROPERTY VS_DEPLOYMENT_CONTENT 1)
set_property(SOURCE ${ASSET_FILES} PROPERTY VS_DEPLOYMENT_LOCATION "Assets")

#set_property(SOURCE ${PIXELSHADER_FILES} PROPERTY VS_DEPLOYMENT_CONTENT 1)
#set_property(SOURCE ${PIXELSHADER_FILES} PROPERTY VS_SHADER_TYPE Pixel)
#set_property(SOURCE ${PIXELSHADER_FILES} PROPERTY VS_SHADER_ENTRYPOINT main)
#set_property(SOURCE ${PIXELSHADER_FILES} PROPERTY VS_SHADER_MODEL 4.0_level_9_3)
#set_property(SOURCE ${PIXELSHADER_FILES} PROPERTY VS_SHADER_FLAGS "/DFLAGS_ADDED /Fh \"$(OutDir)%(Filename).h\"")

#set_property(SOURCE ${VERTEXSHADER_FILES} PROPERTY VS_DEPLOYMENT_CONTENT 1)
#set_property(SOURCE ${VERTEXSHADER_FILES} PROPERTY VS_SHADER_TYPE Vertex)
#set_property(SOURCE ${VERTEXSHADER_FILES} PROPERTY VS_SHADER_ENTRYPOINT main)
#set_property(SOURCE ${VERTEXSHADER_FILES} PROPERTY VS_SHADER_MODEL 4.0_level_9_3)
#set_property(SOURCE ${VERTEXSHADER_FILES} PROPERTY VS_SHADER_FLAGS "/DFLAGS_ADDED /Fh \"$(OutDir)%(Filename).h\"")

#source_group("common" FILES ${COMMON_FILES})
#source_group("content" FILES ${CONTENT_FILES})
#source_group("assets" FILES ${ASSET_FILES})

add_executable(${EXE_NAME} WIN32 ${SOURCE_FILES} ${COMMON_FILES} ${CONTENT_FILES} ${ASSET_FILES})

# This is the important line, making sure to point to the header file
target_include_directories(${EXE_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/source)
target_include_directories(${EXE_NAME} PRIVATE ${DEPENDENCIES_INCLUDE_DIRECTORIES})

set_target_properties(${EXE_NAME} PROPERTIES COMPILE_FLAGS "/Yupch.h")
set_source_files_properties(source/pch.cpp PROPERTIES COMPILE_FLAGS "/Ycpch.h")

set_property(TARGET ${EXE_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${EXE_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(${EXE_NAME} d2d1)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${EXE_NAME})
