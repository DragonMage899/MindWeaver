#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <string>
#include <vector>
#include <iostream>

#include <GL/glew.h>
#include <glm/glm.hpp> // OpenGL Mathematics library
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#define STB_IMAGE_IMPLEMENTATION 
#include "stb_image.h"

// If your Vector.h doesn't have Vector<2>, you can use glm::vec2 or define a simple struct
// For simplicity, this example will use glm::vec3 for positions/normals and glm::vec2 for texCoords.
// Make sure your Matrix.h and Vector.h are compatible or adapt accordingly.
// This example assumes you'll use GLM for matrix/vector operations within ObjLoader
// for compatibility with typical OpenGL workflows.
// If you must use your custom Matrix/Vector classes, you'll need to:
// 1. Ensure Vector<2> exists or create it.
// 2. Ensure Matrix<4,4> has all necessary operations (multiplication, identity, translation, rotation, scaling).
// 3. Replace glm types and functions with your custom ones.

// Forward declaration for stb_image
unsigned char* stbi_load(char const *filename, int *x, int *y, int *comp, int desired_channels);
void stbi_image_free(void *retval_from_stbi_load);


struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    // You can add Tangent and Bitangent here if you plan to use normal mapping
    // glm::vec3 Tangent;
    // glm::vec3 Bitangent;
};

struct Texture {
    unsigned int id;
    std::string type; // e.g., "texture_diffuse", "texture_specular"
    std::string path; // Store path of texture to compare with other textures
};

class Mesh {
public:
    // Mesh Data
    std::vector<Vertex>       vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture>      textures; // All textures associated with this mesh
    glm::vec4 diffuseColor; // Default diffuse color if no texture or from material

    // OpenGL Buffers
    unsigned int VAO, VBO, EBO;

    // Constructor
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::vector<Texture>& textures, const glm::vec4& diffuseColor);
    
    // Render the mesh
    void Draw(GLuint shaderProgramID);

private:
    // Initializes all the buffer objects/arrays
    void setupMesh();
};

class ObjLoader {
public:
    // Model data
    std::vector<Mesh> meshes;
    std::string directory; // Useful for loading textures relative to the .obj file
    bool gammaCorrection;

    // Transformation
    glm::mat4 transform; // Object's local transformation matrix

    // Rendering
    GLuint shaderProgramID; // Shader program to use for drawing this object
    glm::vec4 drawColor;    // A general color for the object, can be used as tint or fallback
    bool useObjectColorInsteadOfTexture; // Flag to switch between texture and objectColor

    // Constructor
    ObjLoader(GLuint shaderID, bool gamma = false);

    // Destructor
    ~ObjLoader();

    // Loads a model with supported ASSIMP extensions from file and stores the resulting meshes in `meshes`
    bool loadModel(const std::string& path);

    // Draws all meshes in the model
    void Draw();

    // Transformation methods
    void translate(const glm::vec3& trans);
    void rotate(float angleRadians, const glm::vec3& axis);
    void scale(const glm::vec3& scaleFactors);
    void resetTransform(); // Resets transform to identity

    // Setters
    void setDrawColor(float r, float g, float b, float a);
    void setUseObjectColor(bool useColor);


private:
    // Processes a node in Assimp's scene graph recursively
    void processNode(aiNode *node, const aiScene *scene);
    
    // Processes an aiMesh object and converts it into our Mesh format
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    
    // Checks all material textures of a given type and loads the textures if they're not loaded yet.
    // The required info is returned as a Texture struct.
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, const std::string& typeName);
    
    // Static utility function to load a texture from file
    static unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma);

    // Helper to convert aiColor4D to glm::vec4
    static glm::vec4 AiColorToGlmVec4(const aiColor4D& color);
};

#endif // OBJLOADER_H

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::vector<Texture>& textures, const glm::vec4& diffuseColor) {
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;
    this->diffuseColor = diffuseColor;

    setupMesh();
}

