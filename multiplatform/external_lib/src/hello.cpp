#include "hello.h"
#include <iostream>

// To link with the *.dll you have to use the coresponding *.lib file.
// It is important to declare at least one symbol to export with
// __declspec(dllexport) (expanded by the macro EXPORT_SPEC), otherwise you
// will not get a matching *.lib file.
// We need to compile this library with compiler option -D SHARED_EXPORTS.

void EXPORT_SPEC hello() {
    std::cout << "Hello World from external library :-)" << std::endl;
}
