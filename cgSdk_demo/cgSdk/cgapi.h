/*
* CakeGame SDK for VC++ 
* Api Version 12.5
* Written by SmallCake
*/

#pragma once

#include <string>
#include <vector>
#include "deelx.h"
#include "sqlite3.h"

using namespace std;

#ifndef CGAPI
#define CGAPI(ReturnType) extern "C" __declspec(dllimport) ReturnType __stdcall
#endif

#define CGEvent(ReturnType, Name, Size) __pragma(comment(linker, "/EXPORT:" #Name "=_" #Name "@" #Size))\
 extern "C" __declspec(dllexport) ReturnType __stdcall Name

#define Version "16"
#define TABLE_Image "Image"
#define TABLE_Shared_User "Shared_User"
#define TABLE_Shared_Data "Shared_Data"
#define TABLE_Basic_information "Basic_information"
#define TABLE_Shared_Basic_knapsack "Basic_knapsack"
#define TABLE_Global "Global"
#define TABLE_Config_Goods "Config_Goods"
#define TABLE_Config_Monster "Config_Monster"
#define TABLE_Config_Skills "Config_Skills"
#define TABLE_Config_Map "Config_Map"
#define TABLE_Config_Occupation "Config_Occupation"
#define TABLE_Config_Shop "Config_Shop"
#define TABLE_Config_Help "Config_Help"
#define TABLE_Config_Union "Config_Union"
#define TABLE_Config_Ranks "Config_Ranks"
#define TABLE_Config_Task "Config_Task"
#define TABLE_Config_Composite "Config_Composite"
#define TABLE_Config_Special "Config_Special"
#define TABLE_Skill_Register "Skill_Register"
#define TABLE_Task_Register "Task_Register"
#define TABLE_Equip_Register "Equip_Register"
#define TABLE_Config_PrivateShops "Config_PrivateShops"
#define TABLE_MessageTemplate "MessageTemplate"

//玩家属性_等级
#define USER_LV "LV"
//玩家属性_生命
#define USER_HP "HP"
//玩家属性_生命_剩余
#define USER_P_HP "P_HP"
//玩家属性_魔法
#define USER_MP "MP"
//玩家属性_魔法_剩余
#define USER_P_MP "P_MP"
//玩家属性_物攻
#define USER_AD "AD"
//玩家属性_魔攻
#define USER_AP "AP"
//玩家属性_防御
#define USER_Defense "Defense"
//玩家属性_魔抗
#define USER_MR "MagicResistance"
//玩家属性_命中
#define USER_Hit "Hit"
//玩家属性_闪避
#define USER_Dodge "Dodge"
//玩家属性_经验
#define USER_CurrentExp "CurrentExp"
//玩家属性_目标
#define USER_Target "Target"
//玩家属性_位置
#define USER_Location "Location"
//玩家属性_职业
#define USER_Occupation "Occupation"
//玩家属性_暴击
#define USER_Crit "Crit"
//玩家属性_公会
#define USER_MyUnion "MyUnion"
//玩家属性_当前任务
#define USER_Task "Task"
//玩家属性_目标_生命
#define USER_TargetHP "TargetHP"
//玩家属性_经验_需求
#define USER_NeedExp "NeedExp"
//玩家属性_金币
#define USER_Currency_gold "Currency_gold"
//玩家属性_钻石
#define USER_Currency_diamond "Currency_diamond"

//货币_金币
#define Currency_gold "currency_gold"
//货币_钻石
#define Currency_diamond "currency_diamond"

//地图_限制等级_下限
#define MAP_LIMIT_LV "LV"
//地图_限制等级_上限
#define MAP_LIMIT_ULV "LV_UP"
//地图_地图介绍
#define MAP_Introduce "Introduce"
//地图_是否为安全区
#define MAP_Security "Security"
//地图_是否为隐藏地图
#define MAP_Hid "Hid"
//地图_是否为基础地图 (旧版残留，无用)
#define MAP_Basis "Basis"
//地图_通道_上
#define MAP_UP "UP"
//地图_通道_下
#define MAP_Down "Down"
//地图_通道_左
#define MAP_Left "Left"
//地图_通道_右
#define MAP_Right "Right"
//地图_进入消耗
#define MAP_Consume "Consume"

