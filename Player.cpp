#include"Player.h"
#include "Novice.h"


void Player::Initialize() { 
	for (int i = 0; i < 5; i++) {
		PosX_[i] = 595.0f;
		PosY_[i] = 480.0f;
	}
	
}
void Player::MoveUpdate()//陣1
{
	PosX_[0] = 595.0f;
	PosY_[0] = 480.0f;

	PosX_[1] = 505.0f;
	PosY_[1] = 480.0f;
	
	PosX_[2] = 685.0f;
	PosY_[2] = 480.0f;
}
void Player::SecondMoveUpdate() // 陣2
{
	
}
void Player::ThirdMoveUpdate()
{

}

void Player::Draw() 
{ 
	Novice::DrawBox(PosX_[0], PosY_[0], W_, H_, 0.0f, WHITE, kFillModeSolid);
	Novice::DrawBox(PosX_[1], PosY_[1], W_, H_, 0.0f, WHITE, kFillModeSolid);
	Novice::DrawBox(PosX_[2], PosY_[2], W_, H_, 0.0f, WHITE, kFillModeSolid);
}


//セッター
void Player::SetX(int PosX_) { this->PosX_[5] = PosX_; }

void Player::SetY(int PosY_) { this->PosY_[5] = PosY_; }

void Player::SetW(int W_) { this->W_ = W_; }

void Player::SetH(int H_) { this->H_ = H_; }

