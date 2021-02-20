//
// Akanya
// sources/Engine/Component/AComponent
// Base of a component
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_COMPONENT_ACOMPONENT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_COMPONENT_ACOMPONENT_HPP___

namespace engine::component {

namespace detail {
struct Component {

    static inline size_t idGiver { 0 };

};
} // namespace detail



template <typename ComponentType>
class AComponent : private ::engine::component::detail::Component {
public:
    explicit AComponent() {};
    virtual ~AComponent() = 0 {};

    static size_t getId() { return m_id };
    static size_t getSize() { return m_size };


private:
    static inline const auto m_id { ++detail::Component::idGiver };
    static inline const auto m_size { sizeof(ComponentType) };

};




} // namespace engine::component

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_COMPONENT_ACOMPONENT_HPP___
