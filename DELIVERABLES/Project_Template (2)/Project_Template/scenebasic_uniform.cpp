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
#include "GLFW/glfw3.h" //for keyboard controls

using glm::vec3;

using glm::vec4;
using glm::mat3;

using glm::mat4;


//SceneBasic_Uniform::SceneBasic_Uniform() : torus(0.7f, 0.3f, /*30*/50, /*30*/50), angle(0.0f) {} 
//SceneBasic_Uniform::SceneBasic_Uniform() : teapot(50, glm::translate(mat4(1.0f), vec3(0.0f,0.0f,1.0f))) {}  //last three numbers open the teapot
//SceneBasic_Uniform::SceneBasic_Uniform() : teapot(50, glm::translate(mat4(1.0f), vec3(0.0f,0.0f,1.0f))) , torus(0.7f, 0.3f, /*30*/50, /*30*/50), angle(0.0f) {}  //last three numbers open the teapot
SceneBasic_Uniform::SceneBasic_Uniform() : plane(50.0f, 50.0f, 100, 100), angle(0.0f), tPrev(0.0f), lightPos(5.0f, 5.0f, 5.0f, 1.0f)
{
    mesh = ObjMesh::load("../Project_Template/media/swampy.obj", true);
    mesh2 = ObjMesh::load("../Project_Template/media/flare.obj", true);

    mesh3 = ObjMesh::load("../Project_Template/media/grassland.obj", true); //for textures
    mesh4 = ObjMesh::load("../Project_Template/media/trees.obj", true); //for controls or splatter
    mesh5 = ObjMesh::load("../Project_Template/media/shanopi.obj", true); //for fog

    //spot = ObjMesh::load("media/spot/spot_triangulated.obj");

}  //last three numbers open the teapot

