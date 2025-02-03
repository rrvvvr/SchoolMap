#include"shaderClass.h"

// Reads a text file and outputs a string with everything in the text file
std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); //Creating a vertex shader reference and linking it to a variable
	glShaderSource(vertexShader, 1, &vertexSource, NULL); //Linking the source code of the vertex shader to the to the variable
	glCompileShader(vertexShader); //Compile the vertex shader to mashine code

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); //Creating a fragment shader reference and linking it to a variable
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL); //Linking the source code of the fragment shader to the to the variable
	glCompileShader(fragmentShader); //Compile the fragment shader into mashine code

	ID = glCreateProgram(); //Creates a shader program (execution protocol of the shaders)

	glAttachShader(ID, vertexShader); //links the vertex shader to the shader program (execution protocol of the shaders)
	glAttachShader(ID, fragmentShader); //links the fragment shader to the shader program (execution protocol of the shaders)

	glLinkProgram(ID); //makes the shader program (execution protocol of the shaders) the currently referenced object

	glDeleteShader(vertexShader); //deletes the vertex shader from memory
	glDeleteShader(fragmentShader); //deletes the fragment shader from memory
};

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}