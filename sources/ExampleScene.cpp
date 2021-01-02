/*
** EPITECH PROJECT, 2020
** sources/ExampleScene
** File description:
** Simple example of a scene, mainly to test things
*/

#include "ExampleScene.hpp"

#include "Engine/Actors/Objects/EnlightenedCube.hpp"
#include "Engine/Actors/Objects/LightSourceCube.hpp"
#include "debugMacros.hpp"


engine::object::LightSourceCube* lamp;



ExampleScene::ExampleScene()
{
    auto lightSource { std::make_unique<engine::object::LightSourceCube>(this->m_ShaderMap["lightSource"],
                                                                         4) };

    lightSource->instances.add(-0.0F, 2.0F, 0.0F);
    lightSource->instances.add(-5.0F, 2.0F, 105.0F);
    lightSource->instances.add(-3.0F, 1.5F, -7.5F);
    lightSource->instances.add(5.0F, 2.0F, 105.0F);

    this->pushActor(std::move(lightSource));
    lamp = dynamic_cast<engine::object::LightSourceCube*>(&(*this->m_VectorActors.back()));


    auto cube { std::make_unique<engine::object::EnlightenedCube>(this->m_ShaderMap["multiEnlightened"]) };

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
    // backpack.setScale(0.005F);
    // backpack.rotate(0, 0, 0);
}

ExampleScene::~ExampleScene()
{}



void ExampleScene::additionalDraws() const
{
    this->backpackShader.set("dirLight.direction", this->m_Window.camera.getOrientation());
    this->backpackShader.set("dirLight.ambient",
                             this->m_Window.camera.getParameters().ambient * glm::vec3 { 0 });
    this->backpackShader.set("dirLight.diffuse",
                             this->m_Window.camera.getParameters().diffuse * glm::vec3 { 0 });
    this->backpackShader.set("dirLight.specular",
                             this->m_Window.camera.getParameters().specular * glm::vec3 { 0 });

    this->backpackShader.set("pointLights[0].position", lamp->instances[0]);
    this->backpackShader.set("pointLights[0].ambient", lamp->getParameters().ambient);
    this->backpackShader.set("pointLights[0].diffuse", lamp->getParameters().diffuse);
    this->backpackShader.set("pointLights[0].specular", lamp->getParameters().specular);
    this->backpackShader.set("pointLights[0].constant", lamp->getParameters().constant);
    this->backpackShader.set("pointLights[0].linear", lamp->getParameters().linear);
    this->backpackShader.set("pointLights[0].quadratic", lamp->getParameters().quadratic);

    this->backpackShader.set("pointLights[1].position", lamp->instances[1]);
    this->backpackShader.set("pointLights[1].ambient", lamp->getParameters().ambient);
    this->backpackShader.set("pointLights[1].diffuse", lamp->getParameters().diffuse);
    this->backpackShader.set("pointLights[1].specular", lamp->getParameters().specular);
    this->backpackShader.set("pointLights[1].constant", lamp->getParameters().constant);
    this->backpackShader.set("pointLights[1].linear", lamp->getParameters().linear);
    this->backpackShader.set("pointLights[1].quadratic", lamp->getParameters().quadratic);

    this->backpackShader.set("pointLights[2].position", lamp->instances[2]);
    this->backpackShader.set("pointLights[2].ambient", lamp->getParameters().ambient);
    this->backpackShader.set("pointLights[2].diffuse", lamp->getParameters().diffuse);
    this->backpackShader.set("pointLights[2].specular", lamp->getParameters().specular);
    this->backpackShader.set("pointLights[2].constant", lamp->getParameters().constant);
    this->backpackShader.set("pointLights[2].linear", lamp->getParameters().linear);
    this->backpackShader.set("pointLights[2].quadratic", lamp->getParameters().quadratic);

    this->backpackShader.set("pointLights[3].position", lamp->instances[3]);
    this->backpackShader.set("pointLights[3].ambient", lamp->getParameters().ambient);
    this->backpackShader.set("pointLights[3].diffuse", lamp->getParameters().diffuse);
    this->backpackShader.set("pointLights[3].specular", lamp->getParameters().specular);
    this->backpackShader.set("pointLights[3].constant", lamp->getParameters().constant);
    this->backpackShader.set("pointLights[3].linear", lamp->getParameters().linear);
    this->backpackShader.set("pointLights[3].quadratic", lamp->getParameters().quadratic);

    this->backpackShader.set("spotLight.position", this->m_Window.camera.getPosition());
    this->backpackShader.set("spotLight.direction", this->m_Window.camera.getFront());
    this->backpackShader.set("spotLight.ambient", lamp->getParameters().ambient);
    this->backpackShader.set("spotLight.diffuse", lamp->getParameters().diffuse);
    this->backpackShader.set("spotLight.specular", lamp->getParameters().specular);
    this->backpackShader.set("spotLight.constant", lamp->getParameters().constant);
    this->backpackShader.set("spotLight.linear", lamp->getParameters().linear);
    this->backpackShader.set("spotLight.quadratic", lamp->getParameters().quadratic);
    this->backpackShader.set("spotLight.cutOff", glm::cos(glm::radians(12.5F)));
    this->backpackShader.set("spotLight.outerCutOff", glm::cos(glm::radians(15.0F)));

    this->backpackShader.set("viewPos", this->m_Window.camera.getPosition());
    this->backpackShader.set("material.shininess", 32.0F);

    this->backpack.draw(this->m_Window.camera);

    this->cubeMap.draw(this->m_Window.camera);
}
