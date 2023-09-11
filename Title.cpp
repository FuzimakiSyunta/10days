#include"Title.h"
#include "Novice.h"

void TitleAction::Initialize()
{
	TitleFrame = 0;
	ButtonFrame = 0;
	TitleAnimation = 0;
	ButtonAnimation = 0;
}
void TitleAction::GameoverInitialize()
{
	GameoverFrame = 0;
	GameoverAnimation = 0;
}


void TitleAction::Update()
{
	// タイトルアニメーション
	if (TitleFrame >= 65) {
		TitleAnimation++;
		TitleFrame = 0;
	}
	if (TitleAnimation >= 2) {
		TitleAnimation = 0;
	}
	TitleFrame++;

	// ボタンアニメーション
	if (ButtonFrame >= 20) {
		ButtonAnimation++;
		ButtonFrame = 0;
	}
	if (ButtonAnimation >= 2) {
		ButtonAnimation = 0;
	}
	ButtonFrame++;
}

void TitleAction::GameoverUpdate()
{
	// ゲームオーバーアニメーション
	if (GameoverFrame >= 10) {
		GameoverAnimation++;
		GameoverFrame = 0;
	}
	if (GameoverAnimation >= 8) {
		GameoverAnimation = 7;	
	}
	GameoverFrame++;
	
}
void TitleAction::GameoverUpdate()
{
	// ゲームオーバーアニメーション
	if (GameoverFrame >= 10) {
		GameoverAnimation++;
		GameoverFrame = 0;
	}
	if (GameoverAnimation >= 8) {
		GameoverAnimation = 7;
	}
	GameoverFrame++;

}

void TitleAction::Draw()
{
	Novice::DrawSprite(0, 0, Titleimage[TitleAnimation], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(0, 0, Buttonimage[ButtonAnimation], 1, 1, 0.0f, WHITE);
}

void TitleAction::GameoverDraw()
{
	Novice::DrawSprite(0, 0, Gameoverimage[GameoverAnimation], 1, 1, 0.0f, WHITE);
}