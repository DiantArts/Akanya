//
// Akanya
// sources/Engine/Component/Drawable
// Drawable component
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_COMPONENT_DRAWABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_COMPONENT_DRAWABLE_HPP___

namespace engine::component {



class Drawable {

public:

    // ---------------------------------- *structors

    explicit Drawable();

    ~Drawable();



    // ---------------------------------- Copy sementic

    Drawable(
        const Drawable&
    ) noexcept;

    auto operator=(
        const Drawable&
    ) noexcept -> Drawable&;



    // ---------------------------------- Copy sementic

    Drawable(
        Drawable&&
    ) noexcept;

    auto operator=(
        Drawable&&
    ) noexcept -> Drawable&;



public:
protected:
protected:
private:
private:

};



} // namespace engine::component

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_COMPONENT_DRAWABLE_HPP___
