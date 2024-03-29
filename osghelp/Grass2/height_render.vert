// height_render.vert

uniform mat4 osg_ViewMatrixInverse;
varying vec4 pos_world;

uniform mat4 viewInverseMatrixCam;

void main()
{
gl_TexCoord[0] = gl_MultiTexCoord0;

	pos_world = viewInverseMatrixCam * gl_ModelViewMatrix * gl_Vertex;
	
//	pos_world = pos_world*0.1;

//	pos_world = -gl_ModelViewMatrix * gl_Vertex;

	vec4 pos = gl_ModelViewProjectionMatrix * gl_Vertex;
	gl_Position = pos;
}