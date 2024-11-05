#ifndef SHADER_CLASS_HPP
#define SHADER_CLASS_HPP


struct GLFWwindow;


// Deals with Vertex Shaders (.vert files).
// Vertex Shaders deal with vertex graphics such as whole fill rasterization. It is vertex per vertex.
class VertexShader {
public:
	unsigned int ID;

	VertexShader(const char* filePath);
	~VertexShader();
};


// Deals with Fragment Shaders (.frag files).
// Fragment Shaders deal with pixel per pixel basis, telling how each pixel of the window will look post-process.
class FragmentShader {
public:
	unsigned int ID;

	FragmentShader(const char* filePath);
	~FragmentShader();
};


// Contains both Vertex and Fragment shaders.
class ShaderProgram {
public:
	unsigned int ID;

	VertexShader* Vertex;
	FragmentShader* Fragment;

	ShaderProgram(const char* vertexFilePath, const char* fragmentFilePath);
	~ShaderProgram();

	void Use();
	void cameraPerspective(GLFWwindow& window, const float &time);
};


#endif