void Mesh::setupMesh() {
    // Create buffers/arrays
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    // Load data into vertex buffers
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    // Set the vertex attribute pointers
    // Vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // Vertex Normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    // Vertex Texture Coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
    // // Vertex Tangent (if using)
    // glEnableVertexAttribArray(3);
    // glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
    // // Vertex Bitangent (if using)
    // glEnableVertexAttribArray(4);
    // glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));

    glBindVertexArray(0); // Unbind VAO
}

void Mesh::Draw(GLuint shaderProgramID) {
    // Bind appropriate textures
    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    unsigned int normalNr = 1;
    unsigned int heightNr = 1;

    bool hasDiffuseTexture = false;

    for (unsigned int i = 0; i < textures.size(); i++) {
        glActiveTexture(GL_TEXTURE0 + i); // Active proper texture unit before binding
        // Retrieve texture number (the N in diffuse_textureN)
        std::string number;
        std::string name = textures[i].type;
        if (name == "texture_diffuse") {
            number = std::to_string(diffuseNr++);
            hasDiffuseTexture = true;
        } else if (name == "texture_specular")
            number = std::to_string(specularNr++); // Transfer unsigned int to stream
        else if (name == "texture_normal")
            number = std::to_string(normalNr++); // Transfer unsigned int to stream
         else if (name == "texture_height")
            number = std::to_string(heightNr++); // Transfer unsigned int to stream

        // Now set the sampler to the correct texture unit
        glUniform1i(glGetUniformLocation(shaderProgramID, (name + number).c_str()), i);
        // And finally bind the texture
        glBindTexture(GL_TEXTURE_2D, textures[i].id);
    }
    
    // Set object color and useTexture flag
    GLint objectColorLoc = glGetUniformLocation(shaderProgramID, "objectColor");
    GLint useTextureLoc = glGetUniformLocation(shaderProgramID, "useTexture");

    if (objectColorLoc != -1) {
        glUniform4fv(objectColorLoc, 1, &diffuseColor[0]);
    }
    if (useTextureLoc != -1) {
        glUniform1i(useTextureLoc, hasDiffuseTexture && !textures.empty());
    }


    // Draw mesh
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    // Always good practice to set everything back to defaults once configured.
    glActiveTexture(GL_TEXTURE0);
}


// --- ObjLoader Class Implementation ---

ObjLoader::ObjLoader(GLuint shaderID, bool gamma) : shaderProgramID(shaderID), gammaCorrection(gamma) {
    transform = glm::mat4(1.0f); // Initialize to identity matrix
    drawColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f); // Default to white
    useObjectColorInsteadOfTexture = false;
}

ObjLoader::~ObjLoader() {
    // OpenGL resources (VAO, VBO, EBO, textures) for each mesh
    // are typically managed by the Mesh objects themselves if they were dynamically allocated.
    // If Mesh objects are directly in std::vector<Mesh> meshes, their destructors will be called.
    // Textures loaded via TextureFromFile might need explicit deletion if not handled elsewhere.
    // For this example, Mesh's VAO/VBO/EBO are cleaned up if Mesh had a destructor.
    // Textures loaded by TextureFromFile are OpenGL objects; their cleanup would involve glDeleteTextures.
    // This example assumes textures are cleaned up when the OpenGL context is destroyed,
    // or you can add explicit cleanup in Mesh destructor or ObjLoader destructor.
    for (Mesh& mesh : meshes) {
        glDeleteVertexArrays(1, &mesh.VAO);
        glDeleteBuffers(1, &mesh.VBO);
        glDeleteBuffers(1, &mesh.EBO);
        for (Texture& tex : mesh.textures) {
            glDeleteTextures(1, &tex.id);
        }
    }
}


bool ObjLoader::loadModel(const std::string& path) {
    Assimp::Importer importer;
    // aiProcess_Triangulate: ensure all faces are triangles
    // aiProcess_FlipUVs: flips texture coordinates vertically (often needed for OpenGL)
    // aiProcess_GenNormals: creates normals if they are missing
    // aiProcess_CalcTangentSpace: creates tangents and bitangents (for normal mapping)
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals | aiProcess_CalcTangentSpace);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cerr << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
        return false;
    }
    directory = path.substr(0, path.find_last_of('/'));
    if (directory == path) { // Handle case where path has no '/'
        directory = ".";
    }


    processNode(scene->mRootNode, scene);
    return true;
}

