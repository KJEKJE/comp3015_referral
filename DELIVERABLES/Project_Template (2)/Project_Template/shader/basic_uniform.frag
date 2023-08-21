#version 460

in vec4 Position;
in vec3 Normal;

layout (location = 0) out vec4 FragColor;

//flat in vec3 LightIntensity;

uniform struct SpotlightInfo
{
    vec4 Position;
    vec3 La;
    vec3 Ld;
    vec3 Ls;
    vec3 Direction;
    float Exponent;
    float Cutoff;
} Spot;

uniform struct MaterialInfo
{
    vec3 Ka; //ambient!*
    vec3 Kd; //diffuse!
    vec3 Ks; //specular!
    float Shininess; //how shiny it is
} Material;


vec3 phongSpotlight(vec3 n, vec4 pos)
{
    vec3 ambient=Spot.La*Material.Ka;

    vec3 diffuse=vec3(0);
    vec3 spec=vec3(0);

    vec3 s=normalize(vec3(Spot.Position-(pos*Spot.Position.w)));
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

    //PHONG SPOTLIGHT//
    return ambient + diffuse + spec; //reminder to remember your brackets!

}

/*vec3 blinnphongSpotlight(vec3 n, vec4 pos)
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
            vec3 h = normalize(v+s);

            spec = Spot.Ls*Material.Ks*pow(max(dot(h,n), 0.0), Material.Shininess);

        }
    
    }

    //BLINNPHONG SPOTLIGHT//
    return ambient + diffuse + spec; //reminder to remember your brackets!

}*/

void main() {
    //FragColor = vec4(LightIntensity, 1.0);
    FragColor = vec4(phongSpotlight(Normal, Position), 1.0);
}
