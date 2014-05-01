; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGetin
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Program.h"
LastPage=0

ClassCount=8
Class1=CProgramApp
Class2=CProgramDoc
Class3=CProgramView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_DIALOG2
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CEnter
Resource3=IDD_DIALOG1
Resource4=IDD_ABOUTBOX
Class7=CServer
Class8=CGetin
Resource5=IDD_DIALOG3

[CLS:CProgramApp]
Type=0
HeaderFile=Program.h
ImplementationFile=Program.cpp
Filter=N

[CLS:CProgramDoc]
Type=0
HeaderFile=ProgramDoc.h
ImplementationFile=ProgramDoc.cpp
Filter=N

[CLS:CProgramView]
Type=0
HeaderFile=ProgramView.h
ImplementationFile=ProgramView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Program.cpp
ImplementationFile=Program.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_APP_ABOUT
CommandCount=11

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[CLS:CEnter]
Type=0
HeaderFile=Enter.h
ImplementationFile=Enter.cpp
BaseClass=CDialog
Filter=D
LastObject=CEnter
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=CServer
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552

[DLG:IDD_DIALOG3]
Type=1
Class=CGetin
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG1]
Type=1
Class=CEnter
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO1,button,1342177289
Control4=IDC_RADIO2,button,1342177289
Control5=IDC_STATIC,static,1342308352

[CLS:CServer]
Type=0
HeaderFile=Server.h
ImplementationFile=Server.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CServer

[CLS:CGetin]
Type=0
HeaderFile=Getin.h
ImplementationFile=Getin.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

