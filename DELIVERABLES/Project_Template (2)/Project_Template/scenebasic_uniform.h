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
//lab3
#include "helper/teapot.h"
#include "helper/plane.h"
#include "helper/objmesh.h"
//#include "helper/swampy.obj"


class SceneBasic_Uniform : public Scene
{
private:
    //GLuint vaoHandle; //Lab1 for triangle
    GLSLProgram prog;
    //GLSLProgram prog2?;
    Torus torus; //Lab2
    Teapot teapot;
    float angle; //Lab1 for spinning

    Plane plane; //plane.
    std::unique_ptr<ObjMesh> mesh; //for swampy?
    std::unique_ptr<ObjMesh> mesh2; //for flare?

    //std::unique_ptr<ObjMesh> mesh3; //for grassland?
    //std::unique_ptr<ObjMesh> mesh4; //for trees?
    //std::unique_ptr<ObjMesh> mesh5; //for shanopi?

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
