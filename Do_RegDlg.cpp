// Do_RegDlg.cpp : implementation file
#include "stdafx.h"
#include "Do_Reg.h"
#include "Do_RegDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDo_RegDlg dialog

CDo_RegDlg::CDo_RegDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDo_RegDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDo_RegDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDo_RegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDo_RegDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDo_RegDlg, CDialog)
	//{{AFX_MSG_MAP(CDo_RegDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EnumValue, OnEnumValue)
	ON_BN_CLICKED(IDC_CreateValue, OnCreateValue)
	ON_BN_CLICKED(IDC_DeleteValue, OnDeleteValue)
	ON_BN_CLICKED(IDC_EnumKey, OnEnumKey)
	ON_BN_CLICKED(IDC_CreateKey, OnCreateKey)
	ON_BN_CLICKED(IDC_DeleteKey, OnDeleteKey)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CDo_RegDlg::backup)
	ON_BN_CLICKED(IDC_Recover, &CDo_RegDlg::onRecover)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDo_RegDlg message handlers

BOOL CDo_RegDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDo_RegDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDo_RegDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDo_RegDlg::OnEnumValue() 
{
   HKEY key;
   long re=RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
	   0,KEY_ALL_ACCESS,&key);
   if(re!=ERROR_SUCCESS){
	   ::MessageBox(0,"�򿪼�ʧ��","��ʾ����",MB_OK);
	   return;          }

   DWORD dinx=0; //��0��ʼ
   char valuename[200];  //������ֵ���ƻ�����
   strcpy(valuename,"CdnCtr");  //���ָ���ĸ���ֵ��
   DWORD nsize=69;  //��ֵ���ƻ�������С
   DWORD k=REG_SZ;  //ָ���������ͣ�Ϊ�ַ���
   unsigned char vari[70]; //������ֵ������
   DWORD ncbvari=69; //��ֵ��������С

   while((re=RegEnumValue(key,dinx,valuename,&nsize,NULL,&k,vari,&ncbvari)) 
          != ERROR_NO_MORE_ITEMS) //һֱѭ����ֱ�����ظ�ֵ
   {
       dinx++;//���� +1,׼��ȡ��һ��ֵ
       nsize=69; //�ָ�ԭ����С
       ncbvari=69;
	   ::MessageBox(0,(char *)vari,valuename,MB_OK);
   }
//�ɹ��󷵻�ֵ0,���������غ���������:
//valuename=��ֵ����,��0��β;�� : DeskColor
//nsize=��ֵ���Ƴ���, 9
//k=REG_SZ  DeskColor ������Ϊ REG_SZ
//vari=��ֵ,32768 DeskColor="32768",
//ncbvari=��ֵ���� REG_SZ������β0,=6, 
   ::RegCloseKey(key);
}

void CDo_RegDlg::OnCreateValue() 
{
   HKEY key;
   long re=RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\11111",
	   0,KEY_ALL_ACCESS,&key);
   if(re!=ERROR_SUCCESS){
	   ::MessageBox(0,"�򿪼�ʧ��","��ʾ����",MB_OK);
	   return;          }
   unsigned char name[]="value1";
   ::RegSetValueEx(key,"one",0,REG_SZ,name,strlen((char *)name));

   ::RegCloseKey(key);	
}

void CDo_RegDlg::OnDeleteValue() 
{
   HKEY key;
   long re=RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE",
	   0,KEY_ALL_ACCESS,&key);
   if(re!=ERROR_SUCCESS){
	   ::MessageBox(0,"�򿪼�ʧ��","��ʾ����",MB_OK);
	   return;          }

   ::RegDeleteValue(key,"one");

   ::RegCloseKey(key);	 	
}

void CDo_RegDlg::OnEnumKey() 
{
   HKEY key;
   long re=RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion",
	   0,KEY_ALL_ACCESS,&key);
   if(re!=ERROR_SUCCESS){
	   ::MessageBox(0,"�򿪼�ʧ��","��ʾ����",MB_OK);
	   return;          }

   DWORD dinx=0;
   char valuename[200];  //������ֵ���ƻ�����
   strcpy(valuename,"CdnCtr");  //���ָ���ĸ���ֵ��
   DWORD nsize=69;  //��ֵ���ƻ�������С
   DWORD k=REG_SZ;  //ָ���������ͣ�Ϊ�ַ���
   char vari[70]; //������ֵ������
   DWORD ncbvari=69; //��ֵ��������С
   CString inf;
   inf="";

   while((re=RegEnumKeyEx(key,dinx,valuename,&nsize,NULL,vari,&k,NULL)) 
          != ERROR_NO_MORE_ITEMS) //һֱѭ����ֱ�����ظ�ֵ
   {
       dinx++;//���� +1,׼��ȡ��һ��ֵ
       nsize=69; //�ָ�ԭ����С
       ncbvari=69;
	   inf+=valuename;
	   inf+="\r\n";
   }
	   ::MessageBox(0,inf,"�ҵ�������",MB_OK);

