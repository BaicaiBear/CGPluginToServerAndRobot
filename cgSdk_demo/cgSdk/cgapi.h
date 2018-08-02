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

//�������_�ȼ�
#define USER_LV "LV"
//�������_����
#define USER_HP "HP"
//�������_����_ʣ��
#define USER_P_HP "P_HP"
//�������_ħ��
#define USER_MP "MP"
//�������_ħ��_ʣ��
#define USER_P_MP "P_MP"
//�������_�﹥
#define USER_AD "AD"
//�������_ħ��
#define USER_AP "AP"
//�������_����
#define USER_Defense "Defense"
//�������_ħ��
#define USER_MR "MagicResistance"
//�������_����
#define USER_Hit "Hit"
//�������_����
#define USER_Dodge "Dodge"
//�������_����
#define USER_CurrentExp "CurrentExp"
//�������_Ŀ��
#define USER_Target "Target"
//�������_λ��
#define USER_Location "Location"
//�������_ְҵ
#define USER_Occupation "Occupation"
//�������_����
#define USER_Crit "Crit"
//�������_����
#define USER_MyUnion "MyUnion"
//�������_��ǰ����
#define USER_Task "Task"
//�������_Ŀ��_����
#define USER_TargetHP "TargetHP"
//�������_����_����
#define USER_NeedExp "NeedExp"
//�������_���
#define USER_Currency_gold "Currency_gold"
//�������_��ʯ
#define USER_Currency_diamond "Currency_diamond"

//����_���
#define Currency_gold "currency_gold"
//����_��ʯ
#define Currency_diamond "currency_diamond"

//��ͼ_���Ƶȼ�_����
#define MAP_LIMIT_LV "LV"
//��ͼ_���Ƶȼ�_����
#define MAP_LIMIT_ULV "LV_UP"
//��ͼ_��ͼ����
#define MAP_Introduce "Introduce"
//��ͼ_�Ƿ�Ϊ��ȫ��
#define MAP_Security "Security"
//��ͼ_�Ƿ�Ϊ���ص�ͼ
#define MAP_Hid "Hid"
//��ͼ_�Ƿ�Ϊ������ͼ (�ɰ����������)
#define MAP_Basis "Basis"
//��ͼ_ͨ��_��
#define MAP_UP "UP"
//��ͼ_ͨ��_��
#define MAP_Down "Down"
//��ͼ_ͨ��_��
#define MAP_Left "Left"
//��ͼ_ͨ��_��
#define MAP_Right "Right"
//��ͼ_��������
#define MAP_Consume "Consume"

CGAPI(const char*) strToHex(const char *Text);
/*
* strToHex
* �ַ�����ʮ������
* Text ��ת��Ϊʮ�����Ƶ��ַ���
* ���� ת��Ϊʮ�����Ƶ��ı�
*/

CGAPI(const char*) hexToStr(const char *Hex);
/*
* hexToStr
* ʮ�����Ƶ��ַ���
* Hex ������Ϊ�ַ�����ʮ������
* ���� ����Ϊ�ִ�����ʮ�������ı�
*/

CGAPI(int) apiVersion();
/*
* apiVersion
* ��ȡcgapi����汾
* ���� �汾��
*/

CGAPI(const char*) _get_user_id();
/*
* _get_user_id
* ��ȡ��¼�Ļ�����QQ
* ���� ������QQ��
*/

CGAPI(sqlite3 *) get_db_handle();
/*
* get_db_handle
* ��ȡCakeGame�����ݿ����Ӿ��
* ���� ���ݿ���
*/

CGAPI(const char*) _judge_usable_function(const char *func,const char *userid,const char *fromid);
/*
* _judge_usable_function
* ���ָ�������Ƿ����(һ������ָ�����ʼ�ж�)
* func ��������(ע�⣺�Ǵ�����ʽ)
* userid ��Դ���
* fromid ��ԴȺ�Ż�������(˽����Ϊ��)
* ���� ���ز����õľ�����Ϣ����������ַ�������Ϊ0���ʾ����
*/