CGAPI(const char*) strToHex(const char *Text);
/*
* strToHex
* 字符串到十六进制
* Text 欲转换为十六进制的字符串
* 返回 转换为十六进制的文本
*/

CGAPI(const char*) hexToStr(const char *Hex);
/*
* hexToStr
* 十六进制到字符串
* Hex 欲翻译为字符串的十六进制
* 返回 翻译为字串符的十六进制文本
*/

CGAPI(int) apiVersion();
/*
* apiVersion
* 获取cgapi引擎版本
* 返回 版本号
*/

CGAPI(const char*) _get_user_id();
/*
* _get_user_id
* 获取登录的机器人QQ
* 返回 机器人QQ号
*/

CGAPI(sqlite3 *) get_db_handle();
/*
* get_db_handle
* 获取CakeGame主数据库连接句柄
* 返回 数据库句柄
*/

CGAPI(const char*) _judge_usable_function(const char *func,const char *userid,const char *fromid);
/*
* _judge_usable_function
* 监测指定功能是否可用(一般用于指令函数初始判断)
* func 功能名称(注意：非触发格式)
* userid 来源玩家
* fromid 来源群号或讨论组(私聊则为空)
* 返回 返回不可用的具体信息，如果返回字符串长度为0则表示可用
*/

CGAPI(int) _judge_weak_user(const char *UserID);
/*
* _judge_weak_user
* 判断玩家是否处于虚弱状态
* UserID 玩家ID
* 返回 虚弱剩余时间(分),返回0代表不是虚弱状态.
*/

CGAPI(bool) Global_Write(const char *ID,const char *SECTION,bool DELID,const char *DATA,bool DELSE);
/*
* Global_Write
* 写入全局设置(一般用于保存设置，ID格式一般为：ext_[扩展名称]_[作者名称])
* ID 全局设置项
* SECTION 设置节
* DELID 是否删除项
* DATA 写入的数据
* DELSE 是否删除节
* 返回 写入成功返回TRUE，失败返回FALSE
*/

CGAPI(const char*) Global_Get(const char *ID,const char *SECTION,const char *DEFAULT);
/*
* Global_Get
* 获取全局设置数据
* ID 全局设置项
* SECTION 设置节
* DEFAULT 默认返回(指定项目不存在时返回此数据)
* 返回 取到的数据
*/

CGAPI(const char*) Global_ALLSECTION(const char *ID);
/*
* Global_ALLSECTION
* 获取指定项所有节
* ID 全局设置项
* 返回 所有节以CGJson格式返回，可直接使用Json解析
*/

CGAPI(bool) UserData_Write(const char *UserID,const char *SECTION,bool DELID,const char *DATA,bool DELSE);
/*
* UserData_Write
* 写入用户属性设置(一般用于保存指定用户和修改用户一些属性设置)
* UserID 用户ID
* SECTION 用户属性设置节
* DELID 是否删除项
* DATA 写入的数据
* DELSE 是否删除节
* 返回 写入成功返回TRUE，失败返回FALSE
*/

CGAPI(const char*) UserData_Get(const char *UserID,const char *SECTION,const char *DEFAULT);
/*
* UserData_Get
* 获取用户属性设置
* UserID 用户ID
* SECTION 用户属性设置节
* DEFAULT 默认返回(指定项目不存在时返回此数据)
* 返回 取到的数据
*/

CGAPI(const char*) UserData_ALLSECTION(const char *UserID);
/*
* UserData_ALLSECTION
* 获取指定用户所有节
* UserID 用户ID
* 返回 所有节以CGJson格式返回，可直接使用Json解析
*/

CGAPI(const char*) _get_map_attribute(const char *mapname,const char *node);
/*
* _get_map_attribute
* 获取指定地图属性
* mapname 地图名称
* node 属性节名
* 返回 取出的属性数据
*/

CGAPI(bool) _judge_exist_user(const char *UserID);
/*
* _judge_exist_user
* 判断用户是否存在(已注册)
* UserID 用户ID
* 返回 存在返回TRUE，不存在返回FALSE
*/

CGAPI(const char*) _get_name_user(const char *UserID);
/*
* _get_name_user
* 获取指定用户的昵称
* UserID 用户ID
* 返回 返回用户昵称
*/

