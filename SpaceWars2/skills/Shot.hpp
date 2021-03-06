#pragma once
#include <Siv3D.hpp>
#include "Bullet.hpp"

class Shot final : public Bullet {
private:
	Circle getShape() { return Circle(pos,8*drawRate); }
	double drawRate = 1;
public:
	Shot(Vec2 _pos, bool _isLeft) : Bullet(_pos, _isLeft) {
		vel = Vec2(bulletSpeed * (isLeft ? 1 : -1), 0).rotate(Radians(Random(-5, 5)));
		SoundAsset(L"shot").setVolume(Config::MASTER_VOLUME * Config::EFFECT_VOLUME);
		SoundAsset(L"shot").playMulti(0.4);
	}

	Vec2 shrink(Rect _area) override{
		Bullet::shrink(_area);
		drawRate = shrinkRate * 3;
		vel *= 2;
		return pos;
	}

	bool update(Vec2 _myPos, Vec2 _oppPos) override;
	void draw() override;
	bool isVisible() override;
	int getDamage(Circle _circle) override;

	const static int bulletSpeed = 30;
};
