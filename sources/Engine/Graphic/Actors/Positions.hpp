/*
** Akanya, Engine
** sources/Engine/Graphic/Actors/Positions
** A vector of position that allow multiple draw from the same object
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_POSITIONS_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_POSITIONS_HPP___

#include "Tools/FuncAlias.hpp"
#include "Tools/Iterator.hpp"

namespace engine::graphic::actor {



class Positions : public tool::Iterator<glm::vec3> {
public:
    // ---------------------------------- *structors
    Positions(size_t sizeToAlloc);
    ~Positions();


    // ---------------------------------- Access
    glm::vec3&       operator[](size_t index);
    const glm::vec3& operator[](size_t index) const;

    glm::vec3*       operator->();
    const glm::vec3* operator->() const;


    // ---------------------------------- Iterator
    engine::graphic::actor::Positions::iterator       begin() override;
    engine::graphic::actor::Positions::const_iterator begin() const override;
    engine::graphic::actor::Positions::const_iterator cbegin() const override;

    engine::graphic::actor::Positions::iterator       end() override;
    engine::graphic::actor::Positions::const_iterator end() const override;
    engine::graphic::actor::Positions::const_iterator cend() const override;


    // ---------------------------------- AddPosition
    // Note: Perform an implicit conversion into an std::vector<glm::vec3> if needed
    void addPosition(float x, float y, float z);
    void addPosition(const glm::vec3& position);
    void addPosition(glm::vec3&& position);

    FUNC_ALIAS(add, addPosition)


    // ---------------------------------- SetPosition
    void setPosition(const glm::vec3& position);
    void setPosition(glm::vec3&& position);
    void setPosition(float positionX, float positionY, float positionZ);

    void setPositionX(float positionX);
    void setPositionY(float positionY);
    void setPositionZ(float positionZ);

    FUNC_ALIAS(operator=, setPosition)
    FUNC_ALIAS(set, setPosition)
    FUNC_ALIAS(setX, setPositionX)
    FUNC_ALIAS(setY, setPositionY)
    FUNC_ALIAS(setZ, setPositionZ)


    // ---------------------------------- Move
    void move(const glm::vec3& offset);
    void move(float offsetX, float offsetY, float offsetZ);

    void moveX(float offsetX);
    void moveY(float offsetY);
    void moveZ(float offsetZ);

    FUNC_ALIAS(operator+=, move)


    // ---------------------------------- Size
    size_t size() const;

private:
    using SinglePosition    = glm::vec3;
    using MultiplePositions = std::vector<SinglePosition>;

    std::variant<SinglePosition, MultiplePositions> m_variant;
};



} // namespace engine::graphic::actor



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_POSITIONS_HPP___
