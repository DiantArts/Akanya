/*
** EPITECH PROJECT, 2020
** threadPool
** File description:
** control a thread execution
*/

#ifndef THREADPOOL_HPP
#define THREADPOOL_HPP

namespace thp {

    class threadPool {
    public:
        explicit threadPool();
        ~threadPool();

        void add();
        void remove();

        void join() const;
        void size();

        std::uint_fast8_t getId() const;

    private:
        const std::uint_fast8_t id;
        std::list<int> pool
    };

} // namespace thp

#endif // THREADPOOL_HPP
