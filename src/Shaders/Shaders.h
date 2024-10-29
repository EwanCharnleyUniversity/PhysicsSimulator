
#ifndef SHADER_CLASS_HPP
#define SHADER_CLASS_HPP


// Deals with Vertex Shaders (.vert files).
class VertexShader {
public:
	unsigned int ID;

	VertexShader();
	~VertexShader();
};


// Deals with Fragment Shaders (.frag files).
class FragmentShader {
public:
	unsigned int ID;

	FragmentShader();
	~FragmentShader();
};


// Contains both Vertex and Fragment shaders.
class ShaderProgram {

};


#endif
