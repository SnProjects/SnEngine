#include "snpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace SnEngine
{
    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
        : m_WindowHandle(windowHandle)
    {
        SN_CORE_ASSERT(windowHandle, "Window handle is null!")
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        SN_CORE_ASSERT(status, "Failed to initialize Glad!")

        SN_CORE_INFO("OpenGL Info:");
        SN_CORE_TRACE("   - Vendor: {0}", (const char*)glGetString(GL_VENDOR));
        SN_CORE_TRACE("   - Renderer: {0}", (const char*)glGetString(GL_RENDERER));
        SN_CORE_TRACE("   - Version: {0}", (const char*)glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}