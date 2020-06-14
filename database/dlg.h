#if !defined(AFX_QUERYDLG_H__2E780155_2E30_4662_BB8A_976AE3E05982__INCLUDED_)
#define AFX_QUERYDLG_H__2E780155_2E30_4662_BB8A_976AE3E05982__INCLUDED_
#include<atltime.h>
#include "StdAfx.h"
using namespace std;

#define MAX_CONNECT	15

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//

/////////////////////////////////////////////////////////////////////////////
//dialog

class dlg
{
	
public:
	int curTem[MAX_CONNECT];
	int speed[MAX_CONNECT];
	int purTem[MAX_CONNECT];
	CTime beginTime[MAX_CONNECT];
	float fee[MAX_CONNECT];

	void get_dlg();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYDLG_H__2E780155_2E30_4662_BB8A_976AE3E05982__INCLUDED_)
#pragma once