CGAPI(bool) _update_user_attribute(const char *UserID,const char *attribute,const char *value);
/*
* _update_user_attribute
* 更新用户指定的基础游戏属性
* UserID 用户ID
* attribute 属性字段名
* value 更新后的数据
* 返回 更新成功返回TRUE，失败返回FALSE
*/

CGAPI(bool) _update_user_attribute_int(const char *UserID, const char *attribute, int value);
/*
* _update_user_attribute_int
* 更新用户指定的基础游戏属性
* UserID 用户ID
* attribute 属性字段名
* value 更新后的数据
* 返回 更新成功返回TRUE，失败返回FALSE
*/

CGAPI(bool) _update_user_attribute_long_int(const char *UserID, const char *attribute, long int value);
/*
* _update_user_attribute_long_int
* 更新用户指定的基础游戏属性
* UserID 用户ID
* attribute 属性字段名
* value 更新后的数据
* 返回 更新成功返回TRUE，失败返回FALSE
*/

CGAPI(const char*) _get_user_attribute(const char *UserID,const char *attribute,const char *error_ret);
/*
* _get_user_attribute
* 获取用户指定的基础游戏属性
* UserID 用户ID
* attribute 属性字段名
* error_ret 如果获取失败返回此数据
* 返回 返回指定游戏属性值
*/

CGAPI(int) _get_user_attribute_int(const char *UserID, const char *attribute, int error_ret);
/*
* _get_user_attribute_int
* 获取用户指定的基础游戏属性
* UserID 用户ID
* attribute 属性字段名
* error_ret 如果获取失败返回此数据
* 返回 返回指定游戏属性值
*/

CGAPI(long int) _get_user_attribute_long_int(const char *UserID, const char *attribute, long int error_ret);
/*
* _get_user_attribute_long_int
* 获取用户指定的基础游戏属性
* UserID 用户ID
* attribute 属性字段名
* error_ret 如果获取失败返回此数据
* 返回 返回指定游戏属性值
*/

CGAPI(const char*) _get_goods_json(const char *goods);
/*
* _get_goods_json
* 获取指定物品的属性Json数据
* goods 物品名称
* 返回 返回Json数据
*/

CGAPI(bool) _judge_exist_goods(const char *goods,const char *id);
/*
* _judge_exist_goods
* 判断指定物品是否存在
* goods 物品名称
* id 物品快捷码(goods与id只需选择一个填写，剩下一个留空文本即可)
* 返回 存在返回TRUE，失败返回FALSE
*/

CGAPI(const char*) _get_goods_type(const char *goods);
/*
* _get_goods_type
* 获取指定物品的类型
* goods 物品名称
* 返回 物品类型名称
*/

CGAPI(bool) _judge_lock_goods(const char *goods);
/*
* _judge_lock_goods
* 判断物品是否锁定
* goods 物品名称
* 返回 锁定返回TRUE，非锁定返回FALSE
*/

CGAPI(bool) _update_knapsack_add(const char *UserID,const char *goods,int quantity,bool del);
/*
* _update_knapsack_add
* 给指定用户的背包添加物品
* UserID 用户ID
* goods 物品名称
* quantity 添加数量(可为负数)
* del 是否删除此物品
* 返回 成功返回TRUE，失败返回FALSE
*/

CGAPI(int) _update_knapsack_consume(const char *UserID, const char *goods, int quantity, bool isRelation);
/*
* _update_knapsack_add
* 给指定用户的背包添加物品
* UserID 用户ID
* goods 物品名称
* quantity 物品消耗数量
* isRelation 是否进行关联消耗
* 返回 成功此物品剩余数量
*/

CGAPI(sqlite3_stmt *) _get_knapsack_all(const char *UserID,bool _lock);
/*
* _get_knapsack_all
* 取指定用户背包所有物品(不受筛选影响)
* UserID 用户ID
* _lock 是否不取锁定物品
* 返回 成功返回记录集句柄，失败返回0
*/

CGAPI(const char*) _get_knapsack_all_cgjson(const char *UserID,bool _lock);
/*
* _get_knapsack_all_cgjson
* 取指定用户背包所有物品(不受筛选影响)
* UserID 用户ID
* _lock 是否不取锁定物品
* 返回 成功返回物品CGJson数据
*/

