#version 460

//in variables, this are in model coordinates
layout (location = 0) in vec3 VertexPosition; 
layout (location = 1) in vec3 VertexNormal; 
layout (location = 2) in vec2 VertexTexCoord;

out vec3 vpos;
out vec3 vn;
out vec2 vTexCoord;
 

//uniforms for matrices required in the shader
uniform mat4 ModelViewMatrix;   //model view 
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


void main() 
{ 
   vTexCoord = VertexTexCoord;
 
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


