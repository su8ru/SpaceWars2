#include <Siv3D.hpp>
#include "./Debug.hpp"

String Debug::inputFnKey(){
	String sceneName;
	if(Input::KeyF1.clicked) sceneName = L"Opening";
	if(Input::KeyF2.clicked) sceneName = L"ControlGuidance";
	if(Input::KeyF3.clicked) sceneName = L"ScreenGuidance";
	if(Input::KeyF4.clicked) sceneName = L"SkillSelect";
	if(Input::KeyF5.clicked) sceneName = L"Game";
	if(Input::KeyF6.clicked) sceneName = L"Finish";
	if(Input::KeyF7.clicked) sceneName = L"Ending";
	return sceneName;
}