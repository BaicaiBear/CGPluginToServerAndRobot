/*
* CakeGame SDK for VC++
* Api Version 12.5
* Written by SmallCake
*/
#include "stdafx.h"
#include ".\cgSdk\cgapi.h"
#include "tongbu.h"

#define TOSERVER "ͬ����������"
#define TOROBOT "ͬ����QQȺ"
#define SERVERGROUP 260645893

using namespace std;

string lastUid;
int ExtAuthCode;

/*
	_AuthCode
	���ڻ�ȡ��չ��AuthCode����ֹ�ڴ˺���������������
*/
CGEvent(int, __AuthCode, 4)(int AuthCode)
{
	ExtAuthCode = AuthCode;
	return 0;
}

/*
	_info_ext
	���ڷ�����չ������Ϣ
*/
CGEvent(const char *, __info_ext, 0)()
{
	CGSDK::CGJson result;
	result.update_item("apiVersion", Version);
	result.update_item("ext_name", "CGSDK_DEMO_V12.5");
	result.update_item("function", "����_cgSdkInfo,_menu_test_cgSdk|����_ȡ������Ʒ,_menu_test_knapsack");
	result.update_item("Event_ReceivedMsg", "_ext_event_ReceivedMsg");
	result.update_item("Event_ReceivedMsg_NT", "_ext_event_ReceivedMsg_NT");
	result.update_item("Event_TriggerFunction", "_ext_event_trigger");
	result.update_item("Event_Start", "_ext_event_start");
	result.update_item("Event_Suspend", "_ext_event_suspend");
	result.update_item("Event_AttributeChange", "_ext_event_AttributeChange");
	result.update_item("Event_GamePlayerDied", "_ext_event_GamePlayerDied");
	result.update_item("Event_Upgrade", "_ext_event_Upgrade");
	result.update_item("Event_KillMonster", "_ext_event_KillMonster");
	result.update_item("Event_ForcedCombat", "_ext_event_ForcedCombat");
	result.update_item("Event_AnalysisVariable", "_ext_event_AnalysisVariable");
	return result.get_cgjson();
}

/*
	_info_function
	���ڷ�����չ������Ϣ
*/
CGEvent(const char *, __info_function, 0)()
{
	CGSDK::CGJson ret;
	ret.update_item("��ʾ_����˽��", "����˽��|_demo_function1");
	return ret.get_cgjson();
}

/*
	_ext_close
	�ر�ʱ���ô˺���
*/
CGEvent(void, __ext_close, 0)()
{
	
}

/*
	_demo_function1
	����һ����Ϣ�ص���������Ӧ_info_function������Ϣ�е�"��ʾ_����˽��"
*/
CGEvent(const char *, __demo_function1, 16)(const char *msg, const char *type, const char *fromGroup, const char *fromUser)
{
	//����1<msg> ���ص���Ϣ
	//����2<type> ��Ϣ���ͣ�1Ϊ������Ϣ 2ΪȺ��Ϣ 3Ϊ��������Ϣ��
	//����3<fromGroup> ��ԴȺ��|������ţ�Ⱥ��ϢΪȺ�ţ���ԴΪ������Ϊ������ţ�����Ϊ�գ�
	//����4<fromUser> ��Դ�û�
	string msgs(msg);
	if (chartoint(formGroup) == SERVERGROUP)
	{
		if (msgs == TOSERVER) toserver(fromUser);
		if (msgs == TOROBOT) torobot(fromUser);
	}
}

/*
	_ext_event_trigger
	��Ҵ�������ʱ����
*/
CGEvent(const char *, __ext_event_trigger, 16)(const char *handle, const char *type, const char *fromGroup, const char *fromUser)
{
	//�����������ĸ��ı�������1.��������2.��Ϣ���ͣ�3.��ԴȺ�ţ�4.��Դ�û�
	lastUid = string(fromUser);
	return "";//���ؿ��ı���ʾ����ִ�У�����ֱ��������ص��ı�
}

/*
	_ext_event_start
	��CakeGame������ʱ�����˺���
*/
CGEvent(void, __ext_event_start, 0)()
{

}

/*
	_ext_event_suspend
	��CakeGame��ͣ��ʱ�����˺���(�˳�ʱ������ô˺���)
*/
CGEvent(void, __ext_event_suspend, 0)()
{

}

/*
	_ext_event_AttributeChange
	����ҵ����Է����仯ʱ��������Ӧ������Ա�����
*/
CGEvent(void, __ext_event_AttributeChange, 12)(const char *fromUser, const char *Node, const char *Val)
{
	//���������������ı�������1.��Դ�û���2.���޸ĵ����ԣ�3.�޸ĺ������ֵ
}

/*
	_ext_event_GamePlayerDied
	�������ʱ�����˺���
*/
CGEvent(void, __ext_event_GamePlayerDied, 12)(const char *fromUser, const char *object, const char *isUser)
{
	//���������������ı�������1.��Դ�û���2.Ŀ������(���ʱΪID)��3.�Ƿ���һ�ɱ(���ʱ����һ�ɱֵΪ"TRUE")
}

/*
	_ext_event_Upgrade
	�������ʱ�����˺���
*/
CGEvent(void, __ext_event_Upgrade, 4)(const char *fromUser)
{
	//����������һ���ı��Ͳ�����1.��Դ�û�
}

/*
	_ext_event_KillMonster
	��һ�ɱ����ʱ�����˺���
*/
CGEvent(void, __ext_event_KillMonster, 8)(const char *fromUser, const char *mName)
{
	//���������������ı�������1.��Դ�û���2.��ɱĿ��
}

/*
	_ext_event_ForcedCombat
	��ұ�����ǿ��ս��ʱ�����˺���
*/
CGEvent(void, __ext_event_ForcedCombat, 8)(const char *fromUser, const char *mName)
{
	//���������������ı�������1.��Դ�û���2.��������
}

/*
	_ext_event_ReceivedMsg
	�¼�_�յ���Ϣ ������Ϣ���պ���һʱ�䴥�����¼�
*/
CGEvent(const char *, __ext_event_ReceivedMsg, 16)(const char *type, const char *fromQQ, const char *fromGroup, const char *Msg)
{
	//�����������ĸ�������1.��Ϣ����, 2.��Դ�û�, 3.��ԴȺ��, 4.��Ϣ����
	return "";
}

/*
	_ext_event_ReceivedMsg_NT
	�¼�_������Ϣ δ�����������Ϣ
*/
CGEvent(const char *, __ext_event_ReceivedMsg_NT, 16)(const char *type, const char *fromQQ, const char *fromGroup, const char *Msg)
{
	//�����������ĸ�������1.��Ϣ����, 2.��Դ�û�, 3.��ԴȺ��, 4.��Ϣ����
	return "";
}

/*
	_ext_event_AnalysisVariable
	CakeGame�������ʱ�����˺���
*/
CGEvent(const char *, __ext_event_AnalysisVariable, 16)(const char *User, const char *Data, const char *OriginalData, const char *type)
{
	//�����������ĸ��ı�������1.�����û�,2.��������,3.����ԭ����(CakeGame����ǰ������),4.����(��start��ΪCakeGame��ʼ����ǰ����end��ΪCakeGame�����)
	string result;
	result = string(Data);
	//**********��ʼ��д�������**********
	if (string(type) == "start") {
		//CakeGame����ǰ
	}
	if (string(type) == "end") {
		//CakeGame�����
	}
	//**********END**********
	return CGSDK::str2char(result);
}

/*
	_menu_test_cgSdk
	�˵�����
*/
CGEvent(void, __menu_test_cgSdk, 0)()
{
	MessageBoxA(0, "CakeGame SDK(C++) 12.5 By SmallCake", "Info:", 64);
}

/*
	_menu_test_knapsack
	�˵�����
*/
CGEvent(void, __menu_test_knapsack, 0)()
{
	MessageBoxA(0, _get_knapsack_all_cgjson(CGSDK::str2char(lastUid), false), "Test:", 64);
}