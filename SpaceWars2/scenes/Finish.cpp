#include "./Finish.hpp"
#include "../Config.hpp"
#include "../functions/Debug.hpp"

void Finish::init() {
	if (m_data->LPlayer.isHPRunOut() && m_data->RPlayer.isHPRunOut())
		isDraw = true;
	if (m_data->LPlayer.isHPRunOut())
		isLeftWin = false;
	if (m_data->RPlayer.isHPRunOut())
		isLeftWin = true;
}

void Finish::update() {
	changeScene(Debug::inputFnKey(), 250);
	if (Input::KeyEnter.clicked)
		changeScene(L"Ending", 500);
}

void Finish::draw() const {
	TextureAsset(L"background").resize(Config::Width, Config::Height).draw();
	FontAsset(L"CicaR32")(winner()).drawCenter(40, Color(L"#ffffff"));
}


String Finish::winner() const{
	if (isDraw)
		return L"引き分け！";
	if (isLeftWin)
		return  L"REDの勝ち！";
	else
		return L"BLUEの勝ち！";
	
	return String();
}
