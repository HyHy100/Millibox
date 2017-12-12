uniform sampler2D texture;
uniform vec2 frameSize;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    gl_FragColor = gl_Color * pixel;
	vec2 fracf = vec2(floor(gl_FragCoord.x)/frameSize.x, floor(gl_FragCoord.y)/frameSize.y);

	if(fract(fracf.x) == 0) {
		gl_FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	}

	if(fract(fracf.y) == 0) {
		gl_FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	}
}