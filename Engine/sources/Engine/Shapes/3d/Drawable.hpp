/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#ifndef SHAPE3D_DRAWABLE_HPP
#define SHAPE3D_DRAWABLE_HPP

#include <vector>
#include <glm/vec3.hpp>
#include "Engine/TextureVector.hpp"
#include "Engine/Vertexes/Vao.hpp"
#include "Engine/Vertexes/Vbo.hpp"

namespace engine {

class Shader;
class Camera;

namespace shape3d {

class Drawable {
public:
    Drawable(engine::Shader& shader, size_t numberOfTextures = 1);
    virtual ~Drawable();

    void changeShader(engine::Shader& shader);
    void addPosition(float x = 0, float y = 0, float z = 0);
    void addPosition(glm::vec3& vec);
    void addTexture(const std::string_view filepath, const std::string_view name, int index);

    void draw(const engine::Camera& camera);

    virtual void setAllIntoShader() = 0;

public:
    static constexpr size_t numberOfArrayToDraw = 36;

protected:
    engine::Shader& m_Shader;

private:
    engine::Vao m_Vao;
    engine::Vbo m_Vbo;
    engine::TextureVector m_TextureVector;

    GLuint m_Ebo;
    std::vector<glm::vec3> m_Positions;
};

} // namespace shape3d
} // namespace engine

#endif // SHAPE3D_DRAWABLE_HPP