CGAPI(int) _judge_weak_user(const char *UserID);
/*
* _judge_weak_user
* �ж�����Ƿ�������״̬
* UserID ���ID
* ���� ����ʣ��ʱ��(��),����0����������״̬.
*/

CGAPI(bool) Global_Write(const char *ID,const char *SECTION,bool DELID,const char *DATA,bool DELSE);
/*
* Global_Write
* д��ȫ������(һ�����ڱ������ã�ID��ʽһ��Ϊ��ext_[��չ����]_[��������])
* ID ȫ��������
* SECTION ���ý�
* DELID �Ƿ�ɾ����
* DATA д�������
* DELSE �Ƿ�ɾ����
* ���� д��ɹ�����TRUE��ʧ�ܷ���FALSE
*/

CGAPI(const char*) Global_Get(const char *ID,const char *SECTION,const char *DEFAULT);
/*
* Global_Get
* ��ȡȫ����������
* ID ȫ��������
* SECTION ���ý�
* DEFAULT Ĭ�Ϸ���(ָ����Ŀ������ʱ���ش�����)
* ���� ȡ��������
*/

CGAPI(const char*) Global_ALLSECTION(const char *ID);
/*
* Global_ALLSECTION
* ��ȡָ�������н�
* ID ȫ��������
* ���� ���н���CGJson��ʽ���أ���ֱ��ʹ��Json����
*/

CGAPI(bool) UserData_Write(const char *UserID,const char *SECTION,bool DELID,const char *DATA,bool DELSE);
/*
* UserData_Write
* д���û���������(һ�����ڱ���ָ���û����޸��û�һЩ��������)
* UserID �û�ID
* SECTION �û��������ý�
* DELID �Ƿ�ɾ����
* DATA д�������
* DELSE �Ƿ�ɾ����
* ���� д��ɹ�����TRUE��ʧ�ܷ���FALSE
*/

CGAPI(const char*) UserData_Get(const char *UserID,const char *SECTION,const char *DEFAULT);
/*
* UserData_Get
* ��ȡ�û���������
* UserID �û�ID
* SECTION �û��������ý�
* DEFAULT Ĭ�Ϸ���(ָ����Ŀ������ʱ���ش�����)
* ���� ȡ��������
*/

CGAPI(const char*) UserData_ALLSECTION(const char *UserID);
/*
* UserData_ALLSECTION
* ��ȡָ���û����н�
* UserID �û�ID
* ���� ���н���CGJson��ʽ���أ���ֱ��ʹ��Json����
*/

CGAPI(const char*) _get_map_attribute(const char *mapname,const char *node);
/*
* _get_map_attribute
* ��ȡָ����ͼ����
* mapname ��ͼ����
* node ���Խ���
* ���� ȡ������������
*/

CGAPI(bool) _judge_exist_user(const char *UserID);
/*
* _judge_exist_user
* �ж��û��Ƿ����(��ע��)
* UserID �û�ID
* ���� ���ڷ���TRUE�������ڷ���FALSE
*/

CGAPI(const char*) _get_name_user(const char *UserID);
/*
* _get_name_user
* ��ȡָ���û����ǳ�
* UserID �û�ID
* ���� �����û��ǳ�
*/

CGAPI(bool) _update_user_attribute(const char *UserID,const char *attribute,const char *value);
/*
* _update_user_attribute
* �����û�ָ���Ļ�����Ϸ����
* UserID �û�ID
* attribute �����ֶ���
* value ���º������
* ���� ���³ɹ�����TRUE��ʧ�ܷ���FALSE
*/

CGAPI(bool) _update_user_attribute_int(const char *UserID, const char *attribute, int value);
/*
* _update_user_attribute_int
* �����û�ָ���Ļ�����Ϸ����
* UserID �û�ID
* attribute �����ֶ���
* value ���º������
* ���� ���³ɹ�����TRUE��ʧ�ܷ���FALSE
*/

