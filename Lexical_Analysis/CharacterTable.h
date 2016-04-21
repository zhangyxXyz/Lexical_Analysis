#pragma once
class CCharacterTable
{
public:
	CCharacterTable();
	~CCharacterTable();
	void CharacterTableInit();
private:
	map<char, int> m_letter;													//�ַ�ӳ��Ϊ���ֱ��
	pair<map<char, int>::iterator, map<char, int>::iterator> m_Search;  		//��������
public:
	int GetTableSize();															//�����ַ����С�����ڽ�����ϵ��
	bool JudgeCharacter(const char& ptr);										//�ж��ַ��Ƿ���ӳ�����
	int GetNumByChar(const char& ptr);											//ͨ���ַ��������
	char GetCharByNum(const int& ptr);											//ͨ����������ַ�
};