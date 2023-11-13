#include <Whatta.h>

class Sandbox : public Whatta::Application
{
public :
	Sandbox()
	{
	}
	~Sandbox()
	{
	}

};

Whatta::Application* Whatta::CreateApplication()
{
	return new Sandbox();
}