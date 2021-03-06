#pragma once
#include <Siv3D.hpp>
#include "Bullet.hpp"

class Missile : public Bullet {
private:
	Circle getShape() { return Circle(pos, 8*drawRate); }
	Vec2 shrinkVec2(Vec2 _d);
	double drawRate = 1;
public:
	Missile(Vec2 p, bool left) : Bullet(p, left) {
		vel = Vec2(bulletSpeed * (left ? 1 : -1), 0).rotate(Radians(Random(-5, 5)));
		SoundAsset(L"missile").setVolume(Config::MASTER_VOLUME * Config::EFFECT_VOLUME);
		SoundAsset(L"missile").playMulti(0.8);
		// vel.rotate(Radians(((System::FrameCount() % 20 == 0) ? 1 : -1) * 10.0));
		/*angle += 7;
		vel = .rotate(Radians(angle));
	}
	else {
		//angle -= 7;
		vel = Vec2(bulletSpeed * (left ? 1 : -1), 0).rotate(Radians(angle));
	}*/
	}

	bool update(Vec2 myPos, Vec2 oppPos) override;
	void draw() override;
	bool isVisible() override;
	int getDamage(Circle circle) override;

	void bend(Vec2 oppPos, double thre);
	int angleBefore = 0;
	// int angle = 0;

	const static int bulletSpeed = 7;
	const double EPS = 1e-2;
	const double ROTATEPOWER = Pi / 120.0;
	Vec2 shrink(Rect _area) override {
		Bullet::shrink(_area);
		drawRate = shrinkRate * 3;
		return pos;
	}
};