CGAPI(bool) _update_user_attribute_long_int(const char *UserID, const char *attribute, long int value);
/*
* _update_user_attribute_long_int
* �����û�ָ���Ļ�����Ϸ����
* UserID �û�ID
* attribute �����ֶ���
* value ���º������
* ���� ���³ɹ�����TRUE��ʧ�ܷ���FALSE
*/

CGAPI(const char*) _get_user_attribute(const char *UserID,const char *attribute,const char *error_ret);
/*
* _get_user_attribute
* ��ȡ�û�ָ���Ļ�����Ϸ����
* UserID �û�ID
* attribute �����ֶ���
* error_ret �����ȡʧ�ܷ��ش�����
* ���� ����ָ����Ϸ����ֵ
*/

CGAPI(int) _get_user_attribute_int(const char *UserID, const char *attribute, int error_ret);
/*
* _get_user_attribute_int
* ��ȡ�û�ָ���Ļ�����Ϸ����
* UserID �û�ID
* attribute �����ֶ���
* error_ret �����ȡʧ�ܷ��ش�����
* ���� ����ָ����Ϸ����ֵ
*/

CGAPI(long int) _get_user_attribute_long_int(const char *UserID, const char *attribute, long int error_ret);
/*
* _get_user_attribute_long_int
* ��ȡ�û�ָ���Ļ�����Ϸ����
* UserID �û�ID
* attribute �����ֶ���
* error_ret �����ȡʧ�ܷ��ش�����
* ���� ����ָ����Ϸ����ֵ
*/

CGAPI(const char*) _get_goods_json(const char *goods);
/*
* _get_goods_json
* ��ȡָ����Ʒ������Json����
* goods ��Ʒ����
* ���� ����Json����
*/

CGAPI(bool) _judge_exist_goods(const char *goods,const char *id);
/*
* _judge_exist_goods
* �ж�ָ����Ʒ�Ƿ����
* goods ��Ʒ����
* id ��Ʒ�����(goods��idֻ��ѡ��һ����д��ʣ��һ�������ı�����)
* ���� ���ڷ���TRUE��ʧ�ܷ���FALSE
*/

CGAPI(const char*) _get_goods_type(const char *goods);
/*
* _get_goods_type
* ��ȡָ����Ʒ������
* goods ��Ʒ����
* ���� ��Ʒ��������
*/

CGAPI(bool) _judge_lock_goods(const char *goods);
/*
* _judge_lock_goods
* �ж���Ʒ�Ƿ�����
* goods ��Ʒ����
* ���� ��������TRUE������������FALSE
*/

CGAPI(bool) _update_knapsack_add(const char *UserID,const char *goods,int quantity,bool del);
/*
* _update_knapsack_add
* ��ָ���û��ı��������Ʒ
* UserID �û�ID
* goods ��Ʒ����
* quantity �������(��Ϊ����)
* del �Ƿ�ɾ������Ʒ
* ���� �ɹ�����TRUE��ʧ�ܷ���FALSE
*/

CGAPI(int) _update_knapsack_consume(const char *UserID, const char *goods, int quantity, bool isRelation);
/*
* _update_knapsack_add
* ��ָ���û��ı��������Ʒ
* UserID �û�ID
* goods ��Ʒ����
* quantity ��Ʒ��������
* isRelation �Ƿ���й�������
* ���� �ɹ�����Ʒʣ������
*/

CGAPI(sqlite3_stmt *) _get_knapsack_all(const char *UserID,bool _lock);
/*
* _get_knapsack_all
* ȡָ���û�����������Ʒ(����ɸѡӰ��)
* UserID �û�ID
* _lock �Ƿ�ȡ������Ʒ
* ���� �ɹ����ؼ�¼�������ʧ�ܷ���0
*/

