#version 460

uniform float Gamma;
uniform float LowThreshold;
uniform float HighThreshold;


in vec2 gTexCoord;
in vec3 gPos;
in vec3 gNormal;
uniform vec4 LineColor;
flat in int GIsEdge;

//out variable, this typical for all fragment shaders
layout (location = 0) out vec4 FragColor;
layout(binding=0) uniform sampler2D BrickTex;
layout(binding=1) uniform sampler2D MossTex;
layout(binding=2) uniform sampler2D ZebTex;

uniform struct SpotLightInfo {
vec3 Position; // Position in cam coords
vec3 L; // Diffuse/spec intensity
vec3 La; // Amb intensity
vec3 Direction; // Direction of the spotlight in cam coords.
float Exponent; // Angular attenuation exponent
float Cutoff; // Cutoff angle (between 0 and pi/2)
float testNumb;
} Spot;

uniform struct LightInfo{
vec4 Position;
vec3 Intensity;
} Light;


//material information struct
uniform struct MaterialInfo 
{
  vec3 Kd;      // Diffuse reflectivity
  vec3 Ks;
  vec3 Ka;
  float Shininess; //specular shininess factor
} Material;
vec3 Colour;

const int levels = 4;
const float scaleFactor = 1.0 / levels;

uniform struct FogInfo
{
float MaxDist; //max distance
float MinDist; //min distance
vec3 Color; //colour of the fog
} Fog;


vec3 blinnPhongSpot( vec3 position, vec3 normal ) {

 vec4 zebTexColor = texture(ZebTex, gTexCoord);
 vec3 texColor = texture(ZebTex, gTexCoord).rgb;

 if(Spot.testNumb == 1.0f){
 vec4 brickTexColor = texture(BrickTex, gTexCoord);
 vec4 mossTexColor = texture(MossTex, gTexCoord);
 texColor = mix(brickTexColor.rgb, mossTexColor.rgb, mossTexColor.a);
}

vec3 ambient = Spot.La * texColor;

vec3 s = normalize(vec3(Spot.Position) - position);
float cosAng = dot(-s, normalize(Spot.Direction)); //cosine of the angle
float angle = acos( cosAng ); //gives you the actual angle
float spotScale = 0.0;
vec3 spec = vec3(0.0);
vec3 diffuse = vec3(0.0);
if(angle < Spot.Cutoff )
{
spotScale = pow( cosAng, Spot.Exponent );
float sDotN = max( dot(s,normal), 0.0 );
diffuse = texColor * floor( sDotN * levels ) * scaleFactor;

if( sDotN > 0.0 )
{
//vec3 v = normalize(-pos.xyz);
vec3 v = normalize(-gPos.xyz);
      vec3 h = normalize(v+s);  //half vector
      vec3 r = reflect( -s, normal );
      spec = Material.Ks * pow( max( dot(h,v), 0.0 ), Material.Shininess );
}
}
return ambient + spotScale * Spot.L * (diffuse + spec);
}

void main()
{

   if(GIsEdge == 1){
     FragColor = LineColor;
   } else{
   vec4 noise = texture(MossTex, gTexCoord);    // uses noise and thresholds to create a disintigration effect;
   if( noise.a < LowThreshold || noise.a > HighThreshold)
   discard; 
   }
   FragColor = vec4( pow( blinnPhongSpot(gPos,normalize(gNormal)), vec3(1.0/Gamma) ), 1.0 );  // use of gamma correction
}
