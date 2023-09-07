#include"Player.h"
#include "Novice.h"


void Player::Initialize() { 
	PosX_ = 595.0f;
	PosY_ = 480.0f;
	
}
void Player::Update()
{
	PosX_ = 585.0f;
}

void Player::Draw() 
{ 
	Novice::DrawBox(PosX_, PosY_, W_, H_, 0.0f, WHITE, kFillModeSolid);
	Novice::DrawBox(PosX_, PosY_, W_, H_, 0.0f, WHITE, kFillModeSolid);

}


//セッター
void Player::SetX(int PosX_) { this->PosX_ = PosX_; }

void Player::SetY(int PosY_) { this->PosY_ = PosY_; }

void Player::SetW(int W_) { this->W_ = W_; }

void Player::SetH(int H_) { this->H_ = H_; }

