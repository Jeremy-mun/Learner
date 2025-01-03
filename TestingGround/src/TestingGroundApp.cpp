#include "Engine.h"

class TestLayer : public Engine::Layer
{
public:
	TestLayer()
		: Layer("Test")
	{
	}

	void OnUpdate() override
	{
		INFO("TestLayer::Update");
	}

	void OnEvent(Engine::Event& e) override
	{
		TRACE("{0}", e.ToString());
	}
};

class TestingGround : public Engine::App
{
public:
	TestingGround()
	{
		PushLayer(new TestLayer());
	}

	~TestingGround()
	{

	}
};

Engine::App* Engine::CreateApp()
{
	return new TestingGround();
}