#pragma once

#include "Novice.h"
#include "WorldTransform.h"


class Item {
public:
    /// <summary>
    /// ������
    /// </summary>
    void Initialize();

    /// <summary>
    /// ���L����
    /// �X�V
    /// </summary>
    void Update();

    /// <summary>
    /// �`��
    /// </summary>
    void Draw();

    ///�Q�b�^�[
    int GetItemFaze() { return isItemFaze_; };

    ///�Z�b�^�[
	void SetItemFaze(int isItemFaze__);

private:
    //�A�C�e���̍��W
    float PosX;
    float PosY;

    //�A�C�e�������蔻��̃T�C�Y
    int W;
    int H;

    //�A�C�e���̎��
    int ItemNum_;

    //�A�C�e���̈ړ��X�s�[�h
    int ItemSpeed;

    ///�A�C�e���t�F�[�Y�ɓ����Ă邩�ǂ���
    int isItemFaze_;
};
