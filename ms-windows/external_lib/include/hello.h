#ifndef HELLO_H
#define HELLO_H

// dllimport declaration is optional but only for functions. Anyway, it's always
// better for optimization. Import of data and objects always need it.

__declspec(dllimport) void hello();

#endif /* HELLO_H */
