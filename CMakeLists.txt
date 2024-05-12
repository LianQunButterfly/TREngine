
cmake_minimum_required(VERSION 3.20)
project(TREngine)
# 添加Include路径
include_directories(vendor/GLFW/include)
include_directories(vendor/glad/include)
include_directories(include)
include_directories(vendor/glm-master)
include_directories(imgui)
# 添加你的源文件和头文件
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.cxx" "src/*.c" "src/*.cc")
file(GLOB_RECURSE HEADER_FILES "include/*.h" "include/*.hpp" "include/*.hxx")
file(GLOB_RECURSE IMGUI "imgui/*.h" "imgui/*.cpp" )
file(GLOB_RECURSE GLAD "vendor/glad/include/glad/glad.h" "vendor/glad/include/KHR/khrplatform.h" "vendor/glad/src/glad.c")
# 添加依赖库
find_package(OpenGL REQUIRED)


# 添加可执行文件
add_executable(TREngine ${SOURCE_FILES} ${HEADER_FILES} ${GLAD} ${IMGUI})
target_link_libraries(TREngine PUBLIC lib/glfw3
OpenGL::GL
)
target_link_libraries(TREngine PUBLIC  lib/opencv_world490d
)
