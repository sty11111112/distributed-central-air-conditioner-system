#include "add_data.h"
#include "ADO.h"
#include "StdAfx.h"

add_data::add_data()
{
	//将信息写入数据库
	ADO m_Ado;								//ADO类对象，将信息写入数据库
	m_Ado.OnInitADOConn();					//连接数据库

	//计费
	CTime curTime = CTime::GetCurrentTime();
	CTimeSpan timeDiffer;
	int differ = 0;
	timeDiffer = curTime - beginTime[i];
	differ = timeDiffer.GetTotalSeconds();
	
	
	try
	{
		CString sql = "select * from details";			//设置查询字符串
		m_Ado.m_pRecordset = m_Ado.OpenRecordset(sql);	//打开记录集
		m_Ado.m_pRecordset->AddNew();					//添加新行
		
		CString num, opentime, aimTep;
		num.Format("%d", no);
		CTime curTime = CTime::GetCurrentTime();		//获取系统时间
		opentime = curTime.Format("%Y-%m-%d %H:%M:%S");
		aimTep.Format("%.1f ℃", ((float)CliBuffer.b) / 10);


		m_Ado.m_pRecordset->PutCollect("房间号", (_bstr_t)num);			//添加新记录
		m_Ado.m_pRecordset->PutCollect("请求起始时间", (_bstr_t)opentime);
		m_Ado.m_pRecordset->PutCollect("请求起始时间", (_bstr_t)closetime);
		m_Ado.m_pRecordset->PutCollect("目标温度", (_bstr_t)aimTep);
		m_Ado.m_pRecordset->PutCollect("是否被响", (_bstr_t)("是"));
		m_Ado.m_pRecordset->PutCollect("起始风速", (_bstr_t)beginSpeed);
		m_Ado.m_pRecordset->PutCollect("结束风速", (_bstr_t)endSpeed);
		m_Ado.m_pRecordset->PutCollect("起始温度", (_bstr_t)beginTep);
		m_Ado.m_pRecordset->PutCollect("结束温度", (_bstr_t)endTep);
		m_Ado.m_pRecordset->PutCollect("本次费用", (_bstr_t)sFee);
		m_Ado.m_pRecordset->Update();					//更新记录集
		m_Ado.CloseRecordset();							//关闭记录集
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description()); //弹出错误处理
	}
	m_Ado.CloseConn();					//关闭数据库连接
}