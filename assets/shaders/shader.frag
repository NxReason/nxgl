#version 330 core

in vec2 TexCoord;

out vec4 FragColor;

uniform vec3 uColor;
uniform sampler2D uTexture;

void main()
{
  vec4 texColor = texture(uTexture, TexCoord);
  vec4 bgColor = vec4(uColor, 1.0);
  FragColor = mix(bgColor, texColor, texColor.a);
}