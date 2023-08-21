#include "helper/scene.h"
#include "helper/scenerunner.h"
#include "scenebasic_uniform.h"

//#include <iostream>
//#include <Windows.h>
//#include "MMSystem.h"
//using namespace std;

int main(int argc, char* argv[])
{
	SceneRunner runner("Shader_Basics");
	
	std::unique_ptr<Scene> scene;

	/*PlaySound("media\test tune.wav", NULL, SND_FILENAME);
	system("pause");*/

	scene = std::unique_ptr<Scene>(new SceneBasic_Uniform());

	return runner.run(*scene);
}
