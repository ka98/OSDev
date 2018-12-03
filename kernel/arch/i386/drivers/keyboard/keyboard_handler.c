#include <stdint.h>
#include <stdbool.h>

#include "keyboard_handler.h"
#include "keyboard.h"
#include <stdio.h>

bool number_lock = false;
bool caps_lock = false;
bool scroll_lock = false;
bool e0 = false;
int e1 = false;

typedef void (*key_function)();

key_function key_handlers[256];
key_function e0key_handlers[256];

bool pressed_keys[256];

bool is_pressed(uint8_t key_code)
{
    return pressed_keys[key_code];
}

bool is_shift()
{
    return ((is_pressed(VK_LSHIFT) || is_pressed(VK_RSHIFT)) && !caps_lock) ||
           ((!is_pressed(VK_LSHIFT) && !is_pressed(VK_RSHIFT)) && caps_lock);
}

void add_key(uint8_t key_code)
{
    pressed_keys[key_code] = true;
}

void remove_key(uint8_t key_code)
{
    pressed_keys[key_code] = false;
}

void update_LED()
{
    set_LEDs(scroll_lock ? SCROLL_LOCK : 0 | number_lock ? NUMBER_LOCK : 0 | caps_lock ? CAPS_LOCK : 0);
}

void pressed_ESC()
{
    add_key(VK_ESC);
}

void released_ESC()
{
    remove_key(ESC);
}

void pressed_ONE_EXCLA()
{
    add_key(VK_ONE);
    if (is_shift())
    {
        putchar(EXCLA);
        return;
    }
    putchar(ONE);
}

void released_ONE_EXCLA()
{
    remove_key(VK_ONE);
}

void pressed_TWO_AT()
{
    add_key(VK_TWO);
    if (is_shift())
    {
        putchar(AT);
        return;
    }
    putchar(TWO);
}

void released_TWO_AT()
{
    remove_key(VK_TWO);
}

void pressed_THREE_NUMBR()
{
    add_key(THREE);
    if (is_shift())
    {
        putchar(NUMBR);
        return;
    }
    putchar(THREE);
}

void released_THREE_NUMBR()
{
    remove_key(VK_THREE);
}

void pressed_FOUR_USD()
{
    add_key(FOUR);
    if (is_shift())
    {
        putchar(USD);
        return;
    }
    putchar(FOUR);
}

void released_FOUR_USD()
{
    remove_key(VK_FOUR);
}

void pressed_FIVE_PERC()
{
    add_key(FIVE);
    if (is_shift())
    {
        putchar(PERCE);
        return;
    }
    putchar(FIVE);
}

void released_FIVE_PERC()
{
    remove_key(VK_FIVE);
}

void pressed_SIX_CARET()
{
    add_key(SIX);
    if (is_shift())
    {
        putchar(CARET);
        return;
    }
    putchar(SIX);
}

void released_SIX_CARET()
{
    remove_key(VK_SIX);
}

void pressed_SEVEN_NPERC()
{
    add_key(SEVEN);
    if (is_shift())
    {
        putchar(NPERC);
        return;
    }
    putchar(SEVEN);
}

void released_SEVEN_NPERC()
{
    remove_key(VK_SEVEN);
}

void pressed_EIGHT_STAR()
{
    add_key(EIGHT);
    if (is_shift())
    {
        putchar(STAR);
        return;
    }
    putchar(EIGHT);
}

void released_EIGHT_STAR()
{
    remove_key(VK_EIGHT);
}

void pressed_NINE_OPBRA()
{
    add_key(NINE);
    if (is_shift())
    {
        putchar(OPBRA);
        return;
    }
    putchar(NINE);
}

void released_NINE_OPBRA()
{
    remove_key(VK_NINE);
}

void pressed_ZERO_CLBRA()
{
    add_key(ZERO);
    if (is_shift())
    {
        putchar(CLBRA);
        return;
    }
    putchar(ZERO);
}

void released_ZERO_CLBRA()
{
    remove_key(VK_ZERO);
}

void pressed_MINUS_UNDER()
{
    add_key(VK_MINUS_UNDER);
    if (is_shift())
    {
        putchar(UNDER);
        return;
    }
    putchar(MINUS);
}

void released_MINUS_UNDER()
{
    remove_key(VK_MINUS_UNDER);
}

void pressed_EQUAL_PLUS()
{
    add_key(VK_EQUAL_PLUS);
    if (is_shift())
    {
        putchar(PLUS);
        return;
    }
    putchar(EQUAl);
}

void released_EQUAL_PLUS()
{
    remove_key(VK_EQUAL_PLUS);
}

void pressed_BACKSPACE()
{
    terminal_backspace();
    add_key(VK_BACKSPACE);
}

void released_BACKSPACE()
{
    remove_key(VK_BACKSPACE);
}

void pressed_TAB()
{
    //Handle Autocorrect
    for (int i = 0; i < 4; i++)
    {
        putchar(SP);
    }
    add_key(VK_TAB);
}

void released_TAB()
{
    remove_key(VK_TAB);
}

void pressed_Q()
{
    add_key(VK_Q);
    if (is_shift())
    {
        putchar(Q);
        return;
    }
    putchar(q);
}

