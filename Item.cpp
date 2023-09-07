#include "Item.h"
#include <stdio.h>
#include <time.h>

void Item::Initialize() {

	///アイテムナンバーを初期化
	ItemNum_ = 0;
	///アイテムフェーズを始める
	ItemNum_ = true;

};

void Item::Update() { 
	
	//ボタンを押したらアイテム選択処理

};

void Item::Draw() {

};

void Item::SetItemNum(int Speed_) { this->ItemNum_ = ItemNum_; }