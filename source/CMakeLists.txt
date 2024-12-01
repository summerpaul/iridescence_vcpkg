project(iridescence_source)
find_package(OpenGL REQUIRED)

find_package(glm)
find_package(Eigen3)
find_package(PNG)
find_package(JPEG)
find_package(assimp QUIET)
find_package(imgui CONFIG REQUIRED)
find_package(imguizmo CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(PNG REQUIRED)
find_package(gl3w CONFIG REQUIRED)

set(iridescence_include_dirs
    "include/glk"
    "include/glk/effects"
    "include/glk/io"
    "include/glk/primitives"
    "include/guik"
    "include/guik/camera"
    "include/guik/viewer"
)

foreach(dir ${iridescence_include_dirs})
    file(GLOB_RECURSE header_files "${dir}/*.h" "${dir}/*.hpp" "${dir}/*.hxx")
    list(APPEND ALL_HEADERS ${header_files})
endforeach()



set(iridescence_src_dirs
    "src/glk"
    "src/glk/effects"
    "src/glk/io"
    "src/glk/primitives"
    "src/guik"
    "src/guik/camera"
    "src/guik/viewer"
)


foreach(dir ${iridescence_src_dirs})
    file(GLOB_RECURSE src_files "${dir}/*.cpp" )
    list(APPEND ALL_SRCS ${src_files})
endforeach()

add_library(libiridescence  ${ALL_SRCS} ${ALL_HEADERS})
target_link_libraries(libiridescence PRIVATE assimp::assimp)
target_link_libraries(libiridescence PRIVATE Eigen3::Eigen)
target_link_libraries(libiridescence PRIVATE imgui::imgui)
target_link_libraries(libiridescence PRIVATE imguizmo::imguizmo)
target_link_libraries(libiridescence PRIVATE implot::implot)
target_link_libraries(libiridescence PRIVATE glad::glad)
target_link_libraries(libiridescence PRIVATE PNG::PNG)
target_link_libraries(libiridescence PRIVATE unofficial::gl3w::gl3w)