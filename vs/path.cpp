#include "path.h"
#include<iostream>

/*
�ݹ�����ָ��·���µ������ļ�������������Ŀ¼�е��ļ����������ǵ�·���洢�������С�
*/
void getFileNames(string path, vector<string>& files)
{
	intptr_t   hFile = 0;//��������ڲ����ļ�
	struct _finddata_t fileinfo;//�ṹ�壬�洢�ļ���Ϣ
	string p;
	cout << "�ļ�·��" << path << endl;
	//path·���µ������ļ����ҵ����طǸ����
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))//�����ǰ�ļ���һ��Ŀ¼
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					//cout << "��ǰ�ļ���һ��Ŀ¼" << p.assign(path).append("\\").append(fileinfo.name) << endl;
					//getFileNames(p.assign(path).append("\\").append(fileinfo.name), files);//������һ��Ѱ���ļ�
					cout << "�Ҿ���һ����Ŀ\n";
			}
			else
			{
				//cout << "��ǰ�ļ���Ҫ����ס��" << p.assign(path).append("\\").append(fileinfo.name) << endl;
				files.push_back(p.assign(path).append("/").append(fileinfo.name));//�洢����·��
			}
		} while (_findnext(hFile, &fileinfo) == 0);//ֱ��ȫ������
		_findclose(hFile);
	}
}


