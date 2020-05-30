#pragma once

#ifdef NB_PLATFORM_WINDOWS

extern Noob::Application* Noob::CreateApplication();

int main(int argc, char** argv) {

	Noob::Log::Init();
	
	NB_CORE_WARN("Initialized Log!");
	int a = 5;
	NB_INFO("Hello! var={0}", a);

	auto app = Noob::CreateApplication();
	app->Run();
	delete app;
}

#endif