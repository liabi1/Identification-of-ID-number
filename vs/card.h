#include <iostream>
#include <string>
#include <vector>
#include <map>//python��ֵ��
#include <algorithm>//�㷨�����⣬game���Ƶ���������ã���ͷβ
#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>//svm��������
using namespace std;
using namespace cv;
using namespace cv::ml;

class Card
{
public:
	Card();													//��ֵ�԰�
	~Card();

	// �û��ӿ�
	const int identify(const string path, string& txt);		// ʶ��
	void show(string winName, const int x = 0, const int y = 0); // ��ʾ��ѡ��ʶ���ͼƬ
	void setPicFolderPath(const string path);				// ����ͼƬ�ļ���·��
	void setTrainDataFolderPath(const string path);			// ���� SVM ѵ������·��
	void setTrain(string _TRAIN);							// �����Ƿ�ѵ�� SVM
	void setDebug(string _Debug);							// ���� Debug ģʽ
	bool is_DEBUG();										// ����ģʽ
	void setSavePath(const string path);					// ����ʶ��������·��
	const string getPicFolderPath();						// ��ȡͼƬ�ļ���·��

private:
	// ���֤����
	Mat idcard;												// ���֤ԭͼ
	Mat img;												// ����ͼ
	Mat idcardNumber;										// ��������ͼ
	vector<Mat> idcardNumbers;								// �����и�ɵ��ַ���֤����
	vector<RotatedRect> rotatedRects;						// ��⵽����ͨ��
	Ptr<SVM> svm;											// SVM ������
	vector<int> predictNumber;								// �������ʶ����
	string trainDataFolderPath;								// �����ļ���·��
	string imgFolderPath;									// ��ʶ��ͼƬ�ļ���·��
	string imgPath;											// ͼƬ·��	
	string savePath;										// ʶ��������·��
	bool TRAIN = true;										// �Ƿ�ѵ�� SVM
	bool DEBUG = false;										// �Ƿ� DEBUG ģʽ
	map<int, string> mapPlace;								// ���֤ǰ��λ����ص�ӳ��
	float time = 0;											// ʶ��ʱ��

	// ʵ�ֺ���
	void resize(const int toRows = 800, const int toCols = 800);	// ԭͼ����������Ԥ���С
	void resize(Mat& img);											// ���ֳߴ��һ��
	void preDeal();											// Ԥ�������š��˲�����Ե����ֵ��
	const int detect();										// �����ͨ��
	const int findNumber();									// �ҳ���ͨ���еĺ�������
	//void thin();											// ϸ�������п��� δʵ�֣�
	const int correct();									// β��У��
	const int predict();									// ʶ�����
	//void twoPass();											// ����ɨ�跨 �����ͨ��
	void release();											// ÿ��ʶ����һ�����֤��Ҫ�ͷ��ڴ�
};