CGAPI(const char*) _get_knapsack_all_cgjson(const char *UserID,bool _lock);
/*
* _get_knapsack_all_cgjson
* ȡָ���û�����������Ʒ(����ɸѡӰ��)
* UserID �û�ID
* _lock �Ƿ�ȡ������Ʒ
* ���� �ɹ�������ƷCGJson����
*/

CGAPI(int) _get_knapsack_filter_all(const char *UserID,bool _lock);
/*
* _get_knapsack_filter_all
* ȡָ���û�����������Ʒ(��ɸѡӰ��)
* UserID �û�ID
* _lock �Ƿ�ȡ������Ʒ
* ���� �ɹ����ؼ�¼�������ʧ�ܷ���0
*/

CGAPI(const char*) _get_knapsack_filter_all_cgjson(const char *UserID,bool _lock);
/*
* _get_knapsack_filter_all_cgjson
* ȡָ���û�����������Ʒ(��ɸѡӰ��)
* UserID �û�ID
* _lock �Ƿ�ȡ������Ʒ
* ���� �ɹ�������ƷCGJson����
*/

CGAPI(int) _get_knapsack_quantity(const char *UserID,const char *goods);
/*
* _get_knapsack_quantity
* ȡָ���û�����ָ����Ʒ����
* UserID �û�ID
* goods ��Ʒ����
* ���� ������Ʒ��������
*/

CGAPI(bool) _judge_exist_msgtem(const char *Name);
/*
* _judge_exist_msgtem
* �ж�ָ����Ϣģ���Ƿ����
* Name ��Ϣģ������
* ���� ������ڷ���TRUE,�����ڷ���FALSE
*/

CGAPI(bool) _update_msgtem(const char *Name,const char *data);
/*
* _update_msgtem
* �޸�ָ����Ϣģ�����ݣ�������������¼�һ����Ϣģ��
* Name ��Ϣģ������
* data д�����Ϣģ������
* ���� д��ɹ�����TRUE��ʧ�ܷ���FALSE
*/

CGAPI(const char*) _get_msgtem(const char *Name);
/*
* _get_msgtem
* ���ָ����Ϣģ������
* Name ��Ϣģ������
* ���� ������Ϣģ���ı�����
*/

CGAPI(int) _get_user_power(const char *UserID);
/*
* _get_user_power
* ���ָ���û���Ȩ��ֵ
* UserID �û�ID
* ���� ����Ȩ��ֵ
*/

CGAPI(bool) _update_user_power(const char *UserID,int power_val);
/*
* _update_user_power
* ����ָ���û���Ȩ��ֵ
* UserID �û�ID
* power_val Ȩ��ֵ
* ���� �ɹ�����TRUE,ʧ�ܷ���FALSE
*/


CGAPI(int) _get_user_real_atk(const char *UserID,int type);
/*
* _get_user_real_atk
* ȡ�����ʵ������
* UserID �û�ID
* type ��������
*/

CGAPI(int) _get_user_real_def(const char *UserID);
/*
* _get_user_real_def
* ȡ�����ʵ������
* UserID �û�ID
*/

CGAPI(int) _get_user_real_mag(const char *UserID);
/*
* _get_user_real_mag
* ȡ�����ʵħ����
* UserID �û�ID
*/

CGAPI(int) _get_user_real_cri(const char *UserID);
/*
* _get_user_real_cri
* ȡ�����ʵ������
* UserID �û�ID
*/

CGAPI(int) _get_user_real_dod(const char *UserID);
/*
* _get_user_real_dod
* ȡ�����ʵ������
* UserID �û�ID
*/

CGAPI(int) _get_user_real_hit(const char *UserID);
/*
* _get_user_real_hit
* ȡ�����ʵ������
* UserID �û�ID
*/

CGAPI(int) _get_user_real_uhp(const char *UserID);
/*
* _get_user_real_uhp
* ȡ�����ʵ��������
* UserID �û�ID
*/

