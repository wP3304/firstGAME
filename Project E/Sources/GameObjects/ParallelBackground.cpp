#include "ParallelBackground.h"

void ParallexBackground::Init()
{
	Layer* layer;
	std::string path = "Background layers/";
	// trang chi them cho background thi them o day :))

	layer = new Layer();
	layer->Init(path + "sky", 20);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "grassy_mountains_fc", 20);
	m_Background.push_back(layer);


	layer = new Layer();
	layer->Init(path + "clouds_mid_t", 70);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "clouds_mid", 70);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "hill", 70);
	m_Background.push_back(layer);


	layer = new Layer();
	layer->Init(path + "clouds_front_t", 125);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "clouds_front", 125);
	m_Background.push_back(layer);

	//under
	layer = new Layer();
	layer->Init(path + "sky_lightened", 20);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "clouds_bg", 50);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "clouds_mg_3", 70);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "glacial_mountains", 15);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "glacial_mountains_lightened", 15);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "clouds_mg_2", 70);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "clouds_mg_1_lightened", 125);
	m_Background.push_back(layer);


	layer = new Layer();
	layer->Init(path + "clouds_mg_1", 125);
	m_Background.push_back(layer);

	layer = new Layer();
	layer->Init(path + "cloud_lonely", 125);
	m_Background.push_back(layer);
	layer = new Layer();
	layer->Init(path + "Background", 120);
	m_Background.push_back(layer);
}

void ParallexBackground::Update(float deltaTime)
{
	for (auto layer : m_Background) {
		layer->Update(deltaTime);
	}
}

void ParallexBackground::Render(sf::RenderWindow* window)
{
	for (auto layer : m_Background) {
		layer->Render(window);
	}
}