void released_Q()
{
    remove_key(VK_Q);
}

void pressed_W()
{
    add_key(VK_W);
    if (is_shift())
    {
        putchar(W);
        return;
    }
    putchar(w);
}

void released_W()
{
    remove_key(VK_W);
}

void pressed_E()
{
    add_key(VK_E);
    if (is_shift())
    {
        putchar(E);
        return;
    }
    putchar(e);
}

void released_E()
{
    remove_key(VK_E);
}

void pressed_R()
{
    add_key(VK_R);
    if (is_shift())
    {
        putchar(R);
        return;
    }
    putchar(r);
}

void released_R()
{
    remove_key(VK_R);
}

void pressed_T()
{
    add_key(VK_T);
    if (is_shift())
    {
        putchar(T);
        return;
    }
    putchar(t);
}

void released_T()
{
    remove_key(VK_T);
}

void pressed_Y()
{
    add_key(VK_Y);
    if (is_shift())
    {
        putchar(Y);
        return;
    }
    putchar(y);
}

void released_Y()
{
    remove_key(VK_Y);
}

void pressed_U()
{
    add_key(VK_Y);
    if (is_shift())
    {
        putchar(U);
        return;
    }
    putchar(u);
}

void released_U()
{
    remove_key(VK_U);
}

void pressed_I()
{
    add_key(VK_I);
    if (is_shift())
    {
        putchar(I);
        return;
    }
    putchar(i);
}

void released_I()
{
    remove_key(VK_I);
}

void pressed_O()
{
    add_key(VK_O);
    if (is_shift())
    {
        putchar(O);
        return;
    }
    putchar(o);
}

void released_O()
{
    remove_key(VK_O);
}

void pressed_P()
{
    add_key(VK_P);
    if (is_shift())
    {
        putchar(P);
        return;
    }
    putchar(p);
}

void released_P()
{
    remove_key(VK_P);
}

void pressed_OPSBR_OPCBR()
{
    add_key(VK_OPSBR_OPCBR);
    if (is_shift())
    {
        putchar(OPCBR);
        return;
    }
    putchar(OPSBR);
}

void released_OPSBR_OPCBR()
{
    remove_key(VK_OPSBR_OPCBR);
}

void pressed_CLSBR_CLCBR()
{
    add_key(VK_CLSBR_CLCBR);
    if (is_shift())
    {
        putchar(CLCBR);
        return;
    }
    putchar(CLSBR);
}

void released_CLSBR_CLCBR()
{
    remove_key(VK_CLSBR_CLCBR);
}

void pressed_ENTER()
{
    printf("\n");
    add_key(VK_ENTER);
}

void released_ENTER()
{
    remove_key(VK_ENTER);
}

void pressed_LCTRL()
{
    add_key(VK_LCONTROL);
}

void released_LCTRL()
{
    remove_key(VK_LCONTROL);
}

void pressed_A()
{
    add_key(VK_A);
    if (is_shift())
    {
        putchar(A);
        return;
    }
    putchar(a);
}

void released_A()
{
    remove_key(VK_A);
}

void pressed_S()
{
    add_key(VK_S);
    if (is_shift())
    {
        putchar(S);
        return;
    }
    putchar(s);
}

void released_S()
{
    remove_key(VK_S);
}

void pressed_D()
{
    add_key(VK_D);
    if (is_shift())
    {
        putchar(D);
        return;
    }
    putchar(d);
}

void released_D()
{
    remove_key(VK_D);
}

void pressed_F()
{
    add_key(VK_F);
    if (is_shift())
    {
        putchar(F);
        return;
    }
    putchar(f);
}

void released_F()
{
    remove_key(VK_F);
}

void pressed_G()
{
    add_key(VK_G);
    if (is_shift())
    {
        putchar(G);
        return;
    }
    putchar(g);
}

void released_G()
{
    remove_key(VK_G);
}

void pressed_H()
{
    add_key(VK_H);
    if (is_shift())
    {
        putchar(H);
        return;
    }
    putchar(h);
}

void released_H()
{
    remove_key(VK_H);
}

void pressed_J()
{
    add_key(VK_J);
    if (is_shift())
    {
        putchar(J);
        return;
    }
    putchar(j);
}

void released_J()
{
    remove_key(VK_J);
}

void pressed_K()
{
    add_key(VK_K);
    if (is_shift())
    {
        putchar(K);
        return;
    }
    putchar(k);
}

void released_K()
{
    remove_key(VK_K);
}

void pressed_L()
{
    add_key(VK_L);
    if (is_shift())
    {
        putchar(L);
        return;
    }
    putchar(l);
}

void released_L()
{
    remove_key(VK_L);
}

void pressed_SEMIC_COLON()
{
    add_key(VK_SEMIC_COLON);
    if (is_shift())
    {
        putchar(COLON);
        return;
    }
    putchar(SEMIC);
}

void released_SEMIC_COLON()
{
    remove_key(VK_SEMIC_COLON);
}

