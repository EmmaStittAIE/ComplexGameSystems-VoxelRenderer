#pragma once

// Include vulkan.hpp before glfw
#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>

#include "VulpexMaths.hpp"

struct WindowInfo
{
	GLFWmonitor* targetMonitor = nullptr;

	const char* title = "Vulkan Application";

    int width = 0;
    int height = 0;
};

class VulkanApplication
{
    // Vulkan resources
    VkInstance vulkanInstance;

    // Window resources
    GLFWwindow* m_window;

    IVec2 m_winDimensions = {0, 0};

	// Bools
	bool AreExtensionsSupported(std::vector<const char*> extensions) const;
	
	#ifdef _DEBUG
		bool AreValidationLayersSupported(std::vector<const char*> validationLayers) const;
	#endif

public:
    VulkanApplication();
    
	void Init(WindowInfo winInfo, VkApplicationInfo appInfo, std::vector<const char*> vkExtensions, VkInstanceCreateFlags vkFlags);

	// Getters
    float GetAspect() const { return m_winDimensions.x / (float)m_winDimensions.y; }

    // Bools
    bool IsRunning() const { return !glfwWindowShouldClose(m_window); };

    ~VulkanApplication();
};