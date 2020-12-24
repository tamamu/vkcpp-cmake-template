// MinimalVulkan.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "MinimalVulkan.h"

#define GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

void glfw_error_callback(int error, const char* description)
{
	panic("glfw error %d: %s", error, description);
}

int main()
{
	if (!glfwInit()) panic("%s", "Failed to initialize GLFW");
	std::atexit(glfwTerminate);

	glfwSetErrorCallback(glfw_error_callback);

	if (!glfwVulkanSupported()) panic("Vulkan is unsupported on GLFW");

	// init vulkan in here

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", nullptr, nullptr);
	if (!window) panic("Failed to create window");

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	// deinit vulkan in here

	std::exit(EXIT_SUCCESS);
}
