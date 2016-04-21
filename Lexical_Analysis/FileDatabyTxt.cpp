#include "stdafx.h"
#include "FileDatabyTxt.h"


CFileDatabyTxt::CFileDatabyTxt()
{
}


CFileDatabyTxt::~CFileDatabyTxt()
{
}


void CFileDatabyTxt::FileOpen()
{
	m_file.open(m_txtName, ofstream::out);
}


void CFileDatabyTxt::FileWrite(const string &fileData)
{
	m_file << fileData;
}


void CFileDatabyTxt::FileClose()
{
	m_file.close();
}
