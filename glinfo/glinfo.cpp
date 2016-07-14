
#include "stdafx.h"

using namespace std;
using namespace glm;

// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

static const GLfloat g_vertex_buffer_data1[] = {
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f, 0.5f, 0.0f
};

static const GLfloat  vertices_normals[] = {
	//aft
	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
	-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
	0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
	0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
	0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
	-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,
	//bow
	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
	0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
	-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
	//starboard
	-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
	-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
	-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,
	//port
	0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
	0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
	0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
	//sea
	0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
	0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
	-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
	-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,
	-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
	0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,
	//sky
	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
	-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
	0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
	0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
	0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
	-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
};

static const GLfloat g_vertex_buffer_data_cube1[] = {
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

static const GLfloat vertices1[] = {
	0.5f, 0.5f, 0.0f,  // Top Right
	0.5f, -0.5f, 0.0f,  // Bottom Right
	-0.5f, -0.5f, 0.0f,  // Bottom Left
	-0.5f, 0.5f, 0.0f   // Top Left 
};

static const GLuint indices1[] = {  // Note that we start from 0!
	0, 1, 3,   // First Triangle
	1, 2, 3    // Second Triangle
};

// One color for each vertex. They were generated randomly.
static const GLfloat g_color_buffer_data1[] = {
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

static const char* vertexshadersource1 =
"#version 440 core\n"
"layout(location = 0) in vec3 vertexPosition_modelspace;\n"
"layout(location = 1) in vec3 vertexColor;\n"
"layout(location = 2) in vec3 vertexNormal;\n"

"uniform mat4 mvp;\n"

"out vec3 objectcolor;\n"

"void main(){\n"
	"gl_Position = mvp*vec4(vertexPosition_modelspace,1.0f);\n"
	"objectcolor = vertexColor;\n"
"}"
;

static const char* fragshadersource1 =
"#version 440 core\n"
"uniform vec4 lightcolor;\n"

"in vec3 objectcolor;\n"

"out vec4 color;\n"

"void main(){\n"
	"float ambientStrength = 0.3f;\n"
	"color = vec4(objectcolor,1.0);\n"
	"color = ambientStrength*lightcolor*color;\n"
"}"
;

static const char* vertexshadersource2 =
"#version 440 core\n"
"layout(location = 0) in vec3 vertexPosition_modelspace;\n"
"layout(location = 1) in vec3 vertexNormal;\n"
"layout(location = 2) in vec3 vertexColor;\n"

"uniform mat4 mvp;\n"
"uniform mat4 model;\n"

"out vec3 normal;\n"
"out vec3 FragPos;\n"
"out vec3 objectcolor;\n"

"void main(){\n"
"gl_Position = mvp * vec4(vertexPosition_modelspace,1.0f);\n"
"normal = mat3(model) * vertexNormal;\n"
"FragPos = vec3(model * vec4(vertexPosition_modelspace, 1.0f));\n"
//"if(vertexColor.r+vertexColor.g+vertexColor.b>=0){objectcolor = vertexColor;\n"
"objectcolor = vertexColor;\n"
"if(vertexColor.r+vertexColor.g+vertexColor.b<0){objectcolor = vec3(0.5*abs(vertexColor.r),0.1,0.5*abs(vertexColor.b));}\n"
"if(vertexColor.g<0){objectcolor = vec3(1,1,1);}\n"
"}"
;

static const char* fragshadersource2 =
"#version 440 core\n"
"uniform vec3 lightcolor;\n"
"uniform vec3 lightDir;\n"
"uniform vec3 viewPos;\n"

"in vec3 normal;\n"
"in vec3 FragPos;\n"
"in vec3 objectcolor;\n"

"out vec4 color;\n"

"void main(){\n"
	"vec3 norm = normalize(normal);\n"
	//ambient light
	"float ambientStrength = 0.3f;\n"
	//diffuse light
	"float diffuse = max(dot(norm,normalize(lightDir)),0.0);\n"
	//specular light
	"float specularStrength = 0.5f;\n"
	"vec3 viewDir = normalize(viewPos - FragPos);\n"
	"vec3 reflectDir = reflect(-lightDir, norm);\n"
	"float reflect = pow(max(dot(reflectDir,viewDir),0.0),32);\n"
	
	//"vec3 objectcolor = vec3(1,0,0);\n"
	"vec3 color_temp = (ambientStrength+diffuse+specularStrength*reflect)*lightcolor*objectcolor;\n"
	"color = vec4(color_temp,1.0);\n"
	//"color = vec4(1,1,1,1.0);\n"
"}"
;

static enum FILE_l{ FILE_NON, FILE_V, FILE_OBJ, FILE_VSHADER, FILE_FSHADER, FILE_PROGRAM };
static double xold = 0, yold = 0, xmov = 0;
static GLuint obj_vao = NULL;
static map<int, bool >keystatus;
static GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
static GLfloat lastFrame = 0.0f;  	// Time of last frame
vec3 cameraPos = vec3(0.0f, 0.0f, 7.0f);
vec3 cameraFront = vec3(0.0f, 0.0f, -1.0f);
vec3 cameraUp = vec3(0.0f, 1.0f, 0.0f);          

GLFWwindow* window;
static bool isFullscreen = false;

int init(void);
GLuint load_shader(const char* path, const char* path2);
int drop_file(string s);
void do_movement();

//load obj file and create vao, just use func(creatvao_obj)
class objload{
private:
	struct Vertex{//vertex
		float x, y, z;
		Vertex(){}
		Vertex(float xi, float yi, float zi) :x(xi), y(yi), z(zi){}
	};

	struct FaceIndex{//face index
		GLuint a, b, c;
		GLuint auv, buv, cuv;
		GLuint an, bn, cn;

		FaceIndex(){}
		FaceIndex(GLuint x, GLuint y, GLuint z) :a(x), b(y), c(z){}
		FaceIndex(GLuint x[3]) :a(x[0]), b(x[1]), c(x[2]){}
		FaceIndex(GLuint x[3], GLuint y[3], GLuint z[3]) :
			a(x[0]), b(x[1]), c(x[2]),
			auv(y[0]), buv(y[1]), cuv(y[2]),
			an(z[0]), bn(z[1]), cn(z[2]){}
	};

	struct Normal{//normal
		float x, y, z;
		Normal(){}
		Normal(float a, float b, float c) :x(a), y(b), z(c){}
	};

	struct Texture{//Texture
		float u,v;
		Texture(){}
		Texture(float a, float b) :u(a), v(b){}
	};

	vector<Vertex> Vertices;
	vector<FaceIndex> Indices;
	vector<Normal> Normals;
	vector<Texture> Textures;

	GLuint* obj_indexbuffer;
	float* obj_vertexbuffer, *obj_normalbuffer;
	int obj_indexbuffer_size, obj_vertexbuffer_size, obj_normalbuffer_size;

	void load_obj(const char* path){
		ifstream obj(path);
		if (!obj.is_open()){
			fprintf_s(stderr, "cannot open file\n");
			return;
		}
		char buffer[128];
		float f1, f2, f3;
		GLuint i0[3], i1[3], i2[3];
		while (!obj.eof()){
			obj.getline(buffer, 128, '\n');
			if (buffer[0] == 'v' && (buffer[1] == ' ' || buffer[1] == 32)){
				if (sscanf_s(buffer, "v %f %f %f", &f1, &f2, &f3) == 3){
					Vertices.push_back(Vertex(f1, f2, f3));
				}
				else{
					fprintf(stderr, "ERROR: vertex not in wanted format in OBJLoader\n");
				}
			}
			else if (buffer[0] == 'f' && (buffer[1] == ' ' || buffer[1] == 32)){
				if (sscanf_s(buffer, "f %d %d %d", &i0[0], &i0[1], &i0[2]) == 3){
					Indices.push_back(FaceIndex(i0));
				}
				else if (sscanf_s(buffer, "f %d/%d/%d %d/%d/%d %d/%d/%d", 
											&i0[0], &i1[0], &i2[0],
											&i0[1], &i1[1], &i2[1], 
											&i0[2], &i1[2], &i2[2]) == 9){
					Indices.push_back(FaceIndex(i0, i1, i2));
				}
				else{
					fprintf(stderr, "ERROR: FaceIndex not in wanted format in OBJLoader\n");
				}
			}
			else if (buffer[0] == 'n' && (buffer[1] == ' ' || buffer[1] == 32)){
				if (sscanf_s(buffer, "n %f %f %f", &f1, &f2, &f3) == 3){
					Normals.push_back(Normal(f1, f2, f3));
				}
				else{
					fprintf(stderr, "ERROR: Normal not in wanted format in OBJLoader\n");
				}
			}
			else if ((buffer[0] == 'v' && buffer[1] == 'n') && (buffer[2] == ' ' || buffer[2] == 32)){
				if (sscanf_s(buffer, "vn %f %f %f", &f1, &f2, &f3) == 3){
					Normals.push_back(Normal(f1, f2, f3));
				}
				else{
					fprintf(stderr, "ERROR: Normal not in wanted format in OBJLoader\n");
				}
			}
			else if ((buffer[0] == 'v' && buffer[1] == 't') && (buffer[2] == ' ' || buffer[2] == 32)){
				if (sscanf_s(buffer, "vt %f %f", &f1, &f2) == 2){
					Textures.push_back(Texture(f1, f2));
				}
				else{
					fprintf(stderr, "ERROR: Texture not in wanted format in OBJLoader\n");
				}
			}
		}
		obj.close();
	}

	GLint load_obj_struct_itr(const char* path, int flag = FILE_V);

public:

	GLuint creatvao_obj(const char* path, int flag = FILE_V);

	~objload(){
		Vertices.clear();
		Indices.clear();
		Normals.clear();
		delete[] obj_vertexbuffer;
		delete[] obj_indexbuffer;
		delete[] obj_normalbuffer;
	}
};

GLint objload::load_obj_struct_itr(const char* path, int flag){

	load_obj(path);
	int iv = 0;
	printf_s("Loading obj file...\n");
	if (!Vertices.size() || !Indices.size())
		goto jump1;

	if (flag == FILE_NON){
		obj_vertexbuffer_size = Vertices.size() * 3;
		obj_vertexbuffer = new float[obj_vertexbuffer_size];
		for (vector<Vertex>::const_iterator ite = Vertices.begin(); ite != Vertices.end(); ++ite){
			obj_vertexbuffer[iv * 3] = ite->x;
			obj_vertexbuffer[iv * 3 + 1] = ite->y;
			obj_vertexbuffer[iv * 3 + 2] = ite->z;
			iv++;
		}
		printf_s("vertexbuffer loaded\n");

		obj_normalbuffer_size = Normals.size() * 3;
		obj_normalbuffer = new float[obj_normalbuffer_size];
		iv = 0;
		for (vector<Normal>::const_iterator ite = Normals.begin(); ite != Normals.end(); ++ite){
			obj_normalbuffer[iv * 3] = ite->x;
			obj_normalbuffer[iv * 3 + 1] = ite->y;
			obj_normalbuffer[iv * 3 + 2] = ite->z;
			iv++;
		}
		printf_s("normalbuffer loaded\n");
		printf_s("obj file loaded\n");
	}

	iv = 0;
	obj_indexbuffer_size = Indices.size() * 3;
	obj_indexbuffer = new GLuint[obj_indexbuffer_size];
	for (vector<FaceIndex>::const_iterator ite = Indices.begin(); ite != Indices.end(); ++ite){
		obj_indexbuffer[iv * 3] = ite->a;
		obj_indexbuffer[iv * 3 + 1] = ite->b;
		obj_indexbuffer[iv * 3 + 2] = ite->c;
		iv++;
	}
jump1:
	printf_s("indexbuffer loaded: vertices:%d,normals:%d,faces:%d\n", Vertices.size(), Normals.size(), Indices.size());
	return (!Vertices.size() || !Indices.size());

}

GLuint objload::creatvao_obj(const char* path, int flag){
	GLuint vao_l, vbo_l, ebo_l, nbo_l;
	if (load_obj_struct_itr(path, flag)){
		fprintf_s(stderr, "obj err\n");
		return 0;
	}		

	if (flag == FILE_NON){

		glGenVertexArrays(1, &vao_l);
		glBindVertexArray(vao_l);

		glEnableVertexAttribArray(0);
		glGenBuffers(1, &vbo_l);
		glBindBuffer(GL_ARRAY_BUFFER, vbo_l);
		glBufferData(GL_ARRAY_BUFFER, sizeof(obj_vertexbuffer), obj_vertexbuffer, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), NULL);

		glGenBuffers(1, &ebo_l);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_l);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(obj_indexbuffer), obj_indexbuffer, GL_STATIC_DRAW);

		glBindVertexArray(0);
	}
	else if (flag == FILE_V){

		glGenVertexArrays(1, &vao_l);
		glBindVertexArray(vao_l);

		glEnableVertexAttribArray(0);
		glGenBuffers(1, &vbo_l);
		glBindBuffer(GL_ARRAY_BUFFER, vbo_l);
		glBufferData(GL_ARRAY_BUFFER, Vertices.size()* sizeof(Vertex), &Vertices[0], GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, x));

		glGenBuffers(1, &ebo_l);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_l);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(obj_indexbuffer), obj_indexbuffer, GL_STATIC_DRAW);
		
		printf_s("sorting normals....");
		vector<Normal>sequentialNormals(Vertices.size());
		vector<GLushort> temp_index;
		for (auto ite = Indices.begin(); ite != Indices.end(); ++ite){
			if (UFIND_INDEX(temp_index, ite->a)){
				sequentialNormals[ite->a - 1] = Normals[ite->an - 1];
				temp_index.push_back(ite->a);
			}
			if (UFIND_INDEX(temp_index, ite->b)){
				sequentialNormals[ite->b - 1] = Normals[ite->bn - 1];
				temp_index.push_back(ite->b);
			}
			if (UFIND_INDEX(temp_index, ite->c)){
				sequentialNormals[ite->c - 1] = Normals[ite->cn - 1];
				temp_index.push_back(ite->c);
			}			

			//cout << temp_index.size() << "	";
			if (temp_index.size() == Vertices.size()){
				printf_s("complete\n");
				break;
			}
		}

		glEnableVertexAttribArray(1);
		glGenBuffers(1, &nbo_l);
		glBindBuffer(GL_ARRAY_BUFFER, nbo_l);
		glBufferData(GL_ARRAY_BUFFER, sequentialNormals.size()* sizeof(Normal), &sequentialNormals[0], GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Normal), (void *)offsetof(Normal, x));

		glBindVertexArray(0);

		vector<Normal>().swap(sequentialNormals);
		vector<GLushort>().swap(temp_index);
	}
	return vao_l;
}


