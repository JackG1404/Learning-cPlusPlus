#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    float time = 0.0f;

    // Init GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to init GLFW\n";
        return -1;
    }

    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Reset", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Load OpenGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to init GLAD\n";
        return -1;
    }

    float lastTime = glfwGetTime();

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

		// Calculate delta time
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;


		// Update time
		time += deltaTime;

		// Clear screen with three colors that changes over time, using sine and cosine functions as they are offset which means a blend between the two colors
		float red = (sin(time) + 1.0f) / 2.0f;
        float green = (cos(time) + 1.0f) / 2.0f;
        float blue = (sin(time + 2.0f) + 1.0f) / 2.0f;
		// We add 1 and divide by 2 to ensure the values are between 0 and 1, as sine and cosine functions return values between -1 and 1, which are not valid for color components

		// Clear the screen with the computed color
		glClearColor(red, green, blue, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
