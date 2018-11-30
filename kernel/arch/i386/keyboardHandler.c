#include <stdint.h>
#include <stdbool.h>

#include <kernel/keyboardHandler.h>
#include <kernel/keyboard.h>
#include <stdio.h>

bool numberLock = false;
bool capsLock = false;
bool scrollLock = false;
bool e0 = false;
int e1 = false;

bool pressedKeys[256];

bool isPressed(uint8_t keyCode)
{
    return pressedKeys[keyCode];
}


bool isShift()
{
    return 
        ((isPressed(VK_LSHIFT) || isPressed (VK_RSHIFT)) && !capsLock)
        || 
        ((!isPressed(VK_LSHIFT) && !isPressed(VK_RSHIFT)) && capsLock); 
}

void addKey(uint8_t keyCode)
{
    pressedKeys[keyCode] = true;
}

void removeKey(uint8_t keyCode)
{
    pressedKeys[keyCode] = false;
}

void updateLED()
{
    setLEDs(scrollLock ? SCROLL_LOCK : 0 | numberLock ? NUMBER_LOCK : 0 | capsLock ? CAPS_LOCK : 0);
}

void pressed_ESC()
{
    addKey(VK_ESC);
}

void released_ESC()
{
    removeKey(ESC);
}

void pressed_ONE_EXCLA()
{
    addKey(VK_ONE);
    if(isShift())
    {
        putchar(EXCLA);
        return;
    }
    putchar(ONE);
}

void released_ONE_EXCLA()
{
    removeKey(VK_ONE);
}

void pressed_TWO_AT()
{
    addKey(VK_TWO);
    if(isShift())
    {
        putchar(AT);
        return;
    }
    putchar(TWO);
}
 
void released_TWO_AT()
{
    removeKey(VK_TWO);
}

void pressed_THREE_NUMBR()
{
    addKey(THREE);
    if(isShift())
    {
        putchar(NUMBR);
        return;
    }
    putchar(THREE);
}

void released_THREE_NUMBR()
{
    removeKey(VK_THREE);
}

void pressed_FOUR_USD()
{
    addKey(FOUR);
    if (isShift())
    {
        putchar(USD);
        return;
    }
    putchar(FOUR);
}

void released_FOUR_USD()
{
    removeKey(VK_FOUR);
}

void pressed_FIVE_PERC()
{
    addKey(FIVE);
    if(isShift())
    {
        putchar(PERCE);
        return;
    }
    putchar(FIVE);
}
    
void released_FIVE_PERC()
{
    removeKey(VK_FIVE);
}

void pressed_SIX_CARET()
{
    addKey(SIX);
    if(isShift())
    {
        putchar(CARET);
        return;
    }
    putchar(SIX);
}
   
void released_SIX_CARET()
{
    removeKey(VK_SIX);
}
        
void pressed_SEVEN_NPERC()
{
    addKey(SEVEN);
    if(isShift())
    {
        putchar(NPERC);
        return;
    }
    putchar(SEVEN);
}

    
void released_SEVEN_NPERC()
{
    removeKey(VK_SEVEN);
}

void pressed_EIGHT_STAR()
{
    addKey(EIGHT);
    if(isShift())
    {
        putchar(STAR);
        return;
    }
    putchar(EIGHT);
}

void released_EIGHT_STAR()
{
    removeKey(VK_EIGHT);
}

void pressed_NINE_OPBRA()
{
    addKey(NINE);
    if(isShift())
    {
        putchar(OPBRA);
        return;
    }
    putchar(NINE);
}

void released_NINE_OPBRA()
{
    removeKey(VK_NINE);
}

void pressed_ZERO_CLBRA()
{
    addKey(ZERO);
    if(isShift())
    {
        putchar(CLBRA);
        return;
    }
    putchar(ZERO);
}

void released_ZERO_CLBRA()
{
    removeKey(VK_ZERO);
}

void pressed_MINUS_UNDER()
{
    addKey(VK_MINUS_UNDER);
    if(isShift())
    {
        putchar(UNDER);
        return;
    }
    putchar(MINUS);
}

void released_MINUS_UNDER()
{
    removeKey(VK_MINUS_UNDER);
}

void pressed_EQUAL_PLUS()
{
    addKey(VK_EQUAL_PLUS);
    if(isShift())
    {
        putchar(PLUS);
        return;
    }
    putchar(EQUAl);
}

void released_EQUAL_PLUS()
{
    removeKey(VK_EQUAL_PLUS);
}

void pressed_BACKSPACE()
{
    terminal_backspace();
    addKey(VK_BACKSPACE);
}

void released_BACKSPACE()
{
    removeKey(VK_BACKSPACE);
}

void pressed_TAB()
{
    //Handle Autocorrect
    for(int i = 0; i < 4; i++)
    {
        putchar(SP);
    }
    addKey(VK_TAB);
}

void released_TAB()
{
    removeKey(VK_TAB);
}
               
void pressed_Q()
{
    addKey(VK_Q);
    if(isShift())
    {
        putchar(Q);
        return;
    }
    putchar(q);
}

void released_Q()
{
    removeKey(VK_Q);
}
               
void pressed_W()
{
    addKey(VK_W);
    if(isShift())
    {
        putchar(W);
        return;
    }
    putchar(w);
}
  
