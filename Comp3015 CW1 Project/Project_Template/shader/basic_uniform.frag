#version 460

//in variable that receives the diffuse calculation from the vertex shader
//in vec3 LightIntensity;
//in vec3 Colour;
// in vec3 pos;
// in vec3 n;
// in vec2 TexCoord;

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
vec3 Position;
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

//vec3 toonShade(){
  //vec3 s = normalize( Light.Position.xyz - gPos.xyz);
  //vec3 ambient = Material.Ka;
  //float cosine = dot(s, gNormal);
  //vec3 diffuse = Material.Kd * ceil(cosine *levels)*scaleFactor;
  //return Light.Intensity *(ambient+diffuse);
//}
vec3 blinnPhongSpot( vec3 position, vec3 normal ) {

//vec4 zebTexColor = texture(ZebTex, TexCoord);
 vec4 zebTexColor = texture(ZebTex, gTexCoord);
//vec3 texColor = texture(ZebTex, TexCoord).rgb;
 vec3 texColor = texture(ZebTex, gTexCoord).rgb;

 if(Spot.testNumb == 1.0f){
//vec4 brickTexColor = texture(BrickTex, TexCoord);
 vec4 brickTexColor = texture(BrickTex, gTexCoord);
//vec4 mossTexColor = texture(MossTex, TexCoord);
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
    //we pass LightInyensity to outr FragColor, notice the difference between vector types
    // vec3 and vec4 and how we solved the problem
    //Colour = vec3(0.0);
    //for( int i = 0; i < 3; i++ ){
    //Colour += phongModel( i, vec3(pos), n );}
    //FragColor = vec4(Colour, 1.0);
     //FragColor = vec4(blinnPhongSpot(pos, normalize(n)), 1);  //just uncomment this to get code to work without fog
  
   // float dist = abs( pos.z ); //distance calculations
   // //fogFactor calculation based on the formula presented earlier
   // float fogFactor = (Fog.MaxDist - dist) / (Fog.MaxDist - Fog.MinDist);
   // fogFactor = clamp( fogFactor, 0.0, 1.0 ); //we clamp values
   // //colour we receive from blinnPhong calculation
   // vec3 shadeColor = blinnPhongSpot(pos, normalize(n));
   // //we assign a colour based on the fogFactor using mix
   // vec3 color = mix( Fog.Color, shadeColor, fogFactor );
   // //vec3 color = mix( Fog.Color, Colour, fogFactor );
   // FragColor = vec4(color, 1.0); //final colour

   // vec4 alphaMap = texture(AlphaTex, TexCoord);
   // if( alphaMap.a < 0.15 ){
   //    discard;
   // } else {
   //    FragColor = vec4( blinnPhongSpot(pos,normalize(n)), 1.0 );
   // }

   if(GIsEdge == 1){
     FragColor = LineColor;
   } else{
     //FragColor = vec4( toonShade(), 1.0);
     FragColor = vec4( blinnPhongSpot(gPos,normalize(gNormal)), 1.0 );
   }
}
