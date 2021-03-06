#pragma once
#include "../asc/Input.hpp"

namespace GamePad {
	extern asc::Input input;

	extern bool isErrorCalled;
	extern MessageBoxCommand com;

	extern XInput LGamePad;
	extern XInput RGamePad;

	extern void SetAxis();
	extern void SetButton();

	extern Vec2 Move(bool _isLeft, int _speed);

	extern bool Key(bool _isLeft, const String& _name);
	extern bool Key(const String& _name);
}