void pressed_APOST_QUOTE()
{
    add_key(VK_APOST_QUOTE);
    if (is_shift())
    {
        putchar(QUOTE);
        return;
    }
    putchar(APOST);
}

void released_APOST_QUOTE()
{
    remove_key(VK_APOST_QUOTE);
}

void pressed_GRAVE_TILDE()
{
    add_key(VK_GRAVE_TILDE);
    if (is_shift())
    {
        putchar(TILDE);
        return;
    }
    putchar(GRAVE);
}

void released_GRAVE_TILDE()
{
    remove_key(VK_GRAVE_TILDE);
}

void pressed_LSHIFT()
{
    add_key(VK_LSHIFT);
}

void released_LSHIFT()
{
    remove_key(VK_LSHIFT);
}

void pressed_BSLASH_VBAR()
{
    add_key(VK_BSLASH_VBAR);
    if (is_shift())
    {
        putchar(VBAR);
        return;
    }
    putchar(BSLASH);
}

void released_BSLASH_VBAR()
{
    remove_key(VK_BSLASH_VBAR);
}

void pressed_Z()
{
    add_key(VK_Z);
    if (is_shift())
    {
        putchar(Z);
        return;
    }
    putchar(z);
}

void released_Z()
{
    remove_key(VK_Z);
}

void pressed_X()
{
    add_key(VK_X);
    if (is_shift())
    {
        putchar(X);
        return;
    }
    putchar(x);
}

void released_X()
{
    remove_key(VK_X);
}

void pressed_C()
{
    add_key(VK_C);
    if (is_shift())
    {
        putchar(C);
        return;
    }
    putchar(c);
}

void released_C()
{
    remove_key(VK_C);
}

void pressed_V()
{
    add_key(VK_V);
    if (is_shift())
    {
        putchar(V);
        return;
    }
    putchar(v);
}

void released_V()
{
    remove_key(VK_V);
}

void pressed_B()
{
    add_key(VK_B);
    if (is_shift())
    {
        putchar(B);
        return;
    }
    putchar(b);
}

void released_B()
{
    remove_key(VK_B);
}

void pressed_N()
{
    add_key(VK_N);
    if (is_shift())
    {
        putchar(N);
        return;
    }
    putchar(n);
}

void released_N()
{
    remove_key(VK_N);
}

void pressed_M()
{
    add_key(VK_M);
    if (is_shift())
    {
        putchar(M);
        return;
    }
    putchar(m);
}

void released_M()
{
    remove_key(VK_M);
}

void pressed_KOMMA_LESST()
{
    add_key(VK_KOMMA_LESST);
    if (is_shift())
    {
        putchar(LESST);
        return;
    }
    putchar(KOMMA);
}

void released_KOMMA_LESST()
{
    remove_key(VK_KOMMA_LESST);
}

void pressed_POINT_GREAT()
{
    add_key(VK_POINT_GREAT);
    if (is_shift())
    {
        putchar(GREAT);
        return;
    }
    putchar(POINT);
}

void released_POINT_GREAT()
{
    remove_key(VK_POINT_GREAT);
}

void pressed_SLASH_QUEST()
{
    add_key(VK_SLASH_QUEST);
    if (is_shift())
    {
        putchar(QUEST);
        return;
    }
    putchar(SLASH);
}

void released_SLASH_QUEST()
{
    remove_key(VK_SLASH_QUEST);
}

void pressed_RSHIFT()
{
    add_key(VK_RSHIFT);
}

void released_RSHIFT()
{
    remove_key(VK_RSHIFT);
}

void pressed_KP_STAR()
{
    add_key(VK_KP_MULTIPLY);
    putchar(STAR);
}

void released_KP_STAR()
{
    remove_key(VK_KP_MULTIPLY);
}

void pressed_LALT()
{
    add_key(VK_LALT);
}

void released_LALT()
{
    remove_key(VK_LALT);
}

void pressed_SPACE()
{
    putchar(SP);
    add_key(VK_SPACE);
}

void released_SPACE()
{
    remove_key(VK_SPACE);
}

void pressed_CAPSLOCK()
{
    caps_lock = !caps_lock;
    update_LED();
    add_key(VK_CAPS_LOCK);
}

void released_CAPSLOCK()
{
    remove_key(VK_CAPS_LOCK);
}

void pressed_F1()
{
    add_key(VK_F1);
}

void released_F1()
{
    remove_key(VK_F1);
}

void pressed_F2()
{
    add_key(VK_F2);
}

void released_F2()
{
    remove_key(VK_F2);
}

void pressed_F3()
{
    add_key(VK_F3);
}

void released_F3()
{
    remove_key(VK_F3);
}

void pressed_F4()
{
    add_key(VK_F4);
}

void released_F4()
{
    remove_key(VK_F4);
}

void pressed_F5()
{
    add_key(VK_F5);
}

void released_F5()
{
    remove_key(VK_F5);
}

void pressed_F6()
{
    add_key(VK_F6);
}

void released_F6()
{
    remove_key(VK_F6);
}

void pressed_F7()
{
    add_key(VK_F7);
}

void released_F7()
{
    remove_key(VK_F7);
}

void pressed_F8()
{
    add_key(VK_F8);
}