class GL{
private:
	GLuint vao, vbo, nbo, vshader, fshader, shaderprogram, ebo, colorbuffer;
	GLint success;
	GLchar infolog[512];
	vector<vec3> vertexbuffer;

	void creatProgram(char* vs, char* fs){
		vshader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vshader, 1, &vs, NULL);
		glCompileShader(vshader);
		glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
		if (!success){
			glGetShaderInfoLog(vshader, 512, NULL, infolog);
			fprintf_s(stderr, "vshader:%s", infolog);
		}

		fshader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fshader, 1, &fs, NULL);
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
		glGetProgramiv(shaderprogram, GL_ACTIVE_UNIFORMS, &success);
		printf_s("number:%d\n", success);
		glDetachShader(shaderprogram, vshader);
		glDetachShader(shaderprogram, fshader);
	}
public:
	GL(
		GLfloat* g_vertex_buffer_data_cube,
		size_t vertex_size,
		GLuint* indices,
		size_t index_size,
		GLfloat* g_color_buffer_data,
		size_t color_size,
		char* vs,
		char* fs){

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glEnableVertexAttribArray(0);
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertex_size, g_vertex_buffer_data_cube, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), NULL);

		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_size, indices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(1);
		glGenBuffers(1, &colorbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glBufferData(GL_ARRAY_BUFFER, color_size, g_color_buffer_data, GL_STATIC_DRAW);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), NULL);

		//glEnableVertexAttribArray(2);
		//glGenBuffers(GL_ARRAY_BUFFER, &nbo);
		//glBindBuffer(GL_ARRAY_BUFFER, nbo);
		//glBufferData(GL_ARRAY_BUFFER,sizof)

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		creatProgram(vs, fs);
	}

	GL(
		GLfloat v_n[],
		size_t vertex_size,
		char* vs,
		char* fs){

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glEnableVertexAttribArray(0);
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertex_size, v_n, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
		
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		creatProgram(vs, fs);
	}

	void display(mat4 VPmatrix, mat4 modelrotate, vec3 eye){
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport(0, 0, 800, 600);
		glBindVertexArray(vao);
		glUseProgram(shaderprogram);
		glProgramUniformMatrix4fv(shaderprogram, glGetUniformLocation(shaderprogram, "mvp"), 1, GL_FALSE, (float*)&VPmatrix);//load mvp
		glProgramUniformMatrix4fv(shaderprogram, glGetUniformLocation(shaderprogram, "model"), 1, GL_FALSE, (float*)&modelrotate);
		glProgramUniform3f(shaderprogram, glGetUniformLocation(shaderprogram, "lightDir"), 1, 0, 0);
		glProgramUniform3f(shaderprogram, glGetUniformLocation(shaderprogram, "viewPos"), eye.x, eye.y, eye.z);
		glProgramUniform3f(shaderprogram, glGetUniformLocation(shaderprogram, "lightcolor"), 1, 1, 1);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glUseProgram(0);
	}

	GLuint get_vao(){
		return vao;
	}

	GLuint get_program(){
		return shaderprogram;
	}
};


