/*
** EPITECH PROJECT, 2020
** Pool
** File description:
** control a thread execution
*/

#ifndef POOL_HPP
#define POOL_HPP

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

#endif // POOL_HPP
