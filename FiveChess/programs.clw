; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEnter
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "programs.h"
LastPage=0

ClassCount=7
Class1=CProgramsApp
Class2=CProgramsDoc
Class3=CProgramsView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CDig
Resource3=IDD_SCORE
Class7=CEnter
Resource4=IDD_ENTER

[CLS:CProgramsApp]
Type=0
HeaderFile=programs.h
ImplementationFile=programs.cpp
Filter=N

[CLS:CProgramsDoc]
Type=0
HeaderFile=programsDoc.h
ImplementationFile=programsDoc.cpp
Filter=N

[CLS:CProgramsView]
Type=0
HeaderFile=programsView.h
ImplementationFile=programsView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CProgramsView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=programs.cpp
ImplementationFile=programs.cpp
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

[CLS:CDig]
Type=0
HeaderFile=Dig.h
ImplementationFile=Dig.cpp
BaseClass=CDialog
Filter=D
LastObject=CDig
VirtualFilter=dWC

[DLG:IDD_SCORE]
Type=1
Class=CDig
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_PALYER1,static,1342308352
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC_NUM1,static,1342308352
Control5=IDC_STATIC_PALYER2,static,1342308352
Control6=IDC_STATIC_PALYER3,static,1342308352
Control7=IDC_STATIC_NUM2,static,1342308352
Control8=IDC_STATIC_NUM3,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352

[DLG:IDD_ENTER]
Type=1
Class=CEnter
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_STATIC,static,1350697473
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352

[CLS:CEnter]
Type=0
HeaderFile=Enter.h
ImplementationFile=Enter.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