int _tmain(int argc, _TCHAR* argv[]){
	cout << sizeof(vertices_normals)/sizeof(GLfloat)<< endl;
	init();
	GL *gl = new GL(const_cast<GLfloat*> (g_vertex_buffer_data_cube1),
					sizeof(g_vertex_buffer_data_cube1),
					const_cast<GLuint*>(indices1),
					sizeof(indices1),
					const_cast<GLfloat*>(g_color_buffer_data1),
					sizeof(g_color_buffer_data1),
					const_cast<char*>(vertexshadersource1),
					const_cast<char*>(fragshadersource1)
					);

	GL gl_n(const_cast<GLfloat*> (vertices_normals), 
			sizeof(vertices_normals), 
			const_cast<char*>(vertexshadersource2),
			const_cast<char*>(fragshadersource2)
			);
	
	int success;
	glGetProgramiv(gl->get_program(), GL_ACTIVE_UNIFORMS, &success);
	printf_s("number:%d\n", success);
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClearColor(0, 0, 0, 0);

	double lasttime = 0;
	vec3 rotate_axis(0.0, 1.0, 0.0);
	//glEnable(GL_CULL_FACE);

	//mainloop
	while (!glfwWindowShouldClose(window)){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		GLfloat grey[] = { 0.8, 0.8, 0.8, 1 };
		/*double now = glfwGetTime();
		float pass = lasttime ? (now - lasttime) : 0;
		lasttime = !lasttime ? now : lasttime;*/

		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glfwPollEvents();
		do_movement();
		//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,grey);
		//mat4 modelrotate = rotate(pass, rotate_axis);
		mat4 modelrotate = mat4(1);
		mat4 projectionmatrix = perspective(75.0f, 4.0f / 3.0f, 0.1f, 500.0f);
		//mat4 viewmatrix = lookAtRH(vec3(4 + xmov, 5, 7), vec3(0, 0, 0), vec3(0, 1, 0));
		mat4 viewmatrix = lookAt(cameraPos, cameraPos+cameraFront, cameraUp);
		mat4 VPmatrix = projectionmatrix*viewmatrix*modelrotate;//mvp matrix

		//gl->display(VPmatrix);
		gl_n.display(VPmatrix, modelrotate, cameraPos);

		glfwSwapBuffers(window);
	}
	delete gl;
	glfwTerminate();
	//system("pause");
	return 0;
}

