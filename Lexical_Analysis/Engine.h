#pragma once
#include "CharacterTable.h"
#include "StateManger.h"
#include "TranslateRelation.h"
#include "InformationManager.h"
class CEngine
{
public:
	CEngine();
	~CEngine();
private:
	ifstream m_file;									//�ļ���ȡ��
	char m_dataBuff[1024];								//���ж�ȡ�ı����ı����ݻ���
	string m_nowFileData;								//��ǰ��������
	CCharacterTable m_CharacterTable;
	CStateManger m_StateManger;
	CTranslateRelation m_TransRelation;
	CInformationManager m_infManager;
	
	int m_indexLine;									//��ǰ����ڼ���
	int m_nowStateStartline;							//��ǰ״̬�Ĵ�����ʼ��

	CSTATE m_now_State;									//��ǰ״̬
	CSTATE m_last_State;								//��ǰ״̬��ǰһ״̬
	CSTATE m_pre_State;									//��һ���ս�״̬


	string m_rest_Data;									//��ǰδ��ֹ��״̬����������ʶ���ַ�
	string m_now_Data;									//��ǰ��������

	bool m_terminal;									//�Ƿ�Ϊ�ս��

	int m_now_index;									//״̬��������ֹ״̬ʱ��Ӧ���ַ��±�
	int m_pre_index;									//����һ��״̬��ʱ��Ӧ���ַ��±�
public:
	void Init();
	bool OpenFile(const string& m_filePath);		    //�򿪴������ļ�
	void FileReader();									//��ȡ�������ı�����
	void DataConduct(const string& nowConductData);		//��ȡ���ݴ���
	void FinalStateJudge();								//�ļ�������ɺ��ж����һ��״̬��
	bool NoteSpecialJudge(int ptr);						//��ע�͵����⴦����ʶ�����ģ�
	void WrongHintManger(int &ptr);						//������Ϣͳ��
	void Right_DataAnalysis(int &ptr);					//��ȷ��Ϣ�ķ���
	void CloseFile();									//�ر��ļ�
};
