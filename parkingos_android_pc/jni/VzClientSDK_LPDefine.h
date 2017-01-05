#ifndef _VZ_CLIENT_SDK_LP_DEFINE_H_
#define _VZ_CLIENT_SDK_LP_DEFINE_H_

// ����ʶ����ز���
//---------------------------------------//
//������ɫ
#define LC_UNKNOWN  0  //δ֪
#define LC_BLUE     1  //��ɫ
#define LC_YELLOW   2  //��ɫ 
#define LC_WHITE    3  //��ɫ
#define LC_BLACK    4  //��ɫ
#define LC_GREEN    5  //��ɫ

//��������
#define LT_UNKNOWN  0   //δ֪����
#define LT_BLUE     1   //����С����
#define LT_BLACK    2   //����С����
#define LT_YELLOW   3   //���Ż���
#define LT_YELLOW2  4   //˫�Ż��ƣ���β�ƣ�ũ�ó���
#define LT_POLICE   5   //��������
#define LT_ARMPOL   6   //�侯����
#define LT_INDIVI   7   //���Ի�����
#define LT_ARMY     8   //���ž�����
#define LT_ARMY2    9   //˫�ž�����
#define LT_EMBASSY  10  //ʹ�ݳ���
#define LT_HONGKONG 11  //��۽����й���½����
#define LT_TRACTOR  12  //ũ�ó���
#define LT_COACH	13  //��������
#define LT_MACAO	14  //���Ž����й���½����
#define LT_ARMPOL2   15 //˫���侯����
#define LT_ARMPOL_ZONGDUI 16  // �侯�ܶӳ���
#define LT_ARMPOL2_ZONGDUI 17 // ˫���侯�ܶӳ���

//�˶�����
#define DIRECTION_LEFT	1  //��
#define DIRECTION_RIGHT	2  //��
#define DIRECTION_UP	3  //��
#define DIRECTION_DOWN	4  //��

//ͼ���ʽ��TH_SetImageFormat������cImageFormat������
#define ImageFormatRGB		0			//RGBRGBRGB...
#define ImageFormatBGR		1			//BGRBGRBGR...
#define ImageFormatYUV422	2			//YYYY...UU...VV..	(YV16)
#define ImageFormatYUV420COMPASS 3		//YYYY...UV...		(NV12)
#define ImageFormatYUV420	4			//YYYY...U...V...	(YU12)
#define ImageFormatUYVY	    5			//UYVYUYVYUYVY...	(UYVY)
#define ImageFormatNV21		6			//YYYY...VU...		(NV21)
#define ImageFormatYV12		7			//YYYY...V...U		(YV12)
#define ImageFormatYUYV	    8			//YUYVYUYVYUYV..	(YUYV)

//������ɫ
#define LGRAY_DARK	0	//��
#define LGRAY_LIGHT	1	//ǳ

#define LCOLOUR_WHITE	0	//��	
#define LCOLOUR_SILVER	1	//��(��)
#define LCOLOUR_YELLOW	2	//��
#define LCOLOUR_PINK	3	//��
#define LCOLOUR_RED		4	//��
#define LCOLOUR_GREEN	5	//��
#define LCOLOUR_BLUE	6	//��
#define LCOLOUR_BROWN	7	//�� 
#define LCOLOUR_BLACK	8	//��

// ����ʶ�����Ͷ���
typedef enum _TH_TRIGGER_TYPE
{
	TRIGGER_TYPE_AUTO		=	0,		//�Զ�
	TRIGGER_TYPE_EXTERNAL	=	1,		//�ⲿ
	TRIGGER_TYPE_SOFTWARE	=	2,		//����
	TRIGGER_TYPE_VLOOP					//����ظ���Ȧ
}TH_TRIGGER_TYPE;

typedef enum
{
	TRIGGER_TYPE_AUTO_BIT		= 1,
	TRIGGER_TYPE_EXTERNAL_BIT	= 1<<1,
	TRIGGER_TYPE_SOFTWARE_BIT	= 1<<2,
	TRIGGER_TYPE_VLOOP_BIT		= 1<<3
}
TH_TRIGGER_TYPE_BIT;

/**����������Ϣ*/
typedef struct TH_RECT
{
	int left;	/**<��*/
	int top;	/**<��*/
	int right;	/**<��*/
	int bottom;	/**<��*/
}TH_RECT;

typedef struct TH_TimeVal
{
	long    tv_sec;         /* �� */
	long    tv_usec;        /* ΢�� */
	long	tv_frameStamp;	/* ֡��� */
}TH_TimeVal;

typedef struct
{
	unsigned uTVSec;
	unsigned uTVUSec;
}
VZ_TIMEVAL;

#define TH_LP_LEN	16

/**����ʶ������Ϣ*/
typedef struct TH_PlateResult 
{
	char license[TH_LP_LEN];   /**<���ƺ���*/
	char color[8];      /**<������ɫ*/
	int nColor;			/**<������ɫ��ţ����������ɫ����LC_X*/
	int nType;			/**<�������ͣ�����������Ͷ���LT_X*/
	int nConfidence;	/**<���ƿ��Ŷ�*/
	int nBright;		/**<��������*/
	int nDirection;		/**<�˶���������˶������� DIRECTION_X*/
	TH_RECT rcLocation; /**<����λ��*/
	int nTime;          /**<ʶ������ʱ��*/
	VZ_TIMEVAL tvPTS;
	unsigned uBitsTrigType;	//ǿ�ƴ�����������͵����,��TH_TRIGGER_TYPE_BIT
	unsigned char nCarBright;		/**<��������*/
	unsigned char nCarColor;		/**<������ɫ�����������ɫ����LCOLOUR_X*/
	char reserved[90];	// ����
}TH_PlateResult;

typedef struct TH_PlateResultImage
{
	char license[16];				// ���ƺ���
	char color[8];					// ������ɫ
	int nColor;						// ������ɫ���
	int nType;						// ��������
	int nConfidence;				// ���ƿ��Ŷ�
	int nBright;					// ��������
	int nDirection;					// �˶�����0 unknown, 1 left, 2 right, 3 up , 4 down	
	int nTime;						// ʶ������ʱ��
	unsigned char nCarBright;		// ��������
	unsigned char nCarColor;		// ������ɫ

	unsigned char* pImageRGB24;     // ץ��ʶ�𵽳��Ƶ�ͼ��,RGB24λ��ʽ
	int nImageWidth;				// ץ��ʶ�𵽳��Ƶ�ͼ��Ŀ���
	int nImageHeight;				// ץ��ʶ�𵽳��Ƶ�ͼ��ĸ߶�

	TH_RECT		rcLocation;			// ץ�ĳ������ڵ�λ��
	TH_TimeVal  tv_time;			// ץ�ĳ��Ƶ�ʱ��

	char reserved[2];
}TH_PlateResultImage;


#endif