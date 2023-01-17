#include"DxLib.h"
#include"flying_Armor.h"
#include"flying_Attack.h"
#include"flying_object.h"

#pragma once
class Player{
private:
	int JoyPadX, JoyPadY;    //�p�b�h���͒l
	float X, Y;              //X,Y���W
	float Width;             //�v���C���[�̕�
	float Speed;             //�ړ����x
	int MoveFlag;

public:
	Player();
	virtual~Player();

	void Update();
	void InitPad();
	void Draw();
	int GetX() { return (int)X; }
	int GetY() { return (int)Y; }

	bool Hit(Flying_Armor armor);
	bool Hit(Flying_Attack attack);
};