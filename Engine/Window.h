#pragma once

class GLFWwindow;

class Window
{
    GLFWwindow * window = nullptr;

    int width;
    int height;

    double prev_x = 0;
    double prev_y = 0;
    bool inverse_mouse_x = false;
    bool inverse_mouse_y = true;

public:

    Window(int screen_width, int screen_height, const char * title);
    void processInput();
    void clear();
    void swap();
    void getMousePosition(double& x, double& y);
    void getMoiseOffset(double& x, double& y);
    bool isRunning();

    int getWidth();
    int getHeight();
    int getKey(int key_code);
    void close();
    double getTime();
};
