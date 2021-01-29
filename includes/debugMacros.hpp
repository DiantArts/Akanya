//
// Akanya, Engine
// macros
// macros of the program
//

#ifndef ___INCLUDE_GUARD_INCLUDES_DEBUGMACROS_HPP___
#define ___INCLUDE_GUARD_INCLUDES_DEBUGMACROS_HPP___

#include "pch.hpp"

#if DEBUG > 0

inline std::ostream& operator<<(std::ostream& os, const glm::vec2& vec)
{
    os << "[" << vec.x << ", " << vec.y << "]";
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const glm::vec3& vec)
{
    os << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]";
    return os;
}

inline std::recursive_mutex debugClogMutex;
inline int                  isDebugClogMutexLocked = 0;
inline std::string          str;

#define NESTED_DEBUG_MSG(message)                                                                            \
    {                                                                                                        \
        std::lock_guard<std::recursive_mutex> debugClogLockGuard(debugClogMutex);                            \
        if (isDebugClogMutexLocked == 1) {                                                                   \
            std::clog << "\n";                                                                               \
            isDebugClogMutexLocked--;                                                                        \
        }                                                                                                    \
        std::clog << "[" << __FILE__ << ":" << __LINE__ << "]";                                              \
        if (isDebugClogMutexLocked == 1) {                                                                   \
            std::clog << " - ";                                                                              \
        }                                                                                                    \
        isDebugClogMutexLocked++;                                                                            \
        auto msg               = message;                                                                    \
        isDebugClogMutexLocked = (!isDebugClogMutexLocked) ? 0 : isDebugClogMutexLocked - 1;                 \
        if (!isDebugClogMutexLocked) {                                                                       \
            std::clog << "[" << __FILE__ << ":" << __LINE__ << "] - ";                                       \
        }                                                                                                    \
        std::clog << msg << "\n";                                                                            \
    }

#define DEBUG_MSG(message)                                                                                   \
    {                                                                                                        \
        std::lock_guard<std::recursive_mutex> debugClogLockGuard(debugClogMutex);                            \
        if (isDebugClogMutexLocked == 1) {                                                                   \
            std::clog << "\n";                                                                               \
            isDebugClogMutexLocked--;                                                                        \
        }                                                                                                    \
        isDebugClogMutexLocked++;                                                                            \
        std::clog << "[" << __FILE__ << ":" << __LINE__ << "] - " << message << "\n";                        \
        isDebugClogMutexLocked--;                                                                            \
    }

#define DEBUG_FUNC                                                                                           \
    {                                                                                                        \
        std::lock_guard<std::recursive_mutex> debugClogLockGuard(debugClogMutex);                            \
        if (isDebugClogMutexLocked == 1) {                                                                   \
            std::clog << "\n";                                                                               \
            isDebugClogMutexLocked--;                                                                        \
        }                                                                                                    \
        isDebugClogMutexLocked++;                                                                            \
        std::clog << '[' << __FILE__ << ':' << __LINE__ << "] (" << __FUNCTION__ << ")" << std::endl;        \
        isDebugClogMutexLocked--;                                                                            \
    }

#define DEBUG_PRETTY_FUNC                                                                                    \
    {                                                                                                        \
        std::lock_guard<std::recursive_mutex> debugClogLockGuard(debugClogMutex);                            \
        if (isDebugClogMutexLocked == 1) {                                                                   \
            std::clog << "\n";                                                                               \
            isDebugClogMutexLocked--;                                                                        \
        }                                                                                                    \
        isDebugClogMutexLocked++;                                                                            \
        std::clog << '[' << __FILE__ << ':' << __LINE__ << "] (" << __PRETTY_FUNCTION__ << ")" << std::endl; \
        isDebugClogMutexLocked--;                                                                            \
    }

#if DEBUG > 1
namespace debuging {
class check_time {
public:
    check_time(const std::string file, const std::string function, const int line)
        : m_clockStart(std::chrono::high_resolution_clock::now())
        , m_file(file)
        , m_function(function)
        , m_line(line)
    {
        std::lock_guard<std::recursive_mutex> debugClogLockGuard(debugClogMutex);

        if (isDebugClogMutexLocked == 1) {
            std::clog << "\n";
            isDebugClogMutexLocked--;
        }
        std::clog << "[" << m_file << ":" << m_line << "] (" << m_function << ")\n";
    }

    ~check_time()
    {
        m_clockEnd = std::chrono::high_resolution_clock::now();

        std::clog << "[" << m_file << ":" << m_line << "] (" << m_function << ") - "
                  << std::chrono::duration<float>(m_clockEnd - m_clockStart).count() * 1000.0f << "ms\n";
        isDebugClogMutexLocked = false;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_clockStart, m_clockEnd;
    std::string                                                 m_file, m_function;
    int                                                         m_line;
};
} // namespace debuging
#define DEBUG_TIME debuging::check_time checking_time_class(__FILE__, __FUNCTION__, __LINE__)


#else // DEBUG > 1


namespace debuging {
class check_time {
public:
    check_time(const std::string file, const std::string function, const int line)
        : m_file(file), m_function(function), m_line(line)
    {
        std::lock_guard<std::recursive_mutex> debugClogLockGuard(debugClogMutex);

        if (isDebugClogMutexLocked == 1) {
            std::clog << "\n";
            isDebugClogMutexLocked--;
        }
        std::clog << "[" << m_file << ":" << m_line << "] (" << m_function << ")\n";
    }

    ~check_time()
    {
        std::lock_guard<std::recursive_mutex> debugClogLockGuard(debugClogMutex);

        std::clog << "[" << m_file << ":" << m_line << "] (" << m_function << ") - Exit\n";
    }

private:
    std::string m_file, m_function;
    int         m_line;
};
} // namespace debuging
#define DEBUG_TIME debuging::check_time checking_time_class(__FILE__, __FUNCTION__, __LINE__)
#endif // DEBUG > 1

#else // DEBUG > 0

#define DEBUG_MSG(message)
#define DEBUG_FUNC
#define DEBUG_PRETTY_FUNC
#define DEBUG_TIME

#endif // DEBUG > 0


#define ERROR_MSG(message)                                                                                   \
    std::cerr << "ERROR [" << __FILE__ << ':' << __LINE__ << ']' << " - " << message << std::endl

#define THROW_MSG(throwMsg)                                                                                  \
    std::cerr << "[" << __FILE__ << ':' << __LINE__ << ']' << std::endl, throw throwMsg,


#endif // ___INCLUDE_GUARD_INCLUDES_DEBUGMACROS_HPP___
