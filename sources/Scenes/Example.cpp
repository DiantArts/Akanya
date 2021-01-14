/*
** EPITECH PROJECT, 2020
** sources/Scenes/Example
** File description:
** Simple example of a scene, mainly to test things
*/

#include "Example.hpp"

#include "Engine/Actors/Objects/EnlightenedCube.hpp"
#include "Engine/Actors/Objects/LightSourceCube.hpp"
#include "debugMacros.hpp"



namespace scene {



// ---------------------------------------------------------------------------- *structors

Example::Example()
{
    auto lightSource { std::make_unique<engine::actor::object::LightSourceCube>(m_ShaderMap["lightSource"],
                                                                         4) };

    lightSource->instances.add(-0.0F, 2.0F, 0.0F);
    lightSource->instances.add(-5.0F, 2.0F, 105.0F);
    lightSource->instances.add(-3.0F, 1.5F, -7.5F);
    lightSource->instances.add(5.0F, 2.0F, 105.0F);

    this->pushActor(std::move(lightSource));


    auto cube { std::make_unique<engine::actor::object::EnlightenedCube>(m_ShaderMap["multiEnlightened"]) };

    cube->addTexture("container.png", "material.diffuse");
    cube->addTexture("containerBorders.png", "material.specular");

    cube->instances.add(0.0F, 0.0F, 0.0F);
    cube->instances.add(2.0F, 10.0F, -15.0F);
    cube->instances.add(-1.5F, -2.2F, -2.5F);
    cube->instances.add(-3.8F, -2.0F, -12.3F);
    cube->instances.add(2.4F, -0.4F, -3.5F);
    cube->instances.add(-1.7F, 3.0F, -7.5F);
    cube->instances.add(1.3F, -2.0F, -2.5F);
    cube->instances.add(1.5F, 2.0F, -2.5F);
    cube->instances.add(1.5F, 0.2F, -1.5F);
    cube->instances.add(-1.3F, 1.0F, -1.5F);

    this->pushActor(std::move(cube));

    // backpack.instances.setPosition(-3.0F,  0.0F, 0.0F);
    backpack.instances.addPosition(-3.0F, 0.0F, 0.0F);
    backpack.instances.addPosition(3.0F, 0.0F, 0.0F);
    backpack.instances.addPosition(9.0F, 0.0F, 0.0F);
    // backpack.setScale(0.005F);
    // backpack.rotate(0, 0, 0);
}

Example::~Example()
{}



// ---------------------------------------------------------------------------- hardcoded

void Example::additionalDraws() const
{
    this->backpackShader.use();

    // this->backpackShader.set("dirLight.direction", m_Window.camera.getOrientation());
    // this->backpackShader.set("dirLight.ambient",
                             // m_Window.camera.parameters.ambient * glm::vec3 { 0 });
    // this->backpackShader.set("dirLight.diffuse",
                             // m_Window.camera.parameters.diffuse * glm::vec3 { 0 });
    // this->backpackShader.set("dirLight.specular",
                             // m_Window.camera.parameters.specular * glm::vec3 { 0 });

    for (auto light : engine::actor::light::ALight::getAll()) {
        this->backpackShader.set(light.name + ".position", light.position);
        this->backpackShader.set(light.name + ".ambient", light.parameters.ambient);
        this->backpackShader.set(light.name + ".diffuse", light.parameters.diffuse);
        this->backpackShader.set(light.name + ".specular", light.parameters.specular);
        this->backpackShader.set(light.name + ".constant", light.parameters.constant);
        this->backpackShader.set(light.name + ".linear", light.parameters.linear);
        this->backpackShader.set(light.name + ".quadratic", light.parameters.quadratic);
    }
    this->backpackShader.set("spotLight.cutOff", glm::cos(glm::radians(12.5F)));
    this->backpackShader.set("spotLight.outerCutOff", glm::cos(glm::radians(15.0F)));

    // this->backpackShader.set("viewPos", m_Window.camera.getPosition());
    this->backpackShader.set("material.shininess", 32.0F);

    this->backpack.draw(m_Window.camera);
}



} // namespace scene
