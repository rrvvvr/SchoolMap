#include"VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &ID); //generetes an array of vertices
}

void VAO::LinkVBO(VBO& VBO, GLuint layout)
{
	VBO.Bind();
	glVertexAttribPointer(layout/*where data is starter to be read from in the vertex array(the line)*/, 3/*number of vertices*/, GL_FLOAT/*type of data used to specify the cooordanetes of the vertices*/, GL_FALSE/*The value false means the values of the coordinates
		are normilized meaning the numbers range from -1,1 if it were set to true than the numbers could be anything*/, 0/*clears space for the values of the Vertex array object and the Vertex Buffer Object*/, (void*)0)/*specyfies the starting
		location of the vertices in the vertex buffer void 0 means the vertices are read starting from 0*/;
	glEnableVertexAttribArray(layout); //Makes the code in the previous line active and linked to a fuction
	VBO.Unbind();
}

void VAO::Bind()
{
	glBindVertexArray(ID); //Makes the data in the variable VAO the curently referenced vertex array object
}

void VAO::Unbind()
{
	glBindVertexArray(0); //Makes the data in the variable VAO the curently referenced vertex array object
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}