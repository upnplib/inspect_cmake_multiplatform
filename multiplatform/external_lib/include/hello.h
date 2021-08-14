#ifndef HELLO_H
#define HELLO_H

// The following macro is needed to have the correct decorators on MS Windows.
// MSVC doesn't export symbols by default and need dllexport resp. dllimport
// decorators for the symbols.
#ifdef _WIN32
    #ifdef SHARED_EXPORTS
        #define EXPORT_SPEC __declspec(dllexport)
    #else
        #define EXPORT_SPEC __declspec(dllimport)
    #endif
#else
    #define EXPORT_SPEC
#endif


// Declare the library function we need; must be compiled with compiler option
// -D SHARED_EXPORTS, otherwise this symbol isn't exported on MS Windows.
EXPORT_SPEC void hello();

#endif /* HELLO_H */
