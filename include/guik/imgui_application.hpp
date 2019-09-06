#ifndef GUIK_IMGUI_APPLICATION_HPP
#define GUIK_IMGUI_APPLICATION_HPP

#include <iostream>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace guik {

class Application {
public:
    Application()
    : window(nullptr)
    {}

    virtual ~Application() {
        if(!window){
            return;
        }

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();
    }

    virtual bool init(const Eigen::Vector2i& size, const char* glsl_version="#version 330") {
        glfwSetErrorCallback([](int err, const char* desc) { std::cerr << "glfw error " << err << ": " << desc << std::endl; });
        if(!glfwInit()) {
            std::cerr << "failed to initialize GLFW" << std::endl;
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        window = glfwCreateWindow(size[0], size[1], "screen", nullptr, nullptr);
        if(window == nullptr) {
            return false;
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        if(glewInit() != GLEW_OK) {
            std::cerr << "failed to initialize GLEW" << std::endl;
            return false;
        }

        // setup imgui
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);

        return true;
    }

    void run() {
        while(!glfwWindowShouldClose(window)) {
            glfwPollEvents();
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            draw_ui();

            ImGui::Render();

            int display_w, display_h;
            glfwGetFramebufferSize(window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            draw_gl();

            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            glfwSwapBuffers(window);
        }
    }

    virtual void draw_ui() {
        ImGui::ShowDemoWindow();
    }

    virtual void draw_gl() {

    }

protected:
    GLFWwindow* window;

};

}

#endif