/*
** Akanya, Engine
** optimizationBuiltins
** builtins
*/

#ifndef OPTIMIZATIONBUILTINS_HPP
#define OPTIMIZATIONBUILTINS_HPP

#define likely(x)   __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)

#endif // OPTIMIZATIONBUILTINS_HPP