void released_F8()
{
    remove_key(VK_F8);
}

void pressed_F9()
{
    add_key(VK_F9);
}

void released_F9()
{
    remove_key(VK_F9);
}

void pressed_F10()
{
    add_key(VK_F10);
}

void released_F10()
{
    remove_key(VK_F10);
}

void pressed_F11()
{
    add_key(VK_F11);
}

void released_F11()
{
    remove_key(VK_F11);
}

void pressed_F12()
{
    add_key(VK_F12);
}

void released_F12()
{
    remove_key(VK_F12);
}

void pressed_NUMBERLOCK()
{
    add_key(VK_NUMBER_LOCK);
    number_lock = !number_lock;
    update_LED();
}

void released_NUMBERLOCK()
{
    remove_key(VK_NUMBER_LOCK);
}

void pressed_SCROLLOCK()
{
    add_key(VK_SCROLL_LOCK);
    scroll_lock = !scroll_lock;
    update_LED();
}

void released_SCROLLOCK()
{
    remove_key(VK_SCROLL_LOCK);
}

void pressed_KP_SEVEN()
{
    add_key(VK_KP_SEVEN);
    if (number_lock)
    {
        putchar(SEVEN);
        return;
    }
    //TODO: HOME Function is missing
}

void released_KP_SEVEN()
{
    remove_key(VK_KP_SEVEN);
}

void pressed_KP_EIGHT()
{
    add_key(VK_KP_EIGHT);
    if (number_lock)
    {
        putchar(EIGHT);
        return;
    }
    terminal_cursor_up();
}

void released_KP_EIGHT()
{
    remove_key(VK_KP_EIGHT);
}

void pressed_KP_NINE()
{
    add_key(VK_KP_NINE);
    if (number_lock)
    {
        putchar(NINE);
        return;
    }
    //TODO: PgUp Function is missing
}

void released_KP_NINE()
{
    remove_key(VK_KP_NINE);
}

void pressed_KP_MINUS()
{
    add_key(VK_KP_MINUS);
    putchar(MINUS);
}

void released_KP_MINUS()
{
    remove_key(VK_KP_MINUS);
}

void pressed_KP_FOUR()
{
    add_key(VK_KP_FOUR);
    if (number_lock)
    {
        putchar(FOUR);
        return;
    }
    terminal_cursor_left();
}

void released_KP_FOUR()
{
    remove_key(VK_KP_FOUR);
}

void pressed_KP_FIVE()
{
    add_key(VK_KP_FIVE);
    if (number_lock)
    {
        putchar(FIVE);
        return;
    }
}

void released_KP_FIVE()
{
    remove_key(VK_KP_FIVE);
}

void pressed_KP_SIX()
{
    add_key(VK_KP_SIX);
    if (number_lock)
    {
        putchar(SIX);
        return;
    }
    terminal_cursor_right();
}

void released_KP_SIX()
{
    remove_key(VK_KP_SIX);
}

void pressed_KP_PLUS()
{
    add_key(VK_KP_ADD);
    putchar(PLUS);
}

void released_KP_PLUS()
{
    remove_key(VK_KP_ADD);
}

void pressed_KP_ONE()
{
    add_key(VK_KP_ONE);
    if (number_lock)
    {
        putchar(ONE);
        return;
    }
    //TODO END function missing
}

void released_KP_ONE()
{
    remove_key(VK_KP_ONE);
}

void pressed_KP_TWO()
{
    add_key(VK_KP_TWO);
    if (number_lock)
    {
        putchar(TWO);
        return;
    }
    terminal_cursor_down();
}

void released_KP_TWO()
{
    remove_key(VK_KP_TWO);
}

void pressed_KP_THREE()
{
    add_key(VK_KP_THREE);
    if (number_lock)
    {
        putchar(THREE);
        return;
    }
    //TODO: PgDown function missing
}

void released_KP_THREE()
{
    remove_key(VK_KP_THREE);
}

void pressed_KP_ZERO()
{
    add_key(VK_ZERO);
    if (number_lock)
    {
        putchar(ZERO);
        return;
    }
    //TODO: INSERT function missing
}

void released_KP_ZERO()
{
    remove_key(VK_KP_ZERO);
}

void pressed_KP_POINT()
{
    add_key(VK_KP_DECIMAL);
    if (number_lock)
    {
        putchar(POINT);
        return;
    }
    terminal_delete();
}

void released_KP_POINT()
{
    remove_key(VK_KP_DECIMAL);
}

void pressed_e0_KP_ENTER()
{
    printf("\n");
}

void released_e0_KP_ENTER()
{
    remove_key(VK_ENTER);
}

void pressed_e0_RCTRL()
{
    add_key(VK_RCONTROL);
}

void released_e0_RCTRL()
{
    remove_key(VK_RCONTROL);
}

void pressed_e0_KP_SLASH()
{
    putchar(SLASH);
}

void released_e0_KP_SLASH()
{
    remove_key(VK_KP_DEVIDE);
}

void pressed_e0_RALT()
{
    add_key(VK_RALT);
}

void released_e0_RALT()
{
    remove_key(VK_RALT);
}

