#pragma once

#include "Window.h"
#include "OGLGraphics.h"

struct EngineConfig
{
	WindowConfig window;
	GraphicsConfig graphics;
};
class Engine
{
	friend Engine& GetEngine();
public:
	bool Init(const EngineConfig& config);

	void Update();
	void BeginFrame();
	void EndFrame();

	bool IsEnd() const
	{
		return m_isEnd;
	}

	bool IsRun() const
	{
		return m_isRun;
	}

	EngineConfig& GetConfig()
	{
		return m_config;
	}

private:
	Engine() = default;
	Engine(const Engine&) = delete;
	Engine(Engine&&) = delete;
	Engine operator=(const Engine&) = delete;
	Engine operator=(Engine&&) = delete;
	~Engine();

	void close();

	EngineConfig m_config;
	Window m_window;
	OGLGraphics m_graphics;
	bool m_isEnd = false;
	bool m_isRun = false;
};

Engine& GetEngine();