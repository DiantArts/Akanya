/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Drawable
** File description:
** Drawable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_DRAWABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_DRAWABLE_HPP___

#include <functional>

#include "Vertexes/Vao.hpp"
#include "Vertexes/Vbo.hpp"

#include "../Camera.hpp"
#include "../Container/Vector/Texture.hpp"
#include "../NonCopyable.hpp"
#include "../Shader.hpp"



namespace engine::graphic {



class Drawable : public engine::NonCopyable {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Drawable(engine::Shader&              shader,
                      const std::function<void()>& setAttributes,
                      const size_t                 numberOfTextures);
    virtual ~Drawable() = 0;


    // ---------------------------------------------------------------------------- draw
    void draw(const engine::Camera& camera) const;


    // ---------------------------------------------------------------------------- Shader
    void                  setShader(engine::Shader& shader);
    const engine::Shader& getShader() const;


    // ---------------------------------------------------------------------------- Textures
    void addTexture(const std::string_view filepath, const std::string_view name, const int index);
    const engine::container::vector::Texture& getTextures() const;


    // ---------------------------------------------------------------------------- set
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


    // ---------------------------------------------------------------------------- pure virtuals
    virtual void transformShape(const engine::Camera& camera) const = 0;
    virtual void drawModels() const                                 = 0;


protected:
    mutable std::reference_wrapper<engine::Shader> m_Shader;
    engine::container::vector::Texture             m_TextureVector; // TODO: std::optional + Material class
                                                                    // if numberOfTexture == 0

private:
    engine::Vao m_Vao;
    engine::Vbo m_Vbo;
};



} // namespace engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_DRAWABLE_HPP___
