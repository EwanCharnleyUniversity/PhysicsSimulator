#ifndef BUFFERS_CLASS_HPP
#define BUFFERS_CLASS_HPP


// This works, but is hard to work with.
// We are going to abstract this.
class Buffer {
public:
	unsigned int VAO, VBO, EBO;

	Buffer();

	void BindVertexArray();
	void BindBuffer(float* vertex);

	void Attribute(unsigned int layout, int size, int stride, int offset);
};


// TODO

class VAO {

};


class VBO {

};


class EBO {

};


#endif



/*
From github: https://stackoverflow.com/questions/8923174/opengl-vao-best-practices

initialization:
    for each batch
        generate, store, and bind a VAO
        bind all the buffers needed for a draw call
        unbind the VAO

main loop/whenever you render:
    for each batch
        bind VAO
        glDrawArrays(...); or glDrawElements(...); etc.
    unbind VAO

*/