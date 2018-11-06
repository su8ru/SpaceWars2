#pragma once
#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "../Config.hpp"
#include "../CommonData.hpp"

class ScreenGuidance : public SceneManager<String,CommonData>::Scene {
private:
	Font CicaR32;
	int y = 0;
	bool mode = false;
public:
	void init() override;
	void update() override;
	void draw() const override;
};