void pressed_e0_HOME()
{
    add_key(VK_HOME);
}

void released_e0_HOME()
{
    remove_key(VK_HOME);
}

void pressed_e0_PRINT_SCR1()
{
    e0 = true;
}

void pressed_e0_PRINT_SCR2()
{
    //handle printscreen
    add_key(VK_SNAPSHOT);
}

void pressed_e0_UP()
{
    terminal_cursor_up();
    add_key(VK_UP);
}

void released_e0_UP()
{
    remove_key(VK_UP);
}

void pressed_e0_PAGE_UP()
{
    add_key(VK_PAGEUP);
}

void released_e0_PAGE_UP()
{
    remove_key(VK_PAGEUP);
}

void pressed_e0_LEFT()
{
    terminal_cursor_left();
    add_key(VK_LEFT);
}

void released_e0_LEFT()
{
    remove_key(VK_LEFT);
}

void pressed_e0_RIGHT()
{
    terminal_cursor_right();
    add_key(VK_RIGHT);
}

void released_e0_RIGHT()
{
    remove_key(VK_RIGHT);
}

void pressed_e0_END()
{
    add_key(VK_END);
}

void released_e0_END()
{
    remove_key(VK_END);
}

void pressed_e0_DOWN()
{
    terminal_cursor_down();
    add_key(VK_DOWN);
}

void released_e0_DOWN()
{
    remove_key(VK_DOWN);
}

void pressed_e0_PAGE_DOWN()
{
    add_key(VK_PAGEDOWN);
}

void released_e0_PAGE_DOWN()
{
    remove_key(VK_PAGEDOWN);
}

void pressed_e0_INSERT()
{
    add_key(VK_INSERT);
}

void released_e0_INSERT()
{
    remove_key(VK_INSERT);
}

void pressed_e0_DELETE()
{
    terminal_delete();
    add_key(VK_DELETE);
}

void released_e0_DELETE()
{
    remove_key(VK_DELETE);
}

void pressed_e0_LEFT_GUI()
{
    add_key(VK_LGUI);
}

void released_e0_LEFT_GUI()
{
    remove_key(VK_RGUI);
}

void pressed_e0_RIGHT_GUI()
{
    add_key(VK_RGUI);
}

void released_e0_RIGHT_GUI()
{
    remove_key(VK_RGUI);
}

void pressed_e0_APPS()
{
    add_key(VK_APPS);
}

void released_e0_APPS()
{
    remove_key(VK_APPS);
}

void released_e0_PRINT_SCR1()
{
    e0 = true;
}

void released_e0_PRINT_SCR2()
{
    remove_key(VK_SNAPSHOT);
}

void unknwonKey()
{
    //Handle an unknown Key by ignoring it
}

