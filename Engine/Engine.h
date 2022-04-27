#pragma once

#include "Camera.h"
#include "Scene.h"
#include "Window.h"

class Engine
{
    Window* window = nullptr;
    double last_time = 0;
    double current_time = 0;

    void draw();
public:
    Engine(int screen_width, int screen_height, const char * title);

    void render(Camera* camera, const Scene* scene);
    float getDeltaTime();
    float getTime();
    void tick();
    bool isRunning();
    void getMousePosition(double& x, double& y);
    void getMoiseOffset(double& x, double& y);
    int getKey(int key_code);
    void close();
};

#define IK_RELEASE            0
#define IK_PRESS              1
#define IK_REPEAT             2
#define IK_ESCAPE             256
#define IK_ENTER              257
#define IK_TAB                258
#define IK_BACKSPACE          259
#define IK_INSERT             260
#define IK_DELETE             261
#define IK_RIGHT              262
#define IK_LEFT               263
#define IK_DOWN               264
#define IK_UP                 265
#define IK_PAGE_UP            266
#define IK_PAGE_DOWN          267
#define IK_HOME               268
#define IK_END                269
#define IK_CAPS_LOCK          280
#define IK_SCROLL_LOCK        281
#define IK_NUM_LOCK           282
#define IK_PRINT_SCREEN       283
#define IK_PAUSE              284
#define IK_F1                 290
#define IK_F2                 291
#define IK_F3                 292
#define IK_F4                 293
#define IK_F5                 294
#define IK_F6                 295
#define IK_F7                 296
#define IK_F8                 297
#define IK_F9                 298
#define IK_F10                299
#define IK_F11                300
#define IK_F12                301
#define IK_F13                302
#define IK_F14                303
#define IK_F15                304
#define IK_F16                305
#define IK_F17                306
#define IK_F18                307
#define IK_F19                308
#define IK_F20                309
#define IK_F21                310
#define IK_F22                311
#define IK_F23                312
#define IK_F24                313
#define IK_F25                314
#define IK_KP_0               320
#define IK_KP_1               321
#define IK_KP_2               322
#define IK_KP_3               323
#define IK_KP_4               324
#define IK_KP_5               325
#define IK_KP_6               326
#define IK_KP_7               327
#define IK_KP_8               328
#define IK_KP_9               329
#define IK_KP_DECIMAL         330
#define IK_KP_DIVIDE          331
#define IK_KP_MULTIPLY        332
#define IK_KP_SUBTRACT        333
#define IK_KP_ADD             334
#define IK_KP_ENTER           335
#define IK_KP_EQUAL           336
#define IK_LEFT_SHIFT         340
#define IK_LEFT_CONTROL       341
#define IK_LEFT_ALT           342
#define IK_LEFT_SUPER         343
#define IK_RIGHT_SHIFT        344
#define IK_RIGHT_CONTROL      345
#define IK_RIGHT_ALT          346
#define IK_RIGHT_SUPER        347
#define IK_MENU               348
#define IK_SPACE              32
#define IK_APOSTROPHE         39  /* ' */
#define IK_COMMA              44  /* , */
#define IK_MINUS              45  /* - */
#define IK_PERIOD             46  /* . */
#define IK_SLASH              47  /* / */
#define IK_0                  48
#define IK_1                  49
#define IK_2                  50
#define IK_3                  51
#define IK_4                  52
#define IK_5                  53
#define IK_6                  54
#define IK_7                  55
#define IK_8                  56
#define IK_9                  57
#define IK_SEMICOLON          59  /* ; */
#define IK_EQUAL              61  /* = */
#define IK_A                  65
#define IK_B                  66
#define IK_C                  67
#define IK_D                  68
#define IK_E                  69
#define IK_F                  70
#define IK_G                  71
#define IK_H                  72
#define IK_I                  73
#define IK_J                  74
#define IK_K                  75
#define IK_L                  76
#define IK_M                  77
#define IK_N                  78
#define IK_O                  79
#define IK_P                  80
#define IK_Q                  81
#define IK_R                  82
#define IK_S                  83
#define IK_T                  84
#define IK_U                  85
#define IK_V                  86
#define IK_W                  87
#define IK_X                  88
#define IK_Y                  89
#define IK_Z                  90
#define IK_LEFT_BRACKET       91  /* [ */
#define IK_BACKSLASH          92  /* \ */
#define IK_RIGHT_BRACKET      93  /* ] */
#define IK_GRAVE_ACCENT       96  /* ` */
#define IK_WORLD_1            161 /* non-US #1 */
#define IK_WORLD_2            162 /* non-US #2 */
