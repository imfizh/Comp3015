# Comp3015

How does the user interact with your executable? How do you open and control the
software you wrote (exe file)?
• How does the program code work? How do the classes and functions fit together and who
does what? 
• What makes your shader program special and how does it compare to similar things?
(Where did you get the idea from? What did you start with? How did you make yours
unique? Did you start with a given shader/project?)
• Include a link to a video report that details the above but also goes into more detail on:
 o Anything else which will helps us understand how your shader works.
 o Are there any software engineering issues, such as the trade-off between
 performance and good practice?
 o A (brief) evaluation of what you think you have achieved, and what (if anything) you
 would do differently, knowing what you now know. Don’t be modest but be realistic!


o Which version Visual Studio and Operating System you used to test/write the code locally?
- Microsoft Visual Studio Community 2019 Version 16.5.3
- Windows 10

o How does it work?
- For the project I've set up a simple scene made with a plane, a cube, a torus, a teapot and a zebra. We then have implemeneted in the fragment
  shader the Blinn Phong model and set up a spotlight that uses it. We also have implemented some cel shading in the fragment shader by setting
  different levels in the diffuse calculation. We also have several textures in the scene, one texture for the zebra which is shared by the other
  objects in the scene, and then some multi texturing for the plane, where we have a brick and moss texture that are overlapped. To top it off 
  we have some fog set in the scene which we combine with our Blinn Phong spotlight by using the glsl mix function.

o How does your code fit together 
Scenebasic_uniform.cpp
- In the scenebasic_uniform.cpp we start by defining what objects we want for our scene, and load in our zebra object into our mesh variable.
- initscene we set the diffuse, specularity and ambience values for our spotlight, as well as the exponent and cutoff values, we also read in
  our texturesand then bind the textures to layout positions in the fragment shader. Finally we set the variables for our fog
- in the update method we increase our value of angle every update, and once it reaches a value greater than 2*pi we update our value in the
  other direction, we than use this value in our look at function to update where the camera is looking in the scene
- In the render function we set the postion of our spotlight in the scene and also set the material diffuse, specular, ambiance and shininess 
  for each object. For the plane and the cube we also set a value for the variable called 'testNumb', we use this to differenciant which texture
  the object should be using in the fragment shader.
basic_uniform.vert
- In the vertices shader we calculate some out variables, these being our normal, our camera position and our texture coordinates, these variables
  are taken in by the fragment shader as we do per fragment shading.
basic_uniform.frag
- We first get our in variables from the vert shader, then have our bindings for our textures
- We then have 3 structs, one for the spot light, one for the material and one for the fog. For the spot light we have a variable for the diffuse,
  for the ambiance, the direction of the light, the exponent, the cutoff angle, and the testNumb variable. For the material struct we also have
  variables for the diffuse, ambience, specular and another for the shininess of the material. For the fog we define a max and min distance for
  the fog and a color variable
- We also define a levels and scaleFactor variable, these are used to enable to cel shading effect
- Our blinnPhongSpot function takes in a postion and a normal, and in the function we perform all our calculations for our spot light and meterial
- For our diffuse calculation in the function we set all values within a certain range to a specific value, as this is what gives us the cel shading
- In the main function is where we perform our calculations for the fog and mix the fog in with our values calculated in the blinn Phong function

o A Link to the unlisted YouTube Video
- t
