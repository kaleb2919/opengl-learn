#include "Box.h"
#include "Camera.h"
#include "Engine.h"
#include "GameObject.h"
#include "Scene.h"

int main(int argc, char* argv[])
{
    int width = 800, height = 600;

    Engine engine(width, height, "Game");

    auto box = new Box("Simple cube", glm::vec3(0.0f, 0.0f, -25.0f), glm::vec3(0.0f, 0.0f, 0.0f));
    auto camera = new Camera(width, height, glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    auto scene = new Scene();
    scene->add(box);

    while (engine.isRunning())
    {
        float delta_time = engine.getDeltaTime();

        if (engine.getKey(IK_ESCAPE) == IK_PRESS)
            engine.close();

        if (engine.getKey(IK_F1) == IK_PRESS)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        if (engine.getKey(IK_F2) == IK_PRESS)
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        if (engine.getKey(IK_W) == IK_PRESS)
            camera->move(FORWARD, delta_time);

        if (engine.getKey(IK_S) == IK_PRESS)
            camera->move(BACKWARD, delta_time);

        if (engine.getKey(IK_D) == IK_PRESS)
            camera->move(RIGHT, delta_time);

        if (engine.getKey(IK_A) == IK_PRESS)
            camera->move(LEFT, delta_time);

        engine.tick();
        engine.render(camera, scene);
    }

    return 0;
}
