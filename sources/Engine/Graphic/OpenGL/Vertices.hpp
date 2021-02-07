//
// Akanya, Engine
// sources/Engine/Graphic/OpenGL/Vertices
// Extract vertices from files and alloc buffers to binded ones
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_VERTEXES_VERTICES_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_VERTEXES_VERTICES_HPP___



namespace engine::graphic::opengl {



class Vertices {
public:
    // ---------------------------------- *structors
    explicit Vertices(const std::string& filepath, size_t& numberOfArrayToDraw);


    // ---------------------------------- buffer

    void createBuffer();


private:
    std::vector<float> m_vertices;
};



} // namespace engine::graphic::opengl



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_VERTEXES_VERTICES_HPP___
