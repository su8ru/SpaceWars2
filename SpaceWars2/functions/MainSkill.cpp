#include "./Player.hpp"
#include "../skills/Shot.hpp"
#include "../skills/Grenade.hpp"
#include "../skills/Bullet.hpp"
#include "../skills/Laser.hpp"
#include "../skills/Reflection.hpp"
#include "../skills/Flame.hpp"

void Player::doMainSkill(std::vector<Bullet*>& bullets){
	switch(this->whatMainSkill){
	case SHOT:
		if (KeyMainSkill.repeat(5)) {
			bullets.push_back(new Shot(pos, isLeft));
			temperature += 20;
			howFrameAfterShooting = 56;
		}
		break;

	case GRENADE:
		if (KeyMainSkill.repeat(30)) {
			bullets.push_back(new Grenade(pos, isLeft));
			temperature += 80;
			howFrameAfterShooting = 0;
		}
		break;

	case LASER:
		if (KeyMainSkill.repeat(0)) {
			bullets.push_back(new Laser(pos, isLeft));
			// temperature rise is in the Laser Class
			howFrameAfterShooting = 0;
		}
		break;

	case REFLECTION:
		if (KeyMainSkill.repeat(7)) {
			bullets.push_back(new Reflection(pos, isLeft));
			temperature += 40;
			howFrameAfterShooting = 10;
		}
		break;

	case FLAME:
		if (KeyMainSkill.repeat(25)) {
			bullets.push_back(new Flame(pos, isLeft));
			temperature += 70;
			howFrameAfterShooting = 30;
		}
		break;

	default:
		LOG_ERROR(L"doMainSkillで意図しない値が参照されました。");
	}
}
