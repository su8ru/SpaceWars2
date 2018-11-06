#pragma once
#include "Opening.hpp"
#include "../Config.hpp"

void Opening::init(){
	this->CicaR32 = Font(32, L"Cica"); // :ac:
	m_data->count++;
	Println(m_data->count);
	m_data->LPlayer.Init(40,   Config::Height/2, true);  //円の半径
	m_data->RPlayer.Init(1240, Config::Height/2, false); //Width-円の半径
}

void Opening::update(){
	if (Input::KeyEnter.clicked)
		changeScene(L"ControlGuidance");
	if (this->mode)
		y++;
	else
		y--;
	if (y < 0)mode = true;
	if (y > 720)mode = false;
}

void Opening::draw() const{
	m_data->background.resize(Config::Width, Config::Height).draw();
	CicaR32(L"SpaceWars2").drawCenter(y/*200*/, Color(L"#ffffff"));
}