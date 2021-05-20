#version 460

//in variables, this are in model coordinates
layout (location = 0) in vec3 VertexPosition; 
layout (location = 1) in vec3 VertexNormal; 
layout (location = 2) in vec2 VertexTexCoord;

//out vector needed for the fragment shader
//out vec3 LightIntensity; 
//out vec3 Colour;  // part of multiple light set up
out vec3 vpos;
out vec3 vn;
out vec2 vTexCoord;
 

//uniforms for matrices required in the shader
uniform mat4 ModelViewMatrix;   //model view matrix
uniform mat3 NormalMatrix;		//normal matrix
uniform mat4 MVP;				//model view projection matrix
uniform mat4 ProjectionMatrix;


void main() 
{ 
   //n = normalize( NormalMatrix * VertexNormal);
   vn = normalize( NormalMatrix * VertexNormal);
   //pos = (ModelViewMatrix * vec4(VertexPosition,1.0)).xyz;
   vpos = vec3(ModelViewMatrix * vec4(VertexPosition,1.0));

   vTexCoord = VertexTexCoord;

  //turns any vertex position into model view projection in preparations to 
  //graphics pipeline processes before fragment shader (clipping)
  gl_Position = MVP * vec4(VertexPosition,1.0); 
} 