void released_W()
{
    removeKey(VK_W);
}
               
void pressed_E()
{
    addKey(VK_E);
    if(isShift())
    {
        putchar(E);
        return;
    }
    putchar(e);
}

void released_E()
{
    removeKey(VK_E);
}
               
void pressed_R()
{
    addKey(VK_R);
    if(isShift())
    {
        putchar(R);
        return;
    }
    putchar(r);
}

void released_R()
{
    removeKey(VK_R);
}
      
void pressed_T()
{
    addKey(VK_T);
    if(isShift())
    {
        putchar(T);
        return;
    }
    putchar(t);
}

void released_T()
{
    removeKey(VK_T);
}
       
void pressed_Y()
{
    addKey(VK_Y);
    if(isShift())
    {
        putchar(Y);
        return;
    }
    putchar(y);
}

void released_Y()
{
    removeKey(VK_Y);
}
     
void pressed_U()
{
    addKey(VK_Y);
    if(isShift())
    {
        putchar(U);
        return;
    }
    putchar(u);
}
  
void released_U()
{
    removeKey(VK_U);
}
     
void pressed_I()
{
    addKey(VK_I);
    if(isShift())
    {
        putchar(I);
        return;
    }
    putchar(i);
}

void released_I()
{
    removeKey(VK_I);
}
      
void pressed_O()
{
    addKey(VK_O);
    if(isShift())
    {
        putchar(O);
        return;
    }
    putchar(o);
}
   
void released_O()
{
    removeKey(VK_O);
}
       
void pressed_P()
{
    addKey(VK_P);
    if(isShift())
    {
        putchar(P);
        return;
    }
    putchar(p);
}

void released_P()
{
    removeKey(VK_P);
}
      
void pressed_OPSBR_OPCBR()
{
    addKey(VK_OPSBR_OPCBR);
    if(isShift())
    {
        putchar(OPCBR);
        return;
    }
    putchar(OPSBR);
}

void released_OPSBR_OPCBR()
{
    removeKey(VK_OPSBR_OPCBR);
}
      
void pressed_CLSBR_CLCBR()
{
    addKey(VK_CLSBR_CLCBR);
    if(isShift())
    {
        putchar(CLCBR);
        return;
    }
    putchar(CLSBR);
}

void released_CLSBR_CLCBR()
{
    removeKey(VK_CLSBR_CLCBR);
}

void pressed_ENTER()
{
    printf("\n");
    addKey(VK_ENTER);
}

void released_ENTER()
{
    removeKey(VK_ENTER);
}

void pressed_LCTRL()
{
    addKey(VK_LCONTROL);
}

void released_LCTRL()
{
    removeKey(VK_LCONTROL);
}
       
void pressed_A()
{
    addKey(VK_A);
    if(isShift())
    {
        putchar(A);
        return;
    }
    putchar(a);
}

void released_A()
{
    removeKey(VK_A);
}
       
void pressed_S()
{
    addKey(VK_S);
    if(isShift())
    {
        putchar(S);
        return;
    }
    putchar(s);
}

void released_S()
{
    removeKey(VK_S);
}
      
void pressed_D()
{
    addKey(VK_D);
    if(isShift())
    {
        putchar(D);
        return;
    }
    putchar(d);
}

void released_D()
{
    removeKey(VK_D);
}
       
void pressed_F()
{
    addKey(VK_F);
    if(isShift())
    {
        putchar(F);
        return;
    }
    putchar(f);
}

void released_F()
{
    removeKey(VK_F);
}
      
void pressed_G()
{
    addKey(VK_G);
    if(isShift())
    {
        putchar(G);
        return;
    }
    putchar(g);
}

void released_G()
{
    removeKey(VK_G);
}
       
void pressed_H()
{
    addKey(VK_H);
    if(isShift())
    {
        putchar(H);
        return;
    }
    putchar(h);
}

void released_H()
{
    removeKey(VK_H);
}
       
void pressed_J()
{
    addKey(VK_J);
    if(isShift())
    {
        putchar(J);
        return;
    }
    putchar(j);
}

void released_J()
{
    removeKey(VK_J);
}
      
void pressed_K()
{
    addKey(VK_K);
    if(isShift())
    {
        putchar(K);
        return;
    }
    putchar(k);
}

void released_K()
{
    removeKey(VK_K);
}
    
void pressed_L()
{
    addKey(VK_L);
    if(isShift())
    {
        putchar(L);
        return;
    }
    putchar(l);
}

void released_L()
{
    removeKey(VK_L);
}
       
void pressed_SEMIC_COLON()
{
    addKey(VK_SEMIC_COLON);
    if(isShift())
    {
        putchar(COLON);
        return;
    }
    putchar(SEMIC);
}

void released_SEMIC_COLON()
{
    removeKey(VK_SEMIC_COLON);
}
      
void pressed_APOST_QUOTE()
{
    addKey(VK_APOST_QUOTE);
    if(isShift())
    {
        putchar(QUOTE);
        return;
    }
    putchar(APOST);
}

void released_APOST_QUOTE()
{
    removeKey(VK_APOST_QUOTE);
}
 
