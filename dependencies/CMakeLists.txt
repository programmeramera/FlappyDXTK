#########
# DirectXTK
message(STATUS "Adding DirectXTK")
add_subdirectory(directxtk ${CMAKE_CURRENT_BINARY_DIR}/dependencies/directxtk)

set(DEPENDENCIES_INCLUDE_DIRECTORIES 
    ${DEPENDENCIES_INCLUDE_DIRECTORIES} 
    "${CMAKE_CURRENT_LIST_DIR}/directxtk/Inc" 
    PARENT_SCOPE
)
