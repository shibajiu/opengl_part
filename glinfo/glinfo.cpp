// glinfo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
using namespace glm;

GLFWwindow* window;

// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

static const GLfloat g_vertex_buffer_data[] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f, 0.5f, 0.0f
};

static const GLfloat g_vertex_buffer_data_cube[] = {
	-1.0f, -1.0f, -1.0f, // triangle 1 : begin
	-1.0f, -1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f, // triangle 1 : end
	1.0f, 1.0f, -1.0f, // triangle 2 : begin
	-1.0f, -1.0f, -1.0f,
	-1.0f, 1.0f, -1.0f, // triangle 2 : end
	1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f, 1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, -1.0f,
	1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f, -1.0f, 1.0f,
	1.0f, -1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f, 1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, -1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, -1.0f,
	-1.0f, 1.0f, -1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, -1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f, -1.0f, 1.0f
};

static const GLfloat vertices[] = {
	0.5f, 0.5f, 0.0f,  // Top Right
	0.5f, -0.5f, 0.0f,  // Bottom Right
	-0.5f, -0.5f, 0.0f,  // Bottom Left
	-0.5f, 0.5f, 0.0f   // Top Left 
};

static const GLuint indices[] = {  // Note that we start from 0!
	0, 1, 3,   // First Triangle
	1, 2, 3    // Second Triangle
};

// One color for each vertex. They were generated randomly.
static const GLfloat g_color_buffer_data[] = {
	0.583f, 0.771f, 0.014f,
	0.609f, 0.115f, 0.436f,
	0.327f, 0.483f, 0.844f,
	0.822f, 0.569f, 0.201f,
	0.435f, 0.602f, 0.223f,
	0.310f, 0.747f, 0.185f,
	0.597f, 0.770f, 0.761f,
	0.559f, 0.436f, 0.730f,
	0.359f, 0.583f, 0.152f,
	0.483f, 0.596f, 0.789f,
	0.559f, 0.861f, 0.639f,
	0.195f, 0.548f, 0.859f,
	0.014f, 0.184f, 0.576f,
	0.771f, 0.328f, 0.970f,
	0.406f, 0.615f, 0.116f,
	0.676f, 0.977f, 0.133f,
	0.971f, 0.572f, 0.833f,
	0.140f, 0.616f, 0.489f,
	0.997f, 0.513f, 0.064f,
	0.945f, 0.719f, 0.592f,
	0.543f, 0.021f, 0.978f,
	0.279f, 0.317f, 0.505f,
	0.167f, 0.620f, 0.077f,
	0.347f, 0.857f, 0.137f,
	0.055f, 0.953f, 0.042f,
	0.714f, 0.505f, 0.345f,
	0.783f, 0.290f, 0.734f,
	0.722f, 0.645f, 0.174f,
	0.302f, 0.455f, 0.848f,
	0.225f, 0.587f, 0.040f,
	0.517f, 0.713f, 0.338f,
	0.053f, 0.959f, 0.120f,
	0.393f, 0.621f, 0.362f,
	0.673f, 0.211f, 0.457f,
	0.820f, 0.883f, 0.371f,
	0.982f, 0.099f, 0.879f
};

static const char* vertexshadersource =
"#version 440 core\n"
"layout(location = 0) in vec3 vertexPosition_modelspace;\n"
"layout(location = 1) in vec3 vertexColor;\n"
"uniform mat4 mvp;\n"
"out vec3 fragcolor;\n"
"void main(){\n"
"gl_Position = mvp*vec4(vertexPosition_modelspace,1.0f);\n"
"fragcolor=vertexColor;\n"
"}"
;

static const char* fragshadersource =
"#version 440 core\n"
"in vec3 fragcolor;\n"
"out vec3 color;\n"
"void main(){\n"
"color=fragcolor;\n"
"}"
;