void ObjLoader::processNode(aiNode *node, const aiScene *scene) {
    // Process all the node's meshes (if any)
    for (unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }
    // Then do the same for each of its children
    for (unsigned int i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
}

Mesh ObjLoader::processMesh(aiMesh *mesh, const aiScene *scene) {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;
    glm::vec4 meshDiffuseColor(0.8f, 0.8f, 0.8f, 1.0f); // Default mesh color

    // Process vertices
    for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex;
        glm::vec3 vector;
        // Positions
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.Position = vector;
        // Normals
        if (mesh->HasNormals()) {
            vector.x = mesh->mNormals[i].x;
            vector.y = mesh->mNormals[i].y;
            vector.z = mesh->mNormals[i].z;
            vertex.Normal = vector;
        }
        // Texture Coordinates
        if (mesh->mTextureCoords[0]) { // Does the mesh contain texture coordinates?
            glm::vec2 vec;
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex.TexCoords = vec;
            // // Tangent (if using)
            // vector.x = mesh->mTangents[i].x;
            // vector.y = mesh->mTangents[i].y;
            // vector.z = mesh->mTangents[i].z;
            // vertex.Tangent = vector;
            // // Bitangent (if using)
            // vector.x = mesh->mBitangents[i].x;
            // vector.y = mesh->mBitangents[i].y;
            // vector.z = mesh->mBitangents[i].z;
            // vertex.Bitangent = vector;
        } else {
            vertex.TexCoords = glm::vec2(0.0f, 0.0f);
        }
        vertices.push_back(vertex);
    }

    // Process indices
    for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }

    // Process material
    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
    
    // 1. Diffuse maps
    std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
    // 2. Specular maps
    std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    // 3. Normal maps
    std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal"); // Assimp often loads normal maps as height maps
    textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
    // 4. Height maps
    std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height"); // Or ambient as height
    textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

    // Get diffuse color from material if no diffuse texture
    aiColor4D diffuse;
    if (AI_SUCCESS == aiGetMaterialColor(material, AI_MATKEY_COLOR_DIFFUSE, &diffuse)) {
        meshDiffuseColor = AiColorToGlmVec4(diffuse);
    }
     // If the object has a name like "Cube" from Blender, you can retrieve it
    // std::string meshName = mesh->mName.C_Str();
    // std::cout << "Processing mesh: " << meshName << " with material index: " << mesh->mMaterialIndex << std::endl;
    // if (textures.empty()) {
    //     std::cout << "Mesh " << meshName << " has no textures, using diffuse color: ("
    //               << meshDiffuseColor.r << ", " << meshDiffuseColor.g << ", "
    //               << meshDiffuseColor.b << ", " << meshDiffuseColor.a << ")" << std::endl;
    // }


    return Mesh(vertices, indices, textures, meshDiffuseColor);
}

std::vector<Texture> ObjLoader::loadMaterialTextures(aiMaterial *mat, aiTextureType type, const std::string& typeName) {
    std::vector<Texture> textures;
    std::vector<Texture> loaded_textures_cache; // Cache to avoid loading same texture multiple times

    for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
        aiString str;
        mat->GetTexture(type, i, &str);
        bool skip = false;
        for (unsigned int j = 0; j < loaded_textures_cache.size(); j++) {
            if (std::strcmp(loaded_textures_cache[j].path.data(), str.C_Str()) == 0) {
                textures.push_back(loaded_textures_cache[j]);
                skip = true;
                break;
            }
        }
        if (!skip) { // If texture hasn't been loaded already, load it
            Texture texture;
            texture.id = TextureFromFile(str.C_Str(), this->directory, gammaCorrection);
            texture.type = typeName;
            texture.path = str.C_Str();
            textures.push_back(texture);
            loaded_textures_cache.push_back(texture); // Add to loaded textures
        }
    }
    return textures;
}

