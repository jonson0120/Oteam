#include"DxLib.h"
#include"flying_object.h"

//�R���X�g���N�^
Flying_object::Flying_object(int x, int y, int w, int h, int speed)
	: x(x), y(y), w(w), h(h), speed(speed)
{
	//�@���@�������w��q�ŕϐ������������Ă܂�
}

//�f�X�g���N�^
Flying_object::~Flying_object()
{

}

//��ʊO�ɂ��邩�`�F�b�N�@true : ��ʊO�@false : ��ʓ�
bool Flying_object::CheckScreenOut()
{
	// x �� 0��菬�����@�܂��́@1280���傫��
	if (x < -10) return true;
	if (y < -10 || y > 730) return true;

	//����ȊO�͉�ʓ�
	return false;
}