CGAPI(int) _get_user_real_ump(const char *UserID);
/*
* _get_user_real_ump
* ȡ�����ʵ����ħ��
* UserID �û�ID
*/

CGAPI(int) _get_user_real_ahp(const char *UserID);
/*
* _get_user_real_ahp
* ȡ�����ʵ��Ѫ��
* UserID �û�ID
*/

CGAPI(int) _get_user_real_imd(const char *UserID);
/*
* _get_user_real_imd
* ȡ�����ʵ���˱�
* UserID �û�ID
*/

CGAPI(int) _get_user_real_dpv(const char *UserID);
/*
* _get_user_real_dpv
* ȡ�����ʵ�ﴩֵ
* UserID �û�ID
*/

CGAPI(int) _get_user_real_dpr(const char *UserID);
/*
* _get_user_real_dpr
* ȡ�����ʵ�ﴩ��
* UserID �û�ID
*/

CGAPI(int) _get_user_real_ptv(const char *UserID);
/*
* _get_user_real_ptv
* ȡ�����ʵ����ֵ
* UserID �û�ID
*/

CGAPI(int) _get_user_real_ptr(const char *UserID);
/*
* _get_user_real_ptr
* ȡ�����ʵ������
* UserID �û�ID
*/

CGAPI(bool) _judge_exist_union(const char *_unionName);
/*
* _judge_exist_union
* �жϹ����Ƿ����
* _unionName ��������
* ���� ������ڷ���TRUE�������ڷ���FALSE
*/

CGAPI(bool) _union_write_set(const char *_unionName,const char *node,const char *data);
/*
* _union_write_set
* д������������
* _unionName ��������
* node ������
* data д������
* ���� ����ɹ�����TRUE��ʧ�ܷ���FALSE
*/

CGAPI(const char*) _union_get_set(const char *_unionName,const char *node);
/*
* _union_get_set
* ȡ������������
* _unionName ��������
* node ������
* ���� ����ȡ���Ĺ������������ı�
*/

CGAPI(const char*) _union_get_attributes(const char *_unionName,const char *node);
/*
* _union_get_attributes
* ȡ������������
* _unionName ��������
* node ������
* ���� ����ȡ���Ĺ������������ı�
*/

CGAPI(bool) _union_set_attributes(const char *_unionName,const char *node,const char *data);
/*
* _union_set_attributes
* д������������
* _unionName ��������
* node ������
* data д������
* ���� ����ɹ�����TRUE��ʧ�ܷ���FALSE
*/

CGAPI(bool) _union_add_exp(const char *_unionName,long int exp);
/*
* _union_add_exp
* ���ӹ��ᾭ��
* _unionName ��������
* exp ���ӵľ�������
* ���� ����ɹ�����TRUE��ʧ�ܷ���FALSE
*/

CGAPI(const char*) _CGJson_Escape(const char *Text);
/*
* CGJson�ؼ���ת��
*/

CGAPI(const char*) _CGJson_BackEscape(const char *Text);
/*
* CGJson�ؼ��ʷ�ת��
*/

CGAPI(void) _event_join(const char *event_data);
/*
* _event_join
* ��CakeGame�����¼�ָ��
* event_data �¼�����(CGJson)
*/

CGAPI(int) _dynamic_attributes_register(const char *user,const char *AttName,int value,const char *AttInvalidTime);
/*
*_dynamic_attributes_register
* ע��һ����̬����
* user ע�����
* AttName ��������
* value ��̬����ֵ
* AttInvalidTime ʧЧʱ��
*/

CGAPI(int) _dynamic_attributes_sum(const char *user,const char *AttName);
/*
* _dynamic_attributes_sum
* ��ȡָ���û������͵���Ч��̬����ֵ�ܺ�
* user ָ���û�
* AttName ��������
*/

CGAPI(bool) _dynamic_attributes_delete(int Id);
/*
* _dynamic_attributes_delete
* ɾ��ָ����̬����
* Id ��ɾ���Ķ�̬����Id
*/

