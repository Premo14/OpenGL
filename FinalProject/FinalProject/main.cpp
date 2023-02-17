#include "libs.h"

void initWindowHints();
void initGLEW();
void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH);
bool loadShaders(GLuint& program);
void initOpenGLOptions(GLFWwindow* window);
void attribPointers();
void textureParameters();
void updateInput(GLFWwindow* window);

Vertex tabletopVerts[] =
{
	// Back face of desk
	vec3(-0.3f, 0.05f, -0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 0 - Back-top left 
	vec3(0.3f, 0.05f, -0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 1 - Back-top right
	vec3(0.3f, 0.03f, -0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 2 - Back-bottom right
	vec3(-0.3f, 0.03f, -0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 3 - Back-bottom left
    // Front face of desk
    vec3(-0.3f, 0.05f, 0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(0.0f, 1.0f), 	 vec3(0.f, 0.f, 1.f), // 4 - Front-top left 
	vec3(-0.3f, 0.03f, 0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(0.0f, 0.0f), 	 vec3(0.f, 0.f, 1.f), // 5 - Front-bottom left
	vec3(0.3f, 0.03f, 0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(1.0f, 0.0f), 	 vec3(0.f, 0.f, 1.f), // 6 - Front-bottom right
	vec3(0.3f, 0.05f, 0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(1.0f, 1.0f), 	 vec3(0.f, 0.f, 1.f), // 7 - Front-top right
	// Left face of desk
    vec3(-0.3f, 0.05f, -0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 8 - Back-top left 
	vec3(-0.3f, 0.03f, -0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 9 - Back-bottom left
	vec3(-0.3f, 0.03f, 0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 10 - Front-bottom left
	vec3(-0.3f, 0.05f, 0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(1.0f, 1.0f), 	 vec3(0.f, 0.f, 1.f), // 11 - Front-top left
	// Right face of desk
    vec3(0.3f, 0.05f, -0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 12 - Back-top right 
	vec3(0.3f, 0.05f, 0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 13 - Front-top right
	vec3(0.3f, 0.03f, 0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 14 - Front-bottom right
	vec3(0.3f, 0.03f, -0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 15 - Back-bottom right
	// Top face of desk
    vec3(-0.3f, 0.05f, -0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 16 - Back-top left 
	vec3(-0.3f, 0.05f, 0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 17 - Front-top left
	vec3(0.3f, 0.05f, 0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 18 - Front-top right
	vec3(0.3f, 0.05f, -0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 19 - Back-top right
	// Bottom face of desk
    vec3(-0.3f, 0.03f, -0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 20 - Back-bottom left 
	vec3(0.3f, 0.03f, -0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 21 - Back-bottom right
	vec3(0.3f, 0.03f, 0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 22 - Front-bottom right
	vec3(-0.3f, 0.03f, 0.2f),		vec3(0.4f, 0.3f, 0.1f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f) // 23 - Front-bottom left
	
	
};																				  
unsigned numOfTabletopVerts = sizeof(tabletopVerts) / sizeof(Vertex);			  

GLuint tabletopIndices[] =
{
    // back face of table
    0, 1, 2,
    2, 3, 0,

    // front face of table
    4, 5, 6,
    6, 7, 4,

    // left face of table
    8, 9, 10,
    10, 11, 8,

    // right face of table
    12, 13, 14,
    14, 15, 12,

    // bottom of table
    16, 17, 18,
    18, 19, 16,

    // top of table
    20, 21, 22,
    22, 23, 20

};
unsigned numOfTabletopIndices = sizeof(tabletopIndices) / sizeof(GLuint);

Vertex tableLegVerts[] = 
{ 
	 // Back face of leg
	 vec3(-0.3f, 0.03f,-0.2f),		vec3(0.75f, 0.75f, 0.75f),	vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 0 - Back-top left 
	 vec3(-0.275f, 0.03f, -0.2f),	vec3(0.75f, 0.75f, 0.75f),	vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 1 - Back-top right
	 vec3(-0.275f, -0.4f, -0.2f),	vec3(0.75f, 0.75f, 0.75f),	vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 2 - Back-bottom right
	 vec3(-0.3f, -0.4f, -0.2f),		vec3(0.75f, 0.75f, 0.75f),	vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 3 - Back-bottom left
	 // Front face of leg
	 vec3(-0.3f, 0.03f, -0.175f),	vec3(0.75f, 0.75f, 0.75f),	vec2(0.0f, 1.0f), 	 vec3(0.f, 0.f, 1.f), // 4 - Front-top left 
	 vec3(-0.3f, -0.4f, -0.175f),	vec3(0.75f, 0.75f, 0.75f),	vec2(0.0f, 0.0f), 	 vec3(0.f, 0.f, 1.f), // 5 - Front-bottom left
	 vec3(-0.275f, -0.4f, -0.175f),	vec3(0.75f, 0.75f, 0.75f),	vec2(1.0f, 0.0f), 	 vec3(0.f, 0.f, 1.f), // 6 - Front-bottom right
	 vec3(-0.275f, 0.03f, -0.175f),	vec3(0.75f, 0.75f, 0.75f),	vec2(1.0f, 1.0f), 	 vec3(0.f, 0.f, 1.f), // 7 - Front-top right
	 // Left face of leg
	 vec3(-0.3f, 0.03f, -0.2f),		vec3(0.75f, 0.75f, 0.75f),	vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 8 - Back-top left 
	 vec3(-0.3f, -0.4f, -0.2f),		vec3(0.75f, 0.75f, 0.75f),	vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 9 - Back-bottom left
	 vec3(-0.3f, -0.4f, -0.175f),	vec3(0.75f, 0.75f, 0.75f),	vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 10 - Front-bottom left
	 vec3(-0.3f, 0.03f, -0.175f),	vec3(0.75f, 0.75f, 0.75f),	vec2(1.0f, 1.0f), 	 vec3(0.f, 0.f, 1.f), // 11 - Front-top left
	 // Right face of leg
	 vec3(-0.275f, 0.03f, -0.2f),	vec3(0.75f, 0.75f, 0.75f),	vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 12 - Back-top right 
	 vec3(-0.275f, 0.03f, -0.175f),	vec3(0.75f, 0.75f, 0.75f),	vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 13 - Front-top right
	 vec3(-0.275f, -0.4f, -0.175f),	vec3(0.75f, 0.75f, 0.75f),	vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 14 - Front-bottom right
	 vec3(-0.275f, -0.4f, -0.2f),	vec3(0.75f, 0.75f, 0.75f),	vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 15 - Back-bottom right
	 // Top face of leg
	 vec3(-0.3f, 0.03f, -0.2f),		vec3(0.75f, 0.75f, 0.75f),	vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 16 - Back-top left 
	 vec3(-0.3f, 0.03f, -0.175f),	vec3(0.75f, 0.75f, 0.75f),	vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 17 - Front-top left
	 vec3(-0.275f, 0.03f, -0.175f),	vec3(0.75f, 0.75f, 0.75f),	vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 18 - Front-top right
	 vec3(-0.275f, 0.03f, -0.2f),	vec3(0.75f, 0.75f, 0.75f),	vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 19 - Back-top right
	 // Bottom face of leg
	 vec3(-0.3f, -0.4f, -0.2f),		vec3(0.75f, 0.75f, 0.75f),	vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 20 - Back-bottom left 
	 vec3(-0.275f, -0.4f, -0.2f),	vec3(0.75f, 0.75f, 0.75f),	vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 21 - Back-bottom right
	 vec3(-0.275f, -0.4f, -0.175f),	vec3(0.75f, 0.75f, 0.75f),	vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 22 - Front-bottom right
	 vec3(-0.3f, -0.4f, -0.175f),	vec3(0.75f, 0.75f, 0.75f),	vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f) // 23 - Front-bottom left
};
unsigned numOfTableLegVerts = sizeof(tableLegVerts) / sizeof(Vertex);

GLuint tableLegIndices[] =
{
	// back face of table
	0, 1, 2,
	2, 3, 0,

	// front face of table
	4, 5, 6,
	6, 7, 4,

	// left face of table
	8, 9, 10,
	10, 11, 8,

	// right face of table
	12, 13, 14,
	14, 15, 12,

	// bottom of table
	16, 17, 18,
	18, 19, 16,

	// top of table
	20, 21, 22,
	22, 23, 20

};
unsigned numOfTableLegIndices = sizeof(tableLegIndices) / sizeof(GLuint);

Vertex monitorBaseVerts[] =
{
	// Back face of monitor base
	vec3(-0.17f, 0.055f, -0.125f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 0 - Back-top left 
	vec3(-0.07f, 0.055f, -0.125f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 1 - Back-top right
	vec3(-0.07f, 0.05f, -0.125f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 2 - Back-bottom right
	vec3(-0.17f, 0.05f, -0.125f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 3 - Back-bottom left
	// Front face of monitor base
	vec3(-0.17f, 0.055f, -0.075f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 4 - Front-top left
	vec3(-0.17f, 0.05f, -0.075f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 5 - Front-bottom left
	vec3(-0.07f, 0.05f, -0.075f), 	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 6 - Front-bottom right
	vec3(-0.07f, 0.055f, -0.075f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 7 - Front-top right
	// Left face of monitor base
	vec3(-0.17f, 0.055f, -0.125f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 8 - Back-top left 
	vec3(-0.17f, 0.05f, -0.125f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 9 - Back-bottom left
	vec3(-0.17f, 0.05f, -0.075f), 	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 10 - Front-bottom left
	vec3(-0.17f, 0.055f, -0.075f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f), 	 vec3(0.f, 0.f, 1.f), // 11 - Front-top left
	// Right face of monitor base
	vec3(-0.07f, 0.055f, -0.125f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 12 - Back-top right 
	vec3(-0.07f, 0.055f, -0.075f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f), 	 vec3(0.f, 0.f, 1.f), // 13 - Front-top right
	vec3(-0.07f, 0.05f, -0.075f),   vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 14 - Front-bottom right
	vec3(-0.07f, 0.05f, -0.125f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 15 - Back-bottom right
	// Top face of monitor base
	vec3(-0.17f, 0.055f, -0.125f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 16 - Back-top left 
	vec3(-0.17f, 0.055f, -0.075f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 17 - Front-top left
	vec3(-0.07f, 0.055f, -0.075f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 18 - Front-top right
	vec3(-0.07f, 0.055f, -0.125f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 19 - Back-top right
	// Bottom face of monitor base
	vec3(-0.17f, 0.05f, -0.125f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 20 - Back-bottom left 
	vec3(-0.07f, 0.05f, -0.125f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 21 - Back-bottom right
	vec3(-0.07f, 0.05f, -0.075f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 22 - Front-bottom right
	vec3(-0.17f, 0.05f, -0.075f), 	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f) // 23 - Front-bottom left
};
unsigned numOfMonitorBaseVerts = sizeof(monitorBaseVerts) / sizeof(Vertex);

GLuint monitorBaseIndices[] =
{
	// back face of monitor base
	0, 1, 2,
	2, 3, 0,

	// front face of monitor base
	4, 5, 6,
	6, 7, 4,

	// left face of monitor base
	8, 9, 10,
	10, 11, 8,

	// right face of monitor base
	12, 13, 14,
	14, 15, 12,

	// bottom of monitor base
	16, 17, 18,
	18, 19, 16,

	// top of monitor base
	20, 21, 22,
	22, 23, 20

};
unsigned numOfMonitorBaseIndices = sizeof(monitorBaseIndices) / sizeof(GLuint);

Vertex monitorShaftVerts[] =
{
	// Back face of monitor shaft
	vec3(-0.136f, 0.15f, -0.11f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 0 - Back-top left 
	vec3(-0.106f, 0.15f, -0.11f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 1 - Back-top right
	vec3(-0.106f, 0.055f, -0.11f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 2 - Back-bottom right
	vec3(-0.136f, 0.055f, -0.11f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 3 - Back-bottom left
	// Front face of monitor shaft
	vec3(-0.136f, 0.15f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 4 - Front-top left
	vec3(-0.136f, 0.055f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 5 - Front-bottom left
	vec3(-0.106f, 0.055f, -0.09f), 	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 6 - Front-bottom right
	vec3(-0.106f, 0.15f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 7 - Front-top right
	// Left face of monitor shaft
	vec3(-0.136f, 0.15f, -0.11f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 8 - Back-top left 
	vec3(-0.136f, 0.055f, -0.11f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 9 - Back-bottom left
	vec3(-0.136f, 0.055f, -0.09f), 	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 10 - Front-bottom left
	vec3(-0.136f, 0.15f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f), 	 vec3(0.f, 0.f, 1.f), // 11 - Front-top left
	// Right face of monitor shaft
	vec3(-0.106f, 0.15f, -0.11f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 12 - Back-top right 
	vec3(-0.106f, 0.15f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f), 	 vec3(0.f, 0.f, 1.f), // 13 - Front-top right
	vec3(-0.106f, 0.055f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 14 - Front-bottom right
	vec3(-0.106f, 0.055f, -0.11f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 15 - Back-bottom right
	// Top face of monitor shaft
	vec3(-0.136f, 0.15f, -0.11f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 16 - Back-top left 
	vec3(-0.136f, 0.15f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 17 - Front-top left
	vec3(-0.106f, 0.15f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 18 - Front-top right
	vec3(-0.106f, 0.15f, -0.11f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 19 - Back-top right
	// Bottom face of monitor shaft
	vec3(-0.136f, 0.055f, -0.11f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 20 - Back-bottom left 
	vec3(-0.106f, 0.055f, -0.11f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 21 - Back-bottom right
	vec3(-0.106f, 0.055f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 22 - Front-bottom right
	vec3(-0.136f, 0.055f, -0.09f), 	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f) // 23 - Front-bottom left
};
unsigned numOfMonitorShaftVerts = sizeof(monitorShaftVerts) / sizeof(Vertex);

GLuint monitorShaftIndices[] =
{
	// back face of monitor shaft
	0, 1, 2,
	2, 3, 0,

	// front face of monitor shaft
	4, 5, 6,
	6, 7, 4,

	// left face of monitor shaft
	8, 9, 10,
	10, 11, 8,

	// right face of monitor shaft
	12, 13, 14,
	14, 15, 12,

	// bottom of monitor shaft
	16, 17, 18,
	18, 19, 16,

	// top of monitor shaft
	20, 21, 22,
	22, 23, 20

};
unsigned numOfMonitorShaftIndices = sizeof(monitorShaftIndices) / sizeof(GLuint);

Vertex monitorArmVerts[] =
{
	// Back face of monitor shaft
	vec3(-0.136f, 0.13f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 0 - Back-top left 
	vec3(-0.106f, 0.13f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 1 - Back-top right
	vec3(-0.106f, 0.12f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 2 - Back-bottom right
	vec3(-0.136f, 0.12f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 3 - Back-bottom left
	// Front face of monitor shaft
	vec3(-0.136f, 0.15f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 4 - Front-top left
	vec3(-0.136f, 0.14f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 5 - Front-bottom left
	vec3(-0.106f, 0.14f, -0.07f), 	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 6 - Front-bottom right
	vec3(-0.106f, 0.15f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 7 - Front-top right
	// Left face of monitor shaft
	vec3(-0.136f, 0.13f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 8 - Back-top left 
	vec3(-0.136f, 0.12f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 9 - Back-bottom left
	vec3(-0.136f, 0.14f, -0.07f), 	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 10 - Front-bottom left
	vec3(-0.136f, 0.15f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f), 	 vec3(0.f, 0.f, 1.f), // 11 - Front-top left
	// Right face of monitor shaft
	vec3(-0.106f, 0.13f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 12 - Back-top right 
	vec3(-0.106f, 0.15f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f), 	 vec3(0.f, 0.f, 1.f), // 13 - Front-top right
	vec3(-0.106f, 0.14f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 14 - Front-bottom right
	vec3(-0.106f, 0.12f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 15 - Back-bottom right
	// Top face of monitor shaft
	vec3(-0.136f, 0.13f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 16 - Back-top left 
	vec3(-0.136f, 0.15f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 17 - Front-top left
	vec3(-0.106f, 0.15f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 18 - Front-top right
	vec3(-0.106f, 0.13f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 19 - Back-top right
	// Bottom face of monitor shaft
	vec3(-0.136f, 0.12f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 20 - Back-bottom left 
	vec3(-0.106f, 0.12f, -0.09f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 21 - Back-bottom right
	vec3(-0.106f, 0.14f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 22 - Front-bottom right
	vec3(-0.136f, 0.14f, -0.07f), 	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f) // 23 - Front-bottom left
};
unsigned numOfMonitorArmVerts = sizeof(monitorArmVerts) / sizeof(Vertex);

GLuint monitorArmIndices[] =
{
	// back face of monitor arm
	0, 1, 2,
	2, 3, 0,

	// front face of monitor arm
	4, 5, 6,
	6, 7, 4,

	// left face of monitor arm
	8, 9, 10,
	10, 11, 8,

	// right face of monitor arm
	12, 13, 14,
	14, 15, 12,

	// bottom of monitor arm
	16, 17, 18,
	18, 19, 16,

	// top of monitor arm
	20, 21, 22,
	22, 23, 20

};
unsigned numOfMonitorArmIndices = sizeof(monitorArmIndices) / sizeof(GLuint);

Vertex monitorFrameVerts[] =
{
	// Back face of monitor frame
	vec3(-0.2f, 0.18f, -0.07f),		vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 0 - Back-top left 
	vec3(-0.042f, 0.18f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 1 - Back-top right
	vec3(-0.042f, 0.07f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 2 - Back-bottom right
	vec3(-0.2f, 0.07f, -0.07f),		vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 3 - Back-bottom left
	// Front face of monitor frame
	vec3(-0.2f, 0.18f, -0.06f),		vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 4 - Front-top left
	vec3(-0.2f, 0.07f, -0.06f),		vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 5 - Front-bottom left
	vec3(-0.042f, 0.07f, -0.06f), 	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 6 - Front-bottom right
	vec3(-0.042f, 0.18f, -0.06f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 7 - Front-top right
	// Left face of monitor frame
	vec3(-0.2f, 0.18f, -0.07f),		vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 8 - Back-top left 
	vec3(-0.2f, 0.07f, -0.07f),		vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 9 - Back-bottom left
	vec3(-0.2f, 0.07f, -0.06f), 	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 10 - Front-bottom left
	vec3(-0.2f, 0.18f, -0.06f),		vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f), 	 vec3(0.f, 0.f, 1.f), // 11 - Front-top left
	// Right face of monitor frame
	vec3(-0.042f, 0.18f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 12 - Back-top right 
	vec3(-0.042f, 0.18f, -0.06f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f), 	 vec3(0.f, 0.f, 1.f), // 13 - Front-top right
	vec3(-0.042f, 0.07f, -0.06f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 14 - Front-bottom right
	vec3(-0.042f, 0.07f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 15 - Back-bottom right
	// Top face of monitor frame
	vec3(-0.2f, 0.18f, -0.07f),		vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 16 - Back-top left 
	vec3(-0.2f, 0.18f, -0.06f),		vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 17 - Front-top left
	vec3(-0.042f, 0.18f, -0.06f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 18 - Front-top right
	vec3(-0.042f, 0.18f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 19 - Back-top right
	// Bottom face of monitor frame
	vec3(-0.2f, 0.07f, -0.07f),		vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 20 - Back-bottom left 
	vec3(-0.042f, 0.07f, -0.07f),	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 21 - Back-bottom right
	vec3(-0.042f, 0.07f, -0.06f),	vec3(0.0f, 0.0f, 0.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 22 - Front-bottom right
	vec3(-0.2f, 0.07f, -0.06f), 	vec3(0.0f, 0.0f, 0.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f) // 23 - Front-bottom left
};
unsigned numOfMonitorFrameVerts = sizeof(monitorFrameVerts) / sizeof(Vertex);

GLuint monitorFrameIndices[] =
{
	// back face of monitor frame
	0, 1, 2,
	2, 3, 0,

	// front face of monitor frame
	4, 5, 6,
	6, 7, 4,

	// left face of monitor frame
	8, 9, 10,
	10, 11, 8,

	// right face of monitor frame
	12, 13, 14,
	14, 15, 12,

	// bottom of monitor frame
	16, 17, 18,
	18, 19, 16,

	// top of monitor frame
	20, 21, 22,
	22, 23, 20

};
unsigned numOfMonitorFrameIndices = sizeof(monitorFrameIndices) / sizeof(GLuint);

Vertex monitorScreenVerts[] =
{
	// Monitor screen
	vec3(-0.198f, 0.178f, -0.059f),		vec3(1.0f, 1.0f, 1.0f),		vec2(0.0f, 1.0f),	 vec3(0.f, 0.f, 1.f), // 0 - Top left 
	vec3(-0.198f, 0.072f, -0.059f),		vec3(1.0f, 1.0f, 1.0f),		vec2(0.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 1 - Bottom left
	vec3(-0.044f, 0.072f, -0.059f),		vec3(1.0f, 1.0f, 1.0f),		vec2(1.0f, 0.0f),	 vec3(0.f, 0.f, 1.f), // 2 - Bottom right
	vec3(-0.044f, 0.178f, -0.059f),		vec3(1.0f, 1.0f, 1.0f),		vec2(1.0f, 1.0f),	 vec3(0.f, 0.f, 1.f) // 3 - Top right
};
unsigned numOfMonitorScreenVerts = sizeof(monitorScreenVerts) / sizeof(Vertex);

GLuint monitorScreenIndices[] =
{
	// Screen
	0, 1, 2,
	2, 3, 0,
};
unsigned numOfMonitorScreenIndices = sizeof(monitorScreenIndices) / sizeof(GLuint);

namespace
{
	const char* WINDOW_TITLE = "Pyramid Fun";
	const int WINDOW_WIDTH = 1440;
	const int WINDOW_HEIGHT = 810;
	int fbW, fbH = 0; // framebuffer sizes
}

void key_callback(GLFWwindow* window, int key, int seconds, int action, int mods);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

bool keys[1024], mouseButtons[3];

// camera
Camera gCamera(glm::vec3(0.0f, 0.0f, 3.0f));
float gLastX = WINDOW_WIDTH / 2.0f;
float gLastY = WINDOW_HEIGHT / 2.0f;
bool gFirstMouse = true;

// timing
float gDeltaTime = 0.0f; // time between current frame and last frame
float gLastFrame = 0.0f;

vec3 cameraPosition = vec3(0.f, 0.f, 3.f);
vec3 target = vec3(0.f, 0.f, 0.f);
vec3 cameraDirection = normalize(cameraPosition - target);
vec3 worldUp = vec3(0.f, 1.f, 0.f);
vec3 cameraRight = normalize(cross(worldUp, cameraDirection));
vec3 cameraUp = normalize(cross(cameraRight, cameraDirection));
vec3 cameraFront = normalize(vec3(0.f, 0.f, -1.f));

int main()
{
	initWindowHints();
	if (!glfwInit())
	{
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, key_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);

	glfwMakeContextCurrent(window);

	initGLEW();

	GLuint shaderProgram;
	loadShaders(shaderProgram);
	if (!loadShaders)
	{
		glfwTerminate();
	}

	GLuint tabletopVAO, tabletopVBO, tabletopEBO,
		tableLegVAO, tableLegVBO, tableLegEBO, 
		monitorBaseVAO, monitorBaseVBO, monitorBaseEBO,
		monitorShaftVAO, monitorShaftVBO, monitorShaftEBO,
		monitorArmVAO, monitorArmVBO, monitorArmEBO,
		monitorFrameVAO, monitorFrameVBO, monitorFrameEBO,
		monitorScreenVAO, monitorScreenVBO, monitorScreenEBO
		;
	glGenBuffers(1, &tabletopVBO); // Create VBO
	glGenBuffers(1, &tabletopEBO); // Create EBO

	glGenBuffers(1, &tableLegVBO); // Create VBO
	glGenBuffers(1, &tableLegEBO); // Create EBO

	glGenBuffers(1, &monitorBaseVBO);
	glGenBuffers(1, &monitorBaseEBO);

	glGenBuffers(1, &monitorShaftVBO);
	glGenBuffers(1, &monitorShaftEBO);

	glGenBuffers(1, &monitorArmVBO);
	glGenBuffers(1, &monitorArmEBO);

	glGenBuffers(1, &monitorFrameVBO);
	glGenBuffers(1, &monitorFrameEBO);

	glGenBuffers(1, &monitorScreenVBO);
	glGenBuffers(1, &monitorScreenEBO);

	glGenVertexArrays(1, &tabletopVAO); // Create VOA
	glGenVertexArrays(1, &tableLegVAO); // Create VOA
	glGenVertexArrays(1, &monitorBaseVAO); // Create VOA
	glGenVertexArrays(1, &monitorShaftVAO); // Create VOA
	glGenVertexArrays(1, &monitorArmVAO); // Create VOA
	glGenVertexArrays(1, &monitorFrameVAO); // Create VOA
	glGenVertexArrays(1, &monitorScreenVAO); // Create VOA

	glBindVertexArray(tabletopVAO);

	// VBO and EBO Placed in User-Defined VAO
	glBindBuffer(GL_ARRAY_BUFFER, tabletopVBO); // Select VBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tabletopEBO); // Select EBO

	glBufferData(GL_ARRAY_BUFFER, sizeof(tabletopVerts), tabletopVerts, GL_STATIC_DRAW); // Load vertex attributes
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(tabletopIndices), tabletopIndices, GL_STATIC_DRAW); // Load indices 

	attribPointers();

	glBindVertexArray(0);

	glBindVertexArray(tableLegVAO);

	// VBO and EBO Placed in User-Defined VAO
	glBindBuffer(GL_ARRAY_BUFFER, tableLegVBO); // Select VBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tableLegEBO); // Select EBO

	glBufferData(GL_ARRAY_BUFFER, sizeof(tableLegVerts), tableLegVerts, GL_STATIC_DRAW); // Load vertex attributes
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(tableLegIndices), tableLegIndices, GL_STATIC_DRAW); // Load indices 

	attribPointers();

	glBindVertexArray(0);

	glBindVertexArray(monitorBaseVAO);

	// VBO and EBO Placed in User-Defined VAO
	glBindBuffer(GL_ARRAY_BUFFER, monitorBaseVBO); // Select VBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, monitorBaseEBO); // Select EBO

	glBufferData(GL_ARRAY_BUFFER, sizeof(monitorBaseVerts), monitorBaseVerts, GL_STATIC_DRAW); // Load vertex attributes
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(monitorBaseIndices), monitorBaseIndices, GL_STATIC_DRAW); // Load indices 

	attribPointers();

	glBindVertexArray(0);

	glBindVertexArray(monitorShaftVAO);

	// VBO and EBO Placed in User-Defined VAO
	glBindBuffer(GL_ARRAY_BUFFER, monitorShaftVBO); // Select VBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, monitorShaftEBO); // Select EBO

	glBufferData(GL_ARRAY_BUFFER, sizeof(monitorShaftVerts), monitorShaftVerts, GL_STATIC_DRAW); // Load vertex attributes
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(monitorShaftIndices), monitorShaftIndices, GL_STATIC_DRAW); // Load indices 

	attribPointers();

	glBindVertexArray(0);

	glBindVertexArray(monitorFrameVAO);

	// VBO and EBO Placed in User-Defined VAO
	glBindBuffer(GL_ARRAY_BUFFER, monitorFrameVBO); // Select VBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, monitorFrameEBO); // Select EBO

	glBufferData(GL_ARRAY_BUFFER, sizeof(monitorFrameVerts), monitorFrameVerts, GL_STATIC_DRAW); // Load vertex attributes
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(monitorFrameIndices), monitorFrameIndices, GL_STATIC_DRAW); // Load indices 

	attribPointers();

	glBindVertexArray(0);

	glBindVertexArray(monitorArmVAO);

	// VBO and EBO Placed in User-Defined VAO
	glBindBuffer(GL_ARRAY_BUFFER, monitorArmVBO); // Select VBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, monitorArmEBO); // Select EBO

	glBufferData(GL_ARRAY_BUFFER, sizeof(monitorArmVerts), monitorArmVerts, GL_STATIC_DRAW); // Load vertex attributes
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(monitorArmIndices), monitorArmIndices, GL_STATIC_DRAW); // Load indices 

	attribPointers();

	glBindVertexArray(0);

	glBindVertexArray(monitorScreenVAO);

	// VBO and EBO Placed in User-Defined VAO
	glBindBuffer(GL_ARRAY_BUFFER, monitorScreenVBO); // Select VBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, monitorScreenEBO); // Select EBO

	glBufferData(GL_ARRAY_BUFFER, sizeof(monitorScreenVerts), monitorScreenVerts, GL_STATIC_DRAW); // Load vertex attributes
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(monitorScreenIndices), monitorScreenIndices, GL_STATIC_DRAW); // Load indices 

	attribPointers();

	glBindVertexArray(0);

	int imageWidth, imageHeight;
	unsigned char* tabletopImage = SOIL_load_image("tabletopTexture.png", &imageWidth, &imageHeight, 0, SOIL_LOAD_RGBA);

	GLuint tabletopTexture;
	glGenTextures(1, &tabletopTexture);
	glBindTexture(GL_TEXTURE_2D, tabletopTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, tabletopImage);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(tabletopImage);
	textureParameters();
	glBindTexture(GL_TEXTURE_2D, tabletopTexture);

	unsigned char* tableLegImage = SOIL_load_image("tableLegTexture.png", &imageWidth, &imageHeight, 0, SOIL_LOAD_RGBA);

	GLuint tableLegTexture;
	glGenTextures(1, &tableLegTexture);
	glBindTexture(GL_TEXTURE_2D, tableLegTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, tableLegImage);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(tableLegImage);
	textureParameters();
	glBindTexture(GL_TEXTURE_2D, tableLegTexture);

	unsigned char* monitorTextureImage = SOIL_load_image("monitorTexture.png", &imageWidth, &imageHeight, 0, SOIL_LOAD_RGBA);

	GLuint monitorTexture; 
	glGenTextures(1, &monitorTexture);
	glBindTexture(GL_TEXTURE_2D, monitorTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, monitorTextureImage);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(monitorTextureImage);
	textureParameters();
	glBindTexture(GL_TEXTURE_2D, monitorTexture);

	unsigned char* monitorScreenImage = SOIL_load_image("monitorScreen.png", &imageWidth, &imageHeight, 0, SOIL_LOAD_RGBA);

	GLuint monitorScreenTexture;
	glGenTextures(1, &monitorScreenTexture);
	glBindTexture(GL_TEXTURE_2D, monitorScreenTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, monitorScreenImage);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(monitorScreenImage);
	textureParameters();
	glBindTexture(GL_TEXTURE_2D, monitorScreenTexture);

	glUniform1i(glGetUniformLocation(shaderProgram, "texture0"), 0);

	vec3 lightPos0(0.f, 2.f, 1.f);

	glUniform3fv(glGetUniformLocation(shaderProgram, "lightPos0"), 1, value_ptr(lightPos0));
	glUniform3fv(glGetUniformLocation(shaderProgram, "cameraPosition"), 1, value_ptr(cameraPosition));

	mat4 model(1.f);
	mat4 projection(1.f);
	mat4 view(1.f);

	model = scale(model, vec3(3.f));

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		gDeltaTime = currentFrame - gLastFrame;
		gLastFrame = currentFrame;

		initOpenGLOptions(window);

		glfwPollEvents();
		updateInput(window);

		glClearColor(0.6f, 0.6f, 0.6f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		glUseProgram(shaderProgram);

		view = gCamera.GetViewMatrix();

		projection = perspective(radians(gCamera.Zoom), (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 100.0f);

		if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
		{
			projection = ortho(-1.0f, 1.0f, -1.0f, 1.0f, 1.f, 100.0f);
		}

		// Get matrix's uniform location and set matrix
		GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
		GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
		GLint projLoc = glGetUniformLocation(shaderProgram, "projection");

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, value_ptr(projection));

		glActiveTexture(GL_TEXTURE0);

		glBindTexture(GL_TEXTURE_2D, tabletopTexture);

		glBindVertexArray(tabletopVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.f, 0.f, 0.f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfTabletopIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, tableLegTexture);
		// Table legs
		glBindVertexArray(tableLegVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.f, 0.f, 0.f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfTableLegIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, tableLegTexture);
		// Table legs
		glBindVertexArray(tableLegVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.575f, 0.f, 0.f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfTableLegIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, tableLegTexture);
		// Table legs
		glBindVertexArray(tableLegVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.575f, 0.f, 0.375f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfTableLegIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, tableLegTexture);
		// Table legs
		glBindVertexArray(tableLegVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.f, 0.f, 0.375f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfTableLegIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, monitorTexture);
		// Monitor Base
		glBindVertexArray(monitorBaseVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.f, 0.f, 0.f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfMonitorBaseIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, monitorTexture);
		// Monitor Base
		glBindVertexArray(monitorBaseVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.25f, 0.f, 0.f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfMonitorBaseIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, monitorTexture);
		// Monitor Shaft
		glBindVertexArray(monitorShaftVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.f, 0.f, 0.f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfMonitorBaseIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, monitorTexture);
		// Monitor Base
		glBindVertexArray(monitorShaftVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.25f, 0.f, 0.f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfMonitorBaseIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, monitorTexture);
		// Monitor arm
		glBindVertexArray(monitorArmVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.f, 0.f, 0.f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfMonitorBaseIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, monitorTexture);
		// Monitor Base
		glBindVertexArray(monitorArmVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.25f, 0.f, 0.f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfMonitorBaseIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, monitorTexture);
		// Monitor frame
		glBindVertexArray(monitorFrameVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.f, 0.f, 0.f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfMonitorBaseIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, monitorTexture);
		// Monitor Base
		glBindVertexArray(monitorFrameVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.25f, 0.f, 0.f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfMonitorBaseIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glBindTexture(GL_TEXTURE_2D, monitorScreenTexture);
		// Monitor screen
		glBindVertexArray(monitorScreenVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.f, 0.f, 0.f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfMonitorBaseIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, monitorScreenTexture);
		// Monitor Base
		glBindVertexArray(monitorScreenVAO);

		model = mat4(1.f);
		model = translate(model, vec3(0.25f, 0.f, 0.f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
		glDrawElements(GL_TRIANGLES, numOfMonitorBaseIndices, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		glUseProgram(0);
		glfwSwapBuffers(window);
		glFlush();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

void initWindowHints()
{
	glfwInit();

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
}

void initGLEW()
{
	//INIT GLEW (NEEDS WINDOW AND OPENGL CONTEXT)
	glewExperimental = GL_TRUE;

	//Error
	if (glewInit() != GLEW_OK)
	{
		std::cout << "ERROR::MAIN.CPP::GLEW_INIT_FAILED" << "\n";
		glfwTerminate();
	}
}

void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH)
{
	glViewport(0, 0, fbW, fbH);
};

bool loadShaders(GLuint& program)
{
	bool loadSuccess = true;
	char infoLog[512];
	GLint success;

	string temp = "";
	string src = "";

	ifstream in_file;

	in_file.open("vertex_shader_src.glsl");

	if (in_file.is_open())
	{
		while (getline(in_file, temp))
		{
			src += temp + "\n";
		}
	}
	else
	{
		cout << "ERROR::LOADING_VERTEX_SRC_FILE" << endl;
		loadSuccess = false;
	}

	in_file.close();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const GLchar* vertSrc = src.c_str();
	glShaderSource(vertexShader, 1, &vertSrc, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		cout << "ERROR::LOADSHADERS::COULD_NOT_COMPILE_VERTEX_SHADER" << endl;
		cout << infoLog << endl;
	}

	temp = "";
	src = "";

	in_file.open("fragment_shader_src.glsl");

	if (in_file.is_open())
	{
		while (getline(in_file, temp))
		{
			src += temp + "\n";
		}
	}
	else
	{
		cout << "ERROR::LOADING_FRAGMENT_SRC_FILE" << endl;
		loadSuccess = false;
	}

	in_file.close();

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* fragSrc = src.c_str();
	glShaderSource(fragmentShader, 1, &fragSrc, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		cout << "ERROR::LOADSHADERS::COULD_NOT_COMPILE_FRAGMENT_SHADER" << endl;
		cout << infoLog << endl;
	}


	program = glCreateProgram();

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		cout << "ERROR::LOADSHADERS::COULD_NOT_LINK_PROGRAM" << endl;
		cout << infoLog << endl;
	}

	glUseProgram(0);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return loadSuccess;
}

void initOpenGLOptions(GLFWwindow* window)
{
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
}

void attribPointers()
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(3);

}

void textureParameters()
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
}

void updateInput(GLFWwindow* window)
{
	static const float cameraSpeed = 2.5f;

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		gCamera.ProcessKeyboard(FORWARD, gDeltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		gCamera.ProcessKeyboard(BACKWARD, gDeltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		gCamera.ProcessKeyboard(LEFT, gDeltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		gCamera.ProcessKeyboard(RIGHT, gDeltaTime);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		gCamera.ProcessKeyboard(UP, gDeltaTime);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		gCamera.ProcessKeyboard(DOWN, gDeltaTime);
}

void key_callback(GLFWwindow* window, int key, int seconds, int action, int mods)
{
	// Close window
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	// Assign true to Element ASCII if key pressed
	if (action == GLFW_PRESS)
		keys[key] = true;
	else if (action == GLFW_RELEASE) // Assign false to Element ASCII if key released
		keys[key] = false;
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	gCamera.ProcessMouseScroll(yoffset);
}
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (gFirstMouse)
	{
		gLastX = xpos;
		gLastY = ypos;
		gFirstMouse = false;
	}

	float xoffset = xpos - gLastX;
	float yoffset = gLastY - ypos; // reversed since y-coordinates go from bottom to top

	gLastX = xpos;
	gLastY = ypos;

	gCamera.ProcessMouseMovement(xoffset, yoffset);
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	switch (button)
	{
	case GLFW_MOUSE_BUTTON_LEFT:
	{
		if (action == GLFW_PRESS)
			cout << "Left mouse button pressed" << endl;
		else
			cout << "Left mouse button released" << endl;
	}
	break;

	case GLFW_MOUSE_BUTTON_MIDDLE:
	{
		if (action == GLFW_PRESS)
			cout << "Middle mouse button pressed" << endl;
		else
			cout << "Middle mouse button released" << endl;
	}
	break;

	case GLFW_MOUSE_BUTTON_RIGHT:
	{
		if (action == GLFW_PRESS)
			cout << "Right mouse button pressed" << endl;
		else
			cout << "Right mouse button released" << endl;
	}
	break;

	default:
		cout << "Unhandled mouse button event" << endl;
		break;
	}
}