CGAPI(int) _get_knapsack_filter_all(const char *UserID,bool _lock);
/*
* _get_knapsack_filter_all
* 取指定用户背包所有物品(受筛选影响)
* UserID 用户ID
* _lock 是否不取锁定物品
* 返回 成功返回记录集句柄，失败返回0
*/

CGAPI(const char*) _get_knapsack_filter_all_cgjson(const char *UserID,bool _lock);
/*
* _get_knapsack_filter_all_cgjson
* 取指定用户背包所有物品(受筛选影响)
* UserID 用户ID
* _lock 是否不取锁定物品
* 返回 成功返回物品CGJson数据
*/

CGAPI(int) _get_knapsack_quantity(const char *UserID,const char *goods);
/*
* _get_knapsack_quantity
* 取指定用户背包指定物品数量
* UserID 用户ID
* goods 物品名称
* 返回 返回物品数量整数
*/

CGAPI(bool) _judge_exist_msgtem(const char *Name);
/*
* _judge_exist_msgtem
* 判断指定消息模板是否存在
* Name 消息模板名称
* 返回 如果存在返回TRUE,不存在返回FALSE
*/

CGAPI(bool) _update_msgtem(const char *Name,const char *data);
/*
* _update_msgtem
* 修改指定消息模板数据，如果不存在则新加一条消息模板
* Name 消息模板名称
* data 写入的消息模板数据
* 返回 写入成功返回TRUE，失败返回FALSE
*/

CGAPI(const char*) _get_msgtem(const char *Name);
/*
* _get_msgtem
* 获得指定消息模板数据
* Name 消息模板名称
* 返回 返回消息模板文本数据
*/

CGAPI(int) _get_user_power(const char *UserID);
/*
* _get_user_power
* 获得指定用户的权限值
* UserID 用户ID
* 返回 整数权限值
*/

CGAPI(bool) _update_user_power(const char *UserID,int power_val);
/*
* _update_user_power
* 更新指定用户的权限值
* UserID 用户ID
* power_val 权限值
* 返回 成功返回TRUE,失败返回FALSE
*/


CGAPI(int) _get_user_real_atk(const char *UserID,int type);
/*
* _get_user_real_atk
* 取玩家真实攻击力
* UserID 用户ID
* type 攻击类型
*/

CGAPI(int) _get_user_real_def(const char *UserID);
/*
* _get_user_real_def
* 取玩家真实防御力
* UserID 用户ID
*/

CGAPI(int) _get_user_real_mag(const char *UserID);
/*
* _get_user_real_mag
* 取玩家真实魔抗力
* UserID 用户ID
*/

CGAPI(int) _get_user_real_cri(const char *UserID);
/*
* _get_user_real_cri
* 取玩家真实暴击率
* UserID 用户ID
*/

CGAPI(int) _get_user_real_dod(const char *UserID);
/*
* _get_user_real_dod
* 取玩家真实闪避率
* UserID 用户ID
*/

CGAPI(int) _get_user_real_hit(const char *UserID);
/*
* _get_user_real_hit
* 取玩家真实命中率
* UserID 用户ID
*/

CGAPI(int) _get_user_real_uhp(const char *UserID);
/*
* _get_user_real_uhp
* 取玩家真实上限生命
* UserID 用户ID
*/

CGAPI(int) _get_user_real_ump(const char *UserID);
/*
* _get_user_real_ump
* 取玩家真实上限魔法
* UserID 用户ID
*/

CGAPI(int) _get_user_real_ahp(const char *UserID);
/*
* _get_user_real_ahp
* 取玩家真实吸血比
* UserID 用户ID
*/

CGAPI(int) _get_user_real_imd(const char *UserID);
/*
* _get_user_real_imd
* 取玩家真实免伤比
* UserID 用户ID
*/

CGAPI(int) _get_user_real_dpv(const char *UserID);
/*
* _get_user_real_dpv
* 取玩家真实物穿值
* UserID 用户ID
*/

CGAPI(int) _get_user_real_dpr(const char *UserID);
/*
* _get_user_real_dpr
* 取玩家真实物穿比
* UserID 用户ID
*/

CGAPI(int) _get_user_real_ptv(const char *UserID);
/*
* _get_user_real_ptv
* 取玩家真实法穿值
* UserID 用户ID
*/