void pressed_GRAVE_TILDE()
{
    addKey(VK_GRAVE_TILDE);
    if(isShift())
    {
        putchar(TILDE);
        return;
    }
    putchar(GRAVE);
}

void released_GRAVE_TILDE()
{
    removeKey(VK_GRAVE_TILDE);
}

void pressed_LSHIFT()
{
    addKey(VK_LSHIFT);
}

void released_LSHIFT()
{
    removeKey(VK_LSHIFT);
}

void pressed_BSLASH_VBAR()
{
    addKey(VK_BSLASH_VBAR);
    if(isShift())
    {
        putchar(VBAR);
        return;
    }
    putchar(BSLASH);
}
   
void released_BSLASH_VBAR()
{
    removeKey(VK_BSLASH_VBAR);
}
       
void pressed_Z()
{
    addKey(VK_Z);
    if(isShift())
    {
        putchar(Z);
        return;
    }
    putchar(z);
}
   
void released_Z()
{
    removeKey(VK_Z);
}
       
void pressed_X()
{
    addKey(VK_X);
    if(isShift())
    {
        putchar(X);
        return;
    }
    putchar(x);
}     

void released_X()
{
    removeKey(VK_X);
}
       
void pressed_C()
{
    addKey(VK_C);
    if(isShift())
    {
        putchar(C);
        return;
    }
    putchar(c);
}

void released_C()
{
    removeKey(VK_C);
}

void pressed_V()
{
    addKey(VK_V);
    if(isShift())
    {
        putchar(V);
        return;
    }
    putchar(v);
}

void released_V()
{
    removeKey(VK_V);
}
       
void pressed_B()
{
    addKey(VK_B);
    if(isShift())
    {
        putchar(B);
        return;
    }
    putchar(b);
}

void released_B()
{
    removeKey(VK_B);
}
       
void pressed_N()
{
    addKey(VK_N);
    if(isShift())
    {
        putchar(N);
        return;
    }
    putchar(n);
}

void released_N()
{
    removeKey(VK_N);
}
     
void pressed_M()
{
    addKey(VK_M);
    if(isShift())
    {
        putchar(M);
        return;
    }
    putchar(m);
}

void released_M()
{
    removeKey(VK_M);
}
       
void pressed_KOMMA_LESST()
{
    addKey(VK_KOMMA_LESST);
    if(isShift())
    {
        putchar(LESST);
        return;
    }
    putchar(KOMMA);
}
    
void released_KOMMA_LESST()
{
    removeKey(VK_KOMMA_LESST);
}
       
void pressed_POINT_GREAT()
{
    addKey(VK_POINT_GREAT);
    if(isShift())
    {
        putchar(GREAT);
        return;
    }
    putchar(POINT);
}

void released_POINT_GREAT()
{
    removeKey(VK_POINT_GREAT);
}
       
void pressed_SLASH_QUEST()
{
    addKey(VK_SLASH_QUEST);
    if(isShift())
    {
        putchar(QUEST);
        return;
    }
    putchar(SLASH);
}

void released_SLASH_QUEST()
{
    removeKey(VK_SLASH_QUEST);
}

void pressed_RSHIFT()
{
    addKey(VK_RSHIFT);
}
        
void released_RSHIFT()
{
    removeKey(VK_RSHIFT);
}

void pressed_KP_STAR()
{
    addKey(VK_KP_MULTIPLY);
    putchar(STAR);
}

void released_KP_STAR()
{
    removeKey(VK_KP_MULTIPLY);
}

void pressed_LALT()
{
    addKey(VK_LALT);
}
    
void released_LALT()
{
    removeKey(VK_LALT);
}

void pressed_SPACE()
{
    putchar(SP);
    addKey(VK_SPACE);
}

void released_SPACE()
{
    removeKey(VK_SPACE);
}

void pressed_CAPSLOCK()
{
    capsLock = !capsLock;
    updateLED();
    addKey(VK_CAPS_LOCK);
}

void released_CAPSLOCK()
{
    removeKey(VK_CAPS_LOCK);
}

void pressed_F1()
{
    addKey(VK_F1);
}
   
void released_F1()
{
    removeKey(VK_F1);
}

void pressed_F2()
{
    addKey(VK_F2);
}

void released_F2()
{
    removeKey(VK_F2);
}
    
void pressed_F3()
{
    addKey(VK_F3);
}

void released_F3()
{
    removeKey(VK_F3);
}
    
void pressed_F4()
{
    addKey(VK_F4);
}

void released_F4()
{
    removeKey(VK_F4);
}
    
void pressed_F5()
{
    addKey(VK_F5);
}

void released_F5()
{
    removeKey(VK_F5);
}
    
void pressed_F6()
{
    addKey(VK_F6);
}
    
void released_F6()
{
    removeKey(VK_F6);
}
    
void pressed_F7()
{
    addKey(VK_F7);
}

void released_F7()
{
    removeKey(VK_F7);
}
    
void pressed_F8()
{
    addKey(VK_F8);
}

void released_F8()
{
    removeKey(VK_F8);
}
    
void pressed_F9()
{
    addKey(VK_F9);
}

void released_F9()
{
    removeKey(VK_F9);
}
    
void pressed_F10()
{
    addKey(VK_F10);
}

void released_F10()
{
    removeKey(VK_F10);
}
    