int _tmain(int argc, _TCHAR* argv[]){

	regex("^(.+)/(.+\.obj)$");

	if (glfwInit() == GLFW_FALSE){
		fprintf_s(stderr, "failed to init glfw\n");
		glfwTerminate();
	}
	window = glfwCreateWindow(800, 600, "shader", NULL, NULL);
	if (!window){
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetErrorCallback(
		[](int error, const char * desc){
		fprintf_s(stderr, "ERROR:%s\n", desc); }
	);
	glfwSetDropCallback(
		window,
		[](GLFWwindow* win, int count, const char * path[]){}
	);
	static double xold = 0, yold = 0, xmov = 0;
	glfwSetCursorPosCallback(
		window,
		[](GLFWwindow* win, double x, double y){
		xmov += x - xold; 
		xold = x; }
	);
	glfwSetKeyCallback(
		window,
		[](GLFWwindow* win, int key, int scancode, int action, int mods){}
	);

	if (glewInit() == GLEW_OK)//init glew after setting glfw
		printf_s("glew initialized\n");
	else
		fprintf_s(stderr, "failed to initialize glew\n");

	GLuint vao,vbo,vshader,fshader,shaderprogram,ebo,colorbuffer;
	GLint success;
	GLchar infolog[512];

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_cube), g_vertex_buffer_data_cube, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), NULL);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(1); 
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),NULL);	

	glBindVertexArray(0);

	vshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vshader, 1, &vertexshadersource, NULL);
	glCompileShader(vshader);
	glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
	if (!success){
		glGetShaderInfoLog(vshader, 512, NULL, infolog);
		fprintf_s(stderr,"vshader:%s", infolog);
	}

	fshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fshader, 1, &fragshadersource, NULL);
	glCompileShader(fshader);
	glGetShaderiv(fshader, GL_COMPILE_STATUS, &success);
	if (!success){
		glGetShaderInfoLog(fshader, 512, NULL, infolog);
		fprintf_s(stderr, "fshader:%s", infolog);
	}

	shaderprogram = glCreateProgram();
	glAttachShader(shaderprogram, vshader);
	glAttachShader(shaderprogram, fshader);
	glLinkProgram(shaderprogram);
	glGetProgramiv(shaderprogram, GL_LINK_STATUS, &success);
	if (!success){
		glGetProgramInfoLog(shaderprogram, 512, NULL, infolog);
		fprintf_s(stderr, "shaderprogram:%s", infolog);
	}
	glDetachShader(shaderprogram, vshader);
	glDetachShader(shaderprogram, fshader);
	
/*
	map<string, int> m;
	m["hello"] = 0;
	m["world"] = 1;
	m["zzfun"] = 2;
	for (auto it = m.begin(); it != m.end(); ++it)
		cout << it->first << "\t" << it->second << endl;
	cout << "------------------------------------------------------------" << endl;*/

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClearColor(0, 0, 0, 0);

	double lasttime = 0;
	vec3 rotate_axis(0.0, 1.0, 0.0);

	while (!glfwWindowShouldClose(window)){
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		double now = glfwGetTime();
		float pass = lasttime ? (now - lasttime) : 0;
		lasttime = !lasttime ? now : lasttime;
		
		mat4 modelrotate = rotate(pass,rotate_axis);
		mat4 projectionmatrix = perspective(75.0f, 4.0f / 3.0f, 0.1f, 500.0f);
		mat4 viewmatrix = lookAtRH(vec3(4+xmov, 5, 7), vec3(0, 0, 0), vec3(0, 1, 0));
		mat4 VPmatrix = projectionmatrix*viewmatrix*modelrotate;
		
		glViewport(0, 0, 800, 600);
		glBindVertexArray(vao);
		glUseProgram(shaderprogram);
		glProgramUniformMatrix4fv(shaderprogram, glGetUniformLocation(shaderprogram, "mvp"), 1, GL_FALSE, (float*)&VPmatrix);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glUseProgram(0);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	//system("pause");
	return 0;
}