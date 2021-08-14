#include <iostream>

// To link with the *.dll you have to use the coresponding *.lib file.
// It is important to declare at least one symbol to export with
// __declspec(dllexport), otherwise you will not get a matching *.lib file.

void __declspec(dllexport) hello() {
    std::cout << "Hello World from external library :-)" << std::endl;
}
