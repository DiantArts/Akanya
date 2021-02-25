//
// Akanya
// sources/Engine/Physic/Hitbox
// Hitbox of everything
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_PHYSIC_HITBOX_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_PHYSIC_HITBOX_HPP___

namespace engine::graphic::actor { class AActor; }



namespace engine::physic {



class Hitbox {

public:

    // ---------------------------------- *structors

    explicit Hitbox();

    ~Hitbox();



    // ---------------------------------- Copy sementic

    Hitbox(
        const Hitbox&
    ) noexcept;

    auto operator=(
        const Hitbox&
    ) noexcept -> Hitbox&;



    // ---------------------------------- Copy sementic

    Hitbox(
        Hitbox&&
    ) noexcept;

    auto operator=(
        Hitbox&&
    ) noexcept -> Hitbox&;



    // ---------------------------------- Vec

    void add(
        const ::glm::vec3& box
    );

    void add(
        ::glm::vec3&& box
    );



    auto get() const
        -> const ::std::vector<::glm::vec3>&;



    // ---------------------------------- Collision

    auto isColliding(
        const ::engine::graphic::actor::AActor& other
    ) const -> bool;

    auto isColliding(
        const ::engine::physic::Hitbox& other
    ) const -> bool;

    auto isColliding(
        const ::glm::vec3& other
    ) const -> bool;



public:
protected:
protected:
private:
private:

    ::std::vector<::glm::vec3> m_boxes;

};



} // namespace engine::physic

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_PHYSIC_HITBOX_HPP___
