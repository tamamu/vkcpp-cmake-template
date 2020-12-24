# CMakeList.txt : MinimalVulkan の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#
cmake_minimum_required (VERSION 3.8)

project ("MinimalVulkan")

# Ref. https://github.com/SaschaWillems/Vulkan/blob/master/CMakeLists.txt
if(WIN32)
  find_path(Vulkan_INCLUDE_DIR
    NAMES vulkan/vulkan.h
    PATHS
      "$ENV{VULKAN_SDK}/Include"
    )

  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    find_library(Vulkan_LIBRARY
      NAMES vulkan-1
      PATHS
        "$ENV{VULKAN_SDK}/Lib"
        "$ENV{VULKAN_SDK}/Bin"
        )
  elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    find_library(Vulkan_LIBRARY
      NAMES vulkan-1
      PATHS
        "$ENV{VULKAN_SDK}/Lib32"
        "$ENV{VULKAN_SDK}/Bin32"
        NO_SYSTEM_ENVIRONMENT_PATH
        )
  endif()
else()
    find_path(Vulkan_INCLUDE_DIR
      NAMES vulkan/vulkan.h
      PATHS
        "$ENV{VULKAN_SDK}/include")
    find_library(Vulkan_LIBRARY
      NAMES vulkan
      PATHS
        "$ENV{VULKAN_SDK}/lib")
endif()

set(Vulkan_LIBRARIES ${Vulkan_LIBRARY})
set(Vulkan_INCLUDE_DIRS ${Vulkan_INCLUDE_DIR})


# ソースをこのプロジェクトの実行可能ファイルに追加します。
find_package(Vulkan REQUIRED)

add_executable (MinimalVulkan "MinimalVulkan.cpp" "MinimalVulkan.h")

if(WIN32)
    set(GLFW_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3.2.bin.WIN64")
    include_directories("${GLFW_DIR}/include")
    target_link_libraries(MinimalVulkan Vulkan::Vulkan "${GLFW_DIR}/lib-vc2019\\glfw3.lib")
else()
    find_package(glfw3 3.3 REQUIRED)
    target_link_libraries(MinimalVulkan glfw)
endif()

include_directories(${Vulkan_INCLUDE_DIRS})
target_compile_definitions(MinimalVulkan PRIVATE VK_USE_PLATFORM_WIN32_KHR)

# TODO: テストを追加し、必要な場合は、ターゲットをインストールします。
