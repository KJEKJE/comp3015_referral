#version 460

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexNormal;
//layout (location = 2) in vec3 VertexColor;

//flat out vec3 LightIntensity;

flat out vec3 Position; //might need to be vec3, will see
out vec3 Normal;

//out vec3 Color;

uniform mat4 RotationMatrix;

//LAB2pt1//
//uniform vec4 LightPosition;
//uniform vec3 Kd;
//uniform vec3 Ld;


//PHONG//
/*uniform struct LightInfo
{
    vec4 Position;
    vec3 La; //ambient!*
    vec3 Ld; //diffuse!
    vec3 Ls; //specular!
} Light;*/

/*uniform struct MaterialInfo
{
    vec3 Ka; //ambient!*
    vec3 Kd; //diffuse!
    vec3 Ks; //specular!
    float Shininess; //how shiny it is
} Material;*/


uniform mat4 ModelViewMatrix;
uniform mat3 NormalMatrix;
uniform mat4 MVP;
uniform mat4 ProjectionMatrix;

//uniform struct SpotlightInfo
//{
//    vec4 Position;
//    vec3 La;
//    vec3 Ld;
//    vec3 Ls;
//    vec3 Direction;
//    float Exponent;
//    float Cutoff;
//} Spot;

//vec3 phong(vec3 n, vec4 pos)
//{
//    vec3 ambient=Light.La*Material.Ka;
//
//    vec3 s=normalize(vec3(Light.Position - pos));
//
//    float sDotN = max(dot(s,n), 0.0);
//    vec3 diffuse = Light.Ld*Material.Kd*sDotN;
//    vec3 spec = vec3 (0.0);
//    if(sDotN > 0.0){
//        vec3 v = normalize(-pos.xyz);
//        vec3 r = reflect(-s,n);
//
//        spec = Light.Ls*Material.Ks*pow(max(dot(r,v), 0.0), Material.Shininess);
//
//    }
//
//    //PHONG//
//    return ambient + diffuse + spec; //reminder to remember your brackets!
//
//}

/*vec3 phongSpotlight(vec3 n, vec4 pos)
{
    vec3 ambient=Spot.La*Material.Ka;

    vec3 diffuse=vec3(0);
    vec3 spec=vec3(0);

    vec3 s=normalize(vec3(Spot.Position - (pos*Spot.Position.w)));
    float cosAng = dot(-s,normalize(Spot.Direction));
    float angle = acos(cosAng);
    float spotScale = 0.0;

    if(angle < Spot.Cutoff)
    {
        spotScale = pow(cosAng, Spot.Exponent);

        float sDotN = max(dot(s,n), 0.0);
        diffuse = Spot.Ld*Material.Kd*sDotN;
        spec = vec3 (0.0);

        if(sDotN > 0.0)
        {
            vec3 v = normalize(-pos.xyz);
            vec3 r = reflect(-s,n);

            spec = Spot.Ls*Material.Ks*pow(max(dot(r,v), 0.0), Material.Shininess);

        }
    
    }

    //PHONG//
    return ambient + diffuse + spec; //reminder to remember your brackets!

}*/


void getCameraSpaceValues(out vec3 norm, out vec3 position)
{
    norm=normalize(NormalMatrix*VertexNormal);
    position=(ModelViewMatrix * vec4(VertexPosition, 1.0)).xyz; //has been tweaked
}

void main()
{
    //vec3 camNormal, camPosition;
    getCameraSpaceValues(Normal, Position);

    //LightIntensity = phongSpotlight(camNormal, vec4 (camPosition, 1.0));  //FOR PHONG    
    //LightIntensity=Kd*Ld* //reminder to remember your brackets!

    gl_Position=MVP*vec4(VertexPosition,1.0);

    //Color = VertexColor;
}
