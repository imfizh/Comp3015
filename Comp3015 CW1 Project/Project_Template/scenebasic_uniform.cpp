#include "scenebasic_uniform.h"
#include <iostream>
#include <sstream>
using std::cerr;
using std::endl;

#include <glm/gtc/matrix_transform.hpp>
#include "helper/texture.h"
using glm::vec3;
using glm::mat4;
using glm::vec4;
using glm::mat3;
float tPrev;
float angle;

SceneBasic_Uniform::SceneBasic_Uniform() : time(0), plane(50.0f, 50.0f, 1, 1), teapot(14, glm::mat4(1.0f)), torus(1.75f * 0.75f, 0.75f * 0.75f, 50, 50) {
    mesh = ObjMesh::loadWithAdjacency("media/zebra.obj",true);
}

void SceneBasic_Uniform::initScene()
{
    compile();
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
    

    prog.setUniform("EdgeWidth", 0.01f);
    prog.setUniform("PctExtend", 0.25f);
    prog.setUniform("LineColor", vec4(0.05f,0.0f,0.05f,1.0f));
    prog.setUniform("Material.Kd", 0.7f,0.5f,0.2f);
    prog.setUniform("Material.Ka", 0.2f,0.2f,0.2f);
    //prog.setUniform("Light.Position", vec4(0.0f, 0.0f, 0.0f, 1.0f));
    //prog.setUniform("Light.Intensity", 1.0f, 1.0f, 1.0f);
    
    projection = mat4(1.0f);
    prog.setUniform("Spot.L", vec3(10.0f));
    prog.setUniform("Spot.La", vec3(0.5f));
    prog.setUniform("Spot.Exponent", 50.0f);
    prog.setUniform("Spot.Cutoff", glm::radians(15.0f));


    tPrev = 0;
    angle = 0;
    GLuint brick = Texture::loadTexture("media/texture/brick1.jpg");
    GLuint moss = Texture::loadTexture("media/texture/moss.png");
    GLuint zeb = Texture::loadTexture("media/zebraUVedit2.png");
    
    // Load brick texture file into channel 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, brick);
    // Load moss texture file into channel 1
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, moss);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, zeb);

  /*  prog.setUniform("Fog.MaxDist", 30.0f);
    prog.setUniform("Fog.MinDist", 1.0f);
    prog.setUniform("Fog.Color", vec3(0.4f, 0.4f, 0.4f));*/
    
    //angle = glm::half_pi<float>();
}