CGAPI (int) _custom_attributes_register(const char *SQL);
/*
* _custom_attributes_register
* ע��һ���Զ�����
* SQL �Զ����Լ���SQL
*/

CGAPI (bool) _custom_attributes_delete(int Id);
/*
* _custom_attributes_delete
* ɾ��һ���Զ�����
* Id ��ɾ�����Զ�����Id
*/

namespace CGSDK
{
	//�¼�����_TriggerFunction���ص�����
	struct TFI
	{
		string Handle; //�������
		string Name; //������������
		string MsgData; //������������
	};
	//stringת��Ϊchar*
	const char *str2char(string Text)
	{
		char *result = new char[Text.size() + 1];
		//strcpy(result, Text.c_str());
		strcpy_s(result, Text.size() + 1, Text.c_str());
		return result;
	}
	//CG���ô�����<CGJson>����ͨ�����ദ������CGJson����
	class CGJson 
	{
	private:
		class CGJson_Item {
		public:
			string node, data;
		};
		vector<CGJson_Item>Item;
	public:
		void load(const char *Json)//����Json����
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

		const char* get_node_data(const char *node)//ȡָ���ڵ�����
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

		int get_item_number()//ȡ�ڵ���
		{
			return Item.size();
		}

		void update_item(const char *node, const char *data)//(����/����)�ڵ�����
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

		const char* get_cgjson()//ȡCGJson�ı�����
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

		vector<const char*> get_all_node()//ȡ���нڵ�
		{
			vector<const char*>ret;
			for (int i = 0; i<Item.size(); i++)
			{
				ret.push_back(str2char(Item[i].node));
			}
			return ret;
		}

		void delete_node(const char *node)//ɾ��ָ���ڵ㼰������
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

		void delete_all()//������нڵ㼰������
		{
			Item.clear();
		}
	};
	//������Ϣ
	void SendMsg(const char* type, const char* id, const char* msg, const char* uID)
	{
		//���� type(1Ϊ��ͨ˽�ģ�2Ϊ��ͨȺ�ģ�3Ϊ��ͨ�����飬4Ϊ�߼�˽�ģ�5Ϊ�߼�Ⱥ�ģ�6Ϊ�߼�������)��id(������)��msg(���͵���Ϣ)��uID(4-6����ʱ����,��������ʱ����UID)
		//��ͨ����(CakeGame������Ϣ���б�������)
		//�߼�����(CakeGame����Ϣ���б�������)
		CGJson join_msg;
		join_msg.update_item("type", type);
		join_msg.update_item("id", id);
		join_msg.update_item("msg", strToHex(msg));
		if (uID != NULL) {
			join_msg.update_item("uID", uID);
		}
		_event_join(join_msg.get_cgjson());
	}
	//�ָ��ִ���
	vector<string> splitWithStl(const string &str, const string &pattern)//�ָ��ִ���
	{
		vector<string> resVec;

		if ("" == str)
		{
			return resVec;
		}
		//�����ȡ���һ������
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
	//��ȡCakeGame��Ϣͷ
	const char* GetMessagePrefix()//��ȡCakeGame��Ϣͷ
	{
		const char* result;
		result = Global_Get("set", "Message_prefix", "");
		if (strlen(result) < 1) {
			result = "LV[UD:Base,type=LV].[UD:Base,type=Name]";
		}
		return result;
	}
	//�¼�����_TriggerFunction ��ȡ���������������Լ�����
	TFI GetTriggerFunctionData(const char* Handle)
	{
		TFI RET;
		RET.Handle = string(Handle);
		RET.MsgData = Global_Get(str2char("STATE." + RET.Handle), "BDW_FUNCTION_MSG", "");
		RET.Name = Global_Get(str2char("STATE." + RET.Handle), "BDW_FUNCTION_NAME", "");
		return RET;
	}
}