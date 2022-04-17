#include <parrlibgl/parrlibgl.h>

using namespace prb;

vec2 qpos = 0.f;
vec2 qsize = 0.2f;
bool moving = true;

void init() {
	prc::setClearColor(vec4(1.0f,1.0f,1.0f,1.0f));
}

void update() {
	if (input::getMouse(0)) qpos = input::getMousePos();
	if (input::getKey(GLFW_KEY_W)) qsize = input::getMousePos()-qpos;

	if (input::getKeyDown(GLFW_KEY_SPACE)) moving = !moving;
}

int accumspp = 0;
void draw() {
	util::setColor4f(vColor4f::gray.colMul(1.2f));
	util::drawQuad(qpos+(moving ? vec2(sin(gtime::time)*0.5f-0.1f,-0.1f) : 0.f), qsize);

	accumspp++;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	prc::setVSync(true);
	prc::setup({ &init, &update, &draw });
}

