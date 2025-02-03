#include"VBO.h"

VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID); //generetes a vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, ID); //Links the curently referenced vertex array object to the Vertex Buffer Object creating the back buffer data
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW); //arranges the space between the start of the data and end of the data in the back buffer
}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID); //Links the curently referenced vertex array object to the Vertex Buffer Object creating the back buffer data
}

void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0); //Uninks the curently referenced vertex array object to the Vertex Buffer Object
}

void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}