int drop_file(string s){
	
	auto reg = regex("([0-9a-zA-Z\_\-]+?)\.(obj|vshader|fshader)$");
	smatch sm;
	//use regex to check the dropped file
	if (regex_search(s, sm, reg)){
		if (sm[2] == "obj"){
			glfwSetWindowTitle(window, "obj");
			for (auto x = sm.begin(); x != sm.end(); x++)
				cout << x->str() << endl;
			return FILE_OBJ;
		}
		else if (sm[2] == "vshader"){
			return FILE_VSHADER;
		}
		else if (sm[2] == "fshader"){
			return FILE_FSHADER;
		}
		else
			printf_s("non\n");
		return FILE_NON;
	}
	else
		printf_s("non1\n");
	return FILE_NON;
}

int init(void){

	keystatus[GLFW_KEY_W] = false;
	keystatus[GLFW_KEY_A] = false;
	keystatus[GLFW_KEY_S] = false;
	keystatus[GLFW_KEY_D] = false;
	keystatus[GLFW_KEY_U] = false;
	keystatus[GLFW_KEY_J] = false;

	static objload Obj;

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
		fprintf_s(stderr, "ERROR:%s\n", desc);
	}
	);

	glfwSetDropCallback(
		window,
		[](GLFWwindow* win, int count, const char * path[]){
		int len = GET_ARRAY_LEN(path), f, path_v = -1, path_f = -1;

		for (int p = 0; p < len; ++p){
			switch (drop_file(path[p])){
			case FILE_NON:
				printf_s("File not found\n");
				break;

			case FILE_OBJ:
				printf_s("Found obj file\n");
				obj_vao = Obj.creatvao_obj(path[p]);
				break;

			case FILE_VSHADER:
				printf_s("Found vshader file\n");
				if (path_f != -1)
					load_shader(path[p], path[path_f]);
				else
					path_v = p;
				break;

			case FILE_FSHADER:
				printf_s("Found fshader file\n");
				if (path_v != -1)
					load_shader(path[path_v], path[p]);
				else
					path_f = p;
				break;

			default:
				break;
			}
		}
	}
	);
	glfwSetCursorPosCallback(
		window,
		[](GLFWwindow* win, double x, double y){
		xmov += x - xold;
		xold = x;
	}
	);
	glfwSetKeyCallback(
		window,
		[](GLFWwindow* win, int key, int scancode, int action, int mods){
		switch (key){
		case GLFW_KEY_F:
			if (action == GLFW_PRESS){
				glfwSetWindowMonitor(window, isFullscreen ? NULL : glfwGetPrimaryMonitor(), 0, 0, 800, 600, GLFW_DONT_CARE);
				isFullscreen = !isFullscreen;
			}
			break;

		case GLFW_KEY_W:
		case GLFW_KEY_A:
		case GLFW_KEY_S:
		case GLFW_KEY_D:
		case GLFW_KEY_U:
		case GLFW_KEY_J:
			if (action == GLFW_PRESS)
				keystatus[key] = true;
			if (action == GLFW_RELEASE)
				keystatus[key] = false;
			break;

		case GLFW_KEY_R:
			cameraPos = vec3(0, 0, 7);
			break;		
			
		default:
			break;

		}
	}
	);
	//init glew after setting glfw
	if (glewInit() == GLEW_OK)
		printf_s("glew initialized\n");
	else
		fprintf_s(stderr, "failed to initialize glew\n");
	return 0;
}