void SceneBasic_Uniform::initScene()
{
    angle = 0.0f;
    tAngle = 0.0f;
    rotateModifier = 0.0f;
    compile();

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

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


    ////CURRENT OLD VERSION INIT
    ////glEnable(GL_DEPTH_TEST);
    ////model = mat4(1.0f);

    ////model = glm::rotate(model, glm::radians(-35.0f/*angle*/), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?

    ////view = glm::lookAt(vec3(-1.0f, 0.0f, 20.0f), vec3(0.0f, 0.0f, 0.0f),vec3(0.0f, 1.0f, 0.0f));
    //////view = glm::lookAt(vec3(0.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f),vec3(0.0f, 1.0f, 0.0f)); //original position from lab2
    ////projection = mat4(1.0f);

    ////model2 = mat4(1.0f);
    ////model2 = glm::rotate(model2, glm::radians(-35.0f/*angle*/), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?
    ////view2 = glm::lookAt(vec3(0.0f, 1.0f, 10.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
    //////view = glm::lookAt(vec3(0.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f),vec3(0.0f, 1.0f, 0.0f)); //original position from lab2
    ////projection2 = mat4(1.0f);



    //DIFFUSE//
    //prog.setUniform("Kd", 0.2f, 0.55f, 0.9f); //can play with this more later
    //prog.setUniform("Ld", 1.0f, 1.0f, 1.0f); //can play with this more later
    //prog.setUniform("LightPosition", view * glm::vec4(5.0f, 5.0f, 2.0f, 1.0f)); //can play with this more later

    //prog.setUniform("Color", glm::vec3( 1.0f, 0.0f, 0.0f)); //struggling to pull off atm


    //////PHONG//
    ////prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f); //diffuse
    ////prog.setUniform("Light.Ld", 1.0f, 1.0f, 1.0f); //diffuse

    ////prog.setUniform("Material.Ka", 0.2f, 0.55f, 0.9f); //ambient
    ////prog.setUniform("Light.La", 0.4f, 0.4f, 0.4f); //ambient

    ////prog.setUniform("Material.Ks", 0.8f, 0.8f, 0.8f); //specular
    ////prog.setUniform("Light.Ls", 1.0f, 1.0f, 1.0f); //specular

    ////prog.setUniform("LightPosition", view * glm::vec4(5.0f, 5.0f, 2.0f, 1.0f)); //can play with this more later
    ////prog.setUniform("Material.Shininess", 100.0f); //can play with this more later

    glEnable(GL_DEPTH_TEST);
    //model = mat4(1.0f);

    //model = glm::rotate(model, glm::radians(-35.0f/*angle*/), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?

    view = glm::lookAt(vec3(-1.0f, 0.0f, 22.0f), vec3(0.0f, angle, 0.0f), vec3(0.0f, 1.0f, 0.0f));
    projection = /*mat4(1.0f);*/ glm::perspective(glm::radians(50.0f), (float)width / height, 0.5f, 100.0f);

    angle = 90.0f;
    rotationSpeed = 0.05f;

    prog.setUniform("Spot.Ld", vec3(0.9f));
    prog.setUniform("Spot.Ls", vec3(0.9f));
    prog.setUniform("Spot.La", vec3(0.5f));
    prog.setUniform("Spot.Exponent",50.0f);
    prog.setUniform("Spot.Cutoff", glm::radians(15.0f));    

    prog.setUniform("Light[0].L", glm::vec3(45.0f));
    prog.setUniform("Light[0].Position", view*lightPos);
    prog.setUniform("Light[1].L", glm::vec3(0.3f));
    prog.setUniform("Light[1].Position", glm::vec4(0,0.14f,-1.0f,0));
    prog.setUniform("Light[2].L", glm::vec3(45.0f));
    prog.setUniform("Light[2].Position", view * glm::vec4(-7,3,7,1));

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
    t = rotateModifier;
    // LAB1//
    if (m_animate) {
        angle += 0.001f + rotateModifier;

        if (angle >= 360.0f)
            angle -= 360.0f;
    }

    float deltaT = t - tPrev;
    if (tPrev == 0.0f)
    {
        deltaT = 0.0f;
        tPrev = t;
        tAngle += 0.25f * deltaT;
        if (tAngle > glm::two_pi<float>())
        {
            tAngle -= glm::two_pi<float>();
        }
    }
    if (animating()) {
        //angle = glm::mod(angle + deltaT * rotationSpeed, glm::two_pi<float>());
        lightPos.x = glm::cos(angle) * 7.0f;
        lightPos.y = 3.0f;
        lightPos.z = glm::sin(angle) * 7.0f;
    }

}

void SceneBasic_Uniform::drawScene()
{
    drawFloor();
    glm::vec3 testColour(0.1f, 0.33f, 0.9f);
    drawSpot(glm::vec3(0, 0, 0), 2.0f, 0, testColour);

    float metalRough = 0.4f;

    drawSpot(glm::vec3(1.0f, 0.0f, 1.0f), metalRough, 1, glm::vec3(0.5f, 0.6f, 0.3f));
}

void SceneBasic_Uniform::drawFloor()
{
    model = glm::mat4(1.0f);
    prog.setUniform("Material.Rough", 0.9f);
    prog.setUniform("Material.Metal", 0);
    prog.setUniform("Material.Colour", glm::vec3(0.2f));
    model = glm::translate(model, glm::vec3(0.0f, -0.7f, 0.0f));
    setMatrices();
    //plane.render();

}

void SceneBasic_Uniform::drawSpot(const glm::vec3& pos, float rough, int metal, const glm::vec3& colour)
{
    model = mat4(1.0f);
    prog.setUniform("Material.Rough", rough);
    prog.setUniform("Material.Metal", metal);
    prog.setUniform("Material.Colour", colour);
    model = glm::translate(model, pos);
    model = glm::rotate(model, glm::radians(180.0f), vec3(0.0f, -0.7f, 0.0f));
    setMatrices();
    //spot->render();

}

