#pragma once
#include "Triangulo.h"

class Scene {
public:
	Scene()
	{
		/*Primer triangulo*/
		GLfloat bufferforma1[] = {
			-1.0f, 1.0f, 0.0f,
			 -1.0f, -1.0f, 0.0f,
			 0.0f,  0.0f, 0.0f,
		};
		forma1 = new Triangle("Color.vertexShader", "Color.fragmentShader", glm::vec3(0, 0, 1), bufferforma1);

		/*Segundo triangulo*/
		GLfloat bufferforma2[] = {
			-1.0f,  1.0f, 0.0f,  // Vértice inferior izquierdo
			 0.0f,  0.0f, 0.0f,  // Vértice inferior derecho
			 1.0f,  1.0f, 0.0f,  // Vértice superior
		};
		forma2 = new Triangle("Color.vertexShader", "Color.fragmentShader", glm::vec3(0, 1, 0), bufferforma2);

		/*Tercer triangulo*/
		GLfloat bufferforma3[] = {
			-0.5f,  -0.5f, 0.0f,  // Vértice inferior izquierdo
			-1.0f,-1.0f, 0.0f,  // Vértice inferior derecho
			 0.0f,  -1.0f, 0.0f,  // Vértice superior
		};
		forma3 = new Triangle("Color.vertexShader", "Color.fragmentShader", glm::vec3(1, 0, 0), bufferforma3);

		/*Cuarto triangulo*/
		GLfloat bufferforma4[] = {
			1.0f,  0.0f, 0.0f,  // Vértice inferior izquierdo
			0.0f,-1.0f, 0.0f,  // Vértice inferior derecho
			 1.0f,  -1.0f, 0.0f,  // Vértice superior
		};
		forma4 = new Triangle("Color.vertexShader", "Color.fragmentShader", glm::vec3(1, 1, 0), bufferforma4);

		/*Quinto triangulo*/
		GLfloat bufferforma5[] = {
			0.5f,  0.5f, 0.0f,  // Vértice inferior izquierdo
			0.0f,  0.0f, 0.0f,  // Vértice inferior derecho
			0.5f,  -0.5f, 0.0f,  // Vértice superior
		};
		forma5 = new Triangle("Color.vertexShader", "Color.fragmentShader", glm::vec3(1, 0, 1), bufferforma5);

		/*Sexto triangulo*/
		GLfloat bufferforma6[] = {
			0.0f,  0.0f, 0.0f,  // Vértice inferior izquierdo
			-0.5f,  -0.5f, 0.0f,  // Vértice inferior derecho
			0.0f,  -1.0f, 0.0f,  // Vértice superior
		};
		forma6 = new Triangle("Color.vertexShader", "Color.fragmentShader", glm::vec3(0.1, 0.8, 0.7), bufferforma6);

		/*Septimo triangulo*/
		GLfloat bufferforma7[] = {
			0.0f,  0.0f, 0.0f,  // Vértice inferior izquierdo
			0.0f,  -1.0f, 0.0f,  // Vértice inferior derecho
			0.5f,  -0.5f, 0.0f,  // Vértice superior
		};
		forma7 = new Triangle("Color.vertexShader", "Color.fragmentShader", glm::vec3(0.1, 0.8, 0.7), bufferforma7);

		/*Octavo triangulo*/
		GLfloat bufferforma8[] = {
			0.5f,   0.5f, 0.0f,  // Vértice inferior izquierdo
			0.5f,  -0.5f, 0.0f,  // Vértice inferior derecho
			1.0f,   0.0f, 0.0f,  // Vértice superior
		};
		forma8 = new Triangle("Color.vertexShader", "Color.fragmentShader", glm::vec3(0.5, 0.55, 0.6), bufferforma8);

		/*Noveno triangulo*/
		GLfloat bufferforma9[] = {
			1.0f,   1.0f, 0.0f,  // Vértice inferior izquierdo
			0.5f,   0.5f, 0.0f,  // Vértice inferior derecho
			1.0f,   0.0f, 0.0f,  // Vértice superior
		};                                                                           //R     G    B
		forma9 = new Triangle("Color.vertexShader", "Color.fragmentShader", glm::vec3(0.5, 0.55, 0.6), bufferforma9);
	}

	void Update()
	{
		// Borra el buffer de color
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		forma1->Draw();
		forma2->Draw();
		forma3->Draw();
		forma4->Draw();
		forma5->Draw();
		forma6->Draw();
		forma7->Draw();
		forma8->Draw();
		forma9->Draw();
	}

	~Scene()
	{
		delete forma1;
		delete forma2;
		delete forma3;
		delete forma4;
		delete forma5;
		delete forma6;
		delete forma7;
		delete forma8;
		delete forma9;

		cout << "Free Scene Objects Memory" << endl;
	}

private:
	Triangle* forma1;
	Triangle* forma2;
	Triangle* forma3;
	Triangle* forma4;
	Triangle* forma5;
	Triangle* forma6;
	Triangle* forma7;
	Triangle* forma8;
	Triangle* forma9;
};
