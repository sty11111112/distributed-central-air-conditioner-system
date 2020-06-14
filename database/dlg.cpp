#include "StdAfx.h"
#include "dlg.h"
#include "ADO.h"


void dlg::get_dlg() {
	ADO m_Ado;								//ADO����󣬽���Ϣд�����ݿ�
	m_Ado.OnInitADOConn();					//�������ݿ�

	int i = 0, k = 0;
	int tFee = 0;
	CString sql_str, str, temp;
	//�Ʒ�
	CTime curTime = CTime::GetCurrentTime();
	CTimeSpan timeDiffer;
	int differ = 0;
	timeDiffer = curTime - beginTime[i];
	differ = timeDiffer.GetTotalSeconds();


	try
	{
		CString sql = "select * from dialog";			//���ò�ѯ�ַ���

		m_Ado.m_pRecordset = m_Ado.OpenRecordset(sql);	//�򿪼�¼��
		m_Ado.m_pRecordset->AddNew();					//�������

		CString num, opentime, aimTep;
		num.Format("%d", i + 1);
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

		sql_str = "select �����, count(��������) as ����, sum (���η���) as ���� from details where ������ʼʱ��";
		
		str = curTime.Format(" like '%Y-%m-%d%%' ");
		sql_str += str;
		
		try
		{
			
			sql_str += "group by �����";
			m_Ado.m_pRecordset = m_Ado.OpenRecordset(sql_str);
			m_Ado.m_pRecordset->Requery(0);

			while (!m_Ado.m_pRecordset->adoEOF)
			{
				str = (char *)(_bstr_t)m_Ado.m_pRecordset->GetCollect("�����");
				for (k = 1; k <= 15; ++k)
				{
					temp.Format("%d", k);
					if (!str.Compare(temp))
						break;
				}
				tFee += (_bstr_t)m_Ado.m_pRecordset->GetCollect("���η���");

				m_Ado.m_pRecordset->MoveNext();
				
			}
				
			
		}
		catch (_com_error e)
		{
			AfxMessageBox(e.Description()); //����������
		}

		m_Ado.m_pRecordset->PutCollect("�ܷ���", (_bstr_t)tFee);
		m_Ado.m_pRecordset->Update();					//���¼�¼��
		m_Ado.CloseRecordset();							//�رռ�¼��
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description()); //����������
	}
	m_Ado.CloseConn();					//�ر����ݿ�����

}