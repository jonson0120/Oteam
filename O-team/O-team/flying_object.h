#pragma once


//��s���́@�̃x�[�X�i���N���X�j
class Flying_object
{
public:
	//�R���X�g���N�^
	Flying_object(float x, float y, float w, float h, float speed);

	//�f�X�g���N�^
	~Flying_object();

	virtual void Update() = 0;   //�X�V
	virtual void Draw() = 0;     //�`��

private:

protected:

	float x;     //�����W
	float y;     //�����W
	const float w;     //��
	const float h;     //����

	float speed; //�X�s�[�h
};