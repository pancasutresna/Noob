#include <Noob.h>

class Sandbox : public Noob::Application {
public:
	Sandbox() {
	}

	~Sandbox() {
	}
};

Noob::Application* Noob::CreateApplication() {
	return new Sandbox();
}