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

	PosX_[1] = 728.0f;//左1
	PosY_[1] = 810.0f;

	PosX_[4] = 540.0f;//左2
	PosY_[4] = 700.0f;
	
	PosX_[2] = 1112.0f;//右1
	PosY_[2] = 810.0f;

	PosX_[3] = 1300.0f;//右2
	PosY_[3] = 700.0f;

	
}

void Player::SecondMoveUpdate() // 陣2
{
	PosX_[0] = 920.0f; // 真ん中
	PosY_[0] = 720.0f;

	PosX_[1] = 635.0f; // 左1
	PosY_[1] = 640.0f;

	PosX_[4] = 635.0f; // 左2
	PosY_[4] = 830.0f;

	PosX_[2] = 1205.0f; // 右1
	PosY_[2] = 640.0f;

	PosX_[3] = 1205.0f; // 右2
	PosY_[3] = 830.0f;
}

void Player::ThirdMoveUpdate()//陣3
{
	PosX_[0] = 920.0f; // 真ん中
	PosY_[0] = 800.0f;

	PosX_[1] = 850.0f; // 左1
	PosY_[1] = 620.0f;

	PosX_[4] = 770.0f; // 左2
	PosY_[4] = 720.0f;

	PosX_[2] = 990.0f; // 右1
	PosY_[2] = 620.0f;

	PosX_[3] = 1070.0f; // 右2
	PosY_[3] = 720.0f;
}

void Player::Draw() 
{ 
	Novice::DrawSprite(PosX_[0],PosY_[0],Ship_,W_,H_,0.0f,WHITE);
	Novice::DrawSprite(PosX_[1], PosY_[1], Ship_, W_, H_, 0.0f, WHITE);
	Novice::DrawSprite(PosX_[2], PosY_[2], Ship_, W_, H_, 0.0f, WHITE);
	Novice::DrawSprite(PosX_[3], PosY_[3], Ship_, W_, H_, 0.0f, WHITE);
	Novice::DrawSprite(PosX_[4], PosY_[4], Ship_, W_, H_, 0.0f, WHITE);
}


//セッター
void Player::SetX(int PosX_) { this->PosX_[5] = PosX_; }

void Player::SetY(int PosY_) { this->PosY_[5] = PosY_; }

void Player::SetW(int W_) { this->W_ = W_; }

void Player::SetH(int H_) { this->H_ = H_; }

