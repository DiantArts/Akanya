/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/ADrawable
** File description:
** ADrawable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_DRAWABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_DRAWABLE_HPP___

#include <functional>
#include <string_view>

#include "../Camera.hpp"
#include "../Shader.hpp"



namespace engine::actor {



class ADrawable {
public:
    // ---------------------------------------------------------------------------- *structors
    ADrawable(engine::Shader& shader);
    virtual ~ADrawable() = 0;


    // ---------------------------------------------------------------------------- Draw
    void         draw(const engine::Camera& camera) const;
    virtual void drawModels(const engine::Camera& camera) const = 0;

    // ---------------------------------------------------------------------------- Update
    virtual void configureShader(const engine::Camera& camera) const;

    // ---------------------------------------------------------------------------- Shader
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
    const engine::Shader& m_Shader;
};


} // namespace engine::actor



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_DRAWABLE_HPP___
