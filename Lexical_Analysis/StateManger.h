#pragma once

//����״̬�ľ������,ÿһ��״̬�����Ը�CSTATE�������
class CSTATE
{
public:
	string m_name;			//״̬����
	bool m_isEnd;			//�Ƿ�Ϊ��̬
	CSTATE() = default;
	CSTATE(const string& name, const bool& judge);
	~CSTATE() {}
public:
	bool operator==(const CSTATE &state)const;
	bool operator!=(const CSTATE &state)const;
};


class CStateManger
{
public:
	CStateManger();
	~CStateManger();
	void StateInit();														//��״̬��ʼ��
private:
	map<string, int> m_stateList;											//״̬ӳ���ӳ��Ϊ����
	pair<map<string, int>::iterator, map<string, int>::iterator> m_Search;	//״̬��Ӧ��������
	vector<CSTATE> m_state;													//�������״̬

public:
	CSTATE GetStateByNum(const int& ptr);										//ͨ���������״̬
	int GetNumByState(const CSTATE& ptr);										//ͨ��״̬�������
	int GetSize();																//����״̬����С�����ڽ�����ϵ��
	CSTATE GetStateByName(const string& ptr);									//ͨ����������״̬
	int GetNumByName(const string& ptr);										//ͨ�������������
};


//<summary>����״̬���ռ�����<summary>
///		IDENTIFIER,						��ʶ��״̬
///     RESERVED_WORD,					������״̬
///		NUM_NORMAL,						��������״̬
///		NUM_ZERO,						����0״̬
///		DELIMITER,						�ֽ��״̬
///		OPERATOR,						�����״̬
///		UNDEFINE_MARK,					����������״̬
///		OPERATOR_TWO_BUFF,				�������ַ����ɵ���������м�״̬
///		OPERATOR_DIV_NOTE_BUFF,			����������ע�ͷ����ٽ��ж�״̬
///		NOTE_START,						ע����ʼ״̬
///		NOTE_END_BUFF,					ע���յ��ٽ�״̬
///		NOTE_END,						ע���ս�״̬
///		SPACE,							�ո���߻���״̬
///		WRONG							����״̬
///		START							��ʼ״̬