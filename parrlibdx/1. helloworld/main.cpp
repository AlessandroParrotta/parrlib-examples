#include <parrlibdx/parrlibdx.h>

using namespace prb;

int argc; LPWSTR* argv;

void init(){
    prc::setClearColor(vc4::black);
}

void update() {
    dxutil::pushMatrix(pmat3::orthoMaxAspect(cst::res()).inverted());

    int num = 20;
    for (int i = 0; i < num; i++) {
        dxutil::setColor(i%3 == 0 ? vc4::red : i%3 == 1 ? vc4::green : i%3 == 2 ? vc4::blue : vc4::white);
        dxutil::drawCircle(pmat3::rotate(curtime * ((1000.f + i*60.f))/(float)num) * pmat3::translate(vec2x(.5f)) * pmat3::scale(0.5f));
    }

    dxutil::popMatrix();
}

// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    argv = CommandLineToArgvW(GetCommandLine(), &argc); //program arguments if needed (in C style, argc & argv)

    prc::setVSync(true);
    prc::setMaximized(true);
    prc::setup(hInstance, { &init, &update });

    return 0;
}
