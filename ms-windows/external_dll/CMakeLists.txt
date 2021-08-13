message("-- Linking hello")
add_library(hello hello.dll)
set_target_properties(hello PROPERTIES LINKER_LANGUAGE C)
