/*
* CakeGame SDK for VC++
* Api Version 12.5
* Written by SmallCake
*/
#include "stdafx.h"
#include ".\cgSdk\cgapi.h"
#include "tongbu.h"

#define TOSERVER "同步到服务器"
#define TOROBOT "同步到QQ群"
#define SERVERGROUP 260645893

using namespace std;

string lastUid;
int ExtAuthCode;

/*
	_AuthCode
	用于获取扩展的AuthCode，禁止在此函数进行其它操作
*/
CGEvent(int, __AuthCode, 4)(int AuthCode)
{
	ExtAuthCode = AuthCode;
	return 0;
}

/*
	_info_ext
	用于返回扩展基本信息
*/
CGEvent(const char *, __info_ext, 0)()
{
	CGSDK::CGJson result;
	result.update_item("apiVersion", Version);
	result.update_item("ext_name", "CGSDK_DEMO_V12.5");
	result.update_item("function", "测试_cgSdkInfo,_menu_test_cgSdk|测试_取背包物品,_menu_test_knapsack");
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
	用于返回扩展功能信息
*/
CGEvent(const char *, __info_function, 0)()
{
	CGSDK::CGJson ret;
	ret.update_item("演示_发送私聊", "发送私聊|_demo_function1");
	return ret.get_cgjson();
}

/*
	_ext_close
	关闭时调用此函数
*/
CGEvent(void, __ext_close, 0)()
{
	
}

/*
	_demo_function1
	这是一个消息回调函数，对应_info_function返回信息中的"演示_发送私聊"
*/
CGEvent(const char *, __demo_function1, 16)(const char *msg, const char *type, const char *fromGroup, const char *fromUser)
{
	//参数1<msg> 返回的消息
	//参数2<type> 消息类型（1为好友消息 2为群消息 3为讨论组消息）
	//参数3<fromGroup> 来源群号|讨论组号（群消息为群号，来源为讨论组为讨论组号，其他为空）
	//参数4<fromUser> 来源用户
	string msgs(msg);
	if (chartoint(formGroup) == SERVERGROUP)
	{
		if (msgs == TOSERVER) toserver(fromUser);
		if (msgs == TOROBOT) torobot(fromUser);
	}
}

/*
	_ext_event_trigger
	玩家触发功能时触发
*/
CGEvent(const char *, __ext_event_trigger, 16)(const char *handle, const char *type, const char *fromGroup, const char *fromUser)
{
	//参数：共有四个文本参数，1.处理句柄，2.消息类型，3.来源群号，4.来源用户
	lastUid = string(fromUser);
	return "";//返回空文本表示继续执行，否则直接输出返回的文本
}

/*
	_ext_event_start
	当CakeGame被启用时触发此函数
*/
CGEvent(void, __ext_event_start, 0)()
{

}

/*
	_ext_event_suspend
	当CakeGame被停用时触发此函数(退出时不会调用此函数)
*/
CGEvent(void, __ext_event_suspend, 0)()
{

}

/*
	_ext_event_AttributeChange
	当玩家的属性发生变化时触发，对应玩家属性表属性
*/
CGEvent(void, __ext_event_AttributeChange, 12)(const char *fromUser, const char *Node, const char *Val)
{
	//参数：共有三个文本参数，1.来源用户，2.被修改的属性，3.修改后的属性值
}

/*
	_ext_event_GamePlayerDied
	玩家死亡时触发此函数
*/
CGEvent(void, __ext_event_GamePlayerDied, 12)(const char *fromUser, const char *object, const char *isUser)
{
	//参数：共有三个文本参数，1.来源用户，2.目标名称(玩家时为ID)，3.是否被玩家击杀(如果时被玩家击杀值为"TRUE")
}

/*
	_ext_event_Upgrade
	玩家升级时触发此函数
*/
CGEvent(void, __ext_event_Upgrade, 4)(const char *fromUser)
{
	//参数：共有一个文本型参数，1.来源用户
}

/*
	_ext_event_KillMonster
	玩家击杀怪物时触发此函数
*/
CGEvent(void, __ext_event_KillMonster, 8)(const char *fromUser, const char *mName)
{
	//参数：共有两个文本参数，1.来源用户，2.击杀目标
}

/*
	_ext_event_ForcedCombat
	玩家被进入强制战斗时触发此函数
*/
CGEvent(void, __ext_event_ForcedCombat, 8)(const char *fromUser, const char *mName)
{
	//参数：共有两个文本参数，1.来源用户，2.怪物名称
}

/*
	_ext_event_ReceivedMsg
	事件_收到信息 所有消息接收后以一时间触发本事件
*/
CGEvent(const char *, __ext_event_ReceivedMsg, 16)(const char *type, const char *fromQQ, const char *fromGroup, const char *Msg)
{
	//参数：共有四个参数：1.消息类型, 2.来源用户, 3.来源群号, 4.消息内容
	return "";
}

/*
	_ext_event_ReceivedMsg_NT
	事件_忽略信息 未处理的所有消息
*/
CGEvent(const char *, __ext_event_ReceivedMsg_NT, 16)(const char *type, const char *fromQQ, const char *fromGroup, const char *Msg)
{
	//参数：共有四个参数：1.消息类型, 2.来源用户, 3.来源群号, 4.消息内容
	return "";
}

/*
	_ext_event_AnalysisVariable
	CakeGame处理变量时触发此函数
*/
CGEvent(const char *, __ext_event_AnalysisVariable, 16)(const char *User, const char *Data, const char *OriginalData, const char *type)
{
	//参数：共有四个文本参数，1.处理用户,2.处理数据,3.处理原数据(CakeGame处理前的数据),4.类型(“start”为CakeGame开始处理前，“end”为CakeGame处理后)
	string result;
	result = string(Data);
	//**********开始编写处理程序**********
	if (string(type) == "start") {
		//CakeGame处理前
	}
	if (string(type) == "end") {
		//CakeGame处理后
	}
	//**********END**********
	return CGSDK::str2char(result);
}

/*
	_menu_test_cgSdk
	菜单函数
*/
CGEvent(void, __menu_test_cgSdk, 0)()
{
	MessageBoxA(0, "CakeGame SDK(C++) 12.5 By SmallCake", "Info:", 64);
}

/*
	_menu_test_knapsack
	菜单函数
*/
CGEvent(void, __menu_test_knapsack, 0)()
{
	MessageBoxA(0, _get_knapsack_all_cgjson(CGSDK::str2char(lastUid), false), "Test:", 64);
}