void pressed_F11()
{
    addKey(VK_F11);
}

void released_F11()
{
    removeKey(VK_F11);
}
    
void pressed_F12()
{
    addKey(VK_F12);
}

void released_F12()
{
    removeKey(VK_F12);
}

void pressed_NUMBERLOCK()
{
    addKey(VK_NUMBER_LOCK);
    numberLock = !numberLock;
    updateLED();
}

void released_NUMBERLOCK()
{
    removeKey(VK_NUMBER_LOCK);
}

void pressed_SCROLLOCK()
{
    addKey(VK_SCROLL_LOCK);
    scrollLock = !scrollLock;
    updateLED();
}

void released_SCROLLOCK()
{
    removeKey(VK_SCROLL_LOCK);
}

void pressed_KP_SEVEN()
{
    addKey(VK_KP_SEVEN);
    if(numberLock)
    {
        putchar(SEVEN);
        return;
    }
    //TODO: HOME Function is missing
}

    
void released_KP_SEVEN()
{
    removeKey(VK_KP_SEVEN);
}

void pressed_KP_EIGHT()
{
    addKey(VK_KP_EIGHT);
    if(numberLock)
    {
        putchar(EIGHT);
        return;
    }
    terminal_cursor_up();
}

void released_KP_EIGHT()
{
    removeKey(VK_KP_EIGHT);
}

void pressed_KP_NINE()
{
    addKey(VK_KP_NINE);
    if(numberLock)
    {
        putchar(NINE);
        return;
    }
    //TODO: PgUp Function is missing
}
    
void released_KP_NINE()
{
    removeKey(VK_KP_NINE);
}

void pressed_KP_MINUS()
{
    addKey(VK_KP_MINUS);
    putchar(MINUS);
}

void released_KP_MINUS()
{
    removeKey(VK_KP_MINUS);
}
        
void pressed_KP_FOUR()
{
    addKey(VK_KP_FOUR);
    if(numberLock)
    {
        putchar(FOUR);
        return;
    }
    terminal_cursor_left();
}
    
void released_KP_FOUR()
{
    removeKey(VK_KP_FOUR);
}

void pressed_KP_FIVE(){
    addKey(VK_KP_FIVE);
    if(numberLock)
    {
        putchar(FIVE);
        return;
    }
}

void released_KP_FIVE()
{
    removeKey(VK_KP_FIVE);
}

void pressed_KP_SIX()
{
    addKey(VK_KP_SIX);
    if(numberLock)
    {
        putchar(SIX);
        return;
    }
    terminal_cursor_right();
}
    
void released_KP_SIX()
{
    removeKey(VK_KP_SIX);
}

void pressed_KP_PLUS()
{
    addKey(VK_KP_ADD);
    putchar(PLUS);
}
    
void released_KP_PLUS()
{
    removeKey(VK_KP_ADD);
}

void pressed_KP_ONE()
{
    addKey(VK_KP_ONE);
    if(numberLock)
    {
        putchar(ONE);
        return;
    }
    //TODO END function missing
}

void released_KP_ONE()
{
    removeKey(VK_KP_ONE);
}

void pressed_KP_TWO()
{
    addKey(VK_KP_TWO);
    if(numberLock)
    {
        putchar(TWO);
        return;
    }
    terminal_cursor_down();
}

void released_KP_TWO()
{
    removeKey(VK_KP_TWO);
}

void pressed_KP_THREE()
{
    addKey(VK_KP_THREE);
    if(numberLock)
    {
        putchar(THREE);
        return;
    }
    //TODO: PgDown function missing
}

void released_KP_THREE()
{
    removeKey(VK_KP_THREE);
}

void pressed_KP_ZERO()
{
    addKey(VK_ZERO);
    if(numberLock)
    {
        putchar(ZERO);
        return;
    }
    //TODO: INSERT function missing
}

void released_KP_ZERO()
{
    removeKey(VK_KP_ZERO);
}

void pressed_KP_POINT()
{
    addKey(VK_KP_DECIMAL);
    if(numberLock)
    {
        putchar(POINT);
        return;
    }
    terminal_delete();
}

void released_KP_POINT()
{
    removeKey(VK_KP_DECIMAL);
}

void pressed_e0_KP_ENTER()
{
    printf("\n");
}

void released_e0_KP_ENTER()
{
    removeKey(VK_ENTER);
}

void pressed_e0_RCTRL()
{
    addKey(VK_RCONTROL);
}

void released_e0_RCTRL()
{
    removeKey(VK_RCONTROL);
}

void pressed_e0_KP_SLASH()
{
    putchar(SLASH);
}

void released_e0_KP_SLASH()
{
    removeKey(VK_KP_DEVIDE);
}

void pressed_e0_RALT()
{
    addKey(VK_RALT);
}

void released_e0_RALT()
{
    removeKey(VK_RALT);
}

void pressed_e0_HOME()
{
    addKey(VK_HOME);
}

void released_e0_HOME()
{
    removeKey(VK_HOME);
}

void pressed_e0_PRINT_SCR1()
{
    e0 = true;
}

void pressed_e0_PRINT_SCR2()
{
    //handle printscreen
    addKey(VK_SNAPSHOT);
}