void do_movement()
{
	// Camera controls
	GLfloat cameraSpeed = 5.0f * deltaTime;
	if (keystatus[GLFW_KEY_W])
		cameraPos += cameraSpeed * cameraFront;
	else if (keystatus[GLFW_KEY_S])
		cameraPos -= cameraSpeed * cameraFront;
	else if (keystatus[GLFW_KEY_A])
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	//cameraPos -= vec3(1, 0, 0)*cameraSpeed;
	else if (keystatus[GLFW_KEY_D])
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	//cameraPos += vec3(1, 0, 0)*cameraSpeed;
	else if (keystatus[GLFW_KEY_U])
		cameraPos += normalize(cameraUp)*cameraSpeed;
	else if (keystatus[GLFW_KEY_J])
		cameraPos -= normalize(cameraUp)*cameraSpeed;
}

//load shader from dropped file, path: vshader, path2: fshader
GLuint load_shader(const char* path, const char* path2){
	string vshader_f_source, fshader_f_source, temp;
	auto shaderfstream = ifstream(path, ios::in);
	if (shaderfstream.is_open()){
		while (getline(shaderfstream, temp)){
			vshader_f_source += temp + "\n";
		}
	}
	shaderfstream.close();

	shaderfstream = ifstream(path2);
	if (shaderfstream.is_open()){
		while (getline(shaderfstream, temp)){
			fshader_f_source += temp + "\n";
		}
	}
	shaderfstream.close();

	GLint success;
	GLchar infolog[512];
	GLuint l_vs, l_fs, l_program;
	char const *l_vshader = vshader_f_source.c_str();
	char const *l_fshader = fshader_f_source.c_str();
	l_vs = glCreateShader(GL_VERTEX_SHADER);
	l_fs = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(l_vs, 1, &l_vshader, NULL);
	glCompileShader(l_vs);
	glGetShaderiv(l_vs, GL_COMPILE_STATUS, &success);
	if (!success){
		glGetShaderInfoLog(l_vs, 512, NULL, infolog);
		fprintf_s(stderr, "loaded_vshader:%s", infolog);
	}

	glShaderSource(l_fs, 1, &l_fshader, NULL);
	glCompileShader(l_fs);
	glGetShaderiv(l_fs, GL_COMPILE_STATUS, &success);
	if (!success){
		glGetShaderInfoLog(l_fs, 512, NULL, infolog);
		fprintf_s(stderr, "loaded_fshader:%s", infolog);
	}

	l_program = glCreateProgram();
	glAttachShader(l_program, l_vs);
	glAttachShader(l_program, l_fs);
	glLinkProgram(l_program);
	glGetProgramiv(l_program, GL_LINK_STATUS, &success);
	if (!success){
		glGetProgramInfoLog(l_program, 512, NULL, infolog);
		fprintf_s(stderr, "shaderprogram:%s", infolog);
	}
	glDetachShader(l_program, l_vs);
	glDetachShader(l_program, l_fs);

	return l_program;
}
