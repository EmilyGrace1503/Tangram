#include <glew.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "Scene.h"

int main() {
    // Inicializar GLFW
    glfwInit();

    // Configurar las opciones de GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Crear una ventana GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "Tangram", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Fallo al crear la ventana GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }

    // Configurar el tamaño del viewport
    glViewport(0, 0, 800, 600);

    glEnable(GL_DEPTH_TEST); // Depth Testing
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);


    Scene* Escena = new Scene();

    // Bucle principal de la aplicación
    while (!glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        // Procesar la entrada del usuario

        // Renderizar aquí...
        Escena->Update();

        // Intercambia los buffers
        glfwSwapBuffers(window);
        // Verifica eventos
        glfwPollEvents();
    }

    // Limpiar los recursos de GLFW antes de salir
    delete Escena;
    cout << "Free Scene Memory" << endl;
    glfwTerminate();
    return 0;
}