void pressed_e0_UP()
{
    terminal_cursor_up();
    addKey(VK_UP);
}

void released_e0_UP()
{
    removeKey(VK_UP);
}

void pressed_e0_PAGE_UP()
{
    addKey(VK_PAGEUP);
}

void released_e0_PAGE_UP()
{
    removeKey(VK_PAGEUP);
}

void pressed_e0_LEFT()
{
    terminal_cursor_left();
    addKey(VK_LEFT);
}

void released_e0_LEFT()
{
    removeKey(VK_LEFT);
}

void pressed_e0_RIGHT()
{
    terminal_cursor_right();
    addKey(VK_RIGHT);
}

void released_e0_RIGHT()
{
    removeKey(VK_RIGHT);
}

void pressed_e0_END()
{
    addKey(VK_END);
}

void released_e0_END()
{
    removeKey(VK_END);
}

void pressed_e0_DOWN()
{
    terminal_cursor_down();
    addKey(VK_DOWN);
}

void released_e0_DOWN()
{
    removeKey(VK_DOWN);
}

void pressed_e0_PAGE_DOWN()
{
    addKey(VK_PAGEDOWN);
}

void released_e0_PAGE_DOWN()
{
    removeKey(VK_PAGEDOWN);
}

void pressed_e0_INSERT()
{
    addKey(VK_INSERT);
}

void released_e0_INSERT()
{
    removeKey(VK_INSERT);
}

void pressed_e0_DELETE()
{
    terminal_delete();
    addKey(VK_DELETE);
}

void released_e0_DELETE()
{
    removeKey(VK_DELETE);
}

void pressed_e0_LEFT_GUI()
{
    addKey(VK_LGUI);
}

void released_e0_LEFT_GUI()
{
    removeKey(VK_RGUI);
}

void pressed_e0_RIGHT_GUI()
{
    addKey(VK_RGUI);
}

void released_e0_RIGHT_GUI()
{
    removeKey(VK_RGUI);
}

void pressed_e0_APPS()
{
    addKey(VK_APPS);
}

void released_e0_APPS()
{
    removeKey(VK_APPS);
}

void released_e0_PRINT_SCR1()
{
    e0 = true;
}

void released_e0_PRINT_SCR2()
{
    removeKey(VK_SNAPSHOT);
}

void unknwonKey()
{
    //Handle an unknown Key by ignoring it
}

typedef void (*keyFunction)();

keyFunction keyHandlers[256];
keyFunction e0keyHandlers[256];

