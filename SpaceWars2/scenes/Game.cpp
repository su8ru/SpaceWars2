#include "Game.hpp"

void Game::init() {
	stopwatch.start();
}

void Game::update() {

	if (!finish) {
		changeScene(Debug::InputFnKey(), 250);

		Data::LPlayer.update(bullets);
		Data::RPlayer.update(bullets);

		if (!Player::inJudgmentTime) {
			for (auto itr = bullets.begin(); itr != bullets.end();) {
				Vec2 myPos = ((**itr).isLeft ? Data::LPlayer : Data::RPlayer).circle().center;
				Vec2 oppPos = ((**itr).isLeft ? Data::RPlayer : Data::LPlayer).circle().center;

				if ((**itr).update(myPos, oppPos)) {
					delete* itr;
					itr = bullets.erase(itr);
				}
				else {
					itr++;
				}
			}
		}
	}
	else { // finish
		stopwatch.pause();
		if (Data::KeyEnter.repeat(20))
			changeScene(L"Ending", 500);
	}

	if (Data::LPlayer.isHPRunOut() || Data::RPlayer.isHPRunOut())
		finish = true;
}

void Game::draw() const {
	TextureAsset(L"background").resize(Config::WIDTH, Config::HEIGHT).draw();

	/*Data::LPlayer.DrawMainSkill();
	Data::LPlayer.DrawSubSkill();
	Data::LPlayer.DrawSpecialSkill();
	Data::RPlayer.DrawMainSkill();
	Data::RPlayer.DrawSubSkill();
	Data::RPlayer.DrawSpecialSkill();*/
	for(auto bul : bullets){
		bul->draw();
	}

	Data::LPlayer.drawShip();
	Data::RPlayer.drawShip();
	Data::LPlayer.drawGauge();
	Data::RPlayer.drawGauge();

	if (!finish) {
		FontAsset(L"Smart32")(L"I am game scene! Hello!").drawCenter(40, Color(L"#ffffff"));

		Vec2 buttonPos(890, 692);

		buttonPos.x += (int)TextureAsset(L"stick_24").draw(buttonPos).w + 6;
		buttonPos.x += (int)FontAsset(L"CicaR12")(L"移動").draw(buttonPos).w + 15;

		buttonPos.x += (int)TextureAsset(L"buttonA_24").draw(buttonPos).w + 6;
		buttonPos.x += (int)FontAsset(L"CicaR12")(L"Main").draw(buttonPos).w + 15;

		buttonPos.x += (int)TextureAsset(L"buttonLB_24").draw(buttonPos).w + 6;
		buttonPos.x += (int)FontAsset(L"CicaR12")(L"Sub").draw(buttonPos).w + 15;

		buttonPos.x += (int)TextureAsset(L"buttonRB_24").draw(buttonPos).w + 6;
		buttonPos.x += (int)FontAsset(L"CicaR12")(L"Special").draw(buttonPos).w + 15;
	}
	else {
		Rect(0, 0, Config::WIDTH, Config::HEIGHT).draw(ColorF(L"#000").setAlpha(0.7));


		if (Data::LPlayer.isHPRunOut() && Data::RPlayer.isHPRunOut())
			FontAsset(L"Smart32")(L"引き分け！").drawCenter(300, Color(L"#fff"));
		else {
			if (Data::LPlayer.isHPRunOut())
				FontAsset(L"Smart32")(L"RPlayer win !").drawCenter(250, Color(L"#00f"));
			if (Data::RPlayer.isHPRunOut())
				FontAsset(L"Smart32")(L"LPlayer win !").drawCenter(250, Color(L"#f00"));
		}

		// 箇条書き
		FontAsset(L"Smart28")(L"HP:").draw(280, 390);
		FontAsset(L"Smart28")(L"Skills:").draw(280, 470);
		FontAsset(L"Smart28")(L"Time:").draw(280, 550);

		// HP
		rightAlign(L"Smart28", Format(Data::LPlayer.HP), 620, 390);
		rightAlign(L"Smart28", Format(Data::RPlayer.HP), 840, 390);

		// Skills
		for (int isLeft = 0; isLeft <= 1; isLeft++) { // LPlayer, RPlayer
			Player* PLAYER = &(isLeft ? Data::LPlayer : Data::RPlayer);
			String skillType[3] = { L"main", L"sub", L"special" };
			int    whatSkill[3] = { PLAYER->whatMainSkill, PLAYER->whatSubSkill, PLAYER->whatSpecialSkill };
			int	   skillsCnt[3] = { PLAYER->mainSkillCnt, PLAYER->subSkillCnt, PLAYER->specialSkillCnt };
			String skillColor[3] = { L"#0c0", L"#00c", L"#cc0" };
			for (int type = 0; type < 3; type++) { // mainSkill, subSkill, specialSkill
				TextureAsset(skillType[type] + Format((int)whatSkill[type])).resize(50, 50)
				.draw(670 + (60 * type) - (220 * isLeft), 472);

				Rect(670 + (60 * type) - (220 * isLeft), 522, 50, 20).draw(Color(skillColor[type]));

				rightAlign(L"CicaR12", (skillsCnt[type] < 1000 ? Format(skillsCnt[type]) : L"999+"), 718 + (60 * type) - (220 * isLeft), 520);
			}
		}

		// Time
		FontAsset(L"Smart28")(stopwatch.min(), L"分 ", stopwatch.s() % 60, L"秒").drawCenter(550);

		// 装飾
		Line(250, 380, 250, 620).draw(6, ColorF(L"#00BFFF"));
	}
}


void Game::rightAlign(String _font, String _text, int _x, int _y, Color _color) {
	FontAsset(_font)(_text).draw(_x - FontAsset(_font)(_text).region().w, _y, _color);
}