CGAPI(int) _get_user_real_ptr(const char *UserID);
/*
* _get_user_real_ptr
* 取玩家真实法穿比
* UserID 用户ID
*/

CGAPI(bool) _judge_exist_union(const char *_unionName);
/*
* _judge_exist_union
* 判断公会是否存在
* _unionName 公会名称
* 返回 如果存在返回TRUE，不存在返回FALSE
*/

CGAPI(bool) _union_write_set(const char *_unionName,const char *node,const char *data);
/*
* _union_write_set
* 写公会属性设置
* _unionName 公会名称
* node 节名称
* data 写入数据
* 返回 如果成功返回TRUE，失败返回FALSE
*/

CGAPI(const char*) _union_get_set(const char *_unionName,const char *node);
/*
* _union_get_set
* 取公会属性设置
* _unionName 公会名称
* node 节名称
* 返回 返回取到的公会设置数据文本
*/

CGAPI(const char*) _union_get_attributes(const char *_unionName,const char *node);
/*
* _union_get_attributes
* 取公会属性数据
* _unionName 公会名称
* node 节名称
* 返回 返回取到的公会属性数据文本
*/

CGAPI(bool) _union_set_attributes(const char *_unionName,const char *node,const char *data);
/*
* _union_set_attributes
* 写公会属性数据
* _unionName 公会名称
* node 节名称
* data 写入数据
* 返回 如果成功返回TRUE，失败返回FALSE
*/

CGAPI(bool) _union_add_exp(const char *_unionName,long int exp);
/*
* _union_add_exp
* 增加公会经验
* _unionName 公会名称
* exp 增加的经验数量
* 返回 如果成功返回TRUE，失败返回FALSE
*/

CGAPI(const char*) _CGJson_Escape(const char *Text);
/*
* CGJson关键词转义
*/

CGAPI(const char*) _CGJson_BackEscape(const char *Text);
/*
* CGJson关键词反转义
*/

CGAPI(void) _event_join(const char *event_data);
/*
* _event_join
* 向CakeGame发送事件指令
* event_data 事件数据(CGJson)
*/

CGAPI(int) _dynamic_attributes_register(const char *user,const char *AttName,int value,const char *AttInvalidTime);
/*
*_dynamic_attributes_register
* 注册一个动态属性
* user 注册对象
* AttName 属性名称
* value 动态属性值
* AttInvalidTime 失效时间
*/

CGAPI(int) _dynamic_attributes_sum(const char *user,const char *AttName);
/*
* _dynamic_attributes_sum
* 获取指定用户与类型的有效动态属性值总和
* user 指定用户
* AttName 属性名称
*/

CGAPI(bool) _dynamic_attributes_delete(int Id);
/*
* _dynamic_attributes_delete
* 删除指定动态属性
* Id 欲删除的动态属性Id
*/

CGAPI (int) _custom_attributes_register(const char *SQL);
/*
* _custom_attributes_register
* 注册一个自定属性
* SQL 自定属性计算SQL
*/

CGAPI (bool) _custom_attributes_delete(int Id);
/*
* _custom_attributes_delete
* 删除一个自定属性
* Id 欲删除的自定属性Id
*/

namespace CGSDK
{
	//事件函数_TriggerFunction返回的数据
	struct TFI
	{
		string Handle; //操作句柄
		string Name; //触发功能名称
		string MsgData; //触发功能数据
	};
	//string转换为char*
	const char *str2char(string Text)
	{
		char *result = new char[Text.size() + 1];
		//strcpy(result, Text.c_str());
		strcpy_s(result, Text.size() + 1, Text.c_str());
		return result;
	}
	//CG常用处理类<CGJson>，可通过此类处理所有CGJson数据
	class CGJson 
	{
	private:
		class CGJson_Item {
		public:
			string node, data;
		};
		vector<CGJson_Item>Item;
	public:
		void load(const char *Json)//加载Json数据
		{
			int start, end;
			string data = string(Json);
			CGJson_Item GetData;
			CRegexpT <char> regexp("\"(.*?)\":\"(.*?)\"");
			MatchResult result = regexp.Match(Json);
			while (result.IsMatched())
			{
				if (result.MaxGroupNumber() == 2)
				{
					start = result.GetGroupStart(1);
					end = result.GetGroupEnd(1);
					GetData.node = string(_CGJson_BackEscape(str2char(data.substr(start, end - start))));
					start = result.GetGroupStart(2);
					end = result.GetGroupEnd(2);
					GetData.data = string(_CGJson_BackEscape(str2char(data.substr(start, end - start))));
					Item.push_back(GetData);
				}
				result = regexp.Match(Json, result.GetEnd());
			}
		}

