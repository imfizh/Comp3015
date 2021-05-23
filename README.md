# Comp3015

o Which version Visual Studio and Operating System you used to test/write the code locally?
- Microsoft Visual Studio Community 2019 Version 16.5.3
- Windows 10

o What did you start with?
- This project was built upon the "Project Template Diffuse" project template provided as part of the Comp3015 module

o How does it work?
- For the project I've set up a simple scene using two Zebra models I created. The first of which uses a zebra texture image I also made, whilst
  the other uses the moss texture that comes with the project template. Within the fragment shader the Blinn Phong shading model has been set up.
  As well as this a noise disintegration effect has also been set up in the fragment shader through the use of the GLSL discard keyword, and to top
  this off gamma colour correction has also been used. The zebra using the moss texture has had the vertex surface animation effect applied to it,
  and both models make use of the silhouette outline effect, which has been created through the use of a geometry shader.

o How does your code fit together 
Scenebasic_uniform.cpp
- In the scenebasic_uniform.cpp we start by defining what objects we want for our scene, and load in our zebra object into our mesh variable.
- initscene we set the diffuse, specularity and ambience values for our spotlight, as well as the exponent and cutoff values, we also read in
  our textures and then bind the textures to layout positions in the fragment shader. The values for the gamme, low and high thresholds, and all
  the variables for the silhouette line effect are also set.
- In the compile method the shader files are compiled.
- in the update method we increase our value of angle every update, and once it reaches a value greater than 2*pi we update our value in the
  other direction, we than use this value in our look at function to update where the camera is looking in the scene
- In the render function we set the postion of our spotlight in the scene and also set the material diffuse, specular, ambiance and shininess 
  for each object. For the first zebra set a value for the variable called 'testNumb' to 0, we use this to differenciant which texture
  the object should be using in the fragment shader, with a value if 0 resulting in the zebra texture and a value of 1 resulting in the moss texture.
  In the vertex shader a bool variable called "wiggle" is created, this is used to determine whether the mesh will have the surface animation effect
  applied or not. The second zebra model has its value set to true, and as such this results in it having the effect.

basic_uniform.vert
- In the vertex shader is where the surface wave animation is calculated. To do so we transform the y coordinate of the surface as a function 
  of the current time and the x coordinate. We then get the normal vector at the transformed location, normalize the vector, and pass it into the out 
  normal variable, which is sent to the geometry shader.

basic_uniform.gs
- Inside the geometry shader is where the silhouette edge effect it produced. When a mesh is rendered with adjacency information, the geometry 
  shader has access to all six vertices of a triangle. We use the adjacent triangles to determine whether a triangle edge is part of the silhouette of 
  the object by calculating if the triangle is front facing and the corresponding adjacent triangle is not front facing. We can determine whether 
  a triangle is front facing within the geometry shader by computing the triangle's normal vector and obtaining the z coordinate, as the z coordinate 
  of the triangles normal vector will be positive for front facing triangles, so in the isFrontFacing bool we calculate if the z of the normal is 
  greater than 0. Once the silhouette edges are determined, we pass out a variable, called GIsEdge, to the fragment shader which if 1 will render 
  the silhouette edge and if 0 will render the base mesh. The function emitEdgeQuad takes in the start and end point of the line, calculates the quads 
  edges and this is what will be emitted as the silhouette line. A variable called n is also produced that calculates the size of the silhouette line. 

basic_uniform.frag
- The frag shader starts by setting the binding locations for the textures textures. As well as setting several uniform variables, these being a gamma
  value, and a low and high threshold. The gamma value will be used for gamma colour correction, and the threshold values will be used to create the
  disintegration effect.
- We have a struct for the light info and a struct for the material info. We also have an in variable for the GIsEdge varaible from the geometry 
  shader. This variable is qualified as flat as this will make sure the value not be interpolated. Instead, it will have the same value for every 
  fragment within a triangle. 
- Our blinnPhongSpot function takes in a postion and a normal, and in the function we perform all our calculations for our light and meterial. The first
  thing in the function is an if that determines which texture will be used on the mesh. In the function we use a float called scaleFactor to give a toon 
  shade effect to the diffuse calculation. It works by setting all values within a certain range to a specific value, and this is what gives us the 
  cel shading effect.
- In the main function we use the GIsEdge value to determine whether to render the silhouette line effect or render the mesh. If the mesh is to be rendered
  the moss texture is taken and stored in a new texture called noise. The alpha value is taken at the render point and is checked against the threshold
  values. If the alpha is higher or lower than the threshold then it is discarded using the GLSL keyword discard.
- The final render is passed into the fragColor through the blinn phong calculation, that is being gamma colour corrected. Because this final pass occurs
  on the silhouette line, it creates a coloured outline effect, using the colour of the texture.

o A Link to the Github Repository 
- https://github.com/imfizh/Comp3015

o A Link to the unlisted YouTube Video
- https://www.youtube.com/watch?v=sv_mPQpy-rA&ab_channel=LukePettitt
