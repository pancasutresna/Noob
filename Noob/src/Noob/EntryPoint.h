#pragma once

#ifdef NB_PLATFORM_WINDOWS

extern Noob::Application* Noob::CreateApplication();

int main(int argc, char** argv) {

	auto app = Noob::CreateApplication();
	app->Run();
	delete app;
}

#endif