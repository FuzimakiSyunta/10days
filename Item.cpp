#include "Item.h"
#include <stdio.h>
#include <time.h>

void Item::Initialize() {

    ItemNum_ = rand() % 7;

};

void Item::Update() {

    ///���������Ƃ��|�C���g���{
    if (ItemNum_ == 0 || ItemNum_ == 1) {

    }
    ///���s�����C�t�������Ȃ�����ɃX�R�A������
    else if (ItemNum_ == 2 || ItemNum_ == 3) {

    }
    ///���̌��ʂ̒����烉���_���ň����
    else if (ItemNum_ == 4 || ItemNum_ == 5) {

    }
    ///�v���C���[��HP���P��
    else if (ItemNum_ == 6) {

    }
};

void Item::Draw() {
    ///aaa


};