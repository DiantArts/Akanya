/*
** EPITECH PROJECT, 2020
** libraries/Tools/FuncAlias
** File description:
** Just a define
*/

#ifndef ___INCLUDE_GUARD_LIBRARIES_TOOLS_FUNCALIAS_HPP___
#define ___INCLUDE_GUARD_LIBRARIES_TOOLS_FUNCALIAS_HPP___



#define FUNC_ALIAS(highLevelFunc, lowLevelFunc)                                                              \
    template <typename... Args>                                                                              \
    inline auto highLevelFunc(Args&&... args)->decltype(lowLevelFunc(std::forward<Args>(args)...))           \
    {                                                                                                        \
        return lowLevelFunc(std::forward<Args>(args)...);                                                    \
    }

#define CONST_FUNC_ALIAS(highLevelFunc, lowLevelFunc)                                                        \
    template <typename... Args>                                                                              \
    inline auto highLevelFunc(Args&&... args) const->decltype(lowLevelFunc(std::forward<Args>(args)...))     \
        const                                                                                                \
    {                                                                                                        \
        return lowLevelFunc(std::forward<Args>(args)...);                                                    \
    }



#endif // ___INCLUDE_GUARD_LIBRARIES_TOOLS_FUNCALIAS_HPP___
