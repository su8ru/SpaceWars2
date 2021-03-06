#pragma once
#include <Siv3D.hpp>
#include "Bullet.hpp"
#include "../CommonData.hpp"


class Shield final : public Bullet {
private:
	int damage = 0;
	int frameCount;
	bool isLInvalid = false;
	bool isRInvalid = false;
	static bool isLDoing;
	static bool isRDoing;
	double drawRate = 1;
	Circle getShape() { return Circle(pos, 100*drawRate); }
	Vec2 shrinkVec2 (Vec2);
public:
	Shield(Vec2 _pos, bool _isLeft) : Bullet(_pos, _isLeft) {
		SoundAsset(L"shield").setVolume(Config::MASTER_VOLUME * Config::EFFECT_VOLUME);
		SoundAsset(L"shield").playMulti(1.0);

		if (isLeft ? isLDoing : isRDoing) {
			(isLeft ? isLInvalid : isRInvalid) = true;
			frameCount = 100005;
		} else {
			(isLeft ? isLDoing : isRDoing) = true;
			frameCount = 0;
		}
	}
	~Shield() {
		(isLeft ? Data::LPlayer : Data::RPlayer).changeHitSize(30);

		if (!(isLeft ? isLInvalid : isRInvalid))
			(isLeft ? isLDoing : isRDoing) = false;
	}

	bool update(Vec2 _myPos, Vec2 _oppPos) override;
	void draw() override;
	bool isVisible() override;
	int getDamage(Circle _circle) override;
	Vec2 shrink(Rect) override;
};
