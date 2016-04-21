#include "stdafx.h"
#include "InformationManager.h"


CInformationManager::CInformationManager()
{
	m_Reservedword.clear();
	m_Reservedword.push_back("if");
	m_Reservedword.push_back("else");
	m_Reservedword.push_back("for");
	m_Reservedword.push_back("while");
	m_Reservedword.push_back("do");
	m_Reservedword.push_back("int");
	m_Reservedword.push_back("write");
	m_Reservedword.push_back("read");
}

CInformationManager::~CInformationManager()
{
}


void CInformationManager::Init()
{
	m_keyWord.clear();
	m_UnsignedNum.clear();
	m_Identifier.clear();
	m_Delimiter.clear();
	m_Operator.clear();
	m_Note.clear();
	m_WrongHint.clear();

	m_filebyTxt.FileOpen();
	m_filebyTxt.FileWrite("�ɹ�ʶ�����������:\n");
}



void CInformationManager::Hint_Category(int stateNum, const string& str)
{
	if (stateNum == 1)
	{
		vector<string>::iterator result = find(m_Reservedword.begin(), m_Reservedword.end(), str);
		if (result == m_Reservedword.end());
		else stateNum = 2;

	}

	switch (stateNum)
	{
	case 2:PushString(m_keyWord, str);
	case 1:PushString(m_Identifier, str);break;
	case 3:
	case 4:PushString(m_UnsignedNum, str);break;
	case 5:PushString(m_Delimiter, str);break;
	case 6:
	case 8:PushString(m_Operator, str);break;
	case 12:PushString(m_Note, str);break;
	}
}


void CInformationManager::PushString(vector<string> & vec, const string& str)
{
	vector<string>::iterator result = find(vec.begin(), vec.end(), str);
	if (result != vec.end()) return;
	vec.push_back(str);
}


void CInformationManager::PushWrongHint(const string & str)
{
	m_WrongHint.push_back(str);
}

void CInformationManager::IdentifierHintInfo()
{
	int ptr = m_Identifier.size();
	if (!ptr) return;
	m_fileData = "��ʶ��:";
	cout << m_fileData;
	for (int i = 0;i < ptr;i++)
	{
		cout << m_Identifier[i] << ' ';
		m_fileData += (m_Identifier[i] + ' ');
	}
	m_fileData += '\n';
	m_filebyTxt.FileWrite(m_fileData);
	cout << endl;
}


void CInformationManager::ReservedWordHintInfo()
{
	int ptr = m_keyWord.size();
	if (!ptr) return;
	m_fileData = "������:";
	cout << m_fileData;
	for (int i = 0;i < ptr;i++)
	{
		cout << m_keyWord[i] << ' ';
		m_fileData += (m_keyWord[i] + ' ');
	}
	m_fileData += '\n';
	m_filebyTxt.FileWrite(m_fileData);
	cout << endl;
}


void CInformationManager::UnsignedNumHintInfo()
{
	int ptr = m_UnsignedNum.size();
	if (!ptr) return;
	m_fileData = "�޷�������:";
	cout << m_fileData;
	for (int i = 0;i < ptr;i++)
	{
		cout << m_UnsignedNum[i] << ' ';
		m_fileData += (m_UnsignedNum[i] + ' ');
	}
	m_fileData += '\n';
	m_filebyTxt.FileWrite(m_fileData);
	cout << endl;
}


void CInformationManager::DelimiterHintInfo()
{
	int ptr = m_Delimiter.size();
	if (!ptr) return;
	m_fileData = "�ֽ��:";
	cout << m_fileData;
	for (int i = 0;i < ptr;i++)
	{
		cout << m_Delimiter[i] << ' ';
		m_fileData += (m_Delimiter[i] + ' ');
	}
	m_fileData += '\n';
	m_filebyTxt.FileWrite(m_fileData);
	cout << endl;
}


void CInformationManager::OperatorHintInfo()
{
	int ptr = m_Operator.size();
	if (!ptr) return;
	m_fileData = "�����:";
	cout << m_fileData;
	for (int i = 0;i < ptr;i++)
	{
		cout << m_Operator[i] << ' ';
		m_fileData += (m_Operator[i] + ' ');
	}
	m_fileData += '\n';
	m_filebyTxt.FileWrite(m_fileData);
	cout << endl;
}


void CInformationManager::NoteHintInfo()
{
	int ptr = m_Note.size();
	if (ptr != 0)
	{
		m_fileData = "ע������:\n";
		cout << m_fileData;
		for (int i = 0;i < ptr;i++)
		{
			cout << m_Note[i] << '\n';
			m_fileData += (m_Note[i] + '\n');
		}
		m_filebyTxt.FileWrite(m_fileData);
		cout << endl;
	}
	m_filebyTxt.FileClose();//ʶ������д����ĵ��ڴ��������һ����Ϣ��ر�
}



void CInformationManager::WrongHintInfo()
{
	int ptr = m_WrongHint.size();
	if (!ptr) return;
	cout << "�ļ��������,�����б�����:\n";
	for (int i = 0;i < ptr;i++)
		cout << m_WrongHint[i] << endl;
}
