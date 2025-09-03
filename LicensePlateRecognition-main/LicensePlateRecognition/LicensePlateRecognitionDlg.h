
// LicensePlateRecognitionDlg.h: ͷ�ļ�
//

#pragma once
#include "pch.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include <map>
#include <iostream>
#include "io.h"
#include "PlateRecognizer.h"
#include  <stdio.h>
#include  <stdlib.h>

// CLicensePlateRecognitionDlg �Ի���
class CLicensePlateRecognitionDlg : public CDialogEx
{
	// ����
public:
	CLicensePlateRecognitionDlg(CWnd* pParent = nullptr);	// ��׼���캯��

															// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LICENSEPLATERECOGNITION_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	void DrawcvMat(cv::Mat m_cvImg, UINT ID);

	// ʵ��
protected:
	HICON m_hIcon;
	int foundmodel = 0;
	int tempmodel = -1;
	vector<vector<Mat>> DisplayImages;
	map<int, string> NumMap, ProvinceMap;
	PlateRecognizer NumModelHOG, ProvinceModelHOG, NumModelLBP, ProvinceModelLBP;
	void Display(int num);
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CFont f;
	bool keyframedectected = false;
	afx_msg void OnBnClickedOpenvideo();
	afx_msg void OnBnClickedOpenframe();
	afx_msg void OnBnClickedTrain();
	CString m_result;
	afx_msg void OnBnClickedReco1();
	afx_msg void OnBnClickedReco2();
	afx_msg void OnBnClickedReco3();
	afx_msg void OnBnClickedReco4();
	afx_msg void OnBnClickedReco5();
	afx_msg void OnBnClickedLbpsvm();
	
	CString m_value;
	afx_msg void OnBnClickedHogsvm();
	afx_msg void OnBnClickedTemp();
};