void SceneBasic_Uniform::render()
{
    //glClear(GL_COLOR_BUFFER_BIT); //LAB1
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //LAB2
    
    prog.setUniform("Light[0].Position", view * lightPos);
    drawScene();

    //create the rotation matrix here and update the uniform in the shader 

    //LAB1//

    //GLuint programHandle = prog.getHandle();
    //GLuint location = glGetUniformLocation(programHandle, "RotationMatrix");

    //rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, vec3(1.0f, 0.0f, 0.0f));

    //glUniformMatrix4fv(location, 1, GL_FALSE, &rotationMatrix[0][0]); //assign a value


    //glBindVertexArray(vaoHandle);
    //glDrawArrays(GL_TRIANGLES, 0, 3 );

    //vec4 lightPos = vec4(0.0f, 40.0f, 0.0f, 0.75f);   //*new code*//
    vec4 lightPos = vec4(0, 40.0f, 10.0f * sin(tAngle), 1.0f - (sin(angle*0.05)*0.4));   //moving light for toon shading
    //light.position?
    prog.setUniform("Spot.Position", vec4(view * lightPos)); //point of origin
    mat3 normalMatrix = mat3(vec3(view[0]), vec3(view[1]), vec3(view[2]));
    prog.setUniform("Spot.Direction", normalMatrix * vec3(-lightPos)); //direction of the spotlight
    

    ////glBindVertexArray(0);
    //prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f); //diffuse
    ////prog.setUniform("Light.Ld", 1.0f, 1.0f, 1.0f); //diffuse

    //prog.setUniform("Material.Ka", 0.2f, 0.55f, 0.9f); //ambient
    ////prog.setUniform("Light.La", 0.4f, 0.4f, 0.4f); //ambient

    //prog.setUniform("Material.Ks", 0.8f, 0.8f, 0.8f); //specular
    ////prog.setUniform("Light.Ls", 1.0f, 1.0f, 1.0f); //specular

    ////prog.setUniform("LightPosition", view * glm::vec4(5.0f, 5.0f, 2.0f, 1.0f)); //can play with this more later
    //prog.setUniform("Material.Shininess", 100.0f); //can play with this more later

    //model = mat4(1.0f);
    //model = glm::translate(model, vec3(-3.0f, 0.75f, 3.0f));//translation is set here?
    //model = glm::rotate(model, glm::radians(angle/*angle*/), vec3(1.0f, 0.0f, 1.0f));//rotation is set here?
    ////model = glm::rotate(model, glm::radians(-80.0f/*angle*/), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?
    //setMatrices();
    ////torus.render();

    ////*//

    //prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f); //diffuse
    ////prog.setUniform("Light.Ld", 1.0f, 1.0f, 1.0f); //diffuse

    //prog.setUniform("Material.Ka", 0.2f, 0.55f, 0.9f); //ambient
    ////prog.setUniform("Light.La", 0.4f, 0.4f, 0.4f); //ambient

    //prog.setUniform("Material.Ks", 0.8f, 0.8f, 0.8f); //specular
    ////prog.setUniform("Light.Ls", 1.0f, 1.0f, 1.0f); //specular

    ////prog.setUniform("LightPosition", view * glm::vec4(5.0f, 5.0f, 2.0f, 1.0f)); //can play with this more later
    //prog.setUniform("Material.Shininess", 100.0f); //can play with this more later

    //model = mat4(1.0f);
    //model = glm::translate(model, vec3(1.0f, 0.75f, 3.0f));//translation is set here?
    //model = glm::rotate(model, glm::radians(-angle/*angle*/), vec3(1.0f, 1.0f, 1.0f));//rotation is set here?
    ////model = glm::rotate(model, glm::radians(-80.0f/*angle*/), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?

    ////view = glm::lookAt(vec3(0.0f, 0.0f, 10.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
    ////view = glm::lookAt(vec3(0.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f),vec3(0.0f, 1.0f, 0.0f)); //original position from lab2
    ////projection = mat4(1.0f);
    //setMatrices(); 
    ////teapot.render();

    ////*//

    prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f); //diffuse
    //prog.setUniform("Light.Ld", 1.0f, 1.0f, 1.0f); //diffuse

    prog.setUniform("Material.Ka", 0.2f, 0.55f, 0.9f); //ambient
    //prog.setUniform("Light.La", 0.4f, 0.4f, 0.4f); //ambient

    prog.setUniform("Material.Ks", 0.8f, 0.8f, 0.8f); //specular
    //prog.setUniform("Light.Ls", 1.0f, 1.0f, 1.0f); //specular

    //prog.setUniform("LightPosition", view * glm::vec4(5.0f, 5.0f, 2.0f, 1.0f)); //can play with this more later
    prog.setUniform("Material.Shininess", 100.0f); //can play with this more later

    model = mat4(1.0f);
    model = glm::translate(model, vec3(0.0f, 0.0f, -10.0f));//translation is set here?
    model = glm::rotate(model, glm::radians(15.0f), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?
    model = glm::rotate(model, glm::radians(angle), vec3(0.0f, 1.0f, 0.0f));//rotation is set here?
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
    mesh->render(); //swampy

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
    model = glm::translate(model, vec3(0.0f, 0.0f, angle*5));//translation is set here?
    model = glm::rotate(model, glm::radians(40.0f), vec3(0.0f, 1.0f, 0.0f));//rotation is set here?
    setMatrices();
    mesh2->render(); //flare



    //*3*//
    prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f); //diffuse
    prog.setUniform("Material.Ka", 0.2f, 0.55f, 0.9f); //ambient
    prog.setUniform("Material.Ks", 0.8f, 0.8f, 0.8f); //specular
    prog.setUniform("Material.Shininess", 100.0f); //can play with this more later

    model = mat4(1.0f);
    model = glm::translate(model, vec3(0.0f, 0.0f, -10.0f));//translation is set here?
    model = glm::rotate(model, glm::radians(15.0f), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?
    model = glm::rotate(model, glm::radians(angle), vec3(0.0f, 1.0f, 0.0f));//rotation is set here?
    setMatrices();
    mesh3->render(); //grass

    //*4*//
    prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f); //diffuse
    prog.setUniform("Material.Ka", 0.2f, 0.55f, 0.9f); //ambient
    prog.setUniform("Material.Ks", 0.8f, 0.8f, 0.8f); //specular
    prog.setUniform("Material.Shininess", 100.0f); //can play with this more later

    model = mat4(1.0f);
    model = glm::translate(model, vec3(0.0f, 10.0f, -5.0f));//translation is set here?
    model = glm::rotate(model, glm::radians(15.0f), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?
    model = glm::rotate(model, glm::radians(angle), vec3(0.0f, 1.0f, 0.0f));//rotation is set here?
    setMatrices();
    mesh4->render(); //trees

    //*5*//
    prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f); //diffuse
    prog.setUniform("Material.Ka", 0.2f, 0.55f, 0.9f); //ambient
    prog.setUniform("Material.Ks", 0.8f, 0.8f, 0.8f); //specular
    prog.setUniform("Material.Shininess", 100.0f); //can play with this more later

    model = mat4(1.0f);
    model = glm::translate(model, vec3(6.0f, 2.0f, -5.0f));//translation is set here?
    model = glm::rotate(model, glm::radians(15.0f), vec3(1.0f, 0.0f, 0.0f));//rotation is set here?
    model = glm::rotate(model, glm::radians(angle), vec3(0.0f, 1.0f, 0.0f));//rotation is set here?
    setMatrices();
    mesh5->render(); //shanopi
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

    prog.setUniform("ProjectionMatrix", projection);    //currently not-used

}

void moveLeft(float r)
{
    
    SceneBasic_Uniform update(float r);
}

void moveRight(float r)
{
    r = r * -1.0f;
    SceneBasic_Uniform update(float r);
}