unsigned int ObjLoader::TextureFromFile(const char *path, const std::string &directory, bool gamma) {
    std::string filename = std::string(path);
    // If the path is absolute, use it directly. Otherwise, prepend the directory.
    // This basic check might need to be more robust for different OS/path styles.
    if (filename.find(':') == std::string::npos && filename[0] != '/' && filename[0] != '\\') {
         filename = directory + '/' + filename;
    }


    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    // stbi_set_flip_vertically_on_load(true); // Tell stb_image.h to flip loaded texture's on the y-axis. (Assimp's aiProcess_FlipUVs might already do this)
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;
        else { // Should not happen for typical image formats
            std::cerr << "Texture loaded with unexpected number of components: " << nrComponents << " for " << filename << std::endl;
            stbi_image_free(data);
            glDeleteTextures(1, &textureID); // Clean up allocated texture ID
            return 0; // Return 0 to indicate failure
        }


        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    } else {
        std::cerr << "Texture failed to load at path: " << filename << std::endl;
        std::cerr << "stb_image error: " << stbi_failure_reason() << std::endl;
        glDeleteTextures(1, &textureID); // Clean up allocated texture ID
        return 0; // Return 0 to indicate failure
    }

    return textureID;
}

glm::vec4 ObjLoader::AiColorToGlmVec4(const aiColor4D& color) {
    return glm::vec4(color.r, color.g, color.b, color.a);
}


void ObjLoader::Draw() {
    glUseProgram(this->shaderProgramID);

    // Set model matrix uniform
    GLint modelLoc = glGetUniformLocation(this->shaderProgramID, "model");
    if (modelLoc != -1) {
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(this->transform));
    } else {
        // std::cerr << "Warning: Uniform 'model' not found in shader program " << this->shaderProgramID << std::endl;
    }
    
    // Set overall object color and texture usage flag (can be overridden by mesh-specific settings in Mesh::Draw)
    GLint objectColorLoc = glGetUniformLocation(shaderProgramID, "objectColor");
    GLint useTextureLoc = glGetUniformLocation(shaderProgramID, "useTexture");

    if (objectColorLoc != -1) {
        glUniform4fv(objectColorLoc, 1, &drawColor[0]);
    }
    if (useTextureLoc != -1) {
        // This logic might need refinement. If useObjectColorInsteadOfTexture is true,
        // we want to tell the shader not to use textures from the mesh.
        // However, Mesh::Draw also sets useTexture based on whether it has diffuse textures.
        // For simplicity now, ObjLoader's flag will try to control this.
        // A more robust way would be for Mesh::Draw to take this flag as a parameter.
        glUniform1i(useTextureLoc, !useObjectColorInsteadOfTexture);
    }


    for (unsigned int i = 0; i < meshes.size(); i++) {
        // If ObjLoader has a specific color set and wants to use it instead of texture,
        // we can pass that down or modify how Mesh::Draw behaves.
        // For now, Mesh::Draw will try to use its own textures/material colors.
        // If you want ObjLoader::drawColor to override everything:
        if (useObjectColorInsteadOfTexture && objectColorLoc != -1) {
             glUniform4fv(objectColorLoc, 1, &drawColor[0]);
        }
        if (useObjectColorInsteadOfTexture && useTextureLoc != -1) {
            glUniform1i(useTextureLoc, false); // Force shader to use objectColor
        }

        meshes[i].Draw(this->shaderProgramID);
    }
}

void ObjLoader::translate(const glm::vec3& trans) {
    this->transform = glm::translate(this->transform, trans);
}

void ObjLoader::rotate(float angleRadians, const glm::vec3& axis) {
    this->transform = glm::rotate(this->transform, angleRadians, axis);
}

void ObjLoader::scale(const glm::vec3& scaleFactors) {
    this->transform = glm::scale(this->transform, scaleFactors);
}

void ObjLoader::resetTransform() {
    this->transform = glm::mat4(1.0f);
}

void ObjLoader::setDrawColor(float r, float g, float b, float a) {
    this->drawColor = glm::vec4(r, g, b, a);
}
void ObjLoader::setUseObjectColor(bool useColor) {
    this->useObjectColorInsteadOfTexture = useColor;
}
