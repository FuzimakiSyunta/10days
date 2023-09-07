#include "Item.h"
#include <stdio.h>
#include <time.h>

void Item::Initialize() {

	///アイテムナンバーを初期化
	ItemNum_ = 0;
	///アイテムフェーズを始める
	isItemPhase_ = true;

};

void Item::Update() { 
	
	if (isItemPhase_ == true) {
		///アイテムを選択するフェーズ
			///もしアイテム1の効果中なら////
			
			////////////////////////////////
	}


};

void Item::Draw() {

};