#pragma once
#include <glm/glm.hpp>
#include <glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

class Triangle {
	
public:
	Triangle(const char* vertex, const char* fragment, glm::vec3 color, GLfloat valores[])
	{

		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);

		Color = color;

		shader = new Shader();
		programID = shader->LoadShaders(vertex, fragment);

		ColorID = glGetUniformLocation(programID, "colorT");

		GLfloat g_vertex_buffer_data[] = {
			valores[0], valores[1], valores[2],
			 valores[3], valores[4], valores[5],
			 valores[6],  valores[7],valores[8],
		};

		glGenBuffers(1, &vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	}

	void Draw()
	{
		// Use our shader
		glUseProgram(programID);

		glUniform3f(ColorID, Color.x, Color.y, Color.z);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

		glDisableVertexAttribArray(0);
		glUseProgram(0);

	}

	~Triangle()
	{
		// Cleanup VBO
		glDeleteBuffers(1, &vertexbuffer);
		glDeleteVertexArrays(1, &VertexArrayID);
		glDeleteProgram(programID);
	}

private:
	Shader* shader;
	GLuint programID;
	GLuint vertexbuffer;
	GLuint VertexArrayID;
	GLuint ColorID;
	glm::vec3 Color;
};
