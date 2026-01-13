#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Callback: called when the window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Main entry point for the program
int main()
{
    // --------------------------------------------------
    // 1) Initialise GLFW
    // --------------------------------------------------
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Tell GLFW we want modern OpenGL (3.3 Core)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // --------------------------------------------------
    // 2) Create window
    // --------------------------------------------------
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Playground", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // --------------------------------------------------
    // 3) Load OpenGL functions via GLAD
    // --------------------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    // --------------------------------------------------
    // 4) (Later) OpenGL setup
    //    - VAOs
    //    - VBOs
    //    - Shaders
    // --------------------------------------------------


    // --------------------------------------------------
    // 5) Render loop
    // --------------------------------------------------
    while (!glfwWindowShouldClose(window))
    {
        // --- Input & events ---
        glfwPollEvents();

        // --- Rendering ---
        glClearColor(0.05f, 0.08f, 0.12f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // (Later) draw calls go here

        // --- Present frame ---
        glfwSwapBuffers(window);
    }

    // --------------------------------------------------
    // 6) Cleanup & exit
    // --------------------------------------------------
    glfwTerminate();
    return 0;
}
