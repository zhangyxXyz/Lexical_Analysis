#include "stdafx.h"
#include "Engine.h"

CEngine::CEngine()
{
}


CEngine::~CEngine()
{
}


void CEngine::Init()
{
	m_indexLine = 0;
	m_terminal = false;
	m_now_Data = m_rest_Data = "";
	m_nowStateStartline = 1;
	m_now_index = m_pre_index = -1;
	m_now_State = CSTATE("START", false);
	m_CharacterTable.CharacterTableInit();
	m_StateManger.StateInit();
	m_TransRelation.TranslateRelationInit(m_CharacterTable, m_StateManger);
	m_infManager.Init();
}


bool CEngine::OpenFile(const string& m_filePath)
{
	m_file.open(m_filePath, std::ios::in);
	if (m_file.fail())
	{
		cout << "�ļ���ȡʧ�ܣ����������룺\n\t";
		return false;
	}
	return true;
}


void CEngine::FileReader()
{
	while (m_file.getline(m_dataBuff, sizeof(m_dataBuff)))
	{
		m_nowFileData.clear();
		m_nowFileData.append(m_dataBuff);
		m_nowFileData += "\n";
		DataConduct(m_nowFileData);
	}
	FinalStateJudge();
	m_infManager.WrongHintInfo();
	if (m_rest_Data.length())
		cout << "�ɹ�ʶ�����������:\n";
	m_infManager.IdentifierHintInfo();
	m_infManager.ReservedWordHintInfo();
	m_infManager.UnsignedNumHintInfo();
	m_infManager.DelimiterHintInfo();
	m_infManager.OperatorHintInfo();
	m_infManager.NoteHintInfo();
}


void CEngine::DataConduct(const string& nowConductData)
{
	m_indexLine++;															//��¼��ǰ��
	m_pre_index = -1;														//��ǰ״̬��ʶ���ʾ����ʼλ�õ�ǰһλ
	m_now_Data = m_rest_Data + nowConductData;								
	for (int i = m_rest_Data.length();i < m_now_Data.length();i++)			//ѭ������ǰ��ÿһλ
	{
		m_pre_State = m_now_State;											//״̬�л�ǰ�ɵ�ǰ״̬��ֵ��ǰһ��״̬
		if (NoteSpecialJudge(i) == false)									//״̬�л���Ѱ����һ��״̬
			m_now_State = m_TransRelation.GetNextState(m_now_State, m_now_Data[i]);
		if (m_now_State.m_isEnd == true)									//�ж��Ƿ�����̬
		{
			m_now_index = i;												//��¼����̬��ʶ����ַ�λ��
			m_last_State = m_now_State;										//��¼��һ�ε���̬�������ж�����
			m_terminal = true;												
		}
		if (m_now_State == CSTATE("WRONG", false))							//��ǰ״̬���������Error״̬��������ж�
		{
			(m_terminal == false) ? WrongHintManger(i) : Right_DataAnalysis(i);
			m_pre_State = m_now_State;
			m_now_State = CSTATE("START", false);							//״̬����
			m_nowStateStartline = m_indexLine;

		}
	}
	m_rest_Data = string(m_now_Data, m_pre_index + 1, m_now_Data.length());//�ѵ�ǰ�е�δ�ս��״̬��ʶ���ַ�������һ��
	m_now_index -= (m_pre_index + 1);
}


bool CEngine::NoteSpecialJudge(int ptr)
{
	if (m_now_State == CSTATE("NOTE_START", false) && m_now_Data[ptr] != '*') return true;
	else if (m_now_State == CSTATE("NOTE_END_BUFF", false))
	{
		if (m_now_Data[ptr] != '/')  m_now_State = CSTATE("NOTE_START", false);
		else m_now_State = CSTATE("NOTE_END", true);
		return true;
	}
	return false;
}


void CEngine::FinalStateJudge()
{
	if (m_now_State.m_isEnd == true) return;
	stringstream s;
	s << m_nowStateStartline;
	string str = "Line " + s.str();
	int case_ptr = m_StateManger.GetNumByState(m_now_State);
	switch (case_ptr)
	{
	case 10:
	case 11:
		if (m_nowStateStartline == m_indexLine)
			str += ":�����ʹ����ע��\n";
		else str += ":�ӱ��п�ʼ��ע��û��ע�ͽ�β\n";
		str += "����ע����������\n" + m_rest_Data;
		m_infManager.PushWrongHint(str);break;
	default:break;
	}
}



void CEngine::WrongHintManger(int &ptr)
{
	stringstream s;
	string str = "";
	s << m_indexLine;
	if (m_CharacterTable.JudgeCharacter(m_now_Data[ptr]) == false)
		str = "Line " + s.str() + ":�����޷�ʶ��ķ��� " + m_now_Data[ptr];

	else
		str = "Line " + s.str() + ":�����ʹ���� " + m_now_Data[--ptr];
	m_infManager.PushWrongHint(str);
	m_pre_index = m_now_index = ptr;
}


void CEngine::Right_DataAnalysis(int &ptr)
{
	if (m_last_State != CSTATE("SPACE", true))
	{
		string str = string(m_now_Data, m_pre_index + 1, m_now_index - m_pre_index);
		m_infManager.Hint_Category(m_StateManger.GetNumByState(m_pre_State), str);
		//cout << "ʶ��ɹ�: " << str << endl;
	}
	m_terminal = false;
	m_pre_index = m_now_index;
	ptr = m_now_index;				//��ǰ�����ַ��±����
}

void CEngine::CloseFile()
{
	if (m_file.fail())
		return;
	m_file.close();
}
