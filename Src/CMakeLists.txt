include_directories(${ROOT_DIR}/Inc)
                                   
add_executable(editor.out main.cpp)

install(TARGETS editor.out DESTINATION ${ROOT_DIR}/bin)