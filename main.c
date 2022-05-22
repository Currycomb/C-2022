#include <windows.h>
#include <winuser.h>
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h"


static double winwidth,winheight;
static int buttonbar=1;

void drawmenu();
void drawButtons(); 
void drawEditText();

void display(void);
//
//void DisplayClear(void);
//
//void startTimer(int id,int timeinterval);
//
void CharEventProcess(char ch)
{
	uiGetChar(ch);
	display();
}//�ַ���Ӧ 
//
void KeyboardEventProcess(int key,int event)
{
	uiGetKeyboard(key,event);
	display();
}//������Ӧ

void MouseEventProcess(int x,int y,int button,int event)
{
	uiGetMouse(x,y,button,event);
	display();
}//�����Ӧ 

//void TimerEventProcess(int timerID)
//{
//	switch(timerID){
//		
//	}
//	display();
//}

void Main()
{
	SetWindowTitle("¥���ı��༭��");
	InitGraphics();
	
	winwidth=GetWindowWidth();
	winheight=GetWindowHeight();
	
    registerCharEvent(CharEventProcess);        // �ַ�
	registerKeyboardEvent(KeyboardEventProcess);// ����
	registerMouseEvent(MouseEventProcess);      // ���
//	registerTimerEvent(TimerEventProcess);      // ��ʱ��
	
//	startTimer()
    display();

}

//���˵� 
void drawmenu()
{
	static char *MenuListFile[]={"File",
	    "�½�     |  Ctrl+N",
		"��     |  Ctrl+O",
		"����     |  Ctrl+S",
		"�˳�     |     Esc"};
		
	static char *MenuListEdit[]={"Edit",
	    "����     |  Ctrl+Z",
		"����     |  Ctrl+X",
		"����     |  Ctrl+C",
		"ճ��     |  Ctrl+V",
		"ɾ��     |  Delete",
		"����     |  Ctrl+F",
		"�滻     |  Ctrl+H",
		"ȫѡ     |  Ctrl+A"};
		
	static char *MenuListFormat[]={"Format",
	    "�Ӵ�     |  Ctrl+B",
		"б��     |  Ctrl+I",
		"����     |  Ctrl+U",  
	    "����              ",
		"�ֺ�              "};
		
	static char *MenuListView[]={"View",
	    "�Ŵ�     |  Ctrl+ �Ӻ�",
		"��С     |  Ctrl+ ����",
		"��ʾ / ����   �����      "};
		
	static char *MenuListHelp[]={"Help",
	    "���ڱ༭��..."};
		
	static char *selectedLabel = NULL;
	
	double fH=GetFontHeight();
	double x=0;
	double y=winheight;
	double h=fH*1.5;
	double w=TextStringWidth(MenuListFormat[0])*2;
	double wlist;
	int selection;//�ؼ������ 
	
	drawMenuBar(0,y-h,winwidth,h);
	
	wlist=TextStringWidth(MenuListFile[1])*1.2;
	selection=menuList(GenUIID(0),x,y-h,w,wlist,h,MenuListFile,sizeof(MenuListFile)/sizeof(MenuListFile[0]));
	switch(selection){
		case 1: 
		case 2: 
		case 3:
			selectedLabel = MenuListFile[selection]; break;
		case 4:
			exit(-1);
	}//�˵�֮Flie 
	
	wlist=TextStringWidth(MenuListEdit[1])*1.2;
	selection=menuList(GenUIID(0),x+w,y-h,w,wlist,h,MenuListEdit,sizeof(MenuListEdit)/sizeof(MenuListEdit[0]));
	switch(selection){
		case 1: 
		case 2: 
		case 3: 
		case 4: 
		case 5:
	    case 6:
	    case 7:
	    case 8:
			selectedLabel = MenuListFile[selection]; break;
	}//�˵�֮Edit
	
	wlist=TextStringWidth(MenuListFormat[1])*1.2;
	selection=menuList(GenUIID(0),x+2*w,y-h,w,wlist,h,MenuListFormat,sizeof(MenuListFormat)/sizeof(MenuListFormat[0]));
	switch(selection){
		case 1: 
		case 2: 
		case 3: 
		case 4: 
		case 5:
			selectedLabel = MenuListFile[selection]; break;
	}//�˵�֮Format
	
	wlist=TextStringWidth(MenuListView[1])*1.2;
	selection=menuList(GenUIID(0),x+3*w,y-h,w,wlist,h,MenuListView,sizeof(MenuListView)/sizeof(MenuListView[0]));
	switch(selection){
		case 1: 
		case 2: 
			selectedLabel = MenuListFile[selection]; break;
	    case 3:
	    	buttonbar=!buttonbar; break;
		     
	}//�˵�֮View
	
	wlist=TextStringWidth(MenuListHelp[1])*1.2;
	selection=menuList(GenUIID(0),x+4*w,y-h,w,wlist,h,MenuListHelp,sizeof(MenuListHelp)/sizeof(MenuListHelp[0]));
	switch(selection){
		case 1: 
			selectedLabel = MenuListFile[selection]; break;
	}//�˵�֮Help
	
	setMenuColors("Black","Black","Red","Black",0);//��ɫ 
	
}
   
   
//����ť 
void drawButtons()
{
	int flag=1;//���԰�ť 
	double fH=GetFontHeight();
	double x=winwidth*2/3;
	double y=winheight;
	double h=fH*1.5;
	//�ؼ������ 
	
	if (button(GenUIID(0), x, y-h, h, h,"A"))
	{
		flag=0;
	} 
	
	if (button(GenUIID(0), x+h, y-h, h, h,"B"))
	{
		flag=0;
	} 
	
	if (button(GenUIID(0), x+2*h, y-h, h, h,"C"))
	{
		flag=0;
	} 
	
	if (button(GenUIID(0), x+3*h, y-h, h, h,"D"))
	{
		flag=0;
	} 
	
	if (button(GenUIID(0), x+4*h, y-h, h, h,"E"))
	{
		flag=0;
	} 
	
	if (button(GenUIID(0), x+5*h, y-h, h, h,"F"))
	{
		flag=0;
	} 
	
	if (button(GenUIID(0), x+6*h, y-h, h, h,"G"))
	{
		flag=0;
	} 
	
	if (button(GenUIID(0), x+7*h, y-h, h, h,"H"))
	{
		flag=0;
	} 
	
	if (button(GenUIID(0), x+8*h, y-h, h, h,"I"))
	{
		flag=0;
	} 
	
	if (button(GenUIID(0), x+9*h, y-h, h, h,"J"))
	{
		flag=0;
	} 
	
	setButtonColors("Black","Black","Red","Red",0);//��ɫ 
}

//�ı��� 
void drawEditText()
{
	static char Text[27][100]={"","","","","","","","","","","","","","","","","","","","","","","","","","",""};
	int i;
	double fH=GetFontHeight();
	double x=0;
	double w=winwidth;
	double h=fH*1.5;
	double y=winheight-2*h;//�ؼ������  
	
	for(i=0;i<27;i++){
	    textbox(GenUIID(i),x,y-i*h,w,h,Text[i],sizeof(Text[i]));
	}
	
	setTextBoxColors("Light Gray","Black","Light Gray","Black",0);
	
}

void display()
{
	DisplayClear();
	
	drawEditText();
	drawmenu();
	if(buttonbar==1)
	{
	    drawButtons();
    }
}


















