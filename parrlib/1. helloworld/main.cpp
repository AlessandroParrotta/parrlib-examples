#include <parrlib/parrlib.h>

using namespace prb;

int argc; LPWSTR* argv;

// color palette to draw the circles
const std::vector<vec4> colors{
    "#253237",
    "#5c6b73",
    "#9db4c0",
    "#c2dfe3",
    "#e0fbfc",
    "#c2dfe3",
    "#9db4c0",
    "#5c6b73",
};

void init(){
    prc::setClearColor("#161c1e");
}

std::wstring testText = L"";
void update() {
    util::pushMatrix(pmat3::orthoMaxAspect(cst::res()).inverted());

    // draw some circles rotating at different speeds around the origin
    int num = 20; // number of circles
    for (int i = 0; i < num; i++) {
        util::setColor(colors[i%colors.size()]);  // set the color to a value present in the colors vector
        util::drawCircle(pmat3::rotate(gtime::time * ((1000.f + i*60.f))/(float)num) * pmat3::translate(vec2x(.5f)) * pmat3::scale(0.5f), 80);
    }

    util::popMatrix();
}

// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    argv = CommandLineToArgvW(GetCommandLine(), &argc); // program arguments if needed (in C style, argc & argv)
    
    prc::setTitle(L"Parrlib Application");  // title displayed on top of the window
    prc::setVSync(true);                    // vertical synchronization
    prc::setMaximized(true);                // maximizing the window automatically sets the resolution

    prc::setRenderBackend("OpenGL");      	// can be 'OpenGL', 'DX11', 'CPUSingleThread', default is 'OpenGL'

    deb::windowEnabled = false;             // opens a debug window on app start that receives deb::ss messages

    vec2 res = { 0.f, 0.f };    // video resolution (optional parameter), { 0.f, 0.f } means take the monitor's resolution automatically
    prc::setup(hInstance, res, { &init, &update });  // launch the directx context and run the app

    return 0;
}
