#pragma once


//��s���́@�̃x�[�X�i���N���X�j
class Flying_object
{
public:
	//�R���X�g���N�^
	Flying_object(int x, int y, int w, int h, int speed);

	//�f�X�g���N�^
	~Flying_object();

	virtual void Update() = 0;   //�X�V
	virtual void Draw() = 0;     //�`��

	bool CheckScreenOut();       //��ʊO�ɂ��邩�`�F�b�N�@true : ��ʊO�@false : ��ʓ�

private:

protected:

	int x;     //�����W
	int y;     //�����W
	const int w;     //��
	const int h;     //����

	int speed; //�X�s�[�h
};