void SceneBasic_Uniform::compile()
{
	try {
		prog.compileShader("shader/basic_uniform.vert");
		prog.compileShader("shader/basic_uniform.frag");
        prog.compileShader("basic_uniform.gs");
		prog.link();
		prog.use();
	} catch (GLSLProgramException &e) {
		cerr << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}

void SceneBasic_Uniform::update( float t )
{
    time = t;
	//update your angle here
    float deltaT = t - tPrev;
    if (tPrev == 0.0f)
        deltaT = 0.0f;

    tPrev = t;
    angle += 0.75f * deltaT;
    if (angle > glm::two_pi<float>())
        angle -= glm::two_pi<float>();
    //view = glm::lookAt(vec3(20.0f * cos(angle), 15.0f, 7.5f), vec3(0.0f, 0.75f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
    view = glm::lookAt(vec3(20.0f * cos(angle), 15.0f, 7.5f), vec3(0.0f, 0.75f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
}

void SceneBasic_Uniform::render()
{
    prog.setUniform("Time", time);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 
    vec4 lightPos = vec4(10.0f, 30.0f, 0.0f, 1.0f);
    prog.setUniform("Spot.Position", vec3(view * lightPos));
    //vec4 lightPos = vec4(10.0f * cos(angle), 5.0f, 5.0f * sin(angle), 0.5f);
    //prog.setUniform("Spot.Position", view * lightPos);
    mat3 normalMatrix = mat3(vec3(view[0]), vec3(view[1]), vec3(view[2]));
    prog.setUniform("Spot.Direction", normalMatrix * vec3(-lightPos));

    
    prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f);
    prog.setUniform("Material.Ks", 0.95f, 0.95f, 0.95f);
    prog.setUniform("Material.Ka", 0.2f * 0.3f, 0.55f * 0.3f, 0.9f * 0.3f);
    prog.setUniform("Material.Shininess", 100.0f);
    model = mat4(1.0f);
    model = glm::translate(model, vec3(0.0f, 0.0f, -2.0f));
    model = glm::rotate(model, glm::radians(45.0f), vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(-90.0f), vec3(1.0f, 0.0f, 0.0f));
    setMatrices();
    teapot.render();
    
   
    prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f);
    prog.setUniform("Material.Ks", 0.95f, 0.95f, 0.95f);
    prog.setUniform("Material.Ka", 0.2f * 0.3f, 0.55f * 0.3f, 0.9f * 0.3f);
    prog.setUniform("Material.Shininess", 100.0f);
    model = mat4(1.0f);
    model = glm::translate(model, vec3(-1.0f, 0.75f, 3.0f));
    model = glm::rotate(model, glm::radians(-90.0f), vec3(1.0f, 0.0f, 0.0f));
    setMatrices(); 
    torus.render();

    
    prog.setUniform("Material.Kd", 0.7f, 0.7f, 0.7f);
    prog.setUniform("Material.Ks", 0.9f, 0.9f, 0.9f);
    prog.setUniform("Material.Ka", 0.2f, 0.2f, 0.2f);
    prog.setUniform("Material.Shininess", 90.0f);
    prog.setUniform("Spot.testNumb", 1.0f);
    model = mat4(1.0f);
    setMatrices();
    plane.render();
    
    
    prog.setUniform("Material.Kd", 0.2f, 0.55f, 0.9f);
    prog.setUniform("Material.Ks", 0.95f, 0.95f, 0.95f);
    prog.setUniform("Material.Ka", 0.2f * 0.3f, 0.55f * 0.3f, 0.9f * 0.3f);
    prog.setUniform("Material.Shininess", 100.0f);
    prog.setUniform("Spot.testNumb", 0.0f);
    model = mat4(1.0f);
    model = glm::translate(model, vec3(3.0f, 0.75f, 2.0f));
    model = glm::rotate(model, glm::radians(-90.0f), vec3(1.0f, 0.0f, 0.0f));
    setMatrices();
    cube.render();

    prog.setUniform("Material.Kd", 0.4f, 0.4f, 0.4f);
    prog.setUniform("Material.Ks", 0.9f, 0.9f, 0.9f);
    prog.setUniform("Material.Ka", 0.5f, 0.5f, 0.5f);
    prog.setUniform("Material.Shininess", 10.0f);
    model = mat4(1.0f);
    model = glm::scale(model, vec3(2.0f, 2.0f, 2.0f));
    model = glm::translate(model, vec3(3.0f, 3.0f, 0.0f));
    model = glm::rotate(model, glm::radians(70.0f), vec3(0.0f, -1.0f, 0.0f));
    setMatrices();
    mesh->render();

}

void SceneBasic_Uniform::setMatrices()
{
    mat4 mv = view * model; //we create a model view matrix
    
    prog.setUniform("ModelViewMatrix", mv); //set the uniform for the model view matrix
    
    prog.setUniform("NormalMatrix", glm::mat3(vec3(mv[0]), vec3(mv[1]), vec3(mv[2]))); //we set the uniform for normal matrix
    
    prog.setUniform("MVP", projection * mv); //we set the model view matrix by multiplying the mv with the projection matrix

}

void SceneBasic_Uniform::resize(int w, int h)
{
    glViewport(0, 0, w, h);
    width = w;
    height = h;
    projection = glm::perspective(glm::radians(70.0f), (float)w / h, 0.3f, 100.0f);
}