//�ɹ��󷵻�ֵ0,���������غ���������:
//valuename=��ֵ����,��0��β;�� : DeskColor
//nsize=��ֵ���Ƴ���, 9
//k=REG_SZ  DeskColor ������Ϊ REG_SZ
//vari=��ֵ,32768 DeskColor="32768",
//ncbvari=��ֵ���� REG_SZ������β0,=6, 
   ::RegCloseKey(key); 	
}

void CDo_RegDlg::OnCreateKey() 
{
	/* char KeyName[]="one";
	 const char *val="0";
	 DWORD len=80;*/
   HKEY subKey;
   ::RegCreateKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\11111",0,NULL,
	   REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL,&subKey,NULL);
   /*::RegSetValueEx(subKey,
	             KeyName,
                 0,
                 REG_SZ,
                 (const BYTE*)val,                   
                 len);
   */

   ::RegCloseKey(subKey); 	
}

void CDo_RegDlg::OnDeleteKey()      
{
   HKEY key;
   long re=RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE",          //ɾ���ӽ������ȴ򿪸�����Ȼ����ɾ��
	   0,KEY_ALL_ACCESS,&key);
   if(re!=ERROR_SUCCESS){
	   ::MessageBox(0,"�򿪼�ʧ��","��ʾ����",MB_OK);
	   return;          }
	::RegDeleteKey(key,"11111");	
    ::RegCloseKey(key); 
}


void CDo_RegDlg::backup()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char strKey[] = "SOFTWARE\\11111";   //����д�����ݵ���11111����������һЩ���ֵ ����ʱ��ס�Լ�����һ��������Ϊ�������Ȼע���ᱻ����
	LPTSTR szSaveFileName;
	HKEY key;
	// ���뱸��Ȩ��
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return;
	LookupPrivilegeValue(NULL, SE_BACKUP_NAME, &tkp.Privileges[0].Luid);//����SE_BACKUP_NAMEȨ�� Ҳ���Ǳ���ע���Ȩ��
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	//��ʼ���ݹ���
	szSaveFileName = LPTSTR("H:\\KeyData");        //ע���ļ����ɴ��ڷ����޷��ɹ��������ļ�����ָ���ļ�����
	RegOpenKeyEx(HKEY_LOCAL_MACHINE, (LPCTSTR)strKey, 0, KEY_ALL_ACCESS, &key);
	RegSaveKey(key, szSaveFileName, NULL);
	RegCloseKey(key);

}


void CDo_RegDlg::onRecover()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int valueone;
	int valuetwo;
	char strKey[] = "SOFTWARE\\11111";      //����д���ָ�����11111����������һЩ���ֵ
	LPTSTR szSaveFileName;
	HKEY key;
	// ����ָ�Ȩ��
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return;
	LookupPrivilegeValue(NULL, SE_RESTORE_NAME, &tkp.Privileges[0].Luid);//����SE_RESTORE_NAMEȨ�� Ҳ���ǻָ�ע���Ȩ��Ȩ��
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	//��ʼ�ָ�����
	szSaveFileName = LPTSTR("H:\\KeyData");   
	valuetwo=RegOpenKeyEx(HKEY_LOCAL_MACHINE, (LPCTSTR)strKey, 0, KEY_ALL_ACCESS, &key);
	if (valuetwo== ERROR_SUCCESS)
	{
		MessageBox("�ɹ�");
	}
	else 
	{
		char two[10];
		sprintf(two, "%d", valuetwo);
		MessageBox(two);
	}
	valueone=RegRestoreKey(key, szSaveFileName,REG_FORCE_RESTORE);//REG_FORCE_RESTORE Ҫָ��������ԣ�����ָ����������ûָ���  REG_WHOLE_HIVE_VOLATILE������Իָ�ʱ������Ч
	if (valueone== ERROR_SUCCESS)
	{
		MessageBox("�ָ��ɹ�");
	}
	else
	{
		char one[10];
		sprintf(one, "%d", valueone);
		MessageBox(one);
	}
	RegCloseKey(key);
}
   