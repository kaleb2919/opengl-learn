#include "Camera.h"
#include "Engine.h"
#include "GameObject.h"
#include "Light.h"
#include "Scene.h"

int main(int argc, char* argv[])
{
    int width = 800, height = 600;

    Engine engine(width, height, "Game");

    auto box_material = new Material("data/shader/shader.vert", "data/shader/shader.frag");
    auto light_material = new Material("data/shader/light.vert", "data/shader/light.frag");
    box_material->setBaseTexture(new Image("data/texture/box_rgb.png"));
    box_material->setNormalMap(new Image("data/texture/box_n.png"));
    box_material->setRoughnessMap(new Image("data/texture/box_m.png"));

    auto box1 = new GameObject("Simple cube", glm::vec3(0.0f, -25.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    box1->setMesh(new MeshComponent("./data/model/box.fbx", box_material));
    auto box2 = new GameObject("Simple cube", glm::vec3(0.0f, 0.0f, -25.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    box2->setMesh(new MeshComponent("./data/model/box.fbx", box_material));
    auto box3 = new GameObject("Simple cube", glm::vec3(-25.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    box3->setMesh(new MeshComponent("./data/model/box.fbx", box_material));
    auto box4 = new GameObject("Simple cube", glm::vec3(0.0f, 25.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    box4->setMesh(new MeshComponent("./data/model/box.fbx", box_material));
    auto box5 = new GameObject("Simple cube", glm::vec3(0.0f, 0.0f, 25.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    box5->setMesh(new MeshComponent("./data/model/box.fbx", box_material));
    auto box6 = new GameObject("Simple cube", glm::vec3(25.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    box6->setMesh(new MeshComponent("./data/model/box.fbx", box_material));
    auto light_sphere = new Light("Light object", glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.5f, 0.5f, 0.5f));
    light_sphere->setMesh(new MeshComponent("./data/model/sphere.fbx", light_material));

    auto camera = new Camera(width, height, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    auto scene = new Scene();
    scene->add(box1);
    scene->add(box2);
    scene->add(box3);
    scene->add(box4);
    scene->add(box5);
    scene->add(box6);
    scene->add(light_sphere);
    scene->addLight(light_sphere);

    while (engine.isRunning())
    {
        float delta_time = engine.getDeltaTime();
        float time = engine.getTime();

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

        double x, y;
        engine.getMoiseOffset(x, y);
        camera->look(x, y);

        light_sphere->setPosition(
            0 + cos(time) * 64,
            0 + cos(time) * 64,
            0 + sin(time) * 64
        );

        engine.tick();
        engine.render(camera, scene);
    }

    return 0;
}
