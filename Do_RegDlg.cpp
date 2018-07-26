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
	   ::MessageBox(0,"打开键失败","提示错误",MB_OK);
	   return;          }

   DWORD dinx=0; //从0开始
   char valuename[200];  //分配数值名称缓冲区
   strcpy(valuename,"CdnCtr");  //随便指定哪个键值名
   DWORD nsize=69;  //数值名称缓冲区大小
   DWORD k=REG_SZ;  //指明数据类型，为字符串
   unsigned char vari[70]; //分配数值缓冲区
   DWORD ncbvari=69; //数值缓冲区大小

   while((re=RegEnumValue(key,dinx,valuename,&nsize,NULL,&k,vari,&ncbvari)) 
          != ERROR_NO_MORE_ITEMS) //一直循环，直到返回该值
   {
       dinx++;//索引 +1,准备取下一个值
       nsize=69; //恢复原来大小
       ncbvari=69;
	   ::MessageBox(0,(char *)vari,valuename,MB_OK);
   }
//成功后返回值0,各变量返回后设置如下:
//valuename=数值名称,以0结尾;如 : DeskColor
//nsize=数值名称长度, 9
//k=REG_SZ  DeskColor 的类型为 REG_SZ
//vari=键值,32768 DeskColor="32768",
//ncbvari=键值长度 REG_SZ包括结尾0,=6, 
   ::RegCloseKey(key);
}

void CDo_RegDlg::OnCreateValue() 
{
   HKEY key;
   long re=RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\11111",
	   0,KEY_ALL_ACCESS,&key);
   if(re!=ERROR_SUCCESS){
	   ::MessageBox(0,"打开键失败","提示错误",MB_OK);
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
	   ::MessageBox(0,"打开键失败","提示错误",MB_OK);
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
	   ::MessageBox(0,"打开键失败","提示错误",MB_OK);
	   return;          }

   DWORD dinx=0;
   char valuename[200];  //分配数值名称缓冲区
   strcpy(valuename,"CdnCtr");  //随便指定哪个键值名
   DWORD nsize=69;  //数值名称缓冲区大小
   DWORD k=REG_SZ;  //指明数据类型，为字符串
   char vari[70]; //分配数值缓冲区
   DWORD ncbvari=69; //数值缓冲区大小
   CString inf;
   inf="";

   while((re=RegEnumKeyEx(key,dinx,valuename,&nsize,NULL,vari,&k,NULL)) 
          != ERROR_NO_MORE_ITEMS) //一直循环，直到返回该值
   {
       dinx++;//索引 +1,准备取下一个值
       nsize=69; //恢复原来大小
       ncbvari=69;
	   inf+=valuename;
	   inf+="\r\n";
   }
	   ::MessageBox(0,inf,"找到键如下",MB_OK);

//成功后返回值0,各变量返回后设置如下:
//valuename=数值名称,以0结尾;如 : DeskColor
//nsize=数值名称长度, 9
//k=REG_SZ  DeskColor 的类型为 REG_SZ
//vari=键值,32768 DeskColor="32768",
//ncbvari=键值长度 REG_SZ包括结尾0,=6, 
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
   long re=RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE",          //删除子健必须先打开父键，然后再删除
	   0,KEY_ALL_ACCESS,&key);
   if(re!=ERROR_SUCCESS){
	   ::MessageBox(0,"打开键失败","提示错误",MB_OK);
	   return;          }
	::RegDeleteKey(key,"11111");	
    ::RegCloseKey(key); 
}


void CDo_RegDlg::backup()
{
	// TODO: 在此添加控件通知处理程序代码
	char strKey[] = "SOFTWARE\\11111";   //这样写，备份的是11111项所包含的一些子项及值 测试时记住自己建立一个子项作为测试项，不然注册表会被搞乱
	LPTSTR szSaveFileName;
	HKEY key;
	// 申请备份权限
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return;
	LookupPrivilegeValue(NULL, SE_BACKUP_NAME, &tkp.Privileges[0].Luid);//申请SE_BACKUP_NAME权限 也就是备份注册表权限
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	//开始备份工作
	szSaveFileName = LPTSTR("H:\\KeyData");        //注意文件不可存在否则无法成功，备份文件无需指定文件类型
	RegOpenKeyEx(HKEY_LOCAL_MACHINE, (LPCTSTR)strKey, 0, KEY_ALL_ACCESS, &key);
	RegSaveKey(key, szSaveFileName, NULL);
	RegCloseKey(key);

}


void CDo_RegDlg::onRecover()
{
	// TODO: 在此添加控件通知处理程序代码
	int valueone;
	int valuetwo;
	char strKey[] = "SOFTWARE\\11111";      //这样写，恢复的是11111项所包含的一些子项及值
	LPTSTR szSaveFileName;
	HKEY key;
	// 申请恢复权限
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return;
	LookupPrivilegeValue(NULL, SE_RESTORE_NAME, &tkp.Privileges[0].Luid);//申请SE_RESTORE_NAME权限 也就是恢复注册表权限权限
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	//开始恢复工作
	szSaveFileName = LPTSTR("H:\\KeyData");   
	valuetwo=RegOpenKeyEx(HKEY_LOCAL_MACHINE, (LPCTSTR)strKey, 0, KEY_ALL_ACCESS, &key);
	if (valuetwo== ERROR_SUCCESS)
	{
		MessageBox("成功");
	}
	else 
	{
		char two[10];
		sprintf(two, "%d", valuetwo);
		MessageBox(two);
	}
	valueone=RegRestoreKey(key, szSaveFileName,REG_FORCE_RESTORE);//REG_FORCE_RESTORE 要指定这个属性（常规恢复，就是永久恢复）  REG_WHOLE_HIVE_VOLATILE这个属性恢复时测试无效
	if (valueone== ERROR_SUCCESS)
	{
		MessageBox("恢复成功");
	}
	else
	{
		char one[10];
		sprintf(one, "%d", valueone);
		MessageBox(one);
	}
	RegCloseKey(key);
}
   