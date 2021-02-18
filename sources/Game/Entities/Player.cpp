//
// Akanya
// sources/Game/Entities/Player
// Desribes a palyer
//

#include "pch.hpp"
#include "Player.hpp"



// ---------------------------------- *structors

::game::entity::Player::Player(
    const std::string& shaderFilepath
)
    : engine::graphic::actor::basicShape::Cube(shaderFilepath)
{
    this->useShader();

    this->addTexture("container.png", "material.diffuse");
    this->addTexture("containerBorders.png", "material.specular");

    this->setIntoShader("spotLight.cutOff", glm::cos(glm::radians(12.5F)));
    this->setIntoShader("spotLight.outerCutOff", glm::cos(glm::radians(15.0F)));
    this->setIntoShader("material.shininess", 8.0F);
}

::game::entity::Player::~Player() = default;



// ---------------------------------- override

void ::game::entity::Player::configureShader() const
{}
