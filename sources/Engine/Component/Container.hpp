//
// Akanya
// sources/Engine/Component/Container
// Contains components
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_COMPONENT_CONTAINER_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_COMPONENT_CONTAINER_HPP___

namespace engine::component {



class Container {

public:

    // ---------------------------------- *structors

    explicit Container() {}

    ~Container() {}



    // ---------------------------------- Copy sementic

    Container(
        const Container&
    )noexcept = default;

    auto operator=(
        const Container&
    ) noexcept -> Container& = default;



    // ---------------------------------- Copy sementic

    Container(
        Container&&
    ) noexcept = default;

    auto operator=(
        Container&&
    ) noexcept -> Container& = default;



    // ---------------------------------- Vectors

    template<typename ComponentType>
    void constructVector()
    {
        m_container.emplace<>(typeid(ComponentType), std::vector<ComponentType>{});
    }

    template<typename ComponentType>
    std::vector<ComponentType>& getVector()
    {
        return boost::any_cast<std::vector<ComponentType>&>(m_container[typeid(ComponentType)]);
    }



public:
protected:
protected:
private:
private:

    std::unordered_map<std::type_index, boost::any> m_container;


};



} // namespace engine::component

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_COMPONENT_CONTAINER_HPP___