void keyboard_handler_init()
{

    //Fill emptyKeycodes so we the os does not crash, if an unknown key was pressed, to it can just ignore it
    for (int i = 0; i < 256; i++)
    {
        key_handlers[i] = &unknwonKey;
        e0key_handlers[i] = &unknwonKey;
    }

    key_handlers[PRESSED_ESC] = &pressed_ESC;
    key_handlers[PRESSED_ONE_EXCLA] = &pressed_ONE_EXCLA;
    key_handlers[PRESSED_TWO_AT] = &pressed_TWO_AT;
    key_handlers[PRESSED_THREE_NUMBR] = &pressed_THREE_NUMBR;
    key_handlers[PRESSED_FOUR_USD] = &pressed_FOUR_USD;
    key_handlers[PRESSED_FIVE_PERC] = &pressed_FIVE_PERC;
    key_handlers[PRESSED_SIX_CARET] = &pressed_SIX_CARET;
    key_handlers[PRESSED_SEVEN_NPERC] = &pressed_SEVEN_NPERC;
    key_handlers[PRESSED_EIGHT_STAR] = &pressed_EIGHT_STAR;
    key_handlers[PRESSED_NINE_OPBRA] = &pressed_NINE_OPBRA;
    key_handlers[PRESSED_ZERO_CLBRA] = &pressed_ZERO_CLBRA;
    key_handlers[PRESSED_MINUS_UNDER] = &pressed_MINUS_UNDER;
    key_handlers[PRESSED_EQUAL_PLUS] = &pressed_EQUAL_PLUS;
    key_handlers[PRESSED_BACKSPACE] = &pressed_BACKSPACE;
    key_handlers[PRESSED_TAB] = &pressed_TAB;
    key_handlers[PRESSED_Q] = &pressed_Q;
    key_handlers[PRESSED_W] = &pressed_W;
    key_handlers[PRESSED_E] = &pressed_E;
    key_handlers[PRESSED_R] = &pressed_R;
    key_handlers[PRESSED_T] = &pressed_T;
    key_handlers[PRESSED_Y] = &pressed_Y;
    key_handlers[PRESSED_U] = &pressed_U;
    key_handlers[PRESSED_I] = &pressed_I;
    key_handlers[PRESSED_O] = &pressed_O;
    key_handlers[PRESSED_P] = &pressed_P;
    key_handlers[PRESSED_OPSBR_OPCBR] = &pressed_OPSBR_OPCBR;
    key_handlers[PRESSED_CLSBR_CLCBR] = &pressed_CLSBR_CLCBR;
    key_handlers[PRESSED_ENTER] = &pressed_ENTER;
    key_handlers[PRESSED_LCTRL] = &pressed_LCTRL;
    key_handlers[PRESSED_A] = &pressed_A;
    key_handlers[PRESSED_S] = &pressed_S;
    key_handlers[PRESSED_D] = &pressed_D;
    key_handlers[PRESSED_F] = &pressed_F;
    key_handlers[PRESSED_G] = &pressed_G;
    key_handlers[PRESSED_H] = &pressed_H;
    key_handlers[PRESSED_J] = &pressed_J;
    key_handlers[PRESSED_K] = &pressed_K;
    key_handlers[PRESSED_L] = &pressed_L;
    key_handlers[PRESSED_SEMIC_COLON] = &pressed_SEMIC_COLON;
    key_handlers[PRESSED_APOST_QUOTE] = &pressed_APOST_QUOTE;
    key_handlers[PRESSED_GRAVE_TILDE] = &pressed_GRAVE_TILDE;
    key_handlers[PRESSED_LSHIFT] = &pressed_LSHIFT;
    key_handlers[PRESSED_BSLASH_VBAR] = &pressed_BSLASH_VBAR;
    key_handlers[PRESSED_Z] = &pressed_Z;
    key_handlers[PRESSED_X] = &pressed_X;
    key_handlers[PRESSED_C] = &pressed_C;
    key_handlers[PRESSED_V] = &pressed_V;
    key_handlers[PRESSED_B] = &pressed_B;
    key_handlers[PRESSED_N] = &pressed_N;
    key_handlers[PRESSED_M] = &pressed_M;
    key_handlers[PRESSED_KOMMA_LESST] = &pressed_KOMMA_LESST;
    key_handlers[PRESSED_POINT_GREAT] = &pressed_POINT_GREAT;
    key_handlers[PRESSED_SLASH_QUEST] = &pressed_SLASH_QUEST;
    key_handlers[PRESSED_RSHIFT] = &pressed_RSHIFT;
    key_handlers[PRESSED_KP_STAR] = &pressed_KP_STAR;
    key_handlers[PRESSED_LALT] = &pressed_LALT;
    key_handlers[PRESSED_SPACE] = &pressed_SPACE;
    key_handlers[PRESSED_CAPSLOCK] = &pressed_CAPSLOCK;
    key_handlers[PRESSED_F1] = &pressed_F1;
    key_handlers[PRESSED_F2] = &pressed_F2;
    key_handlers[PRESSED_F3] = &pressed_F3;
    key_handlers[PRESSED_F4] = &pressed_F4;
    key_handlers[PRESSED_F5] = &pressed_F5;
    key_handlers[PRESSED_F6] = &pressed_F6;
    key_handlers[PRESSED_F7] = &pressed_F7;
    key_handlers[PRESSED_F8] = &pressed_F8;
    key_handlers[PRESSED_F9] = &pressed_F9;
    key_handlers[PRESSED_F10] = &pressed_F10;
    key_handlers[PRESSED_NUMBERLOCK] = &pressed_NUMBERLOCK;
    key_handlers[PRESSED_SCROLLOCK] = &pressed_SCROLLOCK;
    key_handlers[PRESSED_KP_SEVEN] = &pressed_KP_SEVEN;
    key_handlers[PRESSED_KP_EIGHT] = &pressed_KP_EIGHT;
    key_handlers[PRESSED_NINE_OPBRA] = &pressed_NINE_OPBRA;
    key_handlers[PRESSED_KP_MINUS] = &pressed_KP_MINUS;
    key_handlers[PRESSED_KP_FOUR] = &pressed_KP_FOUR;
    key_handlers[PRESSED_KP_FIVE] = &pressed_KP_FIVE;
    key_handlers[PRESSED_KP_SIX] = &pressed_KP_SIX;
    key_handlers[PRESSED_KP_PLUS] = &pressed_KP_PLUS;
    key_handlers[PRESSED_KP_ONE] = &pressed_KP_ONE;
    key_handlers[PRESSED_KP_TWO] = &pressed_KP_TWO;
    key_handlers[PRESSED_KP_THREE] = &pressed_KP_THREE;
    key_handlers[PRESSED_KP_ZERO] = &pressed_KP_ZERO;
    key_handlers[PRESSED_KP_POINT] = &pressed_KP_POINT;
    key_handlers[PRESSED_F11] = &pressed_F11;
    key_handlers[PRESSED_F12] = &pressed_F12;

    key_handlers[RELEASED_ESC] = &released_ESC;
    key_handlers[RELEASED_ONE_EXCLA] = &released_ONE_EXCLA;
    key_handlers[RELEASED_TWO_AT] = &released_TWO_AT;
    key_handlers[RELEASED_THREE_NUMBR] = &released_THREE_NUMBR;
    key_handlers[RELEASED_FOUR_USD] = &released_FOUR_USD;
    key_handlers[RELEASED_FIVE_PERC] = &released_FIVE_PERC;
    key_handlers[RELEASED_SIX_CARET] = &released_SIX_CARET;
    key_handlers[RELEASED_SEVEN_NPERC] = &released_SEVEN_NPERC;
    key_handlers[RELEASED_EIGHT_STAR] = &released_EIGHT_STAR;
    key_handlers[RELEASED_NINE_OPBRA] = &released_NINE_OPBRA;
    key_handlers[RELEASED_ZERO_CLBRA] = &released_ZERO_CLBRA;
    key_handlers[RELEASED_MINUS_UNDER] = &released_MINUS_UNDER;
    key_handlers[RELEASED_EQUAL_PLUS] = &released_EQUAL_PLUS;
    key_handlers[RELEASED_BACKSPACE] = &released_BACKSPACE;
    key_handlers[RELEASED_TAB] = &released_TAB;
    key_handlers[RELEASED_Q] = &released_Q;
    key_handlers[RELEASED_W] = &released_W;
    key_handlers[RELEASED_E] = &released_E;
    key_handlers[RELEASED_R] = &released_R;
    key_handlers[RELEASED_T] = &released_T;
    key_handlers[RELEASED_Y] = &released_Y;
    key_handlers[RELEASED_U] = &released_U;
    key_handlers[RELEASED_I] = &released_I;
    key_handlers[RELEASED_O] = &released_O;
    key_handlers[RELEASED_P] = &released_P;
    key_handlers[RELEASED_OPSBR_OPCBR] = &released_OPSBR_OPCBR;
    key_handlers[RELEASED_CLSBR_CLCBR] = &released_CLSBR_CLCBR;
    key_handlers[RELEASED_ENTER] = &released_ENTER;
    key_handlers[RELEASED_LCTRL] = &released_LCTRL;
    key_handlers[RELEASED_A] = &released_A;
    key_handlers[RELEASED_S] = &released_S;
    key_handlers[RELEASED_D] = &released_D;
    key_handlers[RELEASED_F] = &released_F;
    key_handlers[RELEASED_G] = &released_G;
    key_handlers[RELEASED_H] = &released_H;
    key_handlers[RELEASED_J] = &released_J;
    key_handlers[RELEASED_K] = &released_K;
    key_handlers[RELEASED_L] = &released_L;
    key_handlers[RELEASED_SEMIC_COLON] = &released_SEMIC_COLON;
    key_handlers[RELEASED_APOST_QUOTE] = &released_APOST_QUOTE;
    key_handlers[RELEASED_GRAVE_TILDE] = &released_GRAVE_TILDE;
    key_handlers[RELEASED_LSHIFT] = &released_LSHIFT;
    key_handlers[RELEASED_BSLASH_VBAR] = &released_BSLASH_VBAR;
    key_handlers[RELEASED_Z] = &released_Z;
    key_handlers[RELEASED_X] = &released_X;
    key_handlers[RELEASED_C] = &released_C;
    key_handlers[RELEASED_V] = &released_V;
    key_handlers[RELEASED_B] = &released_B;
    key_handlers[RELEASED_N] = &released_N;
    key_handlers[RELEASED_M] = &released_M;
    key_handlers[RELEASED_KOMMA_LESST] = &released_KOMMA_LESST;
    key_handlers[RELEASED_POINT_GREAT] = &released_POINT_GREAT;
    key_handlers[RELEASED_SLASH_QUEST] = &released_SLASH_QUEST;
    key_handlers[RELEASED_RSHIFT] = &released_RSHIFT;
    key_handlers[RELEASED_KP_STAR] = &released_KP_STAR;
    key_handlers[RELEASED_LALT] = &released_LALT;
    key_handlers[RELEASED_SPACE] = &released_SPACE;
    key_handlers[RELEASED_CAPSLOCK] = &released_CAPSLOCK;
    key_handlers[RELEASED_F1] = &released_F1;
    key_handlers[RELEASED_F2] = &released_F2;
    key_handlers[RELEASED_F3] = &released_F3;
    key_handlers[RELEASED_F4] = &released_F4;
    key_handlers[RELEASED_F5] = &released_F5;
    key_handlers[RELEASED_F6] = &released_F6;
    key_handlers[RELEASED_F7] = &released_F7;
    key_handlers[RELEASED_F8] = &released_F8;
    key_handlers[RELEASED_F9] = &released_F9;
    key_handlers[RELEASED_F10] = &released_F10;
    key_handlers[RELEASED_NUMBERLOCK] = &released_NUMBERLOCK;
    key_handlers[RELEASED_SCROLLOCK] = &released_SCROLLOCK;
    key_handlers[RELEASED_KP_SEVEN] = &released_KP_SEVEN;
    key_handlers[RELEASED_KP_EIGHT] = &released_KP_EIGHT;
    key_handlers[RELEASED_NINE_OPBRA] = &released_NINE_OPBRA;
    key_handlers[RELEASED_KP_MINUS] = &released_KP_MINUS;
    key_handlers[RELEASED_KP_FOUR] = &released_KP_FOUR;
    key_handlers[RELEASED_KP_FIVE] = &released_KP_FIVE;
    key_handlers[RELEASED_KP_SIX] = &released_KP_SIX;
    key_handlers[RELEASED_KP_PLUS] = &released_KP_PLUS;
    key_handlers[RELEASED_KP_ONE] = &released_KP_ONE;
    key_handlers[RELEASED_KP_TWO] = &released_KP_TWO;
    key_handlers[RELEASED_KP_THREE] = &released_KP_THREE;
    key_handlers[RELEASED_KP_ZERO] = &released_KP_ZERO;
    key_handlers[RELEASED_KP_POINT] = &released_KP_POINT;
    key_handlers[RELEASED_F11] = &released_F11;
    key_handlers[RELEASED_F12] = &released_F12;

    e0key_handlers[PRESSED_E0_KP_ENTER] = &pressed_e0_KP_ENTER;
    e0key_handlers[PRESSED_E0_RCTRL] = &pressed_e0_RCTRL;
    e0key_handlers[PRESSED_E0_KP_SLASH] = &pressed_e0_KP_SLASH;
    e0key_handlers[PRESSED_E0_RALT] = &pressed_e0_RALT;
    e0key_handlers[PRESSED_E0_UP] = &pressed_e0_UP;
    e0key_handlers[PRESSED_E0_PAGE_UP] = &pressed_e0_PAGE_UP;
    e0key_handlers[PRESSED_E0_LEFT] = &pressed_e0_LEFT;
    e0key_handlers[PRESSED_E0_RIGHT] = &pressed_e0_RIGHT;
    e0key_handlers[PRESSED_E0_END] = &pressed_e0_END;
    e0key_handlers[PRESSED_E0_DOWN] = &pressed_e0_DOWN;
    e0key_handlers[PRESSED_E0_PAGE_DOWN] = &pressed_e0_PAGE_DOWN;
    e0key_handlers[PRESSED_E0_INSERT] = &pressed_e0_INSERT;
    e0key_handlers[PRESSED_E0_DELETE] = &pressed_e0_DELETE;
    e0key_handlers[PRESSED_E0_LEFT_GUI] = &pressed_e0_LEFT_GUI;
    e0key_handlers[PRESSED_E0_RIGHT_GUI] = &pressed_e0_RIGHT_GUI;
    e0key_handlers[PRESSED_E0_APPS] = &pressed_e0_APPS;
    e0key_handlers[PRESSED_E0_PRINT_SCR1] = &pressed_e0_PRINT_SCR1;
    e0key_handlers[PRESSED_E0_PRINT_SCR2] = &pressed_e0_PRINT_SCR2;

    e0key_handlers[RELEASED_E0_KP_ENTER] = &released_e0_KP_ENTER;
    e0key_handlers[RELEASED_E0_RCTRL] = &released_e0_RCTRL;
    e0key_handlers[RELEASED_E0_KP_SLASH] = &released_e0_KP_SLASH;
    e0key_handlers[RELEASED_E0_RALT] = &released_e0_RALT;
    e0key_handlers[RELEASED_E0_UP] = &released_e0_UP;
    e0key_handlers[RELEASED_E0_PAGE_UP] = &released_e0_PAGE_UP;
    e0key_handlers[RELEASED_E0_LEFT] = &released_e0_LEFT;
    e0key_handlers[RELEASED_E0_RIGHT] = &released_e0_RIGHT;
    e0key_handlers[RELEASED_E0_END] = &released_e0_END;
    e0key_handlers[RELEASED_E0_DOWN] = &released_e0_DOWN;
    e0key_handlers[RELEASED_E0_PAGE_DOWN] = &released_e0_PAGE_DOWN;
    e0key_handlers[RELEASED_E0_INSERT] = &released_e0_INSERT;
    e0key_handlers[RELEASED_E0_DELETE] = &released_e0_DELETE;
    e0key_handlers[RELEASED_E0_LEFT_GUI] = &released_e0_LEFT_GUI;
    e0key_handlers[RELEASED_E0_RIGHT_GUI] = &released_e0_RIGHT_GUI;
    e0key_handlers[RELEASED_E0_APPS] = &released_e0_APPS;
    e0key_handlers[RELEASED_E0_PRINT_SCR1] = &released_e0_PRINT_SCR1;
    e0key_handlers[RELEASED_E0_PRINT_SCR2] = &released_e0_PRINT_SCR2;
}

void keyboard_irq_handler(void)
{
    uint8_t scancode = inb(KBC_IO_BUFFER_PORT);

    if (scancode == 0xFA) //Keyboard ACK
    {
        return;
    }

    if (scancode == EXTEND_E0)
    {
        e0 = true;
    }
    else if (scancode == EXTEND_E1)
    {
        e1 = 1;
    }
    else
    {

        if (e0)
        {
            e0 = false;
            //intercept fake shift
            if ((scancode == 0x2A) || (scancode == 0x36))
            {
                return;
            }
            e0key_handlers[scancode]();
        }
        else if (e1 == 1)
        {
            if (scancode = PRESSED_PAUSE_5)
            {
                e1 = 0;
                //TODO: handle Pause key
            }
        }
        else
        {
            key_handlers[scancode]();
        }
    }
}