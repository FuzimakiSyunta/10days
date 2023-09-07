#include"Player.h"
#include "Novice.h"


void Player::Initialize() { 
	for (int i = 0; i < 5; i++) {
		PosX_[i] = 920.0f;
		PosY_[i] = 700.0f;
	}
	
}
void Player::MoveUpdate()//陣1
{
	PosX_[0] = 920.0f;//真ん中
	PosY_[0] = 700.0f;

	PosX_[1] = 635.0f;//左1
	PosY_[1] = 700.0f;

	PosX_[4] = 350.0f;//左2
	PosY_[4] = 700.0f;
	
	PosX_[2] = 1205.0f;//右1
	PosY_[2] = 700.0f;

	PosX_[3] = 1490.0f;//右2
	PosY_[3] = 700.0f;

	
}
void Player::SecondMoveUpdate() // 陣2
{
	PosX_[0] = 920.0f; // 真ん中
	PosY_[0] = 800.0f;

	PosX_[1] = 635.0f; // 左1
	PosY_[1] = 700.0f;

	PosX_[4] = 350.0f; // 左2
	PosY_[4] = 800.0f;

	PosX_[2] = 1205.0f; // 右1
	PosY_[2] = 700.0f;

	PosX_[3] = 1490.0f; // 右2
	PosY_[3] = 800.0f;
}
void Player::ThirdMoveUpdate()//陣3
{
	PosX_[0] = 595.0f;
	PosY_[0] = 690.0f;

	PosX_[1] = 505.0f;
	PosY_[1] = 520.0f;

	PosX_[2] = 685.0f;
	PosY_[2] = 400.0f;

	PosX_[3] = 685.0f;
	PosY_[3] = 480.0f;

	PosX_[4] = 685.0f;
	PosY_[4] = 480.0f;
}

void Player::Draw() 
{ 
	Novice::DrawBox(PosX_[0], PosY_[0], W_, H_, 0.0f, WHITE, kFillModeSolid);
	Novice::DrawBox(PosX_[1], PosY_[1], W_, H_, 0.0f, WHITE, kFillModeSolid);
	Novice::DrawBox(PosX_[2], PosY_[2], W_, H_, 0.0f, WHITE, kFillModeSolid);
	Novice::DrawBox(PosX_[3], PosY_[3], W_, H_, 0.0f, WHITE, kFillModeSolid);
	Novice::DrawBox(PosX_[4], PosY_[4], W_, H_, 0.0f, WHITE, kFillModeSolid);
}


//セッター
void Player::SetX(int PosX_) { this->PosX_[5] = PosX_; }

void Player::SetY(int PosY_) { this->PosY_[5] = PosY_; }

void Player::SetW(int W_) { this->W_ = W_; }

void Player::SetH(int H_) { this->H_ = H_; }

