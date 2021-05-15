sampler RT : register(s0);
sampler Text0 : register(s1);
uniform float timeSin;
float alphaBlending;
float tamanioBorde;

struct VS_OUTPUT {
   float4 pos: POSITION;
   float2 texCoord0: TEXCOORD0;
};

float4 ps_main( VS_OUTPUT input ): COLOR0
{
    float bordeCircle = abs(sin(timeSin)) * tamanioBorde;
    float4 colorVertex = tex2D(RT, input.texCoord0.xy);
    float dist = distance(float2(0.5f, 0.5f), input.texCoord0.xy);

    if(dist < 0.85f - bordeCircle){
        return colorVertex;
    }
    
    float4 color = (tex2D(Text0, input.texCoord0.xy) * alphaBlending) + (colorVertex * (1 - alphaBlending));

    return color;
}
