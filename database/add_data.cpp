#include "add_data.h"
#include "ADO.h"
#include "StdAfx.h"

add_data::add_data()
{
	//����Ϣд�����ݿ�
	ADO m_Ado;								//ADO����󣬽���Ϣд�����ݿ�
	m_Ado.OnInitADOConn();					//�������ݿ�

	//�Ʒ�
	CTime curTime = CTime::GetCurrentTime();
	CTimeSpan timeDiffer;
	int differ = 0;
	timeDiffer = curTime - beginTime[i];
	differ = timeDiffer.GetTotalSeconds();
	
	
	try
	{
		CString sql = "select * from details";			//���ò�ѯ�ַ���
		m_Ado.m_pRecordset = m_Ado.OpenRecordset(sql);	//�򿪼�¼��
		m_Ado.m_pRecordset->AddNew();					//�������
		
		CString num, opentime, aimTep;
		num.Format("%d", no);
		CTime curTime = CTime::GetCurrentTime();		//��ȡϵͳʱ��
		opentime = curTime.Format("%Y-%m-%d %H:%M:%S");
		aimTep.Format("%.1f ��", ((float)CliBuffer.b) / 10);


		m_Ado.m_pRecordset->PutCollect("�����", (_bstr_t)num);			//����¼�¼
		m_Ado.m_pRecordset->PutCollect("������ʼʱ��", (_bstr_t)opentime);
		m_Ado.m_pRecordset->PutCollect("������ʼʱ��", (_bstr_t)closetime);
		m_Ado.m_pRecordset->PutCollect("Ŀ���¶�", (_bstr_t)aimTep);
		m_Ado.m_pRecordset->PutCollect("�Ƿ���", (_bstr_t)("��"));
		m_Ado.m_pRecordset->PutCollect("��ʼ����", (_bstr_t)beginSpeed);
		m_Ado.m_pRecordset->PutCollect("��������", (_bstr_t)endSpeed);
		m_Ado.m_pRecordset->PutCollect("��ʼ�¶�", (_bstr_t)beginTep);
		m_Ado.m_pRecordset->PutCollect("�����¶�", (_bstr_t)endTep);
		m_Ado.m_pRecordset->PutCollect("���η���", (_bstr_t)sFee);
		m_Ado.m_pRecordset->Update();					//���¼�¼��
		m_Ado.CloseRecordset();							//�رռ�¼��
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description()); //����������
	}
	m_Ado.CloseConn();					//�ر����ݿ�����
}