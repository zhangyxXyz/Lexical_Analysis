#pragma once
class CFileDatabyTxt
{
public:
	CFileDatabyTxt();
	~CFileDatabyTxt();
	void FileOpen();
	void FileWrite(const string &fileData);
	void FileClose();
private:
	ofstream m_file;			            //�ļ�д����
	const string m_txtName = "./lex.txt";   //�ļ��洢λ��
};

