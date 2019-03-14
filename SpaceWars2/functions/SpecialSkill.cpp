#include "./Player.hpp"
#include "../skills/LockOn.hpp"


void Player::DoSpacialSkill(std::vector<Bullet*>& bullets){
	switch(this->whatSpecialSkill){
		case JUDGEMENT_TIME:
		break;

		case LOCK_ON:
		bullets.push_back(new LockOn(pos, isLeft));
		break;

		case SUMMON_PARTNER:
		break;

		case INVERESION_RECOVERY:
		break;

		default:
		LOG(L"[ERROR] DoSpecialSkillで意図しない値が参照されました。");
	}
}

void Player::UpdateSpecialSkill(){
	switch(this->whatSpecialSkill){
		case JUDGEMENT_TIME:
		break;

		case LOCK_ON:
		break;

		case SUMMON_PARTNER:
		break;

		case INVERESION_RECOVERY:
		break;

		default:
		LOG(L"[ERROR] UpdateSpecialSkillで意図しない値が参照されました。");
	}
}

void Player::DrawSpecialSkill(){
	switch(this->whatSpecialSkill){
		case JUDGEMENT_TIME:
		break;

		case LOCK_ON:
		break;

		case SUMMON_PARTNER:
		break;

		case INVERESION_RECOVERY:
		break;

		default:
		LOG(L"[ERROR] DrawSpecialSkillで意図しない値が参照されました。");
	}
}
