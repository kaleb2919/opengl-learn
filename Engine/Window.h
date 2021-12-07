#pragma once

class GLFWwindow;

class Window
{
    GLFWwindow * window = nullptr;

    int width;
    int height;

    double prev_x;
    double prev_y;
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
