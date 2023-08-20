#ifndef SCENEBASIC_UNIFORM_H
#define SCENEBASIC_UNIFORM_H

#include "helper/scene.h"

#include <glad/glad.h>
#include "helper/glslprogram.h"
//lab1
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//lab2
#include "helper/torus.h"


class SceneBasic_Uniform : public Scene
{
private:
    //GLuint vaoHandle; //Lab1 for triangle
    GLSLProgram prog;
    Torus torus; //Lab2
    float angle; //Lab1 for spinning

    glm::mat4 rotationMatrix; //check later for errors

    void compile();

public:
    SceneBasic_Uniform();

    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
    void setMatrices();
};

#endif // SCENEBASIC_UNIFORM_H
