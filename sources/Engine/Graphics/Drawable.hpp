/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Drawable
** File description:
** Drawable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_DRAWABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_DRAWABLE_HPP___

#include <string_view>
#include <functional>

#include "../Camera.hpp"
#include "../Shader.hpp"



namespace engine::graphic {



class Drawable {
public:
    // ---------------------------------------------------------------------------- *structors
    Drawable(engine::Shader& shader);
    virtual ~Drawable() = 0;


    // ---------------------------------------------------------------------------- Draw
    virtual void draw(const engine::Camera& camera) const;
    virtual void drawModels(const engine::Camera& camera) const = 0;

    // ---------------------------------------------------------------------------- Update
    virtual void update(float deltaTime);
    virtual void transformShape(const engine::Camera& camera) const; // TODO: shapeFromPointOfView

    // ---------------------------------------------------------------------------- Shader
    void                  setShader(engine::Shader& shader);
    const engine::Shader& getShader() const;

    template <typename... Args>
    void set(const std::string& name, const Args&... args) const
    {
        const_cast<engine::Shader&>(this->getShader()).set(name, args...);
    }

    template <typename... Args>
    void set(std::string&& name, const Args&... args) const
    {
        const_cast<engine::Shader&>(this->getShader()).set(std::move(name), args...);
    }

protected:
    mutable std::reference_wrapper<engine::Shader> m_Shader;
};


} // namespace engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_DRAWABLE_HPP___
