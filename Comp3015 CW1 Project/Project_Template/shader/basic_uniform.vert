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

//Practical 7 variables
//out vec4 vpos;
uniform float Time;
uniform float Freq = 2.5;
uniform float Velocity = 2.5;
uniform float Amp = 0.6;

uniform struct WiggleInfo{
 bool wiggle;
}Wiggle;

//shadow variables
//out vec4 ShadowCoord;
//uniform mat4 ShadowMatrix;

void main() 
{ 
   //n = normalize( NormalMatrix * VertexNormal);
   // vn = normalize( NormalMatrix * VertexNormal);
   //pos = (ModelViewMatrix * vec4(VertexPosition,1.0)).xyz;
   //vpos = vec3(ModelViewMatrix * vec4(VertexPosition,1.0));
   // vpos = (ModelViewMatrix * vec4(VertexPosition,1.0)).xyz;
   //ShadowCoord = ShadowMatrix *vec4(VertexPosition,1.0);

  // vec4 pos = vec4(VertexPosition,1.0);
  // float u = Freq * pos.x - Velocity * Time;
  // pos.y = Amp * sin( u );

  // vec3 n = vec3(0.0);
  // n.xy = normalize(vec2(cos( u ), 1.0));

  // vpos = vec3(ModelViewMatrix * pos);
  // vn = NormalMatrix * n;


   vTexCoord = VertexTexCoord;

  //gl_Position = MVP * vec4(VertexPosition,1.0); 

 // gl_Position = MVP * pos;

 
  if(Wiggle.wiggle == true){
   vec4 pos = vec4(VertexPosition,1.0);
   float u = Freq * pos.x - Velocity * Time;
   pos.y = Amp * sin( u );
   vec3 n = vec3(0.0);
   n.xy = normalize(vec2(cos( u ), 1.0));
   vpos = vec3(ModelViewMatrix * pos);
   vn = NormalMatrix * n;
   gl_Position = MVP * pos;
  }else{
  vn = normalize( NormalMatrix * VertexNormal);
  vpos = (ModelViewMatrix * vec4(VertexPosition,1.0)).xyz;
  gl_Position = MVP * vec4(VertexPosition,1.0);
  }
} 


