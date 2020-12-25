/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Drawable
** File description:
** Drawable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_DRAWABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_DRAWABLE_HPP___

#include <functional>
#include <string_view>

#include "../Camera.hpp"
#include "../Shader.hpp"



namespace engine::graphic {



class Drawable {
public:
    // ---------------------------------------------------------------------------- *structors
    Drawable(engine::Shader& shader);
    virtual ~Drawable() = 0;


    // ---------------------------------------------------------------------------- Draw
    void         draw(const engine::Camera& camera) const;
    virtual void drawModels(const engine::Camera& camera) const = 0;

    // ---------------------------------------------------------------------------- Update
    virtual void applyPerspective(const engine::Camera& camera) const;

    // ---------------------------------------------------------------------------- Shader
    void                  setShader(engine::Shader& shader);
    const engine::Shader& getShader() const;

protected:
    template <typename... Args>
    void setIntoShader(const std::string& name, const Args&... args) const
    {
        this->getShader().set(name, args...);
    }

    template <typename... Args>
    void setIntoShader(std::string&& name, const Args&... args) const
    {
        this->getShader().set(std::move(name), args...);
    }

private:
    std::reference_wrapper<engine::Shader> m_Shader;
};


} // namespace engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_DRAWABLE_HPP___
