#version 460

flat in vec3 Position;
flat in vec3 Normal;

layout (location = 0) out vec4 FragColour;

//flat in vec3 LightIntensity;

const float PI = 3.14159265358979323846;

uniform struct LightInfo
{
    vec4 Position;
    vec3 L;
} Light[3];

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

const int level = 8;
const float scaleFactor = 1.0/level;

/*uniform struct MaterialInfo
{
    vec3 Ka; //ambient!*
    vec3 Kd; //diffuse!
    vec3 Ks; //specular!
    float Shininess; //how shiny it is
} Material;*/


uniform struct MaterialInfo
{
    float Rough;
    bool Metal;
    vec3 Colour;
} Material;


float ggxDistribution(float nDotH)
{
    float alpha2 = Material.Rough*Material.Rough*Material.Rough*Material.Rough;
    float d=(nDotH*nDotH)*(alpha2-1)+1;
    return alpha2/(PI*d*d);
}

float geomSmith(float dotProd)
{
    float k=(Material.Rough+1.0)*(Material.Rough+1.0)/8.0;
    float denom=dotProd*(1-k)+k;
    return 1.0/denom;
}

vec3 schlickFresnel(float lDotH)
{
    vec3 f0=vec3(0.04);
    if(Material.Metal)
    {
        f0 = Material.Colour;
    }
    return f0+(1-f0)*pow(1.0-lDotH, 5);
}


vec3 microfacetModel(int lightIdx, vec3 position, vec3 n)
{
    vec3 diffuseBrdf=vec3(0.0);
    if(!Material.Metal) diffuseBrdf=Material.Colour;

    vec3 l=vec3(0.0), lightI = Light[lightIdx].L;
    if(Light[lightIdx].Position.w == 0.0)
    {
        l = normalize(Light[lightIdx].Position.xyz);
    }
    else
    {
        l=Light[lightIdx].Position.xyz-position;
        float dist = length(l);
        l=normalize(l);
        lightI/=(dist*dist);
    }

    vec3 v=normalize(-position);
    vec3 h=normalize(v+l);
    float nDotH = dot(n,h);
    float lDotH = dot(l,h);
    float nDotL = max(dot(n,l), 0.0);
    float nDotV = dot(n,v);
    vec3 specBrdf = 0.25 * ggxDistribution(nDotH)*schlickFresnel(lDotH)*geomSmith(nDotL)*geomSmith(nDotV); //aaaaaaahhhhhhh
    return (diffuseBrdf + PI*specBrdf) * lightI * nDotL;


}


/*vec3 phongSpotlight(vec3 n, vec4 pos)
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
        diffuse = Spot.Ld*Material.Kd*(floor(sDotN * level) * scaleFactor);
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

}*/

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
    
    //FragColor = vec4(phongSpotlight(Normal, Position), 1.0);

    vec3 sum=vec3(0);
    vec3 n=normalize(Normal);
    for (int i=0; i<3; i++)
        sum += microfacetModel(i, Position, n);
    sum = pow(sum, vec3(1.0/2.2));
    FragColour = vec4(sum, 1);

}