void keyboardHandlerInit()
{

    //Fill emptyKeycodes so we the os does not crash, if an unknown key was pressed, to it can just ignore it
    for(int i = 0; i < 256; i++)
    {
        keyHandlers[i] = &unknwonKey;
        e0keyHandlers[i] = &unknwonKey;
    }

    keyHandlers[PRESSED_ESC] = &pressed_ESC;
    keyHandlers[PRESSED_ONE_EXCLA] = &pressed_ONE_EXCLA;
    keyHandlers[PRESSED_TWO_AT] = &pressed_TWO_AT;
    keyHandlers[PRESSED_THREE_NUMBR] = &pressed_THREE_NUMBR;
    keyHandlers[PRESSED_FOUR_USD] = &pressed_FOUR_USD;
    keyHandlers[PRESSED_FIVE_PERC] = &pressed_FIVE_PERC;
    keyHandlers[PRESSED_SIX_CARET] = &pressed_SIX_CARET;
    keyHandlers[PRESSED_SEVEN_NPERC] = &pressed_SEVEN_NPERC;
    keyHandlers[PRESSED_EIGHT_STAR] = &pressed_EIGHT_STAR;
    keyHandlers[PRESSED_NINE_OPBRA] = &pressed_NINE_OPBRA;
    keyHandlers[PRESSED_ZERO_CLBRA] = &pressed_ZERO_CLBRA;
    keyHandlers[PRESSED_MINUS_UNDER] = &pressed_MINUS_UNDER;
    keyHandlers[PRESSED_EQUAL_PLUS] = &pressed_EQUAL_PLUS;
    keyHandlers[PRESSED_BACKSPACE] = &pressed_BACKSPACE;
    keyHandlers[PRESSED_TAB] = &pressed_TAB;
    keyHandlers[PRESSED_Q] = &pressed_Q;
    keyHandlers[PRESSED_W] = &pressed_W;
    keyHandlers[PRESSED_E] = &pressed_E;
    keyHandlers[PRESSED_R] = &pressed_R;
    keyHandlers[PRESSED_T] = &pressed_T;
    keyHandlers[PRESSED_Y] = &pressed_Y;
    keyHandlers[PRESSED_U] = &pressed_U;
    keyHandlers[PRESSED_I] = &pressed_I;
    keyHandlers[PRESSED_O] = &pressed_O;
    keyHandlers[PRESSED_P] = &pressed_P;
    keyHandlers[PRESSED_OPSBR_OPCBR] = &pressed_OPSBR_OPCBR;
    keyHandlers[PRESSED_CLSBR_CLCBR] = &pressed_CLSBR_CLCBR;
    keyHandlers[PRESSED_ENTER] = &pressed_ENTER;
    keyHandlers[PRESSED_LCTRL] = &pressed_LCTRL;
    keyHandlers[PRESSED_A] = &pressed_A;
    keyHandlers[PRESSED_S] = &pressed_S;
    keyHandlers[PRESSED_D] = &pressed_D;
    keyHandlers[PRESSED_F] = &pressed_F;
    keyHandlers[PRESSED_G] = &pressed_G;
    keyHandlers[PRESSED_H] = &pressed_H;
    keyHandlers[PRESSED_J] = &pressed_J;
    keyHandlers[PRESSED_K] = &pressed_K;
    keyHandlers[PRESSED_L] = &pressed_L;
    keyHandlers[PRESSED_SEMIC_COLON] = &pressed_SEMIC_COLON;
    keyHandlers[PRESSED_APOST_QUOTE] = &pressed_APOST_QUOTE;
    keyHandlers[PRESSED_GRAVE_TILDE] = &pressed_GRAVE_TILDE;
    keyHandlers[PRESSED_LSHIFT] = &pressed_LSHIFT;
    keyHandlers[PRESSED_BSLASH_VBAR] = &pressed_BSLASH_VBAR;
    keyHandlers[PRESSED_Z] = &pressed_Z;
    keyHandlers[PRESSED_X] = &pressed_X;
    keyHandlers[PRESSED_C] = &pressed_C;
    keyHandlers[PRESSED_V] = &pressed_V;
    keyHandlers[PRESSED_B] = &pressed_B;
    keyHandlers[PRESSED_N] = &pressed_N;
    keyHandlers[PRESSED_M] = &pressed_M;
    keyHandlers[PRESSED_KOMMA_LESST] = &pressed_KOMMA_LESST;
    keyHandlers[PRESSED_POINT_GREAT] = &pressed_POINT_GREAT;
    keyHandlers[PRESSED_SLASH_QUEST] = &pressed_SLASH_QUEST;
    keyHandlers[PRESSED_RSHIFT] = &pressed_RSHIFT;
    keyHandlers[PRESSED_KP_STAR] = &pressed_KP_STAR;
    keyHandlers[PRESSED_LALT] = &pressed_LALT;
    keyHandlers[PRESSED_SPACE] = &pressed_SPACE;
    keyHandlers[PRESSED_CAPSLOCK] = &pressed_CAPSLOCK;
    keyHandlers[PRESSED_F1] = &pressed_F1;
    keyHandlers[PRESSED_F2] = &pressed_F2;
    keyHandlers[PRESSED_F3] = &pressed_F3;
    keyHandlers[PRESSED_F4] = &pressed_F4;
    keyHandlers[PRESSED_F5] = &pressed_F5;
    keyHandlers[PRESSED_F6] = &pressed_F6;
    keyHandlers[PRESSED_F7] = &pressed_F7;
    keyHandlers[PRESSED_F8] = &pressed_F8;
    keyHandlers[PRESSED_F9] = &pressed_F9;
    keyHandlers[PRESSED_F10] = &pressed_F10;
    keyHandlers[PRESSED_NUMBERLOCK] = &pressed_NUMBERLOCK;
    keyHandlers[PRESSED_SCROLLOCK] = &pressed_SCROLLOCK;
    keyHandlers[PRESSED_KP_SEVEN] = &pressed_KP_SEVEN;
    keyHandlers[PRESSED_KP_EIGHT] = &pressed_KP_EIGHT;
    keyHandlers[PRESSED_NINE_OPBRA] = &pressed_NINE_OPBRA;
    keyHandlers[PRESSED_KP_MINUS] = &pressed_KP_MINUS;
    keyHandlers[PRESSED_KP_FOUR] = &pressed_KP_FOUR;
    keyHandlers[PRESSED_KP_FIVE] = &pressed_KP_FIVE;
    keyHandlers[PRESSED_KP_SIX] = &pressed_KP_SIX;
    keyHandlers[PRESSED_KP_PLUS] = &pressed_KP_PLUS;
    keyHandlers[PRESSED_KP_ONE] = &pressed_KP_ONE;
    keyHandlers[PRESSED_KP_TWO] = &pressed_KP_TWO;
    keyHandlers[PRESSED_KP_THREE] = &pressed_KP_THREE;
    keyHandlers[PRESSED_KP_ZERO] = &pressed_KP_ZERO;
    keyHandlers[PRESSED_KP_POINT] = &pressed_KP_POINT;
    keyHandlers[PRESSED_F11] = &pressed_F11;
    keyHandlers[PRESSED_F12] = &pressed_F12;
    
    keyHandlers[RELEASED_ESC] = &released_ESC;
    keyHandlers[RELEASED_ONE_EXCLA] = &released_ONE_EXCLA;
    keyHandlers[RELEASED_TWO_AT] = &released_TWO_AT;
    keyHandlers[RELEASED_THREE_NUMBR] = &released_THREE_NUMBR;
    keyHandlers[RELEASED_FOUR_USD] = &released_FOUR_USD;
    keyHandlers[RELEASED_FIVE_PERC] = &released_FIVE_PERC;
    keyHandlers[RELEASED_SIX_CARET] = &released_SIX_CARET;
    keyHandlers[RELEASED_SEVEN_NPERC] = &released_SEVEN_NPERC;
    keyHandlers[RELEASED_EIGHT_STAR] = &released_EIGHT_STAR;
    keyHandlers[RELEASED_NINE_OPBRA] = &released_NINE_OPBRA;
    keyHandlers[RELEASED_ZERO_CLBRA] = &released_ZERO_CLBRA;
    keyHandlers[RELEASED_MINUS_UNDER] = &released_MINUS_UNDER;
    keyHandlers[RELEASED_EQUAL_PLUS] = &released_EQUAL_PLUS;
    keyHandlers[RELEASED_BACKSPACE] = &released_BACKSPACE;
    keyHandlers[RELEASED_TAB] = &released_TAB;
    keyHandlers[RELEASED_Q] = &released_Q;
    keyHandlers[RELEASED_W] = &released_W;
    keyHandlers[RELEASED_E] = &released_E;
    keyHandlers[RELEASED_R] = &released_R;
    keyHandlers[RELEASED_T] = &released_T;
    keyHandlers[RELEASED_Y] = &released_Y;
    keyHandlers[RELEASED_U] = &released_U;
    keyHandlers[RELEASED_I] = &released_I;
    keyHandlers[RELEASED_O] = &released_O;
    keyHandlers[RELEASED_P] = &released_P;
    keyHandlers[RELEASED_OPSBR_OPCBR] = &released_OPSBR_OPCBR;
    keyHandlers[RELEASED_CLSBR_CLCBR] = &released_CLSBR_CLCBR;
    keyHandlers[RELEASED_ENTER] = &released_ENTER;
    keyHandlers[RELEASED_LCTRL] = &released_LCTRL;
    keyHandlers[RELEASED_A] = &released_A;
    keyHandlers[RELEASED_S] = &released_S;
    keyHandlers[RELEASED_D] = &released_D;
    keyHandlers[RELEASED_F] = &released_F;
    keyHandlers[RELEASED_G] = &released_G;
    keyHandlers[RELEASED_H] = &released_H;
    keyHandlers[RELEASED_J] = &released_J;
    keyHandlers[RELEASED_K] = &released_K;
    keyHandlers[RELEASED_L] = &released_L;
    keyHandlers[RELEASED_SEMIC_COLON] = &released_SEMIC_COLON;
    keyHandlers[RELEASED_APOST_QUOTE] = &released_APOST_QUOTE;
    keyHandlers[RELEASED_GRAVE_TILDE] = &released_GRAVE_TILDE;
    keyHandlers[RELEASED_LSHIFT] = &released_LSHIFT;
    keyHandlers[RELEASED_BSLASH_VBAR] = &released_BSLASH_VBAR;
    keyHandlers[RELEASED_Z] = &released_Z;
    keyHandlers[RELEASED_X] = &released_X;
    keyHandlers[RELEASED_C] = &released_C;
    keyHandlers[RELEASED_V] = &released_V;
    keyHandlers[RELEASED_B] = &released_B;
    keyHandlers[RELEASED_N] = &released_N;
    keyHandlers[RELEASED_M] = &released_M;
    keyHandlers[RELEASED_KOMMA_LESST] = &released_KOMMA_LESST;
    keyHandlers[RELEASED_POINT_GREAT] = &released_POINT_GREAT;
    keyHandlers[RELEASED_SLASH_QUEST] = &released_SLASH_QUEST;
    keyHandlers[RELEASED_RSHIFT] = &released_RSHIFT;
    keyHandlers[RELEASED_KP_STAR] = &released_KP_STAR;
    keyHandlers[RELEASED_LALT] = &released_LALT;
    keyHandlers[RELEASED_SPACE] = &released_SPACE;
    keyHandlers[RELEASED_CAPSLOCK] = &released_CAPSLOCK;
    keyHandlers[RELEASED_F1] = &released_F1;
    keyHandlers[RELEASED_F2] = &released_F2;
    keyHandlers[RELEASED_F3] = &released_F3;
    keyHandlers[RELEASED_F4] = &released_F4;
    keyHandlers[RELEASED_F5] = &released_F5;
    keyHandlers[RELEASED_F6] = &released_F6;
    keyHandlers[RELEASED_F7] = &released_F7;
    keyHandlers[RELEASED_F8] = &released_F8;
    keyHandlers[RELEASED_F9] = &released_F9;
    keyHandlers[RELEASED_F10] = &released_F10;
    keyHandlers[RELEASED_NUMBERLOCK] = &released_NUMBERLOCK;
    keyHandlers[RELEASED_SCROLLOCK] = &released_SCROLLOCK;
    keyHandlers[RELEASED_KP_SEVEN] = &released_KP_SEVEN;
    keyHandlers[RELEASED_KP_EIGHT] = &released_KP_EIGHT;
    keyHandlers[RELEASED_NINE_OPBRA] = &released_NINE_OPBRA;
    keyHandlers[RELEASED_KP_MINUS] = &released_KP_MINUS;
    keyHandlers[RELEASED_KP_FOUR] = &released_KP_FOUR;
    keyHandlers[RELEASED_KP_FIVE] = &released_KP_FIVE;
    keyHandlers[RELEASED_KP_SIX] = &released_KP_SIX;
    keyHandlers[RELEASED_KP_PLUS] = &released_KP_PLUS;
    keyHandlers[RELEASED_KP_ONE] = &released_KP_ONE;
    keyHandlers[RELEASED_KP_TWO] = &released_KP_TWO;
    keyHandlers[RELEASED_KP_THREE] = &released_KP_THREE;
    keyHandlers[RELEASED_KP_ZERO] = &released_KP_ZERO;
    keyHandlers[RELEASED_KP_POINT] = &released_KP_POINT;
    keyHandlers[RELEASED_F11] = &released_F11;
    keyHandlers[RELEASED_F12] = &released_F12;

    e0keyHandlers[PRESSED_E0_KP_ENTER] = &pressed_e0_KP_ENTER;
    e0keyHandlers[PRESSED_E0_RCTRL] = &pressed_e0_RCTRL;
    e0keyHandlers[PRESSED_E0_KP_SLASH] = &pressed_e0_KP_SLASH;
    e0keyHandlers[PRESSED_E0_RALT] = &pressed_e0_RALT;
    e0keyHandlers[PRESSED_E0_UP] = &pressed_e0_UP;
    e0keyHandlers[PRESSED_E0_PAGE_UP] = &pressed_e0_PAGE_UP;
    e0keyHandlers[PRESSED_E0_LEFT] = &pressed_e0_LEFT;
    e0keyHandlers[PRESSED_E0_RIGHT] = &pressed_e0_RIGHT;
    e0keyHandlers[PRESSED_E0_END] = &pressed_e0_END;
    e0keyHandlers[PRESSED_E0_DOWN] = &pressed_e0_DOWN;
    e0keyHandlers[PRESSED_E0_PAGE_DOWN] = &pressed_e0_PAGE_DOWN;
    e0keyHandlers[PRESSED_E0_INSERT] = &pressed_e0_INSERT;
    e0keyHandlers[PRESSED_E0_DELETE] = &pressed_e0_DELETE;
    e0keyHandlers[PRESSED_E0_LEFT_GUI] = &pressed_e0_LEFT_GUI;
    e0keyHandlers[PRESSED_E0_RIGHT_GUI] = &pressed_e0_RIGHT_GUI;
    e0keyHandlers[PRESSED_E0_APPS] = &pressed_e0_APPS;
    e0keyHandlers[PRESSED_E0_PRINT_SCR1] = &pressed_e0_PRINT_SCR1;
    e0keyHandlers[PRESSED_E0_PRINT_SCR2] = &pressed_e0_PRINT_SCR2;

    e0keyHandlers[RELEASED_E0_KP_ENTER] = &released_e0_KP_ENTER;
    e0keyHandlers[RELEASED_E0_RCTRL] = &released_e0_RCTRL;
    e0keyHandlers[RELEASED_E0_KP_SLASH] = &released_e0_KP_SLASH;
    e0keyHandlers[RELEASED_E0_RALT] = &released_e0_RALT;
    e0keyHandlers[RELEASED_E0_UP] = &released_e0_UP;
    e0keyHandlers[RELEASED_E0_PAGE_UP] = &released_e0_PAGE_UP;
    e0keyHandlers[RELEASED_E0_LEFT] = &released_e0_LEFT;
    e0keyHandlers[RELEASED_E0_RIGHT] = &released_e0_RIGHT;
    e0keyHandlers[RELEASED_E0_END] = &released_e0_END;
    e0keyHandlers[RELEASED_E0_DOWN] = &released_e0_DOWN;
    e0keyHandlers[RELEASED_E0_PAGE_DOWN] = &released_e0_PAGE_DOWN;
    e0keyHandlers[RELEASED_E0_INSERT] = &released_e0_INSERT;
    e0keyHandlers[RELEASED_E0_DELETE] = &released_e0_DELETE;
    e0keyHandlers[RELEASED_E0_LEFT_GUI] = &released_e0_LEFT_GUI;
    e0keyHandlers[RELEASED_E0_RIGHT_GUI] = &released_e0_RIGHT_GUI;
    e0keyHandlers[RELEASED_E0_APPS] = &released_e0_APPS;
    e0keyHandlers[RELEASED_E0_PRINT_SCR1] = &released_e0_PRINT_SCR1;
    e0keyHandlers[RELEASED_E0_PRINT_SCR2] = &released_e0_PRINT_SCR2;
}

void keyboard_irq_handler(void)
{
    uint8_t scancode = inb(KBC_IO_BUFFER_PORT);

    if(scancode == 0xFA) //Keyboard ACK
    {
        return;
    }

    if(scancode == EXTEND_E0)
    {        
        e0 = true;
    }
    else if (scancode == EXTEND_E1)
    {
        e1 = 1;
    }
    else{

        if(e0)
        {
            e0 = false;
            //intercept fake shift
            if ((scancode == 0x2A) || (scancode == 0x36)) 
            {
                return;
            }
            //handle_scancode1_E0_to_EN_US(scancode);           
            e0keyHandlers[scancode]();
        }
        else if(e1 == 1)
        {
            if(scancode = PRESSED_PAUSE_5)
            {
                e1 = 0;
                //TODO: handle Pause key
            }
        }
        else
        {
            //handle_scancode1_to_EN_US(scancode);
            keyHandlers[scancode]();
        }
    }
}