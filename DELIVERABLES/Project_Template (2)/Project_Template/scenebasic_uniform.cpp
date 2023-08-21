#include "scenebasic_uniform.h"
#include <sstream>

#include <cstdio>
#include <cstdlib>

#include <string>
using std::string;

#include <iostream>
using std::cerr;
using std::endl;

#include <glm/gtc/matrix_transform.hpp>

#include "helper/glutils.h"

using glm::vec3;

using glm::vec4;
using glm::mat3;

using glm::mat4;

//SceneBasic_Uniform::SceneBasic_Uniform() : torus(0.7f, 0.3f, /*30*/50, /*30*/50), angle(0.0f) {} 
//SceneBasic_Uniform::SceneBasic_Uniform() : teapot(50, glm::translate(mat4(1.0f), vec3(0.0f,0.0f,1.0f))) {}  //last three numbers open the teapot
//SceneBasic_Uniform::SceneBasic_Uniform() : teapot(50, glm::translate(mat4(1.0f), vec3(0.0f,0.0f,1.0f))) , torus(0.7f, 0.3f, /*30*/50, /*30*/50), angle(0.0f) {}  //last three numbers open the teapot
SceneBasic_Uniform::SceneBasic_Uniform() : teapot(50, glm::translate(mat4(1.0f), vec3(0.0f, 0.0f, 1.0f))), plane(10.0f, 10.0f, 100, 100), torus(0.7f, 0.3f, /*30*/50, /*30*/50), angle(0.0f)
{
    mesh = ObjMesh::load("../Project_Template/media/swampy.obj", true);
    mesh2 = ObjMesh::load("../Project_Template/media/flare.obj", true);

    /*mesh = ObjMesh::load("../Project_Template/media/swampy.obj", true);
    mesh = ObjMesh::load("../Project_Template/media/swampy.obj", true);
    mesh = ObjMesh::load("../Project_Template/media/swampy.obj", true);*/

}  //last three numbers open the teapot

void SceneBasic_Uniform::initScene()
{
    compile();

    //FOR TRIANGLE (LAB1)//

    //std::cout << std::endl;

    //prog.printActiveUniforms();

    ///////////////////// Create the VBO ////////////////////
    //float positionData[] = {
    //    -0.8f, -0.8f, 0.0f,
    //     0.8f, -0.8f, 0.0f,
    //     0.0f,  0.8f, 0.0f };
    //float colorData[] = {
    //    1.0f, 0.0f, 0.0f,
    //    0.0f, 1.0f, 0.0f,
    //    0.0f, 0.0f, 1.0f };

    //// Create and populate the buffer objects
    //GLuint vboHandles[2];
    //glGenBuffers(2, vboHandles);
    //GLuint positionBufferHandle = vboHandles[0];
    //GLuint colorBufferHandle = vboHandles[1];

    //glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    //glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), positionData, GL_STATIC_DRAW);

    //glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
    //glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), colorData, GL_STATIC_DRAW);

    //// Create and set-up the vertex array object
    //glGenVertexArrays( 1, &vaoHandle );
    //glBindVertexArray(vaoHandle);

    //glEnableVertexAttribArray(0);  // Vertex position
    //glEnableVertexAttribArray(1);  // Vertex color

    //#ifdef __APPLE__
    //    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    //    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL );

    //    glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
    //    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL );
    //#else
    //		glBindVertexBuffer(0, positionBufferHandle, 0, sizeof(GLfloat)*3);
    //		glBindVertexBuffer(1, colorBufferHandle, 0, sizeof(GLfloat)*3);

    //		glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
    //		glVertexAttribBinding(0, 0);
    //		glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);
    //	  glVertexAttribBinding(1, 1);
    //#endif
    //glBindVertexArray(0);

    glEnable(GL_DEPTH_TEST);
    model = mat4(1.0f);

    model = glm::rotate(model, glm::radians(-35.0f/*angle*/), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?

    view = glm::lookAt(vec3(-1.0f, 0.0f, 20.0f), vec3(0.0f, 0.0f, 0.0f),vec3(0.0f, 1.0f, 0.0f));
    //view = glm::lookAt(vec3(0.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f),vec3(0.0f, 1.0f, 0.0f)); //original position from lab2
    projection = mat4(1.0f);

    //model2 = mat4(1.0f);
    //model2 = glm::rotate(model2, glm::radians(-35.0f/*angle*/), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?
    //view2 = glm::lookAt(vec3(0.0f, 1.0f, 10.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
    ////view = glm::lookAt(vec3(0.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f),vec3(0.0f, 1.0f, 0.0f)); //original position from lab2
    //projection2 = mat4(1.0f);



    //DIFFUSE//
    //prog.setUniform("Kd", 0.2f, 0.55f, 0.9f); //can play with this more later
    //prog.setUniform("Ld", 1.0f, 1.0f, 1.0f); //can play with this more later
    //prog.setUniform("LightPosition", view * glm::vec4(5.0f, 5.0f, 2.0f, 1.0f)); //can play with this more later

    //prog.setUniform("Color", glm::vec3( 1.0f, 0.0f, 0.0f)); //struggling to pull off atm
    


    //PHONG//
    prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f); //diffuse
    prog.setUniform("Light.Ld", 1.0f, 1.0f, 1.0f); //diffuse

    prog.setUniform("Material.Ka", 0.2f, 0.55f, 0.9f); //ambient
    prog.setUniform("Light.La", 0.4f, 0.4f, 0.4f); //ambient

    prog.setUniform("Material.Ks", 0.8f, 0.8f, 0.8f); //specular
    prog.setUniform("Light.Ls", 1.0f, 1.0f, 1.0f); //specular

    prog.setUniform("LightPosition", view * glm::vec4(5.0f, 5.0f, 2.0f, 1.0f)); //can play with this more later
    prog.setUniform("Material.Shininess", 100.0f); //can play with this more later


}

void SceneBasic_Uniform::compile()
{
	try {
		prog.compileShader("shader/basic_uniform.vert");
		prog.compileShader("shader/basic_uniform.frag");
		prog.link();
		prog.use();
	} catch (GLSLProgramException &e) {
		cerr << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}

void SceneBasic_Uniform::update( float t )
{
	//update your angle here
    
    // LAB1//
    if (m_animate) {
        angle += 0.01f;

        if (angle >= 360.0f)
            angle -= 360.0f;
    }
}

void SceneBasic_Uniform::render()
{
    //glClear(GL_COLOR_BUFFER_BIT); //LAB1
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //LAB2
    
    //create the rotation matrix here and update the uniform in the shader 

    //LAB1//

    //GLuint programHandle = prog.getHandle();
    //GLuint location = glGetUniformLocation(programHandle, "RotationMatrix");

    //rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, vec3(1.0f, 0.0f, 0.0f));

    //glUniformMatrix4fv(location, 1, GL_FALSE, &rotationMatrix[0][0]); //assign a value


    //glBindVertexArray(vaoHandle);
    //glDrawArrays(GL_TRIANGLES, 0, 3 );

    //glBindVertexArray(0);
    prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f); //diffuse
    //prog.setUniform("Light.Ld", 1.0f, 1.0f, 1.0f); //diffuse

    prog.setUniform("Material.Ka", 0.2f, 0.55f, 0.9f); //ambient
    //prog.setUniform("Light.La", 0.4f, 0.4f, 0.4f); //ambient

    prog.setUniform("Material.Ks", 0.8f, 0.8f, 0.8f); //specular
    //prog.setUniform("Light.Ls", 1.0f, 1.0f, 1.0f); //specular

    //prog.setUniform("LightPosition", view * glm::vec4(5.0f, 5.0f, 2.0f, 1.0f)); //can play with this more later
    prog.setUniform("Material.Shininess", 100.0f); //can play with this more later

    model = mat4(1.0f);
    model = glm::translate(model, vec3(-3.0f, 0.75f, 3.0f));//translation is set here?
    model = glm::rotate(model, glm::radians(angle/*angle*/), vec3(1.0f, 0.0f, 1.0f));//rotation is set here?
    //model = glm::rotate(model, glm::radians(-80.0f/*angle*/), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?
    setMatrices();
    torus.render();

    //*//

    prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f); //diffuse
    //prog.setUniform("Light.Ld", 1.0f, 1.0f, 1.0f); //diffuse

    prog.setUniform("Material.Ka", 0.2f, 0.55f, 0.9f); //ambient
    //prog.setUniform("Light.La", 0.4f, 0.4f, 0.4f); //ambient

    prog.setUniform("Material.Ks", 0.8f, 0.8f, 0.8f); //specular
    //prog.setUniform("Light.Ls", 1.0f, 1.0f, 1.0f); //specular

    //prog.setUniform("LightPosition", view * glm::vec4(5.0f, 5.0f, 2.0f, 1.0f)); //can play with this more later
    prog.setUniform("Material.Shininess", 100.0f); //can play with this more later

    model = mat4(1.0f);
    model = glm::translate(model, vec3(1.0f, 0.75f, 3.0f));//translation is set here?
    model = glm::rotate(model, glm::radians(-angle/*angle*/), vec3(1.0f, 1.0f, 1.0f));//rotation is set here?
    //model = glm::rotate(model, glm::radians(-80.0f/*angle*/), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?

    //view = glm::lookAt(vec3(0.0f, 0.0f, 10.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
    //view = glm::lookAt(vec3(0.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f),vec3(0.0f, 1.0f, 0.0f)); //original position from lab2
    //projection = mat4(1.0f);
    setMatrices(); 
    teapot.render();

    //*//

    prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f); //diffuse
    //prog.setUniform("Light.Ld", 1.0f, 1.0f, 1.0f); //diffuse

    prog.setUniform("Material.Ka", 0.2f, 0.55f, 0.9f); //ambient
    //prog.setUniform("Light.La", 0.4f, 0.4f, 0.4f); //ambient

    prog.setUniform("Material.Ks", 0.8f, 0.8f, 0.8f); //specular
    //prog.setUniform("Light.Ls", 1.0f, 1.0f, 1.0f); //specular

    //prog.setUniform("LightPosition", view * glm::vec4(5.0f, 5.0f, 2.0f, 1.0f)); //can play with this more later
    prog.setUniform("Material.Shininess", 100.0f); //can play with this more later

    model = mat4(1.0f);
    model = glm::translate(model, vec3(0.0f, 0.0f, 1.0f));//translation is set here?
    model = glm::rotate(model, glm::radians(35.0f), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?
    //model = glm::rotate(model, glm::radians(-80.0f/*angle*/), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?

    //view = glm::lookAt(vec3(0.0f, 0.0f, 10.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
    //view = glm::lookAt(vec3(0.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f),vec3(0.0f, 1.0f, 0.0f)); //original position from lab2
    //projection = mat4(1.0f);
    setMatrices();
    plane.render();

    //*//

    prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f); //diffuse
    //prog.setUniform("Light.Ld", 1.0f, 1.0f, 1.0f); //diffuse

    prog.setUniform("Material.Ka", 0.2f, 0.55f, 0.9f); //ambient
    //prog.setUniform("Light.La", 0.4f, 0.4f, 0.4f); //ambient

    prog.setUniform("Material.Ks", 0.8f, 0.8f, 0.8f); //specular
    //prog.setUniform("Light.Ls", 1.0f, 1.0f, 1.0f); //specular

    //prog.setUniform("LightPosition", view * glm::vec4(5.0f, 5.0f, 2.0f, 1.0f)); //can play with this more later
    prog.setUniform("Material.Shininess", 100.0f); //can play with this more later

    model = mat4(1.0f);
    model = glm::translate(model, vec3(0.0f, 0.0f, 1.0f));//translation is set here?
    model = glm::rotate(model, glm::radians(-90.0f), vec3(0.0f, 1.0f, 0.0f));//rotation is set here?
    setMatrices();
    mesh->render();

    //*flare*//

    prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f); //diffuse
    //prog.setUniform("Light.Ld", 1.0f, 1.0f, 1.0f); //diffuse

    prog.setUniform("Material.Ka", 0.2f, 0.55f, 0.9f); //ambient
    //prog.setUniform("Light.La", 0.4f, 0.4f, 0.4f); //ambient

    prog.setUniform("Material.Ks", 0.8f, 0.8f, 0.8f); //specular
    //prog.setUniform("Light.Ls", 1.0f, 1.0f, 1.0f); //specular

    //prog.setUniform("LightPosition", view * glm::vec4(5.0f, 5.0f, 2.0f, 1.0f)); //can play with this more later
    prog.setUniform("Material.Shininess", 100.0f); //can play with this more later

    model = mat4(1.0f);
    model = glm::translate(model, vec3(-6.0f, 0.0f, 1.0f));//translation is set here?
    model = glm::rotate(model, glm::radians(-90.0f), vec3(0.0f, 1.0f, 0.0f));//rotation is set here?
    setMatrices();
    mesh2->render();
}

void SceneBasic_Uniform::resize(int w, int h)
{
    //LAB1//
    /*width = w;
    height = h;
    glViewport(0,0,w,h);*/

    //LAB2//
    glViewport(0, 0, w, h);
    width = w;
    height = h;
    projection = glm::perspective(glm::radians(70.0f), (float)w / h, 0.3f, 100.0f);

}

void SceneBasic_Uniform::setMatrices()
{
    mat4 mv = view * model;
    prog.setUniform("ModelViewMatrix", mv);
    prog.setUniform("NormalMatrix", glm::mat3(vec3(mv[0]), vec3(mv[1]), vec3(mv[2])));    
    prog.setUniform("MVP", projection * mv);
    
    //mat4 mv2 = view2 * model2;
    //prog.setUniform("ModelViewMatrix", mv2);
    //prog.setUniform("NormalMatrix", glm::mat3(vec3(mv2[0]), vec3(mv2[1]), vec3(mv2[2])));    
    //prog.setUniform("MVP", projection2 * mv2);

}

//add a method that rotates the model
