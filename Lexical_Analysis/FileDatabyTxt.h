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
	ofstream m_file;			            //文件写入流
	const string m_txtName = "./lex.txt";   //文件存储位置
};

