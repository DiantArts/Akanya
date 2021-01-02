/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/ADrawable
** File description:
** Every class inheriting from this one should be able to be drawn. Must be inheriting with ATransformable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_ADRAWABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_ADRAWABLE_HPP___

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
    virtual void draw(const engine::Camera& camera) const;
    virtual void drawModels(const engine::Camera& camera) const = 0;

    // ---------------------------------------------------------------------------- Shader
    const engine::Shader& getShader() const;
    void useShader() const;
    virtual void configureShader(const engine::Camera& camera) const;

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



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_ADRAWABLE_HPP___
