#include"Player.h"
#include "Novice.h"


void Player::Initialize()
{
	

}
void Player::Update()
{

}

void Player::Draw() {
	Novice::DrawBox(PosX_,PosY_,W_,H_,0.0f,WHITE,kFillModeSolid);
};