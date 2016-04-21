#pragma once
#include "StateManger.h"
#include "CharacterTable.h"

class CTranslateRelation
{
public:
	CTranslateRelation();
	~CTranslateRelation();
private:
	CCharacterTable *m_chaTable;		//�ַ���
	CStateManger *m_stamanager;			//״̬��
	CSTATE **m_tranlist;				//״̬ת�������ö�ά��̬���齨��������һ��λ���ַ�״̬ת��
public:
	void TranslateRelationInit(CCharacterTable& m_chaTable, CStateManger& m_stamanager);	//״̬ת����ĳ�ʼ��
	void TranslateRelationBulit(const string& l, const string& r, const char& conduct);		//״̬ת����Ľ���
	CSTATE GetNextState(const CSTATE& now_State, const char& ptr);							//��ptr�����µõ���һ��״̬
};