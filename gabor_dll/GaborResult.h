
struct Gabor_Result     //�����ṹ��
{
	Gabor_Result()
	{
		memset(Event_Array,0,sizeof(Event_Array));
		memset(Event_Loss,0,sizeof(Event_Loss));
		memset(Reflect_Type,0,sizeof(Reflect_Type));
		memset(Event_Hight,0,sizeof(Event_Hight));
		memset(Line_k,0,sizeof(Line_k));
		memset(Total_Loss,0,sizeof(Total_Loss));
		//memset(Event_Array_End,0,sizeof(Event_Array_End));
		Trail_End=10;
		Valid_Num=0;
	}
	int Reflect_Type[100];  //�¼�����	//Event Code
	int Event_Array[100];  //�¼�λ��  //Event Propagation Time
	float  Event_Loss[100];       //���//Event Loss
	float Event_Hight[100]; //�¼��㷴��dB
	float Line_k[100];//����б��
	float  Total_Loss[100];  //����ġ��ۼ����
	float  Reflect;   //����
	int Valid_Num;    //��Ч����
	float Trail_End;//β��λ��
	char Event_type[100];// A���û��Լӣ�M:    E:����ĩ�ˣ�F:������в��ң�O:����������Χ�Ĺ���ĩ�� D:
	//int Event_Array_End[100];
};//�ṹ��Ķ����λ������

