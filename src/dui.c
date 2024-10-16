#include "dui.h" 

GLFWwindow* DUI_window;
GLuint shaderProgram;
int u_width, u_height;
DUI_Element* DUI_elements;

char* readFileToString(const char *filename) {
    FILE *file = fopen(filename, "r");

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET); 

    char *buffer = malloc(fileSize + 1);
    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0'; 

    fclose(file);
    return buffer;
}

GLuint createShaderProgram(GLfloat* vertices, size_t vertices_size, const char* vertexShaderSource, const char* fragmentShaderSource, GLuint* VAO, GLuint* VBO) {

    // Create a Vertex Buffer Object (VBO) and a Vertex Array Object (VAO)
    glGenVertexArrays(1, VAO);
    glGenBuffers(1, VBO);

    // Bind the Vertex Array Object first, then bind and set the vertex buffer(s)
    glBindVertexArray(*VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices, GL_STATIC_DRAW);

    // Then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind the VAO (it's a good practice to unbind it when we're done)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    GLint success;

    // Compile Vertex Shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Check for compilation errors
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    // Compile Fragment Shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Check for compilation errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    // Link shaders into a shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Delete the shaders as they're no longer needed
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

GLfloat* generateVertices(size_t* vertices_size) {

	GLfloat _vertices[] = {
		-1,  1,  0,  // Top-left
		 1,  1,  0,  // Top-right
		-1, -1,  0,  // Bottom-left
		 1, -1,  0   // Bottom-right
	};

	*vertices_size = sizeof(_vertices);
	GLfloat* vertices = (GLfloat*)malloc(*vertices_size);
	for(size_t i = 0; i < *vertices_size/sizeof(GLfloat); i++)
		vertices[i] = _vertices[i];

	return vertices;
	
}

void DUI_update() {
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void DUI_init(GLFWwindow* _window, int width, int height) {

	DUI_window = _window;	
	glewInit();

	size_t vertices_size;
	GLfloat* vertices = generateVertices(&vertices_size);
	const char* fragSource = readFileToString("src/shader.frag");
	const char* vertSource = readFileToString("src/shader.vert");
	GLuint VAO, VBO;
	shaderProgram = createShaderProgram(vertices, vertices_size, vertSource, fragSource, &VAO, &VBO);

	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);

	glUniform2f(glGetUniformLocation(shaderProgram, "u_resolution"), width, height); 

	
	free(vertices);
	free((void*)fragSource);
	free((void*)vertSource);

}
