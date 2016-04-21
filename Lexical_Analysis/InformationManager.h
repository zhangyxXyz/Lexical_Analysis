#pragma once
#include "StateManger.h"
#include "FileDatabyTxt.h"
class CInformationManager
{
public:
	CInformationManager();
	~CInformationManager();
private:
	vector<string> m_Reservedword;						//��׼�ؼ���
	vector<string> m_keyWord;							//ʶ��Ĺؼ���
	vector<string> m_UnsignedNum;						//�޷�������
	vector<string> m_Identifier;						//��ʶ��
	vector<string> m_Delimiter;							//�ֽ��
	vector<string> m_Operator;							//�����
	vector<string> m_Note;								//ע��
	vector<string> m_WrongHint;							//������Ϣ
	
	CFileDatabyTxt m_filebyTxt;							//���ݴ��������
	string m_fileData;									//��Ҫд����ı���Ϣ
public:
	void Init();
	void Hint_Category(int stateNum, const string& str);			//��Ϣ����

	void PushString(vector<string> & vec, const string& str);		//����������Ϣ
	void PushWrongHint(const string & str);

	//���������Ϣ
	void IdentifierHintInfo();
	void ReservedWordHintInfo();
	void UnsignedNumHintInfo();
	void DelimiterHintInfo();
	void OperatorHintInfo();
	void NoteHintInfo();
	void WrongHintInfo();

};