		const char* get_node_data(const char *node)//取指定节点数据
		{
			for (int i = 0; i<Item.size(); i++)
			{
				if (Item[i].node == string(node))
				{
					return str2char(Item[i].data);
				}
			}
			return "";
		}

		int get_item_number()//取节点数
		{
			return Item.size();
		}

		void update_item(const char *node, const char *data)//(更新/插入)节点数据
		{
			for (int i = 0; i<Item.size(); i++)
			{
				if (Item[i].node == string(node))
				{
					Item[i].data = string(data);
					return;
				}
			}
			CGJson_Item GetData;
			GetData.node = string(node); GetData.data = string(data);
			Item.push_back(GetData);
		}

		const char* get_cgjson()//取CGJson文本数据
		{
			if (Item.size() == 0)
			{
				return "";
			}
			string ret = "{";
			for (int i = 0; i<Item.size(); i++)
			{
				ret = ret + "\"" + string(_CGJson_Escape(str2char(Item[i].node))) + "\":\"" + string(_CGJson_Escape(str2char(Item[i].data)));
				if (i + 1 >= Item.size())
				{
					ret = ret + "\"}";
				}
				else {
					ret = ret + "\",";
				}
			}
			return str2char(ret);
		}

		vector<const char*> get_all_node()//取所有节点
		{
			vector<const char*>ret;
			for (int i = 0; i<Item.size(); i++)
			{
				ret.push_back(str2char(Item[i].node));
			}
			return ret;
		}

		void delete_node(const char *node)//删除指定节点及其数据
		{
			for (int i = 0; i<Item.size(); i++)
			{
				if (Item[i].node == string(node))
				{
					Item.erase(Item.begin() + i);
					return;
				}
			}
		}

		void delete_all()//清空所有节点及其数据
		{
			Item.clear();
		}
	};
	//发送消息
	void SendMsg(const char* type, const char* id, const char* msg, const char* uID)
	{
		//参数 type(1为普通私聊，2为普通群聊，3为普通讨论组，4为高级私聊，5为高级群聊，6为高级讨论组)，id(发送至)，msg(发送的消息)，uID(4-6类型时输入,变量处理时主用UID)
		//普通发送(CakeGame不对消息进行变量处理)
		//高级发送(CakeGame对消息进行变量处理)
		CGJson join_msg;
		join_msg.update_item("type", type);
		join_msg.update_item("id", id);
		join_msg.update_item("msg", strToHex(msg));
		if (uID != NULL) {
			join_msg.update_item("uID", uID);
		}
		_event_join(join_msg.get_cgjson());
	}
	//分割字串符
	vector<string> splitWithStl(const string &str, const string &pattern)//分割字串符
	{
		vector<string> resVec;

		if ("" == str)
		{
			return resVec;
		}
		//方便截取最后一段数据
		string strs = str + pattern;

		size_t pos = strs.find(pattern);
		size_t size = strs.size();

		while (pos != string::npos)
		{
			string x = strs.substr(0, pos);
			resVec.push_back(x);
			strs = strs.substr(pos + pattern.size(), size);
			pos = strs.find(pattern);
		}

		return resVec;
	}
	//获取CakeGame消息头
	const char* GetMessagePrefix()//获取CakeGame消息头
	{
		const char* result;
		result = Global_Get("set", "Message_prefix", "");
		if (strlen(result) < 1) {
			result = "LV[UD:Base,type=LV].[UD:Base,type=Name]";
		}
		return result;
	}
	//事件函数_TriggerFunction 获取触发函数的名称以及数据
	TFI GetTriggerFunctionData(const char* Handle)
	{
		TFI RET;
		RET.Handle = string(Handle);
		RET.MsgData = Global_Get(str2char("STATE." + RET.Handle), "BDW_FUNCTION_MSG", "");
		RET.Name = Global_Get(str2char("STATE." + RET.Handle), "BDW_FUNCTION_NAME", "");
		return RET;
	}
}