#include"Player.h"
#include "Novice.h"


void Player::Initialize()
{
	

}
void Player::Update()
{

}

void Player::Draw() 
{ 
	Novice::DrawBox(PosX_, PosY_, W_, H_, 0.0f, WHITE, kFillModeSolid);

}


//セッター
void Player::SetX(int PosX_) { this->PosX_ = PosX_; }

void Player::SetY(int PosY_) { this->PosY_ = PosY_; }

void Player::SetW(int W_) { this->W_ = W_; }

void Player::SetH(int H_) { this->H_ = H_; }

void Player::SetHP(int HP_) { this->HP_ = HP_; }
