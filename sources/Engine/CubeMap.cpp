/*
** EPITECH PROJECT, 2020
** sources/Engine/CubeMap
** File description:
** allow sky or things like that
*/

#include "CubeMap.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>

#include <glm/gtc/matrix_transform.hpp>

#include <stb/stb_image.h>

#include "Actors/Vertexes/Vertices.hpp"
#include "Filepaths.hpp"
#include "Window.hpp"



namespace engine::actor {



// ---------------------------------------------------------------------------- *structors

CubeMap::CubeMap(engine::Shader&              shader,
                 const std::function<void()>& setAttributesFunc /* = CubeMap::setAttributes */,
                 const std::string_view       verticesFilename,
                 const std::string_view       textureDirectory)
    : AActor(shader, 1), m_Texture(textureDirectory.data())
{
    this->m_Vbo.bind();
    this->m_Vao.bind();
    engine::Vertices(verticesFilename, this->m_NumberOfArrayToDraw).createBuffer();
    setAttributesFunc();

    this->instances.setPosition(0, 0, 0);

    this->useShader();
    this->setIntoShader("skybox", static_cast<int>(0));
}

CubeMap::~CubeMap()
{}



// ---------------------------------------------------------------------------- Drawable

void CubeMap::draw(const engine::Camera& camera) const
{
    glDepthFunc(GL_LEQUAL); // change depth function so depth test passes when values are equal to depth
                            // buffer's content
    ADrawable::draw(camera);
    glDepthFunc(GL_LESS); // set depth function back to default
}

void CubeMap::drawModels(const engine::Camera&) const
{
    this->m_Vao.bind();
    this->m_Texture.bind();
    glDrawArrays(GL_TRIANGLES, 0, this->m_NumberOfArrayToDraw);
}

void CubeMap::configureShader(const engine::Camera& camera) const
{
    this->setIntoShader("view", glm::mat4(glm::mat3(camera.getView())));
    this->setIntoShader("projection",
                        glm::perspective(glm::radians(camera.getZoom()),
                                         (float)Window::width / (float)Window::height, 0.1F, 100.0F));
}



// ---------------------------------------------------------------------------- defaultAttributes

void CubeMap::setAttributes()
{
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
}



// ---------------------------------------------------------------------------- Textures

CubeMap::Texture::Texture(const std::string& textureDirectory)
    : engine::Texture(textureDirectory)
{
    if (this->m_Id.use_count() == 1) { // if just created
        glBindTexture(GL_TEXTURE_CUBE_MAP, *this->m_Id);

        std::string textureConfigFilepath;
        textureConfigFilepath.reserve(textureDirectory.size() + engine::filepath::textures.size() + 17);
        textureConfigFilepath += engine::filepath::textures;
        textureConfigFilepath += textureDirectory;
        textureConfigFilepath += "/filepaths.config";

        std::ifstream configFile(textureConfigFilepath);
        if (!configFile.is_open()) {
            throw std::runtime_error(std::string("unable to open '") + textureConfigFilepath +
                                     "' texture config file");
        }


        std::string filepath, filename;
        filepath.reserve(textureDirectory.size() + engine::filepath::textures.size() + 1);
        filepath += engine::filepath::textures;
        filepath += textureDirectory;
        filepath += "/";
        size_t filepathSize { filepath.size() };

        stbi_set_flip_vertically_on_load(false);
        for (size_t i { 0 }; std::getline(configFile, filename); ++i) {
            filepath.replace(filepath.begin() + filepathSize, filepath.end(), filename);

            int        width, height, nrComponents;
            const auto data { stbi_load(filepath.c_str(), &width, &height, &nrComponents, 0) };

            if (!data) {
                stbi_image_free(const_cast<unsigned char*>(data));
                throw std::runtime_error(std::string("Failed to load '") + filepath + "' cube map's texture");
            }

            GLenum format;
            switch (nrComponents) {
            case 1: format = GL_RED; break;
            case 3: format = GL_RGB; break;
            case 4: format = GL_RGBA; break;
            default: throw std::runtime_error("unsupported texture format found");
            }

            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, format, width, height, 0, format,
                         GL_UNSIGNED_BYTE, data);
            stbi_image_free(const_cast<unsigned char*>(data));
        }
        stbi_set_flip_vertically_on_load(true);

        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    }
}

CubeMap::Texture::~Texture()
{}

void CubeMap::Texture::bind() const
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, *this->m_Id);
}



} // namespace engine